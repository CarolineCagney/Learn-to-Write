//Here are all the included classed that are required for this class
#include "YScene.h"
#include "LetterSelection.h"
#include "Definitions.h"
#include "LoseScene.h"
#include "ZScene.h"
#include "WinScene.h"
#include "MainMenuScene.h"

// namespace for cocos2d
using namespace cocos2d;

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* YScene::createScene()//Here is where the scene is created
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = YScene::create();//creating the game layer 

	scene->addChild(layer);//adding the layer to the scene as a child 

	return scene;//returning the scene so it can be made 
}


bool YScene::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	auto backgroundSprite = Sprite::create("background25.png");//The image for the background is gotten here
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(YScene::GoToMainMenuScene, this));
	MainMenu->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 9 + origin.y));

	_y = Sprite::create("Lettery.png");
	_y->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(_y);

	auto MainMenuButton = Menu::create(MainMenu, NULL);
	MainMenuButton->setPosition(Point::ZERO);
	this->addChild(MainMenuButton);

	dot = Sprite::create("dot.png");
	dot->setPosition(Point(40 + winSize.width / 2.4 + origin.x, winSize.height / 1.4 + origin.y));
	this->addChild(dot);

	dot2 = Sprite::create("bluedot.png");
	dot2->setPosition(Point(winSize.width / 2.1 + origin.x, winSize.height / 3.4  - 30 + origin.y));
	this->addChild(dot2);
	
	dot3 = Sprite::create("blackdot.png");
	dot3->setPosition(Point(winSize.width / 1.7 + origin.x, winSize.height / 1.4 + origin.y));
	this->addChild(dot3);

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(YScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(YScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(YScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;

}//end is init() ->setContentSize(Size(70,70));

bool YScene::onTouchBegan(Touch* touch, Event* event)
{
	if (dot->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot1Touched = true;
	}
	else if (dot2->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot2Touched = true;
	}
	else if (dot3->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot3Touched = true;
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

void YScene::onTouchEnded(Touch* touch, Event* event)
{
	/*
		if(the mouse is no longer pressed stop)
		{
		 stop drawing 
		}

		Then Check to see if the user has connected all the circles together
	*/
	if (dot1Touched && dot2Touched && dot3Touched)
	{
		GoToWinScene(NULL);
	}
	else
	{
		GoToLoseScene(NULL);
	}
}

void YScene::onTouchMoved(Touch* touch, Event* event)
{
	/*
	   If(get location of the mouse location != the circle location)
	   {
	    then stop drawing
	   }
	*/
	auto draw = DrawNode::create();
	if (_y->getBoundingBox().containsPoint(touch->getLocation()))
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
		else if (dot3->getBoundingBox().containsPoint(touch->getLocation()))
		{
			dot3Touched = true;
		}
	}
	else
	{
		GoToLoseScene(NULL);
	}
	
}

void YScene::GoToWinScene(Ref *sender)//go to game scene method implementation 
{
	GameManager* gm = GameManager::getInstance();
	
	if (gm->getChoice())
	{
		//goto b	
		auto scene = ZScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	else
	{
//		gotolevelselect
		auto scene = WinScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}
void YScene::GoToLoseScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LoseScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
 
void YScene::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LetterSelection::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}