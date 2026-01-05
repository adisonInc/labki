
#pragma once
#ifndef LABKI_ORGANIZM_H
#define LABKI_ORGANIZM_H

class Swiat;

class Organizm {
    protected:
        int sila;
        int inicjatywa;
        int polozenie;

        Swiat* world;


    public:
        Organizm();
        virtual ~Organizm();
        virtual void akcja() = 0;
        virtual void kolizja() = 0;
        virtual void rysowanie() = 0;

};


#endif //LABKI_ORGANIZM_H