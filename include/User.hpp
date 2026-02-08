#ifndef USER_HPP
#define USER_HPP
#include <string>

class User{
    public:
        User();
    private:
        std::string userName;
        std::string password;
        std::string displayName;
        std::string bio;      
};


#endif