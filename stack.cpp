#include <iostream>

using namespace std;

template<class T>
class StackNode
{
private:
    T value_;
    StackNode<T>* next_;
public:
    StackNode<T>(T value, StackNode<T>* next = NULL);
    T value() const;
    StackNode<T>* next() const;
};

template<class T> StackNode<T>::StackNode(T value, StackNode<T>* next)
{
    this->value_ = value;
    this->next_ = next;
}

template<class T> T StackNode<T>::value() const
{
    return this->value_;
}

template<class T> StackNode<T>* StackNode<T>::next() const
{
    return this->next_;
}

template<class T>
class Stack
{
private:
    StackNode<T>* top_;
    int size_;
public:
    Stack();
    void operator=(Stack<T> stack);
    void push(T value);
    void pop();
    void clear();
    T top() const;
    int size() const;
    bool empty() const;
};

template<class T> Stack<T>::Stack()
{
    this->top_ = NULL;
    this->size_ = 0;
}

template<class T> void Stack<T>::operator=(Stack<T> stack)
{
    this->clear();
    this->top_ = stack->top_;
    this->size_ = stack-> size_;
}

template<class T> void Stack<T>::push(T value)
{
    if(this->size_ == 0)
    {
        StackNode<T>* top = new StackNode<T>(value);
        this->top_ = top;
    }
    else
    {
        StackNode<T>* top = new StackNode<T>(value, this->top_);
        this->top_ = top;
    }
    this->size_++;
}

template<class T> void Stack<T>::pop()
{
    StackNode<T>* temp = this->top_;
    this->top_ = temp->next();
    delete temp;
    this->size_--;
}

template<class T> void Stack<T>::clear()
{
    while(!this->empty())
    {
        this->pop();
    }
}

template<class T> T Stack<T>::top() const
{
    return this->top_->value();
}

template<class T> int Stack<T>::size() const
{
    return this->size_;
}

template<class T> bool Stack<T>::empty() const
{
    return this->size_ == 0;
}

int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    Stack<int> st2 = st;
    while(!st2.empty())
    {
        cout<<st2.top()<<endl;
        st2.pop();
    }
    return 0;
}
