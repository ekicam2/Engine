#pragma once

#include <sstream>
#include <iostream>

#if defined(_DEBUG)
#define ENGINE_DEBUG
#endif

template <typename T>
void LOG(T variable, const char* comment = nullptr)
{
    std::stringstream oss;
    oss << variable;

    if (comment)
        oss << " " << comment;

    oss << " \n";
    std::cout << oss.str();
}

inline void LOG(const char* comment)
{
    std::stringstream oss;
    oss << comment << " \n";
    std::cout << oss.str();
}

inline void __ASSERT(bool condition, std::string comment, std::string fileName, int line)
{
    if (!condition)
    {
        //auto ret = MessageBox(App::GetHWND(), comment.append(L"\n ").append(fileName).append(L" (").append(std::to_wstring(line)).append(L")").c_str(), L"Assertion failed!", MB_ABORTRETRYIGNORE | MB_ICONERROR);
        //switch (ret)
        //{
        //case IDABORT:
        //    App::Exit();
        //    break;
        //default:
        //    // continue working
        //    break;
        //}
    }
}

#ifdef ENGINE_DEBUG
    #define ASSERT(condition, comment) __ASSERT(condition, comment, __FILEW__, __LINE__)
#else
    #define ASSERT(...)
#endif