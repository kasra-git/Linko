#include "../../include/Model/Network.hpp"
#include <vector>

// Register-new-user
void Network::register_user(
    std::string user_name,
    std::string password,
    std::string display_name,
    std::string bio
){
    users.push_back(std::move(User(user_name,password,display_name,bio)));
    
}

// check-password-for-user to use in login_user() method
bool Network::check_password(
    User& user,
    std::string password
){
    return user.show_hashed_password() == password;
}

// login-user
User* Network::login_user(
    std::string user_name,
    std::string password
){
    for(auto& user : users){
        if (user.show_user_name() == user_name && check_password(user,password))  
            return &user;
    }
    return nullptr;
}