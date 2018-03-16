#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t():
{
	size_ = 0;
	capacity_ = 0;
	elements_ = new int [capacity_];
}

vector_t::vector_t(vector_t const & other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
	
	for (std::size_t i=0; i<other.capacity_; i++) {
		elements_[i] = other.elements_[i];
	}	
}

vector_t & vector_t::operator =(vector_t const & other)
{
	capicity_=other.capicity_;
	size_=other.size_;
	elements_ = new std::size_t[capacity_];
	for(std::size_t i=0;i<other.capicity_;i++)
	{
		elements_[i]=other.elements_[i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	bool succ=true;
	 if(size_==other.size_) && (capicity_==other.capicity_)
	 {
		 for(size_t i=0;i<size_;i++)
		 {
			 if(elements_[i]!=other.elements_[i])
			 {
				 succ=false;
				 return succ;
			 }
		 }
	 }
	else succ=false;
	return succ;
}

vector_t::~vector_t()
{
	delete []elements_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capicity_;
}

void vector_t::push_back(int value)
{
	size_++;
	if(capicity_<size_){
		if(capisity_=0) capicity_=1;
		else capicity_*=2;
		int * p = new [capacity_];
        	for (std::size_t i=0; i<size_; i++) {
            		p[i] = elements_[i];
        	}
        	delete [] elements_;
        	elements_ = p;
	}
	elements_[size_++]=value;
	
}

void vector_t::pop_back()
{
    if(size_==0) return;
    size_--;
    if( size_ == capacity_/4 ){
        capacity_ /=2;
        int * p = new [capacity_];
        for (std::size_t i=0; i<size_; i++) {
            p[i] = elements_[i];
        }
        delete [] elements_;
        elements_ = p;
    }
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool succ=true;
	if(lhs==rhs)
	{
		succ=false
	}
	return succ;
}
