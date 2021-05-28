#include "gtest.h"
#include<Windows.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int flag= RUN_ALL_TESTS();
    std::cout << "PRESS ENTER TO EXIT\n";
    while (getchar() != '\n');
    return flag;
}