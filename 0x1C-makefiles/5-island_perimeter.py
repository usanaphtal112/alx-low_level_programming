#!/usr/bin/python3
"""Defines an island perimeter measuring function."""

def island_perimeter(grid):

    '''
    Calculates the perimeter of an island represented by a grid.

    This function takes a 2D grid as input, where each cell represents.
    It calculates the perimeter of the island formed by the contiguous.

    Parameters:
    - grid (list of lists): A 2D grid representing the island, where grid[i][j]

    Returns:
    - int: The perimeter of the island formed by the contiguous land cells.

    Example:
        grid = [
            [0, 1, 0, 0],
            [1, 1, 1, 0],
            [0, 1, 0, 0],
            [1, 1, 0, 0]
        ]
        island_perimeter(grid)  # Output: 16
    '''

    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1
    return size * 4 - edges * 2
