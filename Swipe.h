#include "cocos2d.h"

USING_NS_CC;
using namespace std;

template <class T>
class ListItem {
	public:
		T value;
		ListItem<T> *next;
		ListItem<T> *prev;

		ListItem(T theVal)
		{
			this->value = theVal;
			this->next = NULL;
			this->prev = NULL;
		}
};

template <class T>
class LinkedList
{
	public:
		ListItem<T> *head; ListItem<T> *cur;
		int length;

		// Constructor
		LinkedList() {head = cur = NULL; length = 0;}

		// Destructor
		~LinkedList() {while (head) {deleteCur();}}

		// Insertion Functions
		void insertAtTail(T item) {
			if (!head) {head = cur = new ListItem<T>(item); length++; cur->next = head; cur->prev = head;}
			else {
				if (length < 500) {
					ListItem<T>* temp = new ListItem<T>(item); 
					temp->prev = cur; temp->next = cur->next; temp->next->prev = temp; cur->next = temp; length++;
					cur = temp;
					// cur->next = head;
				} else {
					cur->next->value = item;
					cur = cur->next;
				}
			}
		}

		// Deletion Functions
		void deleteCur() {
			if (length == 1) {delete head; head = cur = NULL;}
			else {
				ListItem<T>* temp = cur->next; cur->next = temp->next; 
				if (temp == head) {head = temp->next;}
				delete temp; cur->next->prev = cur;
			}
			length--;
		}
};

// ***************************************************************************

class s_Point {
	public:
		CCPoint pt;
		float r, g, b;
		s_Point() {pt = ccp(0,0); r = g = b = 1;}
		s_Point(CCPoint _pt) {pt = _pt; r = g = b = 1;}
};

class s_Line {
	public:
		CCPoint pt1, pt2;
		float r, g, b, duration;
		s_Line() {pt1 = pt2 = ccp(0,0); r = g = b = 1; duration = 0;}
		s_Line(CCPoint _pt1, CCPoint _pt2) {pt1 = _pt1; pt2 = _pt2; r = g = b = 1; duration = 0;}
};

class Swipe : public CCNode {
	public:
		LinkedList<s_Line>* s_lines;
		LinkedList<s_Point>* s_points;
		
		static Swipe* create();
		Swipe();
		~Swipe();
		virtual void draw();
		
		void addLine(CCPoint pt1, CCPoint pt2);
		void addPoint(CCPoint pt1);
		void removeLine();
};
