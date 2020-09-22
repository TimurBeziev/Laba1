#include "draw_cafeteria.h"

void DrawCafeteria::DrawStudent(HDC hdc, Student* student, int quantity) {
  HBRUSH brush_handle = CreateSolidBrush(RGB(255, 255, 0));
  SelectObject(hdc, brush_handle);
  Rectangle(hdc,
            student->GetCoordinates().x - 20,
            student->GetCoordinates().y - 20,
            student->GetCoordinates().x + 20,
            student->GetCoordinates().y + 20);
  std::string number = std::to_string(quantity);
  TextOut(hdc, 90, 90, number.c_str(), number.length());
  DeleteObject(brush_handle);
}

void DrawCafeteria::DrawProfessor(HDC hdc, Professor* professor, int quantity) {
  HBRUSH brush_handle = CreateSolidBrush(RGB(200, 0, 10));
  SelectObject(hdc, brush_handle);
  Rectangle(hdc,
            professor->GetCoordinates().x - 50,
            professor->GetCoordinates().y - 50,
            professor->GetCoordinates().x + 50,
            professor->GetCoordinates().y + 50);
  std::string number = std::to_string(quantity);
  TextOut(hdc, 400, 100, number.c_str(), number.length());
  DeleteObject(brush_handle);
}
void DrawCafeteria::ShowMessage(HDC hdc, std::string message) {
  HBRUSH brush_handle = CreateSolidBrush(RGB(0, 0, 0));
  SelectObject(hdc, brush_handle);
  TextOut(hdc, 100, 300, message.c_str(), message.length());
  DeleteObject(brush_handle);
}
void DrawCafeteria::DrawShopAssistant(HDC hdc) {
  HBRUSH brush_handle = CreateSolidBrush(RGB(0, 255, 0));
  SelectObject(hdc, brush_handle);
  POINT center = {300, 300};
  Rectangle(hdc,
            center.x ,
            center.y - 20,
            center.x + 100,
            center.y + 70);
  DeleteObject(brush_handle);
}
