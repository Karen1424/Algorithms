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
void selectionSort(std::vector<int> & vec)
{
    for(int i = 0; i < vec.size() - 1; ++i)
    {
        int min = i;
        
        for(int j = i + 1; j < vec.size(); ++j)
        {
            if(vec[min] > vec[j])
            {
                min = j;
            }
        }

        Utility::swap(vec[min],vec[i]);
    }
}

int main() {

    std::vector<int> vec {2,-7,8,1,3,6,15,4,12,7};
    Utility::printArrayElems(vec);
    selectionSort(vec);
    Utility::printArrayElems(vec);

    return 0;
}