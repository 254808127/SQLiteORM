#pragma once

#include <iostream>
#include <chrono>
#include <functional>

namespace SQLiteORM
{
    class AutoTickCount
    {
        typedef std::chrono::system_clock SC;
        typedef std::chrono::time_point<SC> TP;

    public:
        typedef std::function<void(const std::string& append, double d)> callback;

        AutoTickCount(const std::string& append, callback fun);
        ~AutoTickCount();
    private:
        callback fun_;
        const std::string& append_;
        TP start_;
        TP end_;
    };
}

#define WCOUT_ATC() \
    std::string __fn__ = __FUNCTION__; \
    AutoTickCount __atc__(__fn__, [](const std::string& append, double d){ \
    });

#define ODS_ATC() \
    std::string __fn__ = __FUNCTION__; \
    AutoTickCount __atc__(__fn__, [](const std::string& append, double d){ \
    });

#define ODS_ATC_U(UNIQUE) \
    std::string __##UNIQUE##_fn__ = __FUNCTION__; \
    AutoTickCount __##UNIQUE##_atc__(__##UNIQUE##_fn__, [](const std::wstring& append, double d){ \
    });
