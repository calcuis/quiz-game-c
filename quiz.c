#include <stdio.h>
#include <ctype.h>

int main (){
    char questions[][100] = {"1. What year did the C language debut?: ",
                             "2. Who is credited with creating C?: ",
                             "3. Python is written by which language?: "};

    char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                           "A. Dennis Ritchie", "B. Bill Gate", "C. Tim Cook", "D. Elon Musk",
                           "A. C", "B. C+", "C. C++", "D. C#"};

    char answers[3] = {'B', 'A', 'A'};
    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

    char guess;
    int score;

    printf("***  QUIZ GAME  ***\n");
    FILE *pF = fopen("results.txt", "a");

    for(int i = 0; i < numberOfQuestions; i++){
        printf("****************************************\n");
        printf("%s\n", questions[i]);
        printf("****************************************\n");

        for(int j = (i * 4); j < (i * 4) + 4; j++){
            printf("%s\n", options[j]);
        }

        printf("Guess: ");
        scanf("%c", &guess);
        scanf("%*c"); //clear \n from input buffer

        guess = toupper(guess);
        fprintf(pF, "%c\n", guess);

        if(guess == answers[i]){
            printf("CORRECT!\n");
            score++;
        }
        else{
            printf("WRONG!\n");
            printf("Answer: %c\n", answers[i]);
        }
    }

    printf("******************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
    printf("******************\n");

    fprintf(pF, "FINAL SCORE: %d/%d", score, numberOfQuestions);
    fclose(pF);

    return 0;
}
