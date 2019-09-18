typedef char DataType; 
class SeqList
{
protected:
	DataType *list;                   //����
	int maxsize;                      //���Ԫ�ظ���
	int size;                         //��ǰԪ�ظ���
public:
	SeqList(int max=0);               //���캯��
	~SeqList(void);                   //��������
	void Insert(const DataType& item,int i);   //����
	DataType Delete(const int i);              //ɾ��
	void Print();      //���
	int Size() const;
	DataType GetData(int i)const;
};