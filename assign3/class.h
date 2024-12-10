template <typename T, typename U, typename K> class myClass {
private:
  T wealth;
  U health;
  K mana;
  void addMana() {}

public:
  myClass(T wealth, U health, K mana) {}
  myClass() {}
  T getWealth() const { return this->wealth; }
  U getHealth() const { return this->health; }
  K getMana() const { return this->mana; }
  void setWealth(T value) {}
  void setHealth(U value) {}
  void setMana(K value) {}
};