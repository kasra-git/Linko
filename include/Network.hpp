#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>
#include <map>
#include "User.hpp"
#include "Post.hpp"


class User;
class Network{
    public:
        Network();
        bool addUser(const User& new_user);
        User* getUser(const std::string& user_name);
        std::vector<Post>& getPosts() const;
        Post& createPost(const std::string& author , const std::string& text);
    private:
        std::map<std::string , User> users;
        std::vector<Post> posts;
        int nextPostID;
};

#endif