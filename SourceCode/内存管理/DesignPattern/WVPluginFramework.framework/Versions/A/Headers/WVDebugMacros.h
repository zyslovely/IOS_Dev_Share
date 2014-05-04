//
//  WVDebugMacros.h
//
//  Created by  shuxiao on 14-2-17.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#ifndef WVDebugWindow_WVMacros_h
#define WVDebugWindow_WVMacros_h




#if WV_DEBUG_WINDOW_ENABLE == 1

  #import "WVDebugWindow.h"
  #import "WVDebugStatusBar.h"
  #import "WVDebugGlobalData.h"

    #define WVDebugJumpRule(isStartLoad,resultId,request) [[WVDebugGlobalData sharedInstance] setWebHitResult:isStartLoad target:resultId withRequest:request]
    #define WVDebugWebStatus(status) [[WVDebugGlobalData sharedInstance] setWebviewStatus:status]

    #define WVDebugWindowClose() [[WVDebugWindow sharedInstance] cancelWindow]
    #define WVDebugBarShow(vc) [[WVDebugStatusBar sharedInstance] show:vc];
    #define WVWindowShow() [[WVDebugWindow sharedInstance] windowShow]
    #define WVWindowHide() [[WVDebugWindow sharedInstance] windowHide]
    #define WVWindowActivationTap(touchesNumber) \
         [[WVDebugWindow sharedInstance] windowActivationTapWithTouchesNumber:touchesNumber]
    
    #define WVWindowActivationLongPress(touchesNumber, minPressDuration) \
        [[WVDebugWindow sharedInstance] windowActivationLongPressWithTouchesNumber:touchesNumber \
                                                                 minimumPressDuration:minPressDuration]

    #define WVConfigFrameGet() [WVDebugWindow sharedInstance].configFrame
    #define WVConfigFrameSet(frame) [[WVDebugWindow sharedInstance] setConfigFrame:frame]

    #define WVConfigBackgroundColorGet()  [WVDebugWindow sharedInstance].backgroundColor
    #define WVConfigTopBGColorGet()       [WVDebugWindow sharedInstance].configTopBGColor
    #define WVConfigTopTextColorGet()     [WVDebugWindow sharedInstance].configTopTextColor

    #define WVDebugConfigBackgroundColorSet(color)  [[WVDebugWindow sharedInstance] setConfigBackroundColor:color]
    #define WVDebugConfigTopBGColorSet(color)       [[WVDebugWindow sharedInstance] setConfigTopBGColor:color]
    #define WVDebugConfigTopTextColorSet(color)     [[WVDebugWindow sharedInstance] setConfigTopTextColor:color]

#else

    #define WVDebugJumpRule(isStartLoad,resultId,request)
    #define WVDebugWebStatus(status)

    #define WVDebugWindowClose()
    #define WVDebugBarShow(vc)
    #define WVWindowShow()
    #define WVWindowHide()
    #define WVWindowActivationTap(touchesNumber)
    
    #define WVWindowActivationLongPress(touchesNumber, minPressDuration)

    #define WVConfigFrameGet()
    #define WVConfigFrameSet(frame)

    #define WVConfigBackgroundColorGet()
    #define WVConfigTopBGColorGet()
    #define WVConfigTopTextColorGet()

    #define WVConfigBackgroundColorSet(color)
    #define WVConfigTopBGColorSet(color)
    #define WVConfigTopTextColorSet(color)

#endif


#endif
