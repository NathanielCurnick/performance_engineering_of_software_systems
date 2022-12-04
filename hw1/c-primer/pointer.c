// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{ // What is the type of argv?
  // argv is a pointer to a char array

  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int *pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char *pc = c; // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d); // What does this print?
  // It prints "char d = 6"

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char **pcp;
  pcp = argv; // Why is this assignment valid?
  // argv is itself a pointer, so pcp points to a pointer

  const char *pcc = c;  // pcc is a pointer to char constant
  char const *pcc2 = c; // What is the type of pcc2? It is a pointer to c

  // For each of the following, why is the assignment:
  // *pcc = '7';  // invalid? Since '7' is not a pointer
  pcc = *pcp;    // valid? pcp is a pointer to a pointer, which we dereference into a pointer and assign to pcc
  pcc = argv[0]; // valid? argv is a char array, so pcc now points to the first element

  char *const cp = c; // cp is a const pointer to char
  // For each of the following, why is the assignment:
  // cp = *pcp;  // invalid? Dereferencing pcp would make it a char, and cp is a pointer
  // cp = *argv;  // invalid? Same as above, this time for a char array
  *cp = '!'; // valid? We dereference cp, so it points to this '!'

  const char *const cpc = c; // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  // cpc = *pcp;  // invalid?
  // cpc = argv[0];  // invalid?
  // *cpc = '@';  // invalid?

  return 0;
}
