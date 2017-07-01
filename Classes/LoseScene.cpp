//Here are the include files for this class
#include "LevelSelectionScene.h"
#include "LoseScene.h"
#include "MainMenuScene.h"
#include "AboutTheApp.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"

//Here are the namespaces used in this class
//CocosDenshion is used for the music in the application
using namespace CocosDenshion; 
#define MENU_SFX "music.mp3"
/*
The namespace cocos2d is used to speed up coding,
by us
*/
using namespace cocos2d;

//#define MENU_SFX "MenuSceneMusic.mp3"//sound for the splash screen

USING_NS_CC;

//Here the new scene is created and added to the scene as a child
Scene* LoseScene::createScene()
{
	//Here the new scene is created
	auto scene = Scene::create();

	// Here the layer LoseScene is created
	auto layer = LoseScene::create();

	//Here the scene is added to the scene as a child
	scene->addChild(layer);

	// Here the scene is returned
	return scene;
}

//Here everything needed for the start of the application is created
bool LoseScene::init()
{
//
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//SimpleAudioEngine::getInstance()->playBackgroundMusic(MENU_SFX);//menu sound 

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Here the image for the background is gotten
	auto backgroundSprite = Sprite::create("background.png");
	//Here the positon for the background image is set
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//Here the background is added to the scene as a child
	this->addChild(backgroundSprite);

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
	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(LoseScene::GoToMainMenuScene, this));
	//Here the position for the new game button is set
	MainMenu->setPosition(Point(visibleSize.width / 2.5 + origin.x, visibleSize.height / 5 + origin.y));

	/*
	Here is where the About the app button is created
	When the newGame button is clicked the application exits and closes 
	*/
	auto LevelSelection = MenuItemImage::create("LevelSelection.png", "LevelSelection.png", CC_CALLBACK_1(LoseScene::GoToLevelSelection, this));
	//Here the postion for the about the app button is set
	LevelSelection->setPosition(Point(visibleSize.width / 1.8 + origin.x, visibleSize.height / 5 + origin.y));

	//Here the Font size is set for the title
	const float LabelFontSize = 65;

	//Here the title is created 
	Title = Label::create("So close!", "fonts/Bubbly.ttf", LabelFontSize);
	//Here the postiion for the title is et
	Title->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.15 + origin.y));
	//Here the colour for the title is set
	Title->setColor(ccc3(0, 0, 0));
	//here the title is added to the scene as a child
	this->addChild(Title);
	
	const float LabelFontSize2 = 50;

	Title2 = Label::create("The best thing to remember is what you did this time, \n and learn from this experience so that you can do \n better next time", "fonts/arial.ttf", LabelFontSize2);
	//Here the postiion for the title is set
	Title2->setPosition(Point(visibleSize.width / 2 +  origin.x, visibleSize.height / 1.5 + origin.y));
	//Here the colour for the title is set
	Title2->setColor(ccc3(22, 31, 12));
	//here the title is added to the scene as a child
	this->addChild(Title2);

	const float LabelFontSize3 = 50;

	Title3 = Label::create("By being able to learn from this, it will allow \nyou to turn any setback into an opportunity \nto better yourself", "fonts/arial.ttf", LabelFontSize2);
	//Here the postiion for the title is set
	Title3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.5 + origin.y));
	//Here the colour for the title is set
	Title3->setColor(ccc3(22, 31, 12));
	//here the title is added to the scene as a child
	this->addChild(Title3);

	//Here the new game button is made into a menu item
	auto MainMenuButton = Menu::create(MainMenu, NULL);
	//Here the new game menu item's position is set
	MainMenuButton->setPosition(Point::ZERO);
	//Here the new game menu item is added to the scene as a child
	this->addChild(MainMenuButton);

	//Here the LevelSelection button is made into a menu item
	auto LevelSelectionButton = Menu::create(LevelSelection, NULL);
	//Here the LevelSelection menu item's position is set
	LevelSelectionButton->setPosition(Point::ZERO);
	//Here the LevelSelection menu item is added to the scene as a child
	this->addChild(LevelSelectionButton);

	return true;
}

/*
	In the following section all the scenes that connect to the main menu are created here.
	This includes:
	*The Level Selection Scene 
	*The About The App Scene
	*The Quit scenario
*/

//This is the GoToLevelSelection is created 
void LoseScene::GoToLevelSelection(Ref *sender)
{
	//Here the Level Selection scene is being made
	auto scene = LevelSelectionScene::createScene();
	//Here the Level Selection Scene is being repalced with the Level Selection Scene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	//this->removeAllChildren;
}

//This is the GoToAboutTheApp is created 
void LoseScene::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	//Here the About the App scene is being made
	auto scene = MainMenuScene::createScene();
	//Here the Main Main Scene is being repalced with the About the App Scene
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	//this->removeAllChildren;

}
