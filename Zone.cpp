#include "Zone.h"

Zone::Zone()
{
}

void Zone::addElement(const Vec2d& element)
{
	locations.push_back(element);
}

void Zone::init_trianglesPoints()
{
	for (int i = 1; i < locations.size();i++) {
		int j = i - 1;
		triPoints.push_back(Triangle(center, locations[i], locations[j]));
	}
}

bool Zone::isInside(const Vec2d& test)
{
	std::vector<int>result;
	for (auto& i : triPoints)
	{
		result.push_back(i.isInside(test));
	}
	for (int i = 1; i < result.size(); i++) {
		int j = i - 1;
		if (result[i] == 1 && result[j] == 1)
			result[i] *= result[j];
		else
			result[i] += result[j];
	}
	if (result[result.size()-1] == 1)
		return true;
	else
		return false;
}

Vec2d Zone::minLongitude()
{
	std::vector<Vec2d>temp;
	temp = locations;
	std::sort(temp.begin(), temp.end(), [](const Vec2d& lhs, const Vec2d& rhs) { return lhs.y < rhs.y;});
	return temp[0];
}

Vec2d Zone::maxLongitude()
{
	std::vector<Vec2d>temp;
	temp = locations;
	std::sort(temp.begin(), temp.end(), [](const Vec2d& lhs, const Vec2d& rhs) { return lhs.y > rhs.y; });
	return temp[0];
}

Vec2d Zone::minLatitude()
{
	std::vector<Vec2d>temp;
	temp = locations;
	std::sort(temp.begin(), temp.end(), [](const Vec2d& lhs, const Vec2d& rhs) { return lhs.x < rhs.x; });
	return temp[0];
}

Vec2d Zone::maxLatitude()
{
	std::vector<Vec2d>temp;
	temp = locations;
	std::sort(temp.begin(), temp.end(), [](const Vec2d& lhs, const Vec2d& rhs) { return lhs.x > rhs.x; });
	return temp[0];
}

void Zone::getCenter()
{
	Vec2d minX = this->minLongitude();
	Vec2d maxX = this->maxLongitude();
	Vec2d minY = this->minLatitude();
	Vec2d maxY = this->maxLatitude();
	center = { ((minX.x + maxX.x)/ 2)+0.001f,((minY.y + maxY.y) / 2)+0.001f};
}
