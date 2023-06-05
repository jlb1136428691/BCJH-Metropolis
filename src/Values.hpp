#ifndef VALUE_HPP
#define VALUE_HPP
#include "include/json/json.h"
#include <iostream>
class MaterialCategoryBuff {
  public:
    int vegetable;
    int meat;
    int fish;
    int creation;
    MaterialCategoryBuff() : vegetable(0), meat(0), fish(0), creation(0) {}
    void add(const MaterialCategoryBuff &m) {
        this->vegetable += m.vegetable;
        this->meat += m.meat;
        this->fish += m.fish;
        this->creation += m.creation;
    }
    void print() {
        std::cout << "MaterialCategoryBuff: Vegetable: " << this->vegetable
                  << "; Meat: " << this->meat << "; Fish: " << this->fish
                  << "; Creation: " << this->creation << std::endl;
    }
};
class FlavorBuff {
  public:
    int sweet;
    int salty;
    int sour;
    int bitter;
    int spicy;
    int tasty;
    FlavorBuff() : sweet(0), salty(0), sour(0), bitter(0), spicy(0), tasty(0) {}
    void add(const FlavorBuff &f) {
        this->sweet += f.sweet;
        this->salty += f.salty;
        this->sour += f.sour;
        this->bitter += f.bitter;
        this->spicy += f.spicy;
        this->tasty += f.tasty;
    }
    void print() {
        std::cout << "FlavorBuff: Sweet: " << this->sweet
                  << "; Salty: " << this->salty << "; Sour: " << this->sour
                  << "; Bitter: " << this->bitter << "; Spicy: " << this->spicy
                  << "; Tasty: " << this->tasty << std::endl;
    }
};
class Ability {
  public:
    int stirfry;
    int bake;
    int boil;
    int steam;
    int fry;
    int knife;
    Ability() : stirfry(0), bake(0), boil(0), steam(0), fry(0), knife(0) {}
    Ability(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : stirfry(stirfry), bake(bake), boil(boil), steam(steam), fry(fry),
          knife(knife) {}

    void add(const Ability &a) {
        this->stirfry += a.stirfry;
        this->bake += a.bake;
        this->boil += a.boil;
        this->steam += a.steam;
        this->fry += a.fry;
        this->knife += a.knife;
    }
    void add(int a) {
        this->stirfry += a;
        this->bake += a;
        this->boil += a;
        this->steam += a;
        this->fry += a;
        this->knife += a;
    }
    void print(std::string title) {
        std::cout << title << "Stirfry: " << this->stirfry
                  << "; Boil: " << this->boil << "; Knife: " << this->knife
                  << "; Fry: " << this->fry << "; Bake: " << this->bake
                  << "; Steam: " << this->steam << std::endl;
    }
};

class AbilityBuff : public Ability {
  public:
    AbilityBuff() {}
    AbilityBuff(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : Ability(stirfry, bake, boil, steam, fry, knife) {}
    void print() { this->Ability::print("AbilityBuff: "); }
};
class CookAbility : public Ability {

  public:
    CookAbility(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : Ability(stirfry, bake, boil, steam, fry, knife) {}
    CookAbility() : Ability() {}
    CookAbility(Json::Value &v);
    int operator/(const Ability &a);
    void print() { this->Ability::print("CookAbility: "); }
    int operator*(const AbilityBuff &a);
};
class RarityBuff {
  public:
    int dishNum;
    int dishBuff;

    RarityBuff() : dishNum(0), dishBuff(0) {}
    RarityBuff(int dishNum, int dishBuff)
        : dishNum(dishNum), dishBuff(dishBuff) {}
    void add(const RarityBuff &r) {
        this->dishNum += r.dishNum;
        this->dishBuff += r.dishBuff;
    }
    void print() {
        std::cout << "RarityBuff: DishNum: " << this->dishBuff
                  << "; DishBuff: " << this->dishBuff << std::endl;
    }
};
// 技法光环
class SkillHalo : public Ability {
  public:
    SkillHalo(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : Ability(stirfry, bake, boil, steam, fry, knife) {}
    SkillHalo() : Ability() {}
    void print() { this->Ability::print("SkillHalo: "); }
};
// 售价光环
class BuffHalo : public Ability {
  public:
    BuffHalo(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : Ability(stirfry, bake, boil, steam, fry, knife) {}
    BuffHalo() : Ability() {}
    void print() { this->Ability::print("BuffHalo: "); }
};
// 下一个技法+X
class SkillNext : public Ability {
  public:
    SkillNext(int stirfry, int bake, int boil, int steam, int fry, int knife)
        : Ability(stirfry, bake, boil, steam, fry, knife) {}
    SkillNext() : Ability() {}
    void print() { this->Ability::print("SkillNext: "); }
};
class Skill {
  private:
  public:
    static std::map<int, Skill> skillList;
    CookAbility ability;
    AbilityBuff abilityBuff;
    FlavorBuff flavorBuff;
    MaterialCategoryBuff materialBuff;
    int coinBuff;
    RarityBuff rarityBuff;
    bool halo;
    SkillHalo skillHalo;
    BuffHalo buffHalo;
    bool next;
    SkillNext skillNext;

    Skill(CookAbility ability, AbilityBuff abilityBuff, FlavorBuff flavorBuff,
          MaterialCategoryBuff materialBuff, int coinBuff,
          RarityBuff(rarityBuff), bool halo, SkillHalo(skillHalo),
          BuffHalo(buffHalo),bool next, SkillNext(skillNext))
        : ability(ability), abilityBuff(abilityBuff), flavorBuff(flavorBuff),
          materialBuff(materialBuff), coinBuff(coinBuff),
          rarityBuff(rarityBuff), halo(halo), skillHalo(skillHalo),
          buffHalo(buffHalo),next(next), skillNext(skillNext) {}
    Skill() {
        this->ability = CookAbility();
        this->abilityBuff = AbilityBuff();
        this->flavorBuff = FlavorBuff();
        this->materialBuff = MaterialCategoryBuff();
        this->coinBuff = 0;
        this->rarityBuff = RarityBuff();
        this->halo = false;
        this->skillHalo = SkillHalo();
        this->buffHalo = BuffHalo();
        this->next = false;
        this->skillNext = SkillNext();
    }
    Skill getSkill(int id) { return skillList[id]; }
    static void loadJson(Json::Value &v);
    void add(const Skill &s) {
        this->ability.add(s.ability);
        this->abilityBuff.add(s.abilityBuff);
        this->flavorBuff.add(s.flavorBuff);
        this->materialBuff.add(s.materialBuff);
        this->coinBuff += s.coinBuff;
        this->rarityBuff.add(s.rarityBuff);
        this->halo = s.halo;
        this->skillHalo.add(s.skillHalo);
        this->buffHalo.add(s.buffHalo);
        this->next = s.next;
        this->skillNext.add(s.skillNext);
    }
    void print() {
        this->ability.print();
        this->abilityBuff.print();
        this->flavorBuff.print();
        this->materialBuff.print();
        std::cout << "CoinBuff: " << this->coinBuff << std::endl;
        this->rarityBuff.print();
        std::cout << "Halo: " << this->halo << std::endl;
        this->skillHalo.print();
        this->buffHalo.print();
        std::cout << "Next: " << this->next << std::endl;
        this->skillNext.print();
    }
};
enum AbilityEnum {
    NO_TOOL = -2,
    NOT_EQUIPPED = -1,
    STIRFRY,
    BAKE,
    BOIL,
    STEAM,
    FRY,
    KNIFE
};

#endif