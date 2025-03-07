#include <iostream>
using namespace std;

//Lab 8 - Merge two LinkedLists  
class Node {
	public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

//Task 1 - Singly LinkedLists and Merge them and display them.

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
	 head = NULL;
	  }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next){
		temp = temp->next;
		} 
        temp->next = newNode;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    SinglyLinkedList merge(SinglyLinkedList& list2) {
        SinglyLinkedList mergedList;
        Node* temp1 = this->head;
        Node* temp2 = list2.head;

        while (temp1 && temp2) {
            mergedList.insertAtEnd(temp1->data);
            temp1 = temp1->next;
            
            mergedList.insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }

        while (temp1) {
            mergedList.insertAtEnd(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2) {
            mergedList.insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }

        return mergedList;
    }
};
// Task 2 - Double LinkedLists and Merge them and display them.

class DNode {
	public:
    int data;
    DNode* next;
    DNode* prev;
    
    DNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() { 
	head = NULL;
	 }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next){
		 temp = temp->next;
		 }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    DoublyLinkedList merge(DoublyLinkedList& list2) {
        DoublyLinkedList mergedList;
        DNode* temp1 = this->head;
        DNode* temp2 = list2.head;

        while (temp1 && temp2) {
            mergedList.insertAtEnd(temp1->data);
            temp1 = temp1->next;
            
            mergedList.insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }

        while (temp1) {
            mergedList.insertAtEnd(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2) {
            mergedList.insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }

        return mergedList;
    }
};

int main() {
    
    SinglyLinkedList list1, list2;
    
    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);
    
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);
    
    cout << "First Singly Linked List: ";
    list1.display();
    
    cout << "Second Singly Linked List: ";
    list2.display();
    
    SinglyLinkedList mergedSinglyList = list1.merge(list2);
    
    cout << "Merged Singly Linked List: ";
    mergedSinglyList.display();
    
    // Doubly Linked List
    DoublyLinkedList dList1, dList2;
    
    dList1.insertAtEnd(1);
    dList1.insertAtEnd(3);
    dList1.insertAtEnd(5);
    
    dList2.insertAtEnd(2);
    dList2.insertAtEnd(4);
    dList2.insertAtEnd(6);
    
    cout << "\nFirst Doubly Linked List: ";
    dList1.display();
    
    cout << "Second Doubly Linked List: ";
    dList2.display();
    
    DoublyLinkedList mergedDoublyList = dList1.merge(dList2);
    
    cout << "Merged Doubly Linked List: ";
    mergedDoublyList.display();

    return 0;
}
