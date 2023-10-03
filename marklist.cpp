#include <iostream>
using namespace std;

class node
{
public:
    int roll_no;
    float marks;
    node *next;
    node *prev;
};

class marklist
{
public:
    node *head;
    marklist()
    {
        head = NULL;
    }

    int create();
    void display();
    node *swap(node *p1, node *p2);
    void sort(int count);
    void merge(marklist l1, marklist l2); // Corrected function name from "marge" to "merge"
};

int marklist::create()
{
    node *temp;
    int len = 0; // Initialize len to 0
    char ch;
    do
    {
        len++; // Increment len
        temp = new node;
        cout << "Enter the roll_no: ";
        cin >> temp->roll_no;
        cout << "Enter the mark: ";
        cin >> temp->marks;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout << "Do you want to add more nodes (y/n): ";
        cin >> ch; // Read the user's input

    } while (ch == 'y' || ch == 'Y'); // Corrected the condition

    return len; // Return the length of the list
}

void marklist::display()
{
    node *p = head;
    cout << "\nRoll_no\t\tMarks" << endl;
    while (p != NULL)
    {
        cout << p->roll_no << "\t\t" << p->marks << endl;
        p = p->next;
    }
}

node *marklist::swap(node *p1, node *p2)
{
    p1->next = p2->next;
    p2->prev = p1->prev;
    p1->prev = p2;
    p2->next = p1;
    if (p1->next != NULL)
    {
        p1->next->prev = p1;
    }
    if (p2->prev != NULL)
    {
        p2->prev->next = p2;
    }
    return p2;
}

void marklist::sort(int count)
{
    node **h;
    int i, j, swapped;
    for (i = 0; i < count; i++) // Corrected the loop condition
    {
        h = &(head);
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            node *p1 = *h;
            node *p2 = p1->next;
            if (p1->marks > p2->marks)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void marklist::merge(marklist l1, marklist l2)
{
    node *temp1 = l1.head;
    node *temp2 = l2.head;

    while (temp1 != NULL)
    {
        create();
        head->roll_no = temp1->roll_no;
        head->marks = temp1->marks;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        create();
        head->roll_no = temp2->roll_no;
        head->marks = temp2->marks;
        temp2 = temp2->next;
    }
}

int main()
{
    marklist l1, l2, mergedList;
    int count1, count2;

    cout << "Creating Mark List 1:" << endl;
    count1 = l1.create();
    cout << "\nCreating Mark List 2:" << endl;
    count2 = l2.create();

    cout << "\nDisplaying Mark List 1:" << endl;
    l1.display();
    cout << "\nDisplaying Mark List 2:" << endl;
    l2.display();

    cout << "\nMerging Mark List 1 and Mark List 2:" << endl;
    mergedList.merge(l1, l2);
    mergedList.display();

    cout << "\nSorting Merged List:" << endl;
    mergedList.sort(count1 + count2);
    mergedList.display();

    return 0;
}

