#pragma once
#include<vector>
#include"Vec2d.h"
#include"Vec2d.h"
#include"Triangle.h"
#include<algorithm>
class Zone
{
 public:
	  std::vector<Vec2d>locations;
	  std::vector<Triangle>triPoints;
	  Vec2d center;

	  Zone();
	  void addElement(const Vec2d& element);
	  void init_trianglesPoints();
	  bool isInside(const Vec2d& test);
	  void getCenter();
 private:
	  Vec2d minLongitude();
	  Vec2d maxLongitude();
	  Vec2d minLatitude();
	  Vec2d maxLatitude();
};

