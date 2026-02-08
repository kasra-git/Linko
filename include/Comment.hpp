#ifndef COMMENT_HPP
#define COMMENT_HPP
#include <string>

class Comment{
    public: 
        Comment(std::string , std::string);
    private:
        std::string author;
        std::string text;
};
#endif