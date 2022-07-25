
#include "gtest/gtest.h"

#include <array>
#include <vector>

typedef int yu;

int main(int argc, char** argv) {
    std::array<int, 10> m;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
