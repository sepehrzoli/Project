#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
char finalremove[1000],clipboard[1000],finalpaste[1000],komaki[1000],gadress[1000],gadress1[1000],create[1000];
char freplace[1000];
char autoi[1000];
int gindex,at,countertree=0,flag=1;
int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;  //exists
    }
    return 0;   // opposite
}
void chertgir(char c)
{
    scanf("%c",&c);
    while (c!='\n')
    {
        scanf("%c",&c);
    }
    printf("invalid input\n");
}
void resetadress(char s[])
{
    s[0]='r'; s[1]='o';s[2]='o';s[3]='t';s[4]='/';
}
int tedad(char adress[])
{
    int m=strlen(adress);
    int k=0,counter=0;
    while(adress[k]!=NULL)
    {
        if (adress[k]=='/')
            counter++;
        k++;
    }
    return counter;
}
int indexx(int line,int cchar,char m[])
{
    int counterline=1;
    int counterchar=0;
    int i=0;
    for (;counterchar!=cchar||counterline!=line;i++)
    {
        if (m[i]=='\n')
        {
            counterline++;
            counterchar=0;
        }
        counterchar++;
    }
    return i+1;
}
void reset(char a[])
{
    for (int i=0;i<1000;i++)
    {
        a[i]=NULL;
    }
}
void removestr(char type,int size,int index,char remove[])
{
    reset(finalremove);
    if (type=='b')
    {
        int x=index-size+1;
        int counter=0;
        for (int i=0;i<x;i++)
        {
            finalremove[i]=remove[i];
            counter++;
        }
        for(int i=index+1;i<strlen(remove);i++)
        {
            finalremove[counter]=remove[i];
            counter++;
        }
    }
    else
    {
        int x=index+size-1;
        int counter=0;
        for (int i=0;i<index;i++)
        {
            finalremove[i]=remove[i];
            counter++;
        }
        for(int i=x+1;i<strlen(remove);i++)
        {
            finalremove[counter]=remove[i];
            counter++;
        }
    }
}
int adad(int start,int finish,char m[])
{
    int x=0;
    while(start<=finish)
    {
        x=x*10;
        int alan=m[start]-'0';
        x=x+alan;
        start++;
    }//123
    return x;
}
int adadat(int start,char m[])
{
    int x=0;
    while(m[start]>='0'&&m[start]<='9')
    {
        x=x*10;
        int alan=m[start]-'0';
        x=x+alan;
        start++;
    }//123
    return x;
}
int ta(int x)
{
    if (x==0)
        return 1;
    int t=0;
    while(x>0)
    {
        t++;
        x=x/10;
    }
    return t;
}
void pastestr(int index,char paste[])
{
    int counter=0;
    int x=strlen(clipboard);
    for (int i=0;i<=index;i++)
    {
        finalpaste[i]=paste[i];
        counter++;
    }
    for (int i=0;i<x;i++)
    {
        finalpaste[counter]=clipboard[i];
        counter++;
    }
    for(int i=index+1;i<strlen(paste);i++)
    {
        finalpaste[counter]=paste[i];
        counter++;
    }
}
int findword(char a[],char kol[])
{
    int counter=0,index,flag=0;;
    for (int i=0;i<=strlen(kol)-strlen(a);i++)
    {
        for (int j=i;j<i+strlen(a);j++)
        {
            if (kol[j]==a[j-i])
            {
                counter++;
            }
        }
        if (counter==strlen(a))
        {
            index=i;
            flag=1;
            break;
        }
        else{counter=0;}
    }
    if (flag==1)
        return index;
    return -1;
}
void makestring(int index1,int index2,char source[],char now[])
{
    reset(now);
    for (int i=index1;i<=index2;i++)
    {
        now[i-index1]=source[i];
    }
}
void copystr(char type,int size,int index,char copy[])
{
    if (type=='b')
    {
        int x=index-size+1;
        for (int i=x;i<=index;i++)
        {
            clipboard[i-x]=copy[i];
        }
    }
    else
    {
        int x=index+size-1;
        for (int i=index;i<=x;i++)
        {
            clipboard[i-index]=copy[i];
        }
    }
}
void findadress(char dastor[])
{

    reset(gadress);
    //printf("%d\n",gindex);
    int i=0;
    if (dastor[gindex]=='"')
    {
        gindex=gindex+2;
        while(dastor[gindex]!='"')
        {
            gadress[i]=dastor[gindex];
            gindex++;
            i++;
        }
        if (dastor[gindex+1]==NULL)
            gindex++;
        else
            gindex+=2;
    }
    else
    {
        gindex++;
        while(dastor[gindex]!=' '&&dastor[gindex]!=NULL)
        {
            gadress[i]=dastor[gindex];
            gindex++;
            i++;
        }
        if (dastor[gindex]!=NULL)
        {
            gindex++;
        }
    }

}
int tedadkalame(char x[])
{
    int counter=0;
    for (int i=0;i<strlen(x);i++)
    {
        if (x[i]!=' '&&x[i]!='\n'&&x[i]!=NULL&&(i==0||x[i-1]==' '||x[i-1]=='\n'))
        {
            counter++;
        }
    }
    return counter;
}
int afindword(char kalame[],char patern[])
{
    int x=strlen(patern)-1,y=strlen(kalame)-1;
    char helpp[1000],helpk[1000];
    reset(helpp); reset(helpk);
    if ((int)patern[0]==92&&patern[1]=='*')
    {
        makestring(1,x,patern,helpp);
        if (strcmp(kalame,helpp)==0)
            return 1;
        return 0;
    }
    else if (patern[0]=='*')
    {
        makestring(1,x,patern,helpp);
        makestring(y-x+1,y,kalame,helpk);
        if (strcmp(helpk,helpp)==0)
            return 1;
        return 0;
    }
    else if (patern[x]=='*'&&(int)patern[x-1]==92)
    {
        makestring(0,x-2,patern,helpp);
        helpp[x-1]='*';
        if (strcmp(kalame,helpp)==0)
            return 1;
        return 0;
    }
    else if (patern[x]=='*')
    {
        makestring(0,x-1,patern,helpp);
        makestring(0,x-1,kalame,helpk);
        if (strcmp(helpk,helpp)==0)
            return 1;
        return 0;
    }
    else
    {
        if (strcmp(kalame,patern)==0)
            return 1;
        return 0;
    }
}
void autoin(char matn[])   //auto-indent /root/sepehr.txt
{
    reset(autoi);
    int c=0,counter=0,flag=0;
    int x=strlen(matn);
    for (int i=0;i<x;i++)
    {
        if ((int)matn[i]==123)
        {
            counter++;
            int t=i;
            while (matn[t+1]==' ')
            {
                t++;
            }
            if (matn[i-1]!=' '&&matn[i-1]!='{'&&i!=0)
            {
                autoi[c]=' ';
                c++;
                autoi[c]=(char)123;
                c++;
                if (matn[t+1]!='\n')
                {
                    autoi[c]='\n';
                    c++;
                }
                int k=i;
                while (matn[k]!='}')
                {
                    k++;
                    if (matn[k]!='}'&&matn[k]!=' ')
                        flag=1;
                }
                if (flag==1)
                {
                    for (int k=0;k<4*counter;k++)
                    {
                        autoi[c]=' ';
                        c++;
                    }
                }
                else
                {
                    for (int k=0;k<4*counter-4;k++)
                    {
                        autoi[c]=' ';
                        c++;
                    }
                }
                while (matn[i+1]==' ')
                {
                    i++;
                }
            }
            else
            {
                autoi[c]=(char)123;
                c++;
                if (matn[t+1]!='\n')
                {
                    autoi[c]='\n';
                    c++;
                }
                int k=i;
                while (matn[k]!='}')
                {
                    k++;
                    if (matn[k]!='}'&&matn[k]!=' ')
                        flag=1;
                }
                if (flag==1)
                {
                    for (int k=0;k<4*counter;k++)
                    {
                        autoi[c]=' ';
                        c++;
                    }
                }
                else
                {
                    for (int k=0;k<4*counter-4;k++)
                    {
                        autoi[c]=' ';
                        c++;
                    }
                }
                while (matn[i+1]==' ')
                {
                    i++;
                }
            }
        }
        else if ((int)matn[i]==125)
        {
            counter--;
            //printf("d\n");
            int k=i;
            while (matn[k]!='{')
            {
                k--;
                if (matn[k]!='{'&&matn[k]!=' ')
                    flag=1;
            }
            if (flag==1)
            {
                autoi[c]='\n';
                c++;
                for (int k=0;k<4*counter;k++)
                {
                    autoi[c]=' ';
                    c++;
                }
            }
            autoi[c]=(char)125;
            c++;
        }
        else
        {
            autoi[c]=matn[i];
            c++;
        }
        flag=0;
    }
    //printf("%s",autoi);
}
int firstnomin(char x[],int n)
{
    int counter=0,counterkalame=0;
    if (x[0]!=' ')
        counterkalame=1;
    while(x[counter]!=NULL)
    {
        if (x[counter]==' ')
        {
            while(x[counter]==' '||x[counter]=='\n')
            {
                counter++;
            }
            if (x[counter]!=NULL)
                counterkalame++;
        }
        if (counterkalame==n)
        {
            break;
        }
        else
        {
            counter++;
        }
    }
    if (counterkalame<n)
    {
        return -1;
    }
    return counter;
}
int endnomin(char x[],int n)
{
    int counter=0,counterkalame=1;
    if (x[0]==' ')
    {
        counterkalame=0;
    }
    while(x[counter]!=NULL)
    {
        if (x[counter]==' ')
        {
            while(x[counter]==' '||x[counter]=='\n')
            {
                counter++;
            }
            if (x[counter]!=NULL)
                counterkalame++;
        }
        if (counterkalame==n)
        {
            if (x[counter+1]==' '||x[counter+1]==NULL||x[counter+1]=='\n')
            {
                break;
            }
            counter++;
        }
        else
        {
            counter++;
        }
    }
    if (counterkalame<n)
    {
        return -1;
    }
    return counter;
}
int findcompare(char kalame1[],char kalame2[])  //1=asli   2=patern
{
    int a=tedadkalame(kalame1),flag=1;   //printf("%d\n",a);
    char help1[1000],help2[1000];
    reset(help1); reset(help2);  //
    int f1=firstnomin(kalame1,1),f2=firstnomin(kalame2,1),be1,be2;
    if (f1!=f2)
        return 0;
    //printf("%d %d\n",f1,f2);
    for (int i=1;i<=a;i++)
    {
        int f1=firstnomin(kalame1,i),e1=endnomin(kalame1,i),f2=firstnomin(kalame2,i),e2=endnomin(kalame2,i); //printf("%d\n",f1);
        makestring(f1,e1,kalame1,help1);makestring(f2,e2,kalame2,help2);
        if (i>1)
        {
            if (f1-be1!=f2-be2)
                return 0;
        }
        if (afindword(help1,help2)==0)
            flag=0;
        if (flag==0)
            break;
        be1=e1;
        be2=e2;
    }
    if (flag==1)
        return 1;
    return 0;
}
void compare(char ad1[],char ad2[])
{
    FILE *f1,*f2;
    f1=fopen(ad1,"r");
    f2=fopen(ad2,"r");
    int buffl=1000;
    char buffer[buffl];
    reset(buffer);
    int line1=0,line2=0;
    while(fgets(buffer, buffl, f1)) {
        line1++;
    }
    fclose(f1);
    while(fgets(buffer, buffl, f2)) {
        line2++;
    }
    fclose(f2);
    if (line1>line2)
    {
        f1=fopen(ad1,"r");
        f2=fopen(ad2,"r");
        int buffl=1000,counter;
        char buffer1[buffl],buffer2[buffl];
        reset(buffer1); reset(buffer2);
        while(fgets(buffer2, buffl, f2)) {
            counter++;
            fgets(buffer1,buffl,f1);
            if (strcmp(buffer1,buffer2))
            {
                printf("========#%d========\n%s%s",counter,buffer1,buffer2);
            }
        }
        printf("\n<<<<<<<#%d-#%d<<<<<<content from file 1\n",line2+1,line1);
        while(fgets(buffer1, buffl, f1)) {
                printf("%s",buffer1);
        }
        fclose(f1); fclose(f2);
        printf("\n");
    }
    else if (line2>line1)
    {
        f1=fopen(ad1,"r");
        f2=fopen(ad2,"r");
        int buffl=1000,counter;
        char buffer1[buffl],buffer2[buffl];
        reset(buffer1); reset(buffer2);
        while(fgets(buffer1, buffl, f1)) {
            counter++;
            fgets(buffer2,buffl,f2);
            if (strcmp(buffer1,buffer2))
            {
                printf("========#%d========\n%s%s",counter,buffer1,buffer2);
            }
        }
        printf("\n<<<<<<<#%d-#%d<<<<<<content from file 2\n",line1+1,line2);
        while(fgets(buffer2, buffl, f2)) {
                printf("%s",buffer2);
        }
        fclose(f1); fclose(f2);
        printf("\n");
    }
    else // compare /root/new.txt /root/salam.txt
    {
        f1=fopen(ad1,"r");
        f2=fopen(ad2,"r");
        int buffl=1000,counter;
        char buffer1[buffl],buffer2[buffl];
        reset(buffer1); reset(buffer2);
        while(fgets(buffer1, buffl, f1)) {
            counter++;
            fgets(buffer2,buffl,f2);
            if (strcmp(buffer1,buffer2))
            {
                printf("========#%d========\n%s%s",counter,buffer1,buffer2);
            }
        }
        fclose(f1); fclose(f2);
        printf("\n");
    }
}
void replace(int start,int finish,char attach[],char original[],char end[])
{
    reset(end);
    strncat(end,original,start);
    strcat(end,attach);
    char help[1000];
    reset(help);
    makestring(finish+1,strlen(original)-1,original,help);
    strcat(end,help);
    strcpy(original,freplace);
}
void finalreplace(char kalame[],char patern[],char attach[],int mode)
{
    flag=1;
    if (mode==3)
    {
        printf("invalid tarkib");
        return;
    }
    reset(freplace);
    int a=tedadkalame(patern);
    int counterkalame=1;
    if (kalame[0]==' ')
        counterkalame=0;
    int index=-1;
    int indexs[1000][2];
    char help[1000];
    int counter=0;
    for (int i=0;i<1000;i++)
    {
        indexs[i][0]=-1;indexs[i][1]=-1;
    }
    char komakkalame[1000];
    for (int i=0;i<strlen(kalame);i++)
    {
        if(kalame[i]==' '||kalame[i]=='\n')
        {
            int x=counterkalame+a;
            if(firstnomin(kalame,x)==-1)
            {
                break;
            }
            int m=endnomin(kalame,x);
            while(kalame[m]!=' '&&kalame[m]!='\n'&&kalame[m]!=NULL)
            {
                if(m>=i)
                {
                    makestring(i,m,kalame,komakkalame);
                    //printf("%s\n",komakkalame);
                    if (findcompare(komakkalame,patern))   // zoli   || *li
                    {
                        index=i;
                        if (patern[0]=='*')
                        {
                            while(kalame[index]!=' '&&index>=0&&kalame[index]!='\n')
                            {
                                index--;
                            }
                            index++;
                        }
                        indexs[counter][0]=index;
                        indexs[counter][1]=m;
                        printf("%d %d\n",index,m);
                        counter++;
                    }
                }
                m--;
            }
            if (kalame[i+1]!=' '&&kalame[i+1]!='\n'&&kalame[i+1]!=NULL)
            {
                counterkalame++;
            }
        }
        else
        {
            int x=counterkalame+a-1;
            if(firstnomin(kalame,x)==-1)
            {
                break;
            }
            else
            {
                int m=endnomin(kalame,x);
                while(kalame[m]!=' '&&kalame[m]!='\n'&&kalame[m]!=NULL)
                {
                    if(m>=i)
                    {
                        makestring(i,m,kalame,komakkalame);
                        //printf("%s\n",komakkalame);
                        if (findcompare(komakkalame,patern))
                        {
                            index=i;
                            if (patern[0]=='*')
                            {
                                while(kalame[index]!=' '&&index>=0&&kalame[index]!='\n')
                                {
                                    index--;
                                }
                                index++;
                            }
                            //printf("%d %d\n",index,m);
                            indexs[counter][0]=index;
                            indexs[counter][1]=m;
                            counter++;
                            i=endnomin(kalame,counterkalame);
                            break;
                        }
                    }
                    m--;
                }
            }
        }
    }
    //printf("%d %d\n",indexs[0][0],indexs[0][1]);
    if (mode==0)
    {
        if (counter==0)
        {
            printf("does not exists\n"); flag=0;
        }
        else
        {
            replace(indexs[0][0],indexs[0][1],attach,kalame,freplace);
            printf("%s\n",freplace);
        }
    }
    else if (mode==1)
    {
        if (counter<at)
        {
            printf("does not exists\n"); flag=0;
        }
        else
        {
            replace(indexs[at][0],indexs[at][1],attach,kalame,freplace);
        }
    }
    else if (mode==2)
    {
        if (counter==0)
        {
            printf("does not exists\n"); flag=0;
        }
        else
        {
            for(int i=0;i<counter;i++)
            {
                replace(indexs[i][0],indexs[i][1],attach,kalame,freplace);
                for (int j=i+1;j<counter;j++)
                {
                    indexs[j][0]=indexs[j][0]+strlen(attach)-(indexs[i][1]-indexs[i][0]+1);
                    indexs[j][1]=indexs[j][1]+strlen(attach)-(indexs[i][1]-indexs[i][0]+1);
                }
            }
        }
    }
}
void finalfind(char kalame[],char patern[],int mode)  //all byword||byword at
{
    if (mode>8||mode==5||mode==7)
    {
        printf("invalid tarkib\n");
        return;
    }
    int a=tedadkalame(patern);
    int counterkalame=1;
    if (kalame[0]==' ')
        counterkalame=0;
    int index=-1,flag=0;
    int indexs[1000];
    int bywords[1000];
    int counter=0;
    for (int i=0;i<1000;i++)
    {
        indexs[i]=-1; bywords[i]=-1;
    }
    char komakkalame[1000];
    for (int i=0;i<strlen(kalame);i++)
    {
        if(kalame[i]==' '||kalame[i]=='\n')
        {
            int x=counterkalame+a;
            if(firstnomin(kalame,x)==-1)
            {
                break;
            }
            int m=firstnomin(kalame,x);
            while(kalame[m]!=' '&&kalame[m]!='\n'&&kalame[m]!=NULL)
            {
                if(m>=i)
                {
                    makestring(i,m,kalame,komakkalame);
                    //printf("%s\n",komakkalame);
                    if (findcompare(komakkalame,patern))   // zoli   || *li
                    {
                        flag=1;
                        index=i;
                        if (patern[0]=='*')
                        {
                            while(kalame[index]!=' '&&index>=0&&kalame[index]!='\n')
                            {
                                index--;
                            }
                            index++;
                        }
                        indexs[counter]=index;
                        bywords[counter]=counterkalame;
                        counter++;
                    }
                }
                m++;
            }
            if (kalame[i+1]!=' '&&kalame[i+1]!='\n'&&kalame[i+1]!=NULL)
            {
                counterkalame++;
            }
        }
        else
        {
            int x=counterkalame+a-1;
            if(firstnomin(kalame,x)==-1)
            {
                break;
            }
            else
            {
                int m=firstnomin(kalame,x);
                while(kalame[m]!=' '&&kalame[m]!='\n'&&kalame[m]!=NULL)
                {
                    if(m>=i)
                    {
                        makestring(i,m,kalame,komakkalame);
                        if (findcompare(komakkalame,patern))
                        {
                            flag=1;
                            index=i;
                            if (patern[0]=='*')
                            {
                                while(kalame[index]!=' '&&index>=0&&kalame[index]!='\n')
                                {
                                    index--;
                                }
                                index++;
                            }
                            indexs[counter]=index;
                            bywords[counter]=counterkalame;
                            counter++;
                        }
                    }
                    m++;
                }
            }
        }
    }
    //printf("%d\n",mode);
    if (mode==0)
    {
        printf("%d\n",indexs[0]);
    }
    if (mode==1)
    {
        printf("%d\n",indexs[at]);
    }
    if (mode==2)
    {
        printf("%d\n",bywords[0]);
    }
    if (mode==3)
    {
        printf("%d\n",bywords[at]);
    }
    if (mode==4)
    {
        for(int i=0;i<counter;i++)
        {
            printf("%d\n",indexs[i]);
        }
    }
    if (mode==6)
    {
        for(int i=0;i<counter;i++)
        {
            printf("%d\n",bywords[i]);
        }
    }
    if (mode==8)
    {
        printf("%d\n",counter);
    }
}
void createfile(char g[],int mode)  //0 baraye create file va 1 baraye baghie
{
    int x=0;
    reset(create);
    FILE *fp;
    while(g[x]!=NULL)
    {
        if (g[x]=='/')
        {
            mkdir(create);
            //printf("%s\n",create);
        }
        create[x]=g[x];
        x++;
        if (g[x]==NULL)
        {
            if (exists(g)==1)
            {
                if (mode==0) printf("file exists\n");
            }
            else
            {
                fp=fopen(g,"w");
                fclose(fp);
            }
        }
     }                   //printf("%s\n",adress);
}
void tree(char *basePath, const int root,int d)
{
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    if (!dir)
        return;
    while (((dp = readdir(dir)) != NULL)&&d!=0)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");

            }
            printf("%c%c%s\n", 195, 196, dp->d_name);
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 2,d-1);
        }
    }
    closedir(dir);
}
int main()
{

    FILE *fp=NULL;
    reset(finalremove);
    char dastor[100];
    char komak[100];
    char esmfile[100],chert,adress[100]="root/";
    int flagslash=0;
    rmdir("salam");
    while(1)
    {
        reset(dastor);
        scanf("%s",dastor);
        if (strcmp(dastor,"createfile")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            gindex=1;
            findadress(dastor);
            //printf("%s\n",gadress);
            //testcase   createfile -file /root/sepi/salam/man.txt
            createfile(gadress,0);
        }
        else if (strcmp(dastor,"insertstr")==0)
        {
            scanf("%s",dastor);
            if (strcmp(dastor,"-file")==0)
            {
                scanf("%[^\n]%*c",dastor);
                if (dastor[1]=='"')
                {
                    int x=8,c=5,counter=0;
                    resetadress(adress);
                    while(dastor[x]!='"')
                    {
                        adress[c]=dastor[x];
                        //printf("%c",dastor[x]);
                        x++;
                        c++;
                        if (dastor[x]=='"')
                        {
                            if (exists(adress)==0)
                            {
                                printf("file does not exists\n");
                            }
                            else
                            {
                                FILE *f;
                                f=fopen(adress,"r"); //bebandesh
                                char alan[1000],m;
                                reset(alan);
                                int q=0;
                                while((m=fgetc(f))!=EOF)
                                {
                                    alan[q]=m;
                                    q++;
                                }
                                strcpy(gadress1,adress);
                                FILE *fp;
                                gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                                createfile(gadress1,1);
                                fp=fopen(gadress1,"w");
                                fputs(alan,fp);
                                fclose(fp);
                                int len1=strlen(dastor)-1,len2=strlen(dastor)-1;
                                while(dastor[len1]!=':')
                                {
                                    len1--;
                                }
                                while(dastor[len2]!=' ')
                                {
                                    len2--;
                                }
                                int line =adad(len2+1,len1-1,dastor),inchar =adad(len1+1,strlen(dastor)-1,dastor);
                                char wantinsert[1000];
                                reset(wantinsert);
                                if(dastor[x+7]=='"')
                                {
                                    for (int i=x+8;i<strlen(dastor)-8-ta(line)-ta(inchar);i++)
                                    {
                                        wantinsert[i-x-8]=dastor[i];
                                        //printf("%d",i-x-8);
                                    }
                                }
                                else
                                {
                                   for (int i=x+7;i<=strlen(dastor)-ta(line)-ta(inchar)-8;i++)
                                    {
                                        wantinsert[i-x-7]=dastor[i];
                                    }
                                }
                                //printf("\n%s",wantinsert);
                                int cline=1,cchar=0,finalcounter=0,alancounter=0;
                                char finalinsert[1000];
                                reset(finalinsert);
                                int i=0;
                                for(;(cline!=line)||(inchar!=cchar);i++)
                                {
                                    finalinsert[i]=alan[i];
                                    cchar++;
                                    if (alan[i]=='\n')
                                    {
                                        cline++;
                                        cchar=0;
                                        finalinsert[i]=alan[i];
                                    }
                                }
                                int edame=i;
                                //printf("%d\n%s\n",i,finalinsert);
                                //printf("%d",strlen(wantinsert));
                                for (int j=0;j<strlen(wantinsert);j++)
                                {
                                    if (((int)wantinsert[j]==92) && (int)wantinsert[j+1]==92 && wantinsert[j+2]=='n')
                                    {
                                        finalinsert[i]=(char)92;
                                        finalinsert[i+1]='n';
                                        i=i+2;
                                        j=j+2;
                                    }
                                    else if ((int)wantinsert[j]==92 && wantinsert[j+1]=='n')
                                    {
                                        //printf("oomad");
                                        finalinsert[i]='\n';
                                        i=i+1;
                                        j=j+1;
                                    }
                                    else
                                    {
                                        finalinsert[i]=wantinsert[j];
                                        i++;
                                    }
                                }
                                //printf("%d %d\n",edame,strlen(alan));
                                for (int j=edame;j<strlen(alan);j++)
                                {
                                    //printf("salam");
                                    //printf("%c",alan[j]);
                                    finalinsert[i]=alan[j];
                                    i++;
                                }
                                //printf("%s",finalinsert);
                                fclose(f);
                                fopen(adress,"w");
                                fputs(finalinsert,f);
                                fclose(f);

                            }
                        //printf("%s\n",adress);
                        }
                    }
                }
                else
                {
                    int x=7,c=5,counter=0;
                    resetadress(adress);
                    while(dastor[x]!=' ')
                    {
                        adress[c]=dastor[x];
                        //printf("%c",dastor[x]);
                        x++;
                        c++;
                        if (dastor[x]==' ')
                        {
                            if (exists(adress)==0)
                            {
                                printf("file does not exists\n");
                            }
                            else
                            {
                                FILE *f;
                                f=fopen(adress,"r"); //bebandesh
                                char alan[1000],m;
                                reset(alan);
                                int q=0;
                                while((m=fgetc(f))!=EOF)
                                {
                                    alan[q]=m;
                                    q++;
                                }
                                strcpy(gadress1,adress);
                                FILE *fp;
                                gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                                createfile(gadress1,1);
                                fp=fopen(gadress1,"w");
                                fputs(alan,fp);
                                fclose(fp);
                                int line =dastor[strlen(dastor)-3]-'0',inchar =dastor[strlen(dastor)-1]-'0';
                                char wantinsert[1000];
                                reset(wantinsert);
                                if(dastor[x+6]=='"')
                                {
                                    for (int i=x+7;i<strlen(dastor)-ta(line)-ta(inchar)-8;i++)
                                    {
                                        wantinsert[i-x-7]=dastor[i];
                                        //printf("%d",i-x-8);
                                    }
                                }
                                else
                                {
                                   for (int i=x+6;i<=strlen(dastor)-ta(line)-ta(inchar)-8;i++)
                                    {
                                        wantinsert[i-x-6]=dastor[i];
                                    }
                                }
                                //printf("\n%s",wantinsert);
                                int cline=1,cchar=0,finalcounter=0,alancounter=0;
                                char finalinsert[1000];
                                reset(finalinsert);
                                int i=0;
                                for(;(cline!=line)||(inchar!=cchar);i++)
                                {
                                    finalinsert[i]=alan[i];
                                    cchar++;
                                    if (alan[i]=='\n')
                                    {
                                        cline++;
                                        cchar=0;
                                        finalinsert[i]=alan[i];
                                    }
                                }
                                int edame=i;
                                //printf("%d\n%s\n",i,finalinsert);
                                //printf("%d",strlen(wantinsert));
                                for (int j=0;j<strlen(wantinsert);j++)
                                {
                                    if (((int)wantinsert[j]==92) && (int)wantinsert[j+1]==92 && wantinsert[j+2]=='n')
                                    {
                                        finalinsert[i]=(char)92;
                                        finalinsert[i+1]='n';
                                        i=i+2;
                                        j=j+2;
                                    }
                                    else if ((int)wantinsert[j]==92 && wantinsert[j+1]=='n')
                                    {
                                        //printf("oomad");
                                        finalinsert[i]='\n';
                                        i=i+1;
                                        j=j+1;
                                    }
                                    else
                                    {
                                        finalinsert[i]=wantinsert[j];
                                        i++;
                                    }
                                }
                                //printf("%d %d\n",edame,strlen(alan));
                                for (int j=edame;j<strlen(alan);j++)
                                {
                                    //printf("salam");
                                    //printf("%c",alan[j]);
                                    finalinsert[i]=alan[j];
                                    i++;
                                }
                                //printf("%s",finalinsert);
                                fclose(f);
                                fopen(adress,"w");
                                fputs(finalinsert,f);
                                fclose(f);

                            }
                        //printf("%s\n",adress);
                        }
                    }
                }

            }
            else
            {
                chertgir(chert);
            }
        }
        else if (strcmp("cat",dastor)==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            gindex=1;
            findadress(dastor);
            FILE *f;
            if (exists(gadress))
            {
                f=fopen(gadress,"r"); //bebandesh
                char m;
                while((m=fgetc(f))!=EOF)
                {
                    printf("%c",m);
                }
                printf("\n");
                fclose(f);
            }
            else
            {
                printf("does not exist\n");
            }
        }
        else if (strcmp("removestr",dastor)==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            resetadress(adress);
            if (dastor[1]=='"')
            {
                int x=8,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!='"')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]=='"')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char remove[1000],m;
                            reset(remove);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                remove[q]=m;
                                q++;
                            }
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            createfile(gadress1,1);
                            fp=fopen(gadress1,"w");
                            fputs(remove,fp);
                            fclose(fp);
                            char type;
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            reset(finalremove);
                            int indexi=indexx(cline,cchar,remove);
                            removestr(type,size,indexi,remove);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            f=fopen(adress,"w");
                            fputs(finalremove,f);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
            else
            {
                int x=7,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!=' ')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]==' ')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char remove[1000],m;
                            reset(remove);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                remove[q]=m;
                                q++;
                            }
                            char type;
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            createfile(gadress1,1);
                            fp=fopen(gadress1,"w");
                            fputs(remove,fp);
                            fclose(fp);
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            reset(finalremove);
                            int indexi=indexx(cline,cchar,remove);
                            removestr(type,size,indexi,remove);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            f=fopen(adress,"w");
                            fputs(finalremove,f);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
        }
        else if (strcmp(dastor,"copystr")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            reset(clipboard);
            if (dastor[1]=='"')
            {
                int x=8,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!='"')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]=='"')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char copy[1000],m;
                            reset(copy);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                copy[q]=m;
                                q++;
                            }
                            char type;
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            int indexi=indexx(cline,cchar,copy);
                            copystr(type,size,indexi,copy);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            printf("%s",clipboard);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
            else
            {
                int x=7,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!=' ')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]==' ')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char copy[1000],m;
                            reset(copy);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                copy[q]=m;
                                q++;
                            }
                            char type;
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            int indexi=indexx(cline,cchar,copy);
                            copystr(type,size,indexi,copy);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            printf("%s",clipboard);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
        }
        else if (strcmp(dastor,"cutstr")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            reset(clipboard);
            if (dastor[1]=='"')
            {
                int x=8,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!='"')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]=='"')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char copy[1000],m;
                            reset(copy);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                copy[q]=m;
                                q++;
                            }
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            fp=fopen(gadress1,"w");
                            createfile(gadress1,1);
                            fputs(copy,fp);
                            fclose(fp);
                            char type;
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            int indexi=indexx(cline,cchar,copy);
                            copystr(type,size,indexi,copy);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            reset(finalremove);
                            removestr(type,size,indexi,copy);
                            fclose(f);
                            f=fopen(adress,"w");
                            fputs(finalremove,f);
                            printf("%s",clipboard);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
            else
            {
                int x=7,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!=' ')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]==' ')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n%s",adress);
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char copy[1000],m;
                            reset(copy);
                            int q=0;
                            reset(clipboard);
                            while((m=fgetc(f))!=EOF)
                            {
                                copy[q]=m;
                                q++;
                            }
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            createfile(gadress1,1);
                            fp=fopen(gadress1,"w");
                            fputs(copy,fp);
                            fclose(fp);
                            char type;
                            int len1,len2,len3,size,cline,cchar,len4;
                            len2=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            len4=strlen(dastor)-1;
                            type=dastor[strlen(dastor)-1];
                            len1=strlen(dastor)-4;
                            while(dastor[len2]!='e')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=':')
                            {
                                len3--;
                            }
                            while(dastor[len4]!='o')
                            {
                                len4--;
                            }
                            size=adad(len2+2,len1,dastor);
                            cline=adad(len4+3,len3-1,dastor);
                            cchar=adad(len3+1,len2-6,dastor);
                            int indexi=indexx(cline,cchar,copy);
                            copystr(type,size,indexi,copy);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            reset(finalremove);
                            removestr(type,size,indexi,copy);
                            f=fopen(adress,"w");
                            //printf("%s\n",clipboard);
                            fputs(finalremove,f);
                            //printf("%s",clipboard);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
        }
        else if (strcmp(dastor,"pastestr")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            reset(finalpaste);
            if (dastor[1]=='"')
            {
                int x=8,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!='"')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]=='"')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char paste[1000],m;
                            reset(paste);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                paste[q]=m;
                                q++;
                            }
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            createfile(gadress1,1);
                            fp=fopen(gadress1,"w");
                            fputs(paste,fp);
                            fclose(fp);
                            char type;
                            int len1,len2,len3,cline,cchar;
                            len2=strlen(dastor)-1;
                            len1=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            while(dastor[len2]!=':')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=' ')
                            {
                                len3--;
                            }
                            cchar=adad(len2+1,len1,dastor);
                            cline=adad(len3+1,len2-1,dastor);
                            int indexi=indexx(cline,cchar,paste);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            pastestr(indexi,paste);
                            f=fopen(adress,"w");
                            fputs(finalpaste,f);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
            else
            {
                int x=7,c=5,counter=0;
                resetadress(adress);
                while(dastor[x]!=' ')
                {
                    adress[c]=dastor[x];
                    x++;
                    c++;
                    if (dastor[x]==' ')
                    {
                        if (exists(adress)==0)
                        {
                            printf("file does not exists\n");
                        }
                        else
                        {
                            FILE *f;
                            f=fopen(adress,"r"); //bebandesh
                            char paste[1000],m;
                            reset(paste);
                            int q=0;
                            while((m=fgetc(f))!=EOF)
                            {
                                paste[q]=m;
                                q++;
                            }
                            strcpy(gadress1,adress);
                            FILE *fp;
                            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                            createfile(gadress1,1);
                            fp=fopen(gadress1,"w");
                            fputs(paste,fp);
                            fclose(fp);
                            char type;
                            int len1,len2,len3,cline,cchar;
                            len2=strlen(dastor)-1;
                            len1=strlen(dastor)-1;
                            len3=strlen(dastor)-1;
                            while(dastor[len2]!=':')
                            {
                                len2--;
                            }
                            while(dastor[len3]!=' ')
                            {
                                len3--;
                            }
                            cchar=adad(len2+1,len1,dastor);
                            cline=adad(len3+1,len2-1,dastor);
                            int indexi=indexx(cline,cchar,paste);
                            //printf("%c",remove[indexi]);
                            //printf("%s",finalremove);
                            fclose(f);
                            pastestr(indexi,paste);
                            f=fopen(adress,"w");
                            fputs(finalpaste,f);
                            fclose(f);
                        }
                    }
                        //printf("%s\n",adress);
                }
            }
        }
        else if (strcmp(dastor,"grep")==0)
        {
            reset(gadress);
            reset(komaki);
            scanf("%[^\n]%*c",dastor);
            //printf("%c",dastor[0]);
            if (dastor[2]=='s')
            {
                int findex=findword("-files",dastor),sindex=findword("-str",dastor);
                char patern[1000];
                reset(patern);
                makestring(sindex+6,findex-3,dastor,komaki);
                makestring(0,strlen(komaki)-1,komaki,patern);
                gindex=findex+7;
                while (dastor[gindex]!=NULL)
                {
                    findadress(dastor);
                    //printf("%s\n",gadress);
                    if (exists(gadress)==0)
                        printf("file does not exist\n");
                    else
                    {
                        FILE* filePointer;
                        int bufferLength = 1000;
                        char buffer[bufferLength]; /* not ISO 90 compatible */
                        filePointer = fopen(gadress, "r");
                        while(fgets(buffer, bufferLength, filePointer)) {
                            //printf("%s %s",buffer,patern);
                            if (findword(patern,buffer)!=-1)
                            {
                                printf("%s: %s\n",gadress,buffer);
                            }
                        }

                        fclose(filePointer);
                    }
                }
            }
            if (dastor[2]=='l')
            {
                int findex=findword("-files",dastor),sindex=findword("-str",dastor);
                char patern[1000];
                reset(patern);
                int counter=0,flag=0;//flago 0 kon
                makestring(sindex+6,findex-3,dastor,komaki);
                makestring(0,strlen(komaki)-1,komaki,patern);
                gindex=findex+7;
                while (dastor[gindex]!=NULL)
                {
                    findadress(dastor);
                    if (exists(gadress)==0)
                        printf("file does not exist\n");
                    else
                    {
                        FILE* filePointer;
                        int bufferLength = 255;
                        char buffer[bufferLength]; /* not ISO 90 compatible */
                        filePointer = fopen(gadress, "r");
                        while(fgets(buffer, bufferLength, filePointer)) {
                            //printf("%s %s",buffer,patern);
                            if (findword(patern,buffer)!=-1 && flag==0)
                            {
                                printf("%s ",gadress);
                                flag=1;
                            }
                        }
                        fclose(filePointer);
                        flag=0;
                    }
                }
                printf("\n");
            }
            if (dastor[2]=='c')
            {
                int findex=findword("-files",dastor),sindex=findword("-str",dastor);
                char patern[1000];
                reset(patern);
                int counter=0;
                makestring(sindex+6,findex-3,dastor,komaki);
                makestring(0,strlen(komaki)-1,komaki,patern);
                gindex=findex+7;
                while (dastor[gindex]!=NULL)
                {
                    findadress(dastor);
                    if (exists(gadress)==0)
                        printf("file does not exist\n");
                    else
                    {
                        FILE* filePointer;
                        int bufferLength = 255;
                        char buffer[bufferLength]; /* not ISO 90 compatible */
                        filePointer = fopen(gadress, "r");
                        while(fgets(buffer, bufferLength, filePointer)) {
                            //printf("%s %s",buffer,patern);
                            if (findword(patern,buffer)!=-1)
                            {
                                counter++;
                            }
                        }
                        fclose(filePointer);
                    }
                }
                printf("%d\n",counter);
            }
        }
        else if (strcmp(dastor,"undo")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            gindex=1;
            findadress(dastor);
            strcpy(gadress1,gadress);
            gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
            FILE *f,*fp;
            if (exists(gadress))
            {
            f=fopen(gadress1,"r");
            char undo[1000],m;
            int q=0;
            reset(undo);
            while((m=fgetc(f))!=EOF)
            {
                undo[q]=m;
                q++;
            }
            //printf("%s\n",undo);
            fclose(f);
            fp=fopen(gadress,"w");
            fputs(undo,fp);
            fclose(fp);
            }
            else
            {
                printf("does not exist\n");
            }
        }
        else if (strcmp(dastor,"auto-indent")==0)
        {
            scanf("%[^\n]%*c",dastor);
            gindex=1;
            findadress(dastor);
            char ai[1000];
            reset(ai);
            FILE *f;
            if (exists(gadress))
            {
                f=fopen(gadress,"r");
                char m;
                int q=0;
                while((m=fgetc(f))!=EOF)
                {
                    ai[q]=m;
                    q++;
                }
                strcpy(gadress1,gadress);
                gadress1[0]='t';gadress1[1]='e';gadress1[2]='m';gadress1[3]='p';
                createfile(gadress1,1);
                FILE *fp;
                fp=fopen(gadress1,"w");
                fputs(ai,fp);
                fclose(fp);
                autoin(ai);
                //printf("%s\n",undo);
                fclose(f);
                fp=fopen(gadress,"w");
                fputs(autoi,fp);
                fclose(fp);
            }
            else
            {
                printf("file does not exist");
            }
        }
        else if(strcmp(dastor,"find")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            char atfind[1000];
            reset(atfind);
            int k=findword("-file",dastor);
            if (dastor[1]=='"')
            {
                makestring(2,k-3,dastor,atfind);
            }
            else
            {
                makestring(1,k-2,dastor,atfind);
            }
            gindex=k+6;
            findadress(dastor);
            //printf("%s\n",gadress);
            char ofind[1000];
            reset(ofind);
            FILE *f;
            int mode=0;
            if (findword("-count",dastor)!=-1)
            {
                mode=mode+8;
            }
            if (findword("-at",dastor)!=-1)
            {
                mode=mode+1;
                at=adadat(findword("-at",dastor)+4,dastor);
            }
            if (findword("-byword",dastor)!=-1)
            {
                mode=mode+2;
            }
            if (findword("-all",dastor)!=-1)
            {
                mode=mode+4;
            }
            if (exists(gadress))
            {
                f=fopen(gadress,"r");
                char m;
                int q=0;
                while((m=fgetc(f))!=EOF)
                {
                    ofind[q]=m;
                    q++;
                }
                //printf("%s\n",undo);
                fclose(f);
                finalfind(ofind,atfind,mode);
                //printf("%s\n",atfind);
            }
            else
            {
                printf("file does not exist\n");
            }
        }
        else if(strcmp(dastor,"replace")==0)
        {
            scanf("%s",dastor);
            scanf("%[^\n]%*c",dastor);
            char patern[1000];
            reset(patern);
            int k=findword("-file",dastor);
            int x=findword("-str2",dastor);
            if (dastor[1]=='"')
            {
                makestring(2,x-3,dastor,patern);
            }
            else
            {
                makestring(1,x-2,dastor,patern);
            }
            gindex=k+6;
            findadress(dastor);
            //printf("%s\n",gadress);
            char oreplace[1000];
            reset(oreplace);
            FILE *f;
            int mode=0;
            if (findword("-at",dastor)!=-1)
            {
                mode=mode+1;
                at=adadat(findword("-at",dastor)+4,dastor);
            }
            if (findword("-all",dastor)!=-1)
            {
                mode=mode+2;
            }
            char attach[1000];
            if(dastor[x+6]=='"')
            {
                makestring(x+7,k-3,dastor,attach);
            }
            else
            {
                makestring(x+6,k-2,dastor,attach);
            }
            if (exists(gadress))
            {
                f=fopen(gadress,"r");
                char m;
                int q=0;
                while((m=fgetc(f))!=EOF)
                {
                    oreplace[q]=m;
                    q++;
                }

                //printf("%s\n",undo);
                fclose(f);
                finalreplace(oreplace,patern,attach,mode);
                if (flag==1)
                {
                    f=fopen(gadress,"w");
                    fputs(freplace,f);    // replace -str1 "man s*" -str2 "man mehrshad" -file /root/new.txt -all
                    //printf("%s\n",undo);
                    fclose(f);
                }
                //printf("%s\n",atfind);
            }
            else
            {
                printf("file does not exist\n");
            }
        }
        else if (strcmp(dastor,"tree")==0)
        {
            int m;
            scanf("%d",&m);
            if (m<-1)
            {
                printf("invalid omgh");
            }
            else{tree("./root/",2,m);}
        }
        else if(strcmp(dastor,"exit")==0)
        {
            break;
        }
        else if (strcmp(dastor,"compare")==0)
        {
            scanf("%[^\n]%*c",dastor);
            gindex=1;
            findadress(dastor);
            char firstadress[1000];
            reset(firstadress);
            strcpy(firstadress,gadress);
            if (exists(gadress))
            {
                findadress(dastor);
                if (exists(gadress))
                {
                    compare(firstadress,gadress);
                }
                else
                {
                    printf("file2 does not exist\n");
                }
            }
            else
            {
                printf("file1 does not exist\n");
            }
        }
        else //baraye dastoorat asli
        {
            chertgir(chert);
        }
    }
}
// testcase    createfile -file "/root/salam/man/sepehram.txt" insertstr -file "/root/new.txt" -str "salam" -pos 2:5
//insertstr -file "/root/sepi/sep.txt" -str mehrshad\nngoljarian -pos 2:5
//undo -file /root/new.txt
//cutstr –file /root/new.txt –pos 2:5 -size 3 -b
//grep -l -str "salam" -file /root/new.txt "/root/sepehr.txt"
//scanf("%[^\n]%*c,)
