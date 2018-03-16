#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t():elements_{nullptr},size_{0},capicity_{0}
{
}

vector_t::vector_t(vector_t const & other)
{
	capicity_=other.capicity_;
	size_=other.size;
	elements = new [capacity_] int;
	for(std::size_t i=0;i<other.capicity;i++)
	{
		elements_[i]=other.elements[i];
	}	
}

vector_t & vector_t::operator =(vector_t const & other)
{
	capicity_=other.capicity_;
	size_=other.size;
	elements = new std::size_t[capacity_];
	for(std::size_t i=0;i<other.capicity;i++)
	{
		elements_[i]=other.elements[i];
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
		capicity_*=2;
	}
	elements_[size-1]=value;
	
}

void vector_t::pop_back()
{
	size--;
	if(size_==capicity_/4)
	{
		capicity_/=2;
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
