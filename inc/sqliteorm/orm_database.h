#pragma once

#include <string>
#include <memory>
#include <functional>

#include <cstdint>

#include "orm_type.h"

namespace SQLite
{
    class Database;
    class Statement;
}

namespace SQLiteORM
{
    struct SQLDatabase : public StringStreamType
    {
        static const uint32_t C_MAX_LOG_COUNT = 32;

        SQLDatabase();

        bool open_db(const MyStr& filename);
        void close_db();

        //SQLBase
        virtual bool commit_once(const MyStr& sqlstring);

        typedef std::function<void(SQLite::Statement* sts)> QueryCallback;
        virtual bool commit_loop(const MyStr& sqlstring, QueryCallback qcb);

        const SQLError& get_last_error() const;
        const ErrorList& get_all_error() const;
        void clear_error();

    private:
        void append_error(const MyStr& instruction, const MyStr& what);

    private:
        bool m_opened;
        std::shared_ptr<SQLite::Database> m_db;
        ErrorList m_error_list;
    };

}