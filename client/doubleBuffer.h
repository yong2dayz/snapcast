#ifndef DOUBLE_BUFFER_H
#define DOUBLE_BUFFER_H

#include<deque>
#include<algorithm>

template <class T>
class DoubleBuffer
{
public:
	DoubleBuffer(size_t size) : bufferSize(size)
	{		
	}

	inline void add(const T& element)
	{
		buffer.push_back(element);
		if (buffer.size() > bufferSize)
			buffer.pop_front();
	}

	T median() const
	{
		if (buffer.empty())
			return 0;
		std::deque<T> tmpBuffer(buffer.begin(), buffer.end());
		std::sort(tmpBuffer.begin(), tmpBuffer.end());
		return tmpBuffer[tmpBuffer.size() / 2];
	}

	T mean() const
	{
		if (buffer.empty())
			return 0;
		double mean = 0.;
		for (size_t n=0; n<buffer.size(); ++n)
			mean += (float)buffer[n] / (float)buffer.size();
		return (T)mean;
	}

	T percentil(unsigned int percentil) const
	{
		if (buffer.empty())
			return 0;
		std::deque<T> tmpBuffer(buffer.begin(), buffer.end());
		std::sort(tmpBuffer.begin(), tmpBuffer.end());
		return tmpBuffer[(size_t)(tmpBuffer.size() * ((float)percentil / (float)100))];
	}

	inline bool full() const
	{
		return (buffer.size() == bufferSize);
	}

	inline void clear()
	{
		buffer.clear();
	}

	inline size_t size() const
	{
		return buffer.size();
	}

private:
	size_t bufferSize;	
	std::deque<T> buffer;
	
};



#endif