#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Linked_list{
    Node* head;
    public:
    Linked_list(){
        this->head = nullptr;
    }
    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;

    }
    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void Display(){
        Node* temp = head;
        //this will stop at end node as tail->next would be null
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    Node* getHead(){
        return this->head;
    }
// 1 based index and not 0 based
    void insertAtn(int n,int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }
        Node* temp = head;
        for(int i=0;i<n-2;i++){
            temp = temp->next;
        }
        //making next pointer of n-1 point to newNode
        newNode->next = temp->next;
        temp->next = newNode;
    }
    Node* get_pointer(int n){
        Node* temp = head;
        if(head == nullptr){
            return nullptr;
        }
        for(int i=0;i<n-2;i++){
            temp = temp->next;
        }
        return temp->next;

    }
    void insertAfter(Node* prev_node,int data){
        Node* newNode = new Node(data);
        if(prev_node == nullptr){
            return;
        }
        newNode->next = prev_node->next;
        prev_node->next = newNode;
    }
    void deleteAtn(int n){
        if(head==nullptr){
            return;
        }
        Node* temp1 = head;
        if(n==1){
            head = temp1->next;
            delete temp1;
        }
        for(int i=0;i<n-2;i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    void deleteHead(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    void deleteTail(){
        if(head==nullptr){
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

    }


};
int main(){
    Linked_list L_1 = Linked_list();
    L_1.insertAtHead(5);
    L_1.insertAtHead(2);
    L_1.insertAtHead(1);
    L_1.insertAtHead(3);
    L_1.insertAtHead(7);
    L_1.insertAtHead(6);
    L_1.insertAtTail(3);
    L_1.Display();
    L_1.insertAtn(3,5);
    L_1.Display();
    cout<<L_1.getHead()<<endl;
    L_1.insertAfter(L_1.get_pointer(4),9);
    L_1.Display();
    L_1.deleteAtn(2);
    L_1.Display();
    L_1.deleteTail();
    L_1.deleteHead();
    L_1.Display();

}
