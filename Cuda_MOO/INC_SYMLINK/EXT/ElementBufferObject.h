#ifndef ELEMENT_BUFFER_OBJECT_H
#define ELEMENT_BUFFER_OBJECT_H

#include "envBilatGL.h"
#include "BufferObject.h"

class CBI_GL ElementBufferObject : public BufferObject
    {
    public:
	ElementBufferObject();

	virtual ~ElementBufferObject();
    };

#endif
