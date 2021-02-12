#include "TreeNode.h"
#include <iostream>
#include "raylib.h"

TreeNode::TreeNode(int value)
{
	m_value = value;
}

void TreeNode::draw(int x, int y, bool selected)
{
	//creates an array to store the value converted to a string
	static char buffer[10];

	//convertrs the value given to a string and stores it in the buffer
	sprintf(buffer, "%d", m_value);

	//draws the outer circle of the node
	DrawCircle(x, y, 30, YELLOW);

	//if the node is selected, make its color green, otherwise make it black
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	//draws the text in the center of the node
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}