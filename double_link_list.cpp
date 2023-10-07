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
    marklist merge(marklist l1, marklist l2);
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

    } while (ch == 'y' || ch == 'Y');

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
    node *h;
    int i, j, swapped;
    for (i = 0; i < count; i++)
    {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            node *p1 = h;
            node *p2 = p1->next;
            if (p1->marks > p2->marks)
            {
                swap(p1, p2);
                swapped = 1;
            }
            h = h->next;
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

marklist marklist::merge(marklist l1, marklist l2)
{
    node *p = l1.head;
    node *q = l2.head;
    node *r = NULL;
    marklist l3;

   
    l3.head = NULL;

   
    if (p == NULL)
    {
        l3.head = q;
        return l3;
    }

    if (q == NULL)
    {
        l3.head = p;
        return l3;
    }

  
    if (p->marks < q->marks)
    {
        l3.head = p;
        r = p;
        p = p->next;
    }
    else
    {
        l3.head = q;
        r = q;
        q = q->next;
    }

    
    while (p != NULL && q != NULL)
    {
        if (p->marks < q->marks)
        {
            r->next = p;
            p->prev = r;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q->prev = r;
            r = q;
            q = q->next;
        }
    }

    // Handle any remaining nodes in l1 or l2
    while (p != NULL)
    {
        r->next = p;
        p->prev = r;
        r = p;
        p = p->next;
    }

    while (q != NULL)
    {
        r->next = q;
        q->prev = r;
        r = q;
        q = q->next;
    }

    return l3;
}

int main()
{
    marklist l1, l2, l3; 
    int len1, len2;
    
    cout << "Enter data for the first marklist:" << endl;
    len1 = l1.create();
    l1.display();
    l1.sort(len1);

    cout << "\nEnter data for the second marklist:" << endl;
    len2 = l2.create();
    l2.display();
    l2.sort(len2);

    l3 = l3.merge(l1, l2);
    l3.sort(len1 + len2);

    cout << "\nMerged marklist:" << endl;
    l3.display();

    return 0;
}

