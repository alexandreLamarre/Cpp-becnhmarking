#include <iostream>
#include <vector>
#include <chrono>

int checkPrimes(int curNum, std::vector<int> primes){
    for(int i = 0; i < primes.size(); i++){
         if(curNum % primes[i] == 0) return false;
         if(primes[i]*primes[i] > curNum) return true;
    }
    return true;
}

std::vector<int> generatePrimes(int num){

    std::vector<int> res(num);
    int curNum = 2;
    while(res.size() < num){
        if(curNum < 4){
            if(checkPrimes(curNum, res) == true){
                res.push_back(curNum);
            }
            curNum ++;
            if( curNum == 4) curNum = 6;
        } else{
            int isPrime = checkPrimes(curNum - 1, res);
            if(isPrime == true) res.push_back(curNum -1);
            isPrime = checkPrimes(curNum + 1, res);
            if(isPrime == true) res.push_back(curNum + 1);
            curNum += 6;
        }
    }
    return res;
}


int main(int argc, char **argv){
    if(argc > 1){
        int number_of_primes = atoi(argv[1]);
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> primes = generatePrimes(number_of_primes);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        int row_count = 20;
        int curCount = 0;
        // for(auto prime: primes){
        //     std::cout << prime << " ";
        //     curCount ++;
        //     if(curCount == 20){
        //         std::cout << "\n";
        //     }
        //     curCount = curCount % 20;
        // }
        std::cout << "\nGenerated " << primes.size() << " primes in " << duration.count() << " micro seconds.\n";
    } else{
        std::cout << "Expected at least one argument as input";
    }
}