#pragma once

#include "Base.h"

NS_BEGIN(Engine)

class CLevel;
class CGameInstance;

class CLevelManager : public CBase
{
private:
    CLevelManager();
    virtual ~CLevelManager() = default;

public:
    void    Update(_float timeDelta);
    void    LateUpdate(_float timeDelta);
    HRESULT Render();

    HRESULT Change_Level(_uint newIndex, CLevel* newLevel);

private:
    CGameInstance*  m_GameInstance = { nullptr };

    _uint           m_CurrentLevelIndex = { };
    CLevel*         m_CurrentLevel = { nullptr };

public:
    CLevelManager*  Create();
    virtual void    Free() override;

};

NS_END
