#include <iostream>
#include <string>
#include <vector>
#include <cctype>

const int SUDOKU_SIZE = 9;
const int BOX_SIZE = 3;

typedef std::vector<std::vector<char> > board_type;

bool is_valid_vector(const std::vector<char>& vec)
{
	// create a bitmap and set everything to 0 initially
	// TODO change to a different data type
	std::vector<int> presence(SUDOKU_SIZE, 0);
	for (int i = 0; i < vec.size(); ++i)
	{
		// TODO rewrite this with a stringstream
		presence[vec[i] - '0'] = 0;
	}

	for(int i = 0; i < presence.size(); ++i)
	{
		if(presence[i] == 0)
		{
			return false;
		}
	}

	return true;
}

bool is_valid_box(const board_type& board, int i, int j, int box_size)
{
	std::vector<char> tmp(box_size * box_size);
	for(int i1 = 0; i1 < box_size; ++i1)
	{
		for(int j1 = 0; j1 < box_size; ++j1)
		{
			tmp.push_back(board[i + i1][j + j1]);
		}
	}
	return is_valid_vector(tmp);
}

bool validate_and_load(const std::string& grid, board_type& board)
{
	if(grid.length() != SUDOKU_SIZE * SUDOKU_SIZE)
	{
		return false;
	}

	// reserve enough memory for better performance in the inner vectors
	for(int i = 0; i < board.size(); ++i)
	{
		board[i].reserve(SUDOKU_SIZE);
	}
	for(int i = 0; i < SUDOKU_SIZE; ++i)
	{
		for(int j = 0; j < SUDOKU_SIZE; ++j)
		{
			char c = grid[i * SUDOKU_SIZE + j];
			if(!std::isdigit(c))
			{
				return false;
			}
			board[i][j] = c;
		}
	}

	return true;
}

bool is_valid_solution(const std::string& grid)
{
	board_type board(SUDOKU_SIZE);
	if(!validate_and_load(grid, board))
	{
		return false;
	}

	// check rows
	for(int i = 0; i < SUDOKU_SIZE; ++i)
	{
		if(!is_valid_vector(board[i]))
		{
			return false;
		}
	}

	// check columns
	for(int j = 0; j < SUDOKU_SIZE; ++j)
	{
		std::vector<char> tmp(SUDOKU_SIZE);
		for (int i = 0; i < SUDOKU_SIZE; ++i)
		{
			tmp.push_back(board[i][j]);
		}

		if(!is_valid_vector(tmp))
		{
			return false;
		}
	}

	// check boxes
	for(int i = 0; i < SUDOKU_SIZE; i += BOX_SIZE)
	{
		for(int j = 0; j < SUDOKU_SIZE; j += BOX_SIZE)
		{
			if(!is_valid_box(board, i, j, BOX_SIZE))
			{
				return false;
			}
		}
	}

	return true;
}

int main() {

	std::string solution;
	std::cin >> solution;

	std::cout << (is_valid_solution(solution) ? "Valid" : "Invalid" ) + " solution\n";
}
