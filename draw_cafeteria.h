#ifndef DRAW_CAFETERIA_H
#define DRAW_CAFETERIA_H

#include <windows.h>
#include "student.h"
#include "professor.h"
#include "student_queue.h"
#include "professors_queue.h"

class DrawCafeteria {
 public:
  void DrawStudent(HDC hdc, Student* student, int quantity);
  void DrawProfessor(HDC hdc, Professor* professor, int quantity);
  void DrawShopAssistant(HDC hdc);
  void ShowMessage(HDC hdc, std::string message);

};

#endif //DRAW_CAFETERIA_H
