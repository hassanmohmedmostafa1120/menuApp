#ifndef STACK_H
#define STACK_H
#include <iostream>
#define LOG(str) std::cout<<str<<std::endl //Macors
namespace stack{
class Stack
{

    public:
        Stack();
        Stack(int sizeArray);
        ~Stack();
        Stack(Stack & s);
        void push(int data);
        int pop(int * data);
        void display(void);
        Stack & operator=(const Stack s);
        static int getactiveStacksCount();
    protected:


    private:
        int top;
        int sizeArray;
        int *items;
        // 1. Declare a static variable to count active stacks
        static int activeStacksCount;
};
}
#endif // STACK_H
