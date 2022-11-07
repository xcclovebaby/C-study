#include <stdio.h>
#include <string.h>

/** ==========================
 * 学习目录：
 * 1.结构类型的概念和定义(重点)
 * 2.结构体类型的定义初始化和使用
 * 3.类型相同的结构体变量可以相互赋值
 * 4.结构体数组
 * 5.结构体指针
 * 6.结构体内存分配
 * 7.位段
 * 8.共用体
 * 9.枚举
 * ==========================*/

/** 1.结构类型的概念和定义(重点) */
/* 构造类型是若干个相同或不同的数据类型组成的结构集合
 * 常用的构造类型：结构体、共用体、数组
 *
 * 数组用于保存多个相同类型的数据
 * 结构体用于保存多个不同类型的数据
 *
 * 结构体是一种构造类型的数据结构
 * 定义方法：
 * struct 结构体类型名{
 *  成员列表
 * };
 */
struct stu {
    int num;
    char name[20];
    char sex;
};

//可以在定义结构体的同时来定义结构体变量
struct stu1 {
    int num;
    char name[20];
    char sex;
}lili, sisi; //同时定义了两个名为lili、sisi的全局结构体变量

//定义结构体时也可以不定义结构体名称：无名结构体
struct {
    int num;
    char name[20];
    char sex;
}mingming;

//最常用的方式来定义结构体：给结构体类型取别名
//此时相当于当前结构体重新起了一个类型名为STU
//使用时直接使用STU即可不
typedef struct {
    int num;
    char name[20];
    char sex;
}STU;

//在函数内定义变量
void test1() {
    //定义了三个struct stu类型的变量
    //每个变量都有三个属性，num、name、sex
    struct stu lucy, bob, lilei;

    //使用STU类型来定义变量
    STU hanhan, chengcheng;
}

/** 2.结构体类型的定义初始化和使用 */
void test2() {
    //结构体变量的初始化
    STU chengcheng = {1, "cc", 'B'};
    STU hanhan, abc = {2, "hh", 'G'};

    //定义和初始化好结构体变量后，如何使用：
    printf("cc:name = %s, num = %d, sex = %c \n", chengcheng.name, chengcheng.num, chengcheng.sex);

    //重新给结构体属性赋值：
    chengcheng.num = 10;
//    chengcheng.name = "123";
    strcpy(chengcheng.name, "123");
    printf("cc:name = %s, num = %d, sex = %c \n", chengcheng.name, chengcheng.num, chengcheng.sex);
}

/** 3.类型相同的结构体变量可以相互赋值 */
void test3() {
    STU chengcheng = {1, "cc", 'B'};
    STU CC = chengcheng;
    printf("cc:name = %s, num = %d, sex = %c \n", CC.name, CC.num, CC.sex);
}

/** 4.结构体数组 */
/* 结构体数组就是由多个相同类型的结构体变量组成的集合
 * 1.struct 结构体类型名 数组名[元素个数]
 * 2.结构体别名 数组名[元素个数]
 */
void test4() {
    struct stu student1[10];
    STU student2[3] = {{1, "cc", 'B'}, {2, "hh", 'G'}, {3, "kaixin", 'G'}};
}

/** 5.结构体指针 */
/* struct 结构体类型名 *指针变量名
 * 结构体别名 *指针变量名
 */
void test5() {
    //定义方法1
    STU cc;
    strcpy(cc.name, "cc");
    cc.num = 1;
    cc.sex = 'B';

    struct stu *p1;
    STU *p2 = &cc;

    //使用结构体指针
    printf("cc:name = %s, num = %d, sex = %c \n", p2->name, p2->num, p2->sex);
    printf("cc:name = %s, num = %d, sex = %c \n", (*p2).name, (*p2).num, (*p2).sex);

    //定义方法2
    p2 = (STU *)malloc(sizeof(STU));
    strcpy(p2->name, "11");
    p2->num = 2;
    p2->sex = 'G';
    printf("cc:name = %s, num = %d, sex = %c \n", (*p2).name, (*p2).num, (*p2).sex);

    free(p2); //释放内存
    p2 = NULL; //防止野指针
}

