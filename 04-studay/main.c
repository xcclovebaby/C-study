#include <stdio.h>

/** ==========================
 * 学习目录：
 * 1.数组的定义
 * 2.一维数组
 * 3.二维数组
 * 4.字符数组
 * 5.函数
 * 6.变量
 * 7.内部函数 & 外部函数
 * 8.编译过程
 * 9.include
 * 10.define
 * 11.选择性编译
 =============================*/

/** 内存的分区：
 * 1.内存：物理内存、虚拟内存
 * 物理内存：实实在在存在的内存
 * 虚拟内存：操作系统虚拟出来的内存
 * 在写应用程序时，看到的都是虚拟内存
 * 在32位操作系统中，虚拟内存被分为两个部分
 * 3G的用户空间和1G的内核空间，
 * 其中用户空间是当前进程私有的，
 * 内核空间是系统所有进程公有的。
 * 2.在运行程序的时候，操作系统会将虚拟内存进行分区：
 * 堆、栈、静态全局区、代码区、文字常量区
 */

/** 1.数组的定义 & 2.一维数组 */
/* 数组是若干个相同变量在内存中德有序集合
 * 数组在内存中会开辟一块连续的空间
 *
 * 定义一个长度为10的int数组：
 * int a[10];
 * 数组的角标从0开始，到9结束
 * a[0] - a[9]在内存中是连续存储的
 * int在内存中占4个字节,
 * 那么int a[10]就在内存中开辟了一块40个字节的空间
 * int a[10]; 就是定义的一维数组
 */
void testArray() {
    //定义一维数组的方式1：
    int a[10];

    //定义一维数组的方式2：
    int b[] = {1,2,3,4,5,6};

    //通过sizeof关键字可以获取数组的大小
    printf("\n sizeof(a) = %d", sizeof(a));
    printf("\n sizeof(b) = %d", sizeof(b));

    //数组中德元素如果不初始化，直接使用会是随机值
    printf("\n %d", a[0]);
    printf("\n %d", a[1]);
    printf("\n %d", a[2]);
    printf("\n %d", a[3]);

    printf("\n for:");
    //遍历一维数组每个元素的值：
    for(int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("\n %d", a[i]);
    }
}

/** 3.二维数组 */
/* 二维数组的格式：数据类型 数组名[行的个数][列的个数]
 * 例如：
 * int a[2][4];
 * 定义一个名为a的二维数组，每个元素都是int类型
 * 这个二维数组为2行4列，一共8个元素
 * 二维数组也是连续开辟空间
 * 访问元素行列都是从角标0开始
 * a[0][0] a[0][1] a[0][2] a[0][3]
 * a[1][0] a[1][1] a[1][2] a[1][3]
 */
void testArrayTwo() {
    //二维数组的定义方式1：
    int a[2][4];

    //二维数组的定义方式2
    int b[][4] = {1,2,3,4,5}; //32
    int c[][4] = {1,2,3,4}; //16
    int d[][4] = {1,2,3,4,5,6,7,8,9}; //48

    //通过sizeof关键字可以获取数组的大小
    printf("\n sizeof(a) = %d", sizeof(a));
    printf("\n sizeof(b) = %d", sizeof(b));
    printf("\n sizeof(c) = %d", sizeof(c));
    printf("\n sizeof(d) = %d", sizeof(d));

    /* 解析 int b[][4] = {1,2,3,4,5};
     * 这里未指定多少行,但指定了有4列,
     * 证明每行最多只有4个元素，
     * b数组在初始化时为5个元素，
     * 那么这个二维数组则为：int b[2][4];
     * b[0][0] b[0][1] b[0][2] b[0][3]
     * 1,2,3,4
     * b[1][0]
     * 5
     * 其余未定义的元素则为0
     */
    printf("\n b[0][0] = %d", b[0][0]);
    printf("\n b[0][1] = %d", b[0][1]);
    printf("\n b[0][2] = %d", b[0][2]);
    printf("\n b[0][3] = %d", b[0][3]);
    printf("\n b[1][0] = %d", b[1][0]);
    printf("\n b[1][1] = %d", b[1][1]);
    printf("\n b[1][2] = %d", b[1][2]);
    printf("\n b[1][3] = %d", b[1][3]);

    //二维数组的初始化1：
    int e[2][4] = {{1,2,3,4}, {5,6,7,8}};
    //(常用方式)二维数组的初始化2：
    int f[2][4] = {1,2,3,4,5,6}; //注意:未被初始化的元素则为0


    printf("\n ================== for =========================");
    //二维数组的遍历数组b中的每个元素：
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            printf("\n b[%d][%d] = %d", i, j, b[i][j]);
        }
    }
}

