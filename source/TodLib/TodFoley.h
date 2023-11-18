#ifndef __TODFOLEY_H__
#define __TODFOLEY_H__

#include "../SexyAppFramework/DSoundInstance.h"
using namespace Sexy;

#define MAX_FOLEY_TYPES 110
#define MAX_FOLEY_INSTANCES 8

// ######################################################################################################################################################
// ############################################################# 以下为拟音音效定义相关内容 #############################################################
// ######################################################################################################################################################

enum FoleyFlags
{
    FOLEYFLAGS_LOOP,                // 循环播放
    FOLEYFLAGS_ONE_AT_A_TIME,       // 禁止叠加播放：指定该种类的音效同时至多存在 1 个实例，重复播放时仅增加引用计数并刷新开始时间
    FOLEYFLAGS_MUTE_ON_PAUSE,       // 暂停时静默
    FOLEYFLAGS_USES_MUSIC_VOLUME,   // 使用音乐音量，指定该种类的音效使用与背景音乐相同的音量
    FOLEYFLAGS_DONT_REPEAT          // 禁止变式重复，指定该种类的音效每次实际播放的变式不得与上一次相同
};



class FoleyParams
{
public:
    FoleyType           mFoleyType;
    float               mPitchRange;
    int*                mSfxID[10];
    unsigned int        mFoleyFlags;
};

/*inline*/ void         TodFoleyInitialize(FoleyParams* theFoleyParamArray, int theFoleyParamArraySize);
/*inline*/ void         TodFoleyDispose();
FoleyParams*            LookupFoley(FoleyType theFoleyType);

extern int gFoleyParamArraySize;        //[0x6A9F04]
extern FoleyParams* gFoleyParamArray;   //[0x6A9F00]

extern FoleyParams gLawnFoleyParamArray[(int)FoleyType::NUM_FOLEY];  //0x69FAD0

// ######################################################################################################################################################
// ############################################################ 以下正式开始拟音音效相关声明 ############################################################
// ######################################################################################################################################################

class TodDSoundInstance : public DSoundInstance
{
    friend class TodFoley;

public:
    TodDSoundInstance(DSoundManager* theSoundManager, LPDIRECTSOUNDBUFFER theSourceSound) : DSoundInstance(theSoundManager, theSourceSound) { }

    /*inline*/ int      GetSoundPosition();
    /*inline*/ void     SetSoundPosition(int thePosition);
};

class FoleyInstance
{
public:
    SoundInstance*      mInstance;
    int                 mRefCount;
    bool                mPaused;
    int                 mStartTime;
    int                 mPauseOffset;

public:
    FoleyInstance();
};

class FoleyTypeData
{
public:
    FoleyInstance       mFoleyInstances[MAX_FOLEY_INSTANCES];
    int                 mLastVariationPlayed;

public:
    FoleyTypeData();
};

class TodFoley
{
public:
    FoleyTypeData	    mFoleyTypeData[MAX_FOLEY_TYPES];

public:
    void                PlayFoley(FoleyType theFoleyType);
    void                StopFoley(FoleyType theFoleyType);
    bool                IsFoleyPlaying(FoleyType theFoleyType);
    void                GamePause(bool theEnteringPause);
    void                PlayFoleyPitch(FoleyType theFoleyType, float thePitch);
    void                CancelPausedFoley();
    /*inline*/ void     ApplyMusicVolume(FoleyInstance* theFoleyInstance);
    void                RehookupSoundWithMusicVolume();
};

void                    SoundSystemReleaseFinishedInstances(TodFoley* theSoundSystem);
bool                    SoundSystemHasFoleyPlayedTooRecently(TodFoley* theSoundSystem, FoleyType theFoleyType);
FoleyInstance*          SoundSystemFindInstance(TodFoley* theSoundSystem, FoleyType theFoleyType);
FoleyInstance*          SoundSystemGetFreeInstanceIndex(TodFoley* theSoundSystem, FoleyType theFoleyType);

#endif
