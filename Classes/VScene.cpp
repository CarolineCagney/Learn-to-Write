//Here are all the included classed that are required for this class
#include "VScene.h"
#include "LetterSelection.h"
#include "Definitions.h"
#include "LoseScene.h"
#include "WScene.h"
#include "WinScene.h"
#include "MainMenuScene.h"

// namespace for cocos2d
using namespace cocos2d;

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* VScene::createScene()//Here is where the scene is created
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = VScene::create();//creating the game layer 

	scene->addChild(layer);//adding the layer to the scene as a child 

	return scene;//returning the scene so it can be made 
}


bool VScene::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	auto backgroundSprite = Sprite::create("background22.png");//The image for the background is gotten here
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(VScene::GoToMainMenuScene, this));
	MainMenu->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 9 + origin.y));

	_v = Sprite::create("Letterv.png");
	_v->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(_v);

	auto MainMenuButton = Menu::create(MainMenu, NULL);
	MainMenuButton->setPosition(Point::ZERO);
	this->addChild(MainMenuButton);

	dot = Sprite::create("dot.png");
	dot->setPosition(Point(winSize.width / 2.1 + origin.x, winSize.height / 5 + origin.y));
	this->addChild(dot);

	dot2 = Sprite::create("orangedot.png");
	dot2->setPosition(Point(winSize.width / 2.1 + origin.x, winSize.height / 2.5 + origin.y));
	this->addChild(dot2);

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(VScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(VScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(VScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;

}//end is init() ->setContentSize(Size(70,70));

bool VScene::onTouchBegan(Touch* touch, Event* event)
{
		if (dot->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot1Touched = true;
	}
	else if (dot2->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot2Touched = true;
	}
	oldPoint = touch->getLocation();

	return true;


	/*
	If the user presses in one of the circles locations then it must draw, 
	If it isn't in one of the circles locations then it must not draw or 
	must stop drawing 
	*/
	
	/*
		if(the location of where the mouse is = the location of that circle)
		multiple if statements for each node 
		{
		 then draw a line 
		}
		else
		{
		don't draw 
		}
	
	*/
}

void VScene::onTouchEnded(Touch* touch, Event* event)
{
	/*
		if(the mouse is no longer pressed stop)
		{
		 stop drawing 
		}

		Then Check to see if the user has connected all the circles together
	*/
	if (dot1Touched && dot2Touched)
	{
		GoToWinScene(NULL);
	}
	else
	{
		GoToLoseScene(NULL);
	}
}

void VScene::onTouchMoved(Touch* touch, Event* event)
{
	/*
	   If(get location of the mouse location != the circle location)
	   {
	    then stop drawing
	   }
	*/
	auto draw = DrawNode::create();
	if (_v->getBoundingBox().containsPoint(touch->getLocation()))
	{
		newPoint = touch->getLocation();
		draw->drawLine(oldPoint, newPoint, Color4F::BLACK);
		addChild(draw);
		oldPoint = newPoint;
		if (dot->getBoundingBox().containsPoint(touch->getLocation()))
		{
			dot1Touched = true;
		}
		else if (dot2->getBoundingBox().containsPoint(touch->getLocation()))
		{
			dot2Touched = true;
		}
	}
	else
	{
		GoToLoseScene(NULL);
	}
	
}

void VScene::GoToWinScene(Ref *sender)//go to game scene method implementation 
{
	GameManager* gm = GameManager::getInstance();
	
	if (gm->getChoice())
	{
		//goto b	
		auto scene = WScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	else
	{
//		gotolevelselect
		auto scene = WinScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}
void VScene::GoToLoseScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LoseScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
 
void VScene::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LetterSelection::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}