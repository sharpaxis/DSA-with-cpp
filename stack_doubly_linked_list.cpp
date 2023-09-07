#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    };
class Stack{
    Node* top;
    int count;
    public:
    Stack(){
        this->top = nullptr;
        this->count = 0;
    }
    void Push(int data){
        Node* newNode = new Node(data);
        if(top == nullptr){
            top = newNode;
            return;
        }
        newNode->next = top;
        top->prev = newNode;
        top = newNode;
        count++;
    }
    void Pop(){
        if(top == nullptr){
            cout<<"Empty Stack"<<endl;
            return;
        }
        top->next->prev = nullptr;
        top = top->next;
        count--;
    }
    Node* Peek(){
        return top;
    }
    void isEmpty(){
        if(count == 0){
            cout<<"True"<<endl;
            return;
        }
        else{
            cout<<"False";
            return;
        }
    }
    void Display(){
        Node* temp = top;
        while(temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

};
int main(){
    Stack s1 = Stack();
    s1.Push(3);
    s1.Push(1);
    s1.Push(2);
    s1.Push(4);
    s1.Push(7);
    s1.Pop();
    s1.Display();
    
}