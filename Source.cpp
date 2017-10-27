#include <iostream>
using namespace std;
const int MAXSIZE = 10;

class Queue {
private:
	int _front;
	int _rear;
	int _array[MAXSIZE];

	bool isEmpty() {
		return (this->_front == -1 && this->_rear == -1);
	}
	bool isFull() {
		return (this->_rear == (sizeof(this->_array)/sizeof(int) - 1));
	}
public:
	Queue() {
		this->_front = -1;
		this->_rear = -1;
	}

	void Enqueue(int info) {
		if (this->isEmpty()) {
			this->_front++;
			this->_rear++;
		}

		else if (this->isFull()) {
			cout << "Queue is full!" << endl;
			return;
		}

		else {
			this->_rear++;
		}

		this->_array[this->_rear] = info;
	}

	int Dequeue() {
		if (this->isEmpty()) {
			throw exception("Queue is empty!");
		}
		else if (this->_front == this->_rear) {
			int temp = this->_array[this->_front];
			this->_front = -1;
			this->_rear = -1;
			return temp;
		}
		else {
			int temp = this->_array[this->_front++];
			return temp;
		}
	}

	void PrintQueue() {
		cout << "Printing queue\n-----------------------------------------------\n";
		for (int i = this->_front; i <= this->_rear; i++) {
			cout << "index [" << i << "] = " << this->_array[i] << endl;
		}
		cout << endl;
	}
	void PrintBuffer() {
		cout << "Printing buffer\n-----------------------------------------------\n";
		for (int i = 0; i < sizeof(this->_array) / sizeof(int); i++) {
			cout << "index [" << i << "] = " << this->_array[i] << endl;
		}
		cout << endl;
	}
	void PrintIndexerStatus() {
		cout << "Printing Indexers status\n-----------------------------------------------\n";
		cout << "front = " << this->_front << endl;
		cout << "rear  = " << this->_rear << endl;
	}
	void PrintAll() {
		this->PrintQueue();
		this->PrintIndexerStatus();
		this->PrintBuffer();
	}
};

int main() {
	Queue q;
	for (int i = 0; i < 5; i++)
		q.Enqueue(i);

	q.PrintAll();

	for (int i = 0; i < 3; i++)
		cout << "Dequeue: " << q.Dequeue() << endl;

	q.PrintAll();
	getchar();
	return 0;
}
