#ifndef GLUT_WINDOW_MANAGERS_H
#define GLUT_WINDOW_MANAGERS_H

#include "envFreeGlutTools.h"
#include "GLConfig.h"
#include "GLUTWindow.h"
#include "GLUTCallBackTools.h"

#include <map>

using std::map;

/**
 * input :
 * 	pointer to GLImage source
 */
typedef void (*FRERE_MASTER_THREAD)(void**);

/**
 * On Linux befor using GLUTWindowManagers you have to call :
 *
 * 	GLUTWindowManagers::init(&argc,argv);
 *
 * Otherwise OpenGL cannot open and an error message will remind you that you haven't call glutInit !!
 *
 */
class CBI_FREEGLUT_TOOLS GLUTWindowManagers
    {
    private:
	GLUTWindowManagers();
	virtual ~GLUTWindowManagers();
    public:
	static void init(int argc, char** argv);
	static GLUTWindowManagers* getInstance();
	/**
	 * Warning Bloquant tand qu'il y a au moins une GLUTWindow d'active!
	 * Utiliser la méthode postDisplay de la class GLUTWindowCustomiser_A pour effectuer un traitement après le 1er rendu.
	 * Cette méthode postDisplay est appelé dans un thread séparé du display !
	 */
	void runALL();

	/**
	 * Use internaly only
	 */
	void addWindow(GLUTWindow* glutWindow);

	/**
	 * Use internaly only
	 */
	void removeWindow(GLUTWindow* glutWindow);

	/**
	 * Don't use this!
	 * Prefering creating a Boost::thread
	 * then call runALL(void)
	 */
	void runALL(FRERE_MASTER_THREAD methodeFrereMasterThread, void** param);

	/**
	 * Never use!
	 * Used only internally!
	 */
	map<unsigned int, GLUTWindow*> getMapIdGlutWindow();

	GLUTWindow* getGLUTWindow(unsigned int glutWindowID);

    private:
	bool isAllDisplaying();
	static void createDummyOpenGLContext();

    private:
	map<unsigned int, GLUTWindow*> mapIdGlutWindow;
	static GLUTWindowManagers* singleton;

    };

#endif
