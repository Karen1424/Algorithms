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

// the complexity of the algorithm O(N*N)
void insertionSort(std::vector<int> & vec)
{
    for(int j = 1; j < vec.size(); ++j)
    {
        int i = j - 1;
        int key = vec[j];

        while(i >= 0 && vec[i] > key)
        {
            vec[i + 1] = vec[i];
            --i;
        }

        vec[i + 1] = key;
    }
}

int main() {

    std::vector<int> vec {1,9,0,12,-15,-1,-3,152,15,14};
    Utility::printArrayElems(vec);
    insertionSort(vec);
    Utility::printArrayElems(vec);

    return 0;
}