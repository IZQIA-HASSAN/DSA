#include"iostream"
using namespace std;
class stack{
	private:
		int arr[5];
		int top;
	public:
		 stack()
		{
			top=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		 bool isempty()
		 {
		 	if(top==-1)
		 	 return true;
		 	 else
		 	 return false;
		 	 
		 }
		 bool isfull()
		 {
		 	if (top==4)
		 		return true;
		 	else 
				 return false;
			 
			 
		 }
		 int push(int add)
		 {
		 	
		 	if(isfull())
		 	{
		 		cout<<"stack full";
			 }
			 else
			 {
			 	top++;
			 	arr[top]=add;
			 }
		 }
		 int pop()
		 {
		 	if(isempty())
		 	{
		 		cout<<"empty";
		 		return 0;
			 }
			 else
			 {
			 	int basket=arr[top];
				 arr[top]=0;
			 	top--;
			 	return basket;
			 }
		 }
		 int count()
		 {
		 	return top+1;
		 }
		 int peek(int index)
		 {
		 	if(isempty())
		 	{
		 		cout<<"empty";
			 }
			 else
			 {
			 	return arr[index];
			 }
		 }
		 int change(int index,int value)
		 {
		 	arr[index]=value;
		 	return index;
		 }
		
};
int main()
{

stack s1;

cout<<s1.count();
	
	
}
