# usage
This is a sample code, create a new vector of `int` and do somethings.
```c
#include <stdio.h>
#include "vector.h"

int main() {

  // Create a vector
  Vector* vec = vec_new(sizeof(int));
  
  // push values 0 to 5
  // WARN: MUST PASS ADDRESS TO ARGUMENT WITH '&'
  // IN POINTER CASE, BE CAREFUL TO DO NOT PASS IT DIRECTORY.
  // CREATE A NEW VARIABLE OF COPY OF POINTER, AND PASS IT IN vec_push
  for( int i = 0; i <= 5; i++ ) {
    vec_push(vec, &i);
  }
  
  // remove 1 and 3
  vec_erase(vec, 3);
  vec_erase(vec, 1);
  
  // print all
  for( size_t i = 0; i < vec->count; i++ ) {
    printf("%s\n", vecget(int, vec, i));
  }
  
  // destroy
  vec_free(vec);
  
  return 0;
}
```
