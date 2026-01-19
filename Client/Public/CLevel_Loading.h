#pragma once

#include "Client_Defines.h"
#include "Level.h"

NS_BEGIN(Client)

class CLevel_Loading : public CLevel
{
private:
    CLevel_Loading(Device* device, Context* context);
    virtual ~CLevel_Loading() = default;

public:
    virtual HRESULT     Initialize() override;
    virtual void        Update(_float fTimeDelta) override;
    virtual void        LateUpdate(_float fTimeDelta) override;
    virtual HRESULT     Render() override;

public:
    static CLevel_Loading*  Create(Device* device, Context* context);
    virtual void            Free() override;

};

NS_END
