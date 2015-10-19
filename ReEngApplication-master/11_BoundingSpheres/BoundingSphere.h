#ifndef _BOUNDING_SPHERE_
#define _BOUNDING_SPHERE_

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>

class BoundingSphere
{
public:
	vector3 center;
	float fRadius;
	int nSubdivisions;
	std::vector<vector3> myList;
	bool isColliding;
	PrimitiveClass* m_pSphere;

	BoundingSphere(std::vector<vector3> listOfVertex);

	//void InitVariable();
	bool IsColliding(BoundingSphere* pOther);
	void UpdatePosition(vector3 v3Input);
	//void SetCenter(vector3 centerVertex);

};

#endif //_BOUNDING_SPHERE_