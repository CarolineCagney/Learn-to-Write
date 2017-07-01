#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class LevelSelectionScene : public cocos2d::Layer
{
public:
	static Scene* createScene();

	virtual bool init();
	
	//Here the variable for the Label title is initialised
	Label *Title;

	// implement the "static create()" method manually
	CREATE_FUNC(LevelSelectionScene);

private:
	/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are three GoTo methods
	 *GoToMainMenuScene 
	 **This goes to the main menu
	 *GoToLetterSelection
	 **This goes to the scene where all the letters are on the screen for the user
	   to chose from
	 *GoToLetterAScene
	 **This goes to the letter A scene
	*/
	void GoToMainMenu(Ref *sender);					//This goes to the main menu scene
	void GoToLetterSelection(Ref *sender);			//This goes to the letterselection scene
	void GoToLetterAScene(Ref *sender);				//This goes to the letter a scene
	void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif // __MAIN_MENU_SCENE_H__