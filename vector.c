#include "metro.h"

#define first_count  10
#define set_buf_size(v) (v->buf_size = v->_item_size * v->actual_count)

#define get_itemptr(v, i) ((char*)v->buf + i * v->_item_size)

Vector* vec_new(size_t item_size) {
  Vector* vec = calloc(1, sizeof(Vector));

  vec->actual_count = 10;
  vec->_item_size = item_size;

  vec->buf = calloc(vec->actual_count, item_size);
  vec->buf_size = vec->actual_count * item_size;

  vec->count = 0;

  return vec;
}

void vec_assign(Vector* vec, size_t i, void* item) {
  memcpy(get_itemptr(vec, i), item, vec->_item_size);
}

void* vec_get(Vector* vec, size_t i) {
  return get_itemptr(vec, i);
}

void vec_push(Vector* vec, void* item) {
  memcpy(get_itemptr(vec, vec->count), item, vec->_item_size);

  vec->count++;

  // realloc to double size if overed half
  if( vec->count >= vec->actual_count >> 1 ) {
    vec->actual_count <<= 1;
    vec->buf = realloc(vec->buf, vec->actual_count);
    set_buf_size(vec);
  }
}

void vec_push_front(Vector* vec, void* item) {
  if( vec->count >= 1 ) {
    for( char* ptr = get_itemptr(vec, vec->count - 1); ptr != vec->buf; ptr -= vec->_item_size ) {
      memcpy(ptr, ptr + vec->_item_size, vec->_item_size);
    }
  }

  vec_assign(vec, 0, item);
}

void vec_pop(Vector* vec) {
  vec->count--;
}

void vec_pop_front(Vector* vec) {
  memcpy((char*)vec->buf + vec->_item_size, vec->buf, (vec->count - 1) * vec->_item_size);
}

void vec_erase(Vector* vec, size_t index) {
  if( index == vec->count - 1 ) {
    vec_pop(vec);
  }
  else if( index == 0 ) {
    vec_pop_front(vec);
  }
  else {
    memcpy(get_itemptr(vec, index - 1), get_itemptr(vec, index), vec->count - index - 1);
    vec->count--;
  }
}

void vec_free(Vector* vec) {
  free(vec->buf);
  free(vec);
}
