#ifndef GLIMAGE_A_H_
#define GLIMAGE_A_H_

#include "envGLImage.h"
#include "GLImage_I.h"
#include "BufferObject.h"
#include "ShaderPrograms.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Render given Image_I in OpenGL Texture and PBO
 */
class CBI_GLIMAGE GLImage_A : public GLImage_I
    {
	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:


	GLImage_A();

	virtual ~GLImage_A();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	virtual void init(Image_I* ptrImage);

	virtual void update(Image_I* ptrImage);

	virtual void draw(Image_I* ptrImage);

	virtual void release();

    protected :

	virtual void fillPbo(Image_I* ptrImage)=0;

	GLint getGLFormat(ColorModel colorModel) const;

    private:

	void loadHsbShader();

	void loadHueShader();

    protected:

	// Tools
	BufferObject* ptrPbo;
	GLuint textureID;
	ShaderPrograms* hsbShader;
	GLuint texturePixelFormat;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
