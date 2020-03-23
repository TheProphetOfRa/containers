#include "vector.hpp"

#include <iostream>

int main()
{
    containers::Vector<int>* v = new containers::Vector<int>();
    for (int i = 0 ; i < 5000 ; ++i)
    {
        v->push_back(i);
    }

    for (int i = 0 ; i < v->size() ; ++i)
    {
        std::cout << (*v)[i] << std::endl;
    }
    
    delete v;

    return 0;
}
