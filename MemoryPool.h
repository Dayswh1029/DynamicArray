#pragma once
#include <cstddef>
#include<iostream>
#include<stack>

class MemoryPool{
    public:
        MemoryPool(size_t objSize,size_t totalSize);
        void* allocate();
        void deallocate(void* ptr);
        ~MemoryPool();



    private:
        size_t objSize; // 对象的大小！ 
        size_t totalSize; // 对象的个数
        char* pool; // 开辟空间的首地址！

        std::stack<void*> freeList; // 管理这个空间使用 栈的方法！




}; 