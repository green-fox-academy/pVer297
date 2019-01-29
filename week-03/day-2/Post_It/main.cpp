#include <iostream>

class PostIt {
private:
    std::string backgroundColor;
    std::string textColor;
    std::string text;
public:
    PostIt(std::string bgColor, std::string txtColor, std::string txt) {
        setBackgroundColor(bgColor);
        setTextColor(txtColor);
        setText(txt);
    }

    void setBackgroundColor(std::string bgColor) {
        backgroundColor = bgColor;
    }

    std::string getBackgroundColor() {
        return backgroundColor;
    }

    void setTextColor(std::string txtColor) {
        textColor = txtColor;
    }

    std::string getTextColor() {
        return textColor;
    }

    void setText(std::string txt) {
        text = txt;
    }

    std::string getText() {
        return text;
    }
};


int main() {
    PostIt orangePost("orange", "blue", "Idea 1");
    PostIt pintPost("pink", "black", "Awesome");
    PostIt yellowPost("yellow", "green", "Superb!");

    return 0;
}