/** 4.字符数组 */
/* 字符数组的定义
 * 使用字符串的方式定义给字符数组每个元素赋值时，
 * 要比字符逐个赋值多占1个字节，
 * 用于存放字符串结束标志 ‘\0’
 */
void testChar() {
    //定义字符数组方式1：
    char a[] = {'a', 'b', 'c'};
    //定义字符数组方式2：
    char b[] = "abc";
    //数组b在内存中实际存放的情况是 'a','b','c','\0'
    //利用这个特性，通过字符串的方式定义字符数组可以清除字符数组中的垃圾字符,让每个元素都是\0
    char c[32] = "";
    //数组名就是当前数组的首地址，所以scanf的参数可以直接使用数组名
    scanf("%s", c);
    printf("\n c=%s", c);

    //定义二维字符数组
    char d[][2] = {"123","456"};
}

/** 5.函数 */
/* 函数是C语言的功能单位，实现一个功能可以封装成一个函数
 * 可以根据功能区定义函数的返回值和参数
 * int funcation(int a, double b, float c); 有返回值带参函数
 * int funcation(); 有返回值无参数函数
 * void funcation(); 无返回值无参函数
 * 有返回值的函数，必须要使用return来结束
 */
int testFun(int a, double b, float c) {
    printf("\n testFun: ");
    printf("\n a=%d,b=%lf,c=%f", a, b, c);
    return 0;
}

/** 6.变量 */
/* 普通的全局变量：在函数外部定义的变量
 * int a = 100; 变量a就是一个全局变量
 * int main(){}
 * 作用范围：全局变量可以在程序的任何地方使用
 * 只不过使用前需要声明，声明方法 extern int a;
 * 如果全局变量没有进行初始化，则系统默认将其初始化为0
 *
 * 静态全局变量：定义全局变量时在前面用static修饰
 * static int b = 1000; 变量b就是一个静态全局变量
 * 作用范围：static限定了静态全局变量的范围，只能在它定义的.c源文件中有效
 * 不能跨文件使用
 *
 * 普通局部变量：在函数内部定义，随着函数结束也会被释放
 * 静态局部变量：定义局部变量前用static修饰
 * 作用范围：在定义的函数和复合语句中有效
 * 生命周期：在第一次调用函数时，开辟空间赋值，函数结束后不释放，以后再调用就不再为其开辟空间也不赋值，用的是以前的变量
 */
int a = 100;
static int b = 1000;
void testA() {
    extern int a;
    static int c = 3;
    printf("\n testA: a=%d", a);
    printf("\n testA: c=%d", c);
    c++;
}

void testB() {
    a = 1;
    printf("\n testB: a=%d", a);
    printf("\n testB: b=%d", b);
}

/** 7.内部函数 & 外部函数 */
/* 定义的普通函数均为外部函数
 * 外部函数可以在程序的任何一个文件中调用
 *
 * 内部函数：在定义函数的时候，前面使用static修饰，static限定了函数的作用范围，在定义的.c中有效
 */
static int testStaticFun();

/** 8.编译过程 */
/* C语言的编译过程：
 * gcc -E hello.c -o hello.i  1.预处理
 * gcc -S hello.i -o hello.s  2.编译
 * gcc -c hello.s -o hello.o  3.汇编
 * gcc hello.o -o hello_ef    4.链接
 *
 * 1.预编译：将.c中的头文件展开、宏展开，生成的是.i文件
 * 2.编译：将预处理后的.i文件生成.s汇编文件
 * 3.汇编：将.s汇编文件生成.o目标文件
 * 4.链接：将.o文件链接成目标文件
 */

