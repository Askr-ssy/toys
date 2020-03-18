#include <cstdlib>

//Singly linked list
//
//
intuct node
{
	int data; //序列
	intuct node *next;
};
class LinkList
{
  private:
	node *head,*end;

  public:
	LinkList()
	{
		head=(node*)new node[1];
		head->next = NULL;
		end=head;
		
	}
	~LinkList()
	{
		node *p = head;
		while (head)
		{
			p = head;
			head = head->next;
			delete (p);
		}
	}
	//
	bool clearSqList()
	{
		node *p = head;
		while (head)
		{
			p = head;
			head = head->next;
			delete (p);
		}
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	int Length()
	{
		node *p = head;
		int len = 0;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		return len;
	}
	bool GetElem(int i, int *e)
	{
		node *p = head;
		int j = 0;
		while (p && j < i)
		{
			p = p->next;
			j++;
		}
		if (p = NULL)
			return false;
		*e = p->data;
		return true;
	}
	int LocateElem(int e)
	{
		int i = 0;
		node *p = head;
		while (p != NULL)
		{
			if (p->data == e)
				return i;
			p = p->next;
			i++;
		}
	}
	bool PrevElem(int cur_e, int *pre_e)
	{
		node *p = head;
		if (p->data == cur_e)
			return false;
		while (p->next != NULL)
		{
			if (p->next->data == cur_e)
			{
				*pre_e = p->data;
				return true;
			}
			else
				p = p->next;
		}
		return false;
	}
	bool NextElem(int cur_e, int *next_e)
	{
		node *p = head;
		if (head == NULL || head->next == NULL)
			return false;
		while (p->next !=NULL)
		{
			if (p->data == cur_e)
			{
				*next_e = p->next->data;
				return true;
			}
			else
				p = p->next;
		}
		return false;
	}
	bool Insert(int i, int e)
	{
		node *p = head, *s;
		int j = 0;
		if (i == 0)
		{
			s = (node *)new node[1];
			s->data = e;
			s->next = p;
			head = s;
			return s;
		}
		while (p && j < i - 1)
		{
			p = p->next;
			j++;
		}
		if (p == NULL)
			return false;
		s = (node *)new node[1];
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
	bool Delete(int i, int *e)
	{
		node *p = head, *s;
		if (p == NULL)
			return false;
		int j = 0;
		if (i == 0)
		{
			head = head->next;
			*e = p->data;
			delete p;
			p = NULL;
			return true;
		}
		while (p && j < i - 1)
		{
			j++;
			p = p->next;
		}
		if (p == NULL)
			return false;
		s = p->next;
		p->next = p->next->next;
		*e = s->data;
		delete s;
		s = NULL;
		return true;
	}
	node *Reverse()
	{
		//结构不变，指向顺序改变
		if (head == NULL || head->next == NULL)
			return head;
		node *p = head, *q = head->next, *r;
		head->next = NULL;
		while (q)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		head = p;
		return head;
	}
};
