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
	bool raw = true;
	for(;;)
	{
		switch(c = getchar())
		{
			case add_entry:
				disableRawMode();
				printf("name of anime: ");
				scanf("%1024[0-9a-zA-Z ]", s);
				printf("the name of the anime was %s", s);
				enableRawMode();
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
