#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include <windef.h>

class Professor: public Person {
 public:
  void Accept(Visitor* visitor) override;
  explicit Professor(POINT persons_location);
};

#endif //PROFESSOR_H
