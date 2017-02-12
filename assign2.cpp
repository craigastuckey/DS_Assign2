//******************************************************************************
//  Authors: Craig Stuckey - 41, DeVante Walls
//  Due Date: 2/13/17
//  Programming Assignment #: 2
//  Spring 2017 - CS 3358 - Section 3
//
//  Instructor: Husain Gholoom 
//
//  This program promopts the user to enter an integer, n, greater than or equal
//  to zero and then creates an n x n matrix with distinct random numbers and 
//  then adds the rows, columns, and diagonals to see if the generated matrix
//  is perfect.
//******************************************************************************

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

void PopulateMatrix(int);   

using namespace std;

//******************************************************************************
//  main: prints user prompt asking for an integer >= 2, calls matrix function
//        to populate matrix with user given dimensions, asks user if they 
//        would like to run the program again.
//
//  returns 0
//******************************************************************************

int main() 
{
    int dimension;    //  user given dimensions for matrix
    bool verify = false;    //  for user input verification
    char choice; // stores user's choice for repeating program

        // Program Header
    cout << endl << "Welcome to my perfect matrix program.";
    cout << " The function of the program is to:" << endl << endl;
    cout << setw(6) << right << "1. ";
    cout << "Allow the user to enter the size of the perfect matrix, ";
    cout << "such as N. N>=2" << endl;
    cout << setw(6) << right << "2. ";     
    cout << "Create a 2 D vector array of size N x N." << endl;
    cout << setw(6) << right << "3. ";
    cout << "Populate the 2 D vector array with distinct random numbers.";
    cout << endl << setw(6) << right << "4. ";
    cout << "Display the sum of each row, column, and diagonal then ";
    cout << "determine whether" << endl << "      the numbers in N x N";
    cout << "vector array are perfect matrix numbers." << endl << endl << endl;

    do  // User interface
    {
        cout << "Enter the size of the matrix : ";  
 
        do    // Verifying if user input is valid 
        {
            cin >> dimension;
            cin.clear();
            cin.ignore(120, '\n');
            cout << endl;             
            if(cin.fail())
                cout << "Input must be an integer greater than or equal to 2: ";
            else if(dimension < 2)
                cout << "Please enter an integer greater than or equal to 2: ";
            else
                verify = true;
        }
        while(!verify);

        PopulateMatrix(dimension);

        verify = false;   // Returning verify to false for later use

        do    // Verifying if user input is valid
        {
            cout << "Would you like to find another perfect matrix? - ";
            cout << "Enter y or Y for yes or n or N for no: ";
            cin >> choice;
            cout << endl;
            if(choice == 'y' || choice == 'Y')
                verify = true;
            else if(choice == 'n' || choice == 'N')
                verify = true;      
            else
                cout << "Error *** Invalid choice - Must enter y|Y or n|N";
            cout << endl << endl;
        }
        while(!verify);
    }
    while(choice == 'y' || choice == 'Y');    // Repeats if user enters "y|Y"

        //  Ending credit
    cout << "This perfect matrix algorithm is implemented by Craig Stuckey";
    cout << " and DeVante Walls" << endl;
    cout << "February 5th - 2017" << endl << endl;     
    return 0;
}

//*****************************************************************************
//  PopulateMatrix(int n) : This function takes the dimensions given by the user
//                          and creates a 2D vector array matrix
//
//  n : user given dimensions for matrix
//*****************************************************************************

void PopulateMatrix(int n) 
{
    vector< vector<int> > matrix (n, vector<int> (n, 0)); // Creating matrix
    int sumRow = 0;       //  Stores the sum of a row in the matrix
    int sumColumn = 0;    //  Stores the sum of a column in the matri
    int sumDiagOne = 0;   //  Stores the sum of the first diagonal in the matrix
    int sumDiagTwo = 0;   //  Stores the sum of the 2nd diagonal in the matrix
    int totalSum = 0;     //  Stores the sum of all numbers in the matrix
    int randNum;          //  Stores a randomly genterated integer
    bool distinct;        //  Used to determine if ranNum is distinct
    bool perfect = false; //  Used to determine if the matris is perfect

    srand(time(NULL));    //  Initializing pseudo-random number generator

    cout << "The perfect matrix that is created for size " << n << " :\n\n";

    for(int i=0; i<n; i++)      //  This block of loops populates the matrix of
    {                           //  size NxN with distinct random numbers and 
        for(int j=0; j<n; j++)  //  displays it. It also takes the sum of the 
        {                       //  numbers in the first and second diagonal as
            do                  //  well as the total sum of numbers in the 
            {                   //  matrix.
                distinct = true;
                randNum = rand() % (n * n) + 1;
                for(int k=0; k<n; k++)
                {
                    for(int l=0; l<n; l++)
                    {
                        if(matrix[l][k] == randNum)
                        {
                            distinct = false;
                            break;
                        }
                    }
                    if(!distinct)
                        break;
                }
            } 
            while(!distinct);
            totalSum += randNum;
            matrix[j][i] = randNum;
            if(i == j)
                sumDiagOne += matrix[j][i];
            if(i+j == (n-1))
                sumDiagTwo += matrix[j][i];
            cout << setw(4) << right << matrix[j][i] << "     ";
        }
        cout << endl << endl << endl;
    }

    cout << endl;

    //  Displaying the matrix perfect number
    cout << "The perfect number is : " << totalSum / 3 << endl << endl;

    //  Displaying the sum of each row in the matrix
    for(int i=0; i<n; i++)
    {
        cout << "Sum of numbers in row\t\t#";
        cout << setw(3) << right << i+1;
        cout << setw(6) << right << "=";
        for(int j=0; j<n; j++)
            sumRow += matrix[j][i];
        cout << setw(6) << right << sumRow << endl;
        sumRow = 0;
    }

    cout << endl;

    //  Displaying the sum of each column in the matrix
    for(int i=0; i<n; i++)
    {
        cout << "Sum of numbers in column\t#";
        cout << setw(3) << right << i+1;
        cout << setw(6) << right << "=";
        for(int j=0; j<n; j++)
            sumColumn += matrix[i][j];
        cout << setw(6) << right << sumColumn << endl;
        sumColumn = 0;
    }

    //  Displaying the sum of both diagonals in the matrix
    cout << "\nSum of numbers in first diagonal\t " << "=";
    cout << setw(6) << right << sumDiagOne << endl;
    cout << "Sum of numbers in second diagonal\t " << "=";
    cout << setw(6) << right << sumDiagTwo << endl << endl;

    if(sumDiagOne == totalSum / 3)
    {
        if(sumDiagTwo == totalSum / 3)
        {
            if(sumRow == totalSum / 3)
            {
                if(sumColumn == totalSum / 3)
                    perfect = true;
            }
        }
    }

    //  Displaying whether or not the generated matrix is perfect.
    cout << "The above " << (perfect ? "is " : "is not ") << "a perfect matrix";
    cout << endl << endl;
}
