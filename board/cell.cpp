#include "cell.h"

void cell::set_height(int height_in)
{
    height = height_in;
}

void cell::set_width(int width_in)
{
    width = width_in;
}

void cell::set_board_index_r(int board_index_r_in)
{
    board_index_r = board_index_r_in;
}

void cell::set_board_index_c(int board_index_c_in)
{
    board_index_c = board_index_c_in;
}

void cell::set_cell_color(int cell_color_in)
{
    cell_color = cell_color_in;
}

void cell::set_border_color(int border_color_in)
{
    border_color = border_color_in;
}

void cell::set_erase_color(int erase_color_in)
{
    erase_color = erase_color_in;
}

void cell::set_state(int state_in)
{
    state = state_in;
}

void cell::draw_border(int offset_r, int offset_c, int color=BORDER_COLOR)
{
    int pixel_r = (board_index_r * height) + offset_r;
    int pixel_c = (board_index_c * width) + offset_c;

    attron(COLOR_PAIR(color));

    // top
    for(int c = pixel_c; c < pixel_c + width; c++)
    {
        mvaddch(pixel_r, c, ACS_BLOCK);
    }
    // left
    for(int r = pixel_r; r < pixel_r + height; r++)
    {
        mvaddch(r, pixel_c, ACS_BLOCK); addch(ACS_BLOCK);
    }
    // right
    for(int r = pixel_r; r < pixel_r + height; r++)
    {
        mvaddch(r, pixel_c + width - 2, ACS_BLOCK); addch(ACS_BLOCK);
    }
    // bottom
    for(int c = pixel_c; c < pixel_c + width; c++)
    {
        mvaddch(pixel_r + height - 1, c, ACS_BLOCK);
    }

    attron(COLOR_PAIR(color));
}

void cell::draw(int offset_r, int offset_c, bool has_border)
{
    int pixel_r = (board_index_r * height) + offset_r;
    int pixel_c = (board_index_c * width) + offset_c;

    attron(COLOR_PAIR(cell_color));

    for(int r = pixel_r; r < pixel_r + height; r++)
    {
        for(int c = pixel_c; c < pixel_c + width; c++)
        {
            mvaddch(r, c, ACS_BLOCK);
        }
    }

    attron(COLOR_PAIR(cell_color));

    if (has_border)
    {
        draw_border(offset_r, offset_c);
    }
    
}

void cell::erase(int offset_r, int offset_c)
{
    int pixel_r = (board_index_r * height) + offset_r;
    int pixel_c = (board_index_c * width) + offset_c;

    attron(COLOR_PAIR(erase_color));

    for(int r = pixel_r; r < pixel_r + height; r++)
    {
        for(int c = pixel_c; c < pixel_c + width; c++)
        {
            mvaddch(r, c, ACS_BLOCK);
        }
    }

    attron(COLOR_PAIR(erase_color));
}