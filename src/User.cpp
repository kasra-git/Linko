#include "../include/User.hpp"

User::User(
    std::string co_userName,
    std::string co_password,
    std::string co_displayName,
    std::string co_bio
): userName(co_userName) , password(co_password) , displayName(co_displayName) , bio(co_bio){}