#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "config.h"

void enableRawMode();
void disableRawMode();

int main()
{
	char c;
	char s[1024];
	printf("\e[1;1H\e[2J");
	printf("AniTrack\n");
	enableRawMode();
	for(;;)
	{
		switch(c = getchar())
		{
			case add_entry:
				printf("now this is epic\n");
				break;
		}
	}
		
}

struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
