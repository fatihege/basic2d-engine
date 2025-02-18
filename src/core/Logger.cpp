#include "Logger.h"

#include <chrono>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#undef ERROR
#endif

inline void setConsoleColor(ConsoleColor color) {
#ifdef _WIN32
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (color) {
        case ConsoleColor::Red:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case ConsoleColor::Green:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case ConsoleColor::Yellow:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case ConsoleColor::Blue:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case ConsoleColor::Default:
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
    }
#else
    switch (color) {
        case ConsoleColor::Red:
            std::cout << "\033[31m";
            break;
        case ConsoleColor::Green:
            std::cout << "\033[32m";
            break;
        case ConsoleColor::Yellow:
            std::cout << "\033[33m";
            break;
        case ConsoleColor::Blue:
            std::cout << "\033[34m";
        break;
        case ConsoleColor::Default:
        default:
            std::cout << "\033[0m";
            break;
    }
#endif
}

inline void resetConsoleColor() {
    setConsoleColor(ConsoleColor::Default);
}

std::string Logger::time() {
    const auto now = std::chrono::system_clock::now();
    const auto now_time_t = std::chrono::system_clock::to_time_t(now);
    const auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::tm tm{};

#ifdef _WIN32
    localtime_s(&tm, &now_time_t);
#else
    localtime_r(&now_time_t, &tm);
#endif

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << '-'
            << std::setw(2) << tm.tm_mday << '-'
            << std::setw(4) << (tm.tm_year + 1900) << ' '
            << std::setw(2) << tm.tm_hour << ':'
            << std::setw(2) << tm.tm_min << ':'
            << std::setw(2) << tm.tm_sec << '.'
            << std::setw(3) << now_ms.count();

    return oss.str();
}

void Logger::Log(const std::string &message, const Level level) {
    ConsoleColor color;
    std::string levelStr;

    switch (level) {
        case Level::INFO:
            color = ConsoleColor::Green;
            levelStr = "INFO";
            break;
        case Level::WARNING:
            color = ConsoleColor::Yellow;
            levelStr = "WARNING";
            break;
        case Level::ERROR:
            color = ConsoleColor::Red;
            levelStr = "ERROR";
            break;
        case Level::DEBUG:
            color = ConsoleColor::Blue;
            levelStr = "DEBUG";
            break;
        case Level::LOG:
        default:
            color = ConsoleColor::Default;
            levelStr = "LOG";
            break;
    }

    setConsoleColor(color);
    std::cout << "[" << levelStr << " " << time() << "] " << message;
    resetConsoleColor();
    std::cout << '\n';
}
