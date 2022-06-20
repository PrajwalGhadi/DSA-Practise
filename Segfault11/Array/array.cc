/**
  Generic Array ADT
  @file array.cc
  @author Rohit Gautam
*/

#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>

enum arithmatic_operator { add, sub, mul, truediv };
void swap(int& a, int& b) {
  int t;
  t = a, a = b, b = t;
};

template <typename T>
struct Array {
 public:
  Array(const size_t size) : size_{size}, data_{new T[size], std::default_delete<T[]>()} {}

  /**
    Returns an rvalue reference of given index position
    @param index position of element in array
    @return rvalue reference of element
  */
  const T& at(size_t index = 0) const {
    assert(index < size_);
    return data_.get()[index];
  }

  /**
    Returns an lvalue reference of given index position
    @param index position of element in array
    @return lvalue reference of element
  */
  T& at(size_t index = 0) {
    assert(index < size_);
    return data_.get()[index];
  }

  /**
    Returns the size of the container
    @return capacity of the container
  */
  size_t size() const { return size_; }

  /**
    Perform element-wise arithmatic operation
    @param rhs right hand side operand container
    @param ar_ops arithmatic operator
    @return new resulting container with same type
  */
  Array<T> do_arithmatic(const Array<T>& rhs, arithmatic_operator ar_ops) const {
    assert(size_ == rhs.size());
    Array<T> result(size_);
    for (int i = 0; i < size_; i++) {
      switch (ar_ops) {
        case add:
          result.at(i) = at(i) + rhs.at(i);
          break;
        case sub:
          result.at(i) = at(i) - rhs.at(i);
          break;
        case mul:
          result.at(i) = at(i) * rhs.at(i);
          break;
        case truediv:
          result.at(i) = at(i) / rhs.at(i);
          break;
      }
    }
    return result;
  }

  /**
    Insert element at a given index position
    @param index position of element to insert in the array
    @param element element to insert
    @return element after insertion
  */
  int insert(const size_t index, const T element);

  /**
    Returns the index of given element in the array.
    throws std::invalid_argument if element is not inside the container
    @param element element to search
    @return index of the element
  */
  size_t index(T element) const;
  /**
    Sort the container in-place with worst-case time complexity of O(n^2)
    @param reverse boolean indicating to sort in descending order
  */
  void sort(bool reverse = false);

  bool operator==(const Array<T>& rhs) const;
  Array<T> operator+(const Array<T>& rhs) const;
  Array<T> operator-(const Array<T>& rhs) const;
  Array<T> operator*(const Array<T>& rhs) const;
  Array<T> operator/(const Array<T>& rhs) const;

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Array<U>& array);

 protected:
  std::shared_ptr<T> data_;
  size_t size_;
};

template <typename T>
size_t Array<T>::index(T element) const {
  for (int i = 0; i < size_; i++) {
    if (at(i) == element) {
      return i;
    }
  }
  std::stringstream ss;
  ss << element << " is not in array\n";
  throw std::invalid_argument(ss.str());
}

template <typename T>
void Array<T>::sort(bool reverse) {
  for (int i = 0; i < size_; i++) {
    for (int j = i; j < size_; j++) {
      if (reverse) {
        if (at(i) < at(j)) {
          swap(at(i), at(j));
        }
      } else {
        if (at(i) > at(j)) {
          swap(at(i), at(j));
        }
      }
    }
  }
}

template <typename T>
int Array<T>::insert(const size_t index, const T element) {
  assert(index < size_);
  data_.get()[index] = element;
  return element;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& rhs) const {
  if (size_ != rhs.size()) {
    return false;
  }

  for (int i = 0; i < size_; i++) {
    if (at(i) != rhs.at(i)) {
      return false;
    }
  }
  return true;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& rhs) const {
  return do_arithmatic(rhs, add);
}

template <typename T>
Array<T> Array<T>::operator-(const Array<T>& rhs) const {
  return do_arithmatic(rhs, sub);
}

template <typename T>
Array<T> Array<T>::operator*(const Array<T>& rhs) const {
  return do_arithmatic(rhs, mul);
}

template <typename T>
Array<T> Array<T>::operator/(const Array<T>& rhs) const {
  return do_arithmatic(rhs, truediv);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
  const int n = array.size();
  os << "[ ";
  for (int i = 0; i < n; i++) {
    os << array.at(i) << ", ";
  }
  os << "\b\b ]";
  return os;
}

int main() {
  int size = 6;
  Array<int> array(size);
  Array<int> array2(size);

  for (int i = 0; i < size; i++) {
    array2.at(i) = i;
  }

  array.at(0) = 5;
  array.at(1) = 11;
  array.at(2) = 4;
  array.at(3) = 2;
  array.at(4) = 15;
  array.at(5) = 3;

  std::cout << array << '\n';
  std::cout << array2 << '\n';

  std::cout << (array + array2) << '\n';

  return 0;
}
