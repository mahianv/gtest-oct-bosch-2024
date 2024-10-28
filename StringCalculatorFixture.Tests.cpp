#include "StringCalculator.h"
#include <gtest/gtest.h>

//fixture class
class StringCalculatoreAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void Setup() override{
    objUnderTest=new StringCalculator();
  }
  void Teardown(){
    delete objUnderTest;
  }
};

TEST_F(StringCalcultorAddFixture, return_0_for_Empty(){
string input="";
int expectedValue=0;
int actualValue =objUnderTest ->Add(input);
ASSERT_EQ(actualValue,expectedValue);


