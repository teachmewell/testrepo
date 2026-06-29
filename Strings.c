#include <stdio.h>

char* myString();
void cypher(char* input);

int main(){
//你在 变量.c 中把 char 定为 "Hello World" - 在 gcc 里会出问题的。
// 一个char 有 1 byte （8 个 0或1）， 无法写出 Hello World 那么长的文字。
// 所以你看到的char 是一个从 0-127 数字 ， 由 ascii 表格来翻译成字母。
// 这也意味着你在任何char上可以做数学改变。 比如 'a'+1 会变成 'b' 。

// 不像别的语言，c 没有 String。 C 里的 String 用一串 char 模拟，就是在内存里的array。

// 当你固定一个array 时，所有array 部分都保存在一起， 比如
// int myString[] = {"String"};
//
//
// 在内存里是这个样子: 
// adress = a (某个内存地址), value = (int) 'S';  
// adress = a +1 , value = (int) 't';  
// adress = a +2 , value = (int) 'r';  
// adress = a +3 , value = (int) 'i';  
// adress = a +4 , value = (int) 'n';  
// adress = a +5 , value = (int) 'g';  
// adress = a +6 , value = (int) '\0';  
//
// 你的string如果仅有他的字母的话， 读String 的时候电脑不知道该啥时候结束。 所以所有string 都必须多一个 \0 符号， 让电脑知道我们的 String 在那里结束。
// 而这也代表所有 String 的 大小是他的字母长度+1 。

//所以 int myString[6]; myString = "String"; 会出错。

  // 想改变String 和改变array 一样:  string[0] = 'A'; 就把string的开头改成 'A' 
 
 char* myString = createString();
  printf(" myString created by createString(): %s \n ", myString);

  cypher(myString);
  printf("myString after the cypher : %s \n" , myString);
}

//___________________________________________________________________________________________________________________

char* createString(){

  //TODO: 建立一个String. 

  return ; // 把你String 的pointer 写道 return 后面。
}

//______________________________________________________________________________________________________________
void cypher( char* input ){

// TODO: input 是一个String 的 Pointer。  把每个char 都变成 拉丁字母 后的 第3个。 
  // 比如 a -> d , B -> E, Y -> B  // 你在网上查一下ASCII 表格， A 不在 z 后面。
  
}

