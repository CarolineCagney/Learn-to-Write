//Here Cocos2d and Box2D are included in this class
#include "cocos2d.h"
#include "Box2D/Box2D.h"

//Here the namespace cocos2d is used for this class
using namespace cocos2d; 

class LetterSelection : public cocos2d::Layer
{
//Here all the public variables are created
public:
	//Here is where the method to create a new scene is created
	static cocos2d::Scene* createScene();

	//Here the method for the init method is initialised
	virtual bool init();// creating the boon init canss 

	//Here the variable for the Label title is initialised
	Label *Title;

	//Here the sprites a to z are initialised
	Sprite* _a;
	Sprite* _b;
	Sprite* _c;
	Sprite* _d;
	Sprite* _e;
	Sprite* _f;
	Sprite* _g;
	Sprite* _h;
	Sprite* _i;
	Sprite* _j;
	Sprite* _k;
	Sprite* _m;
	Sprite* _n;
	Sprite* _o;
	Sprite* _p;
	Sprite* _q;
	Sprite* _r;
	Sprite* _s;
	Sprite* _t;
	Sprite* _u;
	Sprite* _v;
	Sprite* _w;
	Sprite* _x;
	Sprite* _y;
	Sprite* _z;

	//Here the variable for the Label LetterSelectionText is initialised
	Label *LetterSelectionText;

	/*
     Here the methods to go to different scenes in this program  is initialised	 
	 There are twenty eight GoTo method
	 *GoToMainMenuScene 
	 **This goes to the main menu
	 *GoToSceneA to GoToSceneZ
	 *CleanUp
	*/
	void GoToMainMenuScene(Ref *sender); //This goes to the letter  scene

	void GoToSceneA(Ref *sender); //This goes to the letter a scene
	void GoToSceneB(Ref *sender); //This goes to the letter b scene
	void GoToSceneC(Ref *sender); //This goes to the letter c scene
	void GoToSceneD(Ref *sender); //This goes to the letter d scene
	void GoToSceneE(Ref *sender); //This goes to the letter e scene
	void GoToSceneF(Ref *sender); //This goes to the letter f scene
	void GoToSceneG(Ref *sender); //This goes to the letter g scene
	void GoToSceneH(Ref *sender); //This goes to the letter h scene
	void GoToSceneI(Ref *sender); //This goes to the letter i scene
	void GoToSceneJ(Ref *sender); //This goes to the letter j scene
	void GoToSceneK(Ref *sender); //This goes to the letter k scene
	void GoToSceneL(Ref *sender); //This goes to the letter l scene
	void GoToSceneM(Ref *sender); //This goes to the letter m scene
	void GoToSceneN(Ref *sender); //This goes to the letter n scene
	void GoToSceneO(Ref *sender); //This goes to the letter o scene
	void GoToSceneP(Ref *sender); //This goes to the letter p scene
	void GoToSceneQ(Ref *sender); //This goes to the letter q scene
	void GoToSceneR(Ref *sender); //This goes to the letter r scene
	void GoToSceneS(Ref *sender); //This goes to the letter s scene
	void GoToSceneT(Ref *sender); //This goes to the letter t scene
	void GoToSceneU(Ref *sender); //This goes to the letter u scene
	void GoToSceneV(Ref *sender); //This goes to the letter v scene
	void GoToSceneW(Ref *sender); //This goes to the letter w scene
	void GoToSceneX(Ref *sender); //This goes to the letter x scene
	void GoToSceneY(Ref *sender); //This goes to the letter y scene
	void GoToSceneZ(Ref *sender); //This goes to the letter z scene

	void CleanUp(Ref *sender);	 //Here is the CleanUp method

	// implement the "static create()" method manually
	CREATE_FUNC(LetterSelection);
};