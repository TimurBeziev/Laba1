#include "student_queue.h"
StudentsQueue::StudentsQueue(int number_of_students) {
  for (int i = 0; i < number_of_students; i++) {
    AddStudent();
  }
}
void StudentsQueue::AddStudent() {
  // изначально думал добавлять много студентов и сделать всек красиво
  // но я устал
  POINT student_position = {100, 100};
  auto* student = new Student(student_position);
  students_queue_.push_back(student);
  students_quantity_++;
}
void StudentsQueue::RemoveStudent(Student* student) {
  if (students_quantity_ > 0) {
    auto index =
        std::find(students_queue_.begin(), students_queue_.end(), student);
    if (index != students_queue_.end()) {
      students_queue_.erase(index);
      students_quantity_--;
      delete student;
    }
  }
}
Student* StudentsQueue::GetStudent() {
  if (!students_queue_.empty()) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, students_queue_.size()-1);
    int student_index = dis(gen);
    return students_queue_[student_index];
  }
  return nullptr;

}
int StudentsQueue::StudentsQuantity() {
  return students_quantity_;
}
