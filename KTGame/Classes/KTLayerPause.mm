//
//  KTPauseLayer.cpp
//  colorful
//
//  Created by SongYang on 13-10-29.
//
//

#include "KTLayerPause.h"

bool KTLayerPause::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    winSize = CCDirector::sharedDirector()->getWinSize();
    
    
//    CCScaleTo *ac1 = CCScaleTo::create(0, 0);
//    CCScaleTo *ac2 = CCScaleTo::create(1.0, 1);
//    runAction(CCSequence::create(ac1, ac2, NULL));
    return true;
}

bool KTLayerPause::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    return true;
}

void KTLayerPause::doCancel()
{
    m_delegate->didRecieveCancelEvent(this);
}

void KTLayerPause::doMakeSure()
{
    m_delegate->didRecieveMakeSureEvent(this);
}

void KTLayerPause::doNextGame()
{
    m_delegate->didRecieveNextGameEvent(this);
}

void KTLayerPause::doRestart()
{
    m_delegate->didRecieveRestartEvent(this);
}
void KTLayerPause::doResume()
{
    m_delegate->didRecieveResumeEvent(this);
}
void KTLayerPause::doQuit()
{
    m_delegate->didRecieveQuitEvent(this);
}
void KTLayerPause::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}
void KTLayerPause::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority - 1, true);
    CCLayer::onEnter();
}
KTLayerPause::~KTLayerPause()
{
    m_delegate = NULL;
}
KTLayerPause::KTLayerPause()
{

}
