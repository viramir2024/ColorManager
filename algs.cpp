//---------------------------------------------------------------------------

#pragma hdrstop
 #include "main.h"
#include "algs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

 double Trim(double value)
{
if (value<0)
return 0;
if (value>255)
return 255;
return value;
}


float linearRGB_from_sRGB(float v)
{
if (Form1->rad->ItemIndex==0) return v;


	float fv = v / 255.f;
	if (fv < 0.04045f) return fv / 12.92f;
	return powf((fv + 0.055f) / 1.055f, 2.4f);
}

float sRGB_from_linearRGB(float v)
{
if (Form1->rad->ItemIndex==0) return v;


	if (v <= 0.f) return 0;
	if (v >= 1.f) return 255;
	if (v < 0.0031308f) return 0.5f + (v * 12.92 * 255.f);
	return 0.f + 255.f * (powf(v, 1.f / 2.4f) * 1.055f - 0.055f);
}

TBitmap* Filter(TBitmap* in,double m[3][3])
{
 TBitmap* bmp=new TBitmap();
	bmp->Assign(in);
        RGBTRIPLE*ptr;
for(int y = 0; y < bmp->Height; y++)
{
ptr = (RGBTRIPLE*)bmp->ScanLine[y];
for (int x = 0; x < bmp->Width; x++)
{
double  r,g ,b;
r= linearRGB_from_sRGB(ptr[x].rgbtRed);
g= linearRGB_from_sRGB(ptr[x].rgbtGreen);
b= linearRGB_from_sRGB(ptr[x].rgbtBlue);
double   r1,g1,b1;

r1=r*m[0][0]+g*m[0][1]+b*m[0][2];
g1=r*m[1][0]+g*m[1][1]+b*m[1][2];
b1=r*m[2][0]+g*m[2][1]+b*m[2][2];
ptr[x].rgbtRed=Trim(sRGB_from_linearRGB(r1));
ptr[x].rgbtGreen=Trim(sRGB_from_linearRGB(g1));
ptr[x].rgbtBlue=Trim(sRGB_from_linearRGB(b1));
}
}
return bmp;
}


 RGBTRIPLE LMS(RGBTRIPLE in,double m[3][3])
 {
  RGBTRIPLE res;
float r,g,b;
  r=linearRGB_from_sRGB(in.rgbtRed);
  g=linearRGB_from_sRGB(in.rgbtGreen);
  b=linearRGB_from_sRGB(in.rgbtBlue);
   float L = r * 0.31399022 + g * 0.63951294 + b * 0.04649755;
   float M = r * 0.15537241 + g * 0.75789446+ b *  0.08670142;
   float S = r * 0.01775239 + g * 0.10944209+ b * 0.87256922;
float L1=L*m[0][0]+M*m[0][1]+S*m[0][2];
float M1=L*m[1][0]+M*m[1][1]+S*m[1][2];
float S1=L*m[2][0]+M*m[2][1]+S*m[2][2];
double r2=L1 * 5.47221206 + M1 *-4.6419601  + S1 *0.16963708 ;
double g2=L1 * -1.1252419 + M1 * 2.29317094  + S1 *-0.1678952;
double b2=L1 * 0.02980165 + M1 * -0.19318073   + S1 *1.16364789;
res.rgbtRed=Trim(sRGB_from_linearRGB(r2));
res.rgbtGreen=Trim(sRGB_from_linearRGB(g2));
res.rgbtBlue=Trim(sRGB_from_linearRGB(b2));
return res;
 }

 RGBTRIPLE UniversalModel(RGBTRIPLE in,int mode)
  {
double PMat[3][3]={
{0,1.05118294,-0.05116099},
{0,1,0},
{0,0,1 }
};
 double DMat[3][3]={
{1,0,0},
{0.9513092,0,0.04866992},
{0,0,1 }
};
 double TMat[3][3]={
{1,0,0},
{0,1,0},
{-0.86744736,1.86727089,0 }
};
   if (mode==1) return LMS(in,PMat);
else if (mode==2) return LMS(in,DMat);
else if (mode==3) return LMS(in,TMat);
  }

  
TBitmap* UniImage(TBitmap* in,int type)
{          TBitmap* bmp=new TBitmap();
bmp->Assign(in);
RGBTRIPLE*ptr;
for(int y = 0; y < bmp->Height; y++)
{
ptr = (RGBTRIPLE*)bmp->ScanLine[y];
for (int x = 0; x < bmp->Width; x++)
{
RGBTRIPLE pix;
pix=ptr[x];
ptr[x]=UniversalModel(pix,type);
}
}
return bmp;
}








