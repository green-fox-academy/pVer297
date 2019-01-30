//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "BlogPost.h"

BlogPost::BlogPost(std::string authorName_, std::string title_, std::string publicationDate_, std::string text_)
{
    setAuthorName(authorName_);
    setTitle(title_);
    setPubDate(publicationDate_);
    setText(text_);
}