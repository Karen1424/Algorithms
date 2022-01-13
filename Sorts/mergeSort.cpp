#include <iostream>
#include <vector>

namespace Utility
{
    
    template <typename T>
    void printArrayElems(std::vector<T> vec)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
    
        std::cout << std::endl;
    }

}

// Merges two sub. vectors of vector.
// left subvec is vec[first..mid]
// right subvec is vec[mid+1..last]
void merge(std::vector<int> & vec, int first, int mid, int last)
{
    int leftVecSize = (mid - first) + 1;
    int rightVecSize = last - mid;

    // Create temp vectors
    std::vector<int> leftVec;
    leftVec.reserve(leftVecSize);
    std::vector<int> rightVec;
    rightVec.reserve(rightVecSize);

     // Copy data to temp vectors leftVec and rightVec
    for(int i = 0; i < leftVecSize; ++i)
        leftVec[i] = vec[first + i];
    
    for(int i = 0; i < rightVecSize; ++i)
        rightVec[i] = vec[mid + 1 + i];

    //Initial index of left,right and merged vectors
    int indexOfLeftVec = 0;
    int indexOfRightVec = 0;
    int indexOfMergedVec = first;

    // Merge the temp vectors back into vec[first..last]
    while(indexOfLeftVec < leftVecSize && indexOfRightVec < rightVecSize)
    {
        if(leftVec[indexOfLeftVec] <= rightVec[indexOfRightVec])
        {
            vec[indexOfMergedVec] = leftVec[indexOfLeftVec];
            ++indexOfLeftVec;
        }
        else
        {
            vec[indexOfMergedVec] = rightVec[indexOfRightVec];
            ++indexOfRightVec;
        }

        ++indexOfMergedVec;
    }

    // Copy the remaining elements of
    // leftVec[], if there are any
    while(indexOfLeftVec < leftVecSize)
    {
        vec[indexOfMergedVec] = leftVec[indexOfLeftVec];
        ++indexOfLeftVec;
        ++indexOfMergedVec;
    }

    // Copy the remaining elements of
    // rightVec[], if there are any
    while(indexOfRightVec < rightVecSize)
    {
        vec[indexOfMergedVec] = rightVec[indexOfRightVec];
        ++indexOfRightVec;
        ++indexOfMergedVec;
    }
        
}

// the complexity of the algorithm in the worst case O(N * logN)
void mergeSort(std::vector<int> & vec, int first, int last)
{
    if(first >= last) return; // recursive

    int mid = first + (last - first) / 2;
    mergeSort(vec,first,mid);
    mergeSort(vec,mid + 1,last);
    merge(vec,first,mid,last);
}

int main() {

    std::vector<int> vec {2,8,-9,6,3,1,5,17,0,14};
    int first = 0;
    int last = vec.size() - 1;
    Utility::printArrayElems(vec);
    mergeSort(vec,first,last);
    Utility::printArrayElems(vec);
    
    return 0;
}