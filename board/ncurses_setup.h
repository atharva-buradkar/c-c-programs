#pragma once

#include "includes.h"

void initialize_ncurses()
{
    initscr();			/* Start curses mode 		*/
	start_color();			/* Start the color functionality */
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	noecho();
    

    curs_set(0);
}

void init_color_pairs()
{
    init_pair(CURSOR_COLOR, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(BORDER_COLOR, COLOR_BLACK, COLOR_BLACK);
    init_pair(TEXT_COLOR, COLOR_GREEN, COLOR_GREEN);
    init_pair(CELL_COLOR, COLOR_BLUE, COLOR_BLUE);
    init_pair(EMPTY_COLOR, COLOR_BLACK, COLOR_BLACK);
}

int get_screen_max_r()
{
    int screen_max_r, screen_max_c;
    getmaxyx( stdscr, screen_max_r, screen_max_c);
    return screen_max_r;
}

int get_screen_max_c()
{
    int screen_max_r, screen_max_c;
    getmaxyx( stdscr, screen_max_r, screen_max_c);
    return screen_max_c;
}
