#ifndef POST_HPP
#define POST_HPP
#include "Comment.hpp"
#include <string>
#include <vector>

class Post{
    public:
        Post();
    private:
        int id;
        std::string author;
        std::string text;
        int likes;
        std::vector<Comment> comments;
};

#endif