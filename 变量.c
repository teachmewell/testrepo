#include <stdio.h>
// 每个变量都需要两部分 : declare （让电脑预定内存和把变量名字分配到数据的地址） 和 assign value（在你的内存里写数据) 
// 
// declare 语法：  <Data type> <name>; 
// 我们有4个基础 Data type:  char (1 byte) （常用为一个字母比如 's' 或 'p'）,  int （整数）, float (逗号数，不精准) , double (也是逗号数)
// java 语言还有 布林(boolean == true 或 false), 但 C 里面他就是1或0的int。
// 
// 比如: 
// char a= 'a' ;
// int b = 1234;
// float c = 1234.5; 
// double d = 1234.5; 
//
// assign value 语法:   <name> = <value>;

int main(){

  //// TODO 你在这里建立四个变量，叫 charvar , intvar , floatvar , doublevar 
    char charvar;
    int intvar;
    float floatvar;
    double doublevar;
  //// TODO 你在这里给他们设一个数字
    charvar = "Hello World!";
    intvar = 1;
    floatvar = 3.141592653589793238462;
    doublevar = 3.141592653589793238462;
  printf( "%c", charvar ); 
  printf( "%i", intvar ); 
    printf( "%f", floatvar ); 
    printf( "%lf", doublevar ); 
}
