# SQLiteORM preview

PURPOSE: A simple encapsulation of SQlite based on C++1x.
- 1.Supported C++ developer an easy way to use sqlite.
- 2.Supported a friendly implement of serialization and deserialization between C++ object and sqlite record.
- 3.Supported sqlite cryption.

BUILD:
- 1.Windows: Open soluntion file ./SLiteORM/build/windows/sqlite_orm.sln, BUILD project 'sqlite_orm_test'.

EXAMPLE: Check source code ./SLiteORM/src_test/hello_orm.cpp

THIRD PARTY TOOLS：

- 1.Python 2.7

THIRD PARTY LIBRARIES:

- 1.SQLite https://sqlite.org/ (required)
- 2.SQLiteCpp https://github.com/SRombauts/SQLiteCpp (required)
- 3.SQLiteCipher https://www.zetetic.net/sqlcipher/open-source/ (optional)
- 4.OpenSSL https://www.openssl.org/source/ (optional, SQLiteCipher dependency)

Open source license: FreeBSD