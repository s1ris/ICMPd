export TARGET = iphone:clang:latest
export ARCHS = armv7 arm64

include /var/theos/makefiles/common.mk

SOURCE_DIR = sources

TOOL_NAME = ICMPd
ICMPd_FILES = $(foreach ext, c cpp m mm x xm xi xmi, $(wildcard $(SOURCE_DIR)/*.$(ext)))
ICMPd_PRIVATE_FRAMEWORKS = CoreFoundation GraphicsServices
ICMPd_CODESIGN_FLAGS = -Sentitlements.xml

include /var/theos/makefiles/tool.mk
