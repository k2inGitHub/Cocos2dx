//
//  KTPopLayer.cpp
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#include "KTPopLayer.h"

bool KTPopLayer::init()
{
    if (!KTPauseLayer::init()) {
        return false;
    }
    
    m_pMenu = CCMenu::create();
    m_pMenu->setTouchPriority(kKTPauseLayerHandlerPriority - 1);
    m_pMenu->setPosition(CCPointZero);
    CC_SAFE_RETAIN(m_pMenu);
    
    m_pLayer = CCLayer::create();
    CC_SAFE_RETAIN(m_pLayer);
    
    return true;
}

KTPopLayer::KTPopLayer()
{

}

KTPopLayer::~KTPopLayer()
{
    CC_SAFE_RELEASE(m_pMenu);
    CC_SAFE_RELEASE(m_pLayer);
}

void KTPopLayer::popIn()
{
    CCScaleTo *ac1 = CCScaleTo::create(0, 0);
    CCScaleTo *ac2 = CCScaleTo::create(0.5, 1);
    CCCallFuncN *ac3 = CCCallFuncN::create(this, callfuncN_selector(KTPopLayer::popInDidFinished));
    runAction(CCSequence::create(ac1, ac2, ac3, NULL));
}

void KTPopLayer::popInDidFinished()
{

}

void KTPopLayer::popOut()
{
    CCScaleTo *ac1 = CCScaleTo::create(0.5, 0);
    CCCallFuncN *ac2 = CCCallFuncN::create(this, callfuncN_selector(KTPopLayer::popOutDidFinished));
    runAction(CCSequence::create(ac1, ac2, NULL));
}

void KTPopLayer::popOutDidFinished()
{
    removeFromParentAndCleanup(true);
}


void KTPopLayer::doCancel()
{
    m_pDelegate->pauseLayerDidCancel(this);
    popOut();
}

void KTPopLayer::doMakeSure()
{
    m_pDelegate->pauseLayerDidMakeSure(this);
    popOut();
}

void KTPopLayer::doRestart()
{
    m_pDelegate->pauseLayerDidRestart(this);
    popOut();
}
void KTPopLayer::doResume()
{
    m_pDelegate->pauseLayerDidResume(this);
    popOut();
}
void KTPopLayer::doQuit()
{
    m_pDelegate->pauseLayerDidQuit(this);
    popOut();
}

void KTPopLayer::onEnter()
{
    KTPauseLayer::onEnter();
    addChild(m_pMenu, 1);
    addChild(m_pLayer, 0);
    popIn();
}

void KTPopLayer::onExit()
{
    KTPauseLayer::onExit();
}