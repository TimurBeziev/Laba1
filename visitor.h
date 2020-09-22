#ifndef VISITOR_H
#define VISITOR_H

class Student;
class Professor;

class Visitor {
 public:
  virtual void Visit(Student* student) = 0;
  virtual void Visit(Professor* professor) = 0;
};

#endif //VISITOR_H
