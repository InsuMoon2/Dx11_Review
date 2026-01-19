#pragma once

#include "Client_Defines.h"
#include "Level.h"

NS_BEGIN(Client)

class CLevel_Logo : public CLevel
{
private:
    CLevel_Logo(Device* device, Context* context);
    virtual ~CLevel_Logo() = default;

public:
    virtual HRESULT     Initialize() override;
    virtual void        Update(_float fTimeDelta) override;
    virtual void        LateUpdate(_float fTimeDelta) override;
    virtual HRESULT     Render() override;

public:
    static CLevel_Logo*  Create(Device* device, Context* context);
    virtual void            Free() override;

};

NS_END