/** 9.include */
/* include：
 * #include <> 用尖括号包含头文件，在系统指定的路径下找头文件
 * #include "" 用双引号包含头文件，先在当前目录下找头文件，找不到再到系统指定的路径下找
 * 注意1：
 * include经常用来包含头文件，可以包含.c文件，但不要包含.c文件，因为include包含的文件会被预编译展开，
 * 如果一个.c包含多次，展开多次，会导致函数重复定义，所以不要使用include包含.c文件
 * 注意2：
 * 预处理只是对include等预处理操作进行处理并不会检查语法
 * 等到第二个阶段编译时才会进行语法检查
 */

/** 10.define */
/* define：定义宏用define去定义
 * 宏是预编译的时候进行替换。
 *
 * 1.不带参宏定义：#define PI 3.14
 * 在预编译的时候如果代码中出现了PI就用3.14去替换
 * 宏的好处：只要修改宏定义，其他地方在预编译的时候就会重新替换
 * 注意：宏定义后面不要加;号
 * 宏定义的适用范围：从定义的地方到文件末尾。
 * 如果想终止宏定义范围：#undef PI即可终止
 *
 * 2.带参宏定义：#define S(a,b) a*b
 * 注意1：带参宏的形参没有类型名
 * S(a,b)在预处理的时候会把形参替换为实参进行计算
 * 注意2：宏定义只是简单的替换，不会自动加括号
 *
 * 3.带参宏与带参函数的区别：
 * 带参宏被调用多少次就被展开多少次，执行代码的时候没有函数调用过程，不需要压栈弹栈
 * 所以带参宏是浪费了空间，因为被展开多次，节约了时间（利用空间提高效率）
 * 带参函数代码只有一份，存在代码段，调用的时候去代码段取指令，并压栈弹栈，有个被调用的过程
 * 所以说带参函数是节省了空间但浪费了时间（利用时间来节约空间）
 * 带参函数形参有类型，带参宏形参没有类型
 */
#define PI 3.141592654 ///不带参宏定义,该宏定义上面的函数无法使用
#define S(a, b) a*b ///带参宏定义
void testDefine() {
    printf("\n PI=%lf", PI);
    printf("\n S=%d", S(2,2));
    printf("\n S=%lf", S(2.2,2));
    printf("\n S=%s", S('2.2',2));

    //如果出现下列情况，在预处理替换是为 2 + 8 * 4
    //想实现先运算2+8可以把宏定义为 #define S(a,b) ((a) * (b))这种形式
    printf("\n S=%d", S(2 + 8, 4)); //值为34
}
#undef PI
//该方法无法使用被终止的PI宏
void testPI() {
//    printf("\n PI=%lf", PI);
}

/** 11.选择性编译 */
/* 选择性编译都是在预编译阶段干的事情
 * 定义1：
 * #ifdef AAA
 *  ...代码1
 * #else
 *  ...代码2
 * #endif
 * 如果在当前.c ifdef上面定义AAA，就编译代码段1，否则编译代码段2
 *
 * 定义2：
 * #ifndef AAA
 *  ...代码段1
 * #else
 *  ...代码段2
 * #endif
 * 这里与上面第一不同的是ifndef，表示没有定义AAA就会编译代码段1，否则编译代码段2
 * 和第一种方式互补，通常用来防止头文件重复包含
 *
 * 定义3：
 * #if 表达式
 *  ...程序段1
 * #else
 *  ...程序段2
 * #endif
 * 如果表达式为真，编译第一段代码，否则编译第二段代码
 */

int main()
{
//    testArray();
//    testArrayTwo();
//    testChar();
//    testFun(1,2,3);
//    testA();
//    testB();
//    testA();
    testDefine();
    return 0;
}
