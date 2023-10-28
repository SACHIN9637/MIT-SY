#include<iostream>
#include<cstring>
#include<ctype.h>
#include<cmath>

using namespace std;

#define MAX 10

class Stack
{
	public:
		
		int top;
		string S[MAX];
		Stack()
		{
			top = -1;
		}
		
		void push(string temp);
		string pop();
		bool isEmpty();
		bool isFull();
};

class intStack
{
	public:
		
		int top;
		int iS[MAX];
		intStack()
		{
			top = -1;
		}
		
		void push(int temp);
		int pop();
		bool isEmpty();
		bool isFull();
};

class Expression
{
	public:
		string infix, prefix, postfix;
		Stack stk;
		
		bool isOperator(char x);
		void prefix_to_infix();
		int precedence(string x);
		void infix_to_postfix();
		void postfix_eval();
};

// Postfix evaluation
void Expression::postfix_eval()
{
	
	intStack S2;
	string postf;
	int first, second, result;
	cout<<"Enter a postfix Expression: ";
	getline(cin, postf);
	int len = postf.length();
	
	for(int i = 0; i < len; ++i)
	{
		if(postf[i] == ' ')
		{
			continue;
		}
		else if(isdigit(postf[i]))
		{
			int num = 0;
			while(isdigit(postf[i]))
			{
				num = num * 10 + (postf[i] - '0');
				i++;
			}
			i--;
			S2.push(num); 

		}
		else {
	
			first = S2.pop();
			second = S2.pop();
			if(postf[i] == '+')
			{
				result = second + first ;
				S2.push(result);
			}
			if(postf[i] == '-')
			{
				result = second - first;
				S2.push(result);
			}
			if(postf[i] == '*')
			{
				result = first * second;
				S2.push(result);
			}
			if(postf[i] == '/')
			{
				result = second / first;
				S2.push(result);
			}
			if(postf[i] == '^')
			{
				result = pow(second, first);
				S2.push(result);
			}
		}

	}
	cout<<"Value of Postfix Expression: "<<S2.pop()<<endl;
}

bool Expression::isOperator(char x)
{
	if(x == '*' || x == '+' || x == '-' || x == '/')
	{
		return true;
	}
	return false;
}

int Expression::precedence(string x)
{
	if(x == "^")
		return 3;
	else if(x == "*" || x == "/")
	{
		return 2;
	}
	else if(x == "+" || x == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// infix to postfix
void Expression::infix_to_postfix()
{
	string temp, inf, pos;
	cout<<"Infix: ";
	getline(cin, inf);
	
	int length = inf.length();
	for(int i = 0; i < length; i++)
	{
		if(inf[i] == '(')
		{
			stk.push(string(1, inf[i]));
		}
		else if(inf[i] == ')')
		{
			do
			{
				temp = stk.pop();
				if(temp != "(")
				{
					break;
				}
				pos = pos + temp;
				
			}
			while(temp != "(");
		}
		else if(isOperator(inf[i]))
		{
			if(precedence(string(1, inf[i])) > precedence(stk.S[stk.top]))
			{
				stk.push(string(1, inf[i]));
			}
			else
			{
				temp = stk.pop();
				pos = pos + temp;
				stk.push(string(1, inf[i]));
			}
		}
		else
		{
			pos = pos + inf[i];
		}
	}
	cout<<"Postfix Expression: "<<pos;
}


// prefix to infix
void Expression::prefix_to_infix()
{
	
	cout<<"Enter a prefix string: ";
	cin>>prefix;
	int len = prefix.length();
	for(int i = len-1; i >= 0; i--)
	{
		if(isOperator(prefix[i]))
		{
			string obj1 = stk.pop();
			string obj2 = stk.pop();
			string tmp = "(" + obj1 + prefix[i] + obj2 + ")";
			stk.push(tmp);
		}
		else
		{
			string s = string(1, prefix[i]);
			stk.push(s);
		}
	}
	cout<<stk.S[0]<<endl;
}

void Stack::push(string temp)
{
	if(isFull())
	{
		cout<<"Stack is Full!\n";
		return;
	}
	else
	{
		top++;
		S[top] = temp;
	}
}

void intStack::push(int temp)
{
	if(isFull())
	{
		cout<<"Stack is Full!\n";
		return;
	}
	else
	{
		top++;
		iS[top] = temp;
	}
}

string Stack::pop()
{
	string tmp;
	if(isEmpty())
	{
		cout<<"Stack is Empty\n";
		return 0;
	}
	else
	{
		tmp = S[top];
		top--;
		return tmp;
	}
}

int intStack::pop()
{
	int tmp;
	if(isEmpty())
	{
		cout<<"Stack is Empty\n";
		return 0;
	}
	else
	{
		tmp = iS[top];
		top--;
		return tmp;
	}
}

bool Stack::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::isFull()
{
	if(top == MAX - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool intStack::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool intStack::isFull()
{
	if(top == MAX - 1)
	{  
		return true;
	}
	else
	{
		return false;
	}
}

int main()
 {
    Expression S1;
    int choice;

    while (true)
	 {
        cout << "Menu:" << endl;
        cout << "1. Postfix Evaluation" << endl;
        cout << "2. Infix to Postfix Conversion" << endl;
        cout << "3. Prefix to Infix Conversion" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) 
		{
            case 1:
                S1.postfix_eval();
                break;
            case 2:
                S1.infix_to_postfix();
                break;
            case 3:
                S1.prefix_to_infix();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}


























//Menu:
//1. Postfix Evaluation
//2. Infix to Postfix Conversion
//3. Prefix to Infix Conversion
//4. Exit
//Enter your choice: 1
//Enter a postfix Expression: 3 5 2 4 - * +
//Value of Postfix Expression: 13
//Menu:
//1. Postfix Evaluation
//2. Infix to Postfix Conversion
//3. Prefix to Infix Conversion
//4. Exit
//Enter your choice: 2
//Infix: 3 + 5 * ( 2 - 4 )
//Postfix Expression: 3 5 2 4 - * +
//Menu:
//1. Postfix Evaluation
//2. Infix to Postfix Conversion
//3. Prefix to Infix Conversion
//4. Exit
//Enter your choice: 3
//Enter a prefix string: + * 5 - 3 4
//((5*3)-4)
//Menu:
//1. Postfix Evaluation
//2. Infix to Postfix Conversion
//3. Prefix to Infix Conversion
//4. Exit
//Enter your choice: 4
//Exiting the program
