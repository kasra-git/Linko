#ifndef COMMENT_HPP
#define COMMENT_HPP
#include <string>

class Comment{
    public: 
        Comment(const std::string& ,const std::string&);

        std::string getAuthor() const;
        std::string getText() const;
    private:
        std::string author;
        std::string text;
};
#endif