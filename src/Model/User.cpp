#include "../../include/Model/User.hpp"

#include <string>

// Constructor
User::User(
    std::string con_u,
    std::string con_p,
    std::string con_d,
    std::string con_b
) : userName(con_u) , password(con_p) , displayName(con_d) , bio(con_b){}


// Getters
std::string& User::show_user_name(){return userName;}
std::string& User::show_hashed_password(){return password;}