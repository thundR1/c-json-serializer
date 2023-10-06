/**
 * @file main.c
 * @author Youssef Amin
 * @brief struct-to-file serializer and vice-versa (Example File)
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "serializer/serialize.h"

int main(void) {
  EN_serialize_error check = SERIALIZE_OK;
  FILE* file = fopen("persons.txt", "w+");

  if (file == NULL) {
    check = SERIALIZE_NOT_OK;
  } else {
    Person p = {.name = "Youssef", .age = 22};
    Person p2;

    if (person_serialize(&p, file) != SERIALIZE_OK) {
      check = SERIALIZE_NOT_OK;
    }
    if (person_deserialize(&p2, file) != SERIALIZE_OK) {
      check = SERIALIZE_NOT_OK;
    }
    if (check == SERIALIZE_OK) {
      printf("P2: Person{name=%s, age=%d}\n", p2.name, p2.age);
    }
  }

  if (check != SERIALIZE_OK) {
    PANIC("Operation Failed");
  }

  return 0;
}
