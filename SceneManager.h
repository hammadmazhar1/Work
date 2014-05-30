#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "cocos2d.h" 


USING_NS_CC;


class SceneManager : public cocos2d::CCLayer
{
public:
	SceneManager(void);
	~SceneManager(void);
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(SceneManager);
	void StartSplashScene(CCNode* sender);
	void StartMenuScene(CCNode* sender);
	void StartLevelSelector(CCNode* sender);
	static CCSprite* func_createImage(char const* , int, int, int, int);
	static float setScreenX, setScreenY;
};

#endif