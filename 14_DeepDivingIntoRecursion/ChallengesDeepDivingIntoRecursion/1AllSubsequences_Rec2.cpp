//All Subsequences

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[100][100];
int k=0;
void subsequences(char input[],char output[],int i,int j)
{
    ///Base Case
    if(input[i]=='\0')
    {
            output[j]='\0';
            int l=0;
            for(int m=0;output[m]!='\0';m++)
            {
               ch[k][l]=output[m];
               l++;
            }
            ch[k][l]='\0';
            k++;
            return;
        }

    output[j]=input[i];
    subsequences(input,output,i+1,j+1);
    subsequences(input,output,i+1,j);
}
int main ()
{
    char input[100],output[100];
    int m,n;
    cin>>m;
    for(n=1;n<=m;n++)
   {
       cin>>input;
    subsequences(input,output,0,0);
    for(int i=0;i<k;i++)
    {
        for(int j=0;ch[i][j]!='\0';j++)
       {
             if (strcmp(ch[j],ch[j + 1]) > 0)
                {
                char temp[100];
                strcpy(temp,ch[j]);
                strcpy(ch[j],ch[j + 1]);
                strcpy(ch[j + 1], temp);
             }
        }
    }
    for(int j=0;ch[k-1][j]!='\0';j++)
        cout<<ch[k-1][j];
    cout<<endl;
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;ch[i][j]!='\0';j++)
       {
        cout<<ch[i][j];
       }
       cout<<endl;
    }
    k=0;
}
}

