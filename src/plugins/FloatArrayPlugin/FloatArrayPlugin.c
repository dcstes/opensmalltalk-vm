/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2950 uuid: dbcba85e-dc26-495f-9ce8-aa01633f6aa5
   from
	FloatArrayPlugin VMMaker.oscog-eem.2950 uuid: dbcba85e-dc26-495f-9ce8-aa01633f6aa5
 */
static char __buildInfo[] = "FloatArrayPlugin VMMaker.oscog-eem.2950 uuid: dbcba85e-dc26-495f-9ce8-aa01633f6aa5 " __DATE__ ;


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
#define PrimErrBadReceiver 2


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveAddFloatArray(void);
EXPORT(sqInt) primitiveAddScalar(void);
EXPORT(sqInt) primitiveAt(void);
EXPORT(sqInt) primitiveAtPut(void);
EXPORT(sqInt) primitiveDivFloatArray(void);
EXPORT(sqInt) primitiveDivScalar(void);
EXPORT(sqInt) primitiveDotProduct(void);
EXPORT(sqInt) primitiveEqual(void);
#if SPURVM
EXPORT(sqInt) primitiveFromFloat64Array(void);
#endif /* SPURVM */
EXPORT(sqInt) primitiveHashArray(void);
EXPORT(sqInt) primitiveLength(void);
EXPORT(sqInt) primitiveMulFloatArray(void);
EXPORT(sqInt) primitiveMulScalar(void);
EXPORT(sqInt) primitiveNormalize(void);
EXPORT(sqInt) primitiveSubFloatArray(void);
EXPORT(sqInt) primitiveSubScalar(void);
EXPORT(sqInt) primitiveSum(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static double (*floatValueOf)(sqInt oop);
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isLong64s)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodReturnFloat)(double aFloat);
static sqInt (*methodReturnInteger)(sqInt integer);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushBool)(sqInt trueOrFalse);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stSizeOf)(sqInt oop);
static double (*stackFloatValue)(sqInt offset);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern double floatValueOf(sqInt oop);
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
extern sqInt isLong64s(sqInt oop);
#else
# define isLong64s(oop) 0
#endif
extern sqInt isWords(sqInt oop);
extern sqInt methodReturnFloat(double aFloat);
extern sqInt methodReturnInteger(sqInt integer);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushBool(sqInt trueOrFalse);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stSizeOf(sqInt oop);
extern double stackFloatValue(sqInt offset);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "FloatArrayPlugin VMMaker.oscog-eem.2950 " INT_EXT;



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


/*	Primitive. Add the receiver and the argument, both FloatArrays and store
	the result into the receiver.
 */

	/* FloatArrayPlugin>>#primitiveAddFloatArray */
EXPORT(sqInt)
primitiveAddFloatArray(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) + (((double) (argPtr[i]))));
	}
	pop(1);
	return 0;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a FloatArray */

	/* FloatArrayPlugin>>#primitiveAddScalar */
EXPORT(sqInt)
primitiveAddScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) + value);
	}
	pop(1);
	return 0;
}

	/* FloatArrayPlugin>>#primitiveAt */
EXPORT(sqInt)
primitiveAt(void)
{
    float *floatPtr;
    sqInt index;
    sqInt rcvr;

	index = stackIntegerValue(0);
	rcvr = stackValue(1);
	if (!((!(failed()))
		 && ((isWords(rcvr))
		 && ((index > 0)
		 && (index <= (slotSizeOf(rcvr))))))) {
		return primitiveFail();
	}
	floatPtr = ((float *) (firstIndexableField(rcvr)));
	methodReturnFloat(floatPtr[index - 1]);
	return 0;
}

	/* FloatArrayPlugin>>#primitiveAtPut */
EXPORT(sqInt)
primitiveAtPut(void)
{
    float *floatPtr;
    double floatValue;
    sqInt index;
    sqInt rcvr;
    sqInt value;

	value = stackValue(0);
	floatValue = (isIntegerObject(value)
		? ((double) (integerValueOf(value)) )
		: floatValueOf(value));
	index = stackIntegerValue(1);
	rcvr = stackValue(2);
	if (!((!(failed()))
		 && ((isWords(rcvr))
		 && ((index > 0)
		 && (index <= (slotSizeOf(rcvr))))))) {
		return primitiveFail();
	}
	floatPtr = ((float *) (firstIndexableField(rcvr)));
	floatPtr[index - 1] = (((float) floatValue));
	popthenPush(3, value);
	return 0;
}


/*	Primitive. Divide each element in the receiver by the corresponding
	element in the argument, both FloatArrays, and store the result into the
	receiver. 
 */

	/* FloatArrayPlugin>>#primitiveDivFloatArray */
