#include <iostream>
#include <string>
#include <fstream>
#include "books.h"

using namespace std; 

int main()
{
  
  
  
  return 0;  
}




// Functions - Stephen
//The function below sorts the books by quantity;
// Largest quantity first;
void sortBooksQuantity(Book arr[], int size) {
  //sort the books by 
  int minIndex;
  int minValue;
  
  for (int start = 0; start < (size - 1); start++) {
    minIndex = start;
    minValue = arr[start].getQuantity();
    for (int index = start + 1; index < size; index++) {
      if(arr[index].getQuantity() > minValue) {
        minValue = arr[index].getQuantity();
        minIndex = index;
      }
    }
    swap(arr[minIndex], arr[start]);
  }

  cout << "AFTER: " << endl;
  listBooks(arr);

};
