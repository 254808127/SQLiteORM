#include "sqliteorm/orm_object.h"
#include "sqlitecpp/SQLiteCpp.h"

namespace SQLiteORM
{
    Column2::Column2() //Ä¬ÈÏÎªNULL
        :
        type_(SQLite::Null)
    {
    }

    Column2::Column2(double num)
        :
        type_(SQLite::FLOAT),
        numberic_(num)
    {

    }

    Column2::Column2(const MyStr& text)
        :
        type_(SQLite::TEXT),
        text_(text)
    {

    }

    Column2::Column2(int64_t integer)
        :
        type_(SQLite::INTEGER),
        integer_(integer)
    {

    }

    Column2::Column2(NullValue)
        :
        type_(SQLite::Null)
    {
    }

    Column2::Column2(const SQLite::Column& col)
    {
        *this = col;
    }

    Column2::Column2(const Column2& col)
    {
        *this = col;
    }

    void Column2::setInt64(int64_t integer)
    {
        integer_ = integer;
        type_ = SQLite::INTEGER;
    }

    void Column2::setDouble(double numberic)
    {
        numberic_ = numberic;
        type_ = SQLite::FLOAT;
    }

    void Column2::setText(const MyCharType* text)
    {
        if (text)
        {
            text_ = text;
            type_ = SQLite::TEXT;
        }
    }

    void Column2::setName(const MyCharType* name)
    {
        if (name)
        {
            name_ = name;
        }
    }

    void Column2::setBlob(const Blob& blob)
    {
        if (blob.empty())
            return;
        setBlob(&blob[0], blob.size());
    }

    void Column2::setBlob(const uint8_t *buffer, uint32_t len)
    {
        if (!buffer || len < 1)
            return;

    }

    void Column2::setNull()
    {
        type_ = SQLite::Null;
    }

    int64_t Column2::getInt64() const
    {
        if (type_ != SQLite::INTEGER)
            return 0;
        return integer_;
    }

    double Column2::getDouble() const
    {
        if (type_ != SQLite::FLOAT)
            return 0;
        return numberic_;
    }

    const MyCharType* Column2::getText() const
    {
        if (type_ != SQLite::TEXT)
            return "";
        return text_.c_str();
    }

    const MyCharType* Column2::getName() const
    {
        return name_.c_str();
    }

    const uint8_t* Column2::getBlob() const
    {
        return &blob_[0];
    }

    int Column2::getType() const
    {
        return type_;
    }

    const Column2::MyC* Column2::getTypeName() const
    {
        if (type_ == SQLite::INTEGER)
        {
            return "SQLite::INTEGER";
        }
        else if (type_ == SQLite::Null)
        {
            return "SQLite::Nul";
        }
        else if (type_ == SQLite::FLOAT)
        {
            return "SQLite::FLOAT";
        }
        else if (type_ == SQLite::TEXT)
        {
            return "SQLite::TEXT";
        }
        else
        {
            return "Unknown type";
        }
        return "Unknown type";
    }

    const MyCharType* Column2::getSQL() const
    {
        return sql_.c_str();
    }

    Column2& Column2::operator=(const Column2& col2)
    {
        type_ = col2.type_;
        name_ = col2.name_;
        if (type_ == SQLite::INTEGER)
        {
            integer_ = col2.integer_;
        }
        else if (type_ == SQLite::Null)
        {
        }
        else if (type_ == SQLite::FLOAT)
        {
            numberic_ = col2.numberic_;
        }
        else if (type_ == SQLite::TEXT)
        {
            text_ = col2.text_;
        }
        else
        {
            assert(0);
        }
        return *this;
    }

    Column2& Column2::operator=(const SQLite::Column& col)
    {
        name_ = col.getName();
        type_ = col.getType();
        if (type_ == SQLite::INTEGER)
        {
            integer_ = col.getInt64();
        }
        else if (type_ == SQLite::Null)
        {
            integer_ = 0;
            numberic_ = 0.0;
            text_ = "";
        }
        else if (type_ == SQLite::FLOAT)
        {
            numberic_ = col.getDouble();
        }
        else if (type_ == SQLite::TEXT)
        {
            text_ = col.getText();
        }
        else
        {
            assert(0);
        }
        return *this;
    }

