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
string input ="0";
int expectedValue =0;
//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}
TEST(string_calculator_add,when_passed_a_single_number_returns_1_for_One){
//Arrange
StringCalculator objUnderTest;
string input ="1";
int expectedValue =1;

//Act
int actualValue =objUnderTest.Add(input);

//ASSERT
ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add,when_passed_two_comma_delimited_numbers_returns_their_sum) {
    // Arrange
    StringCalculator calculator;
    string input = "1,2";
    int expectedValue = 3;

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_numbers_returns_sum) {
    // Arrange
    StringCalculator calculator;
    string input = "1,2,3";
    int expectedValue = 6;

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}
TEST(string_calcultor_add,when_delimited_with_newline_and_comma_returns_sum){
StringCalculator calculator;
string input = "1\n2,3";
int expectedValue = 6;
// Act
int actualValue = calculator.Add(input);

// Assert
ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_delimiter_returns_the_sum_based_on_that_delimiter ){
StringCalculator calculator;
string input = "//;\n1;2";
int expectedValue = 3;
// Act
int actualValue = calculator.Add(input);

// Assert
ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_negative_numbers_throws_an_exception_listing_invalid_values){
StringCalculator calculator;
string input = "1,-2,-4,5";
try {
        calculator.Add(input);
        FAIL() << "Expected invalid_argument exception";
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Negatives not allowed: -2,-4");
    } catch (...) {
        FAIL() << "Expected invalid_argument exception, but got a different exception";
    }
}

TEST(string_calculator_add, when_passed_numbers_over_1000_ignores_them) {
    // Arrange
    StringCalculator calculator;
    string input = "42,1001,3";
    int expectedValue = 45;  // 

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}


TEST(string_calculator_add, when_passed_multicharacter_delimiter_uses_that_delimiter_to_sum_values) {
    // Arrange
    StringCalculator calculator;
    string input = "//[***]\n8***2***3";
    int expectedValue = 13;  

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multiple_delimiters_sums_on_each_delimiter) {
    // Arrange
    StringCalculator calculator;
    string input = "//[*][%]\n4*2%3";
    int expectedValue = 9;  

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add,when_passed_multiple_multicharacter_delimiters_sums_on_each_delimiter ) {
    // Arrange
    StringCalculator calculator;
    string input = "//[**][%^]\n4**1%^9";
    int expectedValue = 14;  

    // Act
    int actualValue = calculator.Add(input);

    // Assert
    ASSERT_EQ(actualValue, expectedValue);
}











