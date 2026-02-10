#include "../include/User.hpp"

User::User(
    const std::string& co_userName,
    const std::string& co_password,
    const std::string& co_displayName,
    const std::string& co_bio
): userName(co_userName) , password(co_password) , displayName(co_displayName) , bio(co_bio){}

std::string User::getUsername()const {return this->userName;}
bool User::checkPassword(const std::string& password)const{return password == this->password;}
void User::follow(const std::string& user){this->following.push_back(user);}
const std::vector<std::string>& User::getFollwing() const {return this->following;}