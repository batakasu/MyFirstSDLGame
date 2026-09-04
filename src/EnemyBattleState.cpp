#include "EnemyBattleState.h"
#include "MainScene.h"
#include "RouteSelectState.h" // ルート選択ステートのインクルード
#include "ResultScene.h"
#include <SDL3/SDL.h>

void EnemyBattleState::Enter(MainScene& context)
{
    SDL_Log("=== 戦闘フェーズ開始 ===");
    mEnemyHp = 10;
    mEnemyPower = 1;
    SDL_Log("敵が現れた！ 敵HP: %d | 敵攻撃力: %d", mEnemyHp, mEnemyPower);
    SDL_Log("操作: [SPACE] 攻撃する");
}

void EnemyBattleState::Update(MainScene& context, float deltaTime)
{
    // GameContext 経由でキーボードを取得
    if (context.GetGameContext().mKeyboard.IsPressed(SDL_SCANCODE_SPACE))
    {
        // 1. 敵からの攻撃（カプセル化した TakeDamage を利用）
        context.TakeDamage(mEnemyPower);
        SDL_Log("敵の攻撃！ ダメージを受けた。（残りHP: %d/%d）", context.GetHp(), context.GetMaxHp());

        // プレイヤーの敗北チェック
        if (context.GetHp() <= 0)
        {
            SDL_Log("ゲームオーバー...");
            context.GetSceneManager().ChangeScene(std::make_unique<ResultScene>(context.GetSceneManager(), context.GetGameContext()));
            return;
        }

        // 2. プレイヤーの攻撃（GetPower を利用）
        int playerPower = context.GetPower();
        mEnemyHp -= playerPower;
        SDL_Log("プレイヤーの攻撃！ 敵に %d のダメージ（敵残りHP: %d）", playerPower, (mEnemyHp > 0 ? mEnemyHp : 0));

        // 勝利チェック
        if (mEnemyHp <= 0)
        {
            SDL_Log("敵を討伐した！ 10G を獲得した。");
            context.AddMoney(10); // カプセル化した AddMoney を利用
            context.ChangeState(std::make_unique<RouteSelectState>());
        }
    }
}

void EnemyBattleState::Draw(MainScene& context)
{
}

void EnemyBattleState::Exit(MainScene& context)
{
}