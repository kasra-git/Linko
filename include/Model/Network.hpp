#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include "./User.hpp"

class Network{
    public:
        Network() = default;

        // Register-New-User
        void register_user(std::string user_name , std::string password , std::string display_name , std::string bio);
        bool check_password(User& user,std::string password);
        // Login-User
        User* login_user(std::string user_name , std::string password);
    private: 
        // Vector of users   
        std::vector<User> users;
};
#endif