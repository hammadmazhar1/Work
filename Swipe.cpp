#include "Swipe.h"

Swipe* Swipe::create() {Swipe* swipe = new Swipe(); swipe->autorelease(); return swipe;}
Swipe::Swipe() {s_lines = new LinkedList<s_Line>; s_points = new LinkedList<s_Point>;}
Swipe::~Swipe() {delete s_lines; delete s_points;}

void Swipe::draw() {
	ccDrawColor4F(209,238,238,255);
	glLineWidth(4);
	ListItem<s_Line>* temp = s_lines->head;
	for (int i = 0; i < s_lines->length; i++) {ccDrawLine(temp->value.pt1, temp->value.pt2); temp = temp->next;}
}

void Swipe::addLine(CCPoint pt1, CCPoint pt2) {s_lines->insertAtTail(s_Line(pt1, pt2));}
void Swipe::addPoint(CCPoint pt1) {s_points->insertAtTail(s_Point(pt1));}
void Swipe::removeLine() {s_lines->deleteCur();}