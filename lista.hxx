#ifndef _LIST_H
#define _LIST_H

#include <iostream>
using namespace std;
#include "node1.hxx"


template <typename Type>
class list
{
    public:
        //class iterator
        class iterator;
        class const_iterator;

        //print
        void print() const;
        
        // Capacity
        size_t size() const;  // Vraca broj elemenata ,O(1)
        bool empty() const; // Provjerava da li je lista prazna, O(1)
        
        // Modifiers
        void clear(); // Uklanja sve elemente liste,O(n)
        // Dodaje elemente na kraj liste,O(1) 
        void push_back(const Type& val); //Vrijednost je kopirana
        void push_back(Type&& val);       //Vrijednost je pomjerena u novi element(moved)
        void push_front(const Type& elem); // Ubacuje elemenat na pocetak liste,O(1),vrijednost je kopirana u novi elemenat
        void push_front(Type&& val);         // Ubacuje elemenat na pocetak liste,0(1), move semantika
        void pop_back(); // Uklanja zadnji elemenat liste, 0(n),smanjuje velicinu za 1
        void pop_front(); // Uklanja prvi elemenat liste,O(1),smanjuje velicinu za 1
        //Ubacuju elemenat iza odjedjene pozicije , koja je proslijedjena u metod,O(1)
	void pop(Type& val);
      void insert (const_iterator position, const Type& val);
       void insert (const_iterator position, Type&& val);
        
        // Pristup elementima
        Type& front();   // Vraca referencu na prvi elemenat liste,O(1)
        const Type& front() const; // Vraca konstantnu referencu na prvi elemenat liste,0(1)
        Type& back(); // Vraca referencu na zadnji elemenat liste,O(1)
        const Type& back() const; // Vraca konstantnu referencu na zadnji elemenat liste,O(1)      
        
        // Iteratori
        iterator begin(){return iterator(first);} // Vraca iterator na prvi elemenat liste,O(1)
        const_iterator begin() const{return const_iterator(first);} // Vraca konstantan iterator na prvi elemenat liste,O(1)       
        iterator end(){return iterator(last->getNext());}// Vraca iterator na poziciju nakon zadnjeg,O(1)
        const_iterator end() const{return const_iterator(last->getNext());} // Vraca konstantan iterator na poziciju nakon zadnjeg elementa,O(1)
       
        //Konstruktori
        list(); // Default konstruktor
        list (const list& x); // Kopi konstruktor
        list (list&& x); // Move konstuktor   
        ~list(); // Destruktor
        list& operator= (const list<Type>& x); // Kopi operator=
        list& operator= (list&& x); // Move operator=
        bool operator!=(list<Type>& b);
    private:
		size_t count; // Broje elemenata liste
		nodeType<Type> *first; // Pokazivac na prvi elemenat liste
		nodeType<Type> *last; // Pokazivac na zadnji elemenat liste
    void copyList(const list<Type>& otherList);

};

template<typename Type>
bool list<Type>::operator!=(list<Type>& b){
  auto it=(*this).begin();
  //auto iter=(*this).end();
  auto otherF=b.begin();
  if((*this).size()!=b.size()){
    std::cout<<"Liste nisu iste velicine!"<<endl;
    return true;
  }
  else{
    while(it!=(*this).end()){
     if((*it).getInfo()!=(*otherF).getInfo())
     {
       return true;
     }
     else{
       ++it;
       ++otherF;
     }



  }
}
return false;
}

template <typename Type>
void list<Type>::print() const
{
nodeType<Type> *current;
current = first;

while (current != nullptr)
{
cout << (*current).getInfo() << endl;
current = (*current).getNext();
}
}

template<typename Type>
size_t list<Type>::size() const{
  return count;
}

template<typename Type>
bool list<Type>::empty() const{
  return (first==nullptr);
}

 template <typename Type>
 void list<Type>::clear()
{
    nodeType<Type> *temp;
    while (first != nullptr)
      {
      temp = first;
      first = (*first).getNext(); 
      delete temp;
      }
      last = nullptr; 
      count = 0;

}

 template <typename Type>
 void list<Type>::push_back(const Type& val)
  
