#include <iostream>

using namespace std;
#define Max 100
template<class T>                                                               //ساختار  پشته اصلی
struct Stack
{
    T Array[Max];
    int top;
    Stack()
    {
        top = -1;
    }
    bool Empty(){
        return top == -1;
    }
    void push(T x)
    {
        if(top<Max-1)
        {
            Array[++top] = x;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }
    T pop()
    {
        if(!Empty())
        {
            return Array[top--];
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
            return T(-1);
        }
    }
    T peek()
    {
        if(!Empty())
        {
            return Array[top];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return T(-1);
        }
    }
};

template <class T>                                                               //پشته ی دوم برای مرتب سازی
void sortStack(Stack<T> & input)
{
    Stack<T> tempStack;
    while(!input.Empty())
    {
        T z = input.pop();
        while(!tempStack.Empty()&& tempStack.peek() > z)                        // مرتب سازی عناصر داخل پشته ی دوم
        {
            input.push(tempStack.pop());
        }
        tempStack.push(z);                                                       // اضافه کردن عنصر به پشته ی دوم
    }
    while(!tempStack.Empty())                                                   // انتقال عناصر به پشته ی اصلی
    {
        input.push(tempStack.pop());
    }
}
int main()
{
    Stack<int> inputStack;
    int num;
    cout<<"Enter -1 to stop !!!\nEnter your number to sort:"<<endl;
    while(true){                                                                 // گرفتن اعداد از ورودی
        cin>>num;
        if(num == -1)
            break;
        inputStack.push(num);
    }

    sortStack(inputStack);

    cout<<"Numbers after Sorting: ";
    while(!inputStack.Empty()){
        cout<<inputStack.pop()<<"  ";
    }
    return 0;
}