#include "StringCalculator.h"
#include <gtest/gtest.h>

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_Emplty){
//Arrange
StringCalculator objUnderTest;
string input ="";
int expectedValue =;

//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}
