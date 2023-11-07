#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.2.2/Lab 7.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:
        TEST_METHOD(TestFindLargestOfMinimums)
        {
            int matrix[3][3] = { { 20, 10, 28 },
                                 { 15, 30, 18 },
                                 { 40, 10, 5 } };
            int* matrixPtr[3];
            for (int i = 0; i < 3; ++i) {
                matrixPtr[i] = matrix[i];
            }

            int result = FindLargestOfMinimums(matrixPtr, 3, 3, 0);

            int expected = 15;

            Assert::AreEqual(result, expected);
        }
    };
}
