//Here are the include files for this class
#include "LetterSelection.h"
#include "AScene.h"
#include "BScene.h"
#include "CScene.h"
#include "DScene.h"
#include "EScene.h"
#include "FScene.h"
#include "GScene.h"
#include "HScene.h"
#include "IScene.h"
#include "JScene.h"
#include "KScene.h"
#include "LScene.h"
#include "MScene.h"
#include "NScene.h"
#include "OScene.h"
#include "PScene.h"
#include "QScene.h"
#include "RScene.h"
#include "SScene.h"
#include "TScene.h"
#include "UScene.h"
#include "VScene.h"
#include "WScene.h"
#include "XScene.h"
#include "YScene.h"
#include "ZScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

// namespace for cocos2d
using namespace cocos2d;
#define MENU_SFX "music.mp3"

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* LetterSelection::createScene()//create scene
{
	//Here the new scene is created
	auto scene = Scene::create();

	// Here the layer MainMenuScene is created
	auto layer = LetterSelection::create();

	//Here the scene is added to the scene as a child
	scene->addChild(layer);

	// Here the scene is returned
	return scene;
}

//Here everything needed for the start of the application is created
bool LetterSelection::init()//initing the game so the scene can be made 
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}//code nike this for consisinsty 

	auto origin = Director::getInstance()->getVisibleOrigin();//setting up the origin 
	auto winSize = Director::getInstance()->getVisibleSize();// as wenn as the window size or the visibne size as wenn 

	//Here the image for the background is gotten
	auto backgroundSprite = Sprite::create("background.png");
	//Here the positon for the background image is set
	backgroundSprite->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	//Here the background is added to the scene as a child
	this->addChild(backgroundSprite);

	/*In the following section all the buttons for this application are
	*Created
	*Positioned
	*Added to the scene
	*Made into menu items which are also added to the scene
	*/
	
	const float ScoreFontSize = 40;

	Title = Label::create("Chose a Letter", "fonts/arial.ttf", ScoreFontSize);
	Title->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 1.05 + origin.y));
	Title->setColor(ccc3(0, 0, 0));
	this->addChild(Title);

	auto MainMenu = MenuItemImage::create("MainMenu.png", "MainMenu.png", CC_CALLBACK_1(LetterSelection::GoToMainMenuScene, this));
	auto LetterA = MenuItemImage::create("a.png", "a.png", CC_CALLBACK_1(LetterSelection::GoToSceneA, this));
	auto LetterB = MenuItemImage::create("b.png", "b.png", CC_CALLBACK_1(LetterSelection::GoToSceneB, this));
	auto LetterC = MenuItemImage::create("c.png", "c.png", CC_CALLBACK_1(LetterSelection::GoToSceneC, this));
	auto LetterD = MenuItemImage::create("d.png", "d.png", CC_CALLBACK_1(LetterSelection::GoToSceneD, this));
	auto LetterE = MenuItemImage::create("e.png", "e.png", CC_CALLBACK_1(LetterSelection::GoToSceneE, this));
	auto LetterF = MenuItemImage::create("f.png", "f.png", CC_CALLBACK_1(LetterSelection::GoToSceneF, this));
	auto LetterG = MenuItemImage::create("g.png", "g.png", CC_CALLBACK_1(LetterSelection::GoToSceneG, this));
	auto LetterH = MenuItemImage::create("h.png", "h.png", CC_CALLBACK_1(LetterSelection::GoToSceneH, this));
	auto LetterI = MenuItemImage::create("i.png", "i.png", CC_CALLBACK_1(LetterSelection::GoToSceneI, this));
	auto LetterJ = MenuItemImage::create("j.png", "j.png", CC_CALLBACK_1(LetterSelection::GoToSceneJ, this));
	auto LetterK = MenuItemImage::create("k.png", "k.png", CC_CALLBACK_1(LetterSelection::GoToSceneK, this));
	auto LetterL = MenuItemImage::create("l.png", "l.png", CC_CALLBACK_1(LetterSelection::GoToSceneL, this));
	auto LetterM = MenuItemImage::create("m.png", "m.png", CC_CALLBACK_1(LetterSelection::GoToSceneM, this));
	auto LetterN = MenuItemImage::create("n.png", "n.png", CC_CALLBACK_1(LetterSelection::GoToSceneN, this));
	auto LetterO = MenuItemImage::create("o.png", "o.png", CC_CALLBACK_1(LetterSelection::GoToSceneO, this));
	auto LetterP = MenuItemImage::create("p.png", "p.png", CC_CALLBACK_1(LetterSelection::GoToSceneP, this));
	auto LetterQ = MenuItemImage::create("q.png", "q.png", CC_CALLBACK_1(LetterSelection::GoToSceneQ, this));
	auto LetterR = MenuItemImage::create("r.png", "r.png", CC_CALLBACK_1(LetterSelection::GoToSceneR, this));
	auto LetterS = MenuItemImage::create("s.png", "s.png", CC_CALLBACK_1(LetterSelection::GoToSceneS, this));
	auto LetterT = MenuItemImage::create("t.png", "t.png", CC_CALLBACK_1(LetterSelection::GoToSceneT, this));
	auto LetterU = MenuItemImage::create("u.png", "u.png", CC_CALLBACK_1(LetterSelection::GoToSceneU, this));
	auto LetterV = MenuItemImage::create("v.png", "v.png", CC_CALLBACK_1(LetterSelection::GoToSceneV, this));
	auto LetterW = MenuItemImage::create("w.png", "w.png", CC_CALLBACK_1(LetterSelection::GoToSceneW, this));
	auto LetterX = MenuItemImage::create("x.png", "x.png", CC_CALLBACK_1(LetterSelection::GoToSceneX, this));
	auto LetterY = MenuItemImage::create("y.png", "y.png", CC_CALLBACK_1(LetterSelection::GoToSceneY, this));
	auto LetterZ = MenuItemImage::create("z.png", "z.png", CC_CALLBACK_1(LetterSelection::GoToSceneZ, this));

	/*
		Here the postition f
	*/
	MainMenu->setPosition(Point(winSize.width / 2.4 + origin.x, winSize.height / 5 + origin.y));
	
	LetterA->setPosition(Point(winSize.width / 9 + origin.x, winSize.height / 1.2 + origin.y));
	LetterB->setPosition(Point(winSize.width / 3.8 + origin.x, winSize.height / 1.2 + origin.y));
	LetterC->setPosition(Point(winSize.width / 2.4 + origin.x, winSize.height / 1.2 + origin.y));
	LetterD->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 1.2 + origin.y));
	LetterE->setPosition(Point(winSize.width / 1.37 + origin.x, winSize.height / 1.2 + origin.y));
	LetterF->setPosition(Point(winSize.width / 1.14 + origin.x, winSize.height / 1.2 + origin.y));
	
	LetterG->setPosition(Point(winSize.width / 9 + origin.x, winSize.height / 1.5 + origin.y));
	LetterH->setPosition(Point(winSize.width / 3.8 + origin.x, winSize.height / 1.5 + origin.y));
	LetterI->setPosition(Point(winSize.width / 2.4 + origin.x, winSize.height / 1.5 + origin.y));
	LetterJ->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 1.5 + origin.y));
	LetterK->setPosition(Point(winSize.width / 1.37 + origin.x, winSize.height / 1.5 + origin.y));
	LetterL->setPosition(Point(winSize.width / 1.14 + origin.x, winSize.height / 1.5 + origin.y));
	
	LetterM->setPosition(Point(winSize.width / 9 + origin.x, winSize.height / 2.0 + origin.y));
	LetterN->setPosition(Point(winSize.width / 3.8 + origin.x, winSize.height / 2.0 + origin.y));
	LetterO->setPosition(Point(winSize.width / 2.4 + origin.x, winSize.height / 2.0 + origin.y));
	LetterP->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 2.0 + origin.y));
	LetterQ->setPosition(Point(winSize.width / 1.37 + origin.x, winSize.height / 2.0 + origin.y));
	LetterR->setPosition(Point(winSize.width / 1.14 + origin.x, winSize.height / 2.0 + origin.y));

	LetterS->setPosition(Point(winSize.width / 9 + origin.x, winSize.height / 2.9 + origin.y));
	LetterT->setPosition(Point(winSize.width / 3.8 + origin.x, winSize.height / 2.9 + origin.y));
	LetterU->setPosition(Point(winSize.width / 2.4 + origin.x, winSize.height / 2.9 + origin.y));
	LetterV->setPosition(Point(winSize.width / 1.75 + origin.x, winSize.height / 2.9 + origin.y));
	LetterW->setPosition(Point(winSize.width / 1.37 + origin.x, winSize.height / 2.9 + origin.y));
	LetterX->setPosition(Point(winSize.width / 1.14 + origin.x, winSize.height / 2.9 + origin.y));
	
	LetterY->setPosition(Point(winSize.width / 9 + origin.x, winSize.height / 5 + origin.y));
	LetterZ->setPosition(Point(winSize.width / 3.8 + origin.x, winSize.height / 5 + origin.y));
	
	auto MainMenuButton = Menu::create(MainMenu, NULL);
	auto LetterAButton = Menu::create(LetterA, NULL);
	auto LetterBButton = Menu::create(LetterB, NULL);
	auto LetterCButton = Menu::create(LetterC, NULL);
	auto LetterDButton = Menu::create(LetterD, NULL);
	auto LetterEButton = Menu::create(LetterE, NULL);
	auto LetterFButton = Menu::create(LetterF, NULL);
	auto LetterGButton = Menu::create(LetterG, NULL);
	auto LetterHButton = Menu::create(LetterH, NULL);
	auto LetterIButton = Menu::create(LetterI, NULL);
	auto LetterJButton = Menu::create(LetterJ, NULL);
	auto LetterKButton = Menu::create(LetterK, NULL);
	auto LetterLButton = Menu::create(LetterL, NULL);
	auto LetterMButton = Menu::create(LetterM, NULL);
	auto LetterNButton = Menu::create(LetterN, NULL);
	auto LetterOButton = Menu::create(LetterO, NULL);
	auto LetterPButton = Menu::create(LetterP, NULL);
	auto LetterQButton = Menu::create(LetterQ, NULL);
	auto LetterRButton = Menu::create(LetterR, NULL);
	auto LetterSButton = Menu::create(LetterS, NULL);
	auto LetterTButton = Menu::create(LetterT, NULL);
	auto LetterUButton = Menu::create(LetterU, NULL);
	auto LetterVButton = Menu::create(LetterV, NULL);
	auto LetterWButton = Menu::create(LetterW, NULL);
	auto LetterXButton = Menu::create(LetterX, NULL);
	auto LetterYButton = Menu::create(LetterY, NULL);
	auto LetterZButton = Menu::create(LetterZ, NULL);

	
	MainMenuButton->setPosition(Point::ZERO);
	LetterAButton->setPosition(Point::ZERO);
	LetterBButton->setPosition(Point::ZERO);
	LetterCButton->setPosition(Point::ZERO);
	LetterDButton->setPosition(Point::ZERO);
	LetterEButton->setPosition(Point::ZERO);
	LetterFButton->setPosition(Point::ZERO);
	LetterGButton->setPosition(Point::ZERO);
	LetterHButton->setPosition(Point::ZERO);
	LetterIButton->setPosition(Point::ZERO);
	LetterJButton->setPosition(Point::ZERO);
	LetterKButton->setPosition(Point::ZERO);
	LetterLButton->setPosition(Point::ZERO);
	LetterMButton->setPosition(Point::ZERO);
	LetterNButton->setPosition(Point::ZERO);
	LetterOButton->setPosition(Point::ZERO);
	LetterPButton->setPosition(Point::ZERO);
	LetterQButton->setPosition(Point::ZERO);
	LetterRButton->setPosition(Point::ZERO);
	LetterSButton->setPosition(Point::ZERO);
	LetterTButton->setPosition(Point::ZERO);
	LetterUButton->setPosition(Point::ZERO);
	LetterVButton->setPosition(Point::ZERO);
	LetterWButton->setPosition(Point::ZERO);
	LetterQButton->setPosition(Point::ZERO);
	LetterXButton->setPosition(Point::ZERO);
	LetterYButton->setPosition(Point::ZERO);
	LetterZButton->setPosition(Point::ZERO);
	
	this->addChild(MainMenuButton);
	this->addChild(LetterAButton);
	this->addChild(LetterBButton);
	this->addChild(LetterCButton);
	this->addChild(LetterDButton);
	this->addChild(LetterEButton);
	this->addChild(LetterFButton);
	this->addChild(LetterGButton);
	this->addChild(LetterHButton);
	this->addChild(LetterIButton);
	this->addChild(LetterJButton);
	this->addChild(LetterKButton);
	this->addChild(LetterLButton);
	this->addChild(LetterMButton);
	this->addChild(LetterNButton);
	this->addChild(LetterOButton);
	this->addChild(LetterPButton);
	this->addChild(LetterQButton);
	this->addChild(LetterRButton);
	this->addChild(LetterSButton);
	this->addChild(LetterTButton);
	this->addChild(LetterUButton);
	this->addChild(LetterVButton);
	this->addChild(LetterWButton);
	this->addChild(LetterXButton);
	this->addChild(LetterYButton);
	this->addChild(LetterZButton);
	
	return true;
}//end is init()


 //This is the  is created 
