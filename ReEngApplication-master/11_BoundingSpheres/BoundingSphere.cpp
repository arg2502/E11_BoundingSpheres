#include "BoundingSphere.h"
//void BoundingSphere::InitVariable()
//{
//	
//}
BoundingSphere::BoundingSphere(std::vector<vector3> listOfVertex)
{
	myList = listOfVertex;
	fRadius = 1.0f;
	nSubdivisions = 6;
	isColliding = false;
	m_pSphere = new PrimitiveClass();
	m_pSphere->GenerateSphere(fRadius, nSubdivisions, REGREEN);

}
bool BoundingSphere::IsColliding(BoundingSphere* other)
{
	// magnitude
	vector3 distance = other->center - center;
	float magnitude = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;
	magnitude = sqrt(magnitude);

	if ((fRadius + other->fRadius) > (magnitude))
	{
		isColliding = true;
		return isColliding;
	}
	else
	{
		isColliding = false;
		return isColliding;
	}
}

// set center of sphere equal to shape's position
void BoundingSphere::UpdatePosition(vector3 pos)
{
	center = pos;
}

//void BoundingSphere::SetCenter(vector3 center)
//{
//
//}