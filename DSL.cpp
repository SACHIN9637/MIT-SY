#include<iostream>
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
    void sort(int count);
    node* swap(node*p1,node*p2);
};

int marklist::create()
{
    node *temp;
    int len = 0;
    char ch;

    do
    {
        len++;
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
        cin >> ch;

    } 
	while (ch == 'y');

    return len;
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

void marklist::sort(int count)
{
    if (head == NULL)
    {
        return; 
    }

    node *current = head;
    node *index = NULL;
    float temp;

    for (int i = 0; i < count; i++)
    {
        index = current->next;

        for (int j = 0; j < count - i - 1; j++)
        {
            if (current->marks > index->marks)
            {
                temp = current->marks;
                current->marks = index->marks;
                index->marks = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

node *marklist::swap(node *ptr1, node *ptr2)
{
    if (ptr1->prev != NULL) {
        ptr1->prev->next = ptr2;
    } else {
        head = ptr2;
    }

    if (ptr2->next != NULL) {
        ptr2->next->prev = ptr1;
    }

    node *temp = ptr2->next;
    ptr2->next = ptr1;
    ptr2->prev = ptr1->prev;
    ptr1->next = temp;
    ptr1->prev = ptr2;

    return ptr2; 
}

int main()
{
    marklist list1;
    int count1;

    cout << "Creating Mark List 1:" << endl;
    count1 = list1.create();

    cout << "\nDisplaying Mark List 1:" << endl;
    list1.display();

    cout << "\nSorting Mark List 1:" << endl;
    list1.sort(count1);
    list1.display();

    return 0;
}














