#pragma once

// vector
typedef struct Vector Vector;
struct Vector {
  void* buf;
  size_t buf_size;
  size_t actual_count;
  size_t count;
  size_t _item_size;
};

// warn: all functions no implemented safety checker (index-check, null-check, etc...)
Vector* vec_new(size_t item_size);
void vec_assign(Vector* vec, size_t i, void* item);
void* vec_get(Vector* vec, size_t i);
void vec_push(Vector* vec, void* item);
void vec_push_front(Vector* vec, void* item);
void vec_pop(Vector* vec);
void vec_pop_front(Vector* vec);
void vec_erase(Vector* vec, size_t index);
void vec_free(Vector* vec);

#define vecget(T,v,i) (*(T*)(vec_get(v, i)))
