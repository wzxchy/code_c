template <class T> 
class BiTreeNode
{
private:
	BiTreeNode<T> *leftChild;		//左子树指针
	BiTreeNode<T> *rightChild;		//右子树指针
public:
	T data;		  			//数据域?
	BiTreeNode( ):leftChild(NULL), rightChild(NULL){}
	BiTreeNode(T item, BiTreeNode<T> *left = NULL, BiTreeNode<T> *right = NULL):data(item), leftChild(left), rightChild(right){}
	~BiTreeNode(){}
	BiTreeNode<T>* &Left(void){return leftChild;}
	BiTreeNode<T>* &Right(void){return rightChild;}
};
