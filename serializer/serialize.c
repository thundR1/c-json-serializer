/**
 * @file serialize.c
 * @author Youssef Amin
 * @brief struct-to-file serializer and vice-versa
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "serialize.h"

EN_serialize_error person_serialize(Person* p, FILE* file) {
  EN_serialize_error ret = SERIALIZE_OK;
  if (p == NULL || file == NULL) {
    ret = SERIALIZE_NOT_OK;
  } else {
    if (fprintf(file, PERSON_FORMAT_OUT, p->name, p->age) < 0) {
      ret = SERIALIZE_NOT_OK;
    }
  }
  return ret;
}
EN_serialize_error person_deserialize(Person* p, FILE* file) {
  fseek(file, 0, SEEK_SET);
  EN_serialize_error ret = SERIALIZE_OK;
  if (p == NULL || file == NULL) {
    ret = SERIALIZE_NOT_OK;
  } else {
    fscanf(file, PERSON_FORMAT_IN, p->name, &(p->age));
  }
  return ret;
}
EN_serialize_error person_serialize_arr(Person* p, FILE* file, uint32_t size) {
  EN_serialize_error ret = SERIALIZE_OK;
  if (p == NULL || file == NULL) {
    ret = SERIALIZE_NOT_OK;
  } else {
    if (fprintf(file, "%s", "[\n") < 0)
      ret = SERIALIZE_NOT_OK;
    for (uint32_t idx = 0; idx < size; idx++) {
      if (fprintf(file, PERSON_FORMAT_OUT, p[idx].name, p[idx].age) < 0) {
        ret = SERIALIZE_NOT_OK;
      }
    }
    if (fprintf(file, "%s", "]\n") < 0)
      ret = SERIALIZE_NOT_OK;
  }
  return ret;
}
