#include <stdio.h>
#include <stdbool.h>

int divisors_count(int num);

bool is_divisor(int check, int num);

void divisor_list(int *divisors_num1, int *divisors_num2, int num1, int num2);

int get_common(int divisors_num1[], int divisors_num2[], int count_num1, int count_num2, int num1, int num2);

bool argument_check(char exe_name[], int num_args);

int main(int argc, char* argv[]) {

    if (argument_check(argv[0], argc))
    {
        return 0;
    }
    else {
        int num1, num2 ;
        sscanf(argv[1], "%d", &num1);
        sscanf(argv[2], "%d", &num2);
        int count_num1 = divisors_count(num1);
        int count_num2 = divisors_count(num2);
        int divisors_num1[count_num1];
        int divisors_num2[count_num2];
        divisor_list(divisors_num1, divisors_num2, num1, num2);
        int gcd = get_common(divisors_num1, divisors_num2, count_num1, count_num2, num1, num2);
        printf("The gcd of %d and %d is %d\n", num1,num2, gcd);
    }

    return 0;
}

bool argument_check(char exe_name[], int num_args){
    if (num_args < 3) {
        printf("program launched with too few arguments.\nProper usage: %s m n\n", exe_name);
        return true;
    }
    else if (num_args > 3){
        printf("program launched with too many arguments.\nProper usage: %s m n\n", exe_name);
        return true;
    }

    return false;
}

int divisors_count(int num){
    // Method to count the number of divsors the arguement has
    int count = 0;
    for (int i = 1; i <= num ; i++){
        if (is_divisor(i, num)){
            count += 1;
        }
    }
    return count;
}

bool is_divisor(int check, int num){
    // Method to check if a number is a divsor or not
    if(num % check == 0){
        return true;
    }
    else {
        return false;
    }
}

void divisor_list(int *divisors_num1, int *divisors_num2, int num1, int num2){
    // Method that gets the list of divisors
    int list_position = 0;

    for (int i = 1; i <= num1 ; i++){
        if (is_divisor(i, num1)){
            divisors_num1[list_position] = i;
            list_position += 1;
        }
    }
    list_position = 0;
    for (int i = 1; i <= num2 ; i++){
        if (is_divisor(i, num2)){
            divisors_num2[list_position] = i;
            list_position += 1;
        }
    }

}

int get_common(int divisors_num1[], int divisors_num2[], int count_num1, int count_num2, int num1, int num2){

    if (count_num1 > count_num2) {
        int common_div[count_num2];
        int common_count = 0;

        for (int i = 0; i < count_num2; i++){
            for (int j = 0; j < count_num1; j++){
                if (divisors_num2[i] == divisors_num1[j]){
                    common_div[common_count] = divisors_num2[i];
                    common_count += 1;
                    break;
                }
            }
        }
        return common_div[common_count - 1];
    }
    else {
        int common_div[count_num2];
        int common_count = 0;

        for (int i = 0; i < count_num1; i++){
            for (int j = 0; j < count_num2; j++){
                if (divisors_num1[i] == divisors_num2[j]){
                    common_div[common_count] = divisors_num1[i];
                    common_count += 1;
                    break;
                }
            }
        }
        return common_div[common_count - 1];
    }

}
