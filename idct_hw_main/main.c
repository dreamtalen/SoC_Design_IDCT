#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <rt_misc.h>
#define BASEADDR 0x10000000


volatile const int* r_status=(int*)(BASEADDR);
volatile int* const r_ctrl=(int*)(BASEADDR+8);
volatile int* const  r_reg0 =(int*)(BASEADDR+16);
volatile int* const  r_reg1 =(int*)(BASEADDR+24);
volatile int* const  r_reg2 =(int*)(BASEADDR+32);
volatile int* const  r_reg3 =(int*)(BASEADDR+40);
volatile int* const  r_reg4 =(int*)(BASEADDR+48);
volatile int* const  r_reg5 =(int*)(BASEADDR+56);
volatile int* const  r_reg6 =(int*)(BASEADDR+64);
volatile int* const  r_reg7 =(int*)(BASEADDR+72);
volatile int* const  r_reg8 =(int*)(BASEADDR+80);
volatile int* const  r_reg9 =(int*)(BASEADDR+88);
volatile int* const  r_reg10=(int*)(BASEADDR+96);
volatile int* const  r_reg11=(int*)(BASEADDR+104);
volatile int* const  r_reg12=(int*)(BASEADDR+112);
volatile int* const  r_reg13=(int*)(BASEADDR+120);
volatile int* const  r_reg14=(int*)(BASEADDR+128);
volatile int* const  r_reg15=(int*)(BASEADDR+136);
volatile int* const  r_reg16=(int*)(BASEADDR+144);
volatile int* const  r_reg17=(int*)(BASEADDR+152);
volatile int* const  r_reg18=(int*)(BASEADDR+160);
volatile int* const  r_reg19=(int*)(BASEADDR+168);
volatile int* const  r_reg20=(int*)(BASEADDR+176);
volatile int* const  r_reg21=(int*)(BASEADDR+184);
volatile int* const  r_reg22=(int*)(BASEADDR+192);
volatile int* const  r_reg23=(int*)(BASEADDR+200);
volatile int* const  r_reg24=(int*)(BASEADDR+208);
volatile int* const  r_reg25=(int*)(BASEADDR+216);
volatile int* const  r_reg26=(int*)(BASEADDR+224);
volatile int* const  r_reg27=(int*)(BASEADDR+232);
volatile int* const  r_reg28=(int*)(BASEADDR+240);
volatile int* const  r_reg29=(int*)(BASEADDR+248);
volatile int* const  r_reg30=(int*)(BASEADDR+256);
volatile int* const  r_reg31=(int*)(BASEADDR+264);
volatile int* const  r_reg32=(int*)(BASEADDR+272);
volatile int* const  r_reg33=(int*)(BASEADDR+280);
volatile int* const  r_reg34=(int*)(BASEADDR+288);
volatile int* const  r_reg35=(int*)(BASEADDR+296);
volatile int* const  r_reg36=(int*)(BASEADDR+304);
volatile int* const  r_reg37=(int*)(BASEADDR+312);
volatile int* const  r_reg38=(int*)(BASEADDR+320);
volatile int* const  r_reg39=(int*)(BASEADDR+328);
volatile int* const  r_reg40=(int*)(BASEADDR+336);
volatile int* const  r_reg41=(int*)(BASEADDR+344);
volatile int* const  r_reg42=(int*)(BASEADDR+352);
volatile int* const  r_reg43=(int*)(BASEADDR+360);
volatile int* const  r_reg44=(int*)(BASEADDR+368);
volatile int* const  r_reg45=(int*)(BASEADDR+376);
volatile int* const  r_reg46=(int*)(BASEADDR+384);
volatile int* const  r_reg47=(int*)(BASEADDR+392);
volatile int* const  r_reg48=(int*)(BASEADDR+400);
volatile int* const  r_reg49=(int*)(BASEADDR+408);
volatile int* const  r_reg50=(int*)(BASEADDR+416);
volatile int* const  r_reg51=(int*)(BASEADDR+424);
volatile int* const  r_reg52=(int*)(BASEADDR+432);
volatile int* const  r_reg53=(int*)(BASEADDR+440);
volatile int* const  r_reg54=(int*)(BASEADDR+448);
volatile int* const  r_reg55=(int*)(BASEADDR+456);
volatile int* const  r_reg56=(int*)(BASEADDR+464);
volatile int* const  r_reg57=(int*)(BASEADDR+472);
volatile int* const  r_reg58=(int*)(BASEADDR+480);
volatile int* const  r_reg59=(int*)(BASEADDR+488);
volatile int* const  r_reg60=(int*)(BASEADDR+496);
volatile int* const  r_reg61=(int*)(BASEADDR+504);
volatile int* const  r_reg62=(int*)(BASEADDR+512);
volatile int* const  r_reg63=(int*)(BASEADDR+520);



void display(int *DataIn){
	int i;
	for (i = 0;i < 64;i++){
	    printf("%d ", data[i]);
	    if (i%8 == 7 ) printf("\n");
	}
}

