#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>
#include "User.hpp"

class User;
class Network{
    public:
        bool add_user(std::string,std::string,std::string,std::string);
    private:    
        std::vector<User> users;

};

#endif