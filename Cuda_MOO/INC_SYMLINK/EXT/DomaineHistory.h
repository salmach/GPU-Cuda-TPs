#ifndef DOMAINE_HISTORY_H_
#define DOMAINE_HISTORY_H_

#include "envGLImage.h"
#include "OnDomaineChangedListener_I.h"
#include <stack>
#include <vector>
#include "TDomaineMath.h"

using std::vector;
using std::stack;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE DomaineHistory
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DomaineHistory(const TDomaineMath &initialDomaine);

	DomaineHistory(const DomaineHistory &source);

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Last Domaine push in History
	 */
	void goToPreviousDomaine();

	/**
	 * First Domaine of History
	 */
	void goToDomaineInit();

	int size();

	/**
	 * Push domaine in history
	 * @return last pushed Domaine
	 */
	TDomaineMath pushDomaine(const TDomaineMath& domaine);

	TDomaineMath popDomaine();

	void addOnDomaineChangedListener(OnDomaineChangedListener_I* ptrListener);

	void removeOnDomaineChangedListener(OnDomaineChangedListener_I* ptrListener);

    private:

	void notifyListeners(const TDomaineMath& ptrDomaine);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:
	/**
	 * push domain in history
	 */
	void setCurrentDomaine(const TDomaineMath &domaine);

	void setInitialDomaine(const TDomaineMath &domaine);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	TDomaineMath getCurrentDomaine() const;

	inline TDomaineMath getInitialDomaine() const
	    {
	    return initialDomaine;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	TDomaineMath initialDomaine;

	// Tools
	stack<TDomaineMath> stackHistoryDomaine;
	vector<OnDomaineChangedListener_I*> vectorOnDomaineChangedListeners;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
