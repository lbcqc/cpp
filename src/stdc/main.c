//
// Created by root on 24-4-16.
//
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
  int x;
  int y;
} Point;

Point get_Point(void);

int main(void) {
  Point my_Point = get_Point();
  printf("Point:(%d,%d)\n", my_Point.x, my_Point.y);

  return 0;
}

Point get_Point(void) {
  // 值语义
  Point p = {10, 20};
  return p;
}
