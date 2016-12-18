#pragma once

//#include "sqlitecpp/SQLiteCpp.h"

#include <memory>
#include <vector>
#include <array>
#include <list>
#include <cstdint>

#include "sqliteorm/orm_type.h"

namespace SQLite
{
    class Column;
    class Statement;
}

namespace SQLiteORM
{
    struct Column2 : public StringStreamType
    {
        typedef std::vector<unsigned char> Blob;

        friend MyOStream& operator<<(StringStreamType::MyOStream& oss, const Column2& rhs);

        Column2(); //Default value NULL
        Column2(double num);
        Column2(const MyStr& text);
        Column2(int64_t integer);
        Column2(NullValue);
        Column2(const SQLite::Column& col);
        Column2(const Column2& col);

        Column2& operator=(const Column2& col2);
        Column2& operator=(const SQLite::Column& col);

        Column2& operator==(int64_t);
        Column2& operator==(double);
        Column2& operator==(const MyStr&);

        Column2& operator!=(int64_t);
        Column2& operator!=(double);
        Column2& operator!=(const MyStr&);

        //AND
        Column2& operator&&(const Column2&);
        //OR
        Column2& operator||(const Column2&);
        //Column2& operator^=(const MyStr&);
         
        Column2& operator>(int64_t);
        Column2& operator>(double);
        Column2& operator<(int64_t);
        Column2& operator<(double);

        void setInt64(int64_t integer);
        void setDouble(double numberic);
        void setText(const MyCharType*);
        void setName(const MyCharType*);
        void setBlob(const Blob& blob);
        void setBlob(const uint8_t * buffer, uint32_t len);
        void setNull();
        void setConstrains(int32_t constrains);

        //为了和SQLite::Column接口一致
        int64_t getInt64() const;
        double getDouble() const;
        const MyCharType* getText() const;
        const MyCharType* getName() const;
        const uint8_t * getBlob() const;
        int32_t getType() const;
        int32_t getConstrains() const;
        const MyCharType* getTypeName() const;
        const MyCharType* getSQL() const;

    private:
        int32_t type_;
        int32_t constrains_;
        //todo: use a big union
        double numberic_;
        int64_t integer_;
        MyStr text_;
        MyStr name_;
        MyStr sql_;
        Blob blob_;
        NullValue null_;
    };

    StringStreamType::MyOStream& operator<<(StringStreamType::MyOStream& oss, const Column2& rhs);

    struct Row : public StringStreamType
    {
        typedef std::vector<Column2> ObjectValues;

        /** \brief base class for Value iterators.
        *
        */
        class RowIteratorBase
        {
        public:
            typedef unsigned int size_t;
            typedef int difference_type;
            typedef RowIteratorBase SelfType;

            RowIteratorBase();
            explicit RowIteratorBase(const Row::ObjectValues::iterator &current);

            bool operator ==(const SelfType &other) const
            {
                return isEqual(other);
            }

            bool operator !=(const SelfType &other) const
            {
                return !isEqual(other);
            }

            difference_type operator -(const SelfType &other) const
            {
                return computeDistance(other);
            }

            /// Return either the index or the member name of the referenced value as a Value.
            //Value key() const;

            /// Return the index of the referenced Value. -1 if it is not an arrayValue.
            int32_t index() const;

            /// Return the member name of the referenced Value. "" if it is not an objectValue.
            const char *memberName() const;

        protected:
            Row &deref() const;

            void increment();

            void decrement();

            difference_type computeDistance(const SelfType &other) const;

            bool isEqual(const SelfType &other) const;

            void copy(const SelfType &other);

        private:
#ifndef JSON_VALUE_USE_INTERNAL_MAP
            Row::ObjectValues::iterator current_;
            // Indicates that iterator is for a null value.
            bool isNull_;
#else
            union
            {
                ValueInternalArray::IteratorState array_;
                ValueInternalMap::IteratorState map_;
            } iterator_;
            bool isArray_;
#endif
        };

        class RowConstIterator : public RowIteratorBase
        {
            friend struct Row;
        public:
            typedef unsigned int size_t;
            typedef int difference_type;
            typedef const Row &reference;
            typedef const Row *pointer;
            typedef RowConstIterator SelfType;

            RowConstIterator();
        private:
            explicit RowConstIterator(const Row::ObjectValues::iterator &current);

        public:
            SelfType &operator =(const RowIteratorBase &other);

            SelfType operator++(int)
            {
                SelfType temp(*this);
                ++*this;
                return temp;
            }

            SelfType operator--(int)
            {
                SelfType temp(*this);
                --*this;
                return temp;
            }

            SelfType &operator--()
            {
                decrement();
                return *this;
            }

            SelfType &operator++()
            {
                increment();
                return *this;
            }

            reference operator *() const
            {
                return deref();
            }
        };

        class RowIterator : public RowIteratorBase
        {
            friend struct Row;
        public:
            typedef unsigned int size_t;
            typedef int difference_type;
            typedef Row &reference;
            typedef Row *pointer;
            typedef RowIterator SelfType;

            RowIterator();
            RowIterator(const RowConstIterator &other);
            RowIterator(const RowIterator &other);
        private:

            explicit RowIterator(const Row::ObjectValues::iterator &current);

        public:

            SelfType &operator =(const SelfType &other);

            SelfType operator++(int)
            {
                SelfType temp(*this);
                ++*this;
                return temp;
            }

            SelfType operator--(int)
            {
                SelfType temp(*this);
                --*this;
                return temp;
            }

            SelfType &operator--()
            {
                decrement();
                return *this;
            }

            SelfType &operator++()
            {
                increment();
                return *this;
            }

            reference operator *() const
            {
                return deref();
            }
        };

        MyStr DumpToDebugString() const;

        void setName(const MyCharType*);
        const MyCharType* getName() const;

        const std::vector<Column2*>& getColumnList() const;

        bool Query(SQLite::Statement& query);
    protected:
        std::vector<Column2*> m_col_list;
        MyStr m_name;
    };

}
