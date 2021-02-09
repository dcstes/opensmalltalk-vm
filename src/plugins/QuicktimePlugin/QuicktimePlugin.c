/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2944 uuid: 242b00d2-2d09-4363-8f25-cedcd6ee2187
   from
	QuicktimePlugin VMMaker.oscog-eem.2944 uuid: 242b00d2-2d09-4363-8f25-cedcd6ee2187
 */
static char __buildInfo[] = "QuicktimePlugin VMMaker.oscog-eem.2944 uuid: 242b00d2-2d09-4363-8f25-cedcd6ee2187 " __DATE__ ;


#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "QuicktimePlugin.h"
#include "sqMemoryAccess.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif


/*** Constants ***/
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
EXPORT(sqInt) primitiveClearFrameCompletedSemaphore(void);
EXPORT(sqInt) primitiveDestroyHandle(void);
EXPORT(sqInt) primitiveDestroySurface(void);
EXPORT(sqInt) primitiveSetFrameCompletedSemaphore(void);
EXPORT(sqInt) primitiveSetGWorldPtrOntoExistingSurface(void);
EXPORT(sqInt) primitiveSetGWorldPtrOntoSurface(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
#if !defined(integerObjectOf)
static sqInt (*integerObjectOf)(sqInt value);
#endif
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static usqIntptr_t (*positiveMachineIntegerValueOf)(sqInt oop);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
#if !defined(integerObjectOf)
extern sqInt integerObjectOf(sqInt value);
#endif
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt methodReturnValue(sqInt oop);
extern sqInt pop(sqInt nItems);
extern usqIntptr_t positiveMachineIntegerValueOf(sqInt oop);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "QuicktimePlugin VMMaker.oscog-eem.2944 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* QuicktimePlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return sqQuicktimeInitialize();
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

	/* QuicktimePlugin>>#moduleUnloaded: */
EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	if ((strcmp(aModuleName, "QuicktimePlugin")) == 0) {
		sqQuicktimeShutdown();
	}
	return 0;
}

	/* QuicktimePlugin>>#primitiveClearFrameCompletedSemaphore: */
