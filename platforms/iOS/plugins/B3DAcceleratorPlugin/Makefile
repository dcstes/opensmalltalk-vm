# The current version of B3DAcceleratorPlugin (the OpenGL interface) uses lots
# of Carbon code & is hence 32-bit only.  So include the Carbon frameworks.
# Until this can be rewritten this implies no 64-bit OpenGL on Mac OS X :-(.

INCDIRS:=$(PLATDIR)/Cross/plugins/FilePlugin \
         $(PLATDIR)/unix/vm
INCDIRS:=$(PLATDIR)/unix/vm

EXTRADYFLAGS=-Wl,-U,_getImageName,-U,_getSTWindow,-U,_setWindowChangedHook,-U,_warning \
	-Wl,-U,_getMainWindowOpenGLContext,-U,_createOpenGLTextureLayerHandle,-U,_destroyOpenGLTextureLayerHandle,-U,_setOpenGLTextureLayerContent \
	-Wl,-U,_getMainWindowMetalDevice,-U,_getMainWindowMetalCommandQueue,-U,_createMetalTextureLayerHandle,-U,_destroyMetalTextureLayerHandle,-U,_setMetalTextureLayerContent
EXTRALIBS:= -framework CoreFoundation -framework OpenGL -framework Metal -framework Cocoa

include ../common/Makefile.plugin
