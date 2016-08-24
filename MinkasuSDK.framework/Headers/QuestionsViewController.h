//
//  QuestionsViewController.h
//  PayNow
//
//  Created by Naveen Doraiswamy on 6/23/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ShowQuestionsViewController.h"

@interface QuestionsViewController : UIViewController<UIPickerViewDataSource, UIPickerViewDelegate>

@property NSUInteger currQuestionIndex;
@property NSMutableArray *answerIndexes;

@property NSString *verificationId;
@property NSString *questionSetId;
@property NSArray  *questions;
@property ShowQuestionsViewController *root_view_controller;

@property (weak, nonatomic) IBOutlet UILabel *questionNum;
@property (weak, nonatomic) IBOutlet UILabel *questionText;
@property (weak, nonatomic) IBOutlet UIPickerView *answerPicker;
@property (weak, nonatomic) IBOutlet UIButton *prevButton;
@property (weak, nonatomic) IBOutlet UIButton *nextButton;
@property (weak, nonatomic) IBOutlet UIButton *submitButton;

- (IBAction)prevQuestion:(id)sender;
- (IBAction)nextQuestion:(id)sender;
- (IBAction)submitAnswers:(id)sender;
- (IBAction)cancelQuestions:(id)sender;

@end
