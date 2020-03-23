#include "vector.hpp"

#include <iostream>

void run()
{
    containers::Vector<int>* v = new containers::Vector<int>();
    for (int i = 0; i < 5000; ++i)
    {
        v->push_back(i);
    }

    for (int i = 0; i < v->size(); ++i)
    {
        std::cout << (*v)[i] << std::endl;
    }

    delete v;
}

#if defined(WIN32)

#include "Windows.h"

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    run();

    return 0;
}

#else

int main()
{
    run();

    return 0;
}

#endif


