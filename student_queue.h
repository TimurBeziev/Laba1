#ifndef STUDENT_QUEUE_H
#define STUDENT_QUEUE_H

#include "student.h"
#include "set"
#include "random"
#include "algorithm"

class StudentsQueue {
 public:
  // friend class StudentsIterator;
  explicit StudentsQueue(int number_of_students);
  void AddStudent();
  void RemoveStudent(Student* student);
  Student* GetStudent();
  int StudentsQuantity();
 private:
  std::vector<Student*> students_queue_;
  int students_quantity_ = 0;
};

// class StudentIterator {
//  public:
//   int GetQuantity();
// };

#endif //STUDENT_QUEUE_H
