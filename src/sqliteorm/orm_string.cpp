#include "sqliteorm/orm_string.h"
#include "sqliteorm/orm_object.h"
#include "sqliteorm/orm_database.h"

#include <list>
#include <vector>

namespace SQLiteORM
{
    void SQLBegin::set_table_name(const MyStr& table_name)
    {
        table_name_ = table_name;
    }

    const SQLBegin::MyStr& SQLBegin::get_table_name() const
    {
        return table_name_;
    }

    SQLStringBase::SQLStringBase()
        :
        commit_type_(enum_commit_invalid),
        state_type_(enum_begin_state),
        begin_(nullptr),
        parent_(nullptr),
        database_(nullptr)
    {
    }

    void SQLStringBase::init(SQLStringBase* parent)
    {
        if (parent)
        {
            parent_ = parent;
            begin_ = parent->begin_;
            database_ = parent->database_;
            commit_type_ = parent->commit_type_;
        }
    }

    SQLStringBase* SQLStringBase::root()
    {
        if (parent_)
            return parent_;
        return root();
    }

    SQLBegin* SQLStringBase::begin()
    { 
        return begin_; 
    }

    const SQLStringBase::MyStr& SQLStringBase::sql() const
    {
        return sql_;
    }

    void SQLEnd::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        state_type_ = enum_end_state;
    }

    const SQLEnd& SQLEnd::END()
    {
        if (begin_)
        {
            begin_->end(this);
        }
        return *this;
    }

    void Select::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        sql_ = "SELECT * ";
        FROM.init(this);
    }

    void SelectCount::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        sql_ = "SELECT count(*) ";
        FROM.init(this);
    }

    SelectMax& SelectMax::operator()(const Column2& col)
    {
        sql_ = "SELECT max(`";
        sql_ += col.getName();
        sql_ += "`) ";
        FROM.init(this);
        return *this;
    }

    //SelectDistinct::SelectDistinct(const std::list<MyStr>& column_name_list)
    //{
    //    if (column_name_list.size() > 0)
    //    {
    //        sql_ = parent_->sql();
    //        sql_ += "SELECT DISTINCT ";
    //        for (auto i : column_name_list)
    //        {
    //            sql_ += "`" + i + "`,";
    //        }
    //        sql_.pop_back(); //popup last comma
    //    }
    //    else
    //    {
    //        assert(0);
    //    }
    //}

    void From::init(SQLStringBase* parent)
    {
        SQLEnd::init(parent);
        if (parent_)
        {
            SQLBegin* begin = parent->begin();
            if (begin)
                sql_ = parent_->sql() + "FROM `" + begin->get_table_name() + "` ";
        }
        WHERE.init(this);
        LIMIT.init(this);
    }

    Limit& Limit::operator()(int count)
    {
        if (parent_)
        {
            MyOStrStream oss;
            oss << parent_->sql() << " LIMIT " << count << " ";
            sql_ = oss.str();
        }
        return *this;
    }

    void OrderBy::init(SQLStringBase* parent)
    {
        SQLEnd::init(parent);
        LIMIT.init(this);
    }

    OrderBy& OrderBy::operator()(const Column2& col, bool ASC)
    {
        if (parent_)
        {
            MyOStrStream oss;
            oss << parent_->sql() << " ORDER BY `" << col.getName() << "` " << (ASC ? "ASC " : "DESC ");
            sql_ += oss.str();
        }
        return *this;
    }

    void Where::init(SQLStringBase* parent)
    {
        SQLEnd::init(parent);
        LIMIT.init(this);
        ORDERBY.init(this);
    }

    Where& Where::operator()(const Column2& col)
    {
        if (parent_)
        {
            sql_ = parent_->sql();
            sql_ += "WHERE ";
            sql_ += col.getSQL();
        }
        return *this;
    }

    //Where& Where::Like(const MyStr& text)
    //{
    //    static const MyStr or = "(`%s` LIKE \'%s%s%s\')";
    //    std::vector<MyC> vec;
    //    vec.resize(or.size() + text.size() + col_.size() + 32);
    //    sprintf(
    //        static_cast<MyC*>(&vec[0]),
    //        or.c_str(),
    //        col_.c_str(), 
    //        "%", text.c_str(), "%");
    //    str_.clear();
    //    str_ = &vec[0];//, vec.size());
    //    sql_ += str_;
    //    return *this;
    //}

    void Delete::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        sql_ = "DELETE ";
        FROM.init(this);
    }

    Values& Values::operator()(const Row& row)
    {
        if (parent_)
        {
            sql_ = parent_->sql();
            sql_ += "VALUES ";
            sql_ += row.DumpToValue();
        }
        return *this;
    }

    void Into::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        if (parent_)
        {
            SQLBegin* begin = parent->begin();
            if (begin)
                sql_ = parent_->sql() + "INTO `" + begin->get_table_name() + "` ";
        }
        VALUES.init(this);
    }

    void Insert::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        sql_ = "INSERT ";
        INTO.init(this);
    }

    void Set::init(SQLStringBase* parent)
    {
        SQLEnd::init(parent);
        WHERE.init(this);
    }

    Set& Set::operator()(const Row& row)
    {
        if (parent_)
        {
            sql_ = parent_->sql();
            sql_ += "SET ";
            sql_ += row.DumpToSet();
            sql_ += " ";
        }
        return *this;
    }

    Set& Set::operator()(const Column2& col)
    {
        if (parent_)
        {
            MyOStrStream oss;
            oss << parent_->sql() << "SET `" << col.getName() << "`=" << col << " ";
            sql_.append(oss.str());
        }
        return *this;
    }

    void Update::init(SQLStringBase* parent)
    {
        SQLStringBase::init(parent);
        if (begin_)
            sql_ = "UPDATE `" + begin_->get_table_name() + "` ";
        SET.init(this);
    }
}