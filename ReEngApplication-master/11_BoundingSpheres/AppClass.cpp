#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Bounding Spheres: Alec Gerchman and Sarah Bishop"); // Window Name

	// Set the clear color based on Microsoft's CornflowerBlue (default in XNA)
	//if this line is in Init Application it will depend on the .cfg file, if it
	//is on the InitVariables it will always force it regardless of the .cfg
	m_v4ClearColor = vector4(0.4f, 0.6f, 0.9f, 0.0f);
}
void AppClass::InitVariables(void)
{
	m_v3Torus = vector3(3.5f, 0.0f, 0.0f);
	m_v3Cone = vector3(0.0f, 0.0f, 0.0f);

	m_pTorus = new PrimitiveClass();
	m_pTorus->GenerateTorus(1.0f, 0.7f, 10, 10, REGREEN);

	m_pCone = new PrimitiveClass();
	m_pCone->GenerateCone(1.0f, 1.0f, 10, REGREEN);
	
	// bounding spheres
	bs_Torus = new BoundingSphere(m_pTorus->GetVertices());
	bs_Cone = new BoundingSphere(m_pCone->GetVertices());

	
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update(false);

	// update spheres
	bs_Torus->UpdatePosition(m_v3Torus);
	bs_Cone->UpdatePosition(m_v3Cone);

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();

	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(); //renders the XY grid with a 100% scale

	m_pMeshMngr->Render(); //renders the render list

	m_pTorus->Render(glm::translate(matrix4(1.0f), m_v3Torus), REGREEN);

	m_pCone->Render(glm::translate(matrix4(1.0f), m_v3Cone), REBLUE);

	// render spheres
	if (!bs_Torus->IsColliding(bs_Cone))
	{
		bs_Torus->m_pSphere->Render(glm::translate(matrix4(1.0f), bs_Torus->center), REWHITE);
		bs_Cone->m_pSphere->Render(glm::translate(matrix4(1.0f), bs_Cone->center), REWHITE);
	}
	else
	{
		bs_Torus->m_pSphere->Render(glm::translate(matrix4(1.0f), bs_Torus->center), RERED);
		bs_Cone->m_pSphere->Render(glm::translate(matrix4(1.0f), bs_Cone->center), RERED);
	}

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}