{
   nodeType<Type> *newNode;  
   newNode = new nodeType<Type>; 
   (*newNode).setInfo(val);  
   (*newNode).setNext(nullptr);
   if (this->first == nullptr) 
   {
    this->first = newNode;
    this->last = newNode;
    this->count++; 
   }
   else
   {
   this->last->setNext(newNode); 
   this->last = newNode; 
   this->count++;
   }
 }


template <typename Type>
 void list<Type>::push_back(Type&& val)
  
{
   nodeType<Type> *newNode;  
   newNode = new nodeType<Type>; 
   (*newNode).setInfo(val);  
   (*newNode).setNext(nullptr);
   if (this->first == nullptr) 
   {
    this->first = newNode;
    this->last = newNode;
    this->count++; 
   }
   else
   {
   this->last->setNext(newNode); 
   this->last = newNode; 
   this->count++;
   }
 }

 template <typename Type>
 void list<Type>::push_front(const Type& elem)
{
  nodeType<Type> *newNode; 
  newNode = new nodeType<Type>; 
  (*newNode).setInfo(elem);
  (*newNode).setNext(this->first);
  this->first = newNode;  
  this->count++;
  if (this->last == nullptr) 
 this->last = newNode;

}


template <typename Type>
 void list<Type>::push_front(Type&& elem)
{
  nodeType<Type> *newNode; 
  newNode = new nodeType<Type>; 
  (*newNode).setInfo(elem);
  (*newNode).setNext(this->first);
  this->first = newNode;  
  this->count++;
  if (this->last == nullptr) 
 this->last = newNode;

}

template<typename Type>
void list<Type>::pop_back(){
  nodeType<Type> *temp;
  temp=first;
  if(empty())
  cout<<"Nema elemenata u listi"<<std::endl;
  else{
  if(first->getNext()==nullptr)
  {
  delete first;
  first=nullptr;
  last=nullptr;
  count=0;
  }
  else{
  while(temp->getNext()!=last)
  temp=temp->getNext();
  delete temp->getNext();
  temp->setNext(nullptr);
  count--;
 }
}
}

template<typename Type>
void list<Type>::pop_front(){
  nodeType<Type> *temp;
  temp=first;
  if(first->getNext()==nullptr){
    first=nullptr;
    last=nullptr;
    count=0;
    delete temp;
  }
  else{
    first=first->getNext();
    temp->setNext(nullptr);
    delete temp;
    count--;
  }
}

template <typename Type>
Type& list<Type>::front() 
{
  if(first==nullptr) throw string("There are no elements in list!");
  else return (*first).getInfo(); 
}

template<typename Type>
const Type& list<Type>::front() const{
  if(first==nullptr) throw string("There are no elements in list!");
  else return (*first).getInfo(); 
}

template <typename Type>
Type& list<Type>::back()
{
  if(last==nullptr) throw string("There are no elements in list!");
  return (*last).getInfo();
}

template <typename Type>
const Type& list<Type>::back()const
{
  if(last==nullptr) throw string("There are no elements in list!");
  return (*last).getInfo();
}


template <typename Type>
list<Type>::list()
{
  first = nullptr;
  last = nullptr;
  count = 0;

}

 template <typename Type>
 void list<Type>::copyList(const list<Type>& otherList)
{
  nodeType<Type> *newNode;
  nodeType<Type> *current;
  if (first != nullptr)
  clear();
  if (otherList.first == nullptr)
  {
  first = nullptr;
  last = nullptr;
  count = 0;
  }
  else
  {
  current = otherList.first; 
  count = otherList.count; 
  first = new nodeType<Type>; 
  (*first).setInfo((*current).getInfo()); 
  (*first).setNext(nullptr); 
  last = first; 
  current = (*current).getNext(); 
  while (current != nullptr) 
  {
  newNode = new nodeType<Type>;  
  (*newNode).setInfo((*current).getInfo()); 
  (*newNode).setNext(nullptr); 
  (*last).setNext(newNode); 
  last = newNode;   current = (*current).getNext();
  }
  }
  }

template <typename Type>
list<Type>::list(const list<Type>& otherList)
{
first = nullptr;
copyList(otherList);
}

