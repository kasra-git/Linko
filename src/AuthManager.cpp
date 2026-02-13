#include "../include/AuthManager.hpp"
#include <functional>

AuthManager::AuthManager(Network& n) : network(n){}

std::string AuthManager::hashPassword(const std::string& password) {
    std::hash<std::string> hasher;
    size_t hashed = hasher(password);
    return std::to_string(hashed);
}


bool AuthManager::registerUser(
    const std::string& u,
    const std::string& p,
    const std::string& d,
    const std::string& b
){
    std::string hashedPassword = hashPassword(p);
    return network.addUser(User(u,hashedPassword,d,b));
}


User* AuthManager::login(const std::string& u,const std::string& p){
    std::string hashedInput = hashPassword(p);
    User* user = network.getUser(u);
    if(user && user->checkPassword(hashedInput))
        return user;
    return nullptr;
}

