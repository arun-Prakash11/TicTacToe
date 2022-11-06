#include <iostream>
#include <string>
#include <conio.h>

char xo[2] = {'X', 'O'};
bool xoAss = true;
char list[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int intlist[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
bool quit = false;

class player
{
public:
    int Score;
    char Char;
    int Num;
    std::string PlayerName;

    player(std::string Name)
    {
        Score = 0;
        PlayerName = Name;
        if (xoAss)
        {
            Char = xo[0];
            xoAss = false;
        }
        else
        {
            Char = xo[1];
            xoAss = true;
        }

        if (Char == 'X')
            Num = 300;
        else
            Num = 3;
    }

    player() {}

    int GetInput()
    {
        bool temp = true;
        int position;
        while (temp)
        {
            std::cout << "\nEnter Position " << PlayerName << ":";
            std::cin >> position;
            if (position < 1 || position >= 9)
                std::cout << "Enter Proper Position Idiot.\n";
            else
                temp = false;
            if (!(intlist[position - 1]))
                temp = false;
            else
            {
                temp = true;
                std::cout << "Position alredy filled, Try again.\n";
            }
        }
        return position;
    }
};

class tictactoe : private player
{
public:
    int whoWon;

/* 
0 1 2
3 4 5 
6 7 8
 */
    int WinCheck() {
        /* Horizontal Check */
        for(int j=0; j<9; j+=3){
            int Count = 0;
            for (int i=j; i<j+3; i++) {
                Count  += intlist[i];
            }
            if (Count == 900) return 1;
            else if (Count == 9) return 2;
        }

        /* Vertical Check */
        for(int j=0; j<3; j++){
            int Count = 0;
            for (int i=j; i < j+7; i+=3) {
                Count += intlist[i];
            }
            if (Count == 900) return 1;
            else if (Count == 9) return 2;
        }

        /* Diagonal Check */
        int Count = 0;
        for(int j=0; j<9; j+=4){
            Count += intlist[j];
            if (Count == 900) return 1;
            else if (Count == 9) return 2;
        }

        Count = 0;
        for(int j=6; j>=0; j-=2){
            Count += intlist[j];
            if (Count == 900) return 1;
            else if (Count == 9) return 2;
        }

        return 0;
    }

    void updateBoard() {
        system("clear");
        std::cout << "\nWelcome to TicTacToe By Nurasquare.\n\n";
        printBoard();
    }

    void play(std::string playerOne, std::string playerTwo)
    {
        player playersOne(playerOne), playersTwo(playerTwo);
        int Input;
        updateBoard();
        int i;
        for (i = 1; i <= 9; i++)
        {
            if (!(i % 2 == 0))
            {
                Input = playersOne.GetInput();
                list[Input-1] = playersOne.Char;
                intlist[Input-1] = playersOne.Num;
            }
            else
            {
                Input = playersTwo.GetInput();
                list[Input-1] = playersTwo.Char;
                intlist[Input-1] = playersTwo.Num;
            }
            updateBoard();
            whoWon = WinCheck();
            if(whoWon != 0){
                if(whoWon == 1){
                    std::cout << playersOne.PlayerName << " Won! in the Match.\n";
                } else{
                    std::cout << playersTwo.PlayerName << " Won! in the Match.\n";
                }
                break;
            }
        }
        if(i==9) std::cout<<"Match is a Draw Between " << playersOne.PlayerName << " and" << playersTwo.PlayerName << "." << std::endl; 
    }

    void printBoard()
    {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "|    " << list[0] << "    |    " << list[1] << "    |    " << list[2] << "    |" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "|-----------------------------|" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "|    " << list[3] << "    |    " << list[4] << "    |    " << list[5] << "    |" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "|-----------------------------|" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "|    " << list[6] << "    |    " << list[7] << "    |    " << list[8] << "    |" << std::endl;
        std::cout << "|         |         |         |" << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
};

int main(int argc, char **argv)
{
    tictactoe board;
    board.printBoard();
    board.play("Arun", "Prakash");  /* (player 1, player 2) */ 
    _getch();
    return 0;
}