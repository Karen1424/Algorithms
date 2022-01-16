#include <iostream>
#include <vector>

namespace Utility
{
    template <typename T>
    void swap(T& v1, T& v2)
    {
        T temp = v1;
        v1 = v2;
        v2 = temp;
    }
    
    template <typename T>
    void printArrayElements(std::vector<T> & vec)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout <<std::endl;
    }
}

void heapify(std::vector<int> & vec, int size, int index)
{
    int largest = index; // root
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // if left child is larger than root
    if(left < size && vec[left] > vec[largest]) largest = left;
    
    // if right child is larger than root
    if(right < size && vec[right] > vec[largest]) largest = right;

    if(largest != index)
    {
        Utility::swap(vec[index],vec[largest]);
        heapify(vec,size,largest);
    }
}

// the complexity of the algorithm O(N*logN)
void heapSort(std::vector<int> & vec, int size)
{
    // build heap
    for(int i = vec.size() / 2; i >= 0; --i)
        heapify(vec,size,i);
    
    // one by one extract en element from heap
    for(int i  = vec.size() - 1; i >= 0; --i)
    {
        // move current root to end
        Utility::swap(vec[0],vec[i]);
        // call max heapify on the reduced heap
        heapify(vec,i,0);
    }
}
int main() {

    std::vector<int> vec {2,9,-12,1,15,4,8,9,3,6};
    Utility::printArrayElements(vec);
    heapSort(vec,vec.size());
    Utility::printArrayElements(vec);
    
    return 0;
}