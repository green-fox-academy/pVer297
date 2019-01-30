//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "Blog.h"

Blog::Blog(std::vector<BlogPost> posts_)
{
    posts = posts_;
}

void Blog::addPost(BlogPost post)
{
    posts.push_back(post);
}

void Blog::deletePost(int index)
{
    posts.erase(posts.begin() + index);
}

void Blog::updatePost(int index, BlogPost post)
{
    posts.insert(posts.begin() + index, post);
    posts.erase(posts.begin() + index + 1);
}

void Blog::showPost(int index)
{
    std::cout << "\t\t\tPost: " << index << std::endl;
    std::cout << posts[index].getTitle() << std::endl;
    std::cout << "by " << posts[index].getAuthorName() << std::endl;
    std::cout << posts[index].getPubDate() << std::endl << std::endl;

    std::cout << posts[index].getText() << std::endl;
}