EXPORT(sqInt)
primitiveClearFrameCompletedSemaphore(void)
{
	sqInt data;

	if (!(isIntegerObject((data = stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	data = integerValueOf(data);
	if (failed()) {
		return null;
	}
	stQuicktimeClearSemaphore(data);
	return null;
}

	/* QuicktimePlugin>>#primitiveDestroyHandle: */
EXPORT(sqInt)
primitiveDestroyHandle(void)
{
	sqInt data;

	if (!(isIntegerObject((data = stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	data = integerValueOf(data);
	if (failed()) {
		return null;
	}
	stQuicktimeDestroy(data);
	return null;
}

	/* QuicktimePlugin>>#primitiveDestroySurface: */
EXPORT(sqInt)
primitiveDestroySurface(void)
{
	sqInt data;

	if (!(isIntegerObject((data = stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	data = integerValueOf(data);
	if (failed()) {
		return null;
	}
	stQuicktimeDestroySurface(data);
	return null;
}

	/* QuicktimePlugin>>#primitiveSetFrameCompletedSemaphore:for: */
EXPORT(sqInt)
primitiveSetFrameCompletedSemaphore(void)
{
	sqInt data;
	sqInt semaIndex;

	if (!((isIntegerObject((semaIndex = stackValue(1))))
		 && (isIntegerObject((data = stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	semaIndex = integerValueOf(semaIndex);
	data = integerValueOf(data);
	if (failed()) {
		return null;
	}
	stQuicktimeSetSemaphorefor(semaIndex, data);
	return null;
}

	/* QuicktimePlugin>>#primitiveSetGWorldPtrOntoExistingSurface:gWorld:width:height:rowBytes:depth:movie: */
EXPORT(sqInt)
primitiveSetGWorldPtrOntoExistingSurface(void)
{
	sqInt bitMapPtr;
	char *buffer;
	sqInt depth;
	sqInt height;
	sqIntptr_t movie;
	sqInt moviePtr;
	sqInt rowBytes;
	sqInt surfaceID;
	sqInt width;

	if (!((isIntegerObject((surfaceID = stackValue(6))))
		 && ((isIntegerObject((width = stackValue(4))))
		 && ((isIntegerObject((height = stackValue(3))))
		 && ((isIntegerObject((rowBytes = stackValue(2))))
		 && (isIntegerObject((depth = stackValue(1))))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	surfaceID = integerValueOf(surfaceID);
	bitMapPtr = stackValue(5);
	width = integerValueOf(width);
	height = integerValueOf(height);
	rowBytes = integerValueOf(rowBytes);
	depth = integerValueOf(depth);
	moviePtr = stackValue(0);
	if (failed()) {
		return null;
	}
	buffer = ((char *) (positiveMachineIntegerValueOf(bitMapPtr)));
	movie = ((sqIntptr_t) (positiveMachineIntegerValueOf(moviePtr)));
	stQuicktimeSetToExistingSurfacegworldwidthheightrowBytesdepthmovie(surfaceID, buffer, width, height, rowBytes, depth, movie);
	if (!(failed())) {
		pop(7);
	}
	return null;
}

	/* QuicktimePlugin>>#primitiveSetGWorldPtrOntoSurface:width:height:rowBytes:depth:movie: */
EXPORT(sqInt)
primitiveSetGWorldPtrOntoSurface(void)
{
	sqInt bitMapPtr;
	char *buffer;
	sqInt depth;
	sqInt height;
	sqIntptr_t movie;
	sqInt moviePtr;
	sqInt results;
	sqInt rowBytes;
	sqInt width;
	sqInt _return_value;

	if (!((isIntegerObject((width = stackValue(4))))
		 && ((isIntegerObject((height = stackValue(3))))
		 && ((isIntegerObject((rowBytes = stackValue(2))))
		 && (isIntegerObject((depth = stackValue(1)))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	bitMapPtr = stackValue(5);
	width = integerValueOf(width);
	height = integerValueOf(height);
	rowBytes = integerValueOf(rowBytes);
	depth = integerValueOf(depth);
	moviePtr = stackValue(0);
	if (failed()) {
		return null;
	}
	buffer = ((char *) (positiveMachineIntegerValueOf(bitMapPtr)));
	movie = ((sqIntptr_t) (positiveMachineIntegerValueOf(moviePtr)));
	results = stQuicktimeSetSurfacewidthheightrowBytesdepthmovie(buffer, width, height, rowBytes, depth, movie);
	if (!(failed())) {
		_return_value = integerObjectOf(results);
		if (!(failed())) {
			methodReturnValue(_return_value);
		}
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
	sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
#if !defined(integerObjectOf)
		integerObjectOf = interpreterProxy->integerObjectOf;
#endif
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
		methodReturnValue = interpreterProxy->methodReturnValue;
		pop = interpreterProxy->pop;
		positiveMachineIntegerValueOf = interpreterProxy->positiveMachineIntegerValueOf;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "QuicktimePlugin";
void* QuicktimePlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "moduleUnloaded", (void*)moduleUnloaded},
	{(void*)_m, "primitiveClearFrameCompletedSemaphore\000\000", (void*)primitiveClearFrameCompletedSemaphore},
	{(void*)_m, "primitiveDestroyHandle\000\000", (void*)primitiveDestroyHandle},
	{(void*)_m, "primitiveDestroySurface\000\000", (void*)primitiveDestroySurface},
	{(void*)_m, "primitiveSetFrameCompletedSemaphore\000\000", (void*)primitiveSetFrameCompletedSemaphore},
	{(void*)_m, "primitiveSetGWorldPtrOntoExistingSurface\000\000", (void*)primitiveSetGWorldPtrOntoExistingSurface},
	{(void*)_m, "primitiveSetGWorldPtrOntoSurface\000\000", (void*)primitiveSetGWorldPtrOntoSurface},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveClearFrameCompletedSemaphoreAccessorDepth = 0;
signed char primitiveDestroyHandleAccessorDepth = 0;
signed char primitiveDestroySurfaceAccessorDepth = 0;
signed char primitiveSetFrameCompletedSemaphoreAccessorDepth = 0;
signed char primitiveSetGWorldPtrOntoExistingSurfaceAccessorDepth = 0;
signed char primitiveSetGWorldPtrOntoSurfaceAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
