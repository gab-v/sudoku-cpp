// THIS PROGRAM IS A C++ CONSOLE GAME

// NAME OF GAME: Sudoku 
// 
// WRITTEN BY: 
// Gabriel Vargas (gavargas@mymail.mapua.edu.ph)
// Bachelor of Science in Computer Engineering - Master of Science in Computer Engineering (CCPE)
// In partial fulfillment of the requirements for the course Object Oriented Programming (CPE103L)
// Mapua University
// October 19, 2022
//
// INSTRUCTOR: 
// Engr. Melissa Martin
//
// 
// Sudoku puzzles are based from the examples given in sudokuprintables.com
// Sudoku tips are based from the ideas shared in sudoku.com


#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <dos.h>
#include <stdio.h>


using namespace std;


// PUZZLE FUNCTIONS
void puzzle1();
void puzzle2();
void puzzle3();
void puzzle4();
void puzzle5();

// OTHER FUNCTIONS
void title();
void menu();
void welcome();
void play();
void mechanics();
void quit();
void delay(int a);

// GLOBAL VARIABLES
string progress;
string name;
char any;
int tips;
int puzzle;
int row, col, ans;
int start, cont, turns;
int choiceMain, choicePlay;


// MAIN 
int main()
{

    system("cls"); 

    // go to welcome
    welcome();

    // go to menu
    menu();
    
}

// MAIN MENU
void menu()
{

    system("cls");
    
    // display the title
    title();

    // display welcoming message in main menu
    cout << "WELCOME TO SUDOKU BY GAB!" << endl << endl;

    // display main menu    
    cout << "MAIN MENU" << endl << endl;

    // prompt player to choose
    cout << "[1] Play" << endl
         << "[2] Mechanics" << endl
         << "[3] Quit" << endl << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> choiceMain;

    // continue
    switch (choiceMain) {
    case 1:
        // continue to game
        play();
        break;
    case 2:
        // continue to mechanics
        mechanics();
        break;
    case 3:
        // continue to quit
        quit();
        break;
    }
}


// delay function - will be used for the "loading.." message in welcome()
void delay(int a) {
    int add = 1;
    int time;
    int i;

    time = a * 1000000;

    for (i = 0; i < time; i++) {
        add *= i;
        add++;
        add++;

    }
}


// SUDOKU TITLE
void title() {

    // display title
    cout << "     _________  ___   ___  _________   _________  ___  ___   ___   ___    " << endl;
    cout << "    /  ______/ /  /  /  / /  ___   |  /  ___   / /  /  |  | /  /  /  /    " << endl;
    cout << "   /  /_____  /  /  /  / /  /  /  /  /  /  /  / /  /__/  / /  /  /  /     " << endl;
    cout << "  /_____   / /  /  /  / /  /  /  /  /  /  /  / /  __    / /  /  /  /      " << endl;
    cout << "  _____/  / /  /__/  / /  /__/  /  /  /__/  / /  /  |  | /  /__/  /       " << endl;
    cout << "/________/ /________/ /________/  /________/ /__/  /__/ /________/        " << endl << endl;
}

// WELCOME TO SUDOKU
void welcome() {
    
    // display title
    title();
    cout << "SUDOKU BY GAB" << endl << endl;
    
    // display tips
    // randomize message 
    srand(time(0));
    for (int x = 1; x < 5 ; x++) {
        tips = 1 + (rand() % 5);
    }
  
    // five tips to be displayed
    switch (tips) {
    case 1:
        cout << "Know where to begin solving. Oftentimes, placing the" << endl;
        cout << "first number could be the hardest part." << endl << endl;
        break;
    case 2:
        cout << "Look for single candidates. Also known as naked singles," << endl;
        cout << "single candidates occur when a particular cell can only" << endl;
        cout << "have one possible candidate." << endl << endl;
        break;
    case 3:
        cout << "Don't just guess! Use the process of elimination, bro." << endl << endl;
        break;
    case 4:
        cout << "Keep moving! This game rewards the 'roving eye,' so if" << endl;
        cout << "ever you feel stuck, let your eye and  mind wander to a" << endl;
        cout << "different grid." << endl << endl;
        break;
    case 5:
        cout << "Constantly re-evaluate. Every time you place a new number" << endl;
        cout << "on the Sudoku grid, ask yourself, 'What changed? What do I" << endl;
        cout << "know now, as a result of having placed that number?'" << endl;
        break;
    }
        
    // loading... message
    cout << "Loading..." << endl << endl;

    // delay for few seconds
    delay(1000);

    // continue
    cout << "(enter any key to continue) ";
    cin >> any;
}


// PLAY GAME
void play() {

    system("cls");

    // display title
    title();

    // play game
    cout << "PLAY SUDOKU" << endl << endl;

    // prompt player to choose
    cout << "[1] Generate Random Puzzle" << endl;
    cout << "[0] Back to Main Menu" << endl << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> choicePlay;

    if (choicePlay == 0) {
        // return to main menu
        menu();
    }

    // generate puzzle
    else {

        // randomize generation
        srand(time(0));
        for (int x = 1; x < 5; x++) {
            puzzle = 1 + (rand() % 5);
        }

        // five puzzles to be generated
        switch (puzzle) {
        case 1:
            puzzle1();
            break;
        case 2:
            puzzle2();
            break;
        case 3:
            puzzle3();
            break;
        case 4:
            puzzle4();
            break;
        case 5:
            puzzle5();
            break;
        }
    }
}


// GAME RESULT
void result() {

    system("cls"); 
    
    // display title
    title();

    // display game result
    cout << "GAME RESULT" << endl << endl;
    
    if (progress == "win") { 
        
        // message if puzzle finished
        cout << "Congratulations, you successfully finished the Sudoku Puzzle. Until next time!" << endl;
    }
    else if (progress == "lost") {

        // message if puzzle not finished
        cout << "Sorry, you failed to complete the Sudoku puzzle. Better luck next time!" << endl;
    }

    // continue to main menu
    cout << "(Enter any key to continue)";
    cin >> any;

    cout << endl << endl;

    // return to main menu
    menu();
}


