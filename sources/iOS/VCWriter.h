/*
 
 Video Core
 Copyright (c) 2014 James G. Hurley
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 */

#import <Foundation/Foundation.h>

#import <AVFoundation/AVFoundation.h>

@interface VCWriter : NSObject
@property (nonatomic, copy, readonly)     NSString     *filePath;
@property (nonatomic, copy, readonly)     NSDictionary *videoSettings;
@property (nonatomic, copy, readonly)     NSDictionary *audioSettings;

@property (nonatomic, readonly, getter=isWriting)   BOOL    writing;
@property (nonatomic, assign, getter=isPaused)      BOOL    paused;

+ (instancetype)writerWithFilePath:(NSString *)filePath
                     videoSettings:(NSDictionary *)videoSettings
                     audioSettings:(NSDictionary *)audioSettings;

- (instancetype)initWithFilePath:(NSString *)filePath
                   videoSettings:(NSDictionary *)videoSettings
                   audioSettings:(NSDictionary *)audioSettings;

- (void)startWriting;

- (void)finishWritingWithCompletionHandler:(void(^)(void))handler;

- (void)cancelWriting;

- (void)pauseWriting;

- (void)continueWriting;

- (void)encodeVideoBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)encodeAudioBuffer:(CMSampleBufferRef)sampleBuffer;

@end