EXPORT(sqInt)
primitiveDivFloatArray(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));

	/* Check if any of the argument's values is zero */
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		if ((argPtr[i]) == (0.0f)) {

			/* i.e. check for both 0.0 and -0.0 */
			return primitiveFail();
		}
	}
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) / (((double) (argPtr[i]))));
	}
	pop(1);
	return 0;
}


/*	Primitive. Divide each element in the receiver by the argument, a scalar,
	and store the result into the receiver, a FloatArray
 */

	/* FloatArrayPlugin>>#primitiveDivScalar */
EXPORT(sqInt)
primitiveDivScalar(void)
{
    sqInt i;
    double inverse;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	inverse = 1.0 / value;
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * inverse);
	}
	pop(1);
	return 0;
}


/*	Primitive. Compute the dot product of the receiver and the argument.
	The dot product is defined as the sum of the products of the individual
	elements. 
 */

	/* FloatArrayPlugin>>#primitiveDotProduct */
EXPORT(sqInt)
primitiveDotProduct(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double result;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	result = 0.0;
	for (i = 0; i < length; i += 1) {
		result += (((double) (rcvrPtr[i]))) * (((double) (argPtr[i])));
	}
	methodReturnFloat(result);
	return 0;
}

	/* FloatArrayPlugin>>#primitiveEqual */
EXPORT(sqInt)
primitiveEqual(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && (isWords(rcvr)))) {
		return primitiveFail();
	}
	pop(2);
	if (!(((length = stSizeOf(arg))) == (stSizeOf(rcvr)))) {
		return pushBool(0);
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		if (!((rcvrPtr[i]) == (argPtr[i]))) {
			return pushBool(0);
		}
	}
	return pushBool(1);
}


/*	Primitive. Set each element of the receiver, a FloatArray with that of the
	argument, a Float64Array and return the receiver.
	Note that this conversion might loose bits, or generate overflow.
	Fail if both have different size
 */

	/* FloatArrayPlugin>>#primitiveFromFloat64Array */
#if SPURVM
EXPORT(sqInt)
primitiveFromFloat64Array(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = (((float) (argPtr[i])));
	}
	pop(1);
	return 0;
}
#endif /* SPURVM */

	/* FloatArrayPlugin>>#primitiveHashArray */
EXPORT(sqInt)
primitiveHashArray(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    unsigned int *rcvrPtr;
    unsigned int result;

	rcvr = stackValue(0);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((unsigned int *) (firstIndexableField(rcvr)));
	result = 0;
	for (i = 0; i < length; i += 1) {
		result += rcvrPtr[i];
	}
	methodReturnInteger(result & 0x1FFFFFFF);
	return 0;
}


/*	Primitive. Compute the length of the argument (sqrt of sum of component
	squares). 
 */

	/* FloatArrayPlugin>>#primitiveLength */
EXPORT(sqInt)
primitiveLength(void)
{
    sqInt i;
    double len;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	rcvr = stackValue(0);
	if (!(isWords(rcvr))) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	len = 0.0;
	for (i = 0; i < length; i += 1) {
		len += (((double) (rcvrPtr[i]))) * (((double) (rcvrPtr[i])));
	}
	if (!(len > 0.0)) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	methodReturnFloat(sqrt(len));
	return 0;
}


/*	Primitive. Multiply the receiver and the argument, both FloatArrays and
	store the result into the receiver.
 */

	/* FloatArrayPlugin>>#primitiveMulFloatArray */
EXPORT(sqInt)
primitiveMulFloatArray(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * (((double) (argPtr[i]))));
	}
	pop(1);
	return 0;
}


/*	Primitive. Multiply elements in the receiver, a FloatArray, by argument, a
	scalar value, and store the result into the receiver.
 */

	/* FloatArrayPlugin>>#primitiveMulScalar */
EXPORT(sqInt)
primitiveMulScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * value);
	}
	pop(1);
	return 0;
}


/*	Primitive. Normalize the argument (A FloatArray) in place. */

	/* FloatArrayPlugin>>#primitiveNormalize */
EXPORT(sqInt)
primitiveNormalize(void)
{
    sqInt i;
    double len;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	rcvr = stackValue(0);
	if (!(isWords(rcvr))) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	len = 0.0;
	for (i = 0; i < length; i += 1) {
		len += (((double) (rcvrPtr[i]))) * (((double) (rcvrPtr[i])));
	}
	if (!(len > 0.0)) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	len = sqrt(len);
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) / len);
	}
	return 0;
}


/*	Primitive. Subtract each element in the argument from each element in the
	receiver, both FloatArrays and store the result into the receiver.
 */

	/* FloatArrayPlugin>>#primitiveSubFloatArray */
