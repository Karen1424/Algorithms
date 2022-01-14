#include <iostream>
#include <vector>

//binary search works only for sorted arrays
// the complexity of the algorithm O(logN)
//binary serach recursive implementation

int binarySearch(int * array, int start, int end, int key)
{
    // stop condition
    if(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(array[mid] == key) return mid;

        if(array[mid] > key) return binarySearch(array,start,mid - 1, key);

        return binarySearch(array,mid + 1,end,key); // if key smaller  array[mid]
    }
    return -1; // if there is no such key in the array
}

// binary serach iterative implementation

int binarySearch(std::vector<int> & vec, int key)
{
    int start = 0;
    int end = vec.size() - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(vec[mid] == key)
        {
            return mid;
        }
        else if(vec[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1; // if there is no such key in the array
}

// binary search: find the sorted array values` (0 or 1), index of the last 0

int indexOfLastZeroBinnarySearch(int * array, int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end)
    {
        int mid = start + (end - start) / 2;

        if(array[mid] == 0 && array[mid + 1] == 1) return mid;

        if(array[mid] == 1 && array[mid + 1] == 1) end = mid;

        if(array[mid] == 0) start = mid + 1;
    }
    return -1; // if there is no 0 in the array
}
int main() {

    const int size = 10;
    int array[size] {2,4,6,8,10,12,14,16,18,20};
    int start = 0; // array first element index
    int end = size - 1; //array last element index

    int key = 0;
    std::cout << "enter the search key" << std::endl;
    //std::cin >> key;

    //std::cout << binarySearch(array,start,end,key); //  the key index
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    //std::cout << binarySearch(vec,key); //  the key index

    int binaryArray[size] {0,0,0,0,1,1,1,1,1,1};
    std::cout << indexOfLastZeroBinnarySearch(binaryArray,size); // index of the last 0

    return 0;
}
