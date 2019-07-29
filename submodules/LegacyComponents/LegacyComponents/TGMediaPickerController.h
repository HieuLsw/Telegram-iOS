#import <LegacyComponents/TGViewController.h>

#import <LegacyComponents/TGSuggestionContext.h>

@class TGMediaPickerLayoutMetrics;
@class TGMediaSelectionContext;
@class TGMediaEditingContext;
@class TGMediaPickerSelectionGestureRecognizer;
@class TGMediaAssetsPallete;

@interface TGMediaPickerController : TGViewController <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>
{
    TGMediaPickerLayoutMetrics *_layoutMetrics;
    CGFloat _collectionViewWidth;
    UICollectionView *_collectionView;
    UIView *_wrapperView;
    TGMediaPickerSelectionGestureRecognizer *_selectionGestureRecognizer;
}

@property (nonatomic, strong) TGSuggestionContext *suggestionContext;
@property (nonatomic, assign) bool localMediaCacheEnabled;
@property (nonatomic, assign) bool captionsEnabled;
@property (nonatomic, assign) bool allowCaptionEntities;
@property (nonatomic, assign) bool inhibitDocumentCaptions;
@property (nonatomic, assign) bool shouldStoreAssets;
@property (nonatomic, assign) bool hasTimer;
@property (nonatomic, assign) bool onlyCrop;
@property (nonatomic, assign) bool inhibitMute;
@property (nonatomic, strong) NSString *recipientName;
@property (nonatomic, assign) bool hasSilentPosting;

@property (nonatomic, strong) TGMediaAssetsPallete *pallete;

@property (nonatomic, readonly) TGMediaSelectionContext *selectionContext;
@property (nonatomic, readonly) TGMediaEditingContext *editingContext;

@property (nonatomic, copy) void (^catchToolbarView)(bool enabled);

- (instancetype)initWithContext:(id<LegacyComponentsContext>)context selectionContext:(TGMediaSelectionContext *)selectionContext editingContext:(TGMediaEditingContext *)editingContext;
- (NSArray *)resultSignals:(id (^)(id, NSString *, NSString *))descriptionGenerator;

- (NSUInteger)_numberOfItems;
- (id)_itemAtIndexPath:(NSIndexPath *)indexPath;
- (SSignal *)_signalForItem:(id)item;
- (NSString *)_cellKindForItem:(id)item;
- (Class)_collectionViewClass;
- (UICollectionViewLayout *)_collectionLayout;

- (void)_hideCellForItem:(id)item animated:(bool)animated;
- (void)_adjustContentOffsetToBottom;

- (void)_setupSelectionGesture;
- (void)_cancelSelectionGestureRecognizer;

@end
