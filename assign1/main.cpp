/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */
 /**
* 表示学生可以在 ExploreCourses 中学习的课程。
* 您必须填写此结构体中字段的类型。
* 提示：还记得 C++ 流支持哪些类型吗？！
*/
struct Course {
  /* STUDENT TODO */ std::string title;
  /* STUDENT TODO */ std::string number_of_units;
  /* STUDENT TODO */ std::string quarter;
};


/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
 /**
* （学生待办事项） 看看 main 函数如何 （在本文件底部）
* 调用 'parse_csv'、'write_courses_offered' 和 'write_courses_not_offered”。
* 修改这些函数的签名，使其按预期工作，然后删除此函数
*评论！
*/

//*注意：
/**
* 我们需要 #include utils.cpp _after_ 声明上面的 Course 结构体
* 以便 utils.cpp 中的代码知道 Course 是什么。
* 回想一下，#include 实际上是复制和粘贴文件内容。
*/
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
 /**
* 此函数应使用 struct 类型的 'courses' 向量
* '课程'。我们希望使用 courses.csv 中的记录创建这些结构
* 文件，其中每行都是一条记录！
*
*提示：
* 1） 看看我们在 utils.cpp 中提供的 split 函数
* 2） 每个 LINE 都是一条记录！*这很重要，所以我们再说一遍 ：>）*
* 3） CSV 中的第一行定义了列名，因此您可以忽略它！
*
* @param filename 要解析的文件的名称。
* @param 课程 要填充的课程向量。
*/
void parse_csv(std::string filename, std::vector<Course> &courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ifstream ifs(filename);
  std::string line;
  std::getline(ifs,line);

  while(std::getline(ifs,line)){
    std::vector<std::string> result = split(line,',');
    Course course = {result[0],result[1],result[2]};
    courses.push_back(course);
  }
}

/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
 /**
* 此功能有两个要求。
*
* 1) 将开设的课程写入文件
*“student_output/courses_offered.csv”
*
* 2) 删除`all_courses`向量中提供的课程。
* 重要提示：在写入文件后执行此操作！
*
* 提示：
* 1) 跟踪您需要删除的类！
* 2）使用我们为您提供的delete_elem_from_vector函数！
* 3) 请记住在输出的开头写入 CSV 列标题！
* 请参阅 course.csv 以供参考。
*
* @param all_courses 通过调用“parse_csv”获取的所有课程的向量。
* 该向量将通过删除所有提供的课程进行修改。
*/
void write_courses_offered(std::vector<Course> &all_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream ofs("/home/maxwell/Documents/cs106l-assignments/assign1/student_output/courses_offered.csv");
  ofs<<"Title,Number of Units,Quarter"<<'\n';
  std::vector<Course> trashs;
  for(Course result:all_courses){
    if(result.quarter!="null"){
    ofs<<result.title<<","<<result.number_of_units<<","<<result.quarter<<'\n';
    trashs.push_back(result);
    }
  }
    for(Course trash:trashs){
      delete_elem_from_vector(all_courses,trash);
  }
      std::cout<<all_courses.size()<<std::endl;
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
 /**
* 该函数将未提供的课程写入文件
*“student_output/courses_not_offered.csv”。
*
* 该函数始终在 `write_courses_offered` 函数之后调用。
* `unlisted_courses` 将简单地包含未提供的课程
* 因为您从“all_courses”中删除了提供的课程
* `write_courses_offered` 函数。
*
* 提示：这应该与 `write_courses_offered` 非常相似
*
* @param unlisted_courses 未提供的课程向量。
*/
void write_courses_not_offered(std::vector<Course> &unlisted_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::cout<<unlisted_courses.size()<<std::endl;
  std::ofstream ofs("/home/maxwell/Documents/cs106l-assignments/assign1/student_output/courses_not_offered.csv");
  ofs<<"Title,Number of Units,Quarter"<<'\n';
  for(Course& result:unlisted_courses){
    // std::cout<<result.title<<result.number_of_units<<result.quarter<<std::endl;
    ofs<<result.title<<","<<result.number_of_units<<","<<result.quarter<<'\n';
  }
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);
  std::cout<<"测试"<<courses.size()<<std::endl;

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}