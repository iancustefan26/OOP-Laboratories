/*
Profesorul X a decis sa faca mai multe fetite PowerPuff, si evident are nevoie de sugar/spice and everything nice
    Pt ca ii este lene, da o comanda cu Glovo si ii spune curieruui sa i aduca tot zaharul/condimentele/fainutzul din magazin
    Implementati clasa abstracta PowerPuffGirl si clasele care mostenesc interfata : Bubbles, Blossom, Buttercup

    Fiecare dintre fetite are
    Damage, health

    clasa Profesor care primeste o lista de ingrediente care a reusit curierul sa le cumpere
    ex: sugar, spice, spice, everything_nice, sugar

    Ca sa creeze o fetita powerpuff are nevoie de
    1x sugar
    1x spice
    1x everything_nice

    O sa creeze cat de multe fetite poate
    cu o sansa de 33% sa fie ori un ButterCup, ori un Blossom, ori un Bubbles

    clasa MojoJojo
    care are
    damage, health

    Si apoi implementati o metoda globala care simuleaza lupta intre MojoJojo si fetitele powerpuff ale profesorului

    Daunele se efectueaza in ture
    In fiecare tura fetitele dau damage lui MojoJojo
    si MojoJojo alege o fetita aleatoare care sa o dauneze

    Scrieti o metoda care afiseaza castigatorul bataliei
    Si o metoda care sa afiseze cate fetite au supravietuit si cu cata viata
*/
#include "MojoJojo.h"
#include "ProfessorX.h"
#pragma warning(disable : 4996)

class Battle {
    char* winner;
    MojoJojo* mojojojo;
    ProffesorX* proffesor_x;
public:
    Battle(ProffesorX* a, MojoJojo* b) {
        mojojojo = b;
        proffesor_x = a;
    }
    void Start() {
        int number_of_grils = proffesor_x->powerpuffs_still_alive();
        while (mojojojo->getHealth() > 0 || proffesor_x->powerpuffs_still_alive() > 0) {
            for(int i = 0; i < number_of_grils; ++i)
                if (proffesor_x->powerpuff_still_alive(i)) {
                    mojojojo->dealDamage(proffesor_x->getDamage(i));
                    proffesor_x->dealDamage(i, mojojojo->getDamage());
                    if (!proffesor_x->powerpuff_still_alive(i))
                        proffesor_x->killPowerPuff(i);
                }
            }
        if (proffesor_x->powerpuffs_still_alive()) {
            winner = new char[15];
            strcpy(winner, "PowerPuffs");
            return;
        }
        else {
            winner = new char[15];
            strcpy(winner, "MojoJojo");
            return;
        }
    }
    void ShowWinner() {
        std::cout << winner << "\n";
    }
    ~Battle() {
        delete[] winner;
    }
};

int main() {
    MojoJojo cel_rau;
    const char* glovo[] = { "spice", "sugar", "everything_nice", "sugar",
                            "sugar", "everything_nice", "sugar", "spice",
                             "spice", "everything_nice", "everything_nice",
                              "spice", "sugar" };
    ProffesorX cel_bun(glovo, 14);
    Battle bataia(&cel_bun, &cel_rau);
    bataia.Start();
    bataia.ShowWinner();
    return 0;
}