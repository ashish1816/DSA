/******************************************************************************

            Implementation of quickSort algorithm

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &v, int low, int high) {
    int pivot, i, j;
    pivot = v[high];
    i = low-1;
    
    for(j=low; j<=high-1; j++) {
        if(v[j]<pivot) {
            i++;
            swap(&v[j], &v[i]);
        }
    }
    swap(&v[i+1], &v[high]);
    return (i+1);
}

void quickSort(vector<int> &v, int low, int high) {
    if(low<high) {
        int pivotIndex = partition(v, low, high);
        quickSort(v, low, pivotIndex-1);
        quickSort(v, pivotIndex+1, high);
    }
}

int main()
{
    vector<int> v = {10, 7, 8, 9, 1, 5};
    int high = v.size()-1;
    
    quickSort(v, 0, high);
    
    for(auto i : v) {
        cout << i << " ";
    }
    return 0;
}