#pragma once

#include "Base.h"

NS_BEGIN(Engine)

class CGameInstance;

class ENGINE_DLL CLevel : public CBase
{
protected:
    CLevel(Device* device, Context* context);
    virtual ~CLevel() = default;

public:
    virtual HRESULT Initialize();
    virtual void    Update(_float fTimeDelta);
    virtual void    LateUpdate(_float fTimeDelta);
    virtual HRESULT Render();

protected:
    Device*         m_Device = { nullptr };
    Context*        m_Context = { nullptr };
    CGameInstance*  m_GameInstance = { nullptr };

public:
    virtual void    Free() override;

};

NS_END
