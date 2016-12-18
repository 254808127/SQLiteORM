#include "sqliteorm/orm_include.h"

#include <iostream>
#include <functional>

//todo: 
//.Implement attach
//.Embedded cipher
//.Provide the ability to dynamic linkage features of all C++ class

SQLITE_ORM_BEGIN(person)
    SQLITE_ORM_INITIALIZER6(id, name, age, tel, address, email);
SQLITE_ORM_END()

#ifdef _DEBUG
#pragma comment(lib, "../lib/sqlite_orm_Debug.lib")
#else
#pragma comment(lib, "../lib/sqlite_orm_Release.lib")
#endif

int main()
{
    SQLiteORM::SQLDatabase db;
    if (db.open_db("./test.db"))
    {
        person p;
        //e.g. INTO `person` VALUES (254808127,'JXSMS', 'age', '254808127','WuDaoKou','254808127@qq.com')
        auto insert = 
        [&]()
        {            
            p.id.setInt64(254808127);
            p.name.setText("JXSMS");
            p.age.setInt64(18);
            p.tel.setText("254808127");
            p.address.setText("WuDaoKou");
            p.email.setText("254808127@qq.com");
            SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .INSERT.INTO.VALUES(p)
                .END();
        };
        //e.g. SELECT * FROM `person`
        auto search = 
        [&]()
        {
            auto records = 
                SQLiteORM::SQL<person>(&db)
                    .BEGIN()
                    .SELECT.FROM
                    .END().Records;
            for (auto i : records)
                std::cout << i->DumpToDebugString() << std::endl;
        };
        //e.g. UPDATE `person` SET `name`='JiXiangSiMengXiong'
        auto update =
        [&]()
        {
            p.name.setText("JiXiangSiMengXiong");
            SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .UPDATE.SET(p.name)
                .END();
        };
        //e.g. DELETE FROM `person`
        auto remove =
        [&]()
        {
            SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .DELETE.FROM
                .END();
        };

        //e.g. SELECT * FROM `person` WHERE `id`=xxxx
        auto search_id =
        [&](const std::string& id)
        {
            auto records =
                SQLiteORM::SQL<person>(&db)
                    .BEGIN()
                    .SELECT.FROM.WHERE(p.id == id)
                    .END().Records;
            for (auto i : records)
                std::cout << i->DumpToDebugString() << std::endl;
        };

        //e.g. SELECT * FROM `person` WHERE `id`=xxxx AND `name`=xxxx
        auto search_id_and_name =
        [&](const std::string& id, const std::string& name)
        {
            auto records =
                SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .SELECT.FROM.WHERE((p.id == id) && (p.name == name))
                .END().Records;
            for (auto i : records)
                std::cout << i->DumpToDebugString() << std::endl;
        };

        //e.g. SELECT count(*) FROM `person`
        auto get_count =
        [&]()
        {
            auto count =
                SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .SELECT_COUNT.FROM
                .END().RecordCount;
            std::cout << "Number: " << count << std::endl;
        };

        //e.g. SELECT max(`age`) FROM `person`
        auto get_max =
        [&]()
        {
            auto max =
                SQLiteORM::SQL<person>(&db)
                .BEGIN()
                .SELECT_MAX(p.age).FROM
                .END().MaxColumn;
            std::cout << "MaxValue: " << *max << std::endl;
        };

        remove();
        insert();
        search();
        update();
        search_id_and_name("254808127", "JiXiangSiMengXiong");
        get_count();
        get_max();
        db.close_db();
    }
	return 0;
}