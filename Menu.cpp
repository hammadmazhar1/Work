#include "Menu.h"
#include "Menu.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Menu::scene(){
	CCScene * scene = NULL;
	do 
	{		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		Menu *layer = Menu::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool Menu::init() {
	if (!CCLayer::init()) {
		return false;
	}
	bk = CCSprite::create("menu2.png");
	
}