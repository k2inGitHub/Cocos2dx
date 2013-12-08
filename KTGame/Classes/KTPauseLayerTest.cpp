//
//  KTPauseLayerTest.cpp
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#include "KTPauseLayerTest.h"
#include "KTUtils.h"
#include "KTFactory.h"

void KTPauseLayerTest::itemClick(cocos2d::CCMenuItemImage *item)
{
    doQuit();
}

bool KTPauseLayerTest::init()
{
    if (!KTPopLayer::init()) {
        return false;
    }
    
    CCLayerColor *la = CCLayerColor::create(ccc4(0, 0, 0, 128));
    CCSize s = CCDirector::sharedDirector()->getWinSize();
//    la->setPosition(ccp(s.width/2, s.height/2));
    m_pLayer->addChild(la);
    
    
//    CCSprite *sp = CCSprite::create("Icon-114.png");
//    sp->setPosition(ccp(s.width/2, s.height/2));
//    m_pLayer->addChild(sp);
//
    CCMenuItemImage *item = KTFactory::createMenuItemImage("Icon-114.png", NULL, this, menu_selector(KTPauseLayerTest::itemClick), ccp(s.width/2, s.height/2), 0);
    m_pMenu->addChild(item);
    return true;
}