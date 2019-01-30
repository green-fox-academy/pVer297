//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H

#include "BlogPost.h"
#include <vector>

class Blog
{
 private:
    std::vector<BlogPost> posts;
 public:
    Blog() = default;
    Blog(std::vector<BlogPost> posts_);

    void addPost(BlogPost post);
    void deletePost(int index);
    void updatePost(int index, BlogPost post);
    void showPost(int index);
};

#endif //BLOG_BLOG_H
