#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <string>

//fixture class
class StringCalculatorAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void Setup() override{
    objUnderTest=new StringCalculator();
  }
  void Teardown(){
    delete objUnderTest;
  }
};

TEST_F(StringCalcultorAddFixture, Returns_0_For_Empty){
string input="";
int expectedValue=0;
int actualValue =objUnderTest ->Add(input);
ASSERT_EQ(actualValue,expectedValue);
}

TEST_F(StringCalculatorAddFixture, Returns_0_For_Zero){
  string input ="0";
  int expectedValue =0;
  int actualValue=objUnderTest->Add(input);
  ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorTest, Returns_1_For_One) {
    string input = "1";
    int expectedValue = 1;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Returns_Sum_For_Two_Comma_Delimited_Numbers) {
    string input = "1,2";
    int expectedValue = 3;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Returns_Sum_For_Multiple_Comma_Delimited_Numbers) {
    string input = "1,2,3";
    int expectedValue = 6;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Returns_Sum_When_Delimited_With_Newline_And_Comma) {
    string input = "1\n2,3";
    int expectedValue = 6;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Returns_Sum_When_Using_Custom_Delimiter) {
    string input = "//;\n1;2";
    int expectedValue = 3;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Throws_Exception_For_Negative_Numbers_With_Message) {
    string input = "1,-2,-4,5";

    try {
        calculator->Add(input);
        FAIL() << "Expected invalid_argument exception";
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Negatives not allowed: -2,-4");
    } catch (...) {
        FAIL() << "Expected invalid_argument exception, but got a different exception";
    }
}

TEST_F(StringCalculatorTest, Ignores_Numbers_Over_1000) {
    string input = "42,1001,3";
    int expectedValue = 45;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Uses_Multicharacter_Delimiter_To_Sum_Values) {
    string input = "//[***]\n8***2***3";
    int expectedValue = 13;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Sums_Values_With_Multiple_Delimiters) {
    string input = "//[*][%]\n4*2%3";
    int expectedValue = 9;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorTest, Sums_Values_With_Multiple_Multicharacter_Delimiters) {
    string input = "//[**][%^]\n4**1%^9";
    int expectedValue = 14;
    int actualValue = calculator->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

