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

// check-password-for-user
bool Network::check_password(
    User& user,
    std::string password
){
    return user.show_hashed_password() == password;
}
