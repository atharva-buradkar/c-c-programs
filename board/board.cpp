#include "board.h"


void board::create_board_cells(int rows, int cols)
{
    num_of_rows = rows;
    num_of_cols = cols;

    for (int r = 0; r < num_of_rows; r++)
    {
        std::vector<cell> row;

        for (int c = 0; c < num_of_cols; c++)
        {
            cell a_cell;
            a_cell.set_board_index_r(r);
            a_cell.set_board_index_c(c);
            row.push_back( a_cell );
        }

        cells.push_back( row );        
    }
    
}

void board::set_top_most_pixel(int top_most_pixel_in)
{
    top_most_pixel = top_most_pixel_in;
}

void board::set_left_most_pixel(int left_most_pixel_in)
{
    left_most_pixel = left_most_pixel_in;
}

void board::draw(bool cells_have_border)
{
    for (int r = 0; r < num_of_rows; r++)
    {
        for (int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].draw(top_most_pixel, left_most_pixel, cells_have_border);
        }
    }
    draw_cursor();
}

void board::erase()
{
    for (int r = 0; r < num_of_rows; r++)
    {
        for (int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].erase(top_most_pixel, left_most_pixel);
        }
    }
}

void board::resize_board(int new_board_height, int new_board_width)
{

}

void board::resize_cells(int new_cell_height, int new_cell_width)
{

}

void board::refresh()
{

}

void board::move(int offset_r, int offset_c)
{

}

void board::clear_board_state()
{

}

void board::fill_board(int value)
{

}

void board::set_cell_height(int cell_height_in)
{
    for(int r = 0; r < num_of_rows; r++)
    {
        for(int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].set_height(cell_height_in);
        }
    }
}

void board::set_cell_width(int cell_width_in)
{
    for(int r = 0; r < num_of_rows; r++)
    {
        for(int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].set_width(cell_width_in);
        }
    }
}

void board::set_cell_color(int color)
{
    for(int r = 0; r < num_of_rows; r++)
    {
        for(int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].set_cell_color(color);
        }
    }
}

void board::set_cell_border_color(int color)
{
    for(int r = 0; r < num_of_rows; r++)
    {
        for(int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].set_border_color(color);
        }
    }
}

void board::set_cursor_color(int color)
{
    cursor_color = color;
}

void board::set_cell_erase_color(int color)
{
    for(int r = 0; r < num_of_rows; r++)
    {
        for(int c = 0; c < num_of_cols; c++)
        {
            cells[r][c].set_erase_color(color);
        }
    }
}

void board::draw_cursor()
{
    cells[cursor_index_r][cursor_index_c].draw_border(top_most_pixel, left_most_pixel, cursor_color);
}

board::board()
{
    cursor_index_r = 0;
    cursor_index_c = 0;    
}

void board::move_cursor(int direction)
{
    switch (direction)
    {
    case UP:
        if (cursor_index_r > 0)
        {
            cursor_index_r--;
        }
        break;
    case DOWN:
        if (cursor_index_r < num_of_rows - 1)
        {
            cursor_index_r++;
        }
        break;
    case LEFT:
        if (cursor_index_c > 0)
        {
            cursor_index_c--;
        }
        break;
    case RIGHT:
        if (cursor_index_c < num_of_cols - 1)
        {
            cursor_index_c++;
        }
        break;
    default:
        break;
    }
}
