#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int tentotwo(int a);
int tentoeight(int a);
int tentosix(int a);
int getjian(int ch);

/*
*   UP     ---   return 1;
*   DOWM   ---   return 2;
*   LEFT   ---   return 3;
*   RIGHT  ---   return 4;
*/




int main()
{
    int i,a;
    char *str1[10] = {
                        "*********************************************",
                        "*                                           *",
                        "*                                           *",
                        "*           >十进制数转二进制数             *",
                        "*            十进制数转八进制数             *",
                        "*            十进制数转16进制数             *",
                        "*            退出                           *",
                        "*                                           *",
                        "*                                           *",
                        "*********************************************"
                    };
    char *str2[10] = {
                        "*********************************************",
                        "*                                           *",
                        "*                                           *",
                        "*            十进制数转二进制数             *",
                        "*           >十进制数转八进制数             *",
                        "*            十进制数转16进制数             *",
                        "*            退出                           *",
                        "*                                           *",
                        "*                                           *",
                        "*********************************************"
                    };
    char *str3[10] = {
                       "*********************************************",
                        "*                                           *",
                        "*                                           *",
                        "*            十进制数转二进制数             *",
                        "*            十进制数转八进制数             *",
                        "*           >十进制数转16进制数             *",
                        "*            退出                           *",
                        "*                                           *",
                        "*                                           *",
                        "*********************************************"
                    };
    char *str4[10] = {
                        "*********************************************",
                        "*                                           *",
                        "*                                           *",
                        "*            十进制数转二进制数             *",
                        "*            十进制数转八进制数             *",
                        "*            十进制数转16进制数             *",
                        "*           >退出                           *",
                        "*                                           *",
                        "*                                           *",
                        "*********************************************"
                    };
    one:
        {
            system("cls");
            for(i=0; i<10; ++i)
            {
                printf("%s\n",str1[i]);
            }
            switch(getjian(a))
            {
                case 5:goto page1;
                case 1:goto four;
                case 2:goto two;
                default:goto one;
            }
        };
    two:
        {
            system("cls");
            for(i=0; i<10; ++i)
            {
                printf("%s\n",str2[i]);
            }
            switch(getjian(a))
            {
                case 5:goto page2;
                case 1:goto one;
                case 2:goto three;
                default:goto two;
            }
        };
    three:
        {
            system("cls");
            for(i=0; i<10; ++i)
            {
                printf("%s\n",str3[i]);
            }
            switch(getjian(a))
            {
                case 5:goto page3;
                case 1:goto two;
                case 2:goto four;
                default:goto three;
            }
        };
    four:
        {
            system("cls");
            for(i=0; i<10; ++i)
            {
                printf("%s\n",str4[i]);
            }
            switch(getjian(a))
            {
                case 5:exit(0);
                case 1:goto three;
                case 2:goto one;
                default:goto four;
            }
        };
    page1:
        {
            zhuanhua(tentotwo);
            if(getjian(a)==5) goto one;
        };
    page2:
        {
            zhuanhua(tentoeight);
            if(getjian(a)==5) goto two;
        };
    page3:
        {
            zhuanhua(tentosix);
            if(getjian(a)==5) goto three;
        };
    return 0;
}


void zhuanhua(int (*f)(int a))
{
    int a;
    system("cls");
    printf("请输入十进制数:\n");
    scanf("%d",&a);
    f(a);
    printf("按回车键返回......");
}



int getjian(int ch)
{
    ch = getch();
    if(ch == 13) return 5;
    switch(getch())
    {
        case 72:return 1;break; //UP
        case 80:return 2;break; //DOWN
    }
    return 0;
/*
*   UP     ~   return 1;
*   DOWM   ~   return 2;
*   LEFT   ~   return 3;
*   RIGHT  ~   return 4;
*/
}

int tentotwo(int a)
{
    int i = 0, str[32];
    for (; a > 0; a /= 2) str[i++] = a % 2;
    printf("十进制整数转换为二进制数是:\n");
    for (i--; i >= 0; i--) printf("%d", str[i]);
    printf("\n");
    return 0;
}

int tentoeight(int a)
{
    int i = 0, str[32];
    for (; a > 0; a /= 8) str[i++] = a % 8;
    printf("十进制整数转换为八进制数是:\n");
    for (i--; i >= 0; i--) printf("%d", str[i]);
    printf("\n");
    return 0;
}

int tentosix(int a)
{
    char str[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char fuck[32];
    int i=0;
    for (;a>0;a/=16) fuck[i++] = str[a%16];
    printf("十进制整数转换为16进制数是:\n");
    printf("0x");
    for (i--;i>=0;i--) printf("%c",fuck[i]);
    printf("\n");
    return 0;
}
