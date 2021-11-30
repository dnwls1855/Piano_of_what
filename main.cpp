//#define _CRT_SECURE_NO_WARNINGS
//#include <bangtal>
//#include <iostream>
//#include <stdio.h>
//using namespace bangtal;
//
//
//void Piano_init() {
//    int key_press[25] = { 0 };
//    int key_index = 0;
//    int stage = 1;
//    int Rudolf_Notes[14] = { 4, 5, 4, 2, 7, 5, 4, 4, 5, 4, 5, 4, 7, 6 };
//    int Lookoutthewindow_Notes[16] = { 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 2, 4, 7, 6 };
//    int Jinglebell_Notes[25] = { 2, 2, 2, 2, 2, 2, 2, 4, 0, 1, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 1, 4 };
//
//
//    ScenePtr Snoopy_Room = Scene::create("방", "Images/피아노게임.jpg");
//    ScenePtr Piano_Play1 = Scene::create("피아노", "Images/루돌프사슴코악보.png");
//    ScenePtr Piano_Play2 = Scene::create("피아노", "Images/창밖을보라악보.png");
//    ScenePtr Piano_Play3 = Scene::create("피아노", "Images/징글벨악보.png");
//    ObjectPtr Piano = Object::create("Images/스타트게임.png", Snoopy_Room, 500, 200);
//    ObjectPtr Dot1 = Object::create("Images/점.png", Piano_Play1, -100, 20);
//    ObjectPtr Dot2 = Object::create("Images/점.png", Piano_Play2, -100, 20);
//    ObjectPtr Dot3 = Object::create("Images/점.png", Piano_Play3, -100, 20);
//
//    Piano->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
//        if (stage == 1) Piano_Play1->enter();
//        else if (stage == 2) Piano_Play2->enter();
//        else if (stage == 3) Piano_Play3->enter();
//
//        key_index = 0;
//        return true;
//
//        });
//
//    SoundPtr Note[8];
//    char path[20];
//    for (int i = 0; i < 8; i++)
//    {
//        sprintf(path, "Sounds/%d.mp3", i + 1);
//        Note[i] = Sound::create(path);
//    }
//
//    Piano_Play1->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
//        int key = 0;
//        if (pressed == true) {
//            switch (code) {
//            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot1->locate(Piano_Play1, 80, 20); break;
//            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot1->locate(Piano_Play1, 238, 20); break;
//            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot1->locate(Piano_Play1, 396, 20); break;
//            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot1->locate(Piano_Play1, 554, 20); break;
//            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot1->locate(Piano_Play1, 712, 20); break;
//            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot1->locate(Piano_Play1, 870, 20); break;
//            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot1->locate(Piano_Play1, 1028, 20); break;
//            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot1->locate(Piano_Play1, 1186, 20); break;
//            }
//            key_press[key_index] = key;
//
//
//            if (key_press[key_index] == Rudolf_Notes[key_index]) key_index++;
//            else key_index = 0;
//
//            if (key_index == 14) {
//                showMessage("스테이지1클리어");
//                Snoopy_Room->enter();
//                stage++;
//            }
//
//        };
//        return true;
//        });
//
//    Piano_Play2->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
//        int key = 0;
//        if (pressed == true) {
//            switch (code) {
//            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot2->locate(Piano_Play2, 80, 20); break;
//            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot2->locate(Piano_Play2, 238, 20); break;
//            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot2->locate(Piano_Play2, 396, 20); break;
//            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot2->locate(Piano_Play2, 554, 20); break;
//            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot2->locate(Piano_Play2, 712, 20); break;
//            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot2->locate(Piano_Play2, 870, 20); break;
//            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot2->locate(Piano_Play2, 1028, 20); break;
//            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot2->locate(Piano_Play2, 1186, 20); break;
//            }
//            key_press[key_index] = key;
//
//            if (key_press[key_index] == Lookoutthewindow_Notes[key_index]) key_index++;
//            else key_index = 0;
//
//            if (key_index == 16) {
//                showMessage("스테이지2클리어");
//                Snoopy_Room->enter();
//                stage++;
//            }
//
//        };
//        return true;
//        });
//
//    Piano_Play3->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
//        int key = 0;
//        if (pressed == true) {
//            switch (code) {
//            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot3->locate(Piano_Play3, 80, 20); break;
//            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot3->locate(Piano_Play3, 238, 20); break;
//            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot3->locate(Piano_Play3, 396, 20); break;
//            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot3->locate(Piano_Play3, 554, 20); break;
//            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot3->locate(Piano_Play3, 712, 20); break;
//            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot3->locate(Piano_Play3, 870, 20); break;
//            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot3->locate(Piano_Play3, 1028, 20); break;
//            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot3->locate(Piano_Play3, 1186, 20); break;
//            }
//            key_press[key_index] = key;
//
//
//
//            if (key_press[key_index] == Jinglebell_Notes[key_index]) key_index++;
//            else key_index = 0;
//
//            if (key_index == 25) {
//                showMessage("스테이지3클리어");
//                Snoopy_Room->enter();
//
//
//            }
//
//
//
//        };
//        return true;
//        });
//
//    startGame(Snoopy_Room);
//}
//
//int main() {
//
//    Piano_init();
//    return 0;
//}