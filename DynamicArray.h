#pragma once
#include <cstddef>
#include<iostream>
class DynamicArray{


    public:
        DynamicArray();
        DynamicArray(int* p);
        void add(int value);

        int get(size_t index);
        size_t getSize()const;
        size_t getCapacity()const;
        ~DynamicArray();


    private:
        int* _data;
        size_t capacity; //容量
        size_t size;   // 已经被利用的元素！
    private:

        void resize(size_t new_capacity){
            int * temp=(int*)std::realloc(_data,new_capacity*sizeof(int));
            if(temp==nullptr)
            {
                throw std::bad_alloc{};
            }
            _data=temp;
            capacity=new_capacity;
        }


};