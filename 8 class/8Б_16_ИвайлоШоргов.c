/*Създайте структура за мисия (Quest), която съдържа следните полета:
уникален идентификатор на мисията;
описание на мисията;
брой стъпки нужни за изпълнение на мисията
сегашна стъпка от изпълнението
награда, в брой злато
списък с идентификаторите на други мисии (максимум 5), които трябва да са изпълнени за да е възможно приемането на мисията(приемате, че в този списък няма повторения)
Създайте и структура за инвентар (Inventory), която съдържа:
наличното количество злато (или пари);
текущо изпълнявана мисия
масив от до 10 изпълнени мисии.
Използвайте typedef и за двете структури.

Реализирайте функция за създаване на мисия
Quest create_quest( ... )  <- вие си изберете параметрите,
която създава нова мисия със уникален идентификатор.

Реализирайте функция за приемане на мисия
int claim_quest(Inventory* inv, Quest quest),
която добавя дадената мисия за изпълнение в инвентара - това е възможно само ако понастоящем не се изпълнява мисия и са изпълнени всички нужни за тази мисия предходни мисии (списъка с идентификатори).

Реализирайте функция за изпълнение на мисия
int complete_quest(Inventory* inv),
 която мести текущо изпълняваната мисия  в списъка с изпълнени и награждава с съответното количество злато.

(допълнителна функционалност е това да премахвате най-отдавна изпълнената мисия в случай на препълване на списъка.)

** приемате, че всички входни данни са валидни
*** НЕ правете user input
*/

#include <stdio.h>
#include <string.h>

#define complQuests 10
#define descripLength 60
#define reqQuests 5

typedef struct
{
    int id;
    char descr[descripLength];
    int prereq[reqQuests];
    int steps_req;
    int current_step;
    int reward;

} Quest;

typedef struct
{
    int dold;
    Quest current_quest;
    Quest completed_quests[complQuests];
} Inventory;

Quest create_quest(int id, const char *description, int reqSteps, int reward, int requiredQuests[reqQuests]);

int claim_quest(Inventory *inv, Quest quest);

int complete_quest(Inventory *inv);

int main()
{
    return 0;
}

Quest create_quest(int id, const char *description, int reqSteps, int reward, int requiredQuests[reqQuests])
{
    Quest newQuest;
    newQuest.id = id;
    strcat(newQuest.descr, description);
    newQuest.steps_req = reqSteps;
    newQuest.current_step = 0;
    newQuest.reward = reward;
    for (int i = 0; i < reqQuests; i++)
    {
        newQuest.prereq[i] = requiredQuests[i];
    }

    printf("You have created a new quest successfully!\n");
    ;
    return newQuest;
}

int claim_quest(Inventory *inv, Quest quest)
{
    if (inv->current_quest.id != 0)
    {
        return -1;
    }

    for (int i = 0; i < reqQuests; i++)
    {
        int prereq_id = quest.prereq[i];
        if (prereq_id == 0)
        {
            break;
        }

        int found = 0;
        for (int j = 0; j < complQuests; j++)
        {
            if (inv->completed_quests[j].id == prereq_id)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            return -1;
        }
    }

    inv->current_quest = quest;
    return 0;
}

int complete_quest(Inventory *inv)
{
    if (inv->current_quest.id == 0)
    {
        return -1;
    }

    for (int i = 0; i < complQuests; i++)
    {
        if (inv->completed_quests[i].id == 0)
        {
            inv->completed_quests[i] = inv->current_quest;
            break;
        }
    }

    inv->dold += inv->current_quest.reward;

    inv->current_quest.id = 0;

    return 0;
}