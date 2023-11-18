#pragma once
enum EffectType
{
    EFFECT_PARTICLE = 0,
    EFFECT_TRAIL = 1,
    EFFECT_REANIM = 2,
    EFFECT_ATTACHMENT = 3,
    EFFECT_OTHER = 4
};
enum AttachmentID { ATTACHMENTID_NULL };
enum ParticleID { PARTICLEID_NULL };
enum ParticleEmitterID { PARTICLEEMITTERID_NULL };
enum ParticleSystemID { PARTICLESYSTEMID_NULL };
enum ReanimationID { REANIMATIONID_NULL };
enum ReanimLoopType
{
    REANIM_LOOP = 0,
    REANIM_LOOP_FULL_LAST_FRAME = 1,
    REANIM_PLAY_ONCE = 2,
    REANIM_PLAY_ONCE_AND_HOLD = 3,
    REANIM_PLAY_ONCE_FULL_LAST_FRAME = 4,
    REANIM_PLAY_ONCE_FULL_LAST_FRAME_AND_HOLD = 5
};
enum EmitterType
{
    EMITTER_CIRCLE = 0,
    EMITTER_BOX = 1,
    EMITTER_BOX_PATH = 2,
    EMITTER_CIRCLE_PATH = 3,
    EMITTER_CIRCLE_EVEN_SPACING = 4
};
enum TodCurves
{
    CURVE_CONSTANT,          
    CURVE_LINEAR,              
    CURVE_EASE_IN,             
    CURVE_EASE_OUT,           
    CURVE_EASE_IN_OUT,         
    CURVE_EASE_IN_OUT_WEAK,     
    CURVE_FAST_IN_OUT,          
    CURVE_FAST_IN_OUT_WEAK,    
    CURVE_WEAK_FAST_IN_OUT,    
    CURVE_BOUNCE,             
    CURVE_BOUNCE_FAST_MIDDLE,   
    CURVE_BOUNCE_SLOW_MIDDLE,   
    CURVE_SIN_WAVE,             
    CURVE_EASE_SIN_WAVE         
};
enum DrawStringJustification
{
    DS_ALIGN_LEFT = 0,
    DS_ALIGN_RIGHT = 1,
    DS_ALIGN_CENTER = 2,
    DS_ALIGN_LEFT_VERTICAL_MIDDLE = 3,
    DS_ALIGN_RIGHT_VERTICAL_MIDDLE = 4,
    DS_ALIGN_CENTER_VERTICAL_MIDDLE = 5
};
//If u want your own reanim types, just include them before including this
#ifndef BOARD_WIDTH
#define BOARD_WIDTH 800
#endif
#ifndef BOARD_HEIGHT
#define BOARD_HEIGHT 800
#endif
#ifndef REANIMATIONTYPE
#define REANIMATIONTYPE
enum ReanimationType
{
    REANIM_NONE = -1,
    NUM_REANIMS=1,
};
#endif
//same for this thing
#ifndef PARTICLEFFECT
#define PARTICLEFFECT
enum ParticleEffect
{
    PARTICLE_NONE = -1,
    NUM_PARTICLES=1,
};
#endif
#ifndef FOLEYTYPE
#define FOLEYTYPE
enum FoleyType
{
    FOLEY_NONE=-1,
    NUM_FOLEY
};
#endif