//
//  SoundManager.h
//  Noah360univarsal
//
//  Created by Neil D on 17/09/13.

#ifndef __Noah360univarsal__SoundManager__
#define __Noah360univarsal__SoundManager__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class SoundManager
{
    private:
        //Constructor
        SoundManager();
        //Instance of the singleton
        static SoundManager* m_mySingleton;
        //sound narrator id to check status if it's playing...
        unsigned int sound_narrator_id;
        unsigned int sound_instractunalnoah_id;
        unsigned int sound_background_id;
        unsigned int soundFX;
    public:
        //Get instance of singleton
        static SoundManager* sharedSoundManager();

        void unLoadSoundEffect(int scene);
        void loadSondEffect(int scene);

        void stopAllEffect();
        //play effect
        unsigned int playSoundEffect(const char* filename,bool islooping);
        void stopSoundEffect(unsigned int stop_sound);
        bool isEffectPlaying( unsigned int stop_sound);

        void setEffectVolume(float volume);
        float getEffectVolume();
    
        //narrator sound play
         void startNarrator();
         void stopNarrator();
         bool isNarratorPlaying();

    
        //InstractunalNoah sound play
        CC_SYNTHESIZE_RETAIN(CCArray*, arr_instractunalNoah, arr_instractunalNoah);
        unsigned int startInstractunalNoah(CCString *name);
        void stopInstractunalNoah();
        bool isInstractunalNoahplaying();
    
        //back ground music..
        void set_Backgound_MusicVolume(float volume);
        float get_Backgrond_MusicVolume();
        bool is_backgroundMusicPlaying();
        void startBackgroundSound();
        void stopBackgroundSound();
};
#endif /* defined(__Noah360univarsal__SoundManager__) */
