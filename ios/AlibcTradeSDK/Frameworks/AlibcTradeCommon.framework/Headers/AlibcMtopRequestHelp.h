/*
 * AlibcMtopRequestHelp.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.93
 * 发布时间：2017-03-06
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1229144682(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcMtopCmd.h"
#import "AlibcNetError.h"
#import "AlibcConfig.h"

#ifndef AlibcMtopRequestHelp_h
#define AlibcMtopRequestHelp_h

//dataObj是mtop返回数据的data节点
typedef void(^MtopRequestCallback)(AlibcNetError *_Nullable error, _Nullable id dataObj);


@interface AlibcMtopRequestHelp : NSObject
//uniqueKey长度大于0,会以cmd+uniqueKey作为值请求去重.
//NSDictionary里面可以包含基本的array,NSDictionary,内部会自己转换成string的
//needLogin,needAuth不填,则默认都欧式NO
//version可以填nil,默认版本是1.0

+ (void)ProcessMtopRequest:(nonnull AlibcMtopCmd *)cmd
                      data:(nullable NSDictionary *)dict
                  complete:(nullable MtopRequestCallback)callback;

+ (void)ProcessMtopRequest:(nonnull AlibcMtopCmd *)cmd
                      data:(nullable NSDictionary *)dict
                 uniqueKey:(nullable NSString *)uniqueKey
                  complete:(nullable MtopRequestCallback)callback;

//这个接口专给组件用的
+ (void)ProcessMtopRequest:(nonnull NSString *)cmdName
                   version:(nullable NSString *)version
                      data:(nullable NSDictionary *)dict
                     bizId:(nullable NSString *)bizId
                 uniqueKey:(nullable NSString *)uniqueKey
                 needLogin:(BOOL)needLogin
                  needAuth:(BOOL)needAuth
                   needWua:(BOOL)needWua
                  complete:(nullable MtopRequestCallback)callback;


@end

#endif
