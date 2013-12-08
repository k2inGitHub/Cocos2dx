//
//  KTScrollLayer.h
//  colorful
//
//  Created by SongYang on 13-10-30.
//
//

#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "KTUtils.h"

USING_NS_CC;
USING_NS_CC_EXT;

class KTScrollLayerDelegate {
    
public:
    KTScrollLayerDelegate(){};
    ~KTScrollLayerDelegate(){};
    
    virtual void scrollLayerPageNumberDidChanged(int number){CC_UNUSED_PARAM(number);};
};

class KTScrollLayer : public cocos2d::CCLayer ,public CCScrollViewDelegate
{
public:
    CREATE_FUNC_PARAM(KTScrollLayer, CCArray*, pages);
    
    /**
     @brief 预览前一页
     @param
     */
    void prevPage();
    /**
     @brief 预览后一页
     @param
     */
    void nextPage();
    /**
     @brief 设置当前显示页
     @param currentPage  页数下标
     */
    void setCurrentPage(int currentPage, bool animated);
    
//    CC_SYNTHESIZE_RETAIN(CCArray*, m_pages, Pages);
    
    CC_SYNTHESIZE(KTScrollLayerDelegate* , m_delegate, Delegate);
    CC_SYNTHESIZE_READONLY(int, m_nCurPage, currentPageIndex);
    CC_PROPERTY(bool, m_bScrollCycle, ScrollCycle);
    bool isGestureForward();
    void setGestureForward(bool gestureForward);
    
    CCArray* getPages();
    void setPages(CCArray *pages);
protected:
    
    CCArray *m_pages;
    //显示的Pages是1+N+1张页面  第一张最后一页 最后一张第一页  实现循环滚动
    CCArray *m_pShowPages;
    
    CCScrollView *m_pScrollView;
    CCPoint m_touchPoint;
    float m_fTouchOffset;
    //响应手势的方向 默认是逆势
    bool m_bGestureForward;
    
    CCSprite* createSprite(CCSprite* sp);
    
    void adjustScrollView(float offset);
    void adjustPosition(bool animated);
    
    void scrollViewDidScroll(CCScrollView* view);
	void scrollViewDidZoom(CCScrollView* view);
    
    virtual void onEnter();
	virtual void onExit();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual bool init(CCArray* pages);
    KTScrollLayer();
    ~KTScrollLayer();
};

#endif  