#define N 100

typedef int SLDataType;


//��̬˳���
struct seqList2
{
	SLDataType _data[N];
	int _size;
};

//��̬˳���
typedef struct seqList
{
	SLDataType* _data;//����ָ��
	int _size;//��ЧԪ�ظ���
	int _capacity;//����Ŀռ�
}seqList;


void initseqList(seqList* sl);

void seqListPushBack(seqList* sl, SLDataType val);

//βɾ:ɾ�����һ������
void seqListpopBack(seqList* sl);

void seqListCheckCapacity(seqList* sl);

void seqListprint(seqList* sl);

//����ĳһ��λ�õ�Ԫ��
SLDataType seqListAT(seqList* sl, int pos);

int seqListEmpty(seqList* sl);

int seqLiseSize(seqList* sl);