//
//  GlobalSchedule.h
//  colorful
//
//  Created by SongYang on 13-11-29.
//
//

#ifndef __colorful__GlobalSchedule__
#define __colorful__GlobalSchedule__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

/**
 *   全局定时器
 */
class GlobalSchedule: public CCObject {
public:
    // 开始全局定时器 fInterval: 时间间隔 ; fDelay: 延迟运行
    static void start(float fInterval = 0.0f, float fDelay = 0.0f);
    // 停止全局定时器
    static void stop();
    // 全局定时器暂停
    static void pause();
    // 全局定时器暂停恢复
    static void resume();
    // 全局定时器主逻辑实现
    void globalUpdate();
    
private:
    // 构造函数私有化，只能通过 start 来启用全局定时器
    GlobalSchedule(float fInterval, float fDelay);
    ~GlobalSchedule();
    
    // 静态变量保持单例
    static GlobalSchedule* m_pSchedule;
};

#endif /* defined(__colorful__GlobalSchedule__) */
