#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");
    std::string replace = "bots";

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

    url.insert(5,":");
    url.replace(url.find(replace),replace.length(),"odds");

    std::cout << url << std::endl;

    return 0;
}