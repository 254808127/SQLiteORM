#include "sqliteorm/orm_performance.h"

namespace SQLiteORM
{

    AutoTickCount::AutoTickCount(const std::string& append, callback fun) : fun_(fun), append_(append)
    {
        start_ = SC::now();
    }

    AutoTickCount::~AutoTickCount()
    {
        end_ = SC::now();
        std::chrono::duration<double> d = end_ - start_;
        if (fun_)
            fun_(append_, d.count());
    }
}