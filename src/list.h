//
// Created by tomek on 05.06.2021.
//

#ifndef LISTA_D_LIST_H
#define LISTA_D_LIST_H

#include <exception>
#include <string>

template<class T>
class element {
    public:
        element(const T & o, element<T> * nextobj, element<T> * previousobj, int i);
        element<T> & operator=(element<T> other);

        int number;
        const T obj;
        element<T> *ptrNextObj;
        element<T> *ptrPreviousObj;

        ~element(){}
} ;
template<class T>
element<T>::element(const T & o, element<T> * nextobj, element<T> * previousobj, int i): obj(o), number(i)
{
    ptrNextObj = nextobj;
    ptrPreviousObj = previousobj;
}

template<class T>
element<T> & element<T>::operator=(element<T> other)
{
    this->ptrPreviousObj = other.ptrPreviousObj;
    this->ptrNextObj = other.ptrNextObj;
    this->obj = other.obj;
    this->number = other.number;
}

template<class T>
class list {

    private:

    element<T> *  last_obj_ptr;
    element<T> * first_obj_ptr;
    element<T> * iterator;
    unsigned size_stack;

    void changing_number();
    element<T> * find_element(int ID);


    public:

        list() { size_stack = 0; }
        list(const T & item);
        ~list();



        bool empty();
        void clear();
        void push_back(const T & item);
        void push_front(const T & item);
        void insert(const T & el, int ID);
        void erase(int ID);
        void reverse();

        T pop_back();
        T operator[](int i);

        int get_size();
        std::string get_list();

};

template<class T>
void list<T>::changing_number()
{
    iterator = first_obj_ptr ;

    for (int i = 0; iterator; ++i) {
        iterator->number = i;
        iterator = iterator->ptrPreviousObj;
    }
}

template<class T>
element<T> * list<T>::find_element(int ID)
{
    iterator = first_obj_ptr;
    int i =0;
    for(i =0; i < size_stack; i++)
    {
        if(ID == i) {
            return iterator;
        }
        else
        {
            iterator = iterator->ptrPreviousObj;
        }
    }
    if(i == size_stack)
    {
        //throw std::exception();
    }

}

template<class T>
list<T>::list(const T & item) {
    element<T> * tmp;

    tmp = new element<T>(item, nullptr, nullptr, 0);

    first_obj_ptr = tmp;
    last_obj_ptr = tmp;

    size_stack++;
}

template<class T>
list<T>::~list()
{
    this -> clear();
}

template<class T>
bool list<T>::empty()
{

    if(size_stack == 0)
    {
        return true;
    } else{
        return false;
    }
}

template<class T>
void list<T>::clear()
{
    iterator = last_obj_ptr;
    while (iterator != nullptr){
        element<T> * tmp_ptr = iterator->ptrNextObj;
        delete iterator;
        iterator = tmp_ptr;
    }
    size_stack =0;
    last_obj_ptr = nullptr;
    first_obj_ptr = nullptr;
}

template<class T>
void list<T>::push_back(const T & item)
{
    element<T> * tmp;
    tmp = (size_stack == 0) ?  new element<T>(item, nullptr, nullptr, size_stack) : new element<T>(item, last_obj_ptr, nullptr, size_stack);
    if(size_stack==0)
    {
        first_obj_ptr = tmp;
        last_obj_ptr = tmp;
    } else
    {
        last_obj_ptr->ptrPreviousObj = tmp;
        last_obj_ptr = tmp;
    }
    size_stack++;
}

template<class T>
void list<T>::push_front(const T & item)
{
    element<T> * tmp;
    size_stack == 0 ? tmp = new element<T>(item, nullptr, nullptr, size_stack) : tmp = new element<T>(item, nullptr, first_obj_ptr, 0);

    if (size_stack == 0)
    {
        first_obj_ptr = tmp;
        last_obj_ptr = tmp;
    } else
    {

        first_obj_ptr->ptrNextObj = tmp;
        first_obj_ptr = tmp;

    }
    size_stack++;
    changing_number();
}

template<class T>
void list<T>::insert(const T & el, int ID)
{
    if(ID == 0)
        this->push_front(el);
    else if(ID == (size_stack-1))
        this->push_back(el);
    else{
    element<T>* tmp = find_element(ID);
    element<T>* tmp_new = new element<T>(el,tmp,tmp->ptrPreviousObj,0);
    tmp->ptrPreviousObj->ptrNextObj = tmp;
    tmp->ptrPreviousObj = tmp_new;
    changing_number();
    }
}

template<class T>
void list<T>::erase(int ID)
{
    element<T> * tmp = find_element(ID);
    iterator = tmp->ptrNextObj;
    iterator->ptrPreviousObj = tmp->ptrPreviousObj;
    tmp->ptrPreviousObj->ptrNextObj = iterator;
    delete tmp;
    changing_number();

}

template<class T>
T list<T>::pop_back()
{
    if(size_stack!=0) {
        T tmp_obj = last_obj_ptr->obj;
        element<T>* tmp_ptr = last_obj_ptr->ptrNextObj;

        delete last_obj_ptr;

        if(tmp_ptr!= nullptr)
            tmp_ptr->ptrPreviousObj= nullptr;

        last_obj_ptr = tmp_ptr;
        size_stack--;
        changing_number();
        return tmp_obj;
    }
    else
    {
        //throw std::runtime_error("Stack is empty!");
    }
}

template<class T>
T list<T>::operator[](int i)
{
    element<T> * tmp = find_element(i) ;
    return tmp->obj;
}

template<class T>
int list<T>::get_size()
{
    return size_stack;
}

template<class T>
void list<T>::reverse()
{
    iterator = last_obj_ptr;
    element<T>* tmp;
    for (int i = 0; i < size_stack; ++i) {
        tmp = iterator->ptrNextObj;
        iterator->ptrNextObj = iterator->ptrPreviousObj;
        iterator->ptrPreviousObj =tmp;
        iterator = tmp;
    }
    tmp = last_obj_ptr;
    last_obj_ptr = first_obj_ptr;
    first_obj_ptr = tmp;

}

template<class T>
std::string list<T>::get_list()
{
    std::string str{""};
    iterator = first_obj_ptr;
    for(int i = 0; i < size_stack ; i++ )
    {
        str += std::to_string(iterator->obj);
        str += " ";
        iterator = iterator->ptrPreviousObj;
    }

    return str;
}

#endif //LISTA_D_LIST_H
