#pragma once
#include <iostream>
#define defaultCapacity 10
using namespace std;
template <typename Data>
class DoubleSideQueue
{
private:
    Data *data;
    int capacity;
    int count;
public:
    DoubleSideQueue()
    {
        capacity = defaultCapacity;
        data = new Data[capacity];
        count = 0;
    }
    DoubleSideQueue(int const capacity_in)
    {
        capacity = capacity_in;
        data = new Data[capacity];
        count = 0;
    }
    DoubleSideQueue(DoubleSideQueue const &any_queue)
    {
        capacity = any_queue.capacity;
        data = new Data[capacity];
        for(count = 0; count <any_queue.count; ++count)
            data[count] = any_queue.data[count];
    }
    void pushBack(Data const new_Data)
    {
        if(count == capacity)
        {
            capacity += 10;
            Data *tmpdata = new Data[capacity];
            for( int i = 0; i < count; ++i)
                tmpdata[i] = data[i];
            delete[]data;
            data = tmpdata;
        }
        data[count++] = new_Data;
    }
    void pushFront(Data const new_Data)
    {
        if(count == capacity)
        {
            capacity += 10;
            Data *tmpdata = new Data[capacity];
            for( int i = 0; i < count; ++i)
                tmpdata[i] = data[i];
            delete[]data;
            data = tmpdata;
        }
        for(int i = count++; i>0; --i)
            data[i] = data[i-1];
        data[0] = new_Data;
    }
    Data const popBack()
    {
        if(isEmpty())
            return 0;
        Data tmpdata = data[--count];
        data[count] = 0;
        return tmpdata;
    }
    Data const popFront()
    {
        if(isEmpty())
            return 0;
        Data tmpdata = data[0];
        --count;
        for(int i = 0; i < count;++i)
            data[i] = data[i+1];
        data[count] = 0;
        return tmpdata;
    }
    Data const topBack() const
    {
        if(isEmpty())
            return 0;
        return data[count-1];
    }
    Data const topFront() const
    {
        if(isEmpty())
            return 0;
        return data[0];
    }
    void clear()
    {
        delete[]data;
        capacity = defaultCapacity;
        count = 0;
        data = new Data[capacity];
    }
    bool const isEmpty() const
    {
        if(count == 0)
            return true;
        return false;
    }
    int const size() const
    {
        return count;
    }
    void print() const
    {
        if(isEmpty())
        {
            cout<<"\nQueue is empty"<<endl;
        }else{
            for(int i = 0; i<count;)
                cout<<"\t"<<data[i++];
        }
    }
    DoubleSideQueue& operator = (DoubleSideQueue const &any_queue)
    {
        delete[] data;
        capacity = any_queue.capacity;
        data = new Data[capacity];
        for(count = 0; count <any_queue.count; ++count)
            data[count] = any_queue.data[count];
        return *this;
    }
    ~DoubleSideQueue()
    {
        delete[] data;
        count = 0;
        capacity = 0;
    }
};
