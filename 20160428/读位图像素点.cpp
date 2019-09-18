#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include<fstream>
//#include "testcpp.h"
using namespace std;
/////////////////////
typedef  unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

//位图文件头定义;
//其中不包含文件类型信息（由于结构体的内存结构决定，
//要是加了的话将不能正确读取文件信息）
typedef struct  tagBITMAPFILEHEADER{
	//WORD bfType;//文件类型，必须是0x424D，即字符“BM”
	DWORD bfSize;//文件大小
	WORD bfReserved1;//保留字
	WORD bfReserved2;//保留字
	DWORD bfOffBits;//从文件头到实际位图数据的偏移字节数
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
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
}BITMAPINFOHEADER; //位图信息头定义

typedef struct tagRGBQUAD{
	BYTE rgbBlue; //该颜色的蓝色分量
	BYTE rgbGreen; //该颜色的绿色分量
	BYTE rgbRed; //该颜色的红色分量
	BYTE rgbReserved; //保留值
}RGBQUAD;//调色板定义

//像素信息
typedef struct tagIMAGEDATA
{
	BYTE blue;
	BYTE green;
	BYTE red;
}IMAGEDATA;
//////////////////////
void showBmpHead(BITMAPFILEHEADER pBmpHead){
	//printf("位图文件头:%X\n",pBmpHead.bfType);
	printf("文件大小:%X\n",pBmpHead.bfSize);
	printf("保留字_1:%X\n",pBmpHead.bfReserved1);
	printf("保留字_2:%X\n",pBmpHead.bfReserved2);
	printf("实际位图数据的偏移字节数:%X\n",pBmpHead.bfOffBits);
}
void showBmpInfo(BITMAPINFOHEADER infohead){
	printf("信息头长度:%X\n",infohead.biSize);
	printf("图像的宽度:%d\n",infohead.biWidth);
	printf("图像的高度:%d\n",infohead.biHeight);
	printf("颜色位数:%d\n",infohead.biBitCount);
	printf("是否压缩:%d\n",infohead.biCompression);
	printf("位图数据大小:%d\n",infohead.biSizeImage);
	printf("使用的颜色数:%d\n",infohead.biClrUsed);
	printf("图像中重要的颜色数:%d\n",infohead.biClrImportant);
}
int main()
{
	int a;
	FILE *fp;
	fp=fopen("C:\\Users\\Administrator\\Desktop\\ps.bmp","rb");
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
	//cout<<"w  "<<w<<endl;
	//cout<<"h  "<<h<<endl;
	RGBQUAD strPla[256];
	//读取调色板
    for(int nCounti=0;nCounti<256;nCounti++)
    {
        //存储的时候，一般去掉保留字rgbReserved
        fread(&strPla[nCounti].rgbBlue,sizeof(BYTE),1,fp);
        fread(&strPla[nCounti].rgbGreen,sizeof(BYTE),1,fp);
        fread(&strPla[nCounti].rgbRed,sizeof(BYTE),1,fp);
        fread(&strPla[nCounti].rgbReserved,sizeof(BYTE),1,fp);
        //printf("%X\n",strPla[nCounti].rgbGreen);
    }
    for(int i=0;i<256;i++)
    {
        printf("%d %d %d\n",strPla[i].rgbGreen,strPla[i].rgbBlue,strPla[i].rgbRed);
    }

    int width,height;//图片的宽度和高度
    width=(infohead.biWidth+3)/4*4;
    IMAGEDATA *imgdata=new IMAGEDATA[infohead.biHeight*width];
    BYTE *n=new BYTE[infohead.biHeight*width];
    for(int i=0;i<infohead.biHeight*width;i++)
    {
		fread(&n[i],sizeof(BYTE),1,fp);

		//printf("%d %d\n",i,n[i]);
    }
	fclose(fp);


	ofstream ofile;
	ofile.open("C:\\Users\\Administrator\\Desktop\\ttt.txt");

    for(int i=0;i<infohead.biHeight*width;i++)
    {
        ofile<<i/width<<' '<<i%width<<' '<<(int)n[i]<<endl;
        //n[i]=max(n[i],0);
        //if(n[i]==0)   printf("pDC->SetPixel(%d,%d,color);\n",i%width,i/width);
        //if((i/width<30)&&(i%width<30))
        //ofile<<"pDC->SetPixel("<<i/width<<","<<i%width<<","<<"RGB("<<(int)n[i]<<","<<(int)n[i]<<","<<(int)n[i]<<")"<<");"<<endl;
        //fprintf(fout,"pDC->SetPixel(%d,%d,RGB(%d,%d,%d),);\r\n",i/width,i%infohead.biHeight,n[i],n[i],n[i]);
    }
    ofile.close();

	return 0;
}
