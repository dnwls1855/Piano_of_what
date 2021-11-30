#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <stdio.h>
using namespace bangtal;

ScenePtr Piano_start;
ScenePtr Piano_gamerule;
ObjectPtr piano_text1;
ObjectPtr piano_text2;
ObjectPtr piano_text3;
ObjectPtr piano_text4;
ObjectPtr piano_text5;
ObjectPtr piano_text6;
ObjectPtr piano_text7;
ObjectPtr piano_text8;
ObjectPtr piano_gamerule;
ObjectPtr next_button1;
ObjectPtr next_button2;
ObjectPtr next_button3;
ObjectPtr next_button4;

ScenePtr Piano_Play1;
ScenePtr Piano_Play2;
ScenePtr Piano_Play3;

ObjectPtr Dot1;
ObjectPtr Dot2;
ObjectPtr Dot3;

int piano_text_index;
int key_press[25];
int key_index;

int Rudolf_Notes[14] = { 4, 5, 4, 2, 7, 5, 4, 4, 5, 4, 5, 4, 7, 6 };
int Lookoutthewindow_Notes[16] = { 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 2, 4, 7, 6 };
int Jinglebell_Notes[25] = { 2, 2, 2, 2, 2, 2, 2, 4, 0, 1, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 1, 4 };
SoundPtr Note[8];
char path[20];
int key;

void Piano_first() {
    

    piano_text2->hide();
    piano_text3->hide();
    piano_text4->hide();
    piano_text5->hide();
    piano_text6->hide();
    piano_text7->hide();
    piano_text8->hide();

    next_button2->hide();
    next_button3->hide();
    next_button4->hide();

    next_button1->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text1->hide();
            piano_text2->show();
            piano_text_index++;
        }
        else if (piano_text_index == 1) {
            Piano_Play1->enter();
            piano_text_index = 0;
        }
        return true;
        });

    next_button2->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text3->hide();
            piano_text4->show();
            piano_text_index++;
        }
      
        else if (piano_text_index == 1) {
            Piano_Play2->enter();
            piano_text_index = 0;
        }
        return true;
        });

    next_button3->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text5->hide();
            piano_text6->show();
            piano_text_index++;
        }

        else if (piano_text_index == 1) {
            Piano_Play3->enter();
            piano_text_index = 0;
        }
        return true;
        });

    next_button4->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text7->hide();
            piano_text8->show();
            piano_text_index++;
        }

        else if (piano_text_index == 1) {
            endGame();
        }
        return true;
        });

    piano_gamerule->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        Piano_Play1->enter();
        return true;
        });








    Piano_Play1->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        key = 0;
        if (pressed == true) {
        switch (code) {
        case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot1->locate(Piano_Play1, 80, 20); break;
        case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot1->locate(Piano_Play1, 238, 20); break;
        case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot1->locate(Piano_Play1, 396, 20); break;
        case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot1->locate(Piano_Play1, 554, 20); break;
        case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot1->locate(Piano_Play1, 712, 20); break;
        case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot1->locate(Piano_Play1, 870, 20); break;
        case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot1->locate(Piano_Play1, 1028, 20); break;
        case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot1->locate(Piano_Play1, 1186, 20); break;
        }
        key_press[key_index] = key;

 
        if (key_press[key_index] == Rudolf_Notes[key_index]) key_index++;
         else key_index = 0;

        if (key_index == 14) {
            piano_text3->show();
            next_button2->show();
     
            }
        
         };
        return true;
        });

    Piano_Play2->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        key = 0;
        if (pressed == true) {
        switch (code) {
        case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot2->locate(Piano_Play2, 80, 20); break;
        case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot2->locate(Piano_Play2, 238, 20); break;
        case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot2->locate(Piano_Play2, 396, 20); break;
        case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot2->locate(Piano_Play2, 554, 20); break;
        case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot2->locate(Piano_Play2, 712, 20); break;
        case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot2->locate(Piano_Play2, 870, 20); break;
        case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot2->locate(Piano_Play2, 1028, 20); break;
        case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot2->locate(Piano_Play2, 1186, 20); break;
        }
        key_press[key_index] = key;

        if (key_press[key_index] == Lookoutthewindow_Notes[key_index]) key_index++;
        else key_index = 0;

        if (key_index == 16) {
             piano_text5->show();
             next_button3->show();

             }

        };
        return true;
        });

    Piano_Play3->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        key = 0;
        if (pressed == true) {
            switch (code) {
            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot3->locate(Piano_Play3, 80, 20); break;
            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot3->locate(Piano_Play3, 238, 20); break;
            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot3->locate(Piano_Play3, 396, 20); break;
            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot3->locate(Piano_Play3, 554, 20); break;
            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot3->locate(Piano_Play3, 712, 20); break;
            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot3->locate(Piano_Play3, 870, 20); break;
            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot3->locate(Piano_Play3, 1028, 20); break;
            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot3->locate(Piano_Play3, 1186, 20); break;
            }
            key_press[key_index] = key;

         

         if (key_press[key_index] == Jinglebell_Notes[key_index]) key_index++;
         else key_index = 0;

         if (key_index == 25) {
             piano_text7->show();
             next_button4->show();


         }
         


        };
        return true;
        });

   
}

void piano_init() {
    Piano_start = Scene::create("피아노", "Images/Piano_start.png");
    Piano_gamerule = Scene::create("피아노", "Images/피아노게임.jpg");

    piano_text1 = Object::create("Images/piano_text1.png", Piano_start, 0, 0);
    piano_text2 = Object::create("Images/piano_text2.png", Piano_start, 0, 0);
    piano_text3 = Object::create("Images/piano_text3.png", Piano_Play1, 0, 0);
    piano_text4 = Object::create("Images/piano_text4.png", Piano_Play1, 0, 0);
    piano_text5 = Object::create("Images/piano_text5.png", Piano_Play2, 0, 0);
    piano_text6 = Object::create("Images/piano_text6.png", Piano_Play2, 0, 0);
    piano_text7 = Object::create("Images/piano_text7.png", Piano_Play3, 0, 0);
    piano_text8 = Object::create("Images/piano_text8.png", Piano_Play3, 0, 0);
    piano_gamerule = Object::create("Images/piano_gamerule.png", Piano_gamerule, 0, 0);
    next_button1 = Object::create("Images/next_button.png", Piano_start, 920, 40);
    next_button2 = Object::create("Images/next_button.png", Piano_Play1, 920, 40);
    next_button3 = Object::create("Images/next_button.png", Piano_Play2, 920, 40);
    next_button4 = Object::create("Images/next_button.png", Piano_Play3, 920, 40);

    piano_text_index = 0;
    Piano_Play1 = Scene::create("피아노", "Images/루돌프사슴코악보.png");
    Piano_Play2 = Scene::create("피아노", "Images/창밖을보라악보.png");
    Piano_Play3 = Scene::create("피아노", "Images/징글벨악보.png");

    Dot1 = Object::create("Images/점.png", Piano_Play1, -100, 20);
    Dot2 = Object::create("Images/점.png", Piano_Play2, -100, 20);
    Dot3 = Object::create("Images/점.png", Piano_Play3, -100, 20);


    key_press[30] = { 0 };
    key_index = 0;

    

    key = 0;

    for (int i = 0; i < 8; i++)
    {
        sprintf(path, "Sounds/%d.mp3", i + 1);
        Note[i] = Sound::create(path);
    }

    Piano_first();
}

int main() {

    piano_init();

    startGame(Piano_start);

    return 0;
}