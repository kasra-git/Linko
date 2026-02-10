#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <vector>

class User{
    public:
        User();
        User(const std::string&,const std::string&,const std::string&,const std::string&);
        std::string getUsername() const;
        bool checkPassword(const std::string& password) const;
        void follow(const std::string& user);
        const std::vector<std::string>& getFollwing()const;

    private:
        std::string userName;
        std::string password;
        std::string displayName;
        std::string bio;   
        std::vector<std::string> following;  
};


#endif