// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert_correct(stack<int> &st, int ele)
{
    if(st.empty() or ele > st.top()) {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insert_correct(st,ele);
    st.push(topele);
        
}

void reverse(stack<int> &st)
{
    if(st.empty()) return;
    
    int ele = st.top();
    st.pop();
    reverse(st);
    insert_correct(st,ele);
}

void SortedStack :: sort()
{
   //Your code here
   reverse(s);
}

