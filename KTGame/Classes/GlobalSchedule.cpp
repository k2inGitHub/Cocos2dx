//
//  GlobalSchedule.cpp
//  colorful
//
//  Created by SongYang on 13-11-29.
//
//

#include "GlobalSchedule.h"
//#include "KTDynamicData.h"

#define SCHEDULE CCDirector::sharedDirector()->getScheduler()

GlobalSchedule* GlobalSchedule::m_pSchedule = NULL;

GlobalSchedule::GlobalSchedule(float fInterval, float fDelay) {
    CCLog("GlobalSchedule()");
    
    CCAssert(!m_pSchedule, "已定义，不能重复定义");
    
    SCHEDULE->scheduleSelector(schedule_selector(GlobalSchedule::globalUpdate), this, fInterval, kCCRepeatForever, fDelay, false);
    
    m_pSchedule = this;
}

GlobalSchedule::~GlobalSchedule() {
    CCLog("GlobalSchedule().~()");
    
    SCHEDULE->unscheduleSelector(
                                 schedule_selector(GlobalSchedule::globalUpdate), this);
    
}

void GlobalSchedule::globalUpdate() {
    // 这里写全局定时器的逻辑处理代码
//    KTDynamicData *dd = KTDynamicData::sharedData();
//    int t = dd->getGameTime();
//    int s = 720 - abs((t%720));
//    CCNotificationCenter::sharedNotificationCenter()->postNotification("HeartTimeChanged", CCString::createWithFormat("%d%c%0.2d",s/60, ':', s%60));
//    if (s == 720 && dd->getHeartCount() < 5) {
//        dd->setHeartCount(dd->getHeartCount() + 1);
//    }
}

void GlobalSchedule::start(float fInterval, float fDelay) {
    new GlobalSchedule(fInterval, fDelay);
}

void GlobalSchedule::stop() {
    CCLog("GlobalSchedule().stop()");
    
    CCAssert(m_pSchedule, "未定义");
    CC_SAFE_DELETE(m_pSchedule);
}

void GlobalSchedule::pause() {
    CCLog("GlobalSchedule().pause()");
    
    CCAssert(m_pSchedule, "未定义");
    SCHEDULE->pauseTarget(m_pSchedule);
}

void GlobalSchedule::resume() {
    CCLog("GlobalSchedule().resume()");
    
    CCAssert(m_pSchedule, " 未定义");
    SCHEDULE->resumeTarget(m_pSchedule);
}