//Here are the include files for this class
#include "LevelSelectionScene.h"
#include "MainMenuScene.h"
#include "AboutTheApp.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "WinScene.h"
#include "LoseScene.h"
#include "Instructions.h"

//Here are the namespaces used in this class
//CocosDenshion is used for the music in the application
using namespace CocosDenshion; 
/*
The namespace cocos2d is used to speed up coding,
by us
*/
using namespace cocos2d;

#define MENU_SFX "music.mp3"

USING_NS_CC;

//Here the new scene is created and added to the scene as a child
Scene* MainMenuScene::createScene()
{
	//Here the new scene is created
	auto scene = Scene::create();

	// Here the layer MainMenuScene is created
	auto layer = MainMenuScene::create();

	//Here the scene is added to the scene as a child
	scene->addChild(layer);

	// Here the scene is returned
	return scene;
}

//Here everything needed for the start of the application is created
bool MainMenuScene::init()
{
//
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	CCLOG("Hello");
	SimpleAudioEngine::getInstance()->playBackgroundMusic(MENU_SFX);//menu sound 

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCLOG("hi");
	//Here the image for the background is gotten
	auto backgroundSprite = Sprite::create("background.png");
	//Here the positon for the background image is set
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//Here the background is added to the scene as a child
	this->addChild(backgroundSprite);
	CCLOG("hey");
	/*In the following section all the buttons for this application are 
	*Created
	*Positioned 
	*Added to the scene
	*Made into menu items which are also added to the scene 
	*/

	/*
	Here is where the newgame button is created
	When the newGame button is clicked the user is brought to the Level Selection scene
	*/
	
	auto NewGame = MenuItemImage::create("newScene.png", "newScene.png", CC_CALLBACK_1(MainMenuScene::GoToLevelSelection, this));
	//Here the position for the new game button is set
	NewGame->setPosition(Point(visibleSize.width / 4 + origin.x, visibleSize.height / 5 + origin.y));
	
	/*
	Here is where the About the app button is created
	When the newGame button is clicked the application exits and closes 
	*/
	
	auto AboutTheApp = MenuItemImage::create("AboutTheApp.png", "AboutTheApp.png", CC_CALLBACK_1(MainMenuScene::GoToAboutTheApp, this));
	//Here the postion for the about the app button is set
	AboutTheApp->setPosition(Point(visibleSize.width / 1.5 + origin.x, visibleSize.height / 5 + origin.y));
	
	auto Instructions = MenuItemImage::create("Instructions.png", "Instructions.png", CC_CALLBACK_1(MainMenuScene::GoToAboutTheApp, this));
	//Here the postion for the Instructions button is set
	Instructions->setPosition(Point(visibleSize.width / 2.5+ origin.x, visibleSize.height / 5 + origin.y));
	/*
	Here is where the quit button is created
	When the quit button is clicked the application is closed
	*/
	CCLOG("3");
	auto closeItem = MenuItemImage::create("quit.png", "quit.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	//Here the position for the quit button is set
	closeItem->setPosition(Point(visibleSize.width / 1.2 + origin.x, visibleSize.height / 5 + origin.y));
	CCLOG("4");
	//Here the Font size is set for the title
	const float ScoreFontSize = 65;
	CCLOG("5");
	//Here the title is created 
	Title = Label::create("Learn To Write", "fonts/arial.ttf", ScoreFontSize);
	//Here the postiion for the title is et
	Title->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.3 + origin.y));
	//Here the colour for the title is set
	Title->setColor(ccc3(0, 0, 0));
	//here the title is added to the scene as a child
	this->addChild(Title);
	CCLOG("6");
	//Here the new game button is made into a menu item
	auto NewGameButton = Menu::create(NewGame, NULL);
	//Here the new game menu item's position is set
	NewGameButton->setPosition(Point::ZERO);
	//Here the new game menu item is added to the scene as a child
	this->addChild(NewGameButton);

	//Here the options button is made into a menu item
	auto AboutTheAppMenu = Menu::create(AboutTheApp, NULL);
	//Here the options menu items position is set
	AboutTheAppMenu->setPosition(Point::ZERO);
	//Here the options menu item is added to the scene as a child
	this->addChild(AboutTheAppMenu);
	CCLOG("7");
	//Here the Instructions button is made into a menu item
	auto InstructionsMenu = Menu::create(Instructions, NULL);
	//Here the Instructions menu items position is set
	InstructionsMenu->setPosition(Point::ZERO);
	//Here the Instructions menu item is added to the scene as a child
	this->addChild(InstructionsMenu);

	//Here the quit button is made into a menu item
	auto exit = Menu::create(closeItem, NULL);
	//Here the exit menu items position is set
	exit->setPosition(Point::ZERO);
	//Here the quit exit menu item is added to the scene as a child
	this->addChild(exit);

	return true;
}

/*
	In the following section all the scenes that connect to the main menu are created here.
	This includes:
	*The Level Selection Scene 
	*The About The App Scene
	*The Quit scenario
	*The Instructions scene
*/

//This is the GoToInstructions is created 
void MainMenuScene::GoToInstructions(Ref *sender)
{
	CCLOG("8");
	//Here the Instructions scene is being made
	auto scene = Instructions::createScene();
	//Here the Instructions Scene is being repalced with the Level Selection Scene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	//this->removeAllChildren;
}

//This is the MainMenuScene is created 
void MainMenuScene::GoToLevelSelection(Ref *sender)
{
	CCLOG("9");
	//Here the Level Selection scene is being made
	auto scene = LevelSelectionScene::createScene();
	//Here the Main Main Scene is being repalced with the Level Selection Scene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	//this->removeAllChildren;
}

//This is the GoToAboutTheApp is created 
void MainMenuScene::GoToAboutTheApp(Ref *sender)//go to game scene method implementation 
{
	CCLOG("10");
	//Here the About the App scene is being made
	auto scene = AboutTheApp::createScene();
	//Here the Main Main Scene is being repalced with the About the App Scene
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	//this->removeAllChildren;
}

//This is the menuCloseCallback is created 
void MainMenuScene::menuCloseCallback(Ref* pSender)
{
	//Here the Application is closed
	Director::getInstance()->end();
}