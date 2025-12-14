#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

int main(int argc, char ** argv) {
  // NEXT:
  // Separate the flag verification into
  // a separate file, or a separate function.
  if (argc < 2) {
    printf("Usage: %s <text [MAX_SIZE == 200]> [-hex | -binary | -help]\n", argv[0]);
    exit(-1);
  } else if (argc == 2 && strcmp(argv[1], "-help") != 0) {
    printf("ERRO: you must inform the conversion type\n");
    printf("Usage: %s <text [MAX_SIZE == 200]> [-hex | -binary | -help]\n", argv[0]);
    exit(-1);
  };
  converter(argc, argv);
  return 0;
}
