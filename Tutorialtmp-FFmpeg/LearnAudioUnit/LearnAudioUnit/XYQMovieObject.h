//
//  XYQMovieObject.h
//  FFmpeg_Test
//
//  Created by mac on 16/7/11.
//  Copyright © 2016年 xiayuanquan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

@interface XYQMovieObject : NSObject

/* Decoded UIImage */
@property (nonatomic, strong, readonly) UIImage *currentImage;

/* Frame height of the video */
@property (nonatomic, assign, readonly) int sourceWidth, sourceHeight;

/* Output image size. The default setting is the source size. */
@property (nonatomic,assign) int outputWidth, outputHeight;

/* The length of the video, in seconds */
@property (nonatomic, assign, readonly) double duration;

/* Current seconds of the video */
@property (nonatomic, assign, readonly) double currentTime;

/* Video frame rate */
@property (nonatomic, assign, readonly) double fps;

/* Video path. */
- (instancetype)initWithVideo:(NSString *)moviePath;

/* Switch resources*/
- (void)replaceTheResources:(NSString *)moviePath;

/* Redial */
- (void)redialPaly;

/* Read the next frame from the video stream. Returns false if there is no frame read (video). */
- (BOOL)stepFrame;

/* Seeking the most recent keyframe at the specified time */
- (void)seekTime:(double)seconds;

- (uint8_t *)getYUVdata;

- (CVPixelBufferRef)getCurrentCVPixelBuffer;
@end
