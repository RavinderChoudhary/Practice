/**
 *  selectionSort
 *  bubbleSort
 *  RecursionBubbleSort
 *  InsertionSort
 *  RecursionInsertionSort
 *  IterativeMergeSort
 *  QuickSort
 *  IterativeQuickSort
 *  HeapSort
 *  countingSort
 *  RadixSort
**/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> arr){
    for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
    cout<<endl;
}
void selectionSort(vector<int> arr){
    display(arr);
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j])
              minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
    
    display(arr);
}
void bubbleSort(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1])
              swap(arr[j],arr[j+1]);
        }
    }
    
    display(arr);
}
void RecursionBubbleSort(vector<int> arr,int counter = 0){
    if(counter == arr.size()){
        display(arr);
        return;
    }
    for(int j=0;j<arr.size()-1;j++)
      if(arr[j] > arr[j+1])
        swap(arr[j],arr[j+1]);

    RecursionBubbleSort(arr,counter+1);
}
void InsertionSort(vector<int> arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
       int j = i - 1;
       int temp = arr[i];
       while(j >= 0 && temp < arr[j]){
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = temp;
    }
    
    display(arr);
}
void RecursionInsertionSort(vector<int> arr,int counter = 0){
      if(counter == arr.size()){
          display(arr);
          return;
      }
    
       int j = counter - 1;
       int temp = arr[counter];
       while(j >= 0 && temp < arr[j]){
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = temp;
       
       RecursionInsertionSort(arr,counter+1);
}
void merge(vector<int> &arr,int si,int mid,int li){
    vector<int> temp;
    int i = si;
    int j = mid + 1;
  
    while(i <= mid && j <= li){
        if(arr[i] < arr[j])
          temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i <= mid)
      temp.push_back(arr[i++]);
    while(j <= li)
      temp.push_back(arr[j++]);
    
    i = 0;
    for(int k=si;k<=li;k++)
      arr[k] = temp[i++];
}
void MergeSortHelper(vector<int> &arr,int si,int li){
    if(si < li){
        int mid = (si + li) / 2;
        MergeSortHelper(arr,si,mid);
        MergeSortHelper(arr,mid+1,li);
        merge(arr,si,mid,li);
    }
}
void MergeSort(vector<int> arr){
    MergeSortHelper(arr,0,arr.size()-1);
    display(arr);
}
void IterativeMergeSort(vector<int> arr){
    int n = arr.size();
    for(int cur_size=1;cur_size<n;cur_size*=2){
        for(int si=0;si<n-1;){
            int mid = min(si + cur_size - 1 , n-1);
            int li = min(si + 2*cur_size - 1 , n-1);
            merge(arr,si,mid,li);
            si = li + 1;;
        }
    }
    
    display(arr);
}
int partition(vector<int> &arr,int si,int li){
    int i = si;
    int j = i - 1;
    int pivotElement = arr[li];
    while(i < li){
        if(arr[i] < pivotElement)
          swap(arr[i],arr[++j]);
        i++;
    }
    swap(arr[j+1],arr[li]);
    return j + 1;
}
void QuickSortHelper(vector<int>& arr,int si,int li){
    if(si <= li){
        int index = partition(arr,si,li);
        QuickSortHelper(arr,si,index-1);
        QuickSortHelper(arr,index+1,li);
    }
}
void QuickSort(vector<int> arr){
    QuickSortHelper(arr,0,arr.size()-1);
    display(arr);
}
void IterativeQuickSort(vector<int> arr){
    stack<pair<int,int>> s;
    s.push({0,arr.size()-1});
    int si = 0;
    int li = arr.size() - 1;
    while(!s.empty()){
        
        si = s.top().first;
        li = s.top().second;
        s.pop();
        
        if(si > li) 
          continue;
        
        int index = partition(arr,si,li);
        s.push({si,index-1});
        s.push({index+1,li});
    }
    display(arr);
}
void upHeapify(vector<int> &arr,int childIndex){
      while(childIndex > 0){
          int parentIndex = (childIndex - 1)/2;
          if(arr[parentIndex] < arr[childIndex])
            swap(arr[parentIndex],arr[childIndex]);
          childIndex = parentIndex;
      }
}
void downHeapify(vector<int> &arr,int n){
     int parentIndex = 0;
     while(true){
         int minIndex = parentIndex;
         int leftChild = 2 * parentIndex + 1;
         int rightChild = 2 * parentIndex + 2;
         if(leftChild < n && arr[minIndex] < arr[leftChild])
            minIndex = leftChild;
         if(rightChild < n && arr[minIndex] < arr[rightChild])
            minIndex = rightChild;
         if(minIndex != parentIndex){
             swap(arr[minIndex],arr[parentIndex]);
             parentIndex = minIndex;
         }
         else break;
     }
}
void HeapSort(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++)
     upHeapify(arr,i);
    
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        downHeapify(arr,i);
    }
    
    display(arr);
}
void countingSort(vector<int>& arr,int k){
    int n = arr.size();
    vector<int> count(10,0);
    int digit;
    int p = pow(10,k);
    for(int i=0;i<n;i++){
      digit = (arr[i] / p) % 10;
      count[digit]++;
    }
    for(int i=1;i<10;i++)
      count[i] += count[i-1]; 
    vector<int> temp(n,0);
    for(int i=n-1;i>=0;i--){
      digit = (arr[i] / p) % 10;
      temp[count[digit]-1] = arr[i];
      count[digit]--;
    }
    
    for(int i=0;i<n;i++)
      arr[i] = temp[i];
}
void RadixSort(vector<int> arr){
    int maxi = *max_element(arr.begin(),arr.end());
    for(int i=0;i<log(maxi);i++) 
        countingSort(arr,i);
    display(arr);
}

int main()
{   
    vector<int> arr{ 5,4,7,22,1,99,9,2,1,11,7};

    selectionSort(arr);
    bubbleSort(arr);
    RecursionBubbleSort(arr);
    InsertionSort(arr);
    RecursionInsertionSort(arr);
    MergeSort(arr);
    IterativeMergeSort(arr);
    QuickSort(arr);
    IterativeQuickSort(arr);
    HeapSort(arr);
    RadixSort(arr);
}

