## Tic Tac Toe AI using MiniMax Algorithm
This is a simple command line Tic Tac Toe game written in C++.   
There are 3 modes:
- Player vs Player
- Player vs Computer (easy)
- Player vs Computer (hard)

The AI is implemented using the [MiniMax algorithm](https://www.neverstopbuilding.com/blog/minimax)

---
## How to Play

When promped enter the x and y coordinates of your move.  
For example `x = 1, y = 2` will result in the following move:
```console
     x1  x2  x3
    -------------
 y1 |   |   |   |
    -------------
 y2 | X |   |   |
    -------------
 y3 |   |   |   |
    -------------
```

---
## Compiling and running
Uses g++ to compile.  
To compile run the Make comand with `tictac`:
```console
❯ Make tictac
```
Then to run the exicutable:
```console
❯ ./tictac
```
---
## Notes
- Since Tic Tac Toe is a solved game, while on hard mode you can, at best, tie with the AI.
