//
// Created by root on 3/24/24.
//
#include <setjmp.h> /* jmp_buf, setjmp, longjmp */
#include <stdio.h>  /* printf, scanf */
#include <stdlib.h> /* exit */
int main(int argc, char *argv[]) {
  jmp_buf env;
  int val;
  val = setjmp(env);
  if (val) {
    fprintf(stderr, "Error %d happened\n", val);
    exit(val);
  }
  /* code here */
  fprintf(stderr, "this is longjmp before\n");
  longjmp(env, 101); /* signaling an error */
  return 0;
}