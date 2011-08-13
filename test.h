#include "common.h"
#include "Engine/CEngine.h"
#include "GameplayCore/CGameplayCore.h"

using namespace Seventh;

class myGame : public CEngine
{
public:
	myGame();
	~myGame();

private:
	void setInitialConfig();
};

// test states
class StateMenu : public CState
{
public:
	StateMenu();
	~StateMenu();
};
