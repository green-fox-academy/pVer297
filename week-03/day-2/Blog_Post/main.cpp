#include <iostream>

class BlogPost {
private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;

public:
    BlogPost(std::string authorName_, std::string title_, std::string publicationDate_, std::string text_) {
        setAuthorName(authorName_);
        setTitle(title_);
        setPubDate(publicationDate_);
        setText(text_);
    }

    void setAuthorName(std::string authorName_) {
        authorName = authorName_;
    }

    std::string getAuthorName() {
        return authorName;
    }

    void setTitle(std::string title_) {
        title = title_;
    }

    std::string getTitle() {
        return title;
    }

    void setPubDate(std::string publicationDate_) {
        publicationDate = publicationDate_;
    }

    std::string getPubDate() {
        return publicationDate;
    }

    void setText(std::string text_) {
        text = text_;
    }

    std::string getText() {
        return text;
    }
};

int main() {
    BlogPost firstPost("John Doe", "Lorem Ipsum", "2000.05.04", "");
    firstPost.setText("Lorem ipsum dolor sit amet.");

    BlogPost secondPost("Tim Urban", "Wait but why", "2010.10.10", "");
    secondPost.setText("A popular long-form, stick-figure-illustrated blog about almost everything.");

    BlogPost thirdPost("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "2017.03.28", "");
    thirdPost.setText("Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. "
                      "When I asked to take his picture outside one of IBM’s New York City offices, "
                      "he told me that he wasn’t really into the whole organizer profile thing.");

    return 0;
}
