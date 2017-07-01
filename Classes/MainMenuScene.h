//Here Cocos2d is included into the class
#include "cocos2d.h"

//Here the namespace cocos2d is used for this class
using namespace cocos2d;

class MainMenuScene : public cocos2d::Layer
{
//Here all the public variables are created
public:
	//Here is where the method to create a new scene is created
	static Scene* createScene();

	//Here the method for the init method is initialised
	virtual bool init();
	
	//Here the variable for the Label title is initialised
	Label *Title;

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);

//Here all the private variables are created
private:
	/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are three GoTo methods
	 *GoToLetterSelection
	 **This goes to the scene where all the letters are on the screen for the user
	   to chose from
	 *GoToLetterAScene
	 **This goes to the letter A scene
	 *menuCloseCallback
	 **This when called exits the application
	*/
	void GoToLevelSelection(Ref *sender);		   //This goes to the letterselection scene
	void GoToAboutTheApp(Ref *sender);			   //This goes to the About the about scene
	void GoToInstructions(Ref *sender);			   //This goes to the Instructions scene
	void menuCloseCallback(cocos2d::Ref* pSender); //This quits the application

};