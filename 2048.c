//______________________________________________________这里利用了C语言的基础图书馆 (standard library), 她给我们提供像 printf 的公式。_____________
#include <stdio.h>
#include <stdlib.h>

//_____________________________________________________________________当前不重要。这里写着我所有想在未来用的公示名_________________________
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

//____________________________________________________________________________________所有C语言从 int main() function 开头。_____________
// ______________________________________________________________________________想知道跑的时候发生什么就从这里开头。________________

//所有C 程序都从int main() 开始
int main(){
int steps = 0;

//___________________________________________________________________________________________________________设一个array
//int field[4][4]= {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
int field[16]= {0};
  // print
printf("enter one of: s, x, z, y ， u, d, l, r");

// _________________________________________________________________________________________得到输入  上下左右
char text;
while(1) {
  display(field, steps);
while(1){

  //____________________________________________________________________________scanf : 读一个 char。
scanf(" %c", &text);

  //________________________________________________________________________________________如果是其中一个，那就跑他的function
if( text == 's' || text == 'u' ){ goup(field); break;}
else if( text == 'x' || text == 'd'){godown(field); break;}
else if( text == 'z' || text == 'l'){goleft(field); break;}
else if( text == 'y' || text == 'r'){goright(field); break;}

//  ___________________________________________________________________________________________________若输入不符合要求: 让 while 从新输入。
else{printf("failed. Write one of: s, x, z, y ， u, d, l, r. \n");}
}


  
  if(!addElement(field)){break;}
    steps++;
}
  printf("\n failed after %i steps. \n", steps);
  return 1;
}


// ___________________________________________________________________________以下是我的functions，定义我在main里写的东西。___________________________________

// _____________________________________________________function 1: add Element
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

//______________________________________________________________function 1: get index of 1 
int getposofnum(int num){
int pos=0;
while(1){
if((num%2) == 1 ){return pos;}
else{num = num>>1; pos++;}
}
}

//________________________________________________________________________ random number 
int newnum(int range){
int shifts = (rand() % range);
return 1<< shifts;
}

//_________________________________________________________________________ 我所有的 printf 
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

//___________________________________________________________________________________________________以下是我所有改变 array 的公式。
//________________________________________________________________________________________ go up : input = array 的地址， 它给array每个数字都单独叫 gouprec 。
void goup(int field[]){
int amountperchange = -4;
for(int i=0; i<15; i++){gouprec(field, i, amountperchange); }
}

//________________________________________________________________________________________ go up rec: tochange是arraz中你想要改变的数字。
void gouprec(int field[], int tochange, int amountperchange){

  //_____________________________________________________________________________如果数字出需要考虑的范围（边上或 array 外面）
if(tochange < 4 || tochange > 15){return;}

  //_______________________________________________________________________________如果tochange 数据是0 (就是没数据情况)， 那就不需要在改了。
else if(field[tochange] == 0){  return; }

  ///___________________________________________________________________________________如果它旁边的格子是空的，把数字移到旁边，在查看旁边是否还能移 
if(field[tochange + amountperchange]==0){
field[tochange + amountperchange] = field[tochange];
field[tochange]=0;
tochange = tochange+amountperchange;
gouprec(field, tochange, amountperchange); return; }

  //______________________________________________________________________________如果旁边和自己一样，那把旁边的格子 *2 和把自己格子变成 0
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
