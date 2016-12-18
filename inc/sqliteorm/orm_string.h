#pragma once

#include "orm_type.h"

#include <memory>
#include <list>

namespace SQLiteORM
{    
    template<class T> struct SQL;

    struct SQLEnd;
    struct SQLBegin : public StringStreamType
    {
        virtual bool end(SQLEnd* sqlend) = 0;

        void set_table_name(const MyStr& table_name);
        const MyStr& get_table_name() const;
    private:
        MyStr table_name_;
    };

    struct SQLStringBase : public StringStreamType 
    {
        template<class T> friend struct SQL;

        SQLStringBase();
        virtual ~SQLStringBase() {} 
        //SQLStringBase(const MyStr& sql);

        const MyStr& sql() const;
        virtual void init(SQLStringBase* parent);
        SQLStringBase* root();
        SQLBegin* begin();

    protected:
        MyStr sql_;
        SQLBegin* begin_;
        SQLStringBase* parent_;
        SQLDatabase* database_;
        SQLStateType state_type_;
        SQLCommitType commit_type_;
    };

    struct SQLEnd : public SQLStringBase
    {
        const SQLEnd& END();
        RecordList Records;
        int32_t RecordCount;
        std::shared_ptr<Column2> MaxColumn;
        virtual void init(SQLStringBase* parent);
    };

    struct Limit : public SQLEnd
    {
        Limit& operator()(int count);
    };

    struct OrderBy : public SQLEnd
    {
        virtual void init(SQLStringBase* parent);
        OrderBy& operator()(const Column2& col, bool ASC);
        Limit LIMIT;
    };

    struct Where : public SQLEnd
    {
        virtual void init(SQLStringBase* parent);
        Where& operator()(const Column2&);
        Limit LIMIT;
        OrderBy ORDERBY;
    };

    struct From : public SQLEnd
    {
        virtual void init(SQLStringBase* parent);
        Where WHERE;
        Limit LIMIT;
    };

    struct Select : public SQLStringBase
    {
        virtual void init(SQLStringBase* parent);
        From FROM;
    };

    struct SelectCount : public SQLStringBase
    {
        virtual void init(SQLStringBase* parent);
        From FROM;
    };

    struct SelectMax : public SQLStringBase
    {
        SelectMax& operator()(const Column2& col);
        From FROM;
    };

    struct SelectDistinct : public SQLStringBase
    {
        //SelectDistinct(const std::list<MyStr>& column_name_list);
        From FROM;
    };

    struct Delete : public SQLStringBase
    {
        virtual void init(SQLStringBase* parent);
        From FROM;
    };

    struct Values : public SQLEnd
    {
        Values& operator()(const Row& row);
    };

    struct Into : public SQLStringBase
    {
        virtual void init(SQLStringBase* parent);
        Values VALUES;
    };

    struct Insert : public SQLStringBase
    {
        virtual void init(SQLStringBase* parent);
        Into INTO;
    };

    struct Set : public SQLEnd
    {
        virtual void init(SQLStringBase* parent);
        //update all column
        Set& operator()(const Row& row);
        //update one column
        Set& operator()(const Column2& col);
        Where WHERE;
    };

    struct Update : public SQLEnd
    {
        virtual void init(SQLStringBase* parent);
        Set SET;
    };

    struct CreateTable : public SQLEnd
    {
        CreateTable& operator()(const Row& Row);
    };

    template<class T>
    struct SQL : public SQLBegin
    {
        SQL(SQLDatabase* db)
        {
            set_table_name(T().getName());

            SELECT.begin_ = this;
            SELECT.database_ = db;
            SELECT.commit_type_ = enum_query_loop;
            SELECT.init(nullptr);
            
            DELETE.begin_ = this;
            DELETE.database_ = db;
            DELETE.commit_type_ = enum_commit_once;
            DELETE.init(nullptr);

            INSERT.begin_ = this;
            INSERT.database_ = db;
            INSERT.commit_type_ = enum_commit_once;
            INSERT.init(nullptr);

            UPDATE.begin_ = this;
            UPDATE.database_ = db;
            UPDATE.commit_type_ = enum_commit_once;
            UPDATE.init(nullptr);

            SELECT_COUNT.begin_ = this;
            SELECT_COUNT.database_ = db;
            SELECT_COUNT.commit_type_ = enum_query_count;
            SELECT_COUNT.init(nullptr);

            SELECT_MAX.begin_ = this;
            SELECT_MAX.database_ = db;
            SELECT_MAX.commit_type_ = enum_query_max;
            SELECT_MAX.init(nullptr);

            CREATE_TABLE.begin_ = this;
            CREATE_TABLE.database_ = db;
            CREATE_TABLE.commit_type_ = enum_commit_once;
            CREATE_TABLE.init(nullptr);
        }

        SQL& BEGIN()
        {
            return *(this);
        }

        Select SELECT;
        Delete DELETE;
        Insert INSERT;
        Update UPDATE;

        SelectCount SELECT_COUNT;
        SelectMax   SELECT_MAX;

        CreateTable CREATE_TABLE;

        bool end(SQLEnd* sqlend)
        {
            if (!sqlend)
                return false;
            if (!sqlend->database_)
                return false;
            if (sqlend->state_type_ != enum_end_state)
                return false;
            bool result = true;
            switch (sqlend->commit_type_)
            {
            case enum_commit_once:
                result = sqlend->database_->commit_once(sqlend->sql_);
                break;
            case enum_query_max:
                result = sqlend->database_->commit_loop(
                    sqlend->sql_,
                    [&](SQLite::Statement* sts) {
                    if (!sts->executeStep())
                        return false;
                    sqlend->MaxColumn.reset(new Column2);
                    *sqlend->MaxColumn = sts->getColumn(0);
                    return true;
                });
                break;
            case enum_query_count:
                result = sqlend->database_->commit_loop(
                    sqlend->sql_,
                    [&](SQLite::Statement* sts) {
                        if (!sts->executeStep())
                            return false;
                        sqlend->RecordCount = sts->getColumn(0).getInt();
                        return true;
                    });
                break;
            case enum_query_loop:                
                result = sqlend->database_->commit_loop(
                    sqlend->sql_,
                    [&](SQLite::Statement* sts) {
                        sqlend->Records.clear();
                        SafeRow row(new T);
                        while (row->Query(*sts))
                            sqlend->Records.push_back(row);
                        return true;
                    });
                break;
            default:
                result = false;
                break;
            }
            return result;
        }
    };
}
