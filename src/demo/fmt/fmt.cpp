//
// Created by root on 3/23/24.
//
#include "fmt/os.h"

int main(int argc, char *argv[]) {
  auto out = fmt::output_file("guide.txt");
  out.print("Don't {}", "Panic");
  return 0;
}