#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Arrow = a, Triangle = t, Square = s, Chars = c) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("You selected arrow:");
      print_arrow(5, 6);
      break;
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");

      // Label for where the font selection occurs.
    select_font:
      fputs("Select which font you want to print (11x16 = 1, 5x7 = 2, 8x12 = 3) or 'q' to quit\n> ", stdout);
      fflush(stdout);/* stdout only flushes automatically on \n */
      int c2;
      while ((c2 = getchar()) == '\n'); /* ignore newlines */
      if (c2 == EOF)     /* terminate on end-of-file */
	goto done;

      // Given the font selected, select which font to print.
      switch(c2) {
      case '1':
	puts("You selected 11x16:");
	for (char c = 'A'; c < 'D'; c++)
	  print_char_11x16(c);
	break;
      case '2':
	puts("You selected 5x7:");
	for (char c = 'A'; c < 'D'; c++)
	  print_char_5x7(c);
	break;
      case '3':
	puts("You selected 8x12:");
	for (char c = 'A'; c < 'D'; c++)
	  print_char_8x12(c);
	break;
      default:
	printf("Unrecognized option '%c', please try again!\n", c2);
	goto select_font;
      }
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
