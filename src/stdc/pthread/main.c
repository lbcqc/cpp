//
// Created by root on 3/24/24.
//
#include <stdio.h>
#include <threads.h>

_Thread_local _Alignas(32) int thread_specific_data = 0;

int thread_function(void *arg) {
  thread_specific_data = *(int *) arg;
  printf("Thread %ld: thread_specific_data = %d\n", thrd_current(), thread_specific_data);
  return 0;
}

int main(void) {
  thrd_t thread1, thread2;
  _Alignas(16) int data_for_thread1 = 1;
  _Alignas(16) int data_for_thread2 = 2;

  thrd_create(&thread1, thread_function, &data_for_thread1);
  thrd_create(&thread2, thread_function, &data_for_thread2);

  thrd_join(thread1, NULL);
  thrd_join(thread2, NULL);

  return 0;
}