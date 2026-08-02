#include "DynamicArray.h"
#include<iostream>
DynamicArray::DynamicArray():_data((int*) malloc(2*sizeof(int))),capacity(2),size(0)
{
    if(_data==0)
    {
        std::cerr<<"malloc failed"<<std::endl;
        throw std::bad_alloc{};
        // 没有返回值！ 直接抛出 错误！
    }
}

void DynamicArray::add(int value)
{
    if(size>=capacity)
    {
        // 扩容！！！！！
        resize(capacity*2);
    }
    _data[size++]=value; // 添加元素！ 

}

int DynamicArray::get(size_t index) const
{
    if(index>=size){
        throw std::out_of_range{"index out of range "};
    }
    return _data[index];
}

size_t DynamicArray::getSize() const // 获取数组的大小
{

    return size;

}
size_t DynamicArray::getCapacity()const{

    return capacity;
}

DynamicArray::~DynamicArray()
{
    free(_data);
    //std::cout<<"deconstructor!!"<<std::endl;
}
