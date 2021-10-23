#include<iostream>
using namespace std;

bool search(char name[], char search_str[]){
    return searchHelper(name,0, search_str);
}

bool searchHelper(char name[], int idx, char search_str[]){
    if(startsWith(name, idx, search_str, 0)){
        return true;
    }
    return searchHelper(name, idx+1, search_str);
}

bool startsWith(char name[], int nameIdx, char search[], int searchIdx){
    if(name[nameIdx] == '\0' || search[searchIdx] =='\0'){ //~(A.B)=~A v ~B ~(AvB) = ~A.~B
        if(search[searchIdx]=='\0'){
            return true;
        }
        return false;
    }
    if(name[nameIdx]==search[searchIdx]){
        return startsWith(name, nameIdx+1, search, searchIdx+1);
    }
    return false;
}