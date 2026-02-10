#ifndef COMMENT_HPP
#define COMMENT_HPP
#include <string>
#include <ctime>

class Comment{
    public: 
        Comment(const std::string& ,const std::string&);

        std::string getAuthor() const;
        std::string getText() const;
        std::time_t getTime() const;
    private:
        std::string author;
        std::string text;
        std::time_t timeStamp;
};
#endif