//implementing stack using Array
//LIFO 
//last inserted element is delete first or taken out first
//prefix to infix
#include<iostream>
#include<cstring>
using namespace std;
#define size 50

class stack{ 
	public: 
	string s[size];
	int top;
	
	stack(){ 
	top = -1;
	}
	
	bool isEmpty();
	bool isFull();
	void push(string s1);
	string pop();
	
};

class stack1{ 

	public: 
	int a[50];
	int top;

	stack1(){
		top=-1;
	}

	int pop1(){ 
		int temp;
		if(top==-1)
		return 0;
		else{
			temp = a[top];
			top--;
			return temp;
		}
	}
	void push1(int x){
		if(top == 49)
		cout<<"Stack is Full.!"<<endl;
		else{ 
			top++;
			a[top]=x;
		}
	}

};


bool stack::isEmpty(){ 

	if(top==-1)
	return true;
	else 
	return false;
}

bool stack::isFull(){ 

	if(top==size-1)
	return true;
	else 
	return false;
}

void stack::push(string s1){ 

	if(isFull()){ 
	cout<<"Stack is Full"<<endl;
	return;
	}
	else{
	
	top++;
	s[top] = s1;
	}
}

string stack::pop(){ 
	string temp;
	if(isEmpty()){ 
	cout<<"Stack is Empty"<<endl;

	}
	
	else
	{ 
	temp = s[top];
	top--;
	return temp;
	}

}


class expression{ 	
public: 
string infix,prefix,postfix;
stack stk;
stack1 stk1;

bool isoperator(char x){ 

	if(x == '+'|| x=='-'|| x=='*'|| x=='/'|| x=='^'|| x=='%')
	return true;
	else
	return false;
	
}	

int checkPrecedence(string x);
void infix_to_posfix();
void postfixEval();

void prefix_to_infix(){ 

	cout<<"Enter Expression: "<<endl;
	cin>>prefix;
	
	int count = prefix.length();

	for(int i = count-1; i>=0 ; i--){ 
	
	if(isoperator(prefix[i])){ 
	
	string op1 = stk.pop();
	string op2 = stk.pop();
	
	string temp = "("+op1+prefix[i]+op2+")";
//	cout<<"Temp "<<temp<<endl;
	stk.push(temp);
	
	}
	
	else 
	stk.push(string(1,prefix[i]));	

	}
cout<<stk.pop();
}		

};

void expression::postfixEval(){ 

	string postfix;

	cout<<"Enter Postfix expression: "<<endl;
	cin>>postfix;

	int len = postfix.length();

	for(int i=0; i<len; i++){ 

		if(postfix[i]==' '){
			continue;
		}

		else if(isdigit(postfix[i])){ 

			int num  = 0;
			while(isdigit(postfix[i])){

				num =  num * 10 + (postfix[i]-'0');
				i++;
			}
				i--;
			
			cout<<"Num is: "<<num<<endl;
			stk1.push1(num);
		}


		else if(isoperator(postfix[i])){ 
			int temp1 = stk1.pop1();
			int temp2 = stk1.pop1();
			int result;
			if(postfix[i] == '/')
			result = temp1/temp2;
			else if(postfix[i] == '*')
			result = temp1*temp2;
			else if(postfix[i] == '+')
			result = temp1+temp2;
			else if(postfix[i] == '-')
			result = temp1-temp2;
			else if(postfix[i] == '%')
			result = temp1%temp2;

			stk1.push1(result);

		}
	
	}

	cout<<"Ans Is: "<<stk1.pop1()<<endl;

}


int expression :: checkPrecedence(string x){ 

    if(x=="^")
    return 3;
    else if(x=="*" || x=="/")
    return 2;
    else if(x=="+"||x=="-")
    return 1;
    else 
    return 0;

}

void expression :: infix_to_posfix(){

    cout<<"Enter Expression: "<<endl;
	cin>>infix;
    int count = infix.length();
    cout<<infix<<endl;

    for(int i=0; i<count; i++){ 

        if((infix[i]>='a'&& infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')){ 
            postfix = postfix + infix[i];
        }
        
        else if(infix[i]=='(')
            stk.push(string(1,infix[i]));

        else if(infix[i]==')')
            { 
                while((stk.s[stk.top]) != "(" || stk.isEmpty())
                {
                string temp4 = stk.pop();
                postfix = postfix + temp4;
                }
                if(stk.s[stk.top]=="("){ 
                    string temp7 = stk.pop();
                }
            }
        else{ 
            while(checkPrecedence(string(1,infix[i]))<=checkPrecedence(stk.s[stk.top])){ 
                string temp5 = stk.pop();
                postfix = postfix + temp5;
            }
            stk.push(string(1,infix[i]));
        }

    }

    while(stk.top!=-1){ 
        string t6 = stk.pop();
        postfix+=t6;
    }

    cout<<"PostFix: "<<postfix<<endl;

}


//postfix evalution



int main(){ 

	stack s1;
//	s1.push("sachin");
//	s1.pop();
	
	expression e;
	// e.infix_to_posfix();
	e.postfixEval();
	
	return 0;
}
