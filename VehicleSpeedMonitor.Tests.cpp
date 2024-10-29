#include "VehicleSpeedMonitor.h"
#include <gtest/gtest.h>
//Hand Made Mock
class MockLogger:public ILogger{
        public:
            int writeMethodCallCount=0;
            string  writeMethodArg;
            void write(const string& message){
                this->writeMethodArg=message;
                this->writeMethodCallCount+=1;
            }
};
class FakeCommunicator:public IMessageCommunicator{
        public:
            int  pushMessage(const string& message){
                return 400;
            }
};
class FakeSpeedSensor:public ISpeedSensor{
        int getCurrentSpeed(){ return 40;}
};

TEST(VehicleSpeedMonitorTestSuite,AssertValidInstanceWithSpeedThreshold){

    int speedThreshold = 70;  // Sample threshold
    SpeedMonitor monitor{speedThreshold};
     EXPECT_EQ(monitor.getSpeedThreshold(), speedThreshold);
}
TEST(VehicleSpeedMonitorTestSuite, MonitorInteractWithLoggerWhenThresholdIsNotInRange) {
    int speedThreshold = 150;  // Sample threshold
     SpeedMonitor objUnderTest{speedThreshold};
     MockLogger logger;//mockObject
    FakeCommunicator communicator; //stub object
    FakeSpeedSensor sensor; //stub object
     objUnderTest.monitor(&communicator, &sensor, &logger);
    EXPECT_GE(logger.writeMethodCallCount,1);
    string  expectedMessageToBeRecievedByLoggerWrite="_speedThreshold value must be in the ramge {1-100} 150";
    EXPECT_STREQ(writeMethodArg,expectedMessageToBeRecievedByLoggerWrite);
}
