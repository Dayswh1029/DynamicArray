#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include"MemoryPool.h"
#include"MemoryPool.cpp"

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

    try{
    MemoryPool pool(sizeof(DynamicArray),4);

    void* mem1=pool.allocate();
    void* mem2=pool.allocate();
    void* mem3=pool.allocate();

    DynamicArray* arr1= new(mem3) DynamicArray;
    arr1->add(1);
    arr1->add(100);
    arr1->add(200);

    // 显示析构 先析构，再回收！
    arr1->~DynamicArray();


    // 收回
    pool.deallocate(mem1);

}catch(const std::bad_alloc&e){
    std::cerr<<"Memory allocation error: "<<e.what()<<std::endl;
    return 1;

}



    return 0;
}