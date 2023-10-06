/**
 * @file serialize.h
 * @author Youssef Amin
 * @brief struct-to-file serializer and vice-versa
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SERIALIZE_H
#define SERIALIZE_H

/* Include Section Start */
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Include Section End */

/* Macros Section Start */
#define MAX_NAME_SIZE 25
#define PERSON_FORMAT_OUT "{\"name\": \"%s\", \"age\": %u},\n"
#define PERSON_FORMAT_IN "{\"name\": \"%[^\"]\", \"age\": %u},\n"
/* Macros Section End */

/* Function Like Macros Section Start */
#define PANIC(msg)                                                  \
  do {                                                              \
    fprintf(stderr, "Error: %s Cause: %s\n", msg, strerror(errno)); \
    exit(EXIT_FAILURE);                                             \
  } while (0)
/* Function Like Macros Section End */

/* Types Section Start */
typedef enum { SERIALIZE_OK, SERIALIZE_NOT_OK } EN_serialize_error;

typedef struct {
  char name[MAX_NAME_SIZE];
  uint32_t age;
} Person;
/* Types Section End */

/* Function Section Start */
EN_serialize_error person_serialize(Person* p, FILE* file);
EN_serialize_error person_deserialize(Person* p, FILE* file);
EN_serialize_error person_serialize_arr(Person* p, FILE* file, uint32_t size);
/* Function Section End */

#endif /* SERIALIZE_H */