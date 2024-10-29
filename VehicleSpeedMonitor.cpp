#include "VehicleSpeedMonitor.h"
void SpeedMonitpr::monitor(){
            if(_speedThreshold  < 1 || _speedThreshold > 100){
              cout<<"_speedThreshold value must be in the ramge {1-100} "<<_speedThreshold<<endl;
            }
              
            BNFSpeedSensor speedSensorInstance;
            IOTCloudCommunicator cloudCommuniccator;
            int currentSpeedInKmph=speedSensorInstance.getCurrentSpeed();
            
            cout<<"Current Speed In Kmph "<<currentSpeedInKmph<<endl;
            if(currentSpeedInKmph > _speedThreshold){
                  double mph = currentSpeedInKmph * 0.621371;
                  string message="Current Speed in Miles "+ to_string(mph);
                 int statusCode= cloudCommuniccator.pushMessage(message);
                  if(statusCode > 400){
                      //Log Message to Console
                       cout<<"Error In Communication Unable to Contact Server "<<message<< endl;
                  }
                 
            }
              
          }
