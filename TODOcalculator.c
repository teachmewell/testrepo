#include <stdio.h> // include <stdio> (standard in out) 包含了我们的 printf 和 scanf

// 建一个计算机
int main(){

  // 建立两个int 和一个char 。目的是有这样的输入 : <int> <空格> <char> <空格> <int> 而 得到他们的计算方式。 
int a;
  char operation;
  int b;
  
printf("获取输入"); // 语法: printf( "String" )  // 你想写的文字。 如果你想 printf 变量, 语法是 : printf( "format specifier", 变量地址)
  
  //scanf() 语法 : scanf( " Format specifier ", 把用户的输入进的地址 );  // format specifier: https://www.w3schools.com/c/c_data_types.php  // 地址 = pointer
scanf( "%i %c %i", &a , &b, &c );

  // TODO 你现在有用户的输入，需要写后续的逻辑。 
  
}
