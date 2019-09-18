#include <math.h>
#include <stdio.h>
int main()
{
    FILE *fin,*fout;
    fin=fopen("D:\\salesin.txt","rb");
    fout=fopen("D:\\salesout.txt","wb");
    double a,b;
    int n;
    double profit=0,loss=0;
    while(fscanf(fin,"%lf %lf %d",&a,&b,&n))
    {
        if(a==0&&b==0&&n==0)  break;
        fprintf(fout,"%.2lf %.2lf %d: ",a,b,n);
        if(b>=a)
        {
            profit+=(b-a)*n;
            fprintf(fout,"profit = %.2lf,total profit = %.2lf\r\n",(b-a)*n,profit);
        }
        else
        {
            loss+=(b-a)*n;
            fprintf(fout,"loss   = %.2lf,total loss   = %.2lf\r\n",-(b-a)*n,-loss);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
