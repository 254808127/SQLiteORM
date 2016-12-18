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
}
