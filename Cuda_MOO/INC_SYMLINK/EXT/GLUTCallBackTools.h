#ifndef GLUT_CALLBACK_TOOLS_H
#define GLUT_CALLBACK_TOOLS_H

#include "envFreeGlutTools.h"
#include "GLUTWindowManagers.h"

#include <map>
using std::map;

/*
 * But :
 *
 * 	Cette class permet d'affecter ses Callback a GLUT.
 *
 *	Exemple :
 *
 *		 glutDisplay(displayGLUTWrapper);
 *		 glutXXX(xxxGLUTWrapper);
 * Probl�me :
 *
 * 	Les m�thodes callback de glut doivent obligatoirement �tre statique. On travail en objet.
 *
 * Solution :
 *
 * 	Pour pouvoir "utiliser" les callback glut avec le monde objet, les callback statique appeleront les m�thodes publiques des objets GLUTWindowCustomiser
 * 	� l'aide d'une map faisant correspondre l'IdGLUT de la frame � l'objet (GLUTWindowCustomiser) correspondant.
 */
class CBI_FREEGLUT_TOOLS  GLUTCallBackTools
    {
    public:
	virtual ~GLUTCallBackTools();

	static void affectAllCallBack(map<unsigned int,GLUTWindow*> mapIDGLUTWindow);

	/*--------------------------------------*\
	 |*		Callbacks		*|
	 \*-------------------------------------*/

	/**
	 * CallBack pour GLUT
	 * glutXXX(xxx)
	 */
	static void displayGLUTWrapper();
	static void reshapeGLUTWrapper(int w, int h);
	static void mouseMotionGLUTWrapper(int x, int y);
	static void mouseGLUTWrapper(int button, int state, int x, int y);
	static void mouseWheelWrapper(int wheel, int direction, int x, int y);
	static void keyboardGLUTWrapper(unsigned char key, int x, int y);
	static void specialFuncGLUTWrapper(int key, int x, int y);

	static void keyboardUpGLUTWrapper(unsigned char key, int x, int y);
	static void specialFuncUpGLUTWrapper(int key, int x, int y);

	static void windowCloseWrapper();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/


	static void idleFuncGLUTWrapper();

	//static void postRunWrapper();

    private:
	GLUTCallBackTools();
	static void affectCallBack();
    };

#endif
