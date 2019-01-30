//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef BLOG_BLOGPOST_H
#define BLOG_BLOGPOST_H

#include <iostream>

class BlogPost
{
 private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;

 public:
    BlogPost(std::string authorName_, std::string title_, std::string publicationDate_, std::string text_);

    void setAuthorName(std::string authorName_)
    {
        authorName = authorName_;
    }

    std::string getAuthorName()
    {
        return authorName;
    }

    void setTitle(std::string title_)
    {
        title = title_;
    }

    std::string getTitle()
    {
        return title;
    }

    void setPubDate(std::string publicationDate_)
    {
        publicationDate = publicationDate_;
    }

    std::string getPubDate()
    {
        return publicationDate;
    }

    void setText(std::string text_)
    {
        text = text_;
    }

    std::string getText()
    {
        return text;
    }
};

#endif //BLOG_BLOGPOST_H