EXPORT(sqInt)
primitiveSubFloatArray(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isWords(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) - (((double) (argPtr[i]))));
	}
	pop(1);
	return 0;
}


/*	Primitive. Subtract the argument, a scalar value from each element in the
	receiver, a FloatArray */

	/* FloatArrayPlugin>>#primitiveSubScalar */
EXPORT(sqInt)
primitiveSubScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) - value);
	}
	pop(1);
	return 0;
}


/*	Primitive. Answer the sum of each float in the receiver, a FloatArray. */

	/* FloatArrayPlugin>>#primitiveSum */
EXPORT(sqInt)
primitiveSum(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double sum;

	rcvr = stackValue(0);
	if (!(isWords(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	sum = 0.0;
	for (i = 0; i < length; i += 1) {
		sum += ((double) (rcvrPtr[i]));
	}
	methodReturnFloat(sum);
	return 0;
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
		firstIndexableField = interpreterProxy->firstIndexableField;
		floatValueOf = interpreterProxy->floatValueOf;
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
		isLong64s = interpreterProxy->isLong64s;
#else
#if !defined(isLong64s)
		isLong64s = 0;
#endif
#endif
		isWords = interpreterProxy->isWords;
		methodReturnFloat = interpreterProxy->methodReturnFloat;
		methodReturnInteger = interpreterProxy->methodReturnInteger;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushBool = interpreterProxy->pushBool;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stSizeOf = interpreterProxy->stSizeOf;
		stackFloatValue = interpreterProxy->stackFloatValue;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "FloatArrayPlugin";
void* FloatArrayPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveAddFloatArray\000\000", (void*)primitiveAddFloatArray},
	{(void*)_m, "primitiveAddScalar\000\000", (void*)primitiveAddScalar},
	{(void*)_m, "primitiveAt\000\000", (void*)primitiveAt},
	{(void*)_m, "primitiveAtPut\000\000", (void*)primitiveAtPut},
	{(void*)_m, "primitiveDivFloatArray\000\000", (void*)primitiveDivFloatArray},
	{(void*)_m, "primitiveDivScalar\000\000", (void*)primitiveDivScalar},
	{(void*)_m, "primitiveDotProduct\000\000", (void*)primitiveDotProduct},
	{(void*)_m, "primitiveEqual\000\000", (void*)primitiveEqual},
#if SPURVM
	{(void*)_m, "primitiveFromFloat64Array\000\000", (void*)primitiveFromFloat64Array},
#endif /* SPURVM */
	{(void*)_m, "primitiveHashArray\000\000", (void*)primitiveHashArray},
	{(void*)_m, "primitiveLength\000\000", (void*)primitiveLength},
	{(void*)_m, "primitiveMulFloatArray\000\000", (void*)primitiveMulFloatArray},
	{(void*)_m, "primitiveMulScalar\000\000", (void*)primitiveMulScalar},
	{(void*)_m, "primitiveNormalize\000\000", (void*)primitiveNormalize},
	{(void*)_m, "primitiveSubFloatArray\000\000", (void*)primitiveSubFloatArray},
	{(void*)_m, "primitiveSubScalar\000\000", (void*)primitiveSubScalar},
	{(void*)_m, "primitiveSum\000\000", (void*)primitiveSum},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

EXPORT(signed char) primitiveAddFloatArrayAccessorDepth = 0;
EXPORT(signed char) primitiveAddScalarAccessorDepth = 0;
EXPORT(signed char) primitiveAtAccessorDepth = 0;
EXPORT(signed char) primitiveAtPutAccessorDepth = 0;
EXPORT(signed char) primitiveDivFloatArrayAccessorDepth = 0;
EXPORT(signed char) primitiveDivScalarAccessorDepth = 0;
EXPORT(signed char) primitiveDotProductAccessorDepth = 0;
EXPORT(signed char) primitiveEqualAccessorDepth = 0;
#if SPURVM
EXPORT(signed char) primitiveFromFloat64ArrayAccessorDepth = 0;
#endif /* SPURVM */
EXPORT(signed char) primitiveHashArrayAccessorDepth = 0;
EXPORT(signed char) primitiveLengthAccessorDepth = 0;
EXPORT(signed char) primitiveMulFloatArrayAccessorDepth = 0;
EXPORT(signed char) primitiveMulScalarAccessorDepth = 0;
EXPORT(signed char) primitiveNormalizeAccessorDepth = 0;
EXPORT(signed char) primitiveSubFloatArrayAccessorDepth = 0;
EXPORT(signed char) primitiveSubScalarAccessorDepth = 0;
EXPORT(signed char) primitiveSumAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
