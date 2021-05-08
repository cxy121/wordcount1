#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void a(FILE *fp){//统计单词数目 
	int cnt = 0;
	    char s[1024];
	    int i;
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            for (i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数:%d\n", cnt);
}

void b(FILE *fp){
	int i;
	int cnt=0;
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数:%d\n", cnt);
}
int main (int argc, char *argv[])
{
    FILE *f;
    f=fopen(argv[2], "r");
    
    /*
    if ((f=fopen(argv[2], "r")) == NULL)
    {
        puts("ERROR!\n");
        return 0;
    }*/
    if (argv[1][1] == 'w') // 统计单词
    {
    	a(f);
        
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        b(f);
    }
    fclose(f);
    return 0;
}

/* 
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int count = 0; // 统计数
    int i;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("ERROR!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 统计单词
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("单词数:%d\n", count);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) count ++;
        printf("字符数:%d\n", count);
    }
    fclose(fp);
    return 0;
}
*/
