#include "../include/Network.hpp"

bool Network::addUser(const User& new_user){
    if (users.count(new_user.getUsername()))
        return false;
    users[new_user.getUsername()] = new_user;
    return true;
}

User* Network::getUser(const std::string& user_name){
    if (!users.count(user_name)) 
        return nullptr;
    return &users[user_name];
}

