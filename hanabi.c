#include "hanabi.h"

#include <ncurses.h>
#include <math.h>
#include <stdlib.h>

void init(void)
{
    initscr();
    start_color();    
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);
    init_pair(0, COLOR_RED, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void constructor(Hanabi* const self, const char* symbols)
{
    init();
    int canvas_width;
    int canvas_height;
    
    getmaxyx(stdscr, canvas_height, canvas_width);

    self->symbols = symbols;
    self->canvas_width = canvas_width;
    self->canvas_height = canvas_height;
    self->launch_x = canvas_width / 2 - 20 + rand() % 40 + 1;
    self->launch_y = canvas_height / 1.5;
    self->burst_x = self->launch_x;
    self->burst_y = canvas_height / 4;
}

int get_symbols_len(Hanabi* const self)
{
    int i;
    int length;
    const char* symbols;
    i = 0;
    length = 0;
    symbols = self->symbols;
    while (symbols[i])
    {
        if ((symbols[i] & 0xc0) != 0x80)
        {
            length++;
        }

        i++;
    } 
    return length;
}

void print_rising(Hanabi* const self)
{
    int now_height;
    
    now_height = self->launch_y;

    while (1)
    {
        werase(stdscr);
        mvaddch(now_height, self->launch_x, '|');
        refresh();

        now_height--;

        if (now_height < self->burst_y)
        {
            werase(stdscr);
            break;
        }


        napms(50);
    }
}

void print_burst(Hanabi* const self)
{
    int i;
    int j;
    int cir_x;
    int cir_y;
    double rad;
    int symbol_length;
    int aspect_ratio;
    int color_num;

    i = 0;
    j = 0;
    symbol_length = get_symbols_len(self);
    aspect_ratio = 2;
    color_num = rand() % 6; 
    int radius = 6; 

    werase(stdscr);
    attron(COLOR_PAIR(color_num));
    while (i < symbol_length)
    {
        for (j = 0; j < 360; j += 30)
        {
            rad = j * M_PI / 180.0;
            cir_x = (int)(self->burst_x + aspect_ratio * radius * cos(rad));
            cir_y = (int)(self->burst_y + radius * sin(rad));
            mvaddch(cir_y, cir_x, self->symbols[i]);
        }
        i++;
        radius -= 1;
    }
    refresh();
    napms(300);

    i = 0;
    radius = 6;
    while (i < symbol_length)
    {
        for (j = 0; j < 360; j += 30)
        {
            rad = j * M_PI / 180.0;
            cir_x = (int)(self->burst_x + aspect_ratio * radius * cos(rad));
            cir_y = (int)(self->burst_y + radius * sin(rad));
            mvaddch(cir_y, cir_x, '.');
        }
        i++;
        radius -= 1;
    }
    refresh();
    napms(600);

    attroff(COLOR_PAIR(color_num));
}

void launch(Hanabi* const self, int is_rise)
{
    int canvas_width;
    int canvas_height;
    canvas_width = self->canvas_width;
    canvas_height = self->canvas_height;
    self->launch_x = canvas_width / 2 - 20 + rand() % 40 + 1;
    self->launch_y = canvas_height / 1.5;
    self->burst_x = self->launch_x;
    self->burst_y = canvas_height / 4;
    if (is_rise == 1)
    {
        print_rising(self);
    }

    print_burst(self);
}
