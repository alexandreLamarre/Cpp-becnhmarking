#include <iostream>
#include <chrono>

int isPrime(int n){
    if( n<= 3){
        return n > 1;
    }
    if( n % 2 == 0 || n%3 == 0) {
        return false;
    }
    int i = 5;

    while(i * i <= n ){
        if( n % i == 0 || n % ( i + 2 ) == 0){
            return false;
        }
        i += 6;
    }

    return true;
}


int main(int argc, char **argv) {
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            std::cout << "Is " << argv[i] << " prime?\n";
            auto start = std::chrono::high_resolution_clock::now();
            if (isPrime( atoi(argv[i]) ) == true) {
                std::cout << "Yes";
            } else{
                std::cout << "No.";
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "(" << duration.count() << "ms) \n"; 
        }
    } else{
        std::cout << "Expected at least one argument";
    }
}