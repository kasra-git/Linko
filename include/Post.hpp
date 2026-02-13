#ifndef POST_HPP
#define POST_HPP
#include "Comment.hpp"
#include <string>
#include <vector>
#include <unordered_set>


class Post{
    public:
        Post(int , const std::string& , const std::string&);

        int getID()const;
        std::string getAuthor()const;
        std::string getText()const;
        int getLikes()const;
        bool addLike(const std::string& username);
        int getCommentCount()const;
        const std::unordered_set<std::string>& getLikedUsers() const;
        void addComment(const Comment& comment);
    private:
        int id;
        std::string author;
        std::string text;
        std::vector<Comment> comments;
        std::unordered_set<std::string> likedUsers;

};

#endif