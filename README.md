# DynamicArray

手动写一个动态数组类，完成一些简单的功能；
目标：创建一个动态数组类，支持添加元素，访问元素 和自动扩展

总容量capacity  和元素个数 size

当capacity  ==size 需要 我们扩容！

可以添加元素！ 

_data[size++]=value; // 添加元素！ 
先要_data[size]=value; 然后 size+1
这个 执行的顺序！