#ifndef POST_HPP
#define POST_HPP
#include "Comment.hpp"
#include <string>
#include <vector>

class Post{
    public:
        Post(int , const std::string& , const std::string&);

        int getID()const;
        std::string getAuthor()const;
        std::string getText()const;
        int getLikes()const;
        int getCommentCount()const;

        void like();
        void addComment(const Comment& comment);
    private:
        int id;
        std::string author;
        std::string text;
        int likes;
        std::vector<Comment> comments;
};

#endif