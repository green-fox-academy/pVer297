#include <iostream>
#include <vector>
#include "Blog.h"
#include "BlogPost.h"

int main()
{
    BlogPost loremIpsum("John Doe", "Lorem Ipsum", "2000.05.04", "");
    loremIpsum.setText("Lorem ipsum dolor sit amet.");

    BlogPost butWhy("Tim Urban", "Wait but why", "2010.10.10", "");
    butWhy.setText("A popular long-form, stick-figure-illustrated blog about almost everything.");

    BlogPost ibm("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "2017.03.28", "");
    ibm.setText("Daniel Hanley, a cybersecurity engineer at IBM, doesn't want to be the center of attention.\n"
                "When I asked to take his picture outside one of IBM's New York City offices,\n"
                "he told me that he wasn't really into the whole organizer profile thing.");

    Blog blog;

    blog.addPost(loremIpsum);
    blog.addPost(butWhy);
    blog.addPost(ibm);

    blog.showPost(0);
    blog.showPost(1);
    blog.showPost(2);

    blog.addPost(ibm); //post index 3

    blog.showPost(3);

    blog.updatePost(3, butWhy);

    blog.showPost(3);

    blog.showPost(0);
    blog.deletePost(0);
    blog.showPost(0);
    return 0;
}