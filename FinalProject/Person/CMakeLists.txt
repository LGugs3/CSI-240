cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Person")

add_executable(Person "person.h" "person.cpp" "patient.h" "patient.cpp" "doctor.h" "doctor.cpp" "doctorOperations.cpp" "doctorOperations.h" "patientOperations.h" "patientOperations.cpp" "commonOperations.h" "commonOperations.cpp" "schedulerOperations.cpp" "schedulerOperations.h" "final-part5.cpp")