/******************************************************************************

                            Bubble Sort:- 
            Using bubble sort to count the number of swaps required to 
            sort the array
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void modifiedBubbbleSort(vector<int> %arr) {
	int len = arr.size()-1;
	for(int i=0; i<len-1; i++) {
		bool swapped = false;
		for(int j=0; j<len-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

int bubbleSort(vector<int> &arr) {
	int len = arr.size();
	int count = 0;
	for(int i=0; i<len-1; i++) {
		for(int j=0; j<len-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				count++;
			}
		}
	}
	return count;
}
 
int main() {
	// number of elements in the array
	int n;
	cin >> n;
	// array of elements
	vector<int> arr(n);

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	modifiedBubbbleSort(arr);
	for(auto i: arr) {
		cout << i << " ";
	}

/*	============ code to count the number of swaps while sorting them ===========
	int result = bubbleSort(arr);

	cout << result;
*/
}