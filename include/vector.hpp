#include <iostream>
template <typename T>
class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		T value;
	};
private:
	node_t * root_;
public:
	tree_t();
	void destr(node_t* node);
	~tree_t();
	void insert(T value);
	bool find(T value) const;
	void print(std::ostream & stream,int lvl,node_t* node);
	void oper1(char op, T value);
	void oper2(char op, T value,std::ostream& stream);
	bool operator==(tree_t & other) const;
	bool ravnbranch(node_t * first,node_t * second) const;
	tree_t(std::initializer_list<T> keys);
	bool remove(T key);
	node_t* root()
	{
		return root_; 
	}
};
template <typename T>
tree_t<T>::tree_t(){
		root_=nullptr;
	}
template <typename T>
void tree_t<T>:: destr(node_t* node) {
    if(node != nullptr)
    {
     	destr(node->left);
     	destr(node->right);
	delete node;
    }
  }
template <typename T>
tree_t<T>::~tree_t(){
		destr(root_);
	}
template <typename T>
void tree_t<T>:: insert(T value){
		node_t * node=new node_t;
		node->right=nullptr;
		node->left=nullptr;
		node->value=value;
		if (root_==nullptr){
			root_=node;
			return;
		}
		node_t * branch=root_;
		while (branch!=nullptr){   
			if(branch->value == value){
			return;
			}
			else if(branch->value<value)
			{
				if(branch->right!=nullptr){
				branch=branch->right;
				}
				else {
					branch->right=node;
					return;
				}
			}
			else if(branch->value>value){
				if(branch->left != nullptr){
				branch=branch->left;
				}
				else{
					branch->left=node;
					return;
				}
			}
			else return;
	}
}
template <typename T>
bool tree_t<T>:: find(T value) const{
	node_t * node=root_;
	while(node!=nullptr){
		if (value==node->value)
			return true;
		else {
			if (value<node->value){
			node=node->left;	
			}
			else node=node->right;
		}
	}
	return false;
}
template<typename T>
bool tree_t<T>::operator==(tree_t & other) const
{
	node_t * first;
	node_t * second;
        first = root_;
        second= other.root();
        return(ravnbranch(first, second));
}
template<typename T>
bool tree_t<T>:: ravnbranch(node_t * first,node_t * second) const
{
	if((first==nullptr) && (second==nullptr)) return (true);
	else if (first!=nullptr && second!=nullptr){
			if((first->value==second->value)&&(ravnbranch(first->left,second->left)) && (ravnbranch(first->right,second->right)))
			{return(true);}
		else return(false);
	}
	else return(false);
}
template <typename T>
void tree_t<T>::print(std::ostream & stream,int lvl,node_t* node){
	if (node==nullptr)
		return;
		print(stream,lvl +1,node->right);
			for (unsigned int i = 0; i < lvl; i++) {
			stream << "---";
		}
		stream << node->value <<std::endl;
		print(stream, lvl + 1, node->left);
	}
template <typename T>
void tree_t<T>:: oper1(char op, T value){
	if(op=='+')
	{
		insert(value);
	}
	
	else if(op=='q')
	{
		exit(0);
	}
	else std::cout<<"incorrect operation";	
}
template <typename T>
void tree_t<T>:: oper2(char op, T value,std::ostream& stream){
	if(op=='?')
	{
		if(find(value))
			stream<<"true";
		else stream<<"false";
			
	}
	else if(op=='=')
	{
		print(stream,0,root_);
	}
	else std::cout<<"incorrect operation";	
	}
template <typename T>
tree_t(std::initializer_list<T> keys)
	{
		root_ = nullptr;
		size_t size = keys.size();
		for (size_t i = 0; i < size; i++) {
			T a = *(keys.begin()+i);
			insert(a);
		}
	}
template<typename T>
bool operator !=(tree_t<T> & lhs, tree_t<T> & rhs) 
{
	bool succ=true;
	if(lhs==rhs)
	{
		succ=false;
	}
	return succ;
}
template <typename T>
bool tree_t<T>::remove(T key); 
{
if (root_ == nullptr)
{
	return false;
}
else
{
	node_t* a = root_;
	node_t* b = root_;
	for(;;)
	{
		if (b->value == key)
		{break;		}
		else if (b->value < key)
		{
			a = b;
			b = b->right;
		}
		else if (b->value > key)
		{
			a = b;
			b = b->left;
		}
		else if (b == nullptr) 
		{break;}
	}
	if (b == nullptr) 
	{return false;}
	else {
		if (b->left == nullptr && b->right == nullptr) {
			delete param2;
			return true;
		}
		else {
			if (b->left == nullptr && b->right != nullptr) {
				if (b == a->right) {
					a->right = b->right;
				}
				if (b == a->left) {
					a->left = b->right;
				}
				delete b;
			}
			else if (b->left != nullptr && b->right == nullptr) {
				if (b == a->right) {
					a->right = b->left;
				}
				if (b == a->left) 
				{a->left = b->left;}
				delete b;
			}
			else if (b->left != nullptr && b->right != nullptr) {
				node_t* c = b;
				a = b;
				b = b->right;
				while (b->left != nullptr) {
					a = b;
					b = b->left;
				}
				c->value = b->value;
				a = b->right;
				delete b;
			}
		}
	}
}
return true;
} 
