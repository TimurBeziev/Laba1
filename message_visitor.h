#ifndef MESSAGE_VISITOR_H
#define MESSAGE_VISITOR_H

#include "visitor.h"
#include "string"

class MessageVisitor: public Visitor {
 public:
  void Visit(Student* student) override ;
  void Visit(Professor* professor) override;
  std::string ShowMessage();
  void ClearMessage();
 private:
  std::string person_text_;
};

#endif //MESSAGE_VISITOR_H