/** 6.结构体内存分配 */
/* 结构体变量大小是它所有属性之和
 * 如何计算结构体属性的大小呢，不是按照属性所占的字节，而是在结构体内找字节数最大的数据类型，
 * 找寻所占内存最大的类型：比如结构体内只有char类型 占1字节，如果有double则占8字节，
 * 字节对齐： char 1字节，内存单元的编号是1的倍数
 *          short 2字节，内存单元的编号是2的倍数
 *          int 4字节，内存单元的编号是4的倍数
 *          long 32位4自己 64位8字节，内存单元的编号是4/8的倍数
 *          float 4字节，内存单元的编号是4的倍数
 *          double 8字节 vc环境:内存单元的编号是8的倍数 gcc环境:内存单元的编号是4的倍数
 * 开辟空间时是根据结构体属性的顺序依次开辟空间
 * 根据字节对齐原理，结构体属性排序不同，开辟的内存空间大小不同
 */
struct s1 {
    int i1; //占4个字节
    int i2; //占4个字节
};//占8个字节

struct s2 {
    char sex; //按照int来开辟空间,先开辟4个字节存放sex
    //再存放 age时不够内存了，字节对齐原理再开辟4字节内存
    int age; //占4个字节
}; //占8个字节

struct s3 {
    char a; //先按int开辟4个字节 存放1字节的a
    short b;//剩余内存可以存放b 不需要开辟空间， 则a和b占4个字节
    int c; //占4个字节
}; //占8个字节

struct s4 {
    char a; //先按int开辟4个字节 存放1字节的a，占4字节
    int b; //内存不够，开辟空间，占4字节
    short c; //再开辟空间，占4字节
}; //占12个字节

struct s5 {
    char buf[10]; //按照int开辟空间 一共10个char型需要10字节，则需要开辟12个字节的内存，占12字节
    int a; //占4个字节
}; //占16个字节

struct s6 {
    char a; //区分vc和gcc环境，按照double开辟空间 分别占4或8个字节
    double b; //占8个字节
}; //vc环境占16个字节 gcc环境占12个字节

/** 7.位段 */
/* 位段即结构体的成员变量的位数空间
 * 位段成员的类型必须是整型或字符型
 * 一个位段必须存放在一个存储单元中，不能跨两个单元
 * 位段数是不能大于类型最高位数
 */
struct packed_data {
    //a b c d一共占4字节 为一个存储单元 int最大为32位
    int a:2;
    int b:6;
    int c:4;
    int d:4;

    int e: 30; //占4个字节

    int i; //占4个字节
}data; //占12个字节

struct d {
    //a b占1个字节
    char a:1;
    char b:2;
    char :0; //表示下面一段从另一个存储单元开始
    //c占一个字节
    char c:3;
} d;

//不能对位段取地址
void test7(){
    printf("%d \n", sizeof(d));
    printf("%d \n", sizeof(data));
    data.a = 2; //注意a位段最大为2位,2位最大是2-> 0000 00 11 = 2,超过2就会报错
    //data.a = 5; //0000 0101 = 5 -> 101是3位,超过了最大的存储单元就会报错
}

/** 8.共用体 */
/* 共用体和结构体类似，也是一种构造类型的数据结构
 * 只需要在定义时把struct换成union就可以了
 * 共用体所有成员占有同一段地址空间
 * 相当于是公共资源被所有线程使用、
 * 共用体的大小是其占内存最大的成员的大小
 *
 * 共用体在同一内存段可以存放几种不同类型的成员变量，但每一瞬时只有一种起作用
 * 共用体变量起作用的成员是最后一次存放的成员，在存入一个新的成员后，原有的成员的值会被覆盖
 * 共用体变量的地址和它的各成员的地址都是一个地址
 * 共用体变量的初始化 DATA a = {123}; 或 union data a = {123};
 */
struct t8 {
    short i;
    char ch;
    float f;
}; //占8个字节

typedef union data {
    unsigned short i;
    unsigned char ch;
    float f;
}DATA;  //占4个字节，即i ch f共用4个字节

void test8() {
    DATA a;
    a.ch = 'a';
    a.i = 1;
    a.f = 22.01;
    printf("ch = %p i = %p f = %p \n", &a.ch, &a.i, &a.f);
    printf("f = %f", a.f);
}

/** 9.枚举 */
/* enum 枚举名{
 *  枚举值列表
 * }
 * 枚举变量只能取枚举值列表中的元素
 * 枚举值为常量
 * 枚举元素本身由系统定义了一个表示序号的数值，默认从0开始
 * 也可以改变枚举的值
 */
enum week {
    mon = 2,
    tue = 1,
    wed,
    thu,
    fri,
    sat = 6,
    sun
};

void test9() {
    enum week workday = mon, weekday = sat; //枚举变量

    printf("day = %d \n", workday);
    printf("day = %d \n", weekday);
}

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test7();
//    test8();
    test9();
    return 0;
}
