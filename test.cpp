#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
    int x = 10;
    int pid;
    
    if((pid = fork())!=0){
        x++;
    

    }else{
        x--;
    }
    cout << x << endl;
}
