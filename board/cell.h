#pragma once

#include "includes.h"

class cell
{
private:
    int height;
    int width;
    int board_index_r;
    int board_index_c;
    int cell_color;
    int border_color;
    int erase_color;
    int state;

public:
    void set_height(int height_in);
    void set_width(int width_in);
    void set_board_index_r(int board_index_r_in);
    void set_board_index_c(int board_index_c_in);
    void set_cell_color(int cell_color_in);
    void set_border_color(int border_color_in);
    void set_erase_color(int erase_color_in);
    void set_state(int state_in);

    void draw(int offset_r, int offset_c, bool has_border);
    void draw_border(int offset_r, int offset_c, int color);
    void erase(int offset_r, int offset_c);
};
