//Here are all the included classed that are required for this class
#include "LScene.h"
#include "LetterSelection.h"
#include "Definitions.h"
#include "LoseScene.h"
#include "MScene.h"
#include "WinScene.h"
#include "MainMenuScene.h"

// namespace for cocos2d
using namespace cocos2d;

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* LScene::createScene()//Here is where the scene is created
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = LScene::create();//creating the game layer 

	scene->addChild(layer);//adding the layer to the scene as a child 

	return scene;//returning the scene so it can be made 
}


bool LScene::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	auto backgroundSprite = Sprite::create("background12.png");//The image for the background is gotten here
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(LScene::GoToMainMenuScene, this));
	MainMenu->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 9 + origin.y));

	_l = Sprite::create("Letterl.png");
	_l->setPosition(Point(winSize.width / 1.8 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(_l);

	dot = Sprite::create("orangedot.png");
	dot->setPosition(Point(winSize.width / 1.8 + origin.x, winSize.height / 1.5 + origin.y));
	this->addChild(dot);

	dot2 = Sprite::create("purpledot.png");
	dot2->setPosition(Point(winSize.width / 1.8 + origin.x, winSize.height / 2.0 + origin.y));
	this->addChild(dot2);

	dot3 = Sprite::create("dot.png");
	dot3->setPosition(Point(winSize.width / 1.8 + origin.x, winSize.height / 2.9 + origin.y));
	this->addChild(dot3);

	auto MainMenuButton = Menu::create(MainMenu, NULL);
	MainMenuButton->setPosition(Point::ZERO);
	this->addChild(MainMenuButton);

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(LScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;

}//end is init() ->setContentSize(Size(70,70));

bool LScene::onTouchBegan(Touch* touch, Event* event)
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
	

	/*
	if(LScene::drawnode->getPosition() == touch->getLocation())
	{
		CCLOG("%d %d", drawnode->getPosition().x, drawnode->getPosition().y);
	}
	else
	{	
		CCLOG("%f %f", drawnode->getPosition().x, drawnode->getPosition().y);
		CCLOG("%f %f\n", touch->getLocation().x, touch->getLocation().y);
	}
	*/
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

void LScene::onTouchEnded(Touch* touch, Event* event)
{
	/*
		if(the mouse is no longer pressed stop)
		{
		 stop drawing 
		}

		Then Check to see if the user has connected all the circles together
	*/
	if (dot1Touched && dot2Touched && dot3Touched )
	{
		GoToWinScene(NULL);
	}
	else
	{
		GoToLoseScene(NULL);
	}
}

void LScene::onTouchMoved(Touch* touch, Event* event)
{
	auto draw = DrawNode::create(2.0F);
	if (_l->getBoundingBox().containsPoint(touch->getLocation()))
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
	
	/*
	   If(get location of the mouse location != the circle location)
	   {
	    then stop drawing
	   }
	*/
}

void LScene::GoToWinScene(Ref *sender)//go to game scene method implementation 
{
	GameManager* gm = GameManager::getInstance();
	
	if (gm->getChoice())
	{
		//goto b	
		auto scene = MScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	else
	{
//		gotolevelselect
		auto scene = WinScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}
void LScene::GoToLoseScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LoseScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
 
void LScene::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}