#include "../include/Comment.hpp"

Comment::Comment(
    const std::string& author,
    const std::string& text
):author(author),text(text){}

std::string Comment::getAuthor() const {return this->author;}
std::string Comment::getText() const {return this->text;}