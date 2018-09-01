#include <iostream> 
#include<algorithm>
#include <vector> 

//Some playing around with heaps in C++. 

int main()
{
	std::vector<int> heap = { 3, 4, 9, 1, 4, 2, 8, 5, 6, 11, 3, 4 }; 

	make_heap(heap.begin(), heap.end());

	//Max shall now be at the front of the vector.  


	//Heapsort 
	int sortedArray[12] = {};

	for (int i = 0; i < 12; i++)
	{
		sortedArray[i] = heap.front(); 
		pop_heap(heap.begin(), heap.end());
		heap.pop_back();
	}

	for (int i = 0; i < 12; i++)
	{
		std::cout << sortedArray[i] << std::endl; 
	}

	return 0; 
}

//BELOW ONLY FOR ARRAY IMPLEMENTATION

//Node at index k in array has children at index 2k + 1 and 2k + 2. 
//Parent node of a node in array at index k is at index (k-1)/2. Chop off decimal. 

//BELOW ONLY FOR HEAP FROM VECTOR

//To create a max heap from a vector: 
//make_heap(vector.begin(), vector.end()); 

//If we want to insert: 
//vector.push_back(50);
// using push_heap(vector.begin(), vector.end());

//If we want to get max: 
//vector.front(); 
//pop_heap(vector.begin(), vector.end());
//vector.pop_back();