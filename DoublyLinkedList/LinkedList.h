#pragma once

namespace LinkedList
{
	struct Empty {};

	template <typename T, typename Tag = Empty>
	struct CLinkedListItem
	{
		CLinkedListItem<T, Tag>* pPrev = nullptr;
		CLinkedListItem<T, Tag>* pNext = nullptr;
	};

	template <typename T, typename Tag>
	struct CLinkedListIterator : public boost::iterator_facade<
		CLinkedListIterator<T, Tag>,
		T,
		boost::bidirectional_traversal_tag>
	{
		CLinkedListIterator() = default;
		CLinkedListIterator(CLinkedListItem<T, Tag>* pVal) :
			m_pValue(pVal)
		{

		}

	private:
		friend class boost::iterator_core_access;

		void increment() { m_pValue = m_pValue->pNext; }

		void decrement() { m_pValue = m_pValue->pPrev; }

		bool equal(CLinkedListIterator<T, Tag> const& other) const
		{
			return this->m_pValue == other.m_pValue;
		}

		T& dereference() const { return *static_cast<T*>(m_pValue); }

		CLinkedListItem<T, Tag>* m_pValue= nullptr;
	};

	template <typename T, typename Tag>
	struct CLinkedListConstIterator : public boost::iterator_facade<
		CLinkedListConstIterator<T, Tag>,
		const T,
		boost::bidirectional_traversal_tag>
	{
		CLinkedListConstIterator() = default;
		CLinkedListConstIterator(const CLinkedListItem<T, Tag>* pVal) :
			m_pValue(pVal)
		{

		}

	private:
		friend class boost::iterator_core_access;

		void increment() { m_pValue = m_pValue->pNext; }

		void decrement() { m_pValue = m_pValue->pPrev; }

		bool equal(CLinkedListConstIterator<T, Tag> const& other) const
		{
			return this->m_pValue == other.m_pValue;
		}

		const T& dereference() const { return *static_cast<const T*>(m_pValue); }

		const CLinkedListItem<T, Tag>* m_pValue = nullptr;
	};

	template <typename T, typename Tag = Empty>
	struct CLinkedList
	{
		CLinkedList() : m_Size(0)
		{

		}

		using TEl = T;
		using TTag = Tag;

		void Insert(T* pel)
		{
			auto pItem = static_cast<CLinkedListItem<T, Tag>*>(pel);
			pItem->pNext = m_Head.pNext;
			m_Head.pNext = pItem;
			pItem->pPrev = m_Head.pNext->pPrev;
			m_Head.pNext->pPrev = pItem;
			++m_Size;

		}

		void Remove(T* pel)
		{

			auto pItem = static_cast<CLinkedListItem<T, Tag>*>(pel);
			pItem->pNext->pPrev = pItem->pPrev;
			pItem->pPrev->pNext = pItem->pNext;
			--m_Size;
		}

		int size() const
		{
			return m_Size;
		}

		bool empty() const
		{
			return m_Size == 0;
		}

		CLinkedListIterator<T, Tag> begin() {
			return { m_Head.pNext };
		}

		CLinkedListIterator<T, Tag> end()
		{
			return { &m_Head };
		}

		CLinkedListConstIterator<T, Tag> begin() const {
			return m_Head.pNext;
		}

		CLinkedListConstIterator<T, Tag> end() const
		{
			return &m_Head;
		}

		int m_Size = 0;
		CLinkedListItem<T, Tag> m_Head;
	};


}