// GAME MECHANICS
void mechanics() {

    system("cls");
    
    // display title
    title();

    // sudoku mechanics
    cout << "SUDOKU MECHANICS" << endl << endl;
    
    cout << "Sudoku is a pen-and-paper puzzle played on a grid of 9 x 9 spaces that" << endl;
    cout << "could be played by a single player. Only this time, the player won't be" << endl;
    cout << "using either a pen or a paper." << endl << endl;

    cout << "Within the rows and columns of a Sudoku are nine squares, each composed" << endl;
    cout << "of 3 x 3 spaces. Each row, column, and square - all of which are" << endl;
    cout << "consisting of nine spaces - should be respectively filled out with" << endl;
    cout << "numbers 1 - 9 without repetition. The Sudoku grid provided comes with a" << endl;
    cout << "few spaces already filled in." << endl << endl;

    cout << "To begin answering the Sudoku puzzle, the row and column number of the box" << endl;
    cout << "the player wish to fill in must be entered. Only then will the player be" << endl;
    cout << "able to input the number he/she desires to put in the specific grid." << endl << endl;

    // return to main menu
    cout << "(Enter any key to return to Main Menu)" << endl;
    cin >> any;

    menu();
}


// QUIT GAME
void quit() {
    
    system("cls"); 
    
    // display title
    title();

    // closing message
    cout << "QUIT" << endl << endl;
    cout << "Bye bye!" << endl;
}


