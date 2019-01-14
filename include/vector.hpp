#include <iostream>
#include <algorithm>
#include <cassert>
template <typename T>
class vector_t
{
private:
	T * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t(vector_t && other)
	vector_t & operator =(vector_t const & other);
	vector_t & operator =(vector_t && other)
	~vector_t();
	std::size_t size() const;
	std::size_t capacity() const;
	T & at(std::size_t index);
	void push_back(T value);
	void pop_back();
	T & operator [](std::size_t index);
	T operator [](std::size_t index) const;
	bool operator ==(vector_t const & other) const;
};
template <typename T>
vector_t<T>::vector_t()
{
	size_ = 0;
	capacity_ = 0;
	elements_ = new T [capacity_];
}
template <typename T>
vector_t<T>::vector_t(vector_t<T> const & other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;
	if(elements_!=nullptr)
		delete[] elements;
	elements_ = new T [capacity_];	
	for (std::size_t i=0; i<size_; i++) {
		elements_[i] = other.elements_[i];
	}	
}
template <typename T>
vector_t<T>::vector_t(vector_t<T> && other)
{
	std::swap(size_,other.size_);
	std::swap(capacity_,other.capacity_);
	std::swap(elements_,other.elements);
}
template <typename T>
T & vector_t<T>::at(std::size_t index)
	{
		if (index >= size_)
		{
			throw std::out_of_range("Error");
		}
		return (*this)[index];
	}
template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{
	size_=other.size_;
	capacity_=other.capacity_;
	if(elements_ != nullptr) delete[] elements_;
	elements_ = new T[capacity_];
	for(std::size_t i=0;i<other.capacity_;i++)
	{
		elements_[i]=other.elements_[i];
	}
	return *this;
}
template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t && other)
{
	std::swap(size_,other.size_);
	std::swap(capacity_,other.capacity_);
	std::swap(elements_,other.elements);
}
template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
	bool succ=false;
	 if((size_==other.size_) && (capacity_==other.capacity_))
	 {
		 for(size_t i=0;i<other.size_;i++)
		 {
			 if(elements_[i]!=other.elements_[i])
			 {
				 return succ;
			 }
		 }
		 succ=!succ;
	 }
	return succ;
}
template <typename T>
vector_t<T>::~vector_t()
{
	delete []elements_;
}
template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}
template <typename T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}
template <typename T>
void vector_t<T>::push_back(T value)
{
	if(capacity_==size_){
		if(capacity_==0) 
			capacity_=1;
		else capacity_*=2;
		T * p = new T [capacity_];
        	for (std::size_t i=0; i<size_; i++) {
            		p[i] = elements_[i];
        	}
        	delete [] elements_;
        	elements_ = p;
	}
	elements_[size_]=value;
	++size_;
	
}
template <typename T>
void vector_t<T>::pop_back()
{
    if(size_==0) return;
    size_--;
    if( size_ == capacity_/4 ){
        capacity_ /=2;
        T * p = new T [capacity_];
        for (std::size_t i=0; i<size_; i++) {
            p[i] = elements_[i];
        }
        delete [] elements_;
        elements_ = p;
    }
}
template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
	return elements_[index];
}
template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
	return elements_[index];
}
template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	bool succ=true;
	if(lhs==rhs)
	{
		succ=false;
	}
	return succ;
}


