//change increase/decrease interval
char *upinterval = "10";
char *downinterval = "10";
//change the seek interval
char *seekforwardint = "10";
char *seekbackint = "10";

//keybinds//
#define clearconsole 'c'
#define add_entry 'a'
#define nowplaying 't'
#define list_titles 'l'
#define enable_raw 'r'
#define enable_verbose 'v'
#define help_msg 'h'
#define volume_increase '+'
#define volume_decrease '-'
#define change_position 'g'
//change the prompt
char cprompt[] = "\nSMP console ~$ ";
//modes
//should headfull be enabled by default?
bool headfull_bool = true;
//should raw be enabled by default?
bool raw_bool = true;
// should verbose be enabled by default?
bool verbose_bool = true;

//clear the text with ctrl + l
#define cl_clear 0x0C
 
