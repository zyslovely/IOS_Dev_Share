//
//  TBWVRuleCoreData.h
//  YYZPlugin
//
//  通信规则模块核心数据定义
//
//  Created by 颜 垣 on 13-5-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

// 开关关闭值
#define TBWV_IS_LOCK_VALUE  @"1"
#define TBWV_SPLIT_CHAR     @","
#define TBWV_SPLIT_KEY_CAHR @":"

// [存留在运行上下文环境]拦截规则的KEY
#define TBWV_RULE_KEY       @"_tbwv_rule_key"
// [存留在运行上下文环境]开关KEY
#define TBWV_RULE_LOCK_KEY  @"_tbwv_rule_lock"

// 拦截规则的默认协议
#define T_OTHER         0
#define T_OUTSIDE       -1 // 外部站点
#define T_OTHER_PRO     -2 // 未处理协议

/*!
 * 请求的拦截方式，正则匹配 or 参数提取
 */
typedef enum {
    T_R_REG     = 0,
    T_R_PARAM   = 1
} TBWVRuleType;
