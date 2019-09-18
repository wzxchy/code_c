#include<iostream>
#include<string>
#include "stdio.h"
#include "stdlib.h"
//#include "testcpp.h"
using namespace std;
/////////////////////
typedef  unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

//位图文件头定义;
//其中不包含文件类型信息（由于结构体的内存结构决定，
//要是加了的话将不能正确读取文件信息）2
typedef struct  tagBITMAPFILEHEADER
{
    //WORD bfType;//文件类型，必须是0x424D，即字符“BM”
    DWORD bfSize;//文件大小
    WORD bfReserved1;//保留字
    WORD bfReserved2;//保留字
    DWORD bfOffBits;//从文件头到实际位图数据的偏移字节数
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;//信息头大小
    LONG biWidth;//图像宽度
    LONG biHeight;//图像高度
    WORD biPlanes;//位平面数，必须为1
    WORD biBitCount;//每像素位数
    DWORD  biCompression; //压缩类型
    DWORD  biSizeImage; //压缩图像大小字节数
    LONG  biXPelsPerMeter; //水平分辨率
    LONG  biYPelsPerMeter; //垂直分辨率
    DWORD  biClrUsed; //位图实际用到的色彩数
    DWORD  biClrImportant; //本位图中重要的色彩数
} BITMAPINFOHEADER; //位图信息头定义

typedef struct tagRGBQUAD
{
    BYTE rgbBlue; //该颜色的蓝色分量
    BYTE rgbGreen; //该颜色的绿色分量
    BYTE rgbRed; //该颜色的红色分量
    BYTE rgbReserved; //保留值
} RGBQUAD; //调色板定义

