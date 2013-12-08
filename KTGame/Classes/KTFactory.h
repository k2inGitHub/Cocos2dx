//
//  KTFactory.h
//  LeiTing
//
//  Created by SongYang on 13-9-27.
//
//

#ifndef LeiTing_KTFactory_h
#define LeiTing_KTFactory_h

#include "cocos2d.h"
USING_NS_CC;
/**
 KTFactory所有方法都是类方法，产生CC元素
 */
class KTFactory {
    
public:
    static CCMenuItemImage* createMenuItemImage(const char *img, const char *imgSel, CCObject *target, SEL_MenuHandler sel, CCPoint position, int tag);
    static CCAnimation* createAnimation(const char* file, int count, int startIndex);
    static void addSpriteFrameToCache(const char*filename);
    static CCSpriteFrame* spriteFrameByName(const char*filename);
    static CCLabelAtlas* createLabelAtlas(const char* string, const char *filename, unsigned int startItem, int itemCount, CCPoint anchorPoint, CCPoint position);
};


#endif
