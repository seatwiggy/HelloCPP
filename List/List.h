#pragma once
#include <initializer_list>
#include <limits>
#include <iostream>
namespace nc {
	template<typename T>
	class list {
		struct node_t {
			node_t(const T& value) : _value{ value } {}

			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};
	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		list(const list& other);
		~list();

		list& operator = (const list& other);

		T& front();
		//const T& front() const;

		T& back();
		//const T& back() const;

		void push_front(const T& value);
		void pop_front();

		void push_back(const T& value);
		void pop_back();

		void remove(const T& value);
		void reverse(); // see references for implementation
		//void resize(size_t count, const T& value = T{});
		void clear(); // search online for implementation

		bool empty() { return (size() == 0); }
		size_t size(); // see references for implementation
		size_t max_size() { return std::numeric_limits<size_t>::max(); }

		std::ostream& write(std::ostream& stream);
	private:
		node_t* tail();
	private:
		node_t* _head{ nullptr };
	};

	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	// Definitions

	// Constructors / Destructor
	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {
		for (auto i = ilist.begin(); i != ilist.end(); i++) {
			push_back(*i);
		}
	}

	template<typename T>
	list<T>::list(const list& other) {
		node_t* node = other._head;
		while (node) {
			push_back(node->_value);
			node = node->_next;
		}
	}

	template<typename T>
	list<T>::~list() {
		clear();
	}

	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		clear();
		node_t* node = other._head;
		while (node) {
			push_back(node->_value);
			node = node->_next;
		}
		return *this;
	}

	template<typename T>
	T& list<T>::front() { return _head->_value; }

	template<typename T>
	T& list<T>::back() { return tail()->_value; }

	template<typename T>
	void list<T>::push_front(const T& value) {
		node_t* new_node = new node_t{ value };
		if (!_head) {
			_head = new_node;
			return;
		}
		_head->_prev = new_node;
		new_node->_next = _head;
		_head = new_node;
	}

	template<typename T>
	void list<T>::pop_front() {
		node_t* new_head = _head->_next;
		delete _head;
		new_head->_prev = nullptr;
		_head = new_head;
	}

	template<typename T>
	void list<T>::push_back(const T& value) {
		node_t* new_tail = new node_t{ value };
		node_t* old_tail = tail();
		if (!_head) {
			_head = new_tail;
			return;
		}
		old_tail->_next = new_tail;
		new_tail->_prev = old_tail;
	}

	template<typename T>
	void list<T>::pop_back() {
		node_t* new_tail = tail()->_prev;
		delete tail();
		new_tail->_next = nullptr;
	}

	template<typename T>
	void list<T>::remove(const T& value) {
		node_t* node = _head;
		while (node) {
			if (node->_value == value) {
				node_t* next_node = node->_next;
				node_t* prev_node = node->_prev;
				if (prev_node) prev_node->_next = next_node;
				if (next_node) next_node->_prev = prev_node;

				if (_head == node) _head = next_node;
				delete node;
				node = next_node;
			}
			else node = node->_next;
		}
	}

	template<typename T>
	void list<T>::reverse() {
		node_t* node = _head;
		while (node) {
			node_t* next_node = node->_next;
			node->_next = node->_prev;
			node->_prev = next_node;
			if (!next_node) _head = node;
			node = node->_prev;
		}
	}

	template<typename T>
	void list<T>::clear() {
		node_t* node = _head;
		while (node) {
			node_t* next_node = node->_next;
			delete node;
			if (next_node) node = next_node;
			else delete node;
		}
	}

	template<typename T>
	size_t list<T>::size() {
		int size = 0;
		node_t* node = _head;
		while (node) {
			size++;
			node = node->_next;
		}
		return size;
	}

	template<typename T>
	typename list<T>::node_t* list<T>::tail() {
		node_t* node = _head;
		while (node) {
			if (!node->_next) return node;
			node = node->_next;
		}
	}

	template<typename T>
	std::ostream& list<T>::write(std::ostream& stream) {
		node_t* node = _head;
		while (node) {
			stream << node->_value << " ";
			node = node->_next;
		}
		stream << std::endl;
		return stream;
	}
}