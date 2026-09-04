#include "RouteSelectState.h"
#include "MainScene.h"
#include "EnemyBattleState.h"
#include "ResultScene.h"
#include <random>
#include <SDL3/SDL.h>

void RouteSelectState::Enter(MainScene& context)
{
    SDL_Log("=== ルート選択フェーズ ===");
    mLeftCard = RollCard();
    mRightCard = RollCard();
    
    // ゲッター経由でステータスを取得
    SDL_Log("ステータス - HP: %d/%d | 攻撃: %d | 防御: %d | 所持金: %dG", 
        context.GetHp(), context.GetMaxHp(), context.GetPower(), context.GetDefense(), context.GetMoney());
    SDL_Log("[1] 左のカード (タイプ: %d) / [2] 右のカード (タイプ: %d)", mLeftCard, mRightCard);
}

int RouteSelectState::RollCard()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 2);
    return dist(gen);
}

void RouteSelectState::Update(MainScene& context, float deltaTime)
{
    int chosenCard = 0;
    if (context.GetGameContext().mKeyboard.IsPressed(SDL_SCANCODE_1) || 
        context.GetGameContext().mKeyboard.IsPressed(SDL_SCANCODE_KP_1))
    {
        chosenCard = mLeftCard;
        SDL_Log("-> 左のルートを進んだ！");
    }
    else if (context.GetGameContext().mKeyboard.IsPressed(SDL_SCANCODE_2) || 
             context.GetGameContext().mKeyboard.IsPressed(SDL_SCANCODE_KP_2))
    {
        chosenCard = mRightCard;
        SDL_Log("-> 右のルートを進んだ！");
    }

    if (chosenCard != 0)
    {
        if (chosenCard == 1)
        {
            context.ChangeState(std::make_unique<EnemyBattleState>());
        }
        else
        {
            // 回復は Heal メソッドを使用
            context.Heal(20);
            SDL_Log("回復の泉で見事 HP が回復した！ 現在HP: %d/%d", context.GetHp(), context.GetMaxHp());
            
            context.ChangeState(std::make_unique<RouteSelectState>());
        }
    }
}

void RouteSelectState::Draw(MainScene& context)
{
}

void RouteSelectState::Exit(MainScene& context)
{
}