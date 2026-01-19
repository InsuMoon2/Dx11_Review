#include "Level_Manager.h"
#include "GameInstance.h"
#include "Level.h"

CLevel_Manager::CLevel_Manager()
    : m_GameInstance(CGameInstance::GetInstance())
{
    Safe_AddRef(m_GameInstance);
}

void CLevel_Manager::Update(_float timeDelta)
{
    NULL_CHECK(m_CurrentLevel);

    m_CurrentLevel->Update(timeDelta);
}

void CLevel_Manager::LateUpdate(_float timeDelta)
{
    NULL_CHECK(m_CurrentLevel);

    m_CurrentLevel->LateUpdate(timeDelta);
}

HRESULT CLevel_Manager::Render()
{
    NULL_CHECK_RETURN(m_CurrentLevel, E_FAIL);

    m_CurrentLevel->Render();

    return S_OK;
}

HRESULT CLevel_Manager::Change_Level(_uint newIndex, CLevel* newLevel)
{
    if (m_CurrentLevel != nullptr)
        m_GameInstance->Clear_Resources(newIndex);

    if (Safe_Release(m_CurrentLevel) != 0)
        return E_FAIL;

    m_CurrentLevel = newLevel;
    m_CurrentLevelIndex = newIndex;

    return S_OK;
}

CLevel_Manager* CLevel_Manager::Create()
{
    return new CLevel_Manager();
}

void CLevel_Manager::Free()
{
    CBase::Free();

    Safe_Release(m_CurrentLevel);
    Safe_Release(m_GameInstance);
}
