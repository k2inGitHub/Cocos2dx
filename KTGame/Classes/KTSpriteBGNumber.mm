//
//  KTSpriteBGNumber.cpp
//  colorful
//
//  Created by SongYang on 13-10-27.
//
//

#include "KTSpriteBGNumber.h"

KTSpriteBGNumber* KTSpriteBGNumber::create(int num,const char* bgFile, const char* fontFile, CCSize fontSize)
{
    KTSpriteBGNumber *pSprite = new KTSpriteBGNumber();
    if (pSprite && pSprite->init(num, bgFile,fontFile, fontSize))
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

bool KTSpriteBGNumber::init(int num, const char* bgFile, const char* fontFile, CCSize fontSize) {
    if (!CCSprite::init()) {
        return false;
    }
    CCString *numStr = CCString::createWithFormat("%d", num);
    m_numLabel = CCLabelAtlas::create(numStr->getCString(), fontFile, fontSize.width, fontSize.height, '0');
    m_numLabel->setAnchorPoint(ccp(0.5, 0.5));
    m_numLabel->setPosition(ccp(0, 2));
    this->addChild(m_numLabel,1);
    
    m_bgSprite = CCSprite::create(bgFile);
    this->addChild(m_bgSprite,0);
    
    return true;
}

KTSpriteBGNumber* KTSpriteBGNumber::create(const char *content, const char *fontFile, cocos2d::CCSize fontSize)
{
    KTSpriteBGNumber *pSprite = new KTSpriteBGNumber();
    if (pSprite && pSprite->init(content,fontFile, fontSize))
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

bool KTSpriteBGNumber::init(const char *content, const char *fontFile, cocos2d::CCSize fontSize)
{
    if (!CCSprite::init()) {
        return false;
    }
    m_numLabel = CCLabelAtlas::create(content, fontFile, fontSize.width, fontSize.height, '0');
    m_numLabel->setAnchorPoint(ccp(0.5, 0.5));
    m_numLabel->setPosition(ccp(0, 2));
    this->addChild(m_numLabel,1);
    
    return true;
}

KTSpriteBGNumber::KTSpriteBGNumber()
: m_numLabel(NULL)
, m_bgSprite(NULL){
    
}

KTSpriteBGNumber::~KTSpriteBGNumber() {
    
}

void KTSpriteBGNumber::refreshContent(const char *content)
{
    m_numLabel->setString(content);
}

void KTSpriteBGNumber::refresh(int num) {
    m_numLabel->setString(CCString::createWithFormat("%d", num)->getCString());
}