#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

int main()
{
    int num = rand()%100 ;
    for(int i = 0; i <10; i++){
        cout<<"please input a number(0-100): "<<endl;
        int number;
        cin>>number;
        if(number > num){
            cout<<"your guess is too big! please guess again ."<<endl;
        }
        else if(number < num){
            cout<<"your guess is too small! please guess again."<<endl;
        }
        else if (number == num) {
            cout<<"success! your guess is right!"<<endl;
            break;
        }
    }
    return 0;
}
