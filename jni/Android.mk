LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := QViewAndroid

#inlcude linopencv-android-armv7a
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libopencv-4.5.0-android-armv7a-prebuilt/sdk/native/jni/include

LOCAL_C_INCLUDES += $(LOCAL_PATH)

#Source main
LOCAL_SRC_FILES := \
		main.cpp \
		DisplayBoard.cpp \
		DisplayProcessor.cpp \
		OpenCVRenderer.cpp \
		Processor.cpp \
		Renderer.cpp \
		RtspThread.cpp \
		ShowProcessor.cpp

#opencv
LOCAL_SHARED_LIBRARIES := libopencv_world-prebuilt


include $(BUILD_EXECUTABLE)


#add lib opencv prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := libopencv_world-prebuilt
LOCAL_SRC_FILES := $(LOCAL_PATH)/libopencv-4.5.0-android-armv7a-prebuilt/sdk/native/libs/armeabi-v7a/libopencv_world.so
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/libopencv-4.5.0-android-armv7a-prebuilt/sdk/native/jni/include
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)