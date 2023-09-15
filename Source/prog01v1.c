#include <stdio.h>
#include <stdbool.h>

int divisors_count(int num);

bool is_divisor(int check, int num);

void divisors(int count, int num);

void print_divisors(int divisor_list[], int count);

bool argument_check(char exe_name[], int num_args);

int main(int argc, char* argv[]) {

    if (argument_check(argv[0], argc))
    {
        return 0;
    }
    else {
        int num;
        sscanf(argv[1], "%d", &num);
        int count = divisors_count(num);
        divisors(count, num);
    }

    return 0;
}

int divisors_count(int num){

    int count = 0;
    for (int i = 1; i <= num ; i++){
        if (is_divisor(i, num)){
            count += 1;
        }
    }
    return count;
}

bool is_divisor(int check, int num){

    if(num % check == 0){
        return true;
    }
    else {
        return false;
    }
}

void divisors(int count, int num){

    int divisor_list[count];
    int list_position = 0;
    for (int i = 1; i <= num ; i++){
        if (is_divisor(i, num)){
            divisor_list[list_position] = i;
            list_position += 1;
        }
    }
    print_divisors(divisor_list, count);
}

void print_divisors(int divisor_list[], int count){

    printf("The list of divisors are ");
    for(int i = 0; i < count; i++){
        if (i == (count - 1)){
            printf("%d. ", divisor_list[i]);
        }
        else {
            printf("%d, ", divisor_list[i]);
        }
    }
    printf("\n");
}

bool argument_check(char exe_name[], int num_args){
    if (num_args == 1) {
        printf("program launched with no argument.\nProper usage: %s m \n", exe_name);
        return true;
    }
    else if (num_args > 2){
        printf("program launched with too many arguments.\nProper usage: %s m\n", exe_name);
        return true;
    }

    return false;
}