#pragma once

#include <list>
#include <sstream>
#include <memory>

namespace SQLiteORM
{

    typedef char MyCharType;

    struct NullValue
    {
    };

    struct Row;
    struct Column2;

    struct StringStreamType
    {
        typedef MyCharType MyC;
        typedef std::basic_string<MyC> MyStr;

        typedef std::basic_istream<MyC> MyIStream;
        typedef std::basic_ostream<MyC> MyOStream;

        typedef std::basic_istringstream<MyC> MyIStrStream;
        typedef std::basic_ostringstream<MyC> MyOStrStream;
    };

    struct SQLDatabase;
    struct SQLStringBase;
    struct SQLError : public StringStreamType
    {
        MyStr m_instruction;
        MyStr m_what;
    };

    typedef std::shared_ptr<Row> SafeRow;
    typedef std::list<SafeRow> RecordList;
    typedef std::list<SQLError> ErrorList;

    enum SQLStateType
    {
        enum_begin_state,
        enum_end_state,
    };

    enum SQLCommitType
    {
        enum_commit_invalid,
        enum_commit_once, //no return
        enum_query_count, //return record count
        enum_query_max, //return max column value
        enum_query_loop, //return multiple record
    };

    enum SQLConstrainType
    {
        enum_constrain_none = 0,
        enum_constrain_not_null = 0x00000001,
        enum_constrain_primary = 0x00000002,
        enum_constrain_autoincrement = 0x00000004,
        enum_constrain_unique = 0x00000008,
    };
}
