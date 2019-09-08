#include <iostream>
#include "std_lib_facilities.h"

vector<int> nums; //vector for user's guesses
vector<int> key; //the 4 digit code
int track=0; //this variable helps handling various trackings in the while loop and increases by 1 each time that the user enters a number
int bull=0;
int cow=0;
int const guess=4; //each try user guess 4 digits

//this function adds numbers 1 to 9 to key vector then shuffles them
//only the first 4 elements of the key vector will be used in this program
//this function will generate non-repeating random numbers between 1 to 9
int rand_geneator(int y){
    srand(y);
    for(int i=0; i<9; ++i){
        key.push_back(i+1);
    }
    random_shuffle(key.begin(),key.end());
}

//this function takes input from the user and check them
//user can only enter 4 digits in each try
//each single digit cannot be larger than 9
//each digit entered has to be unique and cannot be repeated in each try
int input_check(int x){
    for(int i=0; i<nums.size(); ++i){
            if(track>0 && x==nums[i]){error("Same numbers are not allowed\n");}
    }
        if(x>9){error("Number larger than 9");}
        nums.push_back(x);
}

//this function checks how many guess the user got right
void check_bullcow(){
    if(nums[track]==key[track]){ //track is 0 after the very first input is entered in each try, check every user's input individually
            bull +=1;
    }
        for(int i=0; i<guess; ++i){
            if(nums[track]==key[i] && nums[track]!=key[track]){ //compare each input individually with the 4 digit answer
                cow +=1;
            }
        }
}

//this function will be activated once the user got all 4 guesses right
int win_game(int x){
    if(x==guess){
    std::cout<<"You got it right!!!\n";
        return 0;
    }
}

// this function is activated after the user has entered 4 digits
// this function display how many guess the user got right
void end_guess(){
   if(track==guess && bull!=guess){
        std::cout<<"Bull: "<<bull<<"   Cow: "<<cow<<'\n';
        nums.erase (nums.begin(),nums.end()+0); //erase the user's guesses at the end of each try to replace with new guesses
        std::cout<<"Try again....\n";
        bull=0;
        cow=0;
        track=0;
        // set variables to 0 again for the new try
    }
}

int main()
try{
    std::cout<<"Please enter a number: ";
    int n=0;
    std::cin>>n;
    rand_geneator(n);
    std::cout<<"Enter 4 digits, press Enter after each digit.\n";
    int inputs;
    while(nums.size()<guess && std::cin>>inputs){
        input_check(inputs);
        check_bullcow();
        ++track;
        win_game(bull);
        end_guess();
    }
    if(nums.size()>guess){error("only 4 guess");}
}
catch(exception& e){
    cerr<<"error: "<<e.what();
}
