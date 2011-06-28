include "ScriptPCH.h"

class custom_levelgold : public PlayerScript
{
public:
    custom_levelgold() : PlayerScript("custom_levelgold") {}

    void OnLevelChanged(Player* player, uint8 newLevel)
    {
        std::string subject = "Congratulations!";
        std::string text    = "Gold for Traininf You require";
        uint32 money        = 0;

        switch (newLevel)
        {
		                case 1:
		                        if (player->getClass() != CLASS_DEATH_KNIGHT) 
                                {
                                        money = 10000;
                                        subject = "Welcome on Heroic-WoW server";
                                        text = "Gold for start, have fun on our server and Good Luck!";
                                }
                                break;
			            case 10:
                                if (player->getClass() != CLASS_DEATH_KNIGHT) 
                                {
                                        money = 100000;
                                        subject = "Level 10!";
                                        text = "Congratulations and Good Luck!";
                                }
                                break;
            
                        case 20:
                                if (player->getClass() != CLASS_DEATH_KNIGHT)
                                {
                                        money = 250000;
                                        subject = "Level 20!";
                                        text = "Congratulations and Good Luck!";
                                }
                                break;
            
                        case 40:
                                if (player->getClass() != CLASS_DEATH_KNIGHT)
                                {
                                        money = 500000;
                                        subject = "Level 40!";
                                        text = "Congratulations and Good Luck!";
                                }
                                break;

                                case 60:
                                if (player->getClass() != CLASS_DEATH_KNIGHT)
                                {
                                        money = 3000000;
                                        subject = "Level 60!";
                                        text = "Congratulations and Good Luck!";
                                }
                                break;

            default:
                                break;
        }
                if (money != 0)
                        {
                        MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);

                        SQLTransaction trans = CharacterDatabase.BeginTransaction();

                        MailDraft(subject, text)
                                .AddMoney(money)
                                .SendMailTo(trans, MailReceiver(player,GUID_LOPART(player->GetGUID())),sender);

                        CharacterDatabase.CommitTransaction(trans);
                        }
        }
};

void AddSC_custom_levelgold()
{