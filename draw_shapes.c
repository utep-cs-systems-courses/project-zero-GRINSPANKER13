#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

// Prints a arrow of specified head heigth whose left edge is at the col leftCol.
// Uses a combination of print_triangle and print_square from above.
void print_arrow(int leftCol, int size)
{
  // Prints the head of the arrow, a triangle.
  for (int row = 0; row <= size; row++) {
      int minCol = leftCol + size - row, maxCol = leftCol + size + row;
      int col;
      for (col = 0; col < minCol; col++) putchar(' ');
      for (       ; col <= maxCol; col++) putchar('*');
      putchar('\n');
    }

  // Prints the body of the arrow, a rectangle. Width is determined by the last row of the head.
  int i, j;
  int length = size+1;
  int width = (2*(size+1))-1;
  int endCol = leftCol + width-2;
  for (int row = 0; row < length; row++) {
      int col;
      for (col = 0; col < leftCol+1; col++) putchar(' ');
      for (       ; col < endCol+1;  col++) putchar('*');
      putchar('\n');
    }
}
