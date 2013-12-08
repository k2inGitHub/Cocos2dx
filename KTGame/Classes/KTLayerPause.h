//
//  KTPauseLayer.h
//  colorful
//
//  Created by SongYang on 13-10-29.
//
//

/*
    暂停Layer基类
 */

#ifndef colorful_KTLayerPause_h
#define colorful_KTLayerPause_h

#include "cocos2d.h"
USING_NS_CC;
//#include "KTSceneBase.h"
//#include "KTStaticData.h"
//#include "SimpleAudioEngine.h"
//using namespace CocosDenshion;
//using namespace CocosDenshion;

class KTLayerPause;

class KTLayerPauseDelegate {
    
public:
    //恢复游戏
    virtual void didRecieveResumeEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
    //重新开始游戏
    virtual void didRecieveRestartEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
    //退出
    virtual void didRecieveQuitEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
    //进行下一局游戏
    virtual void didRecieveNextGameEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
    //取消
    virtual void didRecieveCancelEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
    //确定
    virtual void didRecieveMakeSureEvent(KTLayerPause *layer){CC_UNUSED_PARAM(layer);};
};

class KTLayerPause : public CCLayer, public KTLayerPauseDelegate {
    
public:
    CCSize winSize;
    CC_SYNTHESIZE(KTLayerPauseDelegate*, m_delegate, KTLayerPauseDelegate);

    virtual void doMakeSure();
    virtual void doCancel();
    virtual void doRestart();
    virtual void doResume();
    virtual void doQuit();
    virtual void doNextGame();
    virtual void onExit();
    virtual void onEnter();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual bool init();
    CREATE_FUNC(KTLayerPause);
    KTLayerPause();
    ~KTLayerPause();
};


#endif
