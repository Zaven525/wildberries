#include "wildberries.hpp"

void foo(const int* ptr)
{
    std::cout << "yes u can pass uptr to function which claims raw ptr";
}

int main()
{
    std::unique_ptr<int> iptr(std::make_unique<int>(5));
    foo(iptr.get()); 
}