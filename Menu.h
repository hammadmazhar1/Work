#ifndef __MENU_H__s
#define __MENU_H__
USING_NS_CC
class Menu : public cocos2d::CCLayer
{
	private:
		CCSprite *bk,*runkid;
		int AnimateCounter;
		bool runforward1, runbehind1, runscream1, runlook, runforward2, runbehind2, runscream2, runwet, runwetstart;
		int behindcounter, forwardcounter, lookcounter, wetcounter, angrycounter;
	public:
		Menu();
		virtual bool init();
		static CCScene::scene()
		~Menu();
		void animateKid(cocos2d::CCTime dt);
}
#endif