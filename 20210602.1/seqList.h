#define N 100

typedef int SLDataType;


//静态顺序表
struct seqList2
{
	SLDataType _data[N];
	int _size;
};

//动态顺序表
typedef struct seqList
{
	SLDataType* _data;//数组指针
	int _size;//有效元素个数
	int _capacity;//数组的空间
}seqList;


void initseqList(seqList* sl);

void seqListPushBack(seqList* sl, SLDataType val);

//尾删:删除最后一个数据
void seqListpopBack(seqList* sl);

void seqListCheckCapacity(seqList* sl);

void seqListprint(seqList* sl);

//访问某一个位置的元素
SLDataType seqListAT(seqList* sl, int pos);

int seqListEmpty(seqList* sl);

int seqLiseSize(seqList* sl);