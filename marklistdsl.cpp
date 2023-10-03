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
			head=NULL;
			
		}
		
		int create();
		void display();
		node* swap(node *p1,node *p2);
		void sort(int count);
		void marge(marklist l1,marklist l2);
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

    } while (ch == 'y');

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
    node **h;
    int i, j, swapped;
    for (i = 0; i < count; i++) 
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

int main()
{
    marklist l1, l2;
    int count1, count2;

    cout << "Creating Mark List 1:" << endl;
    count1 = l1.create();
    cout << "\nCreating Mark List 2:" << endl;
    count2 = l2.create();

    cout << "\nDisplaying Mark List 1:" << endl;
    l1.display();
    cout << "\nDisplaying Mark List 2:" << endl;
    l2.display();
    
    	return 0;
}





 




















