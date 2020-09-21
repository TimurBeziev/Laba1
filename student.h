#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <windef.h>

class Student : public Person {
 public:
  void Accept(Visitor* visitor) override;
  explicit Student(POINT persons_location);
};

#endif //STUDENT_H
