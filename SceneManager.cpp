
#include "SceneManager.h"
#include "HelloWorldScene.h"
#include "SplashScreen.h"
#include "Menu.h"
// #include "Menu.h"
// #include "LevelSelector.h"
// #include "ScoreScreen.h"
// #include "Store.h"
// #include "Level2.h"

USING_NS_CC;

float SceneManager::setScreenX, SceneManager::setScreenY;

CCScene* SceneManager::scene(){
	CCScene * scene = NULL;
	do 
	{		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SceneManager *layer = SceneManager::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
CCSprite* SceneManager::func_createImage(char const* name, int anchorx, int anchory, int posx, int posy) {
	CCSprite* temp = CCSprite::create(name);
	temp->setAnchorPoint(ccp(anchorx, anchory));
	temp->setPositionX(posx*setScreenX);
	temp->setPositionY(posy*setScreenY);
	temp->setScaleX(setScreenX);
	temp->setScaleY(setScreenY);
	return temp;
}
SceneManager::SceneManager(void)
{
}


SceneManager::~SceneManager(void)
{
}

bool SceneManager::init(){
	  if (!CCLayer::init()) {
        return false;
    }
	  
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	setScreenX = size.width/800;
	setScreenY = size.height/480;
	CCFiniteTimeAction *seq1 = CCSequence::create(CCDelayTime::create(0.1),
         CCCallFuncN::create(this,
		 callfuncN_selector(SceneManager::StartSplashScene)), NULL);
	this->runAction(seq1);

    return true;
}

void SceneManager::StartSplashScene(CCNode* sender){
	 CCDirector::sharedDirector()->replaceScene(SplashScreen::scene()); 
}
void SceneManager::StartMenuScene(CCNode* sender) {
	CCDirector::sharedDirector()->replaceScene(Menu::scene());
}
void StartLevelSelector(CCNode* sender) {
	// CCDirector:.sharedDirector()->replaceScene(LevelSelector::scene());
}
