#ifndef BUFFER_OBJECT_H
#define BUFFER_OBJECT_H

#include "envBilatGL.h"
#include <GL/glew.h>

/**
 * Manage BufferObject OpenGL
 *
 * Usage :
 *
 * 	BufferObject vbo=BufferObject(GL_ARRAY_BUFFER);
 * 	vbo.init(); //in a init Method
 * 	vbo.bufferData(...) // for setting data to vbo
 *
 * 	vbo.binBuffer();
 * 	draw();
 * 	vbo.unBindBufer();
 *
 * 	vbo.release();
 *
 */
class CBI_GL BufferObject
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/
    public:
	/**
	 *
	 * @param target (GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER, GL_PIXEL_PACK_BUFFER, or GL_PIXEL_UNPACK_BUFFER)
	 */
	BufferObject(GLenum target);

	virtual ~BufferObject();

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public:
	void init();

	void release();

	void bindBuffer();

	void unBindBuffer();

	/*
	 *  @param bufferUsage
	 *  	GL_STREAM_DRAW
	 *  	GL_STREAM_READ
	 *  	GL_STREAM_COPY
	 *  	GL_STATIC_DRAW
	 *  	GL_STATIC_READ
	 *  	GL_STATIC_COPY
	 *  	GL_DYNAMIC_DRAW
	 *  	GL_DYNAMIC_READ
	 *  	GL_DYNAMIC_COPY)
	 */
	void bufferData(unsigned int sizeOctet, void* bufferData, GLenum bufferUsage);

	void bufferSubData(unsigned int offset, unsigned int sizeOctet, void* bufferData);

	/**
	 * @param access
	 * 	GL_READ_ONLY
	 * 	GL_WRITE_ONLY
	 * 	GL_READ_WRITE)
	 */
	void* map(GLenum access);

	bool unMap(void);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	unsigned int getBufferID() const;

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

	inline bool isInit()
	    {
	    return initialized;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	GLenum target;

	// GL
	GLuint bufferID[1]; // OpenGL Identifiant (from glGenBuffer)

	bool initialized;



    };

#endif
