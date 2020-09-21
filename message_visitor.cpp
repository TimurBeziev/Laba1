#include "message_visitor.h"
void MessageVisitor::Visit(Student* student) {
  person_text_ = "Hi, Student!!";
}
void MessageVisitor::Visit(Professor* professor) {
  person_text_ = "Good evening, Mr. Professor!!!";
}
std::string MessageVisitor::ShowMessage() {
  return person_text_;
}
void MessageVisitor::ClearMessage() {
  person_text_ = "";
}
