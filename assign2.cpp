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

void PopulateMatrix(int);   //  Will populate a 2D vector array 
                            //  of size NxN

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
//                        and creates a 2D vector array matrix
//
//  n : user given dimensions for matrix
//*****************************************************************************

void PopulateMatrix(int n) 
{
    vector< vector<int> > matrix (n, vector<int> (n, 0)); // Creating matrix
    vector<int> sumRows (n, 0);
    vector<int> sumColumns (n, 0);
    int sumDiagOne = 0;
    int sumDiagTwo = 0;
    int randNum;
    bool distinct;

    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            do
            {
                distinct = true;
                randNum = rand() % ((n * n) + 1);
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
            matrix[j][i] = randNum;
            sumColumns[j] += randNum;
            sumRows[i] += randNum;
            if(i == j)
                sumDiagOne += matrix[j][i];
            if(i+j == (n-1))
                sumDiagTwo += matrix[j][i];
            cout << setw(4) << right << matrix[j][i] << "     ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
        cout << "Column " << i+1 << ": " << sumColumns[i] << endl;
    
    cout << endl;

    for(int i=0; i<n; i++)
        cout << "Row " << i+1 << ": " << sumRows[i] << endl;

    cout << "\nDiagonal one: " << sumDiagOne << endl;
    cout << "Diagonal two: " << sumDiagTwo << endl;


}
