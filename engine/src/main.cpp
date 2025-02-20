#include "core/Logger.h"

int main() {
    Logger::Log("Hello, World!");
    Logger::Info("Well, this ain't looking like an info.");
    Logger::Warning("But here's a warning for you;");
    Logger::Error("Don't write a buggy code.");
    Logger::Debug("Cuz then you'd spend so much time on debugging.");
    return 0;
}
