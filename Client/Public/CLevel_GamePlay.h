#pragma once

#include "Client_Defines.h"
#include "Level.h"

NS_BEGIN(Client)

class CLevel_GamePlay : public CLevel
{
private:
    CLevel_GamePlay(Device* device, Context* context);
    virtual ~CLevel_GamePlay() = default;

public:
    virtual HRESULT     Initialize() override;
    virtual void        Update(_float fTimeDelta) override;
    virtual void        LateUpdate(_float fTimeDelta) override;
    virtual HRESULT     Render() override;

public:
    static CLevel_GamePlay*  Create(Device* device, Context* context);
    virtual void            Free() override;

};

NS_END
