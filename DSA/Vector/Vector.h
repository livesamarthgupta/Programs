
template<typename T>
class Vector {
	int cs;
	int ms;
	T *arr
	
public:
	Vector() {
		cs = 0;
		ms = 1;
		arr = new T[ms];
	}
	
	Vector(int size) {
		cs = 0;
		ms = size;
		arr = new T[ms];
	}
	
	void push_back(const T data) {
		if(cs == ms) {
			T *oldArr = arr;
			arr = new T[ms * 2];
			for(auto i = 0; i < ms; i++) {
				arr[i] = oldArr[i];
			}
			ms = ms * 2;
			delete [] oldArr;
		}
		arr[cs++] = data;
	}
	
	void pop_back() const {
		cs--;
	}
	
	T front() const {
		return arr[0];
	}
	
	T back() const {
		return arr[cs - 1];
	}
	
	bool empty() const {
		return cs == 0;
	}
	
	int capacity() const {
		return ms;
	}
	
	T at(const int i) const {
		return arr[i];
	}
	
	T operator[](const int i) {
		return arr[i];
	}
	
	int size() const {
		return cs;
	}
	
	
};
