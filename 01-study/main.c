#include <stdio.h> //头文件包含,一定要有

/* qt下载地址: https://download.qt.io/archive/qt/5.9/5.9.0 */

void helloWorld(){ //这是书写的第一个函数
    printf("Hello World!\n"); //输出hello world
}

/* 数据类型相关关键字
 * char 字符型,用char定义的变量为字符型变量,占1个字节 char a = 'a'; 取值范围-2^7 ~ 2^7-1
 * short 短整型,占2个字节 short int s = 1; 取值范围 -2^15 ~ 2^15-1
 * int 整型,在32位系统占4字节,16位系统占2个字节 int i = 1; 取值范围 -2^31 ~ 2^31-1
 * long 长整形,在32位系统占4个字节,在64位系统占8个字节 long int l = 1; 取值范围 -2^31 ~ 2^31-1/-2^63 ~ 2^63-1
 * float 单精度浮点型,占4个字节
 * double 双精度浮点型,占8个字节
 * struct 结构体类型
 * union 共用体(联合体)类型
 * enum 枚举类型
 * signed 有符号类型, 默认数据类型为signed修饰
 * unsigned 无符号类型,只能保存正数和0,同signed一样用来修饰数据类型
 * void 空类型
 */
void testData(){
    char a = 'a';
    short b = 10;
    int c;
    long d;
    float e;
    double f;

    //sizeof()函数用来计算所占内存字节
    printf("%s%d \n","a的内存占用为:",sizeof(a));
    printf("%s%d \n","b的内存占用为:",sizeof(b));
    printf("%s%d \n","c的内存占用为:",sizeof(c));
    printf("%s%d \n","d的内存占用为:",sizeof(d));
    printf("%s%d \n","e的内存占用为:",sizeof(e));
    printf("%s%d \n","f的内存占用为:",sizeof(f));

    /* 输出结果:
    a的内存占用为:1
    b的内存占用为:2
    c的内存占用为:4
    d的内存占用为:8
    e的内存占用为:4
    f的内存占用为:8
    */
}

/* 存储相关关键字
 * register 寄存器,用register修饰的变量是寄存器变量,在编译时 #尽量# 将存储空间分配在寄存器中,运行速度比内存快.
      ※ 注意:
      * ①定义的变量不一定真的存放在寄存器中
      * ②CPU取数据的时候去寄存器中拿数据比去内存中拿数据快
      * ③寄存器比较宝贵,所以不能定义寄存器数组
      * ④register只能修饰字符型和整型,不能修饰浮点型
      * ⑤register修饰的变量可能存放在寄存器中,所以不能对寄存器变量取地址,只有放在内存中的数据才有地址
 * static 静态类型,可以修饰全局变量,局部变量,函数.被修饰的变量保存在静态区
 * const 常量类型,被修饰的变量为只读,不能修改它的值,const可以修饰指针.
 * extern 外部类型,一般用于函数和全局变量的声明
 */

/* typedef 重命名相关关键字 */
void testTypedef(){
    /*
     * 在C语言中 没有 U16 INT16 U8这些关键字
     * 其实是用typedef定义出来的新的类型名
     */
    typedef unsigned short int INT16;
    typedef unsigned char U16;
    typedef char U8;
    U16 a = 'a'; //U16 a和 unsigned char a是一个效果
    printf("a = %x \n", a);
}

/* 格式化输出字符
 * %d 十进制有符号整数
 * %ld 十进制long有符号整数
 * %u 十进制无符号整数
 * %o 以八进制表示的整数
 * %x 以十六进制表示的整数
 * %f float型浮点数
 * %lf double型浮点数
 * %e 指数形式的浮点数
 * %c 字符类型
 * %s 字符串类型
 * %p 指针类型
 *
 * 特殊应用:
 * %3d 要求宽度为3位,如果不足3位,前面空格补齐
 * %03d 要求宽度为3位,如果不足则0补齐
 * %-3d 要求宽度为3位,不足则后面空格补齐
 * %.2f 小数点后保留2位
 */

int main() //main函数是主函数,任意一个c程序必须只能有一个主函数,是程序的入口
{
    helloWorld(); //在主函数中调用helloWrold函数
    testData(); //调用测试数据内存函数
    testTypedef();
    return 0; //给函数设置一个返回值
}
