/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "./class.h"

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
  // STUDENT TODO: Construct an instance of your class!

  /* #### Please don't change this line! #### */
  myClass<int,int,int> demo = myClass<int,int,int>(20,20,20);
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"