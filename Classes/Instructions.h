#include "cocos2d.h"// brining in cocos funcality 
#include "Box2D/Box2D.h"

using namespace cocos2d; // namespace for cococs so you dont have to use cocos2d:: every time 

class Instructions : public cocos2d::Layer
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();// creating the bool init calss 

	/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are one GoTo methods
	 *GoToMainMenuScene 
	 **This goes to the main menu
	*/
	void GoToMainMenuScene(Ref *sender); //This goes to the letter  scene

	// implement the "static create()" method manually
	CREATE_FUNC(Instructions);
};