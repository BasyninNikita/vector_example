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
	auto operator==(tree_t & other) const;
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
auto tree_t<T>::operator==(tree_t & other) const
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
tree_t<T>::tree_t(std::initializer_list<T> keys)
	{
		root_=nullptr;
		int n = keys.size();
		const int* ptr = keys.begin();
		for (int i=0; i < n; i++)
		{
			insert(ptr[i]);
		}
	}
template <typename T>
bool tree_t<T>::remove(T key) 
{
if (root_ == nullptr)
{
	return false;
}
else
{
	node_t* param1 = root_;
	node_t* param2 = root_;
	while (1)
	{
		if (param2->value == key)
		{
			break;
		}
		else if (param2->value < key)
		{
			param1 = param2;
			param2 = param2->right;
		}
		else if (param2->value > key)
		{
			param1 = param2;
			param2 = param2->left;
		}
		else if (param2 == nullptr) {
			break;
		}
	}
	if (param2 == nullptr) {
		return false;
	}
	else {
		if (param2->left == nullptr && param2->right == nullptr) {
			if (param2 == param1->right) {
				param1->right = nullptr;
			}
			if (param2 == param1->left) {
				param1->left = nullptr;
			}
			delete param2;
			return true;
		}
		else {
			if (param2->left == nullptr && param2->right != nullptr) {
				if (param2 == param1->right) {
					param1->right = nullptr;
				}
				if (param2 == param1->left) {
					param1->left = nullptr;
				}
				delete param2;
			}
			else if (param2->left != nullptr && param2->right == nullptr) {
				if (param2 == param1->right) {
					param1->right = nullptr;
				}
				if (param2 == param1->left) {
					param1->left = nullptr;
				}
				delete param2;
			}
			else if (param2->left != nullptr && param2->right != nullptr) {
				node_t* param = param2;
				param1 = param2;
				param2 = param2->right;
				while (param2->left != nullptr) {
					param1 = param2;
					param2 = param2->left;
				}
				param->value = param2->value;
				param1->left = param2->right;
				delete param2;
			}
		}
	}
}
return true;
} 
