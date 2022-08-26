#include "cell.h"
#include "board.h"
#include "ncurses_setup.h"

int main()
{
    int cell_height = 3;
    int cell_width = cell_height * 2;

    int num_of_rows = 22;
    int num_of_cols = 22;

    initialize_ncurses();
    init_color_pairs();

    int screen_max_r = get_screen_max_r();
    int screen_max_c = get_screen_max_c();

    int board_pixel_top = (screen_max_r - (cell_height * num_of_rows)) / 2;
    int board_pixel_left = (screen_max_c - (cell_width * num_of_cols)) / 2;

    board my_board;
    my_board.create_board_cells(num_of_rows, num_of_cols);
    my_board.set_top_most_pixel(board_pixel_top);
    my_board.set_left_most_pixel(board_pixel_left);
    my_board.set_cell_height(cell_height);
    my_board.set_cell_width(cell_width);
    my_board.set_cell_color(CELL_COLOR);
    my_board.set_cell_border_color(EMPTY_COLOR);
    my_board.set_cursor_color(CURSOR_COLOR);
    my_board.set_cell_erase_color(EMPTY_COLOR);
    my_board.fill_board(EMPTY);
    
    

    bool quit = false;
    while (true)
    {
        my_board.draw(true);

        int ch = getch();

        switch (ch)
        {
        case KEY_UP:
            my_board.move_cursor(UP);
            break;
        case KEY_DOWN:
            my_board.move_cursor(DOWN);
            break;
        case KEY_LEFT:
            my_board.move_cursor(LEFT);
            break;
        case KEY_RIGHT:
            my_board.move_cursor(RIGHT);
            break;
        case 'q':
            quit = true;
        default:
            break;
        }

        if(quit)
        {
            break;
        }
    }

    endwin();
    return 0;
}