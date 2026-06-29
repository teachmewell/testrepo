#include <stdio.h>
#include <stdlib.h>

void display(int field[], int steps);
int addElement(int field[]);
int getposofnum(int num);
int newnum(int range);
void goup(int field[]);
void godown(int field[]);
void goleft(int field[]);
void goright(int field[]);
void gouprec(int field[], int tochange, int amountperchange);
void godownrec(int field[], int tochange, int amountperchange);
void gorightrec(int field[], int tochange, int amountperchange);
void goleftrec(int field[], int tochange, int amountperchange);

//所有C 程序都从int main() 开始
int main(){
int steps = 0;

//设一个array
//int field[4][4]= {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
int field[16]= {0};
  // print
printf("enter one of: s, x, z, y ， u, d, l, r");

// 得到输入  上下左右
char text;
while(1) {
  display(field, steps);
while(1){
scanf(" %c", &text);
if( text == 's' || text == 'u' ){ goup(field); break;}
else if( text == 'x' || text == 'd'){godown(field); break;}
else if( text == 'z' || text == 'l'){goleft(field); break;}
else if( text == 'y' || text == 'r'){goright(field); break;}
else{printf("failed. Write one of: s, x, z, y ， u, d, l, r. \n");}
}
  if(!addElement(field)){break;}
    steps++;
}
  printf("\n failed after %i steps. \n", steps);
  return 1;
}

int addElement(int field[]){
  int res = 0;
int biggest = 2;
  int indexes[16]= {0};
  for(int i=0; i<16; i++){
if(field[i]> biggest){biggest= field[i];}
    if(field[i]== 0){ indexes[res]=i; res++;}
  }
if(res==0){return 0;}

 int k = rand() % res;
  field[ indexes[k] ] = newnum( getposofnum(biggest) );
  return 1;
}

int getposofnum(int num){
int pos=0;
while(1){
if((num%2) == 1 ){return pos;}
else{num = num>>1; pos++;}
}
}

int newnum(int range){
int shifts = (rand() % range);
return 1<< shifts;
}

void display(int field[], int steps){
  printf("\n after %i steps : \n", steps);
    for(int a = 0; a < 13; a=a+4){
      printf("%4i ", field[a]);
      printf("%4i ",field[a+1]);
      printf("%4i ",field[a+2]);
      printf("%4i ",field[a+3]);
      printf("\n");
    }
}
void goup(int field[]){
int amountperchange = -4;
for(int i=0; i<15; i++){gouprec(field, i, amountperchange); }
}

void gouprec(int field[], int tochange, int amountperchange){
if(tochange < 4 || tochange > 15){return;}
else if(field[tochange] == 0){  return; }

if(field[tochange + amountperchange]==0){
field[tochange + amountperchange] = field[tochange];
field[tochange]=0;
tochange = tochange+amountperchange;
gouprec(field, tochange, amountperchange); return; }

if(field[tochange+ amountperchange] == field[tochange]){
field[tochange + amountperchange] = field[tochange + amountperchange]<<1;
  field[tochange]=0;
tochange = tochange + amountperchange;
gouprec(field, tochange, amountperchange); return;}

}


void godown(int field[]) {
int amountperchange = 4;
for(int i=15; i>=0; i=i-1){godownrec(field, i, amountperchange); }
}

void godownrec(int field[], int tochange, int amountperchange){
if(tochange < 0 || tochange > 11){return;}
else if(field[tochange] == 0){  return; }

if(field[tochange + amountperchange]==0){
field[tochange + amountperchange] = field[tochange];
field[tochange]=0;
tochange = tochange+amountperchange;
godownrec(field, tochange, amountperchange); return; }

if(field[tochange+ amountperchange] == field[tochange]){
field[tochange + amountperchange] = field[tochange + amountperchange]<<1;
  field[tochange]=0;
tochange = tochange + amountperchange;
godownrec(field, tochange, amountperchange); return;}

}

void goright(int field[]){
int amountperchange = 1;

for(int i=15; i>=0; i=i-1){gorightrec(field, i, amountperchange);}
}

void gorightrec(int field[], int tochange, int amountperchange){
if(tochange == 3 || tochange == 7 || tochange == 11 || tochange == 15){return;}
else if(field[tochange] == 0){  return; }

if(field[tochange + amountperchange]==0){
field[tochange + amountperchange] = field[tochange];
field[tochange]=0;
tochange = tochange+amountperchange;
gorightrec(field, tochange, amountperchange); return; }

if(field[tochange+ amountperchange] == field[tochange]){
field[tochange + amountperchange] = field[tochange + amountperchange]<<1;
  field[tochange]=0;
tochange = tochange + amountperchange;
gorightrec(field, tochange, amountperchange); return;}


}

void goleft(int field[]){
int amountperchange = -1;

for(int i=0; i<16; i++){goleftrec(field, i, amountperchange);}
}

void goleftrec(int field[], int tochange, int amountperchange){
if(tochange == 0 || tochange == 4 || tochange == 8 || tochange == 12){return;}
else if(field[tochange] == 0){  return; }

if(field[tochange + amountperchange]==0){
field[tochange + amountperchange] = field[tochange];
field[tochange]=0;
tochange = tochange+amountperchange;
goleftrec(field, tochange, amountperchange); return; }

if(field[tochange+ amountperchange] == field[tochange]){
field[tochange + amountperchange] = field[tochange + amountperchange]<<1;
  field[tochange]=0;
tochange = tochange + amountperchange;
goleftrec(field, tochange, amountperchange); return;}

}
