#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

// Uses font_5x7 bitmap, which is 5 rows and 7 columns representing the bits.
void print_char_5x7(char c)
{
  c -=0x20; // Space character starts at 32 (0x20) in the ASCII table.
  for (char row = 0; row < 5; row++) { // Loop through the rows.
    unsigned short rowBits = font_5x7[c][row]; // Grab the corresponding bitmap entry.
    for (char col = 0; col < 7; col++) { // Loop through the columns.
      unsigned short colMask = 1 << (6-col); // Grab the corresponding bit.
      putchar( (rowBits & colMask) ? '*' : ' '); // Print '*' if bit is 1 and ' ' if bit is 0.
    }
    putchar('\n'); // Print new line after each row.
  }
  putchar('\n'); // Print new line after each character.
}

// Uses font_8x12 bitmap, which is 12 rows and 8 columns representing the bits.
void print_char_8x12(char c)
{
  c -= 0x20;
  for (char row = 0; row < 12; row++) {
    unsigned short rowBits = font_8x12[c][row];
    for (char col = 0; col < 8; col++) {
      unsigned short colMask = 1 << (7-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}
