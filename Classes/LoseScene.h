//Here Cocos2d is included into the class
#include "cocos2d.h"

//Here the namespace cocos2d is used for this class
using namespace cocos2d;

class LoseScene : public cocos2d::Layer
{
//Here all the public variables are created
public:
	//Here is where the method to create a new scene is created
	static Scene* createScene();

	//Here the method for the init method is initialised
	virtual bool init();
	
	//Here the variable for the Label title, title2 and title3 are initialised
	Label *Title;
	Label *Title2;
	Label *Title3;

	// implement the "static create()" method manually
	CREATE_FUNC(LoseScene);

//Here all the private variables are created
private:
	/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are three GoTo methods
	 *GoToMainMenuScene 
	 **This goes to the main menu
	 *GoToLetterSelection
	 **This goes to the scene where all the letters are on the screen for the user
	   to chose from
	*/
	void GoToMainMenuScene(Ref *sender);					//This goes to the main menu scene
	void GoToLevelSelection(Ref *sender);			//This goes to the letterselection scene
};