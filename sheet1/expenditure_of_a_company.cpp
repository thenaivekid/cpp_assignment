// Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified.
//  Use arrays to construct a table, display the table of expenditure and find the sum and average.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int take_data(vector < vector < int > > &matrix, int rows, int columns, int first_year){
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            cout << "Enter data of year " << first_year << " month " << column+1 << " : ";
            int x;
            cin >> matrix[row][column];
        }
        first_year++;
    }
    return 0;
}

void print_table(vector < vector < int > > &matrix, int first_year){
    int month = 1;
    for (const auto &row: matrix){
        for (const auto &element: row){
            cout << "Expenditure of " << month << " of year " << first_year << ": " << element << endl;
            month++;
        }
        first_year++;
    }
}

void print_table_csv(const std::vector<std::vector<int>>& matrix, int first_year, const std::string& filename) {
    std::fstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    int month = 1;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            file << element << ", ";
            month++;
        }
        file << endl;
        first_year++;
    }

    file.close();

    std::cout << "Expenditure table written to file: " << filename << std::endl;
}

double sum(vector< vector < int > > &matrix){
    double sum = 0;
    for(const auto &row: matrix){
        for(const auto &element: row){
            sum += element;
        }
    }
    return sum;
}

double mean(vector < vector < int > > &matrix, int num_data){
    return sum(matrix)/num_data;
}

int main(){
    int from, to;
    
    cout << "Enter the range of years" << endl;
    cout << "From: ";
    cin >> from;
    cout << "To: ";
    cin >> to;
    int num_years = to - from;

    vector < vector < int > > matrix(num_years, vector <int> (12));
    int input = take_data(matrix, num_years, 12, from);
    if (input != 0){
        cout << "Error taking input";
        return 1;
    }

    int sum_ = sum(matrix);
    int mean_ = mean(matrix, num_years*12);

    print_table(matrix, from);
    cout << "sum: " << sum_ << endl;
    cout << "mean: " << mean_ << endl;

    cout << "Do you want to save data? (y/n) ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y'){
        print_table_csv(matrix, from, to_string(from) + "_to_" + to_string(to) + ".csv");
    }
    return 0;
}