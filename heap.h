#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  std::vector<T> vect;
  int leafCount;
  PComparator comp;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : leafCount(m), comp(c) {

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  this->vect.push_back(item);
  std::size_t index = vect.size() - 1;
  std::size_t parent;

  // Continues to trickle up tree until parent is better or reaches highest node
  while (index != 0) {
    parent = (index - 1) / 2;

    if (this->comp(this->vect[index], this->vect[parent])) {
      std::swap(this->vect[index], this->vect[parent]);
      index = parent;
    }
    else {
      break;
    }
  }
}


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
    throw std::underflow_error("Heap is empty - top()");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vect[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty - pop()");
  }

  this->vect[0] = this->vect[this->vect.size() - 1];
  this->vect.pop_back();

  size_t parent = 0;
  size_t child;
  size_t it;
  bool bottomOfTreeFlag = true;

  // Continues to trickle down if the best child node is better than it
  while (((parent * 2) + leafCount) < this->size()) {
    child = (parent * 2) + 1;
    it = child + 1;

    for (int i = 0; i < leafCount; ++i) {
      if (this->comp(this->vect[it + i], this->vect[child])) {
        child = it + i;
      }
    }

    if (this->comp(this->vect[child], this->vect[parent])) {
      std::swap(this->vect[parent], this->vect[child]);
      parent = child;
    }
    else {
      bottomOfTreeFlag = false;
      break;
    }
  }

  // If at the bottom of the tree, unknown number of child nodes,
  // need to be careful not to reference outside of vector
  if (bottomOfTreeFlag && ((parent * 2) + 1) < this->vect.size()) {
    child = (parent * 2) + 1;

    for (it = child + 1; it < this->vect.size(); ++it) {
      if (this->comp(this->vect[it], this->vect[child])) {
        child = it;
      }
    }

    if (this->comp(this->vect[child], this->vect[parent])) {
      std::swap(this->vect[parent], this->vect[child]);
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return (this->size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return this->vect.size();
}

#endif