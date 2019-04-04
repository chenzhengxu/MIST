//
//  CALayer+AsyncTransactionContainer.h
//  VZFlexLayout
//
//  Created by chenzhengxu on 2019/4/4.
//

#import <Foundation/Foundation.h>
#import "VZFAsyncLayer.h"
#import "VZFAsyncDrawingTransactionInterface.h"

@class VZFAsyncDrawingTransaction;
@interface CALayer (AsyncTransactionContainer)<VZFAsyncDrawingTransactionInterface>

// private
// 实际应用场景 hashtable中只会有一个transtion对象
@property (nonatomic, retain) NSHashTable *asyncLayerTransactions;
// layer当前的transtion
@property (nonatomic, retain) VZFAsyncDrawingTransaction *currentAsyncTransaction;

// public
// 可看做是currentAsyncTransaction的getter方法
@property(nonatomic,retain,readonly) VZFAsyncDrawingTransaction* asyncTransaction;
// 遍历查询根节点
@property (nonatomic, retain, readonly) CALayer *parentTransactionContainer;

// isAsyncTransactionContainer 是否是根节点
// asyncTransactionContainerState asyncLayerTransactions是否为空

//subclass overrring
- (void)vz_asyncTransactionContainerWillBeginTransaction:(VZFAsyncDrawingTransaction *)transaction;
- (void)vz_asyncTransactionContainerDidCompleteTransaction:(VZFAsyncDrawingTransaction *)transaction;

@end
