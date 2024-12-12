/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

#include "utils.h"

std::string kYourName = "Donald Trump"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
/**
* 获取文件名并返回包含所有申请人姓名的集合。
*
* @param filename 要读取的文件的名称。
* 文件的每一行都是一个申请人的姓名。
* @returns 从文件中读取的所有申请人姓名的集合。
*
* @remark 请随意更改此函数的返回类型（以及函数
* 在其下方）使用 `std::unordered_set` 代替。如果您这样做，请确保
* 同时更改`utils.h`中的相应函数。
*/
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs(filename);
  std::string line;
  
  std::set<std::string> students;

  while(std::getline(ifs,line)){

    students.insert(line);
  } 
  return students;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
/**
* 通过引用获取一组学生姓名并返回姓名队列
* 与给定的学生姓名相匹配。
*
* @param name 返回的名称队列应该与名称具有相同的首字母缩写。
* @param Students 学生姓名集。
* @return 包含指向每个匹配名称的指针的队列。
*/
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> queue;
  std::stringstream test(name);
  std::string str1,str2;
  test>>str1>>str2;

  for(const auto& s:students){
    std::stringstream test2(s);
    std::string str3,str4;
    test2>>str3>>str4;
    if(str1[0]==str3[0]&&str2[0]==str4[0]) queue.push(&s);
    test.clear();
  }
  return queue;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
/**
* 接收指向可能匹配的指针队列并确定一个真正的匹配！
*
* 你可以随心所欲地实现这个功能，但是尝试做一些事情
* 比简单的 `pop()` 更复杂。
*
* @param matches 可能匹配的队列。
* @return 你神奇的真爱。
* 将返回“未找到匹配项”。如果“matches”为空。
*/
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.size()>0){return *(matches.front());}
  else return "NO MATCHES FOUND.";
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
