/*
    Input through stdin ( pipe '|' ) and prints approximate rainbow 
    paragraph
*/

#include<stdio.h>
#include<stdlib.h>

#define BLACK       "\x1b[30m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define PURPLE      "\x1b[35m"
#define CYAN        "\x1b[36m"
#define RESET       "\x1b[0m"


void readBuffer(char buff[256][256], int *lineCount, int *maxWidth) {
    char c;
    int chrCountLine = 0;
    while((c = fgetc(stdin)) != EOF){
        // printf("\nCopying -  %c\n", c);
        if(*lineCount > 255) {
            return;
        }
        buff[*lineCount][chrCountLine] = c;  
        chrCountLine++;
        if(c == 10) {
            buff[*lineCount][chrCountLine] = '\0';
            (*lineCount)++;
            if(chrCountLine > *maxWidth) *maxWidth = chrCountLine;
            chrCountLine = 0;
        }
    }
    lineCount--;

}

char *calculateColor(int linePos, int colorSpreadRegionSize){
    char *COLORS[] = {PURPLE, BLUE, GREEN, YELLOW, CYAN, RED};
    int paintArea = linePos/colorSpreadRegionSize;
    if(paintArea > 5) paintArea = 5;
    return COLORS[paintArea];
}


void printColoredOutput(char buff[256][256], int lineCount) {
    int linePos = 0;
    char *COLORS[] = {PURPLE, BLUE, GREEN, YELLOW, CYAN, RED};
    int colorSpreadRegionSize = lineCount/6;
    if (colorSpreadRegionSize <= 0) colorSpreadRegionSize = 1;

    while(linePos < lineCount) {
        int traverseLine = 0;
        char c;
        char *color = calculateColor(linePos, colorSpreadRegionSize);
        while((c=buff[linePos][traverseLine++])!='\0'){
            printf("%s%c", color, c);
        }
        printf("%s", RESET);
        linePos++;
    }
}


int main() {
    printf("\nHELLO LOLCAT\n" );

    char buff[256][256];
    int lineCount=0, maxWidth=0;

    readBuffer(buff, &lineCount, &maxWidth);

    

    printf("\nSizeof(buff), %ld, lineCount =%d, maxWidth = %d\n", sizeof buff, lineCount, maxWidth);
    
    printColoredOutput(buff, lineCount);
    
    return 0;
} 