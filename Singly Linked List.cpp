#include <iostream>
using namespace std;
class Node;
Node *head = NULL;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    //		Lab 3 _ Singly Linked List(Insert at End, Insert at Start)
    // Insert At Start
    void insert_at_start(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert At Last
    void insert_At_Last(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //		Lab 4 _ Singly Linked List (Insert at Specific Location)
    // Insert At Any Position
    void insert_at_pos(int pos, int val)
    {
        Node *newNode = new Node(val);
        if (pos < 1)
        {
            cout << "Invalid Position.";
        }
        else if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {

                if (head == NULL)
                {
                    cout << "Invalid Position.";
                    break;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    //		Lab 5 _ Singly Linked List (Display Nodes)
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL \n";
    }

    //    Print Centre Node
    void PrintMiddleNode()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int middleNode = count / 2;
        if (count % 2 == 0)
        {
            temp = head;

            for (int i = 0; i < middleNode - 1; i++)
            {
                temp = temp->next;
            }
            cout << temp->data << " and " << temp->next->data << endl;
        }
        else
        {
            temp = head;

            for (int i = 0; i < middleNode; i++)
            {
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }

    //		Lab 6 _ Singly Linked List (Delete Nodes)
    //	Delete First Node
    void delete_at_start()
    {
        if (head == NULL){
            cout<<"Linked List is empty.";

            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    //  Delete Last Node
    void delete_at_end()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    // Delete Nth Node
    void delete_at_pos(int pos)
    {
        Node *temp = head;

        if (temp != NULL)
        {
            if (pos < 1)
            {
                cout << "Invalid Position.";
            }
            else if (pos == 1)
            {
                delete_at_start();
            }
            else
            {
                for (int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                    if (temp == NULL)
                    {
                        cout << "Invalid Position.";
                    }
                }
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                temp2 = NULL;
                delete temp2;
            }
        }
    }

    // Delete Center Node
    void delete_at_center()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int center = count / 2;
        temp = head;
        for (int i = 0; i < center - 1; i++)
        {
            temp = temp->next;
        }
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    //	Display Nodes after Deletion
    void display_after_deletion()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

};
int main()
{
    SinglyLinkedList list;
    cout << " Insertion at Start:  ";
    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_start(30);
    // list.insert_at_start(80);
    list.display();
    cout << " --------------------------------------------------- \n";
    cout << "\n";

    cout << " Insertion at End:  ";
    list.insert_At_Last(40);
    list.insert_At_Last(50);
    list.display();
    cout << " ------------------------------------------------------------ \n";
    cout << "\n";

    cout << " Insertion at Nth Position:  ";
    list.insert_at_pos(3, 70);
    list.display();
    cout << " -------------------------------------------------------------------------- \n";
    cout << "\n";

    cout << " List:  ";
    list.display();
    cout << " ------------------------------------------------------ \n";
    cout << "\n";

    cout << "Middle Node:  ";
    list.PrintMiddleNode();
    cout << " ------------------------------- \n";
    cout << "\n";

    cout << "Deletion at Start: ";
    list.delete_at_start();
    list.display();
    cout << " ---------------------------------------------------------- \n";
    cout << "\n";

    cout << " Deletion at End: ";
    list.delete_at_end();
    list.display();
    cout << " ----------------------------------------------------- \n";
    cout << "\n";

    list.delete_at_pos(3);
    cout << "After deletion at Any Position: ";
    list.display();
    cout << " ------------------------------------------------------------ \n";
    cout << "\n";

    cout << "Deleting central node:";
    list.delete_at_center();
    list.display();
    cout << " -------------------------------------------- \n";
    cout << "\n";

    cout << "List After Deletion: ";
    list.display_after_deletion();
    cout << " -------------------------------------------- \n";
    cout << "\n";

    return 0;
}