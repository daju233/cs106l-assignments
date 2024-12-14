/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User {
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /**
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  friend User& operator+=(User& user,User& other);
  friend bool operator<(const User& user,const User& other);
  friend std::ostream& operator<<(std::ostream& output, const User& user);

  // Implement a destructor for the User class. To do so, implement the User::~User() SMF.
  ~User() { delete[] this->_friends; };

  // Make the User class copy constructible. To do so, implement the User::User(const User& user)
  // SMF.
  User(const User& user) {
    this->_capacity = user._capacity;
    this->_size = user._size;
    this->_name = user._name;
    this->_friends = new std::string[user._size];
    for (size_t i = 0; i < user._size; ++i) {
      this->_friends[i] = user._friends[i];
    }
  };

  // Make the User class copy assignable. To do so, implement the User& User::operator=(const User&
  // user) SMF.
  User& operator=(const User& user) {
    this->_capacity = user._capacity;
    this->_size = user._size;
    this->_name = user._name;
    delete[] this->_friends;
    this->_friends = new std::string[user._size];
    for (size_t i = 0; i < user._size; ++i) {
      this->_friends[i] = user._friends[i];
    }
    return *this;
  };

  // Prevent the User class from being move constructed. To do so, delete the User::User(User&&
  // user) SMF. Prevent the User class from being move assigned. To do so, delete the User&
  // User::operator=(User&& user) SMF.
  User(User&& user) = delete;
  User& operator=(User&& user) = delete;


private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};