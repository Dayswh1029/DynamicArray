#include "MemoryPool.h"
#include <cstdlib>
#include <new>

MemoryPool::MemoryPool(size_t objSize,size_t totalSize):objSize(objSize),totalSize(totalSize)
{
    pool =(char*)malloc(objSize*totalSize);

    // 初始化 freeList
    for(size_t i=0; i<totalSize;i++)
    {
        freeList.push(pool+i*objSize); // 
    }
}
// malloc  new 
void* MemoryPool::allocate()
{
    if(freeList.empty()) throw std::bad_alloc(); // 直接抛出 异常！

    void* p= freeList.top();
    freeList.pop();
    return p;

}

void MemoryPool::deallocate(void* ptr)
{

    freeList.push(ptr);
}



MemoryPool::~MemoryPool()
{

    // 释放内存 ！ 用 函数处理

    free(pool);
    std::cout<<"MemoryPool deconstructor! "<<std::endl;
    

}


