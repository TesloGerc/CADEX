#include <string>

class RadiusException
{
public: 
    RadiusException(std::string message): message{message}{}
    std::string getMessage() const {return message;}
private:
    std::string message;
};