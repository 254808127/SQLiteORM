# SQLiteORM preview

目标: 基于C++11实现的SQLite封装  
- 1.让C++的开发者更简单的操作SQLite数据库(开发者只需要了解最基本的SQL语法)。  
- 2.提供一种友好的方式实现数据库记录与C++ Object的序列化和反序列化。  
- 3.支持SQLite加密(在SQLiteCipher的基础上实现)。

编译: 

- 1.Windows: 用vs2015打开SLiteORM/build/windows/sqlite_orm.sln，编译sqlite_orm工程

实例: 参考代码-SLiteORM/src_test/hello_orm.cpp

第三方工具：

- 1.Python 2.7

第三方代码库:

- 1.SQLite https://sqlite.org/ (必须)
- 2.SQLiteCpp https://github.com/SRombauts/SQLiteCpp (必须)
- 3.SQLiteCipher https://www.zetetic.net/sqlcipher/open-source/ (可选)
- 4.OpenSSL https://www.openssl.org/source/ (可选-SQLiteCipher的依赖)

开源协议: FreeBSD