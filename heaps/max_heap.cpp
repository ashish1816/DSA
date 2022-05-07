/******************************************************************************
 * Contributed by:- Ashish Burnwal
    Implementing priority queues using binary heaps.

    1. Implementation of MaxHeap
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Heap
{
  private:
  vector<int> A;
  int parent(int i)
  {
      return (i-1)/2;
  }
  int left_child(int i)
  {
      return 2*i+1;
  }
  int right_child(int i)
  {
      return 2*i+2;
  }
  
  void heapify_up(int i)
  {
      if(i && A[i]>A[parent(i)])
      {
          swap(A[i], A[parent(i)]);
          heapify_up(parent(i));
      }
  }
  
  void heapify_down(int i)
  {
      int left = left_child(i);
      int right = right_child(i);
      
      int largest = i;
      
      if(left<size() && A[left]>A[largest])
      {
          largest = left;
      }
      if(right<size() && A[right]>A[largest])
      {
          largest = right;
      }
      
      if(largest!=i)
      {
          swap(A[largest], A[i]);
          heapify_down(largest);
      }
  }
  
  public:
  unsigned int size()
  {
      return A.size();
  }
  bool empty()
  {
      return A.size()==0;
  }
  
  int top()
  {
      if(size()==0)
      {
          cout << "The list is empty. \n";
          return -1;
      }
      return A.at(0);
  }
  
  void push(int i)
  {
      A.push_back(i);
      int index = size()-1;
      heapify_up(index);
  }
  
  void pop()
  {
      if(size()==0)
      {
          cout << "Cannot pop as the list is empty.\n";
          return;
      }
      A[0] = A.back();
      A.pop_back();
      heapify_down(0);
  }
  
};

int main() {
    cout << "Hello world!\n";
    
    Heap h;
    h.push(5);
    h.push(10);
    h.push(3);
    
    cout << h.top() << "\n";
    
    h.push(7);
    
    cout << h.top() << "\n";
    h.pop();
    cout << h.top() << "\n";
    h.pop();
    h.push(1);
    h.push(6);
    h.push(11);
    cout << h.top() << "\n";
    h.pop();
    cout << h.top() << "\n";

    return 0;
}