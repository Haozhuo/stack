#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


// stack implementation in linked list
class Stack
{
public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    int top();
    int size();
    bool empty();
    void print();

private:
    struct Node
    {
        int m_value;
        Node* m_next;
    };

    Node* m_head;
    int m_size;
};

Stack::Stack()
{
    m_head = nullptr;
    m_size = 0;
}

Stack::~Stack()
{
    Node* p;
    for(;m_head != nullptr; m_head = p)
    {
        p = m_head->m_next;
        delete m_head;
    }
}

void Stack::push(int value)
{
    Node* newNode = new Node;
    newNode->m_value = value;

    if(m_head == nullptr)
    {
        m_head = newNode;
        newNode->m_next = nullptr;
        m_size++;
        return;
    }

    newNode->m_next = m_head;
    m_head = newNode;
    m_size++;
}

void Stack::pop()
{
    if(m_head == nullptr)
    {
        cout << "No element to be deleted" << endl;
        exit(1);
    }

    Node* p = m_head;
    m_head = p->m_next;
    delete p;
    m_size--;
}

int Stack::top()
{
    if(m_head == nullptr)
    {
        cout << "No element" << endl;
        exit(1);
    }

    return (m_head->m_value);
}

int Stack::size()
{
    return m_size;
}

bool Stack::empty()
{
    return (m_size == 0);
}

void Stack::print()
{
    Node* p = m_head;
    for(; p!= nullptr; p = p->m_next)
        cout << p->m_value;
}
