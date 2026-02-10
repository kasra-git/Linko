#ifndef AUTH_MANAGER_HPP
#define AUTH_MANAGER_HPP
#include "Network.hpp"
#include <string>

class AuthManager{
    public:
        AuthManager(Network& n);
        bool registerUser(const std::string&,const std::string&,const std::string&,const std::string&);
        User* login(const std::string&,const std::string&);
    private:
        Network& network;
};

#endif