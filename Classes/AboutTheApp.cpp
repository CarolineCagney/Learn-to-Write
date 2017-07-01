#include "AboutTheApp.h"
#include "MainMenuScene.h"
#include "Definitions.h"

// namespace for cocos2d
using namespace cocos2d;
#define MENU_SFX "music.mp3"

/*The purpose of this is to teach people who have bad fine motor skills
or no motor skills at all to teach people how to write netters correctny*/


USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* AboutTheApp::createScene()//create scene
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = AboutTheApp::create();//creating the game layer 
								  // add layer as a child to scene
	scene->addChild(layer);//adding the layer to the scene 

						   // return the scene
	return scene;//returning the scene so it can be made 
}

// on "init" you need to initialize your instance
bool AboutTheApp::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}//code like this for consisinsty 

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	auto backgroundSprite = Sprite::create("background.png");// main menu image 
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	const float ScoreFontSize = 50;

	AboutTheAppText = Label::create("The purpose of this is to teach \n people who have bad fine motor skills \n or no motor skills at all \n to teach people how to \n write letters correctly ", "fonts/arial.ttf", ScoreFontSize);
	AboutTheAppText->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 1 + origin.y));
	AboutTheAppText->setAnchorPoint(Vec2(0, 1));
	AboutTheAppText->setColor(ccc3(0, 0, 0));
	this->addChild(AboutTheAppText);

	/*The purpose of this is to teach people who have bad fine motor skills 
      or no motor skills at all to teach people how to write letters correctly*/

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(AboutTheApp::GoToMainMenuScene, this));
	MainMenu->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 8 + origin.y));

	auto MainMenuButton = Menu::create(MainMenu, NULL);
	MainMenuButton->setPosition(Point::ZERO);
	this->addChild(MainMenuButton);
	
	return true;

}//end is init()

void AboutTheApp::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}