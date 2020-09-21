#include "controller.h"
Controller::Controller() {
  professors_queue_ = new ProfessorsQueue(10);
  student_queue_ = new StudentsQueue(3);
  draw_cafeteria_ = new DrawCafeteria();
  message_visitor_ = new MessageVisitor();
  gen_ = std::mt19937(rd_());
  dis_ = std::uniform_int_distribution<>(0, 10000);
}
void Controller::AddStudent() {
  if (student_queue_->StudentsQuantity() == 0) {
    FirstBuyer(student_queue_->GetStudent());
  }
  student_queue_->AddStudent();
}
void Controller::AddProfessor() {
  if (professors_queue_->ProfessorsQuantity() == 0) {
    FirstBuyer(professors_queue_->GetProfessor());
  }
  professors_queue_->AddProfessor();

}
void Controller::NextPerson() {
  int result = dis_(gen_) % 2;
  if ((student_queue_->StudentsQuantity() > 0
      && result == 0) || ((student_queue_->StudentsQuantity() > 0
      && professors_queue_->GetProfessor() == nullptr))) {
    auto student = student_queue_->GetStudent();
    FirstBuyer(student);
    student_queue_->RemoveStudent(student);
  } else if (professors_queue_->ProfessorsQuantity() > 0
      || student_queue_->GetStudent() == nullptr) {
    auto professor = professors_queue_->GetProfessor();
    FirstBuyer(professor);
    professors_queue_->RemoveProfessor(professor);
  }
  // Да, скорее всего на такое больно смотреть
  // но сейчас у меня марафон на скорость, потому что уже просрочил дедлайн
  // Кстати говоря, надеюсь за такую микропросрочку меня не сильно накажут

  if (professors_queue_->ProfessorsQuantity() == 0
      && student_queue_->StudentsQuantity() == 0) {
    FirstBuyer(nullptr);
  }
}

void Controller::FirstBuyer(Person* person) {
  if (person != nullptr) {
    person->Accept(message_visitor_);
  } else {
    message_visitor_->ClearMessage();
  }
}

void Controller::Draw(HDC hdc) {
  if (student_queue_->StudentsQuantity() > 0) {
    auto student = student_queue_->GetStudent();
    draw_cafeteria_->DrawStudent(hdc,
                                 student,
                                 student_queue_->StudentsQuantity());
    draw_cafeteria_->ShowMessage(hdc, message_visitor_->ShowMessage());
  }

  if (professors_queue_->ProfessorsQuantity() > 0) {
    auto professor = professors_queue_->GetProfessor();
    draw_cafeteria_->DrawProfessor(hdc,
                                   professor,
                                   professors_queue_->ProfessorsQuantity());
    draw_cafeteria_->ShowMessage(hdc, message_visitor_->ShowMessage());
  }
  draw_cafeteria_->DrawShopAssistant(hdc);

}

