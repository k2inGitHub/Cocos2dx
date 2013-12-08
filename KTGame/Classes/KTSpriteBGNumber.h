//
//  KTSpriteBGNumber.h
//  colorful
//
//  Created by SongYang on 13-10-27.
//
//

/*
    自定义带背景，显示图片文字的Sprite
 */

#ifndef colorful_KTSpriteBGNumber_h
#define colorful_KTSpriteBGNumber_h

#include "cocos2d.h"
#include "KTUtils.h"
USING_NS_CC;

class KTSpriteBGNumber : public CCSprite {
    
    CCLabelAtlas *m_numLabel;
    CCSprite *m_bgSprite;
public:
    virtual bool init(int num,const char* bgFile, const char* fontFile, CCSize fontSize);
    virtual bool init(const char* content, const char* fontFile, CCSize fontSize);
    KTSpriteBGNumber();
    ~KTSpriteBGNumber();
    static KTSpriteBGNumber* create(int num,const char* bgFile, const char* fontFile, CCSize fontSize);
    static KTSpriteBGNumber* create(const char* content, const char* fontFile, CCSize fontSize);
    void refresh(int num);
    void refreshContent(const char* content);
};

#endif
