#include "ScriptPCH.h"

class duelreset : public PlayerScript
{
    public:
        duelreset() : PlayerScript("duelreset") {}

    void OnDuelEnd(Player *winner, Player *loser, DuelCompleteType type)
    {
        // reset cooldowns in zone 2817 - under dalaran CSF, 12 - outside Stormwind and 14- outside Orgrimmar
                if (winner->GetZoneId() == 2817 || winner->GetZoneId() == 12 || winner->GetZoneId() == 14)
                {
                        winner->RemoveArenaSpellCooldowns();
                        loser->RemoveArenaSpellCooldowns();
                        winner->SetHealth(winner->GetMaxHealth());
                        winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
                        loser->SetHealth(loser->GetMaxHealth());
                        loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));
                }
    }
};

void AddSC_duelreset()
{
    new duelreset;
}