//Here are all the included classed that are required for this class
#include "CScene.h"
#include "LetterSelection.h"
#include "Definitions.h"
#include "LoseScene.h"
#include "DScene.h"
#include "WinScene.h"
#include "MainMenuScene.h"

// namespace for cocos2d
using namespace cocos2d;

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* CScene::createScene()//Here is where the scene is created
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = CScene::create();//creating the game layer 

	scene->addChild(layer);//adding the layer to the scene as a child 

	return scene;//returning the scene so it can be made 
}


bool CScene::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as well as the window size or the visible size as well 

	//The image for the background is gotten here
	auto backgroundSprite = Sprite::create("background3.png");
	//The position for the background is set here
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y)); 
	//the background image is added to the scene as a child
	this->addChild(backgroundSprite); 

	/*
		The image for the main menu button is gotten here
		Once this button has been pressed the user is brought to the main menu 
	*/
	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(CScene::GoToMainMenuScene, this));
	//The position for the background is set here
	MainMenu->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 9 + origin.y));
	
	//A button is created here for the main menu
	auto MainMenuButton = Menu::create(MainMenu, NULL);
	//Here the position fo the button is set
	MainMenuButton->setPosition(Point::ZERO);
	//Here the button is added to the scene as a child
	this->addChild(MainMenuButton);
	
	_c = Sprite::create("Letterc.png");
	_c->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	this->addChild(_c);

	dot = Sprite::create("dot.png");
	dot->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 1.5 + origin.y));
	this->addChild(dot);

	dot2 = Sprite::create("blackdot.png");
	dot2->setPosition(Point(winSize.width / 2.3 + origin.x, winSize.height / 1.5 + origin.y));
	this->addChild(dot2);

	dot3 = Sprite::create("bluedot.png");
	dot3->setPosition(Point(winSize.width / 2.3 + origin.x, winSize.height / 3.1 + origin.y));
	this->addChild(dot3);

	dot4 = Sprite::create("orangedot.png");
	dot4->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 2.95 + origin.y));
	this->addChild(dot4);

	//Here a touchlistener is created 
	auto touchListener = EventListenerTouchOneByOne::create();
	/*
	   In the following section four touch listeners are made
	   *onTouchBegan
	   *onTouchEnded
	   *onTouchMoved
	*/

	touchListener->onTouchBegan = CC_CALLBACK_2(CScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(CScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(CScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;

}//end is init() 

bool CScene::onTouchBegan(Touch* touch, Event* event)
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
		else if (dot4->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot4Touched = true;
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

void CScene::onTouchEnded(Touch* touch, Event* event)
{
	/*
		if(the mouse is no longer pressed stop)
		{
		 stop drawing 
		}

		Then Check to see if the user has connected all the circles together
	*/
	if (dot1Touched && dot2Touched && dot3Touched && dot4Touched)
	{
		GoToWinScene(NULL);
	}
	else
	{
		GoToLoseScene(NULL);
	}
}

void CScene::onTouchMoved(Touch* touch, Event* event)
{
	/*
	   If(get location of the mouse location != the circle location)
	   {
	    then stop drawing
	   }
	*/
	auto draw = DrawNode::create(2.0F);
	if (_c->getBoundingBox().containsPoint(touch->getLocation()))
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
			else if (dot4->getBoundingBox().containsPoint(touch->getLocation()))
			{
				dot4Touched = true;
			}
	}
	else
	{
		GoToLoseScene(NULL);
	}
	
}

void CScene::GoToWinScene(Ref *sender)//go to game scene method implementation 
{
	GameManager* gm = GameManager::getInstance();
	
	if (gm->getChoice())
	{
		//goto b	
		auto scene = DScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	else
	{
//		gotolevelselect
		auto scene = WinScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}
void CScene::GoToLoseScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LoseScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
 
void CScene::GoToMainMenuScene(Ref *sender)//go to game scene method implementation 
{
	auto scene = LetterSelection::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}