#ifndef __SPLASHSCREEN_H__
#define __SPLASHSCREEN_H__

#include "cocos2d.h" 

USING_NS_CC;

class SplashScreen :
	public cocos2d::CCLayer
{
public:
	SplashScreen();
	virtual bool init();
	static CCScene* scene();
	~SplashScreen();
	void changeImage(CCTime dt);

	CREATE_FUNC(SplashScreen);
	CCSprite *splash, *splash2;
};

#endif