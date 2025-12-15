#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 200

// ---------------- TODO ----------------
// text to hexadecimal    [ X ]
// text to binary         [ X ]
// hexadecimal to text    [   ]
// hexadecimal to binary  [   ]
// binary to text         [   ]
// binary to hexadecimal  [   ]
// ---------------- TODO ----------------

void convert_text_to_hex(const char * buffer);
void convert_text_to_binary(const char * buffer);

void converter(int argc, char ** argv) {
  if (strcmp(argv[1], "-help") == 0) {
      printf("<text>  : text formatted in ASCII-UTF8");
      printf("-binary : transform text in binary\n");
      printf("-hex    : transform text in hexadecimal\n");
      printf("-help   : show all possibles commands\n");
  }
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "-hex") ==  0) {
      for (int k = 1; k < i; k++) {
        convert_text_to_hex(argv[k]);
        if (k < i-1) {
          printf("20");
        }
      }
      printf("\n");
    } else if (strcmp(argv[i], "-binary") == 0) {
      for (int k = 1; k < i; k++) {
        convert_text_to_binary(argv[k]);
        if (k < i-1) {
          printf("00100000 ");
        }
      }
      printf("\n");
    }
  }
}

void convert_text_to_hex(const char * buffer) {
  for (int i = 0; i < strlen(buffer); i++) { 
    printf("%02X", buffer[i]);
  }
}

// Next:
// Remove the string from buffer and
// simply print the result of the conversion directly.
void convert_text_to_binary(const char * buffer) {
  size_t len = strlen(buffer);
  char * binary_string = (char*) malloc(len * CHAR_BIT + 1);
  char * ptr = binary_string;
  for (size_t i = 0; i < len; i++) {
    char target = buffer[i];
    for (int k = CHAR_BIT - 1; k >=0; k--) {
      if (target & (1 << k)) {
        *ptr++ = '1';
      } else {
        *ptr++ = '0';
      }
    }
  }
  *ptr = '\0';
  for (int l = 0; l < strlen(binary_string); l++) {
    if ((l % 8 == 0 && l > 0)) {
      printf(" ");
    }
    printf("%c", binary_string[l]);
  }
  printf(" ");
  free(binary_string);
}
