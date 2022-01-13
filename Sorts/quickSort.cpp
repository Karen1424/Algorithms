#include <iostream>
#include <vector>

namespace Utility
{
    template <typename T>
    void swap(T& value1, T& value2)
    {
        T temp = value1;
        value1 = value2;
        value2 = temp;
    }

    template <typename T>
    void printArrayElems(T* array, int size)
    {
        for(int i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
    
        std::cout << std::endl;
    }

}

// the complexity of the algorithm in the worst case O(N*N), on average O(N * logN)
void quickSort(int * array, int first, int last)
{
    if(first < last)
    {
        int left = first;
        int right = last;
        int mid = array[(left + right) / 2];

        do
        {
            //Find a larger element on the left, relative to the mid element
            while(array[left] < mid)
                ++left;

            //Find a smaller  element on the right,relative to the mid element           
            while(array[right] > mid)
                --right;

            if(left <= right)
            {
                Utility::swap(array[left],array[right]);
                ++left;
                --right;
            }
        } while (left < right);

        quickSort(array,first,right);
        quickSort(array,left,last);
                
    }

}

int main() {

    const int size = 10;
    int array[size] {2,-5,6,9,11,0,1,5,7,18};
    int first = 0; // array first element index
    int last = size - 1; // array last element index

    Utility::printArrayElems(array,size);
    quickSort(array,first,last);
    Utility::printArrayElems(array,size);

    return 0; 
}