int main(){
	int Data1[64];
	int data[64];
	int i;
	for(i = 0;i < 64;i++){
	    Data1[i] = rand()%256 - 128;
	}
	printf("\n -- DataIn -- \n");
	display(Data1);
    *r_reg0 = Data1[0];
    *r_reg1 = Data1[1];
    *r_reg2 = Data1[2];
    *r_reg3 = Data1[3];
    *r_reg4 = Data1[4];
    *r_reg5 = Data1[5];
    *r_reg6 = Data1[6];
    *r_reg7 = Data1[7];
    *r_reg8 = Data1[8];
    *r_reg9 = Data1[9];
    *r_reg10 = Data1[10];
    *r_reg11 = Data1[11];
    *r_reg12 = Data1[12];
    *r_reg13 = Data1[13];
    *r_reg14 = Data1[14];
    *r_reg15 = Data1[15];
    *r_reg16 = Data1[16];
    *r_reg17 = Data1[17];
    *r_reg18 = Data1[18];
    *r_reg19 = Data1[19];
    *r_reg20 = Data1[20];
    *r_reg21 = Data1[21];
    *r_reg22 = Data1[22];
    *r_reg23 = Data1[23];
    *r_reg24 = Data1[24];
    *r_reg25 = Data1[25];
    *r_reg26 = Data1[26];
    *r_reg27 = Data1[27];
    *r_reg28 = Data1[28];
    *r_reg29 = Data1[29];
    *r_reg30 = Data1[30];
    *r_reg31 = Data1[31];
    *r_reg32 = Data1[32];
    *r_reg33 = Data1[33];
    *r_reg34 = Data1[34];
    *r_reg35 = Data1[35];
    *r_reg36 = Data1[36];
    *r_reg37 = Data1[37];
    *r_reg38 = Data1[38];
    *r_reg39 = Data1[39];
    *r_reg40 = Data1[40];
    *r_reg41 = Data1[41];
    *r_reg42 = Data1[42];
    *r_reg43 = Data1[43];
    *r_reg44 = Data1[44];
    *r_reg45 = Data1[45];
    *r_reg46 = Data1[46];
    *r_reg47 = Data1[47];
    *r_reg48 = Data1[48];
    *r_reg49 = Data1[49];
    *r_reg50 = Data1[50];
    *r_reg51 = Data1[51];
    *r_reg52 = Data1[52];
    *r_reg53 = Data1[53];
    *r_reg54 = Data1[54];
    *r_reg55 = Data1[55];
    *r_reg56 = Data1[56];
    *r_reg57 = Data1[57];
    *r_reg58 = Data1[58];
    *r_reg59 = Data1[59];
    *r_reg60 = Data1[60];
    *r_reg61 = Data1[61];
    *r_reg62 = Data1[62];
    *r_reg63 = Data1[63];


	printf("\n -- IDCT1 -- \n");
	while(*r_status);
	*r_ctrl = 1;
	data[0]  =  *r_reg0;
    data[1]  =  *r_reg1;
    data[2]  =  *r_reg2;
    data[3]  =  *r_reg3;
    data[4]  =  *r_reg4;
    data[5]  =  *r_reg5;
    data[6]  =  *r_reg6;
    data[7]  =  *r_reg7;
    data[8]  =  *r_reg8;
    data[9]  =  *r_reg9;
    data[10] =  *r_reg10;
    data[11] =  *r_reg11;
    data[12] =  *r_reg12;
    data[13] =  *r_reg13;
    data[14] =  *r_reg14;
    data[15] =  *r_reg15;
    data[16] =  *r_reg16;
    data[17] =  *r_reg17;
    data[18] =  *r_reg18;
    data[19] =  *r_reg19;
    data[20] =  *r_reg20;
    data[21] =  *r_reg21;
    data[22] =  *r_reg22;
    data[23] =  *r_reg23;
    data[24] =  *r_reg24;
    data[25] =  *r_reg25;
    data[26] =  *r_reg26;
    data[27] =  *r_reg27;
    data[28] =  *r_reg28;
    data[29] =  *r_reg29;
    data[30] =  *r_reg30;
    data[31] =  *r_reg31;
    data[32] =  *r_reg32;
    data[33] =  *r_reg33;
    data[34] =  *r_reg34;
    data[35] =  *r_reg35;
    data[36] =  *r_reg36;
    data[37] =  *r_reg37;
    data[38] =  *r_reg38;
    data[39] =  *r_reg39;
    data[40] =  *r_reg40;
    data[41] =  *r_reg41;
    data[42] =  *r_reg42;
    data[43] =  *r_reg43;
    data[44] =  *r_reg44;
    data[45] =  *r_reg45;
    data[46] =  *r_reg46;
    data[47] =  *r_reg47;
    data[48] =  *r_reg48;
    data[49] =  *r_reg49;
    data[50] =  *r_reg50;
    data[51] =  *r_reg51;
    data[52] =  *r_reg52;
    data[53] =  *r_reg53;
    data[54] =  *r_reg54;
    data[55] =  *r_reg55;
    data[56] =  *r_reg56;
    data[57] =  *r_reg57;
    data[58] =  *r_reg58;
    data[59] =  *r_reg59;
    data[60] =  *r_reg60;
    data[61] =  *r_reg61;
    data[62] =  *r_reg62;
    data[63] =  *r_reg63;
    display(data);
	return 0;
}
