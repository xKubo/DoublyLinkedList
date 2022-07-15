#pragma once

namespace LinkedList
{
	struct Empty {} ;
	template <typename T, typename Tag = Empty>
	struct CLinkedListItem
	{
		CLinkedListItem<T, Tag>* pPrev = nullptr;
		CLinkedListItem<T, Tag>* pNext = nullptr;
	};

	template <typename T, typename Tag = Empty>
	struct CLinkedList
	{
		CLinkedList() : m_Size(0)
		{

		}

		using TEl = T;
		using TTag = Tag;

		void Insert(CLinkedListItem<T, Tag> *pel)
		{
			if (m_pHead == nullptr)
			{
				m_pHead = pel;
				pel->pNext = pel->pPrev = m_pHead;
			}


				
		}

		void Remove(CLinkedListItem<T, Tag> *pel)
		{
			pel->pNext->pPrev = pel->pPrev;
			pel->pPrev->pNext = pel->pNext;
		}

		int size() const
		{
			return m_Size;
		}

		bool empty() const
		{
			return m_Size == 0;
		}

		T* begin() { return m_pHead; };
		T* end() { return m_pHead; };

		const T* begin() const {
			return m_pHead;
		}

		const T* end() const
		{
			return m_pHead;
		}

		int m_Size = 0;
		CLinkedListItem<T, Tag>* m_pHead = nullptr;
	};


}
