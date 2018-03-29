#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class tree_t
{
private:
	struct node_t {
		node_t * left=nullptr;
		node_t * right;
		int value=0;
	};
private:
	node_t * root_;
public:
	tree_t(){
		root_=nullptr;
	}
void destr(node_t * node){
 		node_t * time=node;
		while(time!=nullptr)
		{
			if(time->left!=nullptr)
			{
				time=time->left;
			}
			else if(time->right!=nullptr)
			{
				time=time->right;
			}
			else if((time->left==nullptr) && (time->right==nullptr) &&(time!=node))
			{
				delete time;
				time=node;
			}
			else if((time->left==nullptr) && (time->right==nullptr) &&(time==node))
			{
				delete time;
				break;
			}
		}
}
~tree_t(){
		destr(root);
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
		node_t * vetka=root_;
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
			else {
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
	node_t * node=root;
	while(node!=nullptr){
		if (value=node->value)
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
		stream << node->value << endl;
		print(stream, lvl + 1, node->left);
	}
void oper(std::ostream& stream, char op, int value){
	if(op=='+')
	{
		insert(value);
	}
	else if(op=='=')
	{
		print(value)
	}
	else if(op=='?')
	{
		find(value);
	}
	else std::cout<<"incorrect operation";	
}
};
