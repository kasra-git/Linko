#ifndef USER_HPP
#define USER_HPP

#include <string>

class User{
    public:
        User(std::string con_u , std::string con_p , std::string con_d , std::string con_b);

        // Getters
        std::string& show_user_name();
        std::string& show_hashed_password();
    private:
        std::string userName;
        std::string password;
        std::string displayName;
        std::string bio;
};

#endif