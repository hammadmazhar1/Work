
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
		if ( !CCLayer::init() )
		{
			break;
		}
		
		// MISC. VARIABLES
		selected = firstTap = false;
		normalSize = true;
		inc = 10;
		doubleTapTimer = 0;
		if (CCUserDefault::isXMLFileExist()) {
			score = CCUserDefault::sharedUserDefault()->getIntegerForKey("score");
		} else {
			score = 0;
			CCUserDefault::sharedUserDefault()->setIntegerForKey("score", score);
		}
		imageTimer = imageIndex = swipeIndex = 0;
		
	//	swipe = Swipe::create();
		
		// IMAGES
		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		setScreenX = screenSize.width/800;
		setScreenY = screenSize.height/480;
		
		test = CCSprite::create("bully1.png");
		test->setAnchorPoint(ccp(0, 1));
		test->setPosition(ccp(400*setScreenX, 250*setScreenY));
		test->setScaleX(setScreenX);
		test->setScaleY(setScreenY);
		this->addChild(test, 1);
		
		reset_score = CCSprite::create("menuoptions.png");
		reset_score->setAnchorPoint(ccp(0, 1));
		reset_score->setPosition(ccp(50*setScreenX, screenSize.height-50*setScreenY));
		reset_score->setScaleX(setScreenX);
		reset_score->setScaleY(setScreenY);
		this->addChild(reset_score, 0);
		
		// DISPLAY
		disp_score = CCLabelTTF::create("Score: 0", "Calibri", 24, CCSizeMake(120, 30), kCCTextAlignmentLeft);
		disp_score->setPosition(ccp(screenSize.width-80, screenSize.height-30));
		stringstream str; str << score;
		disp_score->setString(("Score: " + str.str()).c_str());
		this->addChild(disp_score);
		
		// ANIMATE
		schedule(schedule_selector(HelloWorld::func_animate) , 0.1);
		schedule(schedule_selector(HelloWorld::func_doubleTapTimer) , 0.1);
		
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
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("grenade.wav"); // sound
	score += 1; // score
	
	if (test->boundingBox().containsPoint(location)) {
		selected = true;
		if (!firstTap) {firstTap = true;} // double tap resizing
		else {
			if (doubleTapTimer <= .5) {
				if (normalSize) {test->setScaleX(setScreenX/2); test->setScaleY(setScreenY/2); normalSize = false;}
				else {test->setScaleX(setScreenX); test->setScaleY(setScreenY); normalSize = true;}
			}
			firstTap = false;
		}
	} else {
		firstTap = false;
	}
	
	///////////
	// SWIPE //
	///////////
	
//	swipe->addPoint(location);
	
	//////////
	
	if (reset_score->boundingBox().containsPoint(location)) {
		// CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
		score = 0;
	}
	
	stringstream str; str << score; // score
	disp_score->setString(("Score: " + str.str()).c_str()); // score
}

void HelloWorld::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCTouch *ptouch = (CCTouch*) touches->anyObject();
	CCPoint location = ptouch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	
	if (selected) {
		test->setPosition(ccp(location.x-(test->boundingBox().size.width)/2, location.y+(test->boundingBox().size.height)/2));
	}
}

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	if (selected) {
		test->setPosition(ccp(100*setScreenX, 300*setScreenY));
		selected = false;
	}
}

void HelloWorld::keyBackClicked() 
{
	CCUserDefault::sharedUserDefault()->setIntegerForKey("score", score);
	CCUserDefault::sharedUserDefault()->flush();
}

void HelloWorld::func_animate(cocos2d::CCTime dt) {
	if (!selected) {
		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		test->setPosition(ccp(test->getPositionX()+inc, test->getPositionY()));
		if (test->getPositionX()+test->boundingBox().size.width >= screenSize.width) {inc = -10;}
		else if (test->getPositionX() <= 0) {inc = 10;}
	}
	imageTimer += .1;
	if (imageTimer > 1) {
		if (imageIndex == 0) {test->setTexture(CCTextureCache::sharedTextureCache()->addImage("bully1.png"));}
		else {test->setTexture(CCTextureCache::sharedTextureCache()->addImage("clock.png"));}
		imageTimer = 0;
		imageIndex = (imageIndex+1)%2;
	}
}

void HelloWorld::func_doubleTapTimer(cocos2d::CCTime dt) {
	if (doubleTapTimer > .5) {firstTap = false;}
	if (firstTap) {
		doubleTapTimer += .1;
	} else {
		doubleTapTimer = 0;
	}
}

