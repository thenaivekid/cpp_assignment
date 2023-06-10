// Write a program to find the position of the character 'C' in the sentence "idea without execution is worthless" using pointer and string.
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main(){
    char *sentence = "idea without execution is worthless";

for (int i = 0; i< strlen(sentence); i++){
    if(*(sentence+i) == 'c'){
        cout << i << endl;
        break;
    }
}
    return 0;
}