// SUDOKU PUZZLE 1
void puzzle1() {
    
    system("cls");

    // display title
    title();

    // display puzzle name
    cout << "PLAY SUDOKU PUZZLE 1" << endl << endl;

    // display brief instruction
    cout << "To complete the Sudoku puzzle, fill the empty boxes with numbers from 1-9!" << endl
        << "To do so, enter the row and column of the specific box you would like to fill.";

    // sudoku puzzle 1 to be answered
    char p1[9][9] = {
        {'6',' ',' ',' ','8',' ',' ','5',' '},
        {' ',' ',' ',' ','7',' ','4',' ',' '},
        {' ',' ','2',' ',' ','1','8',' ',' '},
        {'1',' ','9',' ',' ','4',' ',' ','2'},
        {' ',' ',' ',' ','6','7',' ','3',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {'8',' ',' ','9',' ',' ',' ',' ','6'},
        {'4',' ','5',' ',' ',' ','1',' ',' '},
        {' ',' ','1',' ','2',' ',' ','9',' '}
    }; 

    // sudoku puzzle 1 answer
    char a1[9][9] = {
        {'6','1','4','3','8','9','2','5','7'},
        {'5','8','3','6','7','2','4','1','9'},
        {'9','7','2','5','4','1','8','6','3'},
        {'1','3','9','8','5','4','6','7','2'},
        {'2','5','8','1','6','7','9','3','4'},
        {'7','4','6','2','9','3','5','8','1'},
        {'8','2','7','9','1','5','3','4','6'},
        {'4','9','5','7','3','6','1','2','8'},
        {'3','6','1','4','2','8','7','9','5'}
    };

    // sudoku puzzle 1 constant
    char b1[9][9];
    memcpy(b1, p1, 9 * 9 * sizeof(char));

    system("cls");

    // display title
    title();

    // display sudoku puzzle 1
    int turns = 1;
    cout << "Sudoku Puzzle 1: Turn #" << turns << endl << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p1[0][0] << " | " << p1[0][1] << " | " << p1[0][2] << " $ " << p1[0][3] << " | " << p1[0][4] << " | " << p1[0][5] << " $ " << p1[0][6] << " | " << p1[0][7] << " | " << p1[0][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[1][0] << " | " << p1[1][1] << " | " << p1[1][2] << " $ " << p1[1][3] << " | " << p1[1][4] << " | " << p1[1][5] << " $ " << p1[1][6] << " | " << p1[1][7] << " | " << p1[1][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[2][0] << " | " << p1[2][1] << " | " << p1[2][2] << " $ " << p1[2][3] << " | " << p1[2][4] << " | " << p1[2][5] << " $ " << p1[2][6] << " | " << p1[2][7] << " | " << p1[2][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p1[3][0] << " | " << p1[3][1] << " | " << p1[3][2] << " $ " << p1[3][3] << " | " << p1[3][4] << " | " << p1[3][5] << " $ " << p1[3][6] << " | " << p1[3][7] << " | " << p1[3][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[4][0] << " | " << p1[4][1] << " | " << p1[4][2] << " $ " << p1[4][3] << " | " << p1[4][4] << " | " << p1[4][5] << " $ " << p1[4][6] << " | " << p1[4][7] << " | " << p1[4][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[5][0] << " | " << p1[5][1] << " | " << p1[5][2] << " $ " << p1[5][3] << " | " << p1[5][4] << " | " << p1[5][5] << " $ " << p1[5][6] << " | " << p1[5][7] << " | " << p1[5][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p1[6][0] << " | " << p1[6][1] << " | " << p1[6][2] << " $ " << p1[6][3] << " | " << p1[6][4] << " | " << p1[6][5] << " $ " << p1[6][6] << " | " << p1[6][7] << " | " << p1[6][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[7][0] << " | " << p1[7][1] << " | " << p1[7][2] << " $ " << p1[7][3] << " | " << p1[7][4] << " | " << p1[7][5] << " $ " << p1[7][6] << " | " << p1[7][7] << " | " << p1[7][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p1[8][0] << " | " << p1[8][1] << " | " << p1[8][2] << " $ " << p1[8][3] << " | " << p1[8][4] << " | " << p1[8][5] << " $ " << p1[8][6] << " | " << p1[8][7] << " | " << p1[8][8] << " $" << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl << endl;

    // prompt player to choose
    cout << "[1] Start" << endl;
    cout << "[0] Exit" << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> cont;

    // check if valid
    while (!(cont == 0 || cont == 1)) {
        
        // enter choice again
        cout << "Enter again: ";
        cin >> cont;
    }

    // start game
    while (cont == 1) {

        turns++;
        cout << endl;

        // enter row and column
        cout << "Type in the row and column number of the box you wish to fill!" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << endl;

        // check if valid
        while (!(row >= 1 && row <= 9 && col >= 1 && col <= 9)) {
            
            // enter row and column again
            cout << "Invalid row and column! Try again." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }
            
        // check if empty
        while (b1[row - 1][col - 1] != ' ') {
            
            // enter row and column again
            cout << "This grid is not empty! Try other grids." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // enter answer
        cout << "Answer: ";
        cin >> p1[row - 1][col - 1];

        system("cls");

        // display new screen
        // display title
        title();

        // display updated sudoku puzzle 1
        cout << "Sudoku Puzzle 1: Turn #" << turns << endl << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p1[0][0] << " | " << p1[0][1] << " | " << p1[0][2] << " $ " << p1[0][3] << " | " << p1[0][4] << " | " << p1[0][5] << " $ " << p1[0][6] << " | " << p1[0][7] << " | " << p1[0][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[1][0] << " | " << p1[1][1] << " | " << p1[1][2] << " $ " << p1[1][3] << " | " << p1[1][4] << " | " << p1[1][5] << " $ " << p1[1][6] << " | " << p1[1][7] << " | " << p1[1][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[2][0] << " | " << p1[2][1] << " | " << p1[2][2] << " $ " << p1[2][3] << " | " << p1[2][4] << " | " << p1[2][5] << " $ " << p1[2][6] << " | " << p1[2][7] << " | " << p1[2][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p1[3][0] << " | " << p1[3][1] << " | " << p1[3][2] << " $ " << p1[3][3] << " | " << p1[3][4] << " | " << p1[3][5] << " $ " << p1[3][6] << " | " << p1[3][7] << " | " << p1[3][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[4][0] << " | " << p1[4][1] << " | " << p1[4][2] << " $ " << p1[4][3] << " | " << p1[4][4] << " | " << p1[4][5] << " $ " << p1[4][6] << " | " << p1[4][7] << " | " << p1[4][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[5][0] << " | " << p1[5][1] << " | " << p1[5][2] << " $ " << p1[5][3] << " | " << p1[5][4] << " | " << p1[5][5] << " $ " << p1[5][6] << " | " << p1[5][7] << " | " << p1[5][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p1[6][0] << " | " << p1[6][1] << " | " << p1[6][2] << " $ " << p1[6][3] << " | " << p1[6][4] << " | " << p1[6][5] << " $ " << p1[6][6] << " | " << p1[6][7] << " | " << p1[6][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[7][0] << " | " << p1[7][1] << " | " << p1[7][2] << " $ " << p1[7][3] << " | " << p1[7][4] << " | " << p1[7][5] << " $ " << p1[7][6] << " | " << p1[7][7] << " | " << p1[7][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p1[8][0] << " | " << p1[8][1] << " | " << p1[8][2] << " $ " << p1[8][3] << " | " << p1[8][4] << " | " << p1[8][5] << " $ " << p1[8][6] << " | " << p1[8][7] << " | " << p1[8][8] << " $" << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl << endl;

        // prompt player to choose
        cout << "[1] Continue" << endl;
        cout << "[2] Finish" << endl;
        cout << "[0] Exit" << endl;

        // enter choice
        cout << "Enter here: ";
        cin >> cont;

        // check if valid
        while (!(cont == 0 || cont == 1 || cont == 2)) {

            // enter choice again
            cout << "Enter again: ";
            cin >> cont;
        }

        // finish game
        if (cont == 2) {
            int n = memcmp(p1, a1, sizeof(p1));

            // game won
            if (n == 0) {
                progress = "win";
            }

            // game lost
            else {
                progress = "lost";
            }

            // go to result
            result();
        }
    }
}


// SUDOKU PUZZLE 2
void puzzle2() {
    
    system("cls");

    // display title
    title();

    // display puzzle name
    cout << "PLAY SUDOKU PUZZLE 2" << endl << endl;

    // display brief instruction
    cout << "To complete the Sudoku puzzle, fill the empty boxes with numbers from 1-9!" << endl
        << "To do so, enter the row and column of the specific box you would like to fill.";

    // sudoku puzzle 2 to be answered
    char p2[9][9] = {
        {'7','3',' ','4',' ',' ',' ','8','5'},
        {'8',' ','4',' ','3',' ',' ',' ','1'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ','4',' ',' ',' ','1',' ',' ','7'},
        {' ','6','9',' ',' ','7','5','2','4'},
        {'5',' ',' ','6',' ',' ','9',' ',' '},
        {' ',' ','1',' ','7',' ','4',' ','9'},
        {'3','2',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','6','8',' ',' '}
    }; 

    // sudoku puzzle 2 answer
    char a2[9][9] = {
        {'7','3','6','4','1','9','2','8','5'},
        {'8','5','4','7','3','2','6','9','1'},
        {'9','1','2','8','6','5','7','4','3'},
        {'2','4','8','5','9','1','3','6','7'},
        {'1','6','9','3','8','7','5','2','4'},
        {'5','7','3','6','2','4','9','1','8'},
        {'6','8','1','2','7','3','4','5','9'},
        {'3','2','5','9','4','8','1','7','6'},
        {'4','9','7','1','5','6','8','3','2'}
    };

    // sudoku puzzle 2 constant
    char b2[9][9];
    memcpy(b2, p2, 9 * 9 * sizeof(char));

    system("cls");

    // display title
    title();


    // display sudoku puzzle 2
    int turns = 1;
    cout << "Sudoku Puzzle 2: Turn #" << turns << endl << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p2[0][0] << " | " << p2[0][1] << " | " << p2[0][2] << " $ " << p2[0][3] << " | " << p2[0][4] << " | " << p2[0][5] << " $ " << p2[0][6] << " | " << p2[0][7] << " | " << p2[0][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[1][0] << " | " << p2[1][1] << " | " << p2[1][2] << " $ " << p2[1][3] << " | " << p2[1][4] << " | " << p2[1][5] << " $ " << p2[1][6] << " | " << p2[1][7] << " | " << p2[1][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[2][0] << " | " << p2[2][1] << " | " << p2[2][2] << " $ " << p2[2][3] << " | " << p2[2][4] << " | " << p2[2][5] << " $ " << p2[2][6] << " | " << p2[2][7] << " | " << p2[2][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p2[3][0] << " | " << p2[3][1] << " | " << p2[3][2] << " $ " << p2[3][3] << " | " << p2[3][4] << " | " << p2[3][5] << " $ " << p2[3][6] << " | " << p2[3][7] << " | " << p2[3][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[4][0] << " | " << p2[4][1] << " | " << p2[4][2] << " $ " << p2[4][3] << " | " << p2[4][4] << " | " << p2[4][5] << " $ " << p2[4][6] << " | " << p2[4][7] << " | " << p2[4][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[5][0] << " | " << p2[5][1] << " | " << p2[5][2] << " $ " << p2[5][3] << " | " << p2[5][4] << " | " << p2[5][5] << " $ " << p2[5][6] << " | " << p2[5][7] << " | " << p2[5][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p2[6][0] << " | " << p2[6][1] << " | " << p2[6][2] << " $ " << p2[6][3] << " | " << p2[6][4] << " | " << p2[6][5] << " $ " << p2[6][6] << " | " << p2[6][7] << " | " << p2[6][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[7][0] << " | " << p2[7][1] << " | " << p2[7][2] << " $ " << p2[7][3] << " | " << p2[7][4] << " | " << p2[7][5] << " $ " << p2[7][6] << " | " << p2[7][7] << " | " << p2[7][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p2[8][0] << " | " << p2[8][1] << " | " << p2[8][2] << " $ " << p2[8][3] << " | " << p2[8][4] << " | " << p2[8][5] << " $ " << p2[8][6] << " | " << p2[8][7] << " | " << p2[8][8] << " $" << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl << endl;

    // prompt player to choose
    cout << "[1] Start" << endl;
    cout << "[0] Exit" << endl;
    
    // enter choice
    cout << "Enter here: ";
    cin >> cont;

    // check if valid
    while (!(cont == 0 || cont == 1)) {
        
        // enter choice again
        cout << "Enter again: ";
        cin >> cont;
    }

    // start game
    while (cont == 1) {

        turns++;
        cout << endl;

        // enter row and column
        cout << "Type in the row and column number of the box you wish to fill!" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << endl;

        // check if valid
        while (!(row >= 1 && row <= 9 && col >= 1 && col <= 9)) {
            
            // enter row and column again
            cout << "Invalid row and column! Try again." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // check if empty
        while (b2[row - 1][col - 1] != ' ') {
            cout << "This grid is not empty! Try other grids." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // enter answer
        cout << "Answer: ";
        cin >> p2[row - 1][col - 1];

        system("cls");

        // display new screen
        // display title
        title();

        // display updated sudoku puzzle 2 
        cout << "Sudoku Puzzle 2: Turn #" << turns << endl << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p2[0][0] << " | " << p2[0][1] << " | " << p2[0][2] << " $ " << p2[0][3] << " | " << p2[0][4] << " | " << p2[0][5] << " $ " << p2[0][6] << " | " << p2[0][7] << " | " << p2[0][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[1][0] << " | " << p2[1][1] << " | " << p2[1][2] << " $ " << p2[1][3] << " | " << p2[1][4] << " | " << p2[1][5] << " $ " << p2[1][6] << " | " << p2[1][7] << " | " << p2[1][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[2][0] << " | " << p2[2][1] << " | " << p2[2][2] << " $ " << p2[2][3] << " | " << p2[2][4] << " | " << p2[2][5] << " $ " << p2[2][6] << " | " << p2[2][7] << " | " << p2[2][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p2[3][0] << " | " << p2[3][1] << " | " << p2[3][2] << " $ " << p2[3][3] << " | " << p2[3][4] << " | " << p2[3][5] << " $ " << p2[3][6] << " | " << p2[3][7] << " | " << p2[3][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[4][0] << " | " << p2[4][1] << " | " << p2[4][2] << " $ " << p2[4][3] << " | " << p2[4][4] << " | " << p2[4][5] << " $ " << p2[4][6] << " | " << p2[4][7] << " | " << p2[4][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[5][0] << " | " << p2[5][1] << " | " << p2[5][2] << " $ " << p2[5][3] << " | " << p2[5][4] << " | " << p2[5][5] << " $ " << p2[5][6] << " | " << p2[5][7] << " | " << p2[5][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p2[6][0] << " | " << p2[6][1] << " | " << p2[6][2] << " $ " << p2[6][3] << " | " << p2[6][4] << " | " << p2[6][5] << " $ " << p2[6][6] << " | " << p2[6][7] << " | " << p2[6][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[7][0] << " | " << p2[7][1] << " | " << p2[7][2] << " $ " << p2[7][3] << " | " << p2[7][4] << " | " << p2[7][5] << " $ " << p2[7][6] << " | " << p2[7][7] << " | " << p2[7][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p2[8][0] << " | " << p2[8][1] << " | " << p2[8][2] << " $ " << p2[8][3] << " | " << p2[8][4] << " | " << p2[8][5] << " $ " << p2[8][6] << " | " << p2[8][7] << " | " << p2[8][8] << " $" << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl << endl;

        // prompt player to choose
        cout << "[1] Continue" << endl;
        cout << "[2] Finish" << endl;
        cout << "[0] Exit" << endl;

        // enter choice
        cout << "Enter here: ";
        cin >> cont;

        // check if valid
        while (!(cont == 0 || cont == 1 || cont == 2)) {

            // enter choice again
            cout << "Enter again: ";
            cin >> cont;
        }

        // finish game
        if (cont == 2) {
            int n = memcmp(p2, a2, sizeof(p2));

            // game won 
            if (n == 0) {
                progress = "win";
            }

            // game lost
            else {
                progress = "lost";
            }

            // go to result
            result();
        }
    }
}


// SUDOKU PUZZLE 3
void puzzle3() {
    
    system("cls");

    // display title
    title();

    // display puzzle name
    cout << "PLAY SUDOKU PUZZLE 3" << endl << endl;

    // display brief instruction
    cout << "To complete the Sudoku puzzle, fill the empty boxes with numbers from 1-9!" << endl
        << "To do so, enter the row and column of the specific box you would like to fill.";

    // sudoku puzzle 3 to be answered
    char p3[9][9] = {
        {' ',' ',' ','6',' ','4',' ',' ',' '},
        {' ','8','2','7',' ',' ','3','1',' '},
        {'6','7','9',' ',' ',' ',' ',' ','2'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {'2',' ','7',' ',' ','3','9',' ',' '},
        {'3','4',' ',' ',' ','5',' ',' ',' '},
        {' ',' ','1',' ','9',' ','4',' ',' '},
        {' ','5',' ',' ','3','2',' ',' ',' '},
        {' ',' ','6','1',' ',' ',' ',' ','3'}
    };

    // sudoku puzzle 3 answer
    char a3[9][9] = {
        {'5','1','3','6','2','4','7','9','8'},
        {'4','8','2','7','5','9','3','1','6'},
        {'6','7','9','3','8','1','5','4','2'},
        {'1','9','5','2','7','8','6','3','4'},
        {'2','6','7','4','1','3','9','8','5'},
        {'3','4','8','9','6','5','2','7','1'},
        {'8','3','1','5','9','6','4','2','7'},
        {'7','5','4','8','3','2','1','6','9'},
        {'9','2','6','1','4','7','8','5','3'}
    };

    // sudoku puzzle 3 constant
    char b3[9][9];
    memcpy(b3, p3, 9 * 9 * sizeof(char));

    system("cls");

    // display title
    title();

    // display sudoku puzzle 1
    int turns = 1;
    cout << "Sudoku Puzzle 3: Turn #" << turns << endl << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p3[0][0] << " | " << p3[0][1] << " | " << p3[0][2] << " $ " << p3[0][3] << " | " << p3[0][4] << " | " << p3[0][5] << " $ " << p3[0][6] << " | " << p3[0][7] << " | " << p3[0][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[1][0] << " | " << p3[1][1] << " | " << p3[1][2] << " $ " << p3[1][3] << " | " << p3[1][4] << " | " << p3[1][5] << " $ " << p3[1][6] << " | " << p3[1][7] << " | " << p3[1][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[2][0] << " | " << p3[2][1] << " | " << p3[2][2] << " $ " << p3[2][3] << " | " << p3[2][4] << " | " << p3[2][5] << " $ " << p3[2][6] << " | " << p3[2][7] << " | " << p3[2][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p3[3][0] << " | " << p3[3][1] << " | " << p3[3][2] << " $ " << p3[3][3] << " | " << p3[3][4] << " | " << p3[3][5] << " $ " << p3[3][6] << " | " << p3[3][7] << " | " << p3[3][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[4][0] << " | " << p3[4][1] << " | " << p3[4][2] << " $ " << p3[4][3] << " | " << p3[4][4] << " | " << p3[4][5] << " $ " << p3[4][6] << " | " << p3[4][7] << " | " << p3[4][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[5][0] << " | " << p3[5][1] << " | " << p3[5][2] << " $ " << p3[5][3] << " | " << p3[5][4] << " | " << p3[5][5] << " $ " << p3[5][6] << " | " << p3[5][7] << " | " << p3[5][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p3[6][0] << " | " << p3[6][1] << " | " << p3[6][2] << " $ " << p3[6][3] << " | " << p3[6][4] << " | " << p3[6][5] << " $ " << p3[6][6] << " | " << p3[6][7] << " | " << p3[6][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[7][0] << " | " << p3[7][1] << " | " << p3[7][2] << " $ " << p3[7][3] << " | " << p3[7][4] << " | " << p3[7][5] << " $ " << p3[7][6] << " | " << p3[7][7] << " | " << p3[7][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p3[8][0] << " | " << p3[8][1] << " | " << p3[8][2] << " $ " << p3[8][3] << " | " << p3[8][4] << " | " << p3[8][5] << " $ " << p3[8][6] << " | " << p3[8][7] << " | " << p3[8][8] << " $" << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl << endl;

    // prompt player to choose
    cout << "[1] Start" << endl;
    cout << "[0] Exit" << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> cont;

    // check if valid
    while (!(cont == 0 || cont == 1)) {

        // enter choice again
        cout << "Enter again: ";
        cin >> cont;
    }

    // start game
    while (cont == 1) {

        turns++;
        cout << endl;

        // enter row and column
        cout << "Type in the row and column number of the box you wish to fill!" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << endl;

        // check if valid
        while (!(row >= 1 && row <= 9 && col >= 1 && col <= 9)) {
            
            // enter row and column again
            cout << "Invalid row and column! Try again." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // check if empty
        while (b3[row - 1][col - 1] != ' ') {

            // enter row and column again
            cout << "This grid is not empty! Try other grids." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // enter answer
        cout << "Answer: ";
        cin >> p3[row - 1][col - 1];
 
        system("cls");

        // display new screen
        // display title
        title();

        // display updated sudoku puzzle 3
        cout << "Sudoku Puzzle 3: Turn #" << turns << endl << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p3[0][0] << " | " << p3[0][1] << " | " << p3[0][2] << " $ " << p3[0][3] << " | " << p3[0][4] << " | " << p3[0][5] << " $ " << p3[0][6] << " | " << p3[0][7] << " | " << p3[0][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[1][0] << " | " << p3[1][1] << " | " << p3[1][2] << " $ " << p3[1][3] << " | " << p3[1][4] << " | " << p3[1][5] << " $ " << p3[1][6] << " | " << p3[1][7] << " | " << p3[1][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[2][0] << " | " << p3[2][1] << " | " << p3[2][2] << " $ " << p3[2][3] << " | " << p3[2][4] << " | " << p3[2][5] << " $ " << p3[2][6] << " | " << p3[2][7] << " | " << p3[2][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p3[3][0] << " | " << p3[3][1] << " | " << p3[3][2] << " $ " << p3[3][3] << " | " << p3[3][4] << " | " << p3[3][5] << " $ " << p3[3][6] << " | " << p3[3][7] << " | " << p3[3][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[4][0] << " | " << p3[4][1] << " | " << p3[4][2] << " $ " << p3[4][3] << " | " << p3[4][4] << " | " << p3[4][5] << " $ " << p3[4][6] << " | " << p3[4][7] << " | " << p3[4][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[5][0] << " | " << p3[5][1] << " | " << p3[5][2] << " $ " << p3[5][3] << " | " << p3[5][4] << " | " << p3[5][5] << " $ " << p3[5][6] << " | " << p3[5][7] << " | " << p3[5][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p3[6][0] << " | " << p3[6][1] << " | " << p3[6][2] << " $ " << p3[6][3] << " | " << p3[6][4] << " | " << p3[6][5] << " $ " << p3[6][6] << " | " << p3[6][7] << " | " << p3[6][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[7][0] << " | " << p3[7][1] << " | " << p3[7][2] << " $ " << p3[7][3] << " | " << p3[7][4] << " | " << p3[7][5] << " $ " << p3[7][6] << " | " << p3[7][7] << " | " << p3[7][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p3[8][0] << " | " << p3[8][1] << " | " << p3[8][2] << " $ " << p3[8][3] << " | " << p3[8][4] << " | " << p3[8][5] << " $ " << p3[8][6] << " | " << p3[8][7] << " | " << p3[8][8] << " $" << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl << endl;

        // prompt player to choose
        cout << "[1] Continue" << endl;
        cout << "[2] Finish" << endl;
        cout << "[0] Exit" << endl;

        // enter choice
        cout << "Enter here: ";
        cin >> cont;

        // check if valid
        while (!(cont == 0 || cont == 1 || cont == 2)) {

            // enter choice again
            cout << "Enter again: ";
            cin >> cont;
        }

        // finish game
        if (cont == 2) {
            int n = memcmp(p3, a3, sizeof(p3));

            // game won
            if (n == 0) {
                progress = "win";
            }

            // game lost
            else {
                progress = "lost";
            }

            // go to result
            result();
        }
    }
}


// SUDOKU PUZZLE 4
void puzzle4() {
    
    system("cls");

    // display title
    title();

    // display puzzle name
    cout << "PLAY SUDOKU PUZZLE 4" << endl << endl;

    // display brief instruction
    cout << "To complete the Sudoku puzzle, fill the empty boxes with numbers from 1-9!" << endl
        << "To do so, enter the row and column of the specific box you would like to fill.";
    
    // sudoku puzzle 4 to be answered
    char p4[9][9] = {
        {'9',' ',' ',' ',' ',' ',' ',' ','8'},
        {' ',' ','6',' ','8',' ',' ','5',' '},
        {' ','7',' ','4','1',' ',' ','9',' '},
        {'6',' ',' ',' ',' ','5','2',' ',' '},
        {' ','5','2',' ','9',' ','4',' ',' '},
        {' ',' ','1',' ',' ',' ',' ',' ',' '},
        {' ',' ','8',' ','4','9',' ',' ',' '},
        {' ',' ','4','5','6',' ',' ','2',' '},
        {' ',' ',' ','3',' ',' ','9',' ',' '}
    }; 

    // sudoku puzzle 4 answer
    char a4[9][9] = {
        {'9','2','3','7','5','6','1','4','8'},
        {'4','1','6','9','8','3','7','5','2'},
        {'8','7','5','4','1','2','3','9','6'},
        {'6','4','9','8','7','5','2','3','1'},
        {'3','5','2','6','9','1','4','8','7'},
        {'7','8','1','2','3','4','5','6','9'},
        {'2','3','8','1','4','9','6','7','5'},
        {'1','9','4','5','6','7','8','2','3'},
        {'5','6','7','3','2','8','9','1','4'}
    };

    // sudoku puzzle 4 constant
    char b4[9][9];
    memcpy(b4, p4, 9 * 9 * sizeof(char));

    system("cls");

    // display title
    title();


    // display sudoku puzzle 1
    int turns = 1;
    cout << "Sudoku Puzzle 4: Turn #" << turns << endl << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p4[0][0] << " | " << p4[0][1] << " | " << p4[0][2] << " $ " << p4[0][3] << " | " << p4[0][4] << " | " << p4[0][5] << " $ " << p4[0][6] << " | " << p4[0][7] << " | " << p4[0][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[1][0] << " | " << p4[1][1] << " | " << p4[1][2] << " $ " << p4[1][3] << " | " << p4[1][4] << " | " << p4[1][5] << " $ " << p4[1][6] << " | " << p4[1][7] << " | " << p4[1][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[2][0] << " | " << p4[2][1] << " | " << p4[2][2] << " $ " << p4[2][3] << " | " << p4[2][4] << " | " << p4[2][5] << " $ " << p4[2][6] << " | " << p4[2][7] << " | " << p4[2][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p4[3][0] << " | " << p4[3][1] << " | " << p4[3][2] << " $ " << p4[3][3] << " | " << p4[3][4] << " | " << p4[3][5] << " $ " << p4[3][6] << " | " << p4[3][7] << " | " << p4[3][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[4][0] << " | " << p4[4][1] << " | " << p4[4][2] << " $ " << p4[4][3] << " | " << p4[4][4] << " | " << p4[4][5] << " $ " << p4[4][6] << " | " << p4[4][7] << " | " << p4[4][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[5][0] << " | " << p4[5][1] << " | " << p4[5][2] << " $ " << p4[5][3] << " | " << p4[5][4] << " | " << p4[5][5] << " $ " << p4[5][6] << " | " << p4[5][7] << " | " << p4[5][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p4[6][0] << " | " << p4[6][1] << " | " << p4[6][2] << " $ " << p4[6][3] << " | " << p4[6][4] << " | " << p4[6][5] << " $ " << p4[6][6] << " | " << p4[6][7] << " | " << p4[6][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[7][0] << " | " << p4[7][1] << " | " << p4[7][2] << " $ " << p4[7][3] << " | " << p4[7][4] << " | " << p4[7][5] << " $ " << p4[7][6] << " | " << p4[7][7] << " | " << p4[7][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p4[8][0] << " | " << p4[8][1] << " | " << p4[8][2] << " $ " << p4[8][3] << " | " << p4[8][4] << " | " << p4[8][5] << " $ " << p4[8][6] << " | " << p4[8][7] << " | " << p4[8][8] << " $" << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl << endl;

    // prompt player to choose
    cout << "[1] Start" << endl;
    cout << "[0] Exit" << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> cont;

    // check if valid
    while (!(cont == 0 || cont == 1)) {

        // enter choice again
        cout << "Enter again: ";
        cin >> cont;
    }

    // start game
    while (cont == 1) {

        turns++;
        cout << endl;

        // enter row and column
        cout << "Type in the row and column number of the box you wish to fill!" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << endl;

        // check if valid
        while (!(row >= 1 && row <= 9 && col >= 1 && col <= 9)) {

            // enter row and column again
            cout << "Invalid row and column! Try again." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // check if empty
        while (b4[row - 1][col - 1] != ' ') {

            // enter row and column again
            cout << "This grid is not empty! Try other grids." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // enter answer
        cout << "Answer: ";
        cin >> p4[row - 1][col - 1];

        system("cls");

        // display new screen
        // display title
        title();

        // display updated sudoku puzzle 4
        cout << "Sudoku Puzzle 4: Turn #" << turns << endl << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p4[0][0] << " | " << p4[0][1] << " | " << p4[0][2] << " $ " << p4[0][3] << " | " << p4[0][4] << " | " << p4[0][5] << " $ " << p4[0][6] << " | " << p4[0][7] << " | " << p4[0][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[1][0] << " | " << p4[1][1] << " | " << p4[1][2] << " $ " << p4[1][3] << " | " << p4[1][4] << " | " << p4[1][5] << " $ " << p4[1][6] << " | " << p4[1][7] << " | " << p4[1][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[2][0] << " | " << p4[2][1] << " | " << p4[2][2] << " $ " << p4[2][3] << " | " << p4[2][4] << " | " << p4[2][5] << " $ " << p4[2][6] << " | " << p4[2][7] << " | " << p4[2][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p4[3][0] << " | " << p4[3][1] << " | " << p4[3][2] << " $ " << p4[3][3] << " | " << p4[3][4] << " | " << p4[3][5] << " $ " << p4[3][6] << " | " << p4[3][7] << " | " << p4[3][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[4][0] << " | " << p4[4][1] << " | " << p4[4][2] << " $ " << p4[4][3] << " | " << p4[4][4] << " | " << p4[4][5] << " $ " << p4[4][6] << " | " << p4[4][7] << " | " << p4[4][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[5][0] << " | " << p4[5][1] << " | " << p4[5][2] << " $ " << p4[5][3] << " | " << p4[5][4] << " | " << p4[5][5] << " $ " << p4[5][6] << " | " << p4[5][7] << " | " << p4[5][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p4[6][0] << " | " << p4[6][1] << " | " << p4[6][2] << " $ " << p4[6][3] << " | " << p4[6][4] << " | " << p4[6][5] << " $ " << p4[6][6] << " | " << p4[6][7] << " | " << p4[6][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[7][0] << " | " << p4[7][1] << " | " << p4[7][2] << " $ " << p4[7][3] << " | " << p4[7][4] << " | " << p4[7][5] << " $ " << p4[7][6] << " | " << p4[7][7] << " | " << p4[7][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p4[8][0] << " | " << p4[8][1] << " | " << p4[8][2] << " $ " << p4[8][3] << " | " << p4[8][4] << " | " << p4[8][5] << " $ " << p4[8][6] << " | " << p4[8][7] << " | " << p4[8][8] << " $" << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl << endl;

        // prompt player to choose
        cout << "[1] Continue" << endl;
        cout << "[2] Finish" << endl;
        cout << "[0] Exit" << endl;

        // enter choice
        cout << "Enter here: ";
        cin >> cont;

        // check if valid
        while (!(cont == 0 || cont == 1 || cont == 2)) {

            // enter choice again
            cout << "Enter again: ";
            cin >> cont;
        }

        // finsih game
        if (cont == 2) {
            int n = memcmp(p4, a4, sizeof(p4));

            // game won
            if (n == 0) {
                progress = "win";
            }

            // game lost
            else {
                progress = "lost";
            }

            // go to result
            result();
        }
    }
}


// SUDOKU PUZZLE 5
void puzzle5() {
    
    system("cls");

    // display title
    title();

    // display puzzle name
    cout << "PLAY SUDOKU PUZZLE 5" << endl << endl;

    // display brief instruction
    cout << "To complete the Sudoku puzzle, fill the empty boxes with numbers from 1-9!" << endl
        << "To do so, enter the row and column of the specific box you would like to fill.";

    // sudoku puzzle 5 to be answered
    char p5[9][9] = {
        {' ','7','8','3','1',' ',' ',' ',' '},
        {' ','4',' ',' ','2','6','5',' ',' '},
        {'6',' ',' ','9','4','7','8',' ',' '},
        {'2',' ',' ',' ',' ',' ',' ','4',' '},
        {'5',' ',' ','7',' ','1',' ',' ','2'},
        {' ','1',' ',' ',' ',' ',' ',' ','3'},
        {'4',' ','5',' ',' ',' ',' ',' ','9'},
        {' ',' ','1','4','5',' ',' ','2',' '},
        {' ',' ',' ',' ','9','2','4','7',' '}
    }; 

    // sudoku puzzle 5 answer
    char a5[9][9] = {
        {'9','7','8','3','1','5','2','6','4'},
        {'1','4','3','8','2','6','5','9','7'},
        {'6','5','2','9','4','7','8','3','1'},
        {'2','3','7','5','8','9','1','4','6'},
        {'5','6','4','7','3','1','9','8','2'},
        {'8','1','9','2','6','4','7','5','3'},
        {'4','2','5','6','7','8','3','1','9'},
        {'7','9','1','4','5','3','6','2','8'},
        {'3','8','6','1','9','2','4','7','5'}
    };

    // sudoku puzzle 1 constant
    char b5[9][9];
    memcpy(b5, p5, 9 * 9 * sizeof(char));

    system("cls");

    // display title
    title();

    // display sudoku puzzle 5
    int turns = 1;
    cout << "Sudoku Puzzle 5: Turn #" << turns << endl << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p5[0][0] << " | " << p5[0][1] << " | " << p5[0][2] << " $ " << p5[0][3] << " | " << p5[0][4] << " | " << p5[0][5] << " $ " << p5[0][6] << " | " << p5[0][7] << " | " << p5[0][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[1][0] << " | " << p5[1][1] << " | " << p5[1][2] << " $ " << p5[1][3] << " | " << p5[1][4] << " | " << p5[1][5] << " $ " << p5[1][6] << " | " << p5[1][7] << " | " << p5[1][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[2][0] << " | " << p5[2][1] << " | " << p5[2][2] << " $ " << p5[2][3] << " | " << p5[2][4] << " | " << p5[2][5] << " $ " << p5[2][6] << " | " << p5[2][7] << " | " << p5[2][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p5[3][0] << " | " << p5[3][1] << " | " << p5[3][2] << " $ " << p5[3][3] << " | " << p5[3][4] << " | " << p5[3][5] << " $ " << p5[3][6] << " | " << p5[3][7] << " | " << p5[3][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[4][0] << " | " << p5[4][1] << " | " << p5[4][2] << " $ " << p5[4][3] << " | " << p5[4][4] << " | " << p5[4][5] << " $ " << p5[4][6] << " | " << p5[4][7] << " | " << p5[4][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[5][0] << " | " << p5[5][1] << " | " << p5[5][2] << " $ " << p5[5][3] << " | " << p5[5][4] << " | " << p5[5][5] << " $ " << p5[5][6] << " | " << p5[5][7] << " | " << p5[5][8] << " $" << endl;

    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl;
    cout << "$ " << p5[6][0] << " | " << p5[6][1] << " | " << p5[6][2] << " $ " << p5[6][3] << " | " << p5[6][4] << " | " << p5[6][5] << " $ " << p5[6][6] << " | " << p5[6][7] << " | " << p5[6][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[7][0] << " | " << p5[7][1] << " | " << p5[7][2] << " $ " << p5[7][3] << " | " << p5[7][4] << " | " << p5[7][5] << " $ " << p5[7][6] << " | " << p5[7][7] << " | " << p5[7][8] << " $" << endl;
    cout << "$---*---*---$---*---*---$---*---*---$" << endl;
    cout << "$ " << p5[8][0] << " | " << p5[8][1] << " | " << p5[8][2] << " $ " << p5[8][3] << " | " << p5[8][4] << " | " << p5[8][5] << " $ " << p5[8][6] << " | " << p5[8][7] << " | " << p5[8][8] << " $" << endl;
    for (int i = 0; i <= 36; i++) { cout << "$"; };
    cout << endl << endl;

    // prompt pkayer to choose
    cout << "[1] Start" << endl;
    cout << "[0] Exit" << endl;

    // enter choice
    cout << "Enter here: ";
    cin >> cont;

    // check if valid
    while (!(cont == 0 || cont == 1)) {

        // enter choice again
        cout << "Enter again: ";
        cin >> cont;
    }

    // check if valid
    while (cont == 1) {

        turns++;
        cout << endl;

        // enter row and column
        cout << "Type in the row and column number of the box you wish to fill!" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << endl;

        // check if valid
        while (!(row >= 1 && row <= 9 && col >= 1 && col <= 9)) {

            // enter row and column again
            cout << "Invalid row and column! Try again." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // check if empty
        while (b5[row - 1][col - 1] != ' ') {

            // enter row and column again
            cout << "This grid is not empty! Try other grids." << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << endl;
        }

        // enter answer
        cout << "Answer: ";
        cin >> p5[row - 1][col - 1];
  
        system("cls");

        // display new screen
        // display title
        title();

        // display updated sudoku puzzle 5
        cout << "Sudoku Puzzle 5: Turn #" << turns << endl << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p5[0][0] << " | " << p5[0][1] << " | " << p5[0][2] << " $ " << p5[0][3] << " | " << p5[0][4] << " | " << p5[0][5] << " $ " << p5[0][6] << " | " << p5[0][7] << " | " << p5[0][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[1][0] << " | " << p5[1][1] << " | " << p5[1][2] << " $ " << p5[1][3] << " | " << p5[1][4] << " | " << p5[1][5] << " $ " << p5[1][6] << " | " << p5[1][7] << " | " << p5[1][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[2][0] << " | " << p5[2][1] << " | " << p5[2][2] << " $ " << p5[2][3] << " | " << p5[2][4] << " | " << p5[2][5] << " $ " << p5[2][6] << " | " << p5[2][7] << " | " << p5[2][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p5[3][0] << " | " << p5[3][1] << " | " << p5[3][2] << " $ " << p5[3][3] << " | " << p5[3][4] << " | " << p5[3][5] << " $ " << p5[3][6] << " | " << p5[3][7] << " | " << p5[3][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[4][0] << " | " << p5[4][1] << " | " << p5[4][2] << " $ " << p5[4][3] << " | " << p5[4][4] << " | " << p5[4][5] << " $ " << p5[4][6] << " | " << p5[4][7] << " | " << p5[4][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[5][0] << " | " << p5[5][1] << " | " << p5[5][2] << " $ " << p5[5][3] << " | " << p5[5][4] << " | " << p5[5][5] << " $ " << p5[5][6] << " | " << p5[5][7] << " | " << p5[5][8] << " $" << endl;

        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl;
        cout << "$ " << p5[6][0] << " | " << p5[6][1] << " | " << p5[6][2] << " $ " << p5[6][3] << " | " << p5[6][4] << " | " << p5[6][5] << " $ " << p5[6][6] << " | " << p5[6][7] << " | " << p5[6][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[7][0] << " | " << p5[7][1] << " | " << p5[7][2] << " $ " << p5[7][3] << " | " << p5[7][4] << " | " << p5[7][5] << " $ " << p5[7][6] << " | " << p5[7][7] << " | " << p5[7][8] << " $" << endl;
        cout << "$---*---*---$---*---*---$---*---*---$" << endl;
        cout << "$ " << p5[8][0] << " | " << p5[8][1] << " | " << p5[8][2] << " $ " << p5[8][3] << " | " << p5[8][4] << " | " << p5[8][5] << " $ " << p5[8][6] << " | " << p5[8][7] << " | " << p5[8][8] << " $" << endl;
        for (int i = 0; i <= 36; i++) { cout << "$"; };
        cout << endl << endl;

        // prompt player to choose
        cout << "[1] Continue" << endl;
        cout << "[2] Finish" << endl;
        cout << "[0] Exit" << endl;

        // enter choice
        cout << "Enter here: ";
        cin >> cont; 

        // check if valid
        while (!(cont == 0 || cont == 1 || cont == 2)) {
            cout << "Enter again: ";
            cin >> cont;
        }

        // finish game
        if (cont == 2) {
            int n = memcmp(p5, a5, sizeof(p5));

            // game won
            if (n == 0) {
                progress = "win";
            }

            // game lost
            else {
                progress = "lost";
            }

            // go to result
            result();
        }
    }
}

    