    Column2& Column2::operator==(int64_t integer)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`=" << integer << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator==(double numeric)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`=" << numeric << ")";
        sql_ = oss.str();        
        return *this;
    }
    Column2& Column2::operator==(const MyStr& text)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`=\'" << text << "\')";
        sql_ = oss.str();
        return *this;
    }

    Column2& Column2::operator!=(int64_t integer)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`<>" << integer << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator!=(double numeric)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`<>" << numeric << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator!=(const MyStr& text)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`<>\'" << text << "\')";
        sql_ = oss.str();
        return *this;
    }

    //Column2& Column2::operator^=(const MyStr& text)
    //{
    //    assert(0);
    //    return *this;
    //}

    //and
    Column2& Column2::operator&&(const Column2& rhs)
    {
        MyOStrStream oss;
        oss << "(" << sql_ << " AND " << rhs.getSQL() << ")";
        return *this;
    }
    //or
    Column2& Column2::operator||(const Column2& rhs)
    {
        MyOStrStream oss;
        oss << "(" << sql_ << " or " << rhs.getSQL() << ")";
        return *this;
    }

    Column2& Column2::operator>(int64_t integer)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`>" << integer << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator>(double numberic)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`>" << numberic << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator<(int64_t integer)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`<" << integer << ")";
        sql_ = oss.str();
        return *this;
    }
    Column2& Column2::operator<(double numberic)
    {
        MyOStrStream oss;
        oss << "(`" << name_ << "`<" << numberic << ")";
        sql_ = oss.str();
        return *this;
    }

    StringStreamType::MyOStream& SQLiteORM::operator<<(StringStreamType::MyOStream& oss, const Column2& rhs)
    {
        if (rhs.type_ == SQLite::INTEGER)
        {
            oss << rhs.integer_;
        }
        else if (rhs.type_ == SQLite::FLOAT)
        {
            oss << rhs.numberic_;
        }
        else if (rhs.type_ == SQLite::Null)
        {
            oss << "NUL";
        }
        else if (rhs.type_ == SQLite::TEXT)
        {
            if (rhs.text_.empty())
                oss << "NUL";
            else
                oss << '\'' << rhs.text_ << '\'';
        }
        else
        {
            assert(false);
        }
        return oss;
    }

    Row::MyStr Row::DumpToDebugString() const
    {
        MyOStrStream oss;
        for (size_t i = 0; i < m_col_list.size(); ++i)
        {
            oss
                << "name = " << m_col_list[i]->getName()
                << ", type = " << m_col_list[i]->getTypeName()
                << ", value = " << *m_col_list[i]
                << std::endl;
        }
        return oss.str();
    }

    Row::MyStr Row::DumpToValue() const
    {
        MyStr value;
        value.push_back('(');
        for (size_t i = 0; i < m_col_list.size(); ++i)
        {
            MyOStrStream oss;
            oss << *m_col_list[i];
            value.append(oss.str());
            value += ",";
        }
        value.pop_back();
        value.push_back(')');
        return value;
    }

    Row::MyStr Row::DumpToSet() const
    {
        MyStr value;
        for (size_t i = 0; i < m_col_list.size(); ++i)
        {
            MyOStrStream oss;
            oss << "`" << m_col_list[i]->getName() << "`=" << *m_col_list[i];
            value.append(oss.str());
            value += ",";
        }
        value.pop_back();
        return value;
    }

    bool Row::Query(SQLite::Statement& query)
    {
        if (!query.executeStep())
            return false;
        for (size_t i = 0; i < m_col_list.size(); ++i)
            *m_col_list[i] = query.getColumn(i);
        return true;
    }

    void Row::setName(const MyCharType* name)
    {
        if (name)
            m_name = name;
    }

    const MyCharType* Row::getName() const
    {
        return m_name.c_str();
    }

}