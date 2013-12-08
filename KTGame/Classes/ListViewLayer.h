#ifndef __TABLEVIEWTESTSCENE_H__
#define __TABLEVIEWTESTSCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class ListViewLayer : public cocos2d::CCLayer, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
    virtual bool init();  
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view);

    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);

	//¥¶¿Ì¥•√˛ ¬º˛
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
	//√ø“ªœÓµƒøÌ∂»∫Õ∏ﬂ∂»
    
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
	//…˙≥…¡–±Ì√ø“ªœÓµƒƒ⁄»›
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	//“ªπ≤∂‡…ŸœÓ
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);

    CREATE_FUNC(ListViewLayer);
};

#endif 