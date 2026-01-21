#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;   
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
class Doublylinkedlist{
private:
    Node* head;
    Node* end;   
public:
    Doublylinkedlist() {
        head = NULL;
        end = NULL;
    }   
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if(head == NULL) {
            head = end = newNode;
        }
        else {
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }  
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Doublylinkedlist list;
    list.insertAtEnd(10);
    list.display();
    return 0;
}