#include <iostream>

using namespace std;

template<typename T>
class TreeIterator;

class Exception : public std::logic_error
{
private:
	string _source;
	string _method;
public:
	explicit Exception(string message, string source, string method) : std::logic_error(message), _source(source), _method(method) {}
};

class TreeRootIsNullException : public Exception
{
public:
	explicit TreeRootIsNullException(string source, string method) : Exception("Tree root is null!", source, method) {}
};

template<typename T>
class Node
{
private:
	T _value;
	Node<T>* _left;
	Node<T>* _right;
	Node<T>* _previous;
public:
	Node(T value);
	Node(T value, Node<T>* previous) : _value(value), _previous(previous) {};
	T GetValue()const;
	Node<T>* GetRight()const;
	Node<T>* GetLeft()const;
	Node<T>* GetPrevious()const;

	void SetValue(T value);
	void SetRight(Node<T>* right);
	void SetLeft(Node<T>* left);
	void SetPrevious(Node<T>* previous);

	bool operator==(Node<T>* node);
	bool operator>(Node<T>* node);
	bool operator<(Node<T>* node);

	~Node();
};



template<typename T>
Node<T>::Node(T value)
{
	_value = value;
	_right = nullptr;
	_left = nullptr;
}

template<typename T>
T Node<T>::GetValue()const { try { return _value; } catch (...) { cout << "Error in get value method!!!"; } }

template<typename T>
Node<T>* Node<T>::GetRight()const { try { return _right; } catch (...) { cout << "Error in get right method!!!"; } }

template<typename T>
Node<T>* Node<T>::GetLeft()const { try { return _left; } catch (...) { cout << "Error in get left method!!!"; } }

template<typename T>
Node<T>* Node<T>::GetPrevious()const { try { return _previous; } catch (...) { cout << "Error in get previous method!!!"; } }

template<typename T>
void Node<T>::SetValue(T value) { try { _value = value; } catch (...) { cout << "Error in set value method!!!"; } }

template<typename T>
void Node<T>::SetRight(Node<T>* right) { try { _right = right; } catch (...) { cout << "Error in set right method!!!"; } }

template<typename T>
void Node<T>::SetPrevious(Node<T>* previous) { try { _previous = previous; } catch (...) { cout << "Error in set previous method!!!"; } }

template<typename T>
void Node<T>::SetLeft(Node<T>* left) { try { _left = left; } catch (...) { cout << "Error in set left method!!!"; } }

template<typename T>
bool Node<T>::operator==(Node<T>* node)
{
	if (_value == node->_value)
		return true;
	return false;
}

template<typename T>
bool Node<T>::operator<(Node<T>* node)
{
	if (_value < node->_value)
		return true;
	return false;
}
template<typename T>
bool Node<T>::operator>(Node<T>* node)
{
	if (_value > node->_value)
		return true;
	return false;
}

template<typename T>
Node<T>::~Node()
{
	cout << _value << " had been deleted." << endl;
}


template<typename T>
class BinaryTree
{
private:
	Node<T>* _root = nullptr;
	bool isUnique = true;
	Node<T>* AddElement(T value, Node<T>* node, Node<T>* previous);

	Node<T>* SearchElement(T value, Node<T>* node)const;

	void DisposeElement(Node<T>* node);

	Node<T>* RemoveElement(T value, Node<T>* node);
	Node<T>* FindMinNode(Node<T>* node);
	Node<T>* RemoveMinElement(Node<T>* node);

	Node<T>* GetMinElement(Node<T>* node);
	Node<T>* GetMaxElement(Node<T>* node);
public:

	template<typename T>
	friend void InLineShow(BinaryTree<T>);

	BinaryTree() {}
	BinaryTree(Node<T>* root) { _root = root; }
	void AddElement(T value);
	void RemoveElement(T value);
	Node<T>* SearchElement(T value)const;
	void Show()const;
	void SetIsUnique(bool state);

	TreeIterator<T> Begin();
	TreeIterator<T> End();

	~BinaryTree();
};

template<typename T>
Node<T>* BinaryTree<T>::GetMinElement(Node<T>* node)
{
	if (!node->GetLeft())
		return node;
	return GetMinElement(node->GetLeft());
}