template <class Type>
list<Type>& list<Type>::operator=(const list<Type>& otherList)
{
if (this != &otherList)
{
 copyList(otherList);
}
return *this;
}

template<typename Type>
list<Type>::list(list<Type>&& otherList){
  if(otherList.first==nullptr){
  this->count=0;
  this->first=nullptr;
  this->last=nullptr;

  }

else{
 first=otherList.first;
 count=otherList.count;
 last=otherList.last;
 otherList.first=nullptr;
 otherList.last=nullptr;
 otherList.count=0;
 cout<<"Move constructor!"<<endl;
  }
}

template <typename Type>
list<Type>& list<Type>::operator=(list<Type>&& otherList)
{
clear();
first=otherList.first;
count=otherList.count;
last=otherList.last;
otherList.first=nullptr;
otherList.last=nullptr;
otherList.count=0;
cout<<"Move operator!"<<endl;

return *this;
}

template <typename Type>
list<Type>::~list()
{
 clear();
}


template<typename Type>
class list<Type>::iterator : public std::iterator<std::forward_iterator_tag, Type>
{
  
  public:
  typedef nodeType<Type> point;
  iterator(point *p) : pel(p){}
  
  point& operator*(){return *pel;}
  iterator& operator++(){pel=pel->getNext(); return *this ;} 
  iterator operator++(int){
  iterator temp = *this;
  pel=pel->getNext();
  return temp;
    }
  bool operator!=(const iterator& b)const{return pel!=b.pel;}
  bool operator==(const iterator& b)const{return pel== b.pel;}
  point* getPel() {return pel;}
  protected:
  point  *pel;
};

template<typename Type>
class list<Type>::const_iterator : public std::iterator<std::forward_iterator_tag, Type>
{
  
  public:
  typedef nodeType<Type> const_point;
  const_iterator(const_point *p) : pel(p){}
  const_iterator(iterator it){pel=it.getPel();}
  const_point& operator*()const{return *pel;}
  const_iterator& operator++(){pel=pel->getNext(); return *this ;} 
  const_iterator operator++(int){
  const_iterator temp = *this;
  pel=pel->getNext();
  return temp;
  }
  bool operator!=(const const_iterator& b)const{return pel!= b.pel;}
  bool operator==(const const_iterator& b)const{return pel == b.pel;}
   private:
  const_point  *pel;
};

template<typename Type>
void list<Type>::insert(const_iterator position,const Type& val){
  if(empty())
  (*this).push_back(val);
  else{
  nodeType<Type> *newNode;
  newNode=new nodeType<Type>;
  newNode->setInfo(val);
   if((*position).getNext()==nullptr){
   last=newNode;
   }
  newNode->setNext((*position).getNext());
  (*position).setNext(newNode);
  nodeType<Type> *temp;
  temp=new nodeType<Type>;
  temp->setInfo((*position).getInfo());
  (*position).setInfo(newNode->getInfo());
  newNode->setInfo(temp->getInfo());
  count++;

  


}


}


template<typename Type>
void list<Type>::insert (const_iterator position, Type&& val){
  if(empty())
  (*this).push_back(val);
  else{
  nodeType<Type> *newNode;
  newNode=new nodeType<Type>;
  newNode->setInfo(val);
   if((*position).getNext()==nullptr){
   last=newNode;
   }
  newNode->setNext((*position).getNext());
  (*position).setNext(newNode);
  nodeType<Type> *temp;
  temp=new nodeType<Type>;
  temp->setInfo((*position).getInfo());
  (*position).setInfo(newNode->getInfo());
  newNode->setInfo(temp->getInfo());
  count++;

}

  }

template<typename Type>
void list<Type>::pop(Type& val){
nodeType<Type> *temp;
  temp=first;
  if(!empty())
  {
  if(first->getNext()==nullptr)
  {
  delete temp;
  first=nullptr;
  last=nullptr;
  count=0;
  }
  else if(temp->getInfo()==val){first=first->getNext(); count--; delete temp;}
  else{while(temp->getNext()->getInfo()!=val){temp=temp->getNext();}
  temp->setNext(temp->getNext()->getNext());
  if(temp->getNext()==nullptr) last=temp;
  delete temp->getNext();
  count--;
 }
}
}
#endif
