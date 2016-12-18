#include "sqliteorm/orm_database.h"
#include "sqliteorm/orm_object.h"

#include "sqlitecpp/Database.h"

namespace SQLiteORM
{
    SQLDatabase::SQLDatabase()
        :
        m_opened(false)
    {

    }

    bool SQLDatabase::open_db(const MyStr& filename)
    {
        if (m_opened)
            return true;
        m_opened = true;
        try
        {
            m_db.reset(new SQLite::Database(filename, SQLite::OPEN_READWRITE));
        }
        catch (std::exception& exp)
        {
            m_opened = false;
            append_error("open_db", exp.what());
        }
        return m_opened;
    }

    void SQLDatabase::close_db()
    {
        m_opened = false;
        try
        {
            m_db.reset();
        }
        catch (std::exception& exp)
        {
            append_error("open_db", exp.what());
        }
    }

    bool SQLDatabase::commit_once(const MyStr& sqlstring)
    {
        if (!m_opened)
            return false;

        bool result = true;
        try
        {
            if (m_db)
                m_db->exec(sqlstring);
            else result = false;
        }
        catch (std::exception& exp)
        {
            result = false;
            append_error(sqlstring, exp.what());
        }
        return result;
    }

    bool SQLDatabase::commit_loop(const MyStr& sqlstring, QueryCallback qcb)
    {
        if (!m_opened)
            return false;

        bool result = true;
        try
        {
            if (m_db)
            {
                SQLite::Statement state(*m_db, sqlstring);
                qcb(&state);
            }
            else
            {
                result = false;
            }
        }
        catch (std::exception& exp)
        {
            result = false;
            append_error(sqlstring, exp.what());
        }
        return result;
    }

    const SQLError& SQLDatabase::get_last_error() const
    {
        return m_error_list.back();
    }

    const ErrorList& SQLDatabase::get_all_error() const
    {
        return m_error_list;
    }

    void SQLDatabase::clear_error()
    {
        m_error_list.clear();
    }

    void SQLDatabase::append_error(const MyStr& instruction, const MyStr& what)
    {
        SQLError error;
        error.m_instruction = instruction;
        error.m_what = what;
        m_error_list.push_back(error);
        if (m_error_list.size() >= C_MAX_LOG_COUNT)
            m_error_list.pop_front();
    }
}