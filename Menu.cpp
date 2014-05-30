#include "Menu.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion;
Menu::Menu()
{
}


Menu::~Menu()
{
}
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
	bk = SceneManager::func_createImage("menu2.png",0,1,0,480);
	this->addChild(bk,1);
	runkid = SceneManager::func_createImage("runkid1.png",0,1,100,200);
	this->addChild(runkid,1);
	AnimateCounter = 0;
	runbehind1 = runscream1 = runlook = runforward2 = runscream2 = runbehind2 = runwetstart = runwet = false;
	runforward1 = true;
	behindcounter = forwardcounter = lookcounter = wetcounter = angrycounter = 0;
	playscream = true;
	playsplash = true;
	playgrr = true;
	abtusnotif = false;
	soundpress = musicpress = false;
	
	schedule(schedule_selector(Menu::animateKid), 0.1);
	this->setTouchEnabled(true);
	this->setKeypadEnabled(true);
	return true;
	
}
void Menu::animateKid(CCTime dt){
	if(runforward1 == true){
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid1.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid2.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid3.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid4.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid5.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid6.png"));
			if(runwet == true){
				wetcounter++;
				if(wetcounter > 3){
					runforward1 = false;
					runwetstart = true;
					wetcounter = 0;
					playgrr = true;
				}
			}
			break;
		default:
			break;
		}
	}else if(runbehind1 == true){
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind12.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind22.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind32.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind42.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind52.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind62.png"));
			behindcounter++;
			if(behindcounter == 3){
				runbehind1 = false;
				runscream1 = true;
				behindcounter = 0;
				playscream = true;
			}
			break;
		default:
			break;
		}
	}else if(runscream1 == true){
		if(playscream == true){
		//	path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("screaming.wav");
			screamid = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("screaming.wav");
			playscream = false;
		}
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream12.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream22.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream32.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream42.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream52.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream62.png"));
			break;
		default:
			break;
		}
	}else if(runforward2 == true){
		runlook = false;
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid12.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid22.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid32.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid42.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid52.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runkid62.png"));
			forwardcounter++;
			if(forwardcounter == 3){
				runlook = true;
				runforward2 = false;
				AnimateCounter = 0;
				forwardcounter = 4;
			}
			break;
		default:
			break;
		}
	}else if(runbehind2 == true){
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind1.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind2.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind3.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind4.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind5.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runbehind6.png"));
			behindcounter++;
			if(behindcounter == 3){
				runbehind2 = false;
				runscream2 = true;
				behindcounter = 0;
				playscream = true;
			}
			break;
		default:
			break;
		}
	}else if(runscream2 == true){
		if(playscream == true){
		//	path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("screaming.wav");
			screamid = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("screaming.wav");
			playscream = false;
		}
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream1.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream2.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream3.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream4.png"));
			break;
		case 4:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream5.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runscream6.png"));
			break;
		default:
			break;
		}
	}else if(runlook == true){
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseEffect(sndid);
		switch (AnimateCounter)
		{
		case 0:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface3.png"));
			break;
		case 1:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface3.png"));
			break;
		case 2: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface3.png"));
			break;
		case 3:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface4.png"));
			break;
		case 4: 
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface4.png"));
			break;
		case 5:
			runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runface4.png"));
			lookcounter++;
			if(lookcounter == 3){
				runlook == false;
				runforward2 = true;
				lookcounter = 4;
				forwardcounter = 4;
				AnimateCounter = 0;
				CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeAllEffects();
			}
			break;
		}
	}else if(runwetstart == true){
		if (playgrr == true)
		{
			playgrr = false;
			CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseEffect(sndid);
		//	path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("grrr.wav");
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("grrr.wav");
		}
		
		switch (AnimateCounter)
		{
		case 0:
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else if(angrycounter > 0){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet2.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet1.png"));
			}
			break;
		case 1:
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else if(angrycounter > 0){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet2.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet1.png"));
			}
			break;
		case 2: 
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet2.png"));
			}
			break;
		case 3:
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet2.png"));
			}
			break;
		case 4:
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet3.png"));
			}
			break;
		case 5:
			if(angrycounter > 4){
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet4.png"));
			}else{
				runkid->setTexture(CCTextureCache::sharedTextureCache()->addImage("runfacewet3.png"));
			}
			angrycounter++;
			if (angrycounter == 5)
			{
		//		path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("facepalm.wav");
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("facepalm.wav");
			}
			if(angrycounter > 7){
				runwetstart = false;
				runwet = false;
				runforward2 = true;
				CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeEffect(sndid);
			}
			break;
		}
	}
	float setScreenX = SceneManager::setScreenX;
	float setScreenY = SceneManager::setScreenY;
	AnimateCounter = (AnimateCounter+1)%6;
	if(runlook == false && runwetstart == false){
		
		if(runforward1 == true || runscream2 == true || runbehind2 == true){
			runkid->setPositionX(runkid->getPositionX() + 30*setScreenX);
		}else{
			runkid->setPositionX(runkid->getPositionX() - 30*setScreenX);
		}
	}
	if(runkid->getPositionX() > 850*setScreenX && runforward1 == true){
		runforward1 = false;
		runbehind1 = true;
		AnimateCounter = 0;
	}
	if(runkid->getPositionX() > 850*setScreenX && runscream2 == true){
		runscream2 = false;
		runforward2 = true;
		AnimateCounter = 0;
	}
	if(runkid->getPositionX() < -350*setScreenX && runscream1 == true){
		runbehind2 = true;
		runscream1 = false;
		AnimateCounter = 0;
	}
	if(runkid->getPositionX() < -350*setScreenX && runforward2 == true && angrycounter == 0){
		runforward2 = false;
		runforward1 = true;
		AnimateCounter = 0;
		runwet = true;
	}
	if(runkid->getPositionX() < -350*setScreenX && runforward2 == true && angrycounter > 0){
		runforward2 = false;
		runforward1 = true;
		AnimateCounter = 0;
		runwet = false;
		lookcounter = forwardcounter = angrycounter = 0;
		//balloon->setPositionX(-1050*setScreenX);
	}

}