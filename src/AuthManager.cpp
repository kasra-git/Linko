#include "../include/AuthManager.hpp"

AuthManager::AuthManager(Network& n) : network(n){}

bool AuthManager::registerUser(
    const std::string& u,
    const std::string& p,
    const std::string& d,
    const std::string& b
){return network.addUser(User(u,p,d,b));}


User* AuthManager::login(const std::string& u,const std::string& p){
    User* user = network.getUser(u);
    if(user && user->checkPassword(p))
        return user;
    return nullptr;
}