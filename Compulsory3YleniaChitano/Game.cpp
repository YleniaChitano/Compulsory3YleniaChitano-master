#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>
#include "header.h"

void makeEmptyBoard(std::vector <std::vector<char>>& board);
void makeEmptyBoard2(std::vector <std::vector<char>>& playerBoard);
int randomRow();
int randomColumn();
void writeLetters();
void makeBoard(int numberOfShips, std::vector <std::vector<char>>& board);
void printBoard(std::vector <std::vector<char>>& board);
void printAIBoard(std::vector <std::vector<char>>& playerBoard);
void printPlayerBoard(std::vector <std::vector<char>>& board);
void shoot(std::vector <std::vector<char>>& board, int& numberOfShots, int& numberOfHits);
void AIshoot(std::vector <std::vector<char>>& playerBoard, int& numberOfShots2, int& numberOfHits2);
void play();
void makeBoard3(int numberOfShips, std::vector <std::vector<char>>& board);

int numberOfShips = 2;
int M = 6;
int N = 6;



void play()
{
    int numberOfHits = 0;
    int numberOfShots = 0;
    int numberOfHits2 = 0;
    int numberOfShots2 = 0;
    int maxShots = 20;
    bool allShips = false;
    std::vector <std::vector <char>> board(M, std::vector<char>(N)); // A vector to store the content of the board
    std::vector <std::vector <char>> playerBoard(M, std::vector<char>(N));

    makeEmptyBoard(board);
    makeEmptyBoard2(playerBoard);


    while (numberOfShots <= maxShots && allShips == false)
    {
        std::cout << "Your board: \n\n";
        printAIBoard(playerBoard);
        std::cout << "Opponent's board: \n\n";
        printPlayerBoard(board);
        shoot(board, numberOfShots, numberOfHits);
        AIshoot(playerBoard, numberOfShots2, numberOfHits2);
        if ((numberOfHits == numberOfShips) | (numberOfHits2 == numberOfShips) )
        {
            allShips = true;
        }
        
    }

    std::cout << "Your board: \n\n";
    printAIBoard(playerBoard);
    std::cout << "Opponent's board: \n\n";
    printBoard(board);
    std::cout << "Number of shots: " << numberOfShots << std::endl;
    std::cout << "Number of hits: " << numberOfHits << std::endl;
    menu();



}

void makeEmptyBoard(std::vector <std::vector<char>>& board)
{
    char BLANK = NULL;


    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < N; j++) {



            board[i][j] = BLANK;


        }

    }



    makeBoard3(numberOfShips, board);


}

void makeEmptyBoard2(std::vector <std::vector<char>>& playerBoard)
{
    char BLANK = NULL;


    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < N; j++) {



            playerBoard[i][j] = BLANK;


        }

    }



    makeBoard(numberOfShips, playerBoard);


}

int randomRow()
{
    int index;
    srand(std::time(0));
    Sleep(((rand() % 2)+1) * 1000);
    index = (rand() % M);

    return index;
}

int randomColumn()
{
    int index;
    srand(std::time(0));
    Sleep(((rand() % 2)+1) * 1000);
    index = (rand() % N);

    return index;
}

void writeLetters()
{
    std::cout << " -------------\n";
    std::cout << " |A|B|C|D|E|F|\n";
}

void makeBoard(int numberOfShips, std::vector <std::vector<char>>& board)
{
    char SHIP = 'S';
    for (int i = 0; i < numberOfShips; i++)
    {
        if (board[randomRow()][randomColumn()] != SHIP)
        {
            board[randomRow()][randomColumn()] = SHIP;
        }

        else
        {
            i = i - 1;
        }
    }
}



void printBoard(std::vector <std::vector<char>>& board)
{
    std::cout << "Remaining ships:\n\n";

    for (int i = 0; i < M; i++) {



        for (int j = 0; j < N; j++) {

            if (j == 0)
            {
                std::cout << (i + 1);
                std::cout << "|";
            }

            if ((board[i][j] == 'H') | (board[i][j] == 'M') | (board[i][j] == 'S'))
            {
                std::cout << board[i][j];
            }

            else
            {
                std::cout << " ";
            }



            std::cout << "|";



        }
        std::cout << std::endl;
    }
    writeLetters();
    std::cout << std::endl;
}

void printPlayerBoard(std::vector <std::vector<char>>& board)
{
    for (int i = 0; i < M; i++) {



        for (int j = 0; j < N; j++) {

            if (j == 0)
            {
                std::cout << (i + 1);
                std::cout << "|";
            }

            if ((board[i][j] == 'H') | (board[i][j] == 'M'))
            {
                std::cout << board[i][j];
            }

            else
            {
                std::cout << " ";
            }



            std::cout << "|";



        }
        std::cout << std::endl;
    }
    writeLetters();
    std::cout << std::endl;
}

void printAIBoard(std::vector <std::vector<char>>& playerBoard)

{
    for (int i = 0; i < M; i++) {



        for (int j = 0; j < N; j++) {

            if (j == 0)
            {
                std::cout << (i + 1);
                std::cout << "|";
            }

            if ((playerBoard[i][j] == 'H') | (playerBoard[i][j] == 'M') | (playerBoard[i][j] == 'S'))
            {
                std::cout << playerBoard[i][j];
            }

            else
            {
                std::cout << " ";
            }



            std::cout << "|";



        }
        std::cout << std::endl;
    }
    writeLetters();
    std::cout << std::endl;

}

