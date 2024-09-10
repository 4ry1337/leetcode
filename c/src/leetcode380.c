#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int *arr;
  size_t length;
  size_t capacity;
} RandomizedSet;

RandomizedSet *randomizedSetCreate() {
  RandomizedSet *set = (RandomizedSet *)malloc(sizeof(RandomizedSet));
  set->capacity = 10;
  set->arr = (int *)calloc(set->capacity, sizeof(int));
  set->length = 0;
  srand(time(NULL));
  return set;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
  for (int i = 0; i < obj->length; i++) {
    if (obj->arr[i] == val) {
      return false;
    }
  }
  if (obj->capacity == obj->length) {
    size_t new_size = obj->capacity * 2;
    int *values = (int *)realloc(obj->arr, new_size * sizeof(int));
    if (values == NULL) {
      printf("Unable to allocate memory\n");
      return false;
    }
    obj->capacity = new_size;
    obj->arr = values;
  }
  obj->arr[obj->length++] = val;
  return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
  if (obj == NULL) {
    printf("NULL set pointer\n");
    return false;
  }
  if (obj->length == 0) {
    printf("Remove attempt on an empty set\n");
    return false;
  }
  for (int i = 0; i < obj->length; i++) {
    if (obj->arr[i] == val) {
      obj->arr[i] = obj->arr[obj->length - 1];
      obj->length--;
      return true;
    }
  }
  return false;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
  if (obj->length == 0) {
    return -1;
  }
  return obj->arr[rand() % obj->length];
}

void randomizedSetPrint(RandomizedSet *obj) {
  printf("Length: %ld\n", obj->length);
  printf("Capacity: %ld\n", obj->capacity);
}

void randomizedSetFree(RandomizedSet *obj) {
  free(obj->arr);
  free(obj);
}
