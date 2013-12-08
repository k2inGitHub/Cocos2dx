//
//  KTPauseLayer.cpp
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#include "KTPauseLayer.h"

bool KTPauseLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    setTouchPriority(kKTPauseLayerHandlerPriority);
    setTouchMode(kCCTouchesOneByOne);
    setTouchEnabled(true);
    
    
    return true;
}

void KTPauseLayer::onEnter()
{
    CCLayer::onEnter();
    
}

void KTPauseLayer::onExit()
{
    
    CCLayer::onExit();
}

bool KTPauseLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    return true;
}

void KTPauseLayer::registerWithTouchDispatcher(void)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, this->getTouchPriority(), true);
    
    
}

void KTPauseLayer::doCancel()
{
    m_pDelegate->pauseLayerDidCancel(this);
    removeFromParentAndCleanup(true);
}

void KTPauseLayer::doMakeSure()
{
    m_pDelegate->pauseLayerDidMakeSure(this);
    removeFromParentAndCleanup(true);
}

void KTPauseLayer::doRestart()
{
    m_pDelegate->pauseLayerDidRestart(this);
    removeFromParentAndCleanup(true);
}
void KTPauseLayer::doResume()
{
    m_pDelegate->pauseLayerDidResume(this);
    removeFromParentAndCleanup(true);
}
void KTPauseLayer::doQuit()
{
    m_pDelegate->pauseLayerDidQuit(this);
    removeFromParentAndCleanup(true);
}

KTPauseLayer::~KTPauseLayer()
{
    m_pDelegate = NULL;
}
KTPauseLayer::KTPauseLayer()
{
    
}
