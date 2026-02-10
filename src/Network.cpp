#include "../include/Network.hpp"

Network::Network():nextPostID(1){}

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

Post& Network::createPost(const std::string& author,const std::string& text){
    posts.emplace_back(nextPostID++ , author,text);
    return posts.back();
}

std::vector<Post>& Network::getPosts() {
    return posts;
}