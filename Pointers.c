// Pointers 就是 一个内存数据地址
// C 里所有内存都有两部分 : 一个地址 和 他的数据。（当然还有别的部分，比如一个是否允许改变数据的bit）
// 比如: 
// adress = 00000000000000000000000000000001, value = 1010101010101010101010101010101010, canOverride = 0     //1 = 允许改变/不重要 
// adress = 00000000000000000000000000000010, value = 0000000000000000000000000000000030, canOverride = 1
// adress = 00000000000000000000000000000011, value = 1111111111111111111111111111111111, canOverride = 1
// adress = 00000000000000000000000000000100, value = 0000000000000000000000000000000001, canOverride = 0
// adress = 00000000000000000000000000000101, value = 0000000000000000000000000000000100, canOverride = 1

// 它主要有两种改变的语法 : 
// <*name> 把name的value里当作 adress 来读 ， 给你这个adress里写的数据 
// <&name> 建立一个pointer (把 pointer 的 value 设成 name 的地址) 

//declare 过程中pointer 语法 : int* pointer; int *pointer2; 或 char *pointer; char *pointer2;
// 那个 int 或 char 是为了 告诉电脑他要读多少个 bit 

// 假设 电脑把变量 abc 设为上面例子的 adress = 2 。 那么: 
int abc = 3; 
int* x = &(abc); 
int y = *(abc);


//假设电脑每次找最小的可以改变数据的位置保存新的内容， 
//  求 abc, x , y 的 adress, value 和 叫他时有效范围。 
