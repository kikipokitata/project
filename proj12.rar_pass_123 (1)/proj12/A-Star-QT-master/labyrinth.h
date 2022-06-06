#pragma once
#include "util.h"

struct node;
class Labyrinth
{
public:
    explicit Labyrinth(int width, int height, bool random = true, int start_x = 0, int start_y = 0, int finish_x = 0, int finish_y = 0);
	node getStartNode();
	node getGoalNode();
    void setWeight(int dW, int drW, int lW);
	bool findWay();
	void drawWay();
	void printLabyrinth();
	void printDebug();
    node **getLabyrinth();
private:
	node** labyrinth;
	node start;
	node goal;
	int height;
	int width;
	bool status;
	void calculateHCostForNode(int x, int y);
	void calculateFCostForNode(int x, int y);
	void find_path();
	void draw_path();

    int ROAD_WEIGHT;
    int DIRTY_ROAD_WEIGHT;
    int LAKE_WEIGHT;
};





