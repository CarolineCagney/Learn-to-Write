//Here are all the included classed that are required for this class
#include "AScene.h"
#include "BScene.h"
#include "LetterSelection.h"
#include "Definitions.h"
#include "LoseScene.h"
#include "WinScene.h"
#include "MainMenuScene.h"

// namespace for cocos2d
using namespace cocos2d;

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* AScene::createScene()//Here is where the scene is created
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();//creating the scene with added physcis engine 
	auto layer = AScene::create();//creating the game layer 
								 // add layer as a child to scene
	scene->addChild(layer);//adding the layer to the scene 

						   // return the scene
	return scene;//returning the scene so it can be made 
}

// on "init" you need to initialize your instance
bool AScene::init()//initing the game so the scene can be made 
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
	auto backgroundSprite = Sprite::create("background1.png");
	//The position for the background is set here
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y)); 
	//the background image is added to the scene as a child
	this->addChild(backgroundSprite); 

	/*
		The image for the main menu button is gotten here
		Once this button has been pressed the user is brought to the main menu 
	*/
	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(AScene::GoToMainMenuScene, this));
	//The position for the background is set here
	MainMenu->setPosition(Point(winSize.width / 4 + origin.x, winSize.height / 9 + origin.y));
	
	//A button is created here for the main menu
	auto MainMenuButton = Menu::create(MainMenu, NULL);
	//Here the position fo the button is set
	MainMenuButton->setPosition(Point::ZERO);
	//Here the button is added to the scene as a child
	this->addChild(MainMenuButton);
	
	//the image sprite for a dot is created here
	_a = Sprite::create("Lettera.png");
	//The position for the sprite a is set here
	_a->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	//the image is added to the scene as a child
	this->addChild(_a);
	
	//the image sprite for a dot is created here
	dot = Sprite::create("dot.png");
	//The position for the sprite dot is set here
	dot->setPosition(Point(winSize.width / 1.65 + origin.x, winSize.height / 1.4 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot);

	//the image sprite for a dot is created here
	dot2 = Sprite::create("dot.png");
	//The position for the sprite dot is set here
	dot2->setPosition(Point(winSize.width / 1.65 + origin.x, winSize.height / 1.9 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot2);

	//the image sprite for a dot is created here
	dot4 = Sprite::create("bluedot.png");
	//The position for the sprite dot is set here
	dot4->setPosition(Point(winSize.width / 1.65 + origin.x, winSize.height / 3.1 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot4);

	//the image sprite for a dot is created here
	dot5 = Sprite::create("purpledot.png");
	//The position for the sprite dot is set here
	dot5->setPosition(Point(winSize.width / 1.85 + origin.x, winSize.height / 1.45 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot5);

	//the image sprite for a dot is created here
	dot6 = Sprite::create("blackdot.png");
	//The position for the sprite dot is set here
	dot6->setPosition(Point(winSize.width / 2.5 + origin.x, winSize.height / 1.7 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot6);

	//the image sprite for a dot is created here
	dot3 = Sprite::create("orangedot.png");
	//The position for the sprite dot is set here
	dot3->setPosition(Point(winSize.width / 2.39 + origin.x, winSize.height / 3 + origin.y));
	//the image is added to the scene as a child
	this->addChild(dot3);

	//Here a touchlistener is created 
	auto touchListener = EventListenerTouchOneByOne::create();
	/*
	   In the following section four touch listeners are made
	   *onTouchBegan
	   *onTouchEnded
	   *onTouchMoved
	*/
	//onTouchBegan is called whenever the user intiially touches the screen
	touchListener->onTouchBegan = CC_CALLBACK_2(AScene::onTouchBegan, this);
	//onTouchEnded is called whenever the user has finished interacting with the screen
	touchListener->onTouchEnded = CC_CALLBACK_2(AScene::onTouchEnded, this);
	//onTouchMoved is called whenever the user touches the screen and draws across the screen
	touchListener->onTouchMoved = CC_CALLBACK_2(AScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;

}//end is init()

/*
In the follwoing section is the onTouchBegan method
In this method whenever the user touches the screen the bounding boxes
of the dots on the screen are checked to see if the user has drawn over
the dots.
If a dot has been drawn over the variable dot(the dots number)Touched 
is set to true
*/
bool AScene::onTouchBegan(Touch* touch, Event* event)
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
	else if (dot5->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot5Touched = true;
	}
	else if (dot6->getBoundingBox().containsPoint(touch->getLocation()))
	{
		dot6Touched = true;
	}
	oldPoint = touch->getLocation();
	
	return true;
}

/*
In the follwoing section is the onTouchEnded method
In this method whenever the user is finished interacting with the screen,
the different dot(the dots number)Touched are checked to see if they 
have been touched. 
If all the dots on the letter have been touched then
GoToWinScene is called.
If all the dots on the letter have not been touched then
GoToLoseScene is called.
*/
void AScene::onTouchEnded(Touch* touch, Event* event)
{
	if (dot1Touched && dot2Touched && dot3Touched && dot4Touched && dot5Touched && dot6Touched)
	{
		GoToWinScene(NULL);
	}
	else
	{
		GoToLoseScene(NULL);
	}
}

/*
In the follwoing section is the onTouchMoved method.
In this method whenever the user is moving the tablet
pen or mouse a line is drawn from where the user first
touches the screen to where ever they move around the
screen.
While the user is drawing around the screen the bounding
boxes of the dots on the screen are checked to see if 
1. If the user has drawn over all of the dots 
2. If the user has drawn to far away from the dots 
*/
void AScene::onTouchMoved(Touch* touch, Event* event)
{
	/*
	   If(get location of the mouse location != the circle location)
	   {
	    then stop drawing
	   }
	*/
		auto draw = DrawNode::create();
	if (_a->getBoundingBox().containsPoint(touch->getLocation()))
	{
		newPoint = touch->getLocation();
		draw->drawLine(oldPoint, newPoint, Color4F::BLACK);
		addChild(draw);
		oldPoint = newPoint;
		/*
		  Everytime the user draws over a dot that dots dot(dotnumber)Touched
		  variable is set to true
		*/
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
		else if (dot5->getBoundingBox().containsPoint(touch->getLocation()))
		{
			dot5Touched = true;
		}
		else if (dot6->getBoundingBox().containsPoint(touch->getLocation()))
		{
			dot6Touched = true;
		}
	}
	/*
       If the user draws outside of the bounding boxes of the dots they are
	   then brought to the LoseScene
	*/
	else
	{
		GoToLoseScene(NULL);
	}
}

/*
The GoToWinScene method calls the singletone GameManager.
Depending on what chose the user made when selecting a 
level there are two things that can happen when they
draw the letter correctly
1. If the user chose to draw only this letter they will
be brought to the Win scene
2. If the user chose to do all the letters they will be 
brought to the letter b scene, where they will have to
draw the letter b
*/
void AScene::GoToWinScene(Ref *sender)
{
	/*
	  Here an instance of the singleton GameManager
	  is being called to see what needs to happen next
	*/
	GameManager* gm = GameManager::getInstance();
	
	/*
	   If getChoice is true then when the user draws the 
		letter correctly they will be brought to the letter
		b scene to draw the letter b
	*/
	if (gm->getChoice())
	{
		auto scene = BScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	/*
	   If getChoice is false when the user draws the 
		letter correctly they will be brought to the 
		win scene
	*/
	else
	{
		auto scene = WinScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}
//The GoToLoseScene changes the current scene to the lose scene
void AScene::GoToLoseScene(Ref *sender)
{
	auto scene = LoseScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
//The GoToMainMenuScene changes the current scene to the main menu scene 
void AScene::GoToMainMenuScene(Ref *sender)
{
	auto scene = LetterSelection::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}