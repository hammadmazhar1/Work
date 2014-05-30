
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
		
		frontdesk = SceneManager::func_createImage("frontdesk.png", 0, 1, 35, 235); this->addChild(frontdesk, 6);
		backdesk = SceneManager::func_createImage("backdesk.png", 0, 1, 118, 280); this->addChild(backdesk, 5);
		door = SceneManager::func_createImage("door.png", 0, 1, 590, 464); this->addChild(door, 3);
		sun = SceneManager::func_createImage("sun.png", 0, 1, 0, 480); this->addChild(sun, 0);
		board = SceneManager::func_createImage("board.png", 0, 1, 314, 446); this->addChild(board, 3);
		wall = SceneManager::func_createImage("wall.png", 0, 1, 0, 480); this->addChild(wall, 2);
		shelf = SceneManager::func_createImage("shelf.png", 0, 1, 128, 472); this->addChild(shelf, 3);
		globe = SceneManager::func_createImage("globe.png", 0, 1, 155, 365); this->addChild(globe, 3);
		clock = SceneManager::func_createImage("clock.png", 0, 1, 530, 480); this->addChild(clock, 3);
		needleH = SceneManager::func_createImage("needleH.png", 0, 1, 530, 483); this->addChild(needleH, 3);
		needleM = SceneManager::func_createImage("needleMin.png", 0, 1, 530, 483); this->addChild(needleM, 3);
		clockC = SceneManager::func_createImage("clockCenter.png", 0, 1, 530, 480); this->addChild(clockC, 3);
		cabinet = SceneManager::func_createImage("cabinet.png", 0, 1, 732, 288); this->addChild(cabinet, 5);
		pot = SceneManager::func_createImage("pot.png", 0, 1, 735, 338); this->addChild(pot, 5);
		mat = SceneManager::func_createImage("mat.png", 0, 1, 616, 98); this->addChild(mat, 3);
		window = SceneManager::func_createImage("window.png", 0, 1, 0, 480); this->addChild(window, 3);
		background = SceneManager::func_createImage("bknoelements.png", 0, 0, 0, 0); this->addChild(background, 1);
		
		// animate clock
		needleM->setAnchorPoint(ccp(0.5, 0)); needleM->runAction(CCRotateTo::create(60,1080)); needleM->setPosition(ccp(565*setScreenX, 445*setScreenY));
		needleH->setAnchorPoint(ccp(0, 0)); needleH->runAction(CCRotateTo::create(60,60)); needleH->setPosition(ccp(565*setScreenX, 445*setScreenY));
		
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
