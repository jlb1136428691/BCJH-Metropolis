// 兔年年兽第九关

// 本代码由 ./assets/generateRule.py 自动生成
#ifndef RULE_HPP
#define RULE_HPP
#include "Calculator.hpp"
#include "functions.hpp"

/**
 * @brief
 *
 * @param rule
 * @param s
 * @return int : the optimal `full` value
 */
int banquetRule(BanquetRule *const &rule, States &s) {
    BanquetStrictRule
        *strictRule[NUM_CHEFS *
                    DISH_PER_CHEF]; // 下一阶段的规则，不受意图生效次数的影响
    BanquetLenientRule *lenientRule[NUM_CHEFS * DISH_PER_CHEF];
    for (int i = 9; i < NUM_CHEFS * DISH_PER_CHEF; i++) {
        strictRule[i] = &rule[i].strictRule;
        lenientRule[i] = &rule[i].lenientRule;
    }
    // 第1轮
    // 条件：三道炒：下阶段切技法料理售价+100%
    if (s.recipe[9]->cookAbility.stirfry > 0 &&
        s.recipe[10]->cookAbility.stirfry > 0 &&
        s.recipe[11]->cookAbility.stirfry > 0) {
        // 效果：三道煮：下阶段炸技法料理售价+100%
        for (int i = 12; i < 15; i++) {
            if (s.recipe[i]->cookAbility.knife > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    for (int i = 9; i < 12; i++) {
        if (s.recipe[i]->flavor.sour) {
            // 效果：酸：本道料理基础售价+50%
            lenientRule[i]->baseRule.buff += 50;
            break;
        }
    }
    // 条件：三道炸：下阶段蒸技法料理售价+100%
    if (s.recipe[9]->cookAbility.fry > 0 &&
        s.recipe[10]->cookAbility.fry > 0 &&
        s.recipe[11]->cookAbility.fry > 0) {
        // 效果：三道炸：下阶段蒸技法料理售价+100%
        for (int i = 12; i < 15; i++) {
            if (s.recipe[i]->cookAbility.steam > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    // 条件：三道烤：下阶段煮技法料理售价+100%
    if (s.recipe[9]->cookAbility.bake > 0 &&
        s.recipe[10]->cookAbility.bake > 0 &&
        s.recipe[11]->cookAbility.bake > 0) {
        // 效果：三道烤：下阶段煮技法料理售价+100%
        for (int i = 12; i < 15; i++) {
            if (s.recipe[i]->cookAbility.boil > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    // 第2轮
    // 条件：酸：本道料理饱腹度-4
    for (int i = 12; i < 15; i++) {
        if (s.recipe[i]->flavor.sour) {
            // 效果：酸：本道料理饱腹度-4
            lenientRule[i]->addRule.full += -4;
            break;
        }
    }
    // 条件：苦：下道料理为辣时售价+100%
    for (int i = 12; i < 15; i++) {
        if (s.recipe[i]->rarity==5) {
            // 效果：苦：下道料理为辣时售价+100%
            lenientRule[i]->addRule.buff += 50;
            break;
        }
    }
    // 条件：甜：本道料理售价+100%
    for (int i = 12; i < 15; i++) {
        if (s.recipe[i]->rarity==5) {
            // 效果：甜：本道料理售价+100%
            lenientRule[i]->oneMore();
            break;
        }
    }
    // 条件：酸：本道料理饱腹感-5
    for (int i = 12; i < 14; i++) {
        if (s.recipe[i]->rarity==4) {
            // 效果：甜：本道料理售价+100%
            lenientRule[i+1]->oneMore();
            break;
        }
    }
    // 第3轮
    // 条件：4火：本道料理饱腹感-4
    for (int i = 15; i < 18; i++) {
        if (s.recipe[i]->rarity == 1) {
            // 效果：4火：本道料理饱腹感-4
            lenientRule[i]->baseRule.buff += 50;
            break;
        }
    }
    // 条件：3火：本道料理售价+100%
    for (int i = 15; i < 18; i++) {
        if (s.recipe[i]->cookAbility.knife>0) {
            // 效果：3火：本道料理售价+100%
            lenientRule[i]->addRule.full += -3;
            break;
        }
    }
    // 条件：2火：本道料理基础售价+50%
    for (int i = 15; i < 18; i++) {
        if (s.recipe[i]->cookAbility.boil>0) {
            // 效果：2火：本道料理基础售价+50%
            lenientRule[i]->addRule.buff += -150;
            break;
        }
    }
    // 条件：1火：本道料理基础售价+1000
    for (int i = 15; i < 18; i++) {
        if (s.recipe[i]->cookAbility.steam>0) {
            // 效果：2火：本道料理基础售价+50%
            lenientRule[i]->addRule.buff += -150;
            break;
        }
    }
    return 19;
}

int banquetRule2(BanquetRule *const &rule, States &s) {
    BanquetStrictRule
        *strictRule[NUM_CHEFS *
                    DISH_PER_CHEF]; // 下一阶段的规则，不受意图生效次数的影响
    BanquetLenientRule *lenientRule[NUM_CHEFS * DISH_PER_CHEF];
    for (int i = 0; i < NUM_CHEFS * DISH_PER_CHEF; i++) {
        strictRule[i] = &rule[i].strictRule;
        lenientRule[i] = &rule[i].lenientRule;
    }
    
    // 第1轮
    // 条件：三道切：下阶段切技法料理售价+100%
    if (s.recipe[0]->cookAbility.knife > 0 &&
        s.recipe[1]->cookAbility.knife > 0 &&
        s.recipe[2]->cookAbility.knife > 0) {
        for (int i = 3; i < 6; i++) {
            if (s.recipe[i]->cookAbility.knife > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (s.recipe[i]->flavor.bitter) {
            // 效果：苦：本道料理售价+100%
            lenientRule[i]->addRule.buff += 100;
            break;
        }
    }
    // 条件：三道蒸：下阶段蒸技法料理售价+100%
    if (s.recipe[0]->cookAbility.steam > 0 && s.recipe[1]->cookAbility.steam > 0 &&
        s.recipe[2]->cookAbility.steam > 0) {
        // 效果：三道炸：下阶段蒸技法料理售价+100%
        for (int i = 3; i < 6; i++) {
            if (s.recipe[i]->cookAbility.steam > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    // 条件：三道煮：下阶段煮技法料理售价+100%
    if (s.recipe[0]->cookAbility.boil > 0 &&
        s.recipe[1]->cookAbility.boil > 0 &&
        s.recipe[2]->cookAbility.boil > 0) {
        // 效果：三道烤：下阶段煮技法料理售价+100%
        for (int i = 3; i < 6; i++) {
            if (s.recipe[i]->cookAbility.boil > 0) {
                strictRule[i]->addRule.buff += 100;
            }
        }
    }
    // 第2轮
    // 条件：甜：本道料理饱腹度+3
    for (int i = 3; i < 6; i++) {
        if (s.recipe[i]->flavor.sweet) {
            lenientRule[i]->addRule.full += 3;
            break;
        }
    }
    // 条件：苦：本道料理基础售价+50%
    for (int i = 3; i < 6; i++) {
        if (s.recipe[i]->flavor.bitter) {
            lenientRule[i]->baseRule.buff += 50;
            break;
        }
    }
    // 条件：5火：本道料理售价-100%
    for (int i = 3; i < 6; i++) {
        if (s.recipe[i]->rarity==5) {
            lenientRule[i]->addRule.buff += -100;
            break;
        }
    }
    // 条件：第三道菜：基础售价+200
    lenientRule[5]->baseRule.directAdd += 200;
    // 第3轮
    // 条件：3火：本道料理饱腹感+2
    for (int i = 6; i < 9; i++) {
        if (s.recipe[i]->rarity == 3) {
            lenientRule[i]->addRule.full += 2;
            break;
        }
    }
    // 条件：苦：本道料理售价+100%
    for (int i = 6; i < 9; i++) {
        if (s.recipe[i]->flavor.bitter) {
            // 效果：3火：本道料理售价+100%
            lenientRule[i]->addRule.buff += 100;
            break;
        }
    }
    // 条件：第二道菜：意图+1
    lenientRule[7]->oneMore();
    // 条件：炒：本道料理基础售价+50%
    for (int i = 6; i < 9; i++) {
        if (s.recipe[i]->cookAbility.stirfry) {
            lenientRule[i]->baseRule.buff += 50;
            break;
        }
    }
    return 32;
}

#endif
