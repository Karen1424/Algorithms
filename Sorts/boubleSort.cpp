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
void boubleSort(std::vector<int> & vec)
{
    bool flag = true;

    for(int i = 0; i < vec.size(); ++i)
    {
        flag = true;

        for(int j = vec.size() - 1; j > i; --j)
        {
            if(vec[j] < vec[j - 1])
            {
                Utility::swap(vec[j],vec[j - 1]);
                flag = false; 
            }
        }

        if(flag) break; //if the array is sorted, the algorithm will work O(N)
    }
}

int main() {

    std::vector<int> vec {2,-7,10,0,9,6,5,12,1,-9};
    Utility::printArrayElems(vec);
    boubleSort(vec);
    Utility::printArrayElems(vec);

    return 0;
}