

#include <iostream>
using namespace std;
template<class X>
class stackUsingArray
{
  public:
   X *data;
   int nextIndex;
   int capacity;
   
   stackUsingArray(int c){
       capacity = c;
       data = new X[capacity];
       nextIndex = 0;
   }
   void push(X val){
       if(nextIndex == capacity){
         X *temp = new X[2*capacity];
         for(int i=0;i<capacity;i++)
             temp[i] = data[i];
         capacity = 2 * capacity;
         delete [] data;
         data = temp;
       }
       data[nextIndex++] = val;
   }
   void pop(){
       if(nextIndex == 0){
           cout<<"Stack is empty"<<endl;
           return;
       }
       nextIndex--;
   }
   X top(){
       if(nextIndex == -1){
           cout<<"Stack is empty"<<endl;
           return -1;
       }
       return data[nextIndex-1];
   }
   bool empty(){
       return nextIndex == 0;
   }
   int size(){
       return nextIndex;
   }
   void display(){
       int j = nextIndex - 1;
       while(j >= 0)
         cout<<data[j--]<<" ";
       cout<<endl;
   }
};
int main()
{
	stackUsingArray<double> *s = new stackUsingArray<double>(3);
	s->push(3.2);
	s->push(8);
	s->push(1.3);
	s->display();
	cout<<s->size()<<endl;
	cout<<s->top()<<endl;
	cout<<s->empty()<<endl;
	s->pop();
	s->pop();
	s->display();
	s->pop();
	s->pop();
}
