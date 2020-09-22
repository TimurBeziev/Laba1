#include "professors_queue.h"
ProfessorsQueue::ProfessorsQueue(int number_of_professors) {
  for (int i = 0; i < number_of_professors; i++) {
    AddProfessor();
  }
}
void ProfessorsQueue::AddProfessor() {
  POINT professor_position = {400, 100};
  auto* professor = new Professor(professor_position);
  professors_queue_.push_back(professor);
  professors_quantity_++;
}
void ProfessorsQueue::RemoveProfessor(Professor* professor) {
  if (professors_quantity_ > 0) {
    auto index =
        std::find(professors_queue_.begin(),
                  professors_queue_.end(),
                  professor);
    if (index != professors_queue_.end()) {
      professors_queue_.erase(index);
      professors_quantity_--;
      delete professor;
    }
  }
}
Professor* ProfessorsQueue::GetProfessor() {
  if (!professors_queue_.empty()) {
    return professors_queue_[0];
  }
  return nullptr;
}
int ProfessorsQueue::ProfessorsQuantity() {
  return professors_quantity_;
}
