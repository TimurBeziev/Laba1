#ifndef PROFESSORS_QUEUE_H
#define PROFESSORS_QUEUE_H

#include "professor.h"
#include "set"
#include "random"
#include "algorithm"

class ProfessorsQueue {
 public:
  explicit ProfessorsQueue(int number_of_professors);
  void AddProfessor();
  void RemoveProfessor(Professor* professor);
  Professor* GetProfessor();
  int ProfessorsQuantity();
 private:
  std::vector<Professor*> professors_queue_;
  int professors_quantity_ = 0;
  Professor* first_professor_int_queue_;
};

#endif //PROFESSORS_QUEUE_H
