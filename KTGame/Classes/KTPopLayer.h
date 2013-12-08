//
//  KTPopLayer.h
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#ifndef __KTGame__KTPopLayer__
#define __KTGame__KTPopLayer__

#include "KTPauseLayer.h"

//
// KTPopLayer
//
/**
@brief KTPopLayer是KTPauseLayer的子类，实现了暂停Layer的弹出显示和弹出消失，使用时需要继承再实现，将CCsprite加入m_pLayer，将CCMenuItem加入m_pMenu
 */
class KTPopLayer : public KTPauseLayer {
    
public:
    CREATE_FUNC(KTPopLayer);
protected:
    CCMenu *m_pMenu;
    CCLayer *m_pLayer;
    
    void popIn();
    void popOut();
    
    void popInDidFinished();
    void popOutDidFinished();
    
    virtual void doMakeSure();
    virtual void doCancel();
    virtual void doRestart();
    virtual void doResume();
    virtual void doQuit();
    
    virtual void onEnter();
    virtual void onExit();
    bool init();
    
    KTPopLayer();
    ~KTPopLayer();
    
};

#endif /* defined(__KTGame__KTPopLayer__) */
