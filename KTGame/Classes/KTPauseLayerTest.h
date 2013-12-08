//
//  KTPauseLayerTest.h
//  KTGame
//
//  Created by 宋扬 on 13-12-7.
//
//

#ifndef __KTGame__KTPauseLayerTest__
#define __KTGame__KTPauseLayerTest__

#include "KTPopLayer.h"

class KTPauseLayerTest : public KTPopLayer {
protected:
    bool init();
    void itemClick(CCMenuItemImage *item);
public:
    CREATE_FUNC(KTPauseLayerTest);
};

#endif /* defined(__KTGame__KTPauseLayerTest__) */
