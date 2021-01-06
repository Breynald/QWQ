#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void output_text(int numColumn, char strText[]);
int JudgeendChar(char ch);
int main()
{
    char strText[] = {"We have an old musical instrument.It is called a clavichord.It was made in Germany in 1681.Our clavichord is kept in the living-room.It has belonged to our family for a long time.The instrument was bought by my grandfather many years ago.Recently it was damaged by a visitor.She tried to play jazz on it!She struck the keys too hard and two of the strings were broken.My father was shocked.Now we are not allowed to touch it.It is being repaired by a friend of my father's."};
    int numColumn;
    output_text(30, strText);
    printf("输入列宽重新排列......\n");
    scanf("%d",&numColumn);
    while (numColumn < 20)
    {
        printf("数据非法！请重新输入......\n");
        scanf("%d",&numColumn);
    }
    output_text(numColumn, strText);
    system("pause");
}
/*判断字符函数*/
int JudgeendChar(char ch)
{
    if (ch==',' || ch=='.' || ch=='!')
        return 1;
    else if (ch == ' ')
        return 2;
    else return 3;
}


void output_text(int numColumn, char strText[])
{
    char strALine[500], strOutput[500];
    int startChar=0, endChar, numSpace=0, fuckChar, fuck;
    while(1)
    {
        int j=0, i=0, numinsert, numinsert1, numSpace = 0;
        endChar = startChar + numColumn - 1;
        fuckChar = startChar;
        char a[500] = {' '};
        memcpy(strALine, a, sizeof(a));
        memcpy(strOutput, a, sizeof(a));
        /*最后一行输出*/
        if (endChar >= (int)strlen(strText))
        {
            while (strText[startChar] != '\0')
                printf("%c",strText[startChar++]);
            printf("\n");
            break;
        }
        /*分行处理*/
        switch (JudgeendChar(strText[endChar]))
        {
            case 1 /*标点*/ :
                {
                    for (; startChar<=endChar; startChar++)
                    {
                        strALine[startChar-fuckChar] = strText[startChar];
                    }
                    strALine[startChar-fuckChar] = '\0';
                    break;
                }
            case 2 /*空格*/ :
                {
                    for (; startChar<=endChar-1; startChar++)
                    {
                        strALine[startChar-fuckChar] = strText[startChar];
                    }
                    strALine[startChar-fuckChar] = '\0';
                    startChar++;
                    break;
                }
            case 3 /*字符*/ :
                {
                    if (JudgeendChar(strText[endChar+1])==2)
                    {
                        for (; startChar<=endChar; startChar++)
                        {
                            strALine[startChar-fuckChar] = strText[startChar];
                        }
                        strALine[startChar-fuckChar] = '\0';
                    }
                    else
                    {
                        while (JudgeendChar(strText[endChar])==3)
                        {
                            endChar--;
                        }
                        switch (JudgeendChar(strText[endChar]))
                        {
                            case 1 /*标点*/ :
                            {
                                for (; startChar<=endChar; startChar++)
                                {
                                    strALine[startChar-fuckChar] = strText[startChar];
                                }
                                strALine[startChar-fuckChar] = '\0';
                                break;
                            }
                            case 2 /*空格*/ :
                            {
                                for (; startChar<=endChar-1; startChar++)
                                {
                                    strALine[startChar-fuckChar] = strText[startChar];
                                }
                                strALine[startChar-fuckChar] = '\0';
                                startChar++;
                                break;
                            }
                        }
                        break;
                    }
                }
        }
        /*格式化输出*/
        {
            for (int i=0; i<(int)strlen(strALine); i++)
            {
                if (isspace(strALine[i]))
                    numSpace++;
            }
            i = 0;
            numinsert = (numColumn - strlen(strALine)) / numSpace;
            numinsert1 = (numColumn - strlen(strALine)) % numSpace;
            while (i <= (int)strlen(strALine))
            {
                if (strALine[i] == ' ')
                {
                    fuck = j + numinsert;
                    for (; j<fuck;)
                        strOutput[j++] = ' ';
                    if (numinsert1-- > 0)
                    {
                        strOutput[j++] = ' ';
                    }
                }
                strOutput[j++] = strALine[i++];
            }
            strOutput[j] = '\0';
            puts(strOutput);
        }
    }
}
