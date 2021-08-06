#include <stdio.h>
#include <assert.h>

void test(int** ptr)
{}

int main()
{
	int  arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int  brr[5][10] = { { 1,2,3,4,5,6,7,8,9,10 } ,{ 1,2,3,4,5,6,7,8,9,10 } ,{ 1,2,3,4,5,6,7,8,9,10 } ,{ 1,2,3,4,5,6,7,8,9,10 } ,{ 1,2,3,4,5,6,7,8,9,10 } };
	int  crr[1] = { 0 };
	int* drr[1] = { NULL };

	int* ap = NULL;
	int (*aq)[10] = NULL;	//[10]可以理解为aq的步长为10个int

	int (*bp)[10] = NULL;	//[10]可以理解为bq的步长为10个int
	int (*bq)[5][10] = NULL;	//[5][10]可以理解为bq的步长为10*5个int

	int (*cp)[1] = NULL;		//[1] 可以理解为bq的步长为1个int
	int (*cq)[1][1] = NULL;	//[5][10]可以理解为bq的步长为1*1个int

	ap = arr;				//ap == arr == &arr[0],首元素arr[0]的类型是int，&arr[0]的类型是int*				|---------|

	//aq = arr; 此句如果这样写，会出现：warning C4047 : “ = ” : “int(*)[10]”与“int * ”的间接级别不同

	aq = &arr;				//无warning，可见‘&’操作符不能简单理解为arr的地址，即不能简单理解为二级指针，此处是取arr的步进，‘&’有两个意思：取地址和取步进，‘*’同理
    aq = (int(*)[10])(&arr[0]);//等价于上句

	//cp = arr; 此句如果这样写，会出现：warning C4047 : “ = ” : “int(*)[1]”与“int * ”的间接级别不同，逻辑上“int(*)[1]”与“int * ”相同，但形式上不同	|---------|

	printf("ap = \t%p\n", ap);
	printf("ap+1 = \t%p\n", ap + 1);//(ap + 1) == &ap[1] == &arr[1]
	printf("ap[1] = \t%d\n", ap[1]);//打印 ‘2’
	printf("aq = \t%p\n", aq);
	printf("aq+1 = \t%p\n", aq + 1);//步进0x28，跳过一个数组,aq+1，aq+2……是均是数组指针
	printf("aq[0] = \t%p\n", aq[0]);//aq[0] == *(aq + 0)，数组指针解引用是数组首元素地址，* 将 int(*)[10] 转化成 int*	
	printf("aq[1] = \t%p\n", aq[1]); //aq[1] == *(aq + 1),但是aq + 1指向的数组不存在，aq与ap的步进不同
	printf("\n");

	bp = brr;						//bp == brr == &brr[0],首元素brr[0]的类型是int[10]		 |---------|
	bq = &brr;                      //bq的类型是int(*)[5][10]

	printf("bp = \t\t%p\n", bp);
	printf("bp[0] = \t%p\n", bp[0]);//(bp + 0) == &bp[0] == &brr[0]
	printf("bp+1 = \t\t%p\n", bp + 1);
	printf("bp[1] = \t%p\n", bp[1]);//(bp + 1) == &bp[1] == &brr[1]

	
	/*
	总结如下：

	1、变量的定义，即是定义变量的性质，分别为性和质。
	2、质：根据运算符与变量名的结合优先顺序，由内向外掏心。
	3、性：根据运算符与变量名的结合优先逆序，由外向内剥皮。

	4、变量的类型：变量定义表达式中，除去变量名的剩余部分。
	5、分析方法：按照表达式，形式上分析，编译器的分析方法。

	6、‘&’有两个意思：取地址和取步进；同理，‘*’表示解步进和解地址。*()与&()互为逆运算

	7、关于数组：数组名表示首元素地址。所有运算均将数组名视为首元素地址，即在首元素地址值上运算但是结果和意义各有不同。
	   
	   运算的结果分为：（1）代数运算，结果类型不变，理解为同阶地址运算
					   （2）*()与&()运算，结果类型能按照固定形式变化，如 int-int*-int**-int***... 或 int-int(*)[]-int(*)[][]-int(*)[][][]... 或反向，理解为地址升阶或降阶运算
					   （3）sizeof()、[]等运算，结果类型变化无固定模式，如 int*-int 或 int(*)[]-size_t等
	   见下面示例

	   数组名arr表示arr[0]的地址，类型是int*
	   
	   &(数组名)结果表示指向整个数组的地址，如：&arr表示整个数组的起始地址，即将arr的类型由 int* 转变为 int(*)[]
	   &(首元素地址) 提示编译错误，&arr[0]表示第一个元素的地址，计算结果通常存如cpu寄存器中，因而无法确定&(寄存器)的结果
	   &(数组元素)结果表示数组元素的地址，如：&arr[0]表示第一个元素的地址，&arr[1]表示第二个元素的地址，类型由 int 转变为 int*

       *(数组的指针或地址)结果表示首元素地址或数组名，如下例中，*p8为arr或&arr[0]，类型由 int(*)[] 转变为 int*
	   *(数组元素的指针或地址)结果表示数组元素，如下例中，*ap为arr[0]，类型由 int* 转变为 int 
	   *()与&()互为逆运算
	   
	   sizeof(数组名)结果表示整个数组的字节大小，如下例b、c
	   sizeof(*(数组的指针或地址))结果表示整个数组的字节大小，如下例e-j，注意sizeof括号内仅有‘*()’的形式

	   sizeof(数组元素)结果表示数组元素的字节大小，如下例d、k
	   sizeof(数组的指针或地址[?])结果表示数组元素的字节大小，如下例c、d，数组的指针或地址[?] 等价于 *(数组的指针或地址 + ?)

	   sizeof(数组的指针或地址)结果表示数组指针或地址的字节大小，通常是4/8字节，如下例e、f
	   sizeof(数组元素的指针或地址)结果表示数组元素地址的字节大小，通常是4/8字节，如下例
	   
	   

	8、对于二维数组，二维数组名表示首元素地址
	   二维数组的首元素是第一行元素，即先由第一行元素组成一个一维数组，然后将此一维数组视为二维数组的第一个元素
	   因此二维数组的首元素的变量类型是一维数组类型，二维数组首元素地址或二维数组名的类型是一维数组指针类型
	   二维数组int brr[5][10] 
	   数组名brr表示首元素地址，类型是int(*)[10]
	   &brr表示整个数组的地址，类型是int(*)[5][10]，&运算将 int(*)[10] 转变为 int(*)[5][10]
	   *(&brr) ==> brr，*运算将 int(*)[5][10] 转变为 int(*)[10]
	   brr[0-5]分别表示二维数组中第1至5个一维数组元素的地址，类型为 int(*)[10]
	   *brr表示第一个一维数组的首元素地址，类型是 int*
	   **brr表示brr[0][0]，类型是int
	   
	   由下例分析可知，&()运算、*()运算及sizeof()运算具有多意性。

	9、数组名的代数运算，首先应将数组名视为首元素地址，第二需要弄清楚首元素是什么，首元素的地址是什么类型，特别对于二维数组：
	   brr[5][10]，brr是数组名，是首元素地址，首元素是第一行的一维数组，所以首元素是一个数组，其地址是数组指针，即brr是一维数组指针，类型是int(*)[10]
	   brr + 1表示第二行元素的指针

	   brr[0]是数组名，是首元素地址，首元素是第一行第一个元素，即brr[0]是brr[0][0]的地址，类型是int*
	   
	   brr[0][0]是元素名
	   
	   *运算与[]运算都具有降阶的效果：如将brr降阶 ——》 brr[0] == *(brr + 0) == *brr ——》brr的类型由int(*)[] 将为 int*



	*/
	
	printf("5  %p\n", bq);						//二维数组起始地址
	printf("6  %p\n", bq + 1);					//步进0xc8字节，地址同阶运算。
	printf("7  %p\n", *bq + 1);					//第二行数组元素的地址（指向该数组的指针）步进0x28字节 等价于 brr[1]，地址降阶后，又同阶运算
	printf("8  %p\n", *(*bq + 1)+1);			//第二行第二个元素的地址，步进4字节 等价于 *brr[1] + 1 或者 &brr[1][1]，地址降阶后，又同阶运算，然后又降阶，又同阶运算
	printf("9  %d\n", *(*(*bq + 1) + 1));		//第二行第二个元素 等价于 brr[1][1]：2，地址降阶后，又同阶运算，然后又降阶，又同阶运算，最后降阶
	printf("a  %d\n", **brr);					//第一行第一个元素brr[0][0]：1，地址连续两次降阶运算

	printf("b  %d\n", (int)sizeof(brr));		//sizeof(数组名)计算整个二维数组的大小
	printf("c  %d\n", (int)sizeof(brr[0]));		//sizeof(数组名)计算整个一维数组的大小    brr[0] 等价于 *(brr + 0)
	printf("d  %d\n", (int)sizeof(*(brr + 0)[0]));	//sizeof(元素名)计算元素的大小		  brr[0][0] 等价于 *(brr + 0)[0] 等价于 *(*(brr + 0) + 0)

	printf("e  %d\n", (int)sizeof(*&brr));		//等价于b，‘*’运算有取得元素的意义
	printf("f  %d\n", (int)sizeof(*(&brr + 0)));//同上
	printf("g  %d\n", (int)sizeof(*(&brr + 1)));//表示下一个数组的大小，打印的是200
	printf("h  %d\n", (int)sizeof(*(&brr + 2)));//同上

	printf("i  %d\n", (int)sizeof(*bq));		//sizeof(二维数组首元素地址，相当于二维数组名brr)计算整个二维数组的大小，等价于 “b”
	printf("j  %d\n", (int)sizeof(**bq));		//sizeof(一维数组首元素地址，相当于一维数组名brr[0])计算一维数组的大小，等价于 “c”
	printf("k  %d\n", (int)sizeof(***bq));		//数组元素的大小
	

	printf("l  %d\n", (int)sizeof(bq));			//sizeof(二维数组指针)计算指针的大小，bq的类型是 int(*)[5][10]
	printf("m  %d\n", (int)sizeof(bq + 1));		//计算第二个数组指针的大小
	printf("n  %d\n", (int)sizeof(*(bq + 0) + 0));    //计算第一个数组第一行指针的大小，即第一行的地址的大小，*bq的类型是 int(*)[10]，例n-q中sizeof括号内不是单独的‘*(运算)’而是多重运算
	printf("o  %d\n", (int)sizeof(*(bq + 0) + 1));    //计算第一个数组第二行指针的大小，即第二行的地址的大小，*bq的类型是 int(*)[10]
	printf("p  %d\n", (int)sizeof(*(*(bq + 0) + 0) + 0));    //计算第一个数组第一行第一列元素地址的大小，**bq的类型是 int*
	printf("q  %d\n", (int)sizeof(*(*(bq + 0) + 0) + 1));    //计算第一个数组第一行第二列元素地址的大小，**bq的类型是 int*

	printf("r  %p\n", brr);						//二维数组首元素地址，类型是int(*)[10]
	printf("s  %p\n", brr + 1);					//二维数组第二元素地址,类型是int(*)[10]
	printf("t  %p\n", brr[0]);					//第一行数组首元素地址，类型是int*
	printf("t  %p\n", brr[0] + 1);				//第一行数组第二元素地址，类型是int*
	printf("\n");

	/*注意到 |--------| 行中，分析如下：*/

	int  p1 = 0;				//变量p1的类型是int，p1是基本变量
	int* p2 = NULL;				//变量p2的类型是int*，p2是指针变量；或者变量*p2的类型是int
	int** p3 = NULL;			//变量p3的类型是int**，p3是二级指针变量；或者变量*p3的类型是int*；或者变量**p3的类型是int
	int  p4[1] = { 0 };			//可以将变量p4的类型的类型理解为int[1],p4是数组变量,在内存中占据1个int大小的空间,或者变量p4[1]的类型是int，但实际上p4表示一维数组首元素地址，类型是int*；&p4的步长是1个int
	int  p5[10] = { 0 };		//可以将变量p5的类型理解为int[10],p5是数组变量,在内存中占据10个int大小的空间,或者变量p5[10]的类型是int，但实际上p5表示一维数组首元素地址，类型是int*；&p5的步长是10个int
	int* p6[10] = { NULL };		//可以将变量p6的类型理解为int*[10],p6是指针数组变量,或者变量p6[10]的类型是int*，但实际上p6表示一维数组首元素地址，类型是int**；&p6的步长是10个int*
	int** p7[10] = { NULL };	//可以将变量p7的类型理解为int**[10],p7是指针数组变量,或者变量p7[10]的类型是int**；或者变量*p7[10]的类型是int*；或者变量**p7[10]的类型是int，
	int(*p8)[10] = NULL;		//变量p8的类型是int(*)[10],p8是数组指针变量,在内存中占据一个地址大小的空间，或者变量(*p8)[10]的类型是int，(*p8)表示一维数组首元素地址，*(*p8)表示数组首元素；&(*p8)的步长是10个int；

	

	//p3 = &(&arr[0]); //&arr[0]计算出来是地址，此地址通常存储在寄存器中而不是内存中，所以此句有误，应改为 p2 = &arr[0] ; p2 = &p2;
	printf("0  %p\n", p3);

	p8 = &arr;       //arr是首元素地址，但&arr运算出来的地址是数组地址，结果合法，与上一句有明显区别。&运算具有多意性。
	printf("1  %p\n", p8);
	p8 = (int(*)[10])arr;  //&arr 等价于 (int(*)[10])arr 或者 (int(*)[10])&arr[0]
	printf("2  %p\n", p8);
	p8 = (int(*)[10]) & arr[0];
	printf("3  %p\n", p8 + 1);//步进0x28字节

	p2 = *p8;        //*p8的结果是首元素地址，即p2 = arr或&arr[0]
	printf("4  %p\n", *p8 + 1);//步进0x4字节						  

	p8 = &arr;					//正确，
	p8 = &brr[0];				//正确，p8 = &brr[0]，&brr[0]+1 == &brr[1]
	assert(p8 + 1 == &brr[1]);	//正确，p8+1 ==  &brr[1]
	assert(*(p8 + 1) == brr[1]);
	assert(*(*(p8 + 1) + 1) == brr[1][1]);

	int* (*p9)[10] = NULL;		//变量p9的类型是int*(*)[10],p9是数组指针变量,&(*p9)的步长是10个int*；或者变量(*p9)[10]的类型是int*；或者变量*(*p9)[10]的类型是int，(*p9)表示一维数组首元素地址

	int p10[5][10] = { 0 };		//变量p10的类型是int[5][10],p10是数组变量,p10步长是[5][10]个int；或者变量p10[5]的类型是int[10],步长是10个int；或者变量p[5][10]的类型是int
								//变量p10[5]的类型是int[10],&p10[5]步长是10个int,即变量p10[0-4]的类型是int[10],&p10[0-4]步长是10个int，相当于每一行数组的地址
	p8 = &p10[0];				//&p10[0]表示首元素取步长
	assert(p8 == p10);		//p10表示首元素地址,上句等价于p8 = p10;

	printf("%d\n", (int)sizeof(p8));
	printf("%d\n", (int)sizeof(&p10[0]));
	printf("%d\n", (int)sizeof(p10[0]));
	printf("%d\n", (int)sizeof(p10));
	printf("%d\n", (int)sizeof(&p10));

	test(drr);
	test(&drr[0]);

	//test(&drr);  err

	return 0;
}
