#include "cocos2d.h"// brining in cocos funcality 
#include "Box2D/Box2D.h"

using namespace cocos2d; // namespace for cococs so you dont have to use cocos2d:: every time 

class BScene : public cocos2d::Layer
{

public:

	static cocos2d::Scene* createScene();
	/*
	In the following section is where all the sprites for this class are initialised 
	and given appropriate names.
	The sprites for this class consist of 
	*A picture of the letter b to be writen over 
	*Seven dots to be connected by being drawn over
	*/
	Sprite* _b;
	Sprite* dot;
	Sprite* dot2;
	Sprite* dot3;
	Sprite* dot4;
	Sprite* dot5;
	Sprite* dot6;
	Sprite* dot7;
	
	/*
	In the following section is where the bool values of the dots for this letter are 
	initialised
	Each dot is given a bool value which is set to 0 when the program begins 
	Once the user has clicked on a dot and has written over all the required dots, 
	these bool values will be set to true 
	*/

	bool dot1Touched = false;
	bool dot2Touched = false;
	bool dot3Touched = false;
	bool dot4Touched = false;
	bool dot5Touched = false;
	bool dot6Touched = false;
	bool dot7Touched = false;
/*
	Here are where two vector points are created,
	One for the old postion the mouse was in
	and
	One for the new position the mouse is now in
	
	Once the user has touched the screen and starts to draw on the screen these two points
    are used to check if the user is properly connecting the dots on the letter correctly 
	*/
	Vec2 oldPoint;
	Vec2 newPoint;
	
	/*
	The following section is where the touch listner method are being created 
	There are three touch listener method
	
	* 1. onTouchBegan 
	  **When the user initially touches the screen with a pen or mouse,
	    this method is called to see if an action needs to be done, 
	    since the screen has been touched
	  2. onTouchEnded 
	  **When the user has finshed touching the screen with a pen or mouse,
	    this method is called to see if an action needs to be done since 
		the user has finished interacting with the screen.
	  3. onTouchMoved
	  **When the user touches the screen with a pen or mouse and then draw
	    across the screen this method is called to see if an action needs
		to be completed, for this program when the user touches one of the
		dots and draws to another dot a line is created from where they 
		began to draw and where ever they move across the screen
	*/
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*); //When the user touches the screen the appropriate action is completed. 
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*); //When the user stops touching the screen the appropriate action is completed.
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*); //When the user touches the screen and draw across the screen the appropriate action is completed

	// creating the bool init class 
	virtual bool init();

/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are three GoTo method
	 *GoToMainMenuScene
	 **This goes to the main menu
	 *GoToWinScene
	 **This goes to the winners game over scene
	 *GoToLoseScene
	 **This goes to the sorry try again game over scene
	*/
	void GoToMainMenuScene(Ref *sender); //This goes to the main menu
	void GoToWinScene(Ref *sender);		 //This goes to the winners game over scene
	void GoToLoseScene(Ref *sender);	 //This goes to the sorry try again game over scene

	// implement the "static create()" method manually
	CREATE_FUNC(BScene);
};