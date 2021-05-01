#include<stdio.h>
#define MAXLINE 120 /* 1行の最大文字数 */

static FILE *fpi;           // ソースファイル
static FILE *fpo;           // コンパイラの出力ファイル
static char line[MAXLINE];  // 1行分の入力バッファ
static int lineIndex = -1;  // 次に読む文字の位置

char nextChar()             // 次の１文字を返す関数
{
    char ch;
    if (lineIndex == -1 ){
        if(fgets(line, MAXLINE, fpi) != NULL){
            fputs(line, fpo);
            lineIndex = 0;
        } else {
            printf("end of file\n");
            exit(1);
        }
    }
    if((ch = line[lineIndex++]) == '\n'){
        lineIndex = -1;
        return ' ';
    }
    return ch;

}

/*

state1: ch = nextChar();
    if(charClassT[ch] == letter)
        goto state2;
    else
        error();

state2: ch = nextChar;
    if(charClassT[ch] == letter || charClassT[ch] == digit)
        goto state2;
    else
        goto state3;
state3:

*/

/* x.yE±zの形式の浮動小数点数を読み込む */
/*
int b;              // xyを整数と見たかず
int e;              // yの桁数
int i;              // zの値
char sign;          // 指数の符号

statei: b = 0; e = 0; i = 0;
    if(ch == '.') {
        ch = nextChar;
        if(charClassT[ch] != digit) error();
        b = ch - '0'; e = 1;
    } else if(charClassT[ch] ==digit) {
        do {
            b = 10 * b + ch - '0';
            ch = nextChar();
        } while(charClassT[ch] == digit);
        if(ch == 'E') goto exp;
    }

exp: sign = '+'; ch = nextChar();
*/