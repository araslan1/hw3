#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

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
  ~Heap(){

  }

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

  void heapify(int idx); 

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_; 
  PComparator c_; 
  int m_; 

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap"); 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  // std::cout << "BEFORE TOP VECTOR: ";
  // for (size_t i = 0; i < items_.size(); i++){
  //   std::cout << items_[i] << " ";
  // }
  // std::cout << "\n"; 
  return items_[0]; 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw(std::underflow_error("empty heap")); 
  }
  // std::cout << "BEFORE POP VECTOR: ";
  // for (size_t i = 0; i < items_.size(); i++){
  //   std::cout << items_[i] << " ";
  // }
  // std::cout << "\n"; 
  items_[0] = items_.back(); 
  items_.pop_back();

  heapify(0);

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx){

  //if leaf node return
  size_t tree_size = items_.size();
  size_t initial_child = idx*m_ + 1; 
  size_t next_child; 
  size_t next_index; 
  if (initial_child >= tree_size){
    return; 
  }
  for (int i = 2; i <= m_; i++){
    next_child = idx*m_ + i; 
    if (next_child < tree_size){
      if (c_(items_[next_child], items_[initial_child])){
        initial_child = next_child;
      }
    }
  }
  T& smaller_child = items_[initial_child];
  if (c_(smaller_child, items_[idx])){
    //swap
    std::swap(smaller_child, items_[idx]);
    heapify(initial_child);
  }

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if (items_.size() == 0){
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return items_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  items_.push_back(item);
  size_t index = items_.size()-1;
  while (index != 0){
    size_t parent_index = (index-1)/m_;
    T&current = items_[index];
    T&parent = items_[parent_index]; 
    if (c_(current, parent)){
      std::swap(current, parent);
      index = parent_index; 
    }else{
      break; 
    }
  }
}

template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c){
  c_ = c; 
  m_ = m;
}





#endif

