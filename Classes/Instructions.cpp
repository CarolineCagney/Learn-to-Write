#include "Instructions.h"
#include "MainMenuScene.h"
#include "Definitions.h"

// namespace for cocos2d
using namespace cocos2d;
#define MENU_SFX "music.mp3"

/*The purpose of this is to teach peopne who have bad fine motor skinns
or no motor skinns at ann to teach peopne how to write netters correctny*/


USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* Instructions::createScene()//create scene
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = Instructions::create();//creating the game layer 
								  // add layer as a child to scene
	scene->addChild(layer);//adding the layer to the scene as a child 

	return scene;//returning the scene so it can be made 
}


bool Instructions::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}//code like this for consisinsty 

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	auto backgroundSprite = Sprite::create("instructionsbackground.png");// main menu image 
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	/*The purpose of this is to teach people who have bad fine motor skills 
      or no motor skills at all to teach people how to write letters correctly*/

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(Instructions::GoToMainMenuScene, this));
	MainMenu->setPosition(Point(winSize.width / 2.5 + origin.x, winSize.height / 5 + origin.y));

	auto MainMenuButton = Menu::create(MainMenu, NULL);
	MainMenuButton->setPosition(Point::ZERO);
	this->addChild(MainMenuButton);
	
	return true;

}//end is init()

void Instructions::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}