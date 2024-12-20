#pragma once

#include <cstddef>
#include <utility>

/**
 * @brief A smart pointer that owns an object and deletes it when it goes out of scope.
 * @tparam T The type of the object to manage.
 * @note This class is a simpler version of `std::unique_ptr`.
 */
template <typename T> class unique_ptr {
private:
  T* ptr;
  /* STUDENT TODO: What data must a unique_ptr keep track of? */

public:
  /**
   * @brief Constructs a new `unique_ptr` from the given pointer.
   * @param ptr The pointer to manage.
   * @note You should avoid using this constructor directly and instead use `make_unique()`.
   */
  unique_ptr(T* ptr) : ptr(ptr) {
    /* STUDENT TODO: Implement the constructor */
    // throw std::runtime_error("Not implemented: unique_ptr(T* ptr)");
  }

  /**
   * @brief Constructs a new `unique_ptr` from `nullptr`.
   */
  unique_ptr(std::nullptr_t) : ptr(nullptr) {
    /* STUDENT TODO: Implement the nullptr constructor */
    // throw std::runtime_error("Not implemented: unique_ptr(std::nullptr_t)");
  }

  /**
   * @brief Constructs an empty `unique_ptr`.
   * @note By default, a `unique_ptr` points to `nullptr`.
   */
  unique_ptr() : ptr(nullptr) {}

  /**
   * @brief Dereferences a `unique_ptr` and returns a reference to the object.
   * @return A reference to the object.
   */
  T& operator*() {
    /* STUDENT TODO: Implement the dereference operator */
    return *ptr;
    // throw std::runtime_error("Not implemented: operator*()");
  }

  /**
   * @brief Dereferences a `unique_ptr` and returns a const reference to the object.
   * @return A const reference to the object.
   */
  const T& operator*() const {
    const T& e = *ptr;
    /* STUDENT TODO: Implement the dereference operator (const) */
    return e;
    // throw std::runtime_error("Not implemented: operator*() const");
  }

  /**
   * @brief Returns a pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A pointer to the object.
   */
  T* operator->() {
    /* STUDENT TODO: Implement the arrow operator */
    return ptr;
    // throw std::runtime_error("Not implemented: operator->()");
  }

  /**
   * @brief Returns a const pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A const pointer to the object.
   */
  const T* operator->() const {
    /* STUDENT TODO: Implement the arrow operator */
    const T* e = ptr;
    return e;
    // throw std::runtime_error("Not implemented: operator->() const");
  }

  /**
   * @brief Returns whether or not the `unique_ptr` is non-null.
   * @note This allows us to use a `unique_ptr` inside an if-statement.
   * @return `true` if the `unique_ptr` is non-null, `false` otherwise.
   */
  operator bool() const {
    /* STUDENT TODO: Implement the boolean conversion operator */
    return ptr == nullptr ? false : true;
    // throw std::runtime_error("Not implemented: operator bool() const");
  }

  /** STUDENT TODO: In the space below, do the following:
   * - Implement a destructor
   * - Delete the copy constructor
   * - Delete the copy assignment operator
   * - Implement the move constructor
   * - Implement the move assignment operator
   */
  ~unique_ptr() {
    if (this->ptr != nullptr)
      delete ptr;
  }
  unique_ptr(unique_ptr&& other) {
    //接管other的ptr
    this->ptr = other.ptr;
    other.ptr = nullptr;
  }
  //移动赋值
  unique_ptr& operator=(unique_ptr&& other) {
    //避免自我赋值
    if (this != &other) {
      delete ptr;
      this->ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  // 在你提供的 unique_ptr
  // 的移动构造函数和移动赋值运算符的实现中，潜在的内存泄漏问题出现在移动赋值运算符 (operator=) 中。
  // 具体来说，如果你不释放当前对象持有的资源（即 this->ptr 指向的内存），那么当你将 other.ptr
  // 赋值给 this->ptr 时， 原来的 this->ptr
  // 指向的内存将被泄露，因为它不再有任何指针指向它，并且没有被显式删除。
  unique_ptr(const unique_ptr& other) = delete;
  unique_ptr& operator=(const unique_ptr& other) = delete;
};

/**
 * @brief Creates a new unique_ptr for a type with the given arguments.
 * @example auto ptr = make_unique<int>(5);
 * @tparam T The type to create a unique_ptr for.
 * @tparam Args The types of the arguments to pass to the constructor of T.
 * @param args The arguments to pass to the constructor of T.
 */
template <typename T, typename... Args> unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}