cmake_minimum_required(VERSION 3.15)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp visitor.h student_queue.cpp student.cpp person.cpp professor.cpp professors_queue.cpp controller.cpp controller.h draw_cafeteria.cpp draw_cafeteria.h message_visitor.cpp message_visitor.h)