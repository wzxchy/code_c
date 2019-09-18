typedef char DataType; 
class SeqList
{
protected:
	DataType *list;                   //数组
	int maxsize;                      //最大元素个数
	int size;                         //当前元素个数
public:
	SeqList(int max=0);               //构造函数
	~SeqList(void);                   //析构函数
	void Insert(const DataType& item,int i);   //插入
	DataType Delete(const int i);              //删除
	void Print();      //输出
	int Size() const;
	DataType GetData(int i)const;
};