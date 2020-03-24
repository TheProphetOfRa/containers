#pragma once

#include <cassert>

namespace containers
{
    template<typename T>
    class Vector
    {
    public:
        using iterator = T*;

        Vector();
        Vector(unsigned int i_size);
        Vector(unsigned int i_size, const T& i_initial);
        Vector(const Vector<T>& i_vec);
        ~Vector();

        unsigned int capacity() const { return m_capacity; }
        unsigned int size() const { return m_size; }
        bool empty() const { return m_size == 0; }
        iterator begin() { return m_data; }
        iterator end() { return m_data + size(); }
        T& front() const { return m_data[0]; }
        T& back() const { return m_data[m_size - 1]; }
        void push_back(const T& i_value);
        void pop_back();

        void reserve(unsigned int i_capacity);
        void resize(unsigned int i_size, const T& i_value = T());

        T& operator[](unsigned int i_index);
        Vector<T>& operator=(const Vector<T>&);
        void clear();

    private:
        static const unsigned int kDefaultCapacity = 128;
        
        size_t m_objSize;
        unsigned int m_size;
        unsigned int m_capacity;

        T* m_data;
    };
    
    template<typename T>
    Vector<T>::Vector()
    : Vector<T>(Vector::kDefaultCapacity)
    {
    }

    template<typename T>
    Vector<T>::Vector(unsigned int i_capacity)
    : m_size(0)
    , m_data(nullptr)
    {
        assert(i_capacity != 0);

        m_objSize = sizeof(T);
        reserve(i_capacity);
    }
    
    template<typename T>
    Vector<T>::Vector(unsigned int i_capacity, const T& i_inital)
    : Vector<T>(i_capacity)
    {
        for (unsigned int i = 0 ; i < i_capacity ; ++i)
        {
            m_data[i] = i_inital;
        }
    }
    
    template<typename T>
    Vector<T>::Vector(const Vector<T>& i_vec)
    {
        m_data = nullptr;
        m_size = i_vec.size();
        m_capacity = i_vec.capacity();
        
        reserve(m_capacity);
        memcpy(m_data, i_vec.begin(), i_vec.size());
    }
    
    template <typename T>
    Vector<T>::~Vector()
    {
        free(m_data);
        m_data = nullptr;
    }

    template <typename T>
    void Vector<T>::push_back(const T& i_value)
    {
        if (m_size >= m_capacity)
        {
            reserve(m_capacity * 2);
        }
        
        m_data[m_size++] = i_value;
    }
    
    template<typename T>
    void Vector<T>::pop_back()
    {
        m_data[m_size--]->~T();
    }

    template<typename T>
    void Vector<T>::reserve(unsigned int i_capacity)
    {
        if (m_data == nullptr)
        {
            m_data = (T*)malloc(i_capacity * m_objSize);
        }
        else
        {
            m_data = (T*)realloc(m_data, i_capacity * m_objSize);
        }
        
        m_capacity = i_capacity;
    }
    
    template<typename T>
    void Vector<T>::resize(unsigned int i_size, const T& i_value/* = T()*/)
    {
        if (i_size < m_size)
        {
            for (unsigned int i = i_size ; i_size < m_size ; ++i)
            {
                m_data[i]->~T();
            }
        }
        else
        {
            while (m_capacity < i_size)
            {
                reserve(m_capacity * 2);
            }
            
            for (unsigned int i = m_size ; i < i_size ; ++i)
            {
                m_data[i] = i_value;
            }
        }
        
        m_size = i_size;
    }
    
    template<typename T>
    T& Vector<T>::operator[](unsigned int i_index)
    {
        return m_data[i_index];
    }
    
    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& i_vec)
    {
        free(m_data);
        m_data = nullptr;
        
        m_size(i_vec.size());
        m_capacity(i_vec.capacity());
        
        reserve(m_capacity);
        memcpy(m_data, i_vec.begin(), i_vec.size());
        
        return *this;
    }
    
    template<typename T>
    void Vector<T>::clear()
    {
        free(m_data);
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
}
