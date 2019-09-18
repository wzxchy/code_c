template <class T> 
class BiTreeNode
{
private:
	BiTreeNode<T> *leftChild;		//������ָ��
	BiTreeNode<T> *rightChild;		//������ָ��
public:
	T data;		  			//������?
	BiTreeNode( ):leftChild(NULL), rightChild(NULL){}
	BiTreeNode(T item, BiTreeNode<T> *left = NULL, BiTreeNode<T> *right = NULL):data(item), leftChild(left), rightChild(right){}
	~BiTreeNode(){}
	BiTreeNode<T>* &Left(void){return leftChild;}
	BiTreeNode<T>* &Right(void){return rightChild;}
};