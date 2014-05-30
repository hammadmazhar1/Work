#ifndef __MENU_H__
#define __MENU_H__
USING_NS_CC
class Menu : public cocos2d::CCLayer
{
	private:
		CCSprite *bk,*runkid;
	public:
		Menu();
		virtual bool init();
		static CCScene::scene()
		~Menu();
	
}
#endif