void shoot(std::vector <std::vector<char>>& board, int& numberOfShots, int& numberOfHits)
{
    std::string cell;
cell:
    std::cout << "Which cell would you like to shoot at? (Please use the format column row, example: B3))\n";
    std::cin >> cell;


    std::vector <char> coordinates(cell.begin(), cell.end());
    coordinates.at(0) = toupper(coordinates.at(0));

    int letters = (int)((coordinates.at(0)) - 65);
    int numbers= (int)((coordinates.at(1)) - 49);

    if ( (letters >= 0) && (letters <= (N-1)) && (numbers >= 0) && (numbers <= (M-1)))
    {
        if (board[numbers][letters] == 'S')
        {
            board[numbers][letters] = 'H';
            numberOfHits++;
        }

        else
        {
            board[numbers][letters] = 'M';
        }
    }
    else
    {
        std::cout << "Invalid input.\n";
        goto cell;
    }

    numberOfShots++;


   
}


void AIshoot(std::vector <std::vector<char>>& playerBoard, int& numberOfShots2, int& numberOfHits2)
{
   
cell:
    int pick;
    srand(std::time(0));
    pick = (rand() % (M));


    int pick2;
    srand(std::time(0));
    Sleep(((rand() % 2)+1) * 1000);
    pick2 = (rand() % (N));
   


    if ((playerBoard[pick][pick2] == 'M') | (playerBoard[pick][pick2] == 'H'))
    {
        goto cell;
    }

    else 
    {
        if (playerBoard[pick][pick2] == 'S')
        {
            playerBoard[pick][pick2] = 'H';
            numberOfHits2++;
        }
        else
        {
            playerBoard[pick][pick2] = 'M';
        }
    }
   
   

    numberOfShots2++;

}


void makeBoard3(int numberOfShips, std::vector <std::vector<char>>& board)
{
    char SHIP = 'S';
    for (int i = 0; i < numberOfShips; i++)
    {
        int choose;
        int number = randomRow();
        int letter= randomColumn();
        srand(std::time(0));
        Sleep(((rand() % 2) + 1) * 1000);
        choose = (rand() % 1);
        std::cout << choose;
        std::cout << number;
        std::cout << letter;


        
       
        

        if (choose == 1) {
            if (board[number][letter] != SHIP && board[(number + 1)][letter] != SHIP && board[(number + 2)][letter] != SHIP /*&& (number + 2) < M*/)
            {
                std::cout << number << letter << std::endl;
                board[number][letter] = SHIP;
                /*board[randomRow() + 1][randomColumn()] = SHIP;
                board[randomRow() + 2][randomColumn()] = SHIP;*/
            }

            /*else if (board[randomRow()][randomColumn()] != SHIP && board[randomRow() + 1][randomColumn()] != SHIP && board[randomRow() - 1][randomColumn()] != SHIP && (randomRow() + 1) <= M && (randomRow() - 1) >= 0)
            {
                board[randomRow()][randomColumn()] = SHIP;
                board[randomRow() + 1][randomColumn()] = SHIP;
                board[randomRow() - 1][randomColumn()] = SHIP;
            }

            else if (board[randomRow()][randomColumn()] != SHIP && board[randomRow() - 1][randomColumn()] != SHIP && board[randomRow() - 2][randomColumn()] != SHIP && (randomRow() - 2) >= 0)
            {
                board[randomRow()][randomColumn()] = SHIP;
                board[randomRow() -2][randomColumn()] = SHIP;
                board[randomRow() - 1][randomColumn()] = SHIP;
            }*/

            else
            {
                i = i - 1;
            }
        }

        else
        {
        //    if ((randomColumn() + 2) < N && board[randomRow()][randomColumn()] != SHIP && board[randomRow() ][randomColumn() + 1] != SHIP && board[randomRow() ][randomColumn()+2] != SHIP )
        //    {
        //        board[randomRow()][randomColumn()] = SHIP;
        //        board[randomRow() ][randomColumn()+1] = SHIP;
        //        board[randomRow() ][randomColumn()+2] = SHIP;
        //    }

       /*     else if ((randomColumn() + 1) <= N && (randomColumn() - 1) >= 0 && board[randomRow()][randomColumn()] != SHIP && board[randomRow() ][randomColumn()+1] != SHIP && board[randomRow() ][randomColumn()-1] != SHIP )
            {
                board[randomRow()][randomColumn()] = SHIP;
                board[randomRow() ][randomColumn()+1] = SHIP;
                board[randomRow() ][randomColumn() -1] = SHIP;
            }

            else if ((randomColumn() - 2) >= 0 && board[randomRow()][randomColumn()] != SHIP && board[randomRow() ][randomColumn()-1] != SHIP && board[randomRow() ][randomColumn()-2] != SHIP )
            {
                board[randomRow()][randomColumn()] = SHIP;
                board[randomRow() ][randomColumn() -1] = SHIP;
                board[randomRow() ][randomColumn() - 2] = SHIP;
            }*/

            //else
            {
                i = i - 1;
            }
        }
    }

}