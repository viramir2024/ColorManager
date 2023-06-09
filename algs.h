//---------------------------------------------------------------------------

#ifndef algsH
#define algsH
#include <vcl.h>



static	struct MCoblis_v1
{
double pr[3][3]= {{0.567, 0.433, 0.000},
								 {0.558, 0.442, 0.000},
								 {0.000, 0.242, 0.758}};
  double dt[3][3]=   {{0.625, 0.375, 0.000},
								 {0.700, 0.300, 0.000},
								 {0.000, 0.300, 0.700}} ;

  double tn  [3][3]= {{0.950,0.050,0.000},
								 {0.000, 0.433, 0.567},
								 {0.000, 0.475, 0.525}} ;

	  }coblisv1;



  static struct MVienot
	  {
  double pr[3][3]={{0.11238, 0.88762, 0.00000},
			{  0.11238, 0.88762, -0.00000,},
			{0.00401, -0.00401, 1.00000}};
  double dt[3][3]={{ 0.29275, 0.70725, 0.00000,},
			{0.29275, 0.70725, -0.00000} ,
			{ -0.02234, 0.02234, 1.00000}};


  double tn  [3][3]={{ 1.00000, 0.14461, -0.14461},
	 {0.00000, 0.85924, 0.14076},
	 {-0.00000, 0.85924, 0.14076}
   };

	  }vienot;


static struct MLinear
{
double pr[3][3]  =  {
			{0.202001295331, 0.991720719265, -0.193722014597},
			{0.163800203026, 0.792663865514, 0.0435359314602},
			{0.00913336570448, -0.0132684300993, 1.00413506439}
		};

double dt[3][3]= {
			{0.430749076295, 0.717402505462, -0.148151581757},
			{0.336582831043, 0.574447762213, 0.0889694067435},
			{-0.0236572929497, 0.0275635332006, 0.996093759749}
		};

double tn[3][3]=     {
			{0.971710712275, 0.112392320487, -0.0841030327623},
			{0.0219508442818, 0.817739672383, 0.160309483335},
			{-0.0628595877201, 0.880724870686, 0.182134717034}
		};

}linear;
 static  double mono[3][3]={
   {0.3,0.59,0.11} ,
   {0.3,0.59,0.11},
   {0.3,0.59,0.11} };
  static struct MMachado
{
double pr[3][3]  =
{
 {0.152286, 1.052583, -0.204868},
 {0.114503, 0.786281, 0.099216},
 {-0.003882, -0.048116, 1.051998},
 };

 double dt[3][3]=
   {
{0.367322, 0.860646, -0.227968},
{0.280085, 0.672501, 0.047413},
{-0.011820, 0.042940, 0.968881},
};

double tn[3][3]=
{
{1.255528, -0.076749, -0.178779},
{-0.078411, 0.930809, 0.147602},
{0.004733, 0.691367, 0.303900},
};
}machado;

double Trim(double value);
float linearRGB_from_sRGB(float v);
float sRGB_from_linearRGB(float v);
TBitmap* Filter(TBitmap* in,double m[3][3]);
RGBTRIPLE LMS(RGBTRIPLE in,double m[3][3]);
RGBTRIPLE UniversalModel(RGBTRIPLE in,int mode);
  TBitmap* UniImage(TBitmap* in,int type);

//---------------------------------------------------------------------------
#endif
