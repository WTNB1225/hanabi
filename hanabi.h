#ifndef CLASS_HANABI
#define CLASS_HANABI

#include <ncurses.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 11
#define MIN_SIZE 6
#define RISING_SYMBOL '|'
#define FADE_SYMBOL '.'

typedef struct hanabi
{
    const char* symbols;
    int is_rise;
    int canvas_height;
    int canvas_width;
    int launch_x;
    int launch_y;
    int burst_x;
    int burst_y;

} Hanabi;

void constructor(Hanabi* const self, const char* symbols);
int get_symbols_len(Hanabi* const self);
void print_rising(Hanabi* const self);
void print_burst(Hanabi* const self);
void launch(Hanabi* const self, int is_rise);

#endif
