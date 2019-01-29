//
// Created by Egri Zoltán on 2019. 01. 29..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
private:
    int initValue;
    int currentValue;
public:
    Counter(){
        initValue = 0;
        currentValue = 0;
    }
    Counter(int inputValue){
        initValue = inputValue;
        currentValue = inputValue;
    }
    void add(){
        currentValue++;
    }

    void add(int number){
        currentValue += number;
    }

    int get() {
        return currentValue;
    }

    void reset(){
        currentValue = initValue;
    }
};


#endif //COUNTER_COUNTER_H
