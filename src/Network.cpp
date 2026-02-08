#include "../include/Network.hpp"
#include <string>

void Network::add_user(
    std::string new_userName,
    std::string new_password,
    std::string new_displayName,
    std::string new_bio
){
    users.push_back(User(new_userName,new_password,new_displayName,new_bio));
}