template<typename T>
Node<T>* BinaryTree<T>::GetMaxElement(Node<T>* node)
{
	if (!node->GetRight())
		return node;
	return GetMaxElement(node->GetRight());
}


template<typename T>
void BinaryTree<T>::AddElement(T value)
{
	try
	{
		if (_root == nullptr)
		{
			_root = new Node<T>(value);
			return;
		}
		AddElement(value, _root, nullptr);
	}
	catch (...)
	{
		cout << "Error in add element method!!!";
	}
}


template<typename T>
Node<T>* BinaryTree<T>::AddElement(T value, Node<T>* node, Node<T>* previous)
{
	if (!node)
		return new Node<T>(value, previous);
	if (value < node->GetValue())
		node->SetLeft(AddElement(value, node->GetLeft(), node));
	else if (node->GetValue() == value && isUnique)
		return node;
	else
		node->SetRight(AddElement(value, node->GetRight(), node));
	return node;
}



template<typename T>
Node<T>* BinaryTree<T>::SearchElement(T value)const
{
	try
	{
		if (_root == nullptr)
			throw TreeRootIsNullException("BinaryTree", "SearchElement");
		return this->SearchElement(value, _root);
	}
	catch (TreeRootIsNullException exception)
	{
		cout << exception.what() << endl;
		return nullptr;
	}
	catch (...)
	{
		cout << "Error in method search element method!!!" << endl;
		return nullptr;
	}
}


template<typename T>
Node<T>* BinaryTree<T>::SearchElement(T value, Node<T>* node)const
{
	if (node->GetValue() == value)
		return node;
	if (node->GetValue() > value)
	{
		if (node->GetLeft())
			SearchElement(value, node->GetLeft());
		else return nullptr;
	}
	else if (node->GetRight())
		SearchElement(value, node->GetRight());
	else return nullptr;
}




template<typename T>
void BinaryTree<T>::SetIsUnique(bool state)
{
	isUnique = state;
}



template<typename T>
Node<T>* BinaryTree<T>::FindMinNode(Node<T>* node)
{
	return node->GetLeft() ? FindMinNode(node->GetLeft()) : node;
}

template<typename T>
Node<T>* BinaryTree<T>::RemoveMinElement(Node<T>* node)
{
	if (node->GetLeft() == nullptr)
		return node->GetRight();
	node->SetLeft(RemoveMinElement(node->GetLeft()));
	return node;
}

template<typename T>
void BinaryTree<T>::RemoveElement(T value)
{
	if (_root->GetValue() == value)
		_root = RemoveElement(value, _root);
	else
		RemoveElement(value, _root);
}

template<typename T>
Node<T>* BinaryTree<T>::RemoveElement(T value, Node<T>* node)
{
	if (!node) return nullptr;
	if (value < node->GetValue())
		node->SetLeft(RemoveElement(value, node->GetLeft()));
	else if (value > node->GetValue())
		node->SetRight(RemoveElement(value, node->GetRight()));
	else
	{
		Node<T>* left = node->GetLeft();
		if (left)
			left->SetPrevious(node->GetPrevious());
		Node<T>* right = node->GetRight();
		if (right)
			right->SetPrevious(node->GetPrevious());
		delete node;
		if (!right) return left;
		Node<T>* minNode = FindMinNode(right);
		minNode->SetRight(RemoveMinElement(right));
		minNode->SetLeft(left);
		return minNode;
	}
	return node;
}

template<typename T>
void BinaryTree<T>::Show()const
{
	ShowTree(_root, 0);
}

template<typename T>
void ShowTree(Node<T>* root, int space = 0) {
	if (!root)
		return;
	space += 2;
	ShowTree(root->GetRight(), space);
	for (int i = 2; i < space; ++i)
		cout << "  ";
	cout << root->GetValue() << endl;
	ShowTree(root->GetLeft(), space);
}


