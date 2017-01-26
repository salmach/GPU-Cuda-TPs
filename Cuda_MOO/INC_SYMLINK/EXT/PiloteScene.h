#ifndef PILOTESCENE_H
#define PILOTESCENE_H

#include "envBilatGL.h"


class CBI_GL PiloteScene
    {
    public:
	PiloteScene(float tx = 0, float ty = 0, float tz = 0, float pitch = 0, float roll = 0, float heading = 0);
	virtual ~PiloteScene();

	void setTranslation(float tx, float ty, float tz);
	void setRotations(float pitch, float roll, float heading);

	void setPitch(float pitch);
	void setRoll(float roll);
	void setHeading(float heading);
	void apply();

	float getHeading() const;
	float getPitch() const;
	float getRoll() const;
	float getTx() const;
	float getTy() const;
	float getTz() const;
	void setTx(float tx);
	void setTy(float ty);
	void setTz(float tz);
    private:
	float tx;
	float ty;
	float tz;
	float pitch;
	float roll;
	float heading;
    };

#endif
