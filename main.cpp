#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include<iostream>

int main()
{
    try {
    
        DynamicArray arr;
        arr.add(10);
        arr.add(100);
        arr.add(200);
        std::cout<<"DynamicArray: "<<std::endl;
        for(size_t i=0;i<arr.getSize();i++)
        {
            std::cout<<"arr["<<i<<"] = "<<arr.get(i)<<std::endl;
        }
        std::cout<<arr[1]<<std::endl;

    } catch(const std::bad_alloc&e)
    {
        std::cerr<<"Memory access error: "<<e.what()<<std::endl;
        return 1;
    } catch(const std::out_of_range&e){
        std::cerr<<"Array access error: "<<e.what()<<std::endl;
        return 1;
    } catch(const std::exception&e){
        std::cerr<<"Error: "<<e.what()<<std::endl;
        return 1;

    }


    return 0;
}