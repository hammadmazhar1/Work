
#include "SplashScreen.h"
#include "HelloWorldScene.h"
#include "SceneManager.h"

USING_NS_CC;
using namespace cocos2d;
//using namespace CocosDenshion;


CCScene* SplashScreen::scene(){
	CCScene * scene = NULL;
	do 
	{		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SplashScreen *layer = SplashScreen::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool SplashScreen::init() {
    if (!CCLayer::init()) {
        return false;
    }
	splash = SceneManager::func_createImage("impart.png",0,1,0,480);
    this->addChild(splash, 1);

	splash2 = SceneManager::func_createImage("splashscreen.png",0,1,0,480);
    this->addChild(splash2, 1);
	splash2->setVisible(false);

	scheduleOnce(schedule_selector(SplashScreen::changeImage) , 4);
    return true;
}


SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::changeImage(CCTime dt){
	splash->setVisible(false);
	splash2->setVisible(true);

	CCFiniteTimeAction *seq1 = CCSequence::create(CCDelayTime::create(1.0),
            CCCallFuncN::create(this,
			callfuncN_selector(SceneManager::StartMenuScene)), NULL);


    this->runAction(seq1);
}