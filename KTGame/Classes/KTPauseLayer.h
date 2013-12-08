//
//  KTPauseLayer.h
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#ifndef __KTGame__KTPauseLayer__
#define __KTGame__KTPauseLayer__

#include "cocos2d.h"
USING_NS_CC;

class KTPauseLayer;

class KTPauseLayerDelegate {
    
public:
    //恢复游戏
    virtual void pauseLayerDidResume(KTPauseLayer *layer){CC_UNUSED_PARAM(layer);};
    //重新开始游戏
    virtual void pauseLayerDidRestart(KTPauseLayer *layer){CC_UNUSED_PARAM(layer);};
    //退出
    virtual void pauseLayerDidQuit(KTPauseLayer *layer){CC_UNUSED_PARAM(layer);};
    //取消
    virtual void pauseLayerDidCancel(KTPauseLayer *layer){CC_UNUSED_PARAM(layer);};
    //确定
    virtual void pauseLayerDidMakeSure(KTPauseLayer *layer){CC_UNUSED_PARAM(layer);};
};

enum{
    //KTPauseLayer触摸优先级
    kKTPauseLayerHandlerPriority  = kCCMenuHandlerPriority - 1,
};

//
// KTPauseLayer
//
/** 
 @brief KTPauseLayer是CCLayer的子类，实现KTPauseLayerDelegate协议，弹出Layer的基类，可以覆盖CCMenu，可以创建使用，也可以继承使用
 */
class KTPauseLayer : public CCLayer, public KTPauseLayerDelegate {
    
public:
    CC_SYNTHESIZE(KTPauseLayerDelegate*, m_pDelegate, Delegate);
    CREATE_FUNC(KTPauseLayer);
    
protected:
    
    //pauseLayer
    virtual void doMakeSure();
    virtual void doCancel();
    virtual void doRestart();
    virtual void doResume();
    virtual void doQuit();
    
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher(void);
    virtual bool init();
    
    KTPauseLayer();
    ~KTPauseLayer();
};



#endif /* defined(__KTGame__KTPauseLayer__) */
