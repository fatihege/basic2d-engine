#pragma once

#include <string>

enum class ConsoleColor { Default, Red, Green, Yellow, Blue };

class Logger {
public:
    enum class Level { LOG, INFO, WARNING, ERROR, DEBUG };

    static std::string time();
    static void Log(const std::string &message, Level level = Level::LOG);

    static void Info(const std::string &message, const Level level = Level::INFO) {
        Log(message, level);
    }

    static void Warning(const std::string &message, const Level level = Level::WARNING) {
        Log(message, level);
    }

    static void Error(const std::string &message, const Level level = Level::ERROR) {
        Log(message, level);
    }

    static void Debug(const std::string &message, const Level level = Level::DEBUG) {
        Log(message, level);
    }
};
