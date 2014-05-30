
#include "HelloWorldScene.h"
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h> 

using namespace cocos2d;
using namespace std;

HelloWorld::~HelloWorld() {}

HelloWorld::HelloWorld() {}

CCScene* HelloWorld::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		HelloWorld *layer = HelloWorld::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);
	} while (0);

	return scene;
}

bool HelloWorld::init()
{
	bool bRet = false;
	
	do 
	{
		if ( !CCLayer::init() ) {break;}
		
		// MISC. VARIABLES
		// if (CCUserDefault::isXMLFileExist()) {
			// score = CCUserDefault::sharedUserDefault()->getIntegerForKey("score");
		// } else {
			// score = 0;
			// CCUserDefault::sharedUserDefault()->setIntegerForKey("score", score);
		// }
		
		// swipe = Swipe::create();
		// this->addChild(swipe, 8);
		
#pragma region Sprites
		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		setScreenX = screenSize.width/800;
		setScreenY = screenSize.height/480;
		
		test = func_createImage("bully1.png", 0, 1, 400, 300, 4, this);
		
		
		
		
		// DISPLAY
		
		
		// ANIMATE
		// schedule(schedule_selector(HelloWorld::func_animate) , 0.1);
		// schedule(schedule_selector(HelloWorld::func_doubleTapTimer) , 0.1);
		// schedule(schedule_selector(HelloWorld::func_deleteSwipes) , 0.05);
		
		// DEFAULTS
		this->setTouchEnabled(true);
		this->setKeypadEnabled(true);
		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::ccTouchesBegan(CCSet* touches, CCEvent *event)
{
	CCTouch *ptouch = (CCTouch*) touches->anyObject();
	CCPoint location = ptouch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	
	///////////
	// SWIPE //
	///////////
	
	// swipe->addPoint(location);
	
}

void HelloWorld::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCTouch *ptouch = (CCTouch*) touches->anyObject();
	CCPoint location = ptouch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	
	///////////
	// SWIPE //
	///////////
	
	// swipe->addPoint(location);
	// swipe->addLine(swipe->s_points->cur->value.pt, swipe->s_points->cur->prev->value.pt);
}

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	
}

void HelloWorld::keyBackClicked() 
{
	CCUserDefault::sharedUserDefault()->setIntegerForKey("score", score);
	CCUserDefault::sharedUserDefault()->flush();
}

#pragma region MyFunctions


void HelloWorld::func_animate(cocos2d::CCTime dt) {
	
}

void HelloWorld::func_doubleTapTimer(cocos2d::CCTime dt) {
	
}

void HelloWorld::func_deleteSwipes(cocos2d::CCTime dt) {
	if (swipe->s_lines->length > 0) {
		while (swipe->s_lines->cur && swipe->s_lines->cur->next->value.duration >= .1) {
			swipe->removeLine();
		}
		int c = swipe->s_lines->length;
		ListItem<s_Line>* temp = swipe->s_lines->head;
		for (int i = 0; i < c; i++) {
			temp->value.duration += .05;
			temp = temp->next;
		}
	}
}
