template <typename T, typename U, typename K> class myClass {
private:
  T wealth;
  U health;
  K mana;
  void addMana() {}

public:
  myClass(T wealth, U health, K mana) {}
  myClass() {}
  T getWealth() const {}
  U getHealth() const {}
  K getMana() const {}
  void setWealth(T value) {}
  void setHealth(U value) {}
  void setMana(K value) {}
};
