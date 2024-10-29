#include <string>
class ILogger{
    public:
     virtual void write(const string& message)=0;
};
