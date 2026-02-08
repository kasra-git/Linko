#ifndef USER_HPP
#define USER_HPP
#include <string>

class User{
    public:
        User(std::string,std::string,std::string,std::string);
    private:
        std::string userName;
        std::string password;
        std::string displayName;
        std::string bio;      
};


#endif