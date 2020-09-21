#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "student_queue.h"
#include "professors_queue.h"
#include "draw_cafeteria.h"
#include "message_visitor.h"

class Controller {
 public:
  Controller();
  void AddStudent();
  void AddProfessor();
  void NextPerson();
  void Draw(HDC hdc);
  void FirstBuyer(Person* person);
 private:
  StudentsQueue* student_queue_;
  ProfessorsQueue* professors_queue_;
  MessageVisitor* message_visitor_;

  DrawCafeteria* draw_cafeteria_;
  std::mt19937 gen_;
  std::random_device rd_;
  std::uniform_int_distribution<> dis_;

};

#endif //CONTROLLER_H