//像素信息
typedef struct tagIMAGEDATA
{
    BYTE blue;
    BYTE green;
    BYTE red;
} IMAGEDATA;
//////////////////////
void showBmpHead(BITMAPFILEHEADER pBmpHead)
{
    //printf("位图文件头:%X\n",pBmpHead.bfType);
    printf("文件大小:%X\n",pBmpHead.bfSize);
    printf("保留字_1:%X\n",pBmpHead.bfReserved1);
    printf("保留字_2:%X\n",pBmpHead.bfReserved2);
    printf("实际位图数据的偏移字节数:%X\n",pBmpHead.bfOffBits);
}
void showBmpInfo(BITMAPINFOHEADER infohead)
{
    printf("信息头长度:%X\n",infohead.biSize);
    printf("图像的宽度:%d\n",infohead.biWidth);
    printf("图像的高度:%d\n",infohead.biHeight);
    printf("颜色位数:%d\n",infohead.biBitCount);
    printf("是否压缩:%d\n",infohead.biCompression);
    printf("位图数据大小:%d\n",infohead.biSizeImage);
    printf("使用的颜色数:%d\n",infohead.biClrUsed);
    printf("图像中重要的颜色数:%d\n",infohead.biClrImportant);
}
string intTostring(int i)
{
    if(i==0)  return "0";
    string s;
    while(i>0)
    {
        int tmp=i%10;
        char c=tmp+'0';
        s=c+s;
        i/=10;
    }
    return s;
}
int main()
{
    FILE *fout;
    fout=fopen("D:\\位图数据.txt","wb");
    for(int ii=0; ii<37; ii++)
    {
        int a;
        FILE *fp;
        string s1="C:\\Users\\Administrator\\Desktop\\a\\a";
        s1=s1+intTostring(ii)+".bmp";
        char *p1=(char*)s1.data();
        cout<<p1<<endl;
        fp=fopen(p1,"rb");
        BITMAPFILEHEADER filehead;
        BITMAPINFOHEADER infohead;
        WORD bfType;
        fread(&bfType,1,sizeof(WORD),fp);
        if(bfType!=0x4d42)
        {
            cout<<"it's not bmp picture!"<<endl;
            return 0;
        }
        fread(&filehead,sizeof(filehead),1,fp);
        fread(&infohead,sizeof(infohead),1,fp);
        int w=infohead.biWidth;
        int h=infohead.biHeight;
        RGBQUAD strPla[256];
        //读取调色板
        for(int nCounti=0; nCounti<256; nCounti++)
        {
            //存储的时候，一般去掉保留字rgbReserved
            fread(&strPla[nCounti].rgbBlue,sizeof(BYTE),1,fp);
            fread(&strPla[nCounti].rgbGreen,sizeof(BYTE),1,fp);
            fread(&strPla[nCounti].rgbRed,sizeof(BYTE),1,fp);
            fread(&strPla[nCounti].rgbReserved,sizeof(BYTE),1,fp);
            //printf("%X\n",strPla[nCounti].rgbGreen);
        }

        int width,height;//图片的宽度和高度
        width=(infohead.biWidth+3)/4*4;

        BYTE n[55][55];
        BYTE tmp=0;

        for(int i=0; i<48; i++)
        {
            for(int j=0; j<48; j++)
            {
                fread(&n[i][j],sizeof(BYTE),1,fp);
            }
        }
        fprintf(fout,"{\r\n");
        for(int i=0; i<infohead.biHeight; i++)
        {
            BYTE tmp=0;
            for(int j=0; j<width; j++)
            {
                int t=7-j%8;
                if(n[i][j]<70)  tmp=tmp+(1<<t);
                if((j+1)%8==0)
                {
                    //printf("0x%02X,",tmp);
                    fprintf(fout,"0x%02X",tmp);
                    if(i!=47||j!=47) fprintf(fout,",");
                    tmp=0;
                }

            }
            fprintf(fout,"\r\n");
        }
        fprintf(fout,"},\r\n");
    }



    /*
          FILE *fpw;
          string s2="C:\\Users\\Administrator\\Desktop\\a\\a";
          s2=s2+intTostring(ii)+".bmp";
          char *p2=(char*)s2.data();
          if((fpw=fopen(p2,"wb"))==NULL)
          {
              cout<<"create the bmp file error!"<<endl;
              return NULL;
          }
          filehead.bfSize=3382;
          infohead.biWidth=48;
          infohead.biHeight=48;
          fwrite(&bfType,sizeof(WORD),1,fpw);
          fwrite(&filehead,sizeof(filehead),1,fpw);
          fwrite(&infohead,sizeof(infohead),1,fpw);
          for(int nCounti=0; nCounti<256; nCounti++)
          {
              //存储的时候，一般去掉保留字rgbReserved
              BYTE blue=strPla[nCounti].rgbBlue;
              BYTE green=strPla[nCounti].rgbGreen;
              BYTE red=strPla[nCounti].rgbRed;

              fwrite(&blue,sizeof(BYTE),1,fpw);
              fwrite(&green,sizeof(BYTE),1,fpw);
              fwrite(&red,sizeof(BYTE),1,fpw);
              fwrite(&strPla[nCounti].rgbReserved,sizeof(BYTE),1,fpw);
              //printf("%X\n",strPla[nCounti].rgbGreen);
          }
          for(int i=0; i<96; i+=2)
          {
              for(int j=0; j<96; j+=2)
              {
                  fwrite(&n[i][j],sizeof(BYTE),1,fpw);
              }
          }

          fclose(fpw);

      }


      	FILE *fpw;
      	if((fpw=fopen("C:\\Users\\Administrator\\Desktop\\ps2.bmp","wb"))==NULL)
          {
              cout<<"create the bmp file error!"<<endl;
              return NULL;
          }
      	fwrite(&bfType,sizeof(WORD),1,fpw);
      	fwrite(&filehead,sizeof(filehead),1,fpw);
      	fwrite(&infohead,sizeof(infohead),1,fpw);
          for(int nCounti=0;nCounti<256;nCounti++)
          {
                  //存储的时候，一般去掉保留字rgbReserved
              BYTE blue=strPla[nCounti].rgbBlue;
              BYTE green=strPla[nCounti].rgbGreen;
              BYTE red=strPla[nCounti].rgbRed;

              fwrite(&blue,sizeof(BYTE),1,fpw);
              fwrite(&green,sizeof(BYTE),1,fpw);
              fwrite(&red,sizeof(BYTE),1,fpw);
              fwrite(&strPla[nCounti].rgbReserved,sizeof(BYTE),1,fpw);
      			//printf("%X\n",strPla[nCounti].rgbGreen);
          }
          BYTE p=0;
          for(int i=0;i<infohead.biHeight*width;i++)
          {
              fwrite(&n[i],sizeof(BYTE),1,fpw);
              //cout<<in[i]<<endl;
          }
          fclose(fpw);
          while(cin>>a)
          {
      		showBmpHead(filehead);
      		showBmpInfo(infohead);
      	}
      	*/
    return 0;
}
