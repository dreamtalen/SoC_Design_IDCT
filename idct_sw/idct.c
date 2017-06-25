#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const double PI = 3.14159265358979323;

void display(int *DataIn){
	int i;
	for (i = 0;i < 64;i++){
	    printf("%d ", DataIn[i]);
	    if (i%8 == 7 ) printf("\n");
	}
}

void IDCT(int *data){
  static const int c1=251 ; /* cos(pi/16)<<8 */
  static const int s1=50 ; /* sin(pi/16)<<8 */
  static const int c3=213 ; /* cos(3pi/16)<<8 */
  static const int s3=142 ; /* sin(3pi/16)<<8 */
  static const int r2c6=277; /* cos(6pi/16)*sqrt(2)<<9 */
  static const int r2s6=669;
  static const int r2=181; /* sqrt(2)<<7 */
  int i;
  int x0,x1,x2,x3,x4,x5,x6,x7,x8;
  /* Stage 4 */
  for(i=0;i<8;i++){
      x0=data[0]<<9, x1=data[1]<<7, x2=data[2],
      x3=data[3]*r2, x4=data[4]<<9, x5=data[5]*r2,
      x6=data[6], x7=data[7]<<7;
      x8=x7+x1; x1 -= x7;
      /* Stage 3 */
      x7=x0+x4; x0-=x4; x4=x1+x5; x1-=x5; x5=x3+x8; x8-=x3;
      x3=r2c6*(x2+x6);x6=x3+(-r2c6-r2s6)*x6;x2=x3+(-r2c6+r2s6)*x2;
      /* Stage 2 */
      x3=x7+x2; x7-=x2; x2=x0+x6; x0-= x6;
      x6=c3*(x4+x5);x5=(x6+(-c3-s3)*x5)>>6;x4=(x6+(-c3+s3)*x4)>>6;
      x6=c1*(x1+x8);x1=(x6+(-c1-s1)*x1)>>6;x8=(x6+(-c1+s1)*x8)>>6;
      /* Stage 1, rounding and output */
      x7+=512; x2+=512;x0+=512;x3+=512;
      *data++=(x3+x4)>>10; *data++=(x2+x8)>>10;
      *data++=(x0+x1)>>10; *data++=(x7+x5)>>10;
      *data++=(x7-x5)>>10; *data++=(x0-x1)>>10;
      *data++=(x2-x8)>>10; *data++=(x3-x4)>>10;
  }
  data -= 64;
  for(i=0;i<8;i++){
      x0=data[0]<<9, x1=data[8]<<7, x2=data[16],
      x3=data[24]*r2, x4=data[32]<<9, x5=data[40]*r2,
      x6=data[48], x7=data[56]<<7;
      x8=x7+x1; x1 -= x7;
      /* Stage 3 */
      x7=x0+x4; x0-=x4; x4=x1+x5; x1-=x5; x5=x3+x8; x8-=x3;
      x3=r2c6*(x2+x6);x6=x3+(-r2c6-r2s6)*x6;x2=x3+(-r2c6+r2s6)*x2;
      /* Stage 2 */
      x3=x7+x2; x7-=x2; x2=x0+x6; x0-= x6;
      x6=c3*(x4+x5);x5=(x6+(-c3-s3)*x5)>>6;x4=(x6+(-c3+s3)*x4)>>6;
      x6=c1*(x1+x8);x1=(x6+(-c1-s1)*x1)>>6;x8=(x6+(-c1+s1)*x8)>>6;
      /* Stage 1, rounding and output */
      x7+=512; x2+=512;x0+=512;x3+=512;
      data[0]=(x3+x4)>>11; data[8]=(x2+x8)>>11;
      data[16]=(x0+x1)>>11; data[24]=(x7+x5)>>11;
      data[32]=(x7-x5)>>11; data[40]=(x0-x1)>>11;
      data[48]=(x2-x8)>>11; data[56]=(x3-x4)>>11;
      data ++;
  }
  data -=8;
  display(data);
}

int main(){
	int Data1[64];
	int Data2[64];
	int i;
	for(i = 0;i < 64;i++){
	    Data1[i] = rand()%256 - 128;
	}
	printf("\n -- DataIn -- \n");
	display(Data1);
	printf("\n -- IDCT -- \n");
	IDCT(Data1);
	return 0;
}
