#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
  public: 
   std::vector<int> arr;
   int last;
   PriorityQueue(){
   }
   void insert(int data){
       arr.push_back(data);
       // check correct order and move upward. if not in order swap the content (single path)
       int childIndex = arr.size() - 1;
       while(childIndex > 0){
           int parentIndex = (childIndex - 1)/2;
           if(arr[parentIndex] > arr[childIndex])
              swap(arr[parentIndex],arr[childIndex]);
           else break;
           childIndex = parentIndex;
       }
   }
   int removeElement(){
       if(arr.size() == 0)
         return -1;
       
       swap(arr[0] , arr[arr.size() - 1]);
       int data = arr[arr.size() - 1];
       arr.pop_back();
       downHeap();
       return data;
   }
   void downHeap(){
       int rootIndex = 0;
       while(true){
           int left = 2 * rootIndex + 1;
           int right = 2 * rootIndex + 2;
           
           int prevRoot = rootIndex;
           if(left < arr.size() && arr[left] < arr[rootIndex])
              rootIndex = left;
           if(right < arr.size() && arr[right] < arr[rootIndex])
              rootIndex = right;
            
           if(prevRoot != rootIndex)
               swap(arr[prevRoot] , arr[rootIndex]);
           else break;
       }
   }
};
int main()
{   
    PriorityQueue p;
    p.insert(13);
    p.insert(9);
    p.insert(30);
    p.insert(1);
    p.insert(3);
    p.insert(8);
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    cout<<p.removeElement()<<endl;
    return 0;
}
