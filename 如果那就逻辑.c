#include <stdio.h>
// 语法: if( 如果 ) { 那就 }

// 为了查看两个数字是否是一样的，可以用  == 。
// 还有 <, >, <= , >= 

//比如:  if( a == b ) {int c = a+b;}

// c机器里面会把 == 翻译成 0 或 1 。

int main(){

  int a = 1; 
  int b = 2; 
  
  //所以这都行 : 
  if( a == 1) { printf(" a is 1 "); }
  if( a < b) { printf(" a smaller b "); }
  if( a < (2+1) ) { printf(" a smaller 2 "); }
int c = (b==2);

  printf("%i", c);
}
