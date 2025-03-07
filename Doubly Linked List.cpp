#include <iostream>
using namespace std;
class Node;
Node *head = NULL;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int d)
    {
        data = d;
        next = NULL;
        previous = NULL;
    }
};
class LinkedList
{
public:
//  Lab 7 _ Doubly Linked List
 // Insert At Start
    void insert_at_start(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
     // Insert At Last
    void insert_at_last(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        else{
           Node* temp = head;
           while(temp->next != NULL ){
            temp = temp->next;
           }
           head->previous = newNode;
           temp->next = newNode;
        }
    }
      // Insert At Nth Location
    void insert_at_pos(int pos, int d)
    {

        Node *newNode = new Node(d);
        Node *temp = head;
        {
            if (pos < 1)
            {
                cout << "Invalid Position!" << endl;
            }
            else if (pos == 1)
            {
                Node *newNode = new Node(d);
                newNode->next = head;
                head->previous = newNode;
                return;
            }
            else
            {
                for (int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                    if (temp == NULL)
                    {
                        cout << "Invalid Position." << endl;
                        break;
                    }
                }
            }

                newNode->next = temp->next;
                newNode->previous = temp;
                if(temp->next != NULL){
                    temp->next->previous = newNode;
                }
                temp->next = newNode;
        }
    }
    //  Insert at Center 
    void insert_at_mid(int d)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
    
        if (temp == NULL)
        {
            insert_at_start(d);
        }
        else
        {
            int count = 0;
    
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
    
            int middleNode = (count + 1) / 2;
            temp = head;
    
            for (int i = 1; i < middleNode; i++)
            {
                temp = temp->next;
            }
    
            newNode->next = temp->next;
    
            if (temp->next != NULL)
            {
                temp->next->previous = newNode;
            }
    
            temp->next = newNode;
            newNode->previous = temp;
        }
    }
      //  Display Nodes
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
        //		Display in reverse Order
    void printReverse(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        printReverse(head->next);
        cout << head->data << " ";
    }
};
int main()
{
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
    list.printReverse(head);
    cout << endl;
    cout << " -------------------------------------------- \n";
    cout << "\n";

    return 0;
}