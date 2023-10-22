#include <string>

namespace curves
{

class RadiusException
{
public: 
    explicit RadiusException(const std::string& message): message{message}{}
    std::string getMessage() const {return message;}
private:
    std::string message;
};

}