template<typename T>
void BinaryTree<T>::DisposeElement(Node<T>* node)
{
	try
	{
		if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
		{
			delete node;
			return;
		}
		if (node->GetLeft() != nullptr)
			DisposeElement(node->GetLeft());
		if (node->GetRight() != nullptr)
			DisposeElement(node->GetRight());
	}
	catch (...)
	{
		cout << "Error in dispose element method!!!" << endl;
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	if (_root != nullptr)
		DisposeElement(_root);
}

template<typename T>
TreeIterator<T> BinaryTree<T>::Begin()
{
	return TreeIterator<T>(GetMinElement(_root));
}

template<typename T>
TreeIterator<T> BinaryTree<T>::End()
{
	Node<T>* max = GetMaxElement(_root);
	if (!max)return nullptr;
	return TreeIterator<T>(max);
}

template<typename T>
class TreeIterator
{
private:
	Node<T>* _current;
public:
	TreeIterator() : _current(nullptr) {};
	TreeIterator(Node<T>* current) :_current(current) {};

	T operator++(int);

	bool operator!=(TreeIterator iter);
	bool operator==(TreeIterator iter);

	T operator* ();
	Node<T>* operator->();
};

template<typename T>
T TreeIterator<T>::operator++(int)
{
	Node<T>* node;

	if (_current->GetRight() != nullptr)
	{
		_current = _current->GetRight();

		while (_current->GetLeft() != nullptr) {
			_current = _current->GetLeft();
		}
	}
	else
	{

		node = _current->GetPrevious();
		while (node != nullptr && _current == node->GetRight())
		{
			_current = node;
			node = node->GetPrevious();
		}
		_current = node;
	}
	return _current->GetValue();
}
template<typename T>
bool TreeIterator<T>::operator==(TreeIterator<T> iter)
{
	if (_current == iter._current)
		return true;
	return false;
}

template<typename T>
bool TreeIterator<T>::operator!=(TreeIterator<T> iter)
{
	return !(*this == iter);
}


template<typename T>
T TreeIterator<T>::operator*() { try { return _current->GetValue(); } catch (...) { cout << "Error in operator* method!!!"; } }

template<typename T>
Node<T>* TreeIterator<T>::operator->() { try { return _current; } catch (...) { cout << "Error in operator-> method!!!"; } }


template<typename T>
void InLineShow(BinaryTree<T>* tree)
{
	TreeIterator<T> it = tree->Begin();
	while (it != tree->End())
	{
		cout << *it << " ";
		it++;
	}
	cout << *it << endl;
}


int main()
{

	BinaryTree<int>* tree = new BinaryTree<int>();

	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "1 - add node to the tree\n";
		cout << "2 - delete node from the tree\n";
		cout << "3 - print tree\n";
		cout << "4 - search element\n";
		cout << "5 - set is unique state\n";
		cout << "6 - show in line\n";
		cout << "7 - exit\n";
		int choice = 0;
		do
		{
			cout << "Your choice: ";
			cin >> choice;
		} while (choice < 0 || choice > 7);
		switch (choice)
		{
		case 1:
		{
			cout << "Enter value: ";
			int value;
			cin >> value;
			tree->AddElement(value);
			break;
		}
		case 2:
		{
			cout << "Enter value to delete: ";
			int value;
			cin >> value;
			tree->RemoveElement(value);
			break;
		}
		case 3:
			tree->Show();
			system("pause");
			break;
		case 4:
		{
			cout << "Enter value to find: ";
			int value;
			cin >> value;

			Node<int>* found = tree->SearchElement(value);
			if (found != nullptr)
				cout << "Your element: " << found->GetValue() << endl;
			else
				cout << "Element \"" <<value<<"\" not found!!!";
			system("pause");
			break;
		}
		case 5:
		{
			char ch = ' ';
			do
			{
				cout << "Unique(y/n):";
				rewind(stdin);
				cin >> ch;
			} while (ch != 'y' && ch != 'n');
			if (ch == 'y')
				tree->SetIsUnique(true);
			else
				tree->SetIsUnique(false);
			break;
		}
		case 6:
			InLineShow<int>(tree);
			system("pause");
			break;
		case 7:
			flag = false;
			break;
		default:
			break;
		}
	}

	delete tree;
	return 0;
}