#include <gtest/gtest.h>
#include "../engine/src/core/Logger.h"

TEST(LoggerTest, LogMessage) {
    EXPECT_NO_THROW(Logger::Log("Test message"));
}
