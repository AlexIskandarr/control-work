#include <iostream>
#include <cstring>

int32_t partitionHoare(int32_t*, int32_t, int32_t);
void quicksortHoare(int32_t*, int32_t, int32_t);
int32_t countSum(int32_t*, int32_t);


int main(){
    int32_t size{};
    std::cout << "enter max size of strings: \n";
    std::cin >> size;
    std::cin.ignore();

    char** mix_mtr = new char* [size];
    for (int32_t i{}; i < size ; ++i){
        mix_mtr[i] = new char[300];
        std::cout << "enter string number " << i + 1 << '\n';
        std::cin.getline(mix_mtr[i], 300);
    }

    /* find num*/
    int32_t* numbers = new int32_t[size];
    for(int32_t i{}; i < size ; ++i){
        char* space_ptr = strchr(mix_mtr[i], ' ');
        char* num_ptr = space_ptr + 1;
        numbers[i] = atoi(num_ptr);
    }

    for(int32_t i {}; i < size ; ++i){
        std::cout << mix_mtr[i] << '\n';
    }

    quicksortHoare(numbers, 0, size - 1);
    std::cout << "numbers after using quicksort: \n";
      for(int32_t i {}; i < size ; ++i){
        std::cout << numbers[i] << '\n';
    }


    std::cout << "sum of numbers is: \t" << countSum(numbers, size) << '\n';

    std::cout << "max num is: \t" << numbers[size - 1] << '\n'; 
    std::cout << "min num is: \t" << numbers[0]; 

    for(int32_t i{}; i < size ; ++i){
        delete[] mix_mtr[i];
    }
    delete[] mix_mtr;

    return 0;
}

int32_t partitionHoare(int32_t* numbers, int32_t low, int32_t high){
    int32_t pivot = numbers[low + (high - low) / 2];
    int32_t i = low - 1;
    int32_t j = high + 1;

    while(true){

        do {
            ++i;
        } while (numbers[i] < pivot);

        do {
            --j;
        }while(numbers[j] > pivot);

        if ( i >= j){
            return j;
        }

        std::swap(numbers[i], numbers[j]);
    }
}

void quicksortHoare(int32_t* numbers, int32_t low, int32_t high){
    if (low < high){
        int32_t piv = partitionHoare(numbers, low, high);
        quicksortHoare(numbers, low, piv);
        quicksortHoare(numbers, piv + 1, high);
    }
}

int32_t countSum(int32_t* numbers, int32_t size){
    int32_t sum {};
    for(int32_t i{}; i < size; ++i){
        sum += numbers[i];
    }
    return sum;
}
