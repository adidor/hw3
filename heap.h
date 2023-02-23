#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  // @brief Destroy the Heap object
  ~Heap();

  //@brief Push an item to the heap
   //@param item item to heap
  void push(const T& item);

   //@brief Returns the top (priority) item
  //@return T const& top priority item
  //@throw std::underflow_error if the heap is empty
  T const & top() const;

  //@brief Remove the top priority item
  //@throw std::underflow_error if the heap is empty
  void pop();

  /// returns true if the heap is empty
  //@brief Returns true if the heap is empty
  bool empty() const;

   //@brief Returns size of the heap
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items;
  PComparator co;
  int m_ary;
};

// Add implementation of member functions here


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  m_ary = m;
  co = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{
  items.push_back(item);
  int i = items.size()-1;
  while (i!=0){
    int pi = (i-1)/m_ary;
    T& prt = items[pi];
    T& cld = items[i];
    if (co(prt,cld)){
      break;
    }
      T temp = prt;
      prt=cld;
      cld=temp;
      i=pi;
  } 
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw(std::underflow_error(""));
  }
  return items[0];
}





template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if (items.size()==0){
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return items.size();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("");
  }
  int i = 0;
  T temp = items[0];
  items[0]=items[items.size()-1];
  items[items.size()-1]=temp;
  items.pop_back();

  while(items.size()-1>i){
    int ci = 1+(m_ary*i);
    int cci = ci;
    while (cci <= ((i+1)*m_ary)){
      if (items.size()>cci){
        if (co(items[cci], items[ci])){
          ci = cci;
        }
      }
      ++cci;
    }

    
    T& cld = items[ci];
    T& prt = items[i];

    if(items.size()<=ci || i == items.size()){
      break;
    }
    else if(co(prt, cld)){
      break;
    }
    T temp = prt;
    prt=cld;
    cld=temp;
    i = ci;
  }
}



#endif