void LetterSelection::GoToMainMenuScene(Ref *sender)//go to scene
{
	//Here the Main Menu Scene scene is being made
	auto scene = MainMenuScene::createScene();
	//Here the Letter Selection Scene is being repalced with the Main Menu Scene
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneA(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = AScene::createScene();
	//Here the Letter Selection Scene is being repalced with the AScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneB(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = BScene::createScene();
	//Here the Letter Selection Scene is being repalced with the BScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
}
//This is the  is created 
void LetterSelection::GoToSceneC(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = CScene::createScene();
	//Here the Letter Selection Scene is being repalced with the CScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneD(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = DScene::createScene();
	//Here the Letter Selection Scene is being repalced with the DScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneE(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = EScene::createScene();
	//Here the Letter Selection Scene is being repalced with the EScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneF(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = FScene::createScene();
	//Here the Letter Selection Scene is being repalced with the FScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneG(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = GScene::createScene();
	//Here the Letter Selection Scene is being repalced with the GScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneH(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = HScene::createScene();
	//Here the Letter Selection Scene is being repalced with the HScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneI(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = IScene::createScene();
	//Here the Letter Selection Scene is being repalced with the IScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneJ(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = JScene::createScene();
	//Here the Letter Selection Scene is being repalced with the JScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneK(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = KScene::createScene();
	//Here the Letter Selection Scene is being repalced with the KScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneL(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = LScene::createScene();
	//Here the Letter Selection Scene is being repalced with the LScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneM(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = MScene::createScene();
	//Here the Letter Selection Scene is being repalced with the MScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneN(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = NScene::createScene();
	//Here the Letter Selection Scene is being repalced with the NScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneO(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = OScene::createScene();
	//Here the Letter Selection Scene is being repalced with the OScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneP(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = PScene::createScene();
	//Here the Letter Selection Scene is being repalced with the PScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneQ(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = QScene::createScene();
	//Here the Letter Selection Scene is being repalced with the QScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneR(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = RScene::createScene();
	//Here the Letter Selection Scene is being repalced with the RScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneS(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = SScene::createScene();
	//Here the Letter Selection Scene is being repalced with the SScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneT(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = TScene::createScene();
	//Here the Letter Selection Scene is being repalced with the TScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneU(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = UScene::createScene();
	//Here the Letter Selection Scene is being repalced with the UScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneV(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = VScene::createScene();
	//Here the Letter Selection Scene is being repalced with the VScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneW(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = WScene::createScene();
	//Here the Letter Selection Scene is being repalced with the WScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneX(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = XScene::createScene();
	//Here the Letter Selection Scene is being repalced with the XScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneY(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = YScene::createScene();
	//Here the Letter Selection Scene is being repalced with the YScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
//This is the  is created 
void LetterSelection::GoToSceneZ(Ref *sender)//go to scene 
{
	//Here the  scene is being made
	auto scene = ZScene::createScene();
	//Here the Letter Selection Scene is being repalced with the ZScene 
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));	
	
}
