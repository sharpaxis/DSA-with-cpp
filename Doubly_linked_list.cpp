#include <iostream>
using namespace std;
class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
};
class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void InsertAtHead(int data){
        Node* newNode = new Node(data);
        //empty list case
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void InsertAfter(Node* prev_node,int data){
        if( prev_node == nullptr){
            cout<<"Previous node is empty";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = prev_node->next;
        newNode->prev = prev_node;
        prev_node->next = newNode;
        //conditional last link
        if(newNode->next != nullptr){
            newNode->next->prev = newNode;
        }
        if(prev_node == tail){
            tail = newNode;
        }
    }
    void InsertBefore(Node* next_node,int data){
        if(next_node == nullptr){
            return;
        }
        Node* newNode = new Node(data);
        newNode->prev = next_node->prev;
        next_node->prev = newNode;
        newNode->next = next_node;
        if(newNode->prev != nullptr){
            newNode->prev->next = newNode;
        }
        if(next_node == head){
            head = newNode;
        }
    }
    void InsertAtTail(int data){
        Node* newNode = new Node(data);
        //empty list case
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void InsertAtIndex(int index,int data){
        if(index<=0){
            return;
        }
        Node* temp = head;
        for(int i=0;i<index-2;i++){
            temp = temp->next;
        }
        if(temp == nullptr){
            return;
        }
        this->InsertAfter(temp,data);

    }
    void Display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        } 
        cout<<endl;
    }
    void Rev_Display(){
        Node* temp = tail;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    Node* get_pointer(int index){
        if(index<=0){
            return nullptr;
        }
        Node* temp = head;
        for(int i=0;i<index-2;i++){
            temp = temp->next;
        }
        return temp->next;

    }
    void removeHead(){
        if(head == nullptr){
            return;
        }
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }
        head->next->prev = nullptr;
        head = head->next;
    }
    void removeTail(){
        if(head == nullptr){
            return;
        }
        if(head == tail){
            head= nullptr;
            tail = nullptr;
        }
        tail->prev->next = nullptr;
        tail = tail->prev;
    }
    void delete_obj(Node* node){
        if(node == nullptr){
            return;
        }
        if(node->next != nullptr){
            node->next->prev = node->prev;
        }
        if(node->prev != nullptr){
            node->prev->next = node->next;
        }
        delete node;
    }
    void delete_index(int index){
        if(index<=0){
            return;
        }
        Node* temp = head;
        for(int i=0;i<index-2;i++){
            temp = temp->next;
        }
        if(temp->next != nullptr){
            this->delete_obj(temp->next);
        }
        return;
    }
        
     

};
int main(){
    DoublyLinkedList Dl_1 =  DoublyLinkedList();
    Dl_1.InsertAtHead(4);
    Dl_1.InsertAtHead(2);
    Dl_1.InsertAtHead(7);
    Dl_1.InsertAtHead(5);
    Dl_1.InsertAtTail(3);
    Dl_1.InsertAfter(Dl_1.get_pointer(2),9); 
    Dl_1.InsertAtIndex(4,1);
    Dl_1.InsertBefore(Dl_1.get_pointer(6),6);
    Dl_1.delete_obj(Dl_1.get_pointer(4));
    Dl_1.delete_index(3);
    Dl_1.Display();
    Dl_1.Rev_Display();

}

