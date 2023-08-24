#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

/*
c++ -g -Wall --std=c++11   heap.h
*/

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

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int mAry;
  PComparator comp;
  void heapify(int idx);

};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  this->mAry=m;
  this->comp=c;
}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}
// Add implementation of member functions here

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  std::size_t index = data.size() - 1;
  while (index!=0) {
    std::size_t parent_index = (index - 1) / mAry;
    T& current = data[index];
    T& parent = data[parent_index];
    if(comp(current,parent)){
      std::swap(current, parent);
      index = parent_index;
    } 
    else 
      break;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.empty();
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(data.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty!\n");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(data.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty!\n");
    
  }

    std::swap(data.front(),data.back());
    data.pop_back();
    if(data.empty()) return;
    heapify(0);
  
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  std::vector<unsigned int> dat;
  for(int i=1; i<mAry; i++){
    dat.push_back(mAry*idx+i);
  }
  int newidx=idx;
  for(unsigned int i=0; i<dat.size();i++){
    if(dat[i]<data.size() && comp(data[dat[i]],data[newidx])){
      newidx=dat[i];
    }
  }
  if(newidx!=idx){
    std::swap(data[idx],data[newidx]);
    heapify(newidx);
  }
}



#endif

