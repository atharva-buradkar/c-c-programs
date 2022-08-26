#include "cell.h"

class board
{
private:
    int pattern_type;
    int num_of_rows;
    int num_of_cols;
    int top_most_pixel;
    int left_most_pixel;
    int cursor_color;
    int cursor_index_r;
    int cursor_index_c;
    std::vector<std::vector<cell>> cells;

public:
    void create_board_cells(int height_in, int width_in);
    void set_top_most_pixel(int board_index_r_in);
    void set_left_most_pixel(int board_index_c_in);
    void draw(bool cells_have_border);
    void erase();
    void resize_board(int new_board_height, int new_board_width);
    void resize_cells(int new_cell_height, int new_cell_width);
    void refresh();
    void move(int offset_r, int offset_c);
    void clear_board_state();
    void fill_board(int value);
    void set_cell_height(int cell_height_in);
    void set_cell_width(int cell_height_in);
    void set_cell_color(int color);
    void set_cell_border_color(int color);
    void set_cursor_color(int color);
    void set_cell_erase_color(int color);
    void draw_cursor();
    void move_cursor(int direction);
    board();
};
 