//
//  KTUtils.h
//  colorful
//
//  Created by SongYang on 13-10-27.
//
//

#ifndef colorful_KTUtils_h
#define colorful_KTUtils_h

#include "cocos2d.h"
USING_NS_CC;


#pragma mark - 带一个参数的create方法

#define CREATE_FUNC_PARAM(__TYPE__,PTYPE,PNAME) \
static __TYPE__* create(PTYPE PNAME) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init(PNAME)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

#pragma mark - 带两个参数的create方法

#define CREATE_FUNC_PARAM_2(__TYPE1__,PTYPE1,PNAME1,PTYPE2,PNAME2) \
static __TYPE__1* create(PTYPE1 PNAME1,PTYPE2 PNAME2) \
{ \
__TYPE1__ *pRet = new __TYPE1__(); \
if (pRet && pRet->init(PNAME1,PNAME2)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}


#define CC_DIRECTOR CCDirector::sharedDirector()
#define WIN_SIZE    CC_DIRECTOR->getWinSize()
#define WIN_CENTER  CCPointMake(WIN_SIZE.width/2, WIN_SIZE.height/2)
#define CC_TOUCH_DISPATCHER CC_DIRECTOR->getTouchDispatcher()
#define CC_NOTIFICATION_CENTER    CCNotificationCenter::sharedNotificationCenter()
#define CC_USER_DEFAULT    CCUserDefault::sharedUserDefault()

#pragma mark - 获取CCRect常用位置的坐标

static inline CCPoint
ccRectRight(CCRect s_visibleRect)
{
    CCDirector::sharedDirector()->getTouchDispatcher();
    return ccp(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}
static inline CCPoint
ccRectLeft(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}
static inline CCPoint
ccRectTop(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y + s_visibleRect.size.height);
}
static inline CCPoint
ccRectBottom(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y);
}
static inline CCPoint
ccRectLeftTop(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height);
}
static inline CCPoint
ccRectLeftBottom(CCRect s_visibleRect)
{
    return s_visibleRect.origin;
}
static inline CCPoint
ccRectRightTop(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height);
}
static inline CCPoint
ccRectRightBottom(CCRect s_visibleRect)
{
    return ccp(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y);
}

#pragma mark - 辅助类
class KTUtils : public CCObject {
    
public:
};


#endif
