#include<iostream>
#define MAX 10
using namespace std;


class sparse_matrix
{
	int data[MAX][3];
	int len;
	public:
		sparse_matrix(int r, int c, int l)
		{
			data[0][0]=r;
			data[0][1]=c;
			data[0][2]=l;
			len=0;
		}
		void insert(int, int, int);
		void display();
		void add(sparse_matrix);
		sparse_matrix transpose();
		void multiply(sparse_matrix);
};

void sparse_matrix::insert(int r, int c, int v)
{
  data[len+1][0]=r;
  data[len+1][1]=c;
  data[len+1][2]=v;
  len++;	
}


void sparse_matrix::display()
{
	cout<<"Row \t Col \t Val"<<endl;
	for(int i=0;i<data[0][2]+1;i++)
	{
		cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<endl;
	}
}

sparse_matrix sparse_matrix::transpose()
{
	sparse_matrix t(data[0][1],data[0][0],data[0][2]);
	for(int i=0;i<data[0][1];i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(data[j][1]==i)
			{
				t.data[t.len+1][0]=data[j][1];
				t.data[t.len+1][1]=data[j][0];
				t.data[t.len+1][2]=data[j][2];
				t.len++;
			}
		}
	}
	return t;
}


void sparse_matrix::add(sparse_matrix s1)
{


int s2pos=1;
int s1pos=1;
sparse_matrix result(data[0][0],data[0][1],0);

while (s2pos <= len && s1pos <= s1.len)
{

	if(data[s2pos][0]>s1.data[s1pos][0] || data[s2pos][0]==s1.data[s1pos][0] && data[s2pos][1]>s1.data[s1pos][1])
	{
		result.insert(s1.data[s1pos][0],s1.data[s1pos][1],s1.data[s1pos][2]);
		s1pos++;
	}
	else if(data[s2pos][0]<s1.data[s1pos][0] || data[s2pos][0]==s1.data[s1pos][0] && data[s2pos][1]<s1.data[s1pos][1])
	{
	result.insert(data[s2pos][0],data[s2pos][1],data[s2pos][2]);
		s2pos++;	
	}
	else
	{
		int addval=data[s2pos][2]+s1.data[s1pos][2];
		if(addval!=0)
		{
		result.insert(data[s2pos][0],data[s2pos][1],addval);	
		s2pos++;
		s1pos++;
		}
	}
}
while(s2pos<=len)
{
	result.insert(data[s2pos][0],data[s2pos][1],data[s2pos][2]);
	s2pos++;
}
while(s1pos<=s1.len)
{
	result.insert(s1.data[s1pos][0],s1.data[s1pos][1],s1.data[s1pos][2]);
	s1pos++;
}
result.data[0][2]=result.len;
result.display();
}

void sparse_matrix::multiply(sparse_matrix s2) {
    if (data[0][1] != s2.data[0][0]) {
        cout << "Matrix multiplication not possible due to incompatible dimensions." << endl;
        return;
    }

    sparse_matrix s2t = s2.transpose();
    sparse_matrix result(data[0][0], s2.data[0][1], 0);

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= s2t.len; j++) {
            if (data[i][1] == s2t.data[j][1]) {
                int val = 0;
                for (int k = 1; k <= s2.len; k++) {
                    if (s2t.data[j][0] == s2.data[k][0]) {
                        val += data[i][2] * s2.data[k][2];
                    }
                }
                if (val != 0) {
                    result.insert(data[i][0], s2t.data[j][0], val);
                }
            }
        }
    }

    result.data[0][2] = result.len;
    result.display();
}

int main()
{ 
    int r,c,v;
	int r1,c1,l1; 
	//sparse_matrix b;
	cout<<"\n Enter the rows of First Sparce_matrix = ";
	cin>>r1;
	cout<<"\n Enter the columns of First Sparce_matrix = ";
	cin>>c1;
	cout<<"\n Enter the number of non zero elements = ";
	cin>>l1;
	sparse_matrix s1(r1,c1,l1);
	
	for(int i=0; i<l1; i++)
{
	cout<<"Enter Row number= ";
	cin>>r;
	cout<<"Enter Column number= ";
	cin>>c;
	cout<<"number of nonzero element= ";
	cin>>v;
	s1.insert(r,c,v);
}
    s1.display();
	
	int r2,c2,l2;
	cout<<"\n Enter the rows of second Sparce_matrix = ";
	cin>>r2;
	cout<<"\n Enter the columns of second Sparce_matrix = ";
	cin>>c2;
	cout<<"\n Enter the number of non zero elements = ";
	cin>>l2;
	sparse_matrix s2(r2,c2,l2);


 
 for(int i=0; i<l2; i++)
{
	cout<<"Enter Row number= ";
	cin>>r;
	cout<<"Enter Column number= ";
	cin>>c;
	cout<<"number of nonzero elements= ";
	cin>>v;
	s2.insert(r,c,v);
}
   s2.display();
   int choice;
    cout<<"1.transpose\n 2.Addition\n 3.Multiplication";
   cout<<"Enter your choice= ";
   cin>>choice;

   switch(choice)
   {
   case 1:
   cout<<"Transpose "; 
   s1 = s1.transpose();
   s1.display();
   break;
   
   case 2:
   cout<<"Addition ";
   s1.add(s2);
   break;
   
   case 3:
   cout<<"Multiplication ";
   s1.multiply(s2);
   break;
}
   return 0;
}

/*Enter the rows of First Sparce_matrix = 3

 Enter the columns of First Sparce_matrix = 3

 Enter the number of non zero elements = 2
Enter Row number= 1
Enter Column number= 2
number of nonzero element= 2
Enter Row number= 2
Enter Column number= 3
number of nonzero element= 6
Row      Col     Val
3       3       2
1       2       2
2       3       6

 Enter the rows of second Sparce_matrix = 3

 Enter the columns of second Sparce_matrix = 3

 Enter the number of non zero elements = 2
Enter Row number= 1
Enter Column number= 2
number of nonzero elements= 7
Enter Row number= 3
Enter Column number= 2
number of nonzero elements= 8
Row      Col     Val
3       3       2
1       2       7
3       2       8
1.transpose
 2.Addition
 3.MultiplicationEnter your choice= 2
Addition Row     Col     Val
3       3       3
1       2       9
2       3       6
3       2       8

--------------------------------
Process exited after 62.41 seconds with return value 0
Press any key to continue .*/

