#pragma once

#include <algorithm>
#include <new>
#include <stdexcept>
#include <iostream>

template <typename T>
class CMyArray
{
	template <bool IsConst>
	class IteratorBase {
		friend class IteratorBase<true>;
	public:
		using MyType = IteratorBase<IsConst>;
		using value_type = std::conditional_t<IsConst, const T, T>;
		using reference = value_type&;
		using pointer = value_type*;
		using difference_type = ptrdiff_t;
		using iterator_category = std::random_access_iterator_tag;

		IteratorBase() = default;
		IteratorBase(const IteratorBase<false>& other)
			: m_item(other.m_item)
		{
		}

		reference& operator*() const
		{
			return *m_item;
		}

		MyType& operator+=(difference_type offset)
		{
			m_item += offset;
			return *this;
		}

		MyType operator+(difference_type offset) const
		{
			MyType self(m_item);
			return self += offset;
		}

		MyType& operator-=(difference_type offset)
		{
			m_item -= offset;
			return *this;
		}

		MyType operator-(difference_type offset) const
		{
			MyType self(m_item);
			return self -= offset;
		}

		MyType& operator++()
		{
			return *this += 1;
		}

		MyType operator++(int)
		{
			return ++(*this);
		}

		MyType& operator--()
		{
			return *this -= 1;
		}

		MyType operator--(int)
		{
			return --(*this);
		}

		friend MyType operator+(difference_type offset, const MyType& it)
		{
			return it + offset;
		}

		friend MyType operator-(difference_type offset, const MyType& it)
		{
			return it - offset;
		}

		friend bool operator==(const MyType& first, const MyType& last)
		{
			return first.m_item == last.m_item;
		}

		friend bool operator!=(const MyType& first, const MyType& last)
		{
			return first.m_item != last.m_item;
		}


	public:
		IteratorBase(T* item)
			: m_item(item)
		{
		}

	protected:
		T* m_item = nullptr;
	};

public:

	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	CMyArray(CMyArray&& other) 
		: m_begin(other.m_begin)
		, m_end(other.m_end)
		, m_endOfCapacity(other.m_endOfCapacity)
	{
		other.m_begin = nullptr;
		other.m_end = nullptr;
		other.m_endOfCapacity = nullptr;
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

	CMyArray<T>& operator=(const CMyArray<T>& arr) //copy and swap
	{
		if (&arr != this)
		{
			CMyArray copyArray(arr);

			std::swap(m_begin, copyArray.m_begin);
			std::swap(m_end, copyArray.m_end);
			std::swap(m_endOfCapacity, copyArray.m_endOfCapacity);
		}
		return *this;
	}

	CMyArray<T>& operator=(CMyArray<T>&& arr)
	{
		if (&arr != this)
		{
			Clear();
			m_begin = arr.m_begin;
			m_end = arr.m_end;
			m_endOfCapacity = arr.m_endOfCapacity;
			arr.m_begin = nullptr;
			arr.m_end = nullptr;
			arr.m_endOfCapacity = nullptr;
		}
		return *this;
	}

	void PushBack(const T& value)
	{
		if (m_end == m_endOfCapacity)
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else 
		{
			new (m_end) T(value);
			++m_end;
		}

	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	T& operator[](size_t index)
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}
		return *(m_begin + index);
	}

	const T& operator[](size_t index) const
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}
		return *(m_begin + index);
	}

	void Resize(size_t size)
	{
		if (size != 0)
		{
			T* newEnd = m_end;
			if (size > GetCapacity())
			{
				auto newBegin = RawAlloc(size);
				newEnd = newBegin;
				try //если выбрасывается исключения, то не все элементы возвращаюся. 3 случая изменения размеров
				{
					CopyItems(m_begin, m_end, newBegin, newEnd);
					DeleteItems(m_begin, m_end);
				}
				catch (...)
				{
					DeleteItems(newBegin, newEnd);
					throw;
				}
				m_begin = newBegin;
				m_end = newEnd;
				m_endOfCapacity = m_begin + size;
			}
			if (size >= GetSize())
			{
				m_end = m_begin + size;
				for (; newEnd != m_end; newEnd++)
				{
					new (newEnd) T();  // может выброситься исключение
				}
			}
			else
			{
				m_end = m_begin + size;
				DestroyItems(m_end, newEnd);
			}
		}
	}

	void Clear() //оставить вместимость
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
		m_endOfCapacity = m_end;
	}


	using iterator = IteratorBase<false>;
	using const_iterator = IteratorBase<true>;

	iterator begin()
	{
		return m_begin;
	}

	const_iterator begin() const
	{
		return m_begin;
	}

	iterator end()
	{
		return m_end;
	}

	const_iterator end() const
	{
		return m_end;
	}

	std::reverse_iterator<iterator> rbegin()
	{
		return std::reverse_iterator<iterator>(end());
	}

	std::reverse_iterator<iterator> rend()
	{
		return std::reverse_iterator<iterator>(begin());
	}

	std::reverse_iterator<const_iterator> rbegin() const
	{
		return std::reverse_iterator<const_iterator>(end());
	}

	std::reverse_iterator<const_iterator> rend() const
	{
		return std::reverse_iterator<const_iterator>(begin());
	}

	private:

		static void DeleteItems(T* begin, T* end)
		{
			DestroyItems(begin, end);
			RawDealloc(begin);
		}

		static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
		{
			for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
			{
				new (dstEnd) T(*srcBegin);
			}
		}

		static void DestroyItems(T* from, T* to)
		{
			while (to != from)
			{
				--to;
				to->~T();
			}
		}

		static T* RawAlloc(size_t n)
		{
			size_t memSize = n * sizeof(T);
			T* p = static_cast<T*>(malloc(memSize));
			if (!p)
			{
				throw std::bad_alloc();
			}
			return p;
		}

		static void RawDealloc(T* p)
		{
			free(p);
		}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};
