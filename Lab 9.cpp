#include <iostream>
using namespace std;

//Lab 9 - Circular Linked List (Insert & Display Nodes)  
class Node;
Node* head;
class Node {
public:
    int data;
    Node* next;
   Node* previous; 

    Node(int d) {
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

// Insert at first
    void insert_at_start(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

// Insert at last
    void insert_at_last(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

// Insert at Nth location
    void insert_at_pos(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid Position." << endl;
            return;
        }

        Node* newNode = new Node(val);
        if (pos == 1) {
            if (head == NULL) {
                head = newNode;
                head->next = head;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                head = newNode;
            }
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp->next == head) {
                cout << "Invalid Position." << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

// Insert at centre
void insert_at_mid(int d) {
    if (!head) {
        insert_at_start(d);
        return;
    }

    Node* temp = head;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    int middleNode = count / 2;

    temp = head;
    for (int i = 1; i < middleNode; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// display in order
    void display() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << temp->data << " -> ";
        temp = temp->next;

        while (temp != head) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "(head)" << endl;
    }

    void printReverseUtil(Node* curr, Node* stop) {
        if (curr->next == stop) {
            cout << curr->data << " ";
            return;
        }
        printReverseUtil(curr->next, stop);
        cout << curr->data << " ";
    }

    // Display in reverse order
    void printReverse() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }
        cout << "Reverse: ";
        printReverseUtil(head, head);
        cout << endl;
    }
};

int main() {

   LinkedList list;
    cout << " Insertion at Start:  ";
    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_start(30);
    // list.insert_at_start(80);
    list.display();
    cout << " --------------------------------------------------- \n";
    cout << "\n";

    cout << " Insertion at End:  ";
    list.insert_at_last(40);
    list.insert_at_last(50);
    list.display();
    cout << " ------------------------------------------------------------ \n";
    cout << "\n";

    cout << " Insertion at Nth Position:  ";
    list.insert_at_pos(3, 70);
    list.display();
    cout << " -------------------------------------------------------------------------- \n";
    cout << "\n";

    
    cout << " Insertion at Centre Position:  ";
    list.insert_at_mid(1000);
    list.display();
    cout << " -------------------------------------------------------------------------- \n";
    cout << "\n";

    cout << " List:  ";
    list.display();
    cout << " ------------------------------------------------------ \n";
    cout << "\n";

    cout << "List in Reverse Order:";
    list.printReverse();
    cout << endl;
    cout << " -------------------------------------------- \n";
    cout << "\n";


    return 0;
}
