#include <vector>
#include <queue>
#include <iostream>


template<typename T>
struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;
};


template<typename T>
void printBST(const Node<T>* pRoot)
{
	if(pRoot)
	{
		std::queue<std::pair<const Node<T>*, int> > q;
		q.push(std::make_pair(pRoot, 0));
		int oldLevel = 0;
		int curLevel = 0;
		while(!q.empty())
		{
			std::pair<const Node<T>*, int> cur = q.front();
			q.pop();
			const Node<T>* curNode = cur.first;
			oldLevel = curLevel;
			curLevel = cur.second;

			if(curLevel > oldLevel)
			{
				std::cout << std::endl;
			}

			if(curNode->left)
			{
				q.push(std::make_pair(curNode->left, curLevel + 1));
			}
			if(curNode->right)
			{
				q.push(std::make_pair(curNode->right, curLevel + 1));
			}

			std::cout << curNode->value << " ";
		}
	}
	else
	{
		std::cout << "Empty tree" << std::endl;
	}
	
	
}

template<typename T>
Node<T>* createMinBST(const std::vector<T>& vec, typename std::vector<T>::const_iterator from, typename std::vector<T>::const_iterator to)
{
	if(distance(from, to) > 0)
	{
	        typename std::vector<T>::const_iterator mid = from + std::distance(from, to) / 2;

		Node<T>* node = new Node<T>();
		node->value = *mid;
		node->left = createMinBST(vec, from, mid);
		node->right = createMinBST(vec, mid + 1, to);
		return node;
	}

	return 0;
}


template<typename T>
Node<T>* createMinBST(const std::vector<T>& vec)
{
	createMinBST(vec, vec.begin(), vec.end());
}


int main()
{	
	int sorted[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 27, 37, 47};
	std::vector<int> sv(sorted, sorted + sizeof(sorted) / sizeof(int));
	Node<int>* root = createMinBST(sv);
	printBST(root);

	return 0;
}
