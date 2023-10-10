#include <iostream>
using namespace std;

class node
{
	public:
		char pizza_name[100];
		char size[100];
		int price;
		int quantity;
		int total_price;
		node *next;	
};


class cll
{
	public:
		node *head;
		
		cll()
		{
			head= NULL;
		}
		
		void insert (node *temp);
		void del();
		void disp();
		
};

void cll::insert(node *temp)
{
    node *p = head;
    if (head == NULL)
    {
        head = temp;
        temp->next = temp; 
    }
    else
    {
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
    
    }
}


void cll::disp()
{
    if (head == NULL)
    {
        cout << "Order list is empty." << endl;
        return;
    }

    node *temp = head;
    cout << "Pizza Orders:" << endl;
    do
    {
        cout << "Pizza Name: " << temp->pizza_name << endl;
        cout << "Size: " << temp->size << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "Total Price: " << temp->total_price << endl;
        cout << "---------------------" << endl;

        temp = temp->next;
    } while (temp !=head);
}

void cll::del()
{
	if (head == NULL)
	{
		cout<<"Order list is empty"<<endl;
		exit(0);
	}
	node *p=head;
	while (p->next !=head)
	p=p->next;
	p->next=head->next;
	p=head;
	head=head->next;
	delete p;
	
}

int main()
{
    int choice;
    cout << "Welcome to the Pizza Center" << endl;
    cll pizzaOrderList;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Place Order\n2. Take Order\n3. Display Orders\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            node *temp = new node;
            temp->next = temp;

            cout << "Enter Pizza Name: ";
            cin >> temp->pizza_name;

            cout << "Enter Pizza Size: ";
            cin >> temp->size;

            cout << "Enter Pizza Quantity: ";
            cin >> temp->quantity;

            cout << "Enter Pizza Price: ";
            cin >> temp->price;

            temp->total_price = temp->price * temp->quantity;

            pizzaOrderList.insert(temp);
            break;
        }
        case 2:
            pizzaOrderList.del();
            cout << "Latest order removed." << endl;
            break;
        case 3:
            pizzaOrderList.disp();
            break;
        case 4:
            exit(0);

        }
    }

    return 0;
}
