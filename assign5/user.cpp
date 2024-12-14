#include "user.h"
#include <set>
/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name) : _name(name), _friends(nullptr), _size(0), _capacity(0) {}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void User::add_friend(const std::string& name) {
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* others = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      others[i] = _friends[i];
    }
    delete[] _friends;
    _friends = others;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string User::get_name() const { return _name; }

/**
 * Returns the number of friends this User has.
 */
size_t User::size() const { return _size; }

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name) { _friends[index] = name; }

/**
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

User& operator+=(User& user,User& other){
  user.add_friend(other.get_name());
  other.add_friend(user.get_name());
  return user;
}

bool operator<(const User& user,const User& other){
  std::set<std::string> set;
  set.insert(user.get_name());
  set.insert(other.get_name());
   // 获取两个元素的迭代器
   auto it1 = set.find(user.get_name());
   auto it2 = set.find(other.get_name());
  return *it1<*it2;
}

std::ostream& operator<<(std::ostream& output, const User& user) {
  output << "User(name=" << user.get_name() << ", friends=[";
  // 不要起一个varable = user.size()的变量，这样写非常容易越界ub
  // 我是傻逼，所以不要这么写
  // 可以输出每一个元素和后面的逗号，检查是否是最后一个元素
  for (size_t i = 0; i < user.size(); i++) {
    output << user._friends[i];
    if (i != user.size() - 1) {
      output << ", ";
    }
  }
  // 也可以这样写
  /*
    检查是否有朋友列表
    if (user.size() > 0) {
    输出第一个朋友，不带前缀的逗号
    output << user._friends[0];

    如果有超过一个朋友，输出剩余的朋友并用逗号分隔
    for (size_t i = 1; i < user.size(); ++i) {
    output << ", " << user._friends[i];
    }
  */
  output << "])";
  return output;
}