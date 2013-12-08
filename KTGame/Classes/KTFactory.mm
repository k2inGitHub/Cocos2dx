//
//  KTFactory.cpp
//  LeiTing
//
//  Created by Men on 13-9-27.
//
//

#include "KTFactory.h"

CCLabelAtlas* KTFactory::createLabelAtlas(const char* string, const char *filename, unsigned int startItem, int itemCount, CCPoint anchorPoint, CCPoint position)
{
    CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(filename);
    CCSize size = pTexture->getContentSize();
    CCLabelAtlas *pLabelAtlas = CCLabelAtlas::create(string, filename, size.width/itemCount, size.height, startItem);
    pLabelAtlas->setAnchorPoint(anchorPoint);
    pLabelAtlas->setPosition(position);
    return pLabelAtlas;
}

void KTFactory::addSpriteFrameToCache(const char*filename)
{
    CCTexture2D *t = CCTextureCache::sharedTextureCache()->addImage(filename);
    CCSpriteFrame *f = CCSpriteFrame::createWithTexture(t, CCRectMake(0, 0, t->getContentSize().width, t->getContentSize().height));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(f, filename);
}
 CCSpriteFrame* KTFactory::spriteFrameByName(const char*filename)
{
    CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename);
    if (pFrame == NULL) {
        addSpriteFrameToCache(filename);
    }
    return CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename);
}

CCMenuItemImage* KTFactory::createMenuItemImage(const char *img, const char *imgSel, CCObject *target, SEL_MenuHandler sel, CCPoint position, int tag)
{
    CCMenuItemImage *itemImg = CCMenuItemImage::create(img, imgSel, target, sel);
    itemImg->setPosition(position);
    itemImg->setTag(tag);
    return itemImg;
}

CCAnimation* KTFactory::createAnimation(const char* file, int count, int startIndex){
    CCAnimation *animation = CCAnimation::create();
    for (int i = startIndex; i < startIndex + count; i++) {
        const char * name =CCString::createWithFormat("%s%d.png", file, i)->getCString();
        animation->addSpriteFrameWithFileName(name);
    }
    animation->setDelayPerUnit(1.25f);
    return animation;
}