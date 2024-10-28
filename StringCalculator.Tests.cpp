#include "StringCalculator.h"
#include <gtest/gtest.h>

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_Empty){
//Arrange
StringCalculator objUnderTest;
string input ="";
int expectedValue =0;

//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add,When_passed_a_single_number_returns_0_for_Zero){
StringCalculator objUnderTest;
string input =0;
int expectedValue =0;
//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}
TEST(string_calculator_add,when_passed_a_single_number_returns_1_for_One){
//Arrange
StringCalculator objUnderTest;
string input =1;
int expectedValue =1;

//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add,when_passed_two_comma_delimited_numbers_ReturnsSumOfTwoCommaDelimitedNumbers) {
    // Arrange
    StringCalculator calculator;
    std::string input = "1,2";
    int expectedValue = 3;

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}






