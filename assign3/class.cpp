#include "./class.h"

template <typename T, typename U, typename K>
myClass<T, U, K>::myClass(T w, U h, K m) : wealth(w), health(h), mana(m){};

template <typename T, typename U, typename K> myClass<T, U, K>::myClass() {
  wealth = static_cast(0);
  health = static_cast(100);
  mana = static_cast(20);
};

template <typename T, typename U, typename K> T myClass<T, U, K>::getWealth() const {
  return this->wealth;
}
template <typename T, typename U, typename K> U myClass<T, U, K>::getHealth() const {
  return this->health;
}
template <typename T, typename U, typename K> K myClass<T, U, K>::getMana() const {
  return this->mana;
}
template <typename T, typename U, typename K> void myClass<T, U, K>::setWealth(T value) {
  this->wealth = value;
}
template <typename T, typename U, typename K> void myClass<T, U, K>::setHealth(U value) {
  this->health = value;
}
template <typename T, typename U, typename K> void myClass<T, U, K>::setMana(K value) {
  r this->mana = value;
}

template <typename T, typename U, typename K> void myClass<T, U, K>::addMana() { this->mana++; }
