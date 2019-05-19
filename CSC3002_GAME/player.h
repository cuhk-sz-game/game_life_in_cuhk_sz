#ifndef PLAYER_H
#define PLAYER_H

#include "role.h"
#include <QString>

class Player : public Role {
public:
    Player() {}
    ~Player() {}
    int GetGrade() { return grade; }
    int GetPosx() { return posx; }
    int GetPosy() { return posy; }
    int GetPlace() {return place; }
    int GetToward() {return toward; }
    int GetSex() {return sex; }
    int GetNeed() {return need; }
    int GetLover1(){return lover_pos1;}
    int GetLover2(){return lover_pos2;}
    int GetLover3(){return lover_pos3;}

    void SetGrade(int grade) { this->grade = grade; }
    void SetLoverpose1(int lover_pos1) {this->lover_pos1=lover_pos1;}
    void SetLoverpose2(int lover_pos2) {this->lover_pos2=lover_pos2;}
    void SetLoverpose3(int lover_pos3) {this->lover_pos3=lover_pos3;}
    void SetPosx(int posx) { this->posx = posx; }
    void SetPosy(int posy) { this->posy = posy; }
    void SetPlace(int place) { this->place = place; }
    void SetToward(int toward) { this->toward = toward; }
    void SetSex(int sex) { this->sex = sex; }
    void SetNeed(int need) { this->need = need; }
    void ChooseSex(int sex);
    void GradeUp();

private:
    int lover_pos1;
    int lover_pos2;
    int lover_pos3;
    int grade;
    int posx;
    int posy;
    int place;
    int toward;
    int sex;
    int need;
};

#endif // PLAYER_H
