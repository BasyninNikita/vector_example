#include <iostream>
class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		int value;
	};
private:
	node_t * root_;
public:
	tree_t(){
		root_=nullptr;
	}
	node_t* root()
	{
		return root_; 
	}
 void destr(node_t* node) {
    if(node != nullptr)
    {
     	destr(node->left);
     	destr(node->right);
    }
    delete node;
  }
~tree_t(){
		destr(root_);
	}
	void insert(int value){
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
bool find(int value) const{
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
void print(std::ostream & stream,int lvl,node_t* node){
	if (node==nullptr)
		return;
		print(stream,lvl +1,node->right);
			for (unsigned int i = 0; i < lvl; i++) {
			stream << "---";
		}
		stream << node->value <<std::endl;
		print(stream, lvl + 1, node->left);
	}
void oper(char op, int value,std::ostream& stream){
	if(op=='+')
	{
		insert(value);
	}
	else if(op=='?')
	{
		if(find(value))
			stream<<"true";
		else stream<<"false";
			
	}
	else if(op=='=')
	{
		print(stream,0,root_);
	}
	else if(op=='q')
	{
		exit(0);
	}
	else std::cout<<"incorrect operation";	
}
};
