#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

int check_flags(int argc, char ** argv) {
  if (argc < 2) {
    printf("Usage: %s <text [MAX_SIZE == 200]> [-hex | -binary | -help]\n", argv[0]);
    return -1;
  } else if (argc == 2 && strcmp(argv[1], "-help") != 0) {
    printf("ERRO: you must inform the conversion type\n");
    printf("Usage: %s <text [MAX_SIZE == 200]> [-hex | -binary | -help]\n", argv[0]);
    return -1;
  };
  return 1;
}

int main(int argc, char ** argv) {
  if (check_flags(argc, argv) == -1) return -1;
  converter(argc, argv);
  return 0;
}
