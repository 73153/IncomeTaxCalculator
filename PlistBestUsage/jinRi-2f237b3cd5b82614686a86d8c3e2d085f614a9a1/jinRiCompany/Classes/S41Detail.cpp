//
//  S41Detail.cpp
//  jinRiCompany
//
//  Created by lyy on 13-6-26.
//
//

#include "S41Detail.h"
#include "AppMacros.h"
#include "ScriptParser.h"
#include "PersonalApi.h"



#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define s1FontName_macro "Arial"

#define classPlistName_macro "S41Detail"
#define zNum 100
#define btnTag 100


using namespace cocos2d;
using namespace std;
using namespace extension;

CCScene* S41Detail::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		S41Detail *layer = S41Detail::create();
		scene->addChild(layer);
	} while (0);
    
	return scene;
}

bool S41Detail::initInfo2()
{
    bool bRet = false;
	do
	{
        string plistStr = classPlistName_macro;
        plistStr += ".plist";
        plistDic = CCDictionary::createWithContentsOfFile(plistStr.c_str());
        
        selectedScene = 1;
        
        bRet = true;
	} while (0);
    
	return bRet;
}
bool S41Detail::setUpSubClass2()
{
	bool bRet = false;
	do
	{
        
        
        CCSprite * showbigPicture = CCSprite::create(ScriptParser::getImageFromPlist(plistDic,"S11BigPic"));
        showbigPicture->setPosition(CCPointZero);
     
		
        
        m_pScrollView = CCScrollView::create();
        
        m_pScrollView->addChild(showbigPicture,zNum);
        
        scrollMaxSizeX = showbigPicture->getContentSize().width;
        scrollMaxSizeY = showbigPicture->getContentSize().height;
        
        
        
        m_pScrollView->setPosition(ScriptParser::getPositionFromPlist(plistDic,"scrollView")); //这一步是1.0版本没有的，重要！
        CCSize showSize = ScriptParser::getSizeFromPlist(plistDic,"showSize");
        m_pScrollView->setContentOffset(ccp(0,-(showbigPicture->getContentSize().height-showSize.height)));
        m_pScrollView->setViewSize(CCSizeMake(scrollMaxSizeX, showSize.height));//大小要设置得比图片的小
        m_pScrollView->setContentSize(CCSizeMake(scrollMaxSizeX, scrollMaxSizeY));
        
        //设置滚动方向，
        m_pScrollView->setDirection(kCCScrollViewDirectionVertical);
        m_pScrollView->setDelegate(this);
        this->addChild(m_pScrollView);
        
      
		bRet = true;
	} while (0);
    
	return bRet;
}

