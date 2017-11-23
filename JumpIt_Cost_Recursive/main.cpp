//
//  main.cpp
//  JumpIt_Cost_Recursive
//
//There is absolutely no warranty whatsoever in any shape or form.


#include <iostream>
using namespace std;

int costOfJump(int arr[], int ind, int last);

int main(){
    int arrSize = 6;
    int last = arrSize-1;   //index of the last element
    int ind = 0;
    int gameBoard[6] = {0,3,80,6,5,10};

    int cost = costOfJump(gameBoard, ind, last);

    cout << "The cost is: " << cost << endl;
    cout << "The cost should be 19." << endl;


    return 0;
}

int costOfJump(int arr[], int ind, int last){
    if(ind==last){          //base case where the array is a single element
        return arr[ind];
    }
    else if(ind+1 == last){ //base case where the array has 2 elements
        return arr[ind]+costOfJump(arr, ind+1, last);   //will go back to first base case which will return the second element
    }
    else if(ind+2 == last){ //base case where the array has 3 elements
        return arr[ind]+costOfJump(arr, ind+2, last);   //will go back to the first base case which will return the last element
    }
    else{
        if(costOfJump(arr, ind+1, last) <= costOfJump(arr, ind+2, last)){   //down the rabbit hole :)
            return arr[ind]+costOfJump(arr, ind+1, last);
        }
        else{
            return arr[ind]+costOfJump(arr, ind+2, last);
        }
    }
}

