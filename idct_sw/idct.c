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

void IDCT(int *Block){
int           m,n,x,y;
int x_t [8];
int y_t [8];
  short IDCT_coefficient[64]= 
  { 64, 64, 64, 64, 64, 64, 64, 64,
    89, 75, 50, 18 ,-18 ,-50,-75,-89,
    83, 36 ,-36 ,-83,-83,-36 , 36 , 83,
    75,-18 ,-89,-50, 50, 89, 18 ,-75,
    64,-64,-64, 64, 64,-64,-64, 64,
    50,-89, 18 , 75,-75,-18 , 89,-50,
    36 ,-83, 83,-36 ,-36 , 83,-83, 36 ,
    18 ,-50, 75,-89, 89,-75, 50,-18  };
  //================================//
  //=== END: from original IDCT   ===//
  //================================//        
              
      int index = 0;
      
      //================================//
      //=== BEGIN: from original IDCT ===//
      //================================//


      for(y=0;y<2;y++)      //IDCT_1D*2
      {
        for(x=0;x<8;x++)  //IDCT_1D
        {
          if(y==0)      //column
          {
            x_t[0]=(int)(Block[   x]); 
            x_t[1]=(int)(Block[8 +x]);
            x_t[2]=(int)(Block[16+x]);
            x_t[3]=(int)(Block[24+x]);
            x_t[4]=(int)(Block[32+x]);
            x_t[5]=(int)(Block[40+x]);
            x_t[6]=(int)(Block[48+x]);
            x_t[7]=(int)(Block[56+x]);
            //message( MX_MSG_WARNING, "%d", x_t[0] );
          }
          else          //row
          {
            x_t[0]=(int)(Block[8*x  ]);
            x_t[1]=(int)(Block[8*x+1]);
            x_t[2]=(int)(Block[8*x+2]);
            x_t[3]=(int)(Block[8*x+3]);
            x_t[4]=(int)(Block[8*x+4]);
            x_t[5]=(int)(Block[8*x+5]);
            x_t[6]=(int)(Block[8*x+6]);
            x_t[7]=(int)(Block[8*x+7]);
          }

          for(m=0;m<8;m++)
          {
            y_t[m]=0;
            for(n=0;n<8;n++)
            {
              y_t[m]=y_t[m]+(int)(IDCT_coefficient[n*8+m])*x_t[n];
              //message( MX_MSG_WARNING, "%d", y_t[m] );
              //y_t[m]=n;
            }
          }

          if(y==0)
          {
            Block[   x]=(short)((y_t[0]+64)>>7);
            Block[8 +x]=(short)((y_t[1]+64)>>7);
            Block[16+x]=(short)((y_t[2]+64)>>7);
            Block[24+x]=(short)((y_t[3]+64)>>7);
            Block[32+x]=(short)((y_t[4]+64)>>7);
            Block[40+x]=(short)((y_t[5]+64)>>7);
            Block[48+x]=(short)((y_t[6]+64)>>7);
            Block[56+x]=(short)((y_t[7]+64)>>7);
            //message( MX_MSG_WARNING, "%d", Block[x] );
          }
          else
          {
            Block[8*x  ]=(short)((y_t[0]+2048)>>12);
            Block[8*x+1]=(short)((y_t[1]+2048)>>12);
            Block[8*x+2]=(short)((y_t[2]+2048)>>12);
            Block[8*x+3]=(short)((y_t[3]+2048)>>12);
            Block[8*x+4]=(short)((y_t[4]+2048)>>12);
            Block[8*x+5]=(short)((y_t[5]+2048)>>12);
            Block[8*x+6]=(short)((y_t[6]+2048)>>12);
            Block[8*x+7]=(short)((y_t[7]+2048)>>12);
          }
        } //End IDCT_1D                   
      } //End IDCT_2D
    display(Block);
}

int main(){
	// int Data1[64];
	int Data2[64];
	int i;
  int Data1 [64] = {6120, -2040, -1224, -1224, -1224, -816, -408, -408, -1224, 408, 0, 0, 0, 0, 0, 0, -1632, 0, 0, 0, 0, 0, 0, 0, -2040, 408, 0, 0, 0, 0, 0, 0, -2040, 0, 408, 0, 0, 0, 0, 0, -1632, 0, 0, 0, 0, 0, 0, 0, -1224, 0, 0, 0, 0, 0, 0, 0, -816, 0, 0, 0, 0, 0, 0, 0};

	printf("\n -- DataIn -- \n");
	display(Data1);
	printf("\n -- IDCT -- \n");
	IDCT(Data1);
	return 0;
}
