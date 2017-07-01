#include "MainMenuScene.h"
#include "LevelSelectionScene.h"
#include "LetterSelection.h"
#include "LScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"

using namespace CocosDenshion; // namespace for audio engine 
using namespace cocos2d;
#define MENU_SFX "music.mp3"

//#define MENU_SFX "MenuSceneMusic.mp3"//sound for the splash screen


USING_NS_CC;

Scene* LevelSelectionScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelectionScene::create();


	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelSelectionScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//SimpleAudioEngine::getInstance()->playBackgroundMusic(MENU_SFX);//menu sound 

	Size visibleSize = Director::getInstance()->getVisibleSize();//init size
	Vec2 origin = Director::getInstance()->getVisibleOrigin();// init the origin 
	
	auto backgroundSprite = Sprite::create("background.png");// main menu image 
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);
	
	//button mapping to other screens

	//when click play it goes to the game scene
	auto NewGame = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(LevelSelectionScene::GoToMainMenu, this));
	NewGame->setPosition(Point(visibleSize.width / 3 + origin.x, visibleSize.height / 3 + origin.y));

	//options
	auto LevelSelection = MenuItemImage::create("LetterSelection.png", "LetterSelection.png", CC_CALLBACK_1(LevelSelectionScene::GoToLetterSelection, this));
	LevelSelection->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));
	
	auto LetterAItem = MenuItemImage::create("all.png", "all.png", CC_CALLBACK_1(LevelSelectionScene::GoToLetterAScene, this));
	LetterAItem->setPosition(Point(visibleSize.width / 1.5 + origin.x, visibleSize.height / 3 + origin.y));
	
	const float ScoreFontSize = 65;
	
	Title = Label::create("Chose which one you want to do", "fonts/arial.ttf", ScoreFontSize);
	Title->setColor(ccc3(0, 0, 0));
	Title->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.3 + origin.y));
	this->addChild(Title);
	
	auto NewGameButton = Menu::create(NewGame, NULL);
	NewGameButton->setPosition(Point::ZERO);
	this->addChild(NewGameButton);
	
	auto LevelSelectionMenu = Menu::create(LevelSelection, NULL);
	LevelSelectionMenu->setPosition(Point::ZERO);
	this->addChild(LevelSelectionMenu);

	auto LetterAItemMenu = Menu::create(LetterAItem, NULL);
	LetterAItemMenu->setPosition(Point::ZERO);
	this->addChild(LetterAItemMenu);
	
	return true;
}

void LevelSelectionScene::GoToMainMenu(Ref *sender)//go to game scene method implementation 
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
//	
}

void LevelSelectionScene::GoToLetterSelection(Ref *sender)//go to game scene method implementation 
{

	GameManager* gameManager = GameManager::getInstance();
	gameManager->setChoice(false);
	auto scene = LetterSelection::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelSelectionScene::GoToLetterAScene(Ref *sender)//go to game scene method implementation 
{
	GameManager* gameManager = GameManager::getInstance();
	gameManager->setChoice(true);
	auto scene = LScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}