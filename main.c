#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void a(FILE *fp){//ͳ�Ƶ�����Ŀ 
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
        printf("������:%d\n", cnt);
}

void b(FILE *fp){
	int i;
	int cnt=0;
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("�ַ���:%d\n", cnt);
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
    if (argv[1][1] == 'w') // ͳ�Ƶ���
    {
    	a(f);
        
    }
    else if (argv[1][1] == 'c') // ͳ���ַ�
    {
        b(f);
    }
    fclose(f);
    return 0;
}

/* 
int main (int argc, char *argv[])
{
    // argc ��ʾ��������, *argv[]ָ������, ÿһ��ָ��ָ��һ���ַ���
    FILE *fp;
    int count = 0; // ͳ����
    int i;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("ERROR!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // ͳ�Ƶ���
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("������:%d\n", count);
    }
    else if (argv[1][1] == 'c') // ͳ���ַ�
    {
        char c;
        while ((c = fgetc(fp)) != EOF) count ++;
        printf("�ַ���:%d\n", count);
    }
    fclose(fp);
    return 0;
}
*/
