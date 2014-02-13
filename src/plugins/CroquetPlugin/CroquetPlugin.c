/* Smalltalk from Squeak4.5 with VMMaker 4.13.2 translated as C source on 12 February 2014 7:19:43 pm */
/* Automatically generated by
	VMPluginCodeGenerator * VMMaker-dtl.340 uuid: 640fa600-e4e0-4cdd-ae74-c6cf1b51b763
   from
	CroquetPlugin * VMMaker-dtl.340 uuid: 640fa600-e4e0-4cdd-ae74-c6cf1b51b763
 */
static char __buildInfo[] = "CroquetPlugin * VMMaker-dtl.340 uuid: 640fa600-e4e0-4cdd-ae74-c6cf1b51b763 " __DATE__ ;




#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif
#include "CroquetPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primitiveARC4Transform(void);
EXPORT(sqInt) primitiveAdj3(void);
EXPORT(sqInt) primitiveDet3(void);
EXPORT(sqInt) primitiveGatherEntropy(void);
EXPORT(sqInt) primitiveInplaceHouseHolderInvert(void);
EXPORT(sqInt) primitiveInverseByAdjoint(void);
EXPORT(sqInt) primitiveMD5Transform(void);
EXPORT(sqInt) primitiveOrthoNormInverseMatrix(void);
EXPORT(sqInt) primitiveTransformDirection(void);
EXPORT(sqInt) primitiveTransformMatrixWithInto(void);
EXPORT(sqInt) primitiveTransformVector3(void);
EXPORT(sqInt) primitiveTransposeMatrix(void);
EXPORT(sqInt) primitiveTriBoxIntersects(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
static void* stackMatrix(sqInt index);
static void* stackVector3(sqInt index);
static sqInt transformMatrixwithinto(float *src, float *arg, float *dst);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"CroquetPlugin 12 February 2014 (i)"
#else
	"CroquetPlugin 12 February 2014 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}


/*	Perform an ARC4 transform of input.
	Arguments:
		buffer		<ByteArray> transformed data
		startIndex 	<Integer>	start of transform
		stopIndex	<Integer>	end of transform
		m			<ByteArray>	key stream data
		x			<Integer>	key state value
		y			<Integer>	key state value
	Return value:
		x@y - updated key state value
	 */

EXPORT(sqInt) primitiveARC4Transform(void) {
    sqInt a;
    sqInt b;
    sqInt bufOop;
    sqInt bufSize;
    unsigned char *buffer;
    sqInt i;
    unsigned char *m;
    sqInt mOop;
    sqInt mask;
    sqInt ptOop;
    sqInt startIndex;
    sqInt stopIndex;
    sqInt x;
    sqInt xOop;
    sqInt y;
    sqInt yOop;

	if (!((interpreterProxy->methodArgumentCount()) == 6)) {
		return interpreterProxy->primitiveFail();
	}
	y = interpreterProxy->stackIntegerValue(0);
	x = interpreterProxy->stackIntegerValue(1);
	mOop = interpreterProxy->stackObjectValue(2);
	stopIndex = interpreterProxy->stackIntegerValue(3);
	startIndex = interpreterProxy->stackIntegerValue(4);
	bufOop = interpreterProxy->stackObjectValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->isBytes(mOop)) && (interpreterProxy->isBytes(bufOop)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->byteSizeOf(mOop)) == 256)) {
		return interpreterProxy->primitiveFail();
	}
	bufSize = interpreterProxy->byteSizeOf(bufOop);
	if (!((startIndex > 0) && (startIndex <= bufSize))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((stopIndex >= startIndex) && (stopIndex <= bufSize))) {
		return interpreterProxy->primitiveFail();
	}
	m = interpreterProxy->firstIndexableField(mOop);
	buffer = interpreterProxy->firstIndexableField(bufOop);
	for (i = (startIndex - 1); i <= (stopIndex - 1); i += 1) {
		x = (x + 1) & 255;
		a = m[x];
		y = (y + a) & 255;
		b = m[y];
		m[x] = b;
		m[y] = a;
		mask = m[(a + b) & 255];
		buffer[i] = ((buffer[i]) ^ mask);
	}
	ptOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classPoint(), 0);
	interpreterProxy->pushRemappableOop(ptOop);
	xOop = interpreterProxy->positive32BitIntegerFor(x);
	interpreterProxy->pushRemappableOop(xOop);
	yOop = interpreterProxy->positive32BitIntegerFor(y);
	xOop = interpreterProxy->popRemappableOop();
	ptOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, ptOop, xOop);
	interpreterProxy->storePointerofObjectwithValue(1, ptOop, yOop);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	return interpreterProxy->push(ptOop);
}


/*	Computes the adjoint of the Matrix4x4 receiver,
	placing the results the the Matrix4x4 argument,
	 */

EXPORT(sqInt) primitiveAdj3(void) {
    sqInt argc;
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;


	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */

	;
	argc = interpreterProxy->methodArgumentCount();
	if (!(argc == 1)) {
		return interpreterProxy->primitiveFail();
	}
	flag("stackArgv");
	srcOop = interpreterProxy->stackObjectValue(argc);
	src = interpreterProxy->firstIndexableField(srcOop);
	dstOop = interpreterProxy->stackObjectValue(argc - 1);

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */

	dst = interpreterProxy->firstIndexableField(dstOop);
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* do the actual work */
	/* compute our cofactors and transpose.  adj = transpose of cofactors */

	m33 = src[c33];
	dst[c11] = ((m22 * m33) - (m23 * m32));
	dst[c21] = (0.0 - ((m21 * m33) - (m23 * m31)));
	dst[c31] = ((m21 * m32) - (m22 * m31));
	dst[c12] = (0.0 - ((m12 * m33) - (m13 * m32)));
	dst[c22] = ((m11 * m33) - (m13 * m31));
	dst[c32] = (0.0 - ((m11 * m32) - (m12 * m31)));
	dst[c13] = ((m12 * m23) - (m13 * m22));
	dst[c23] = (0.0 - ((m11 * m23) - (m13 * m21)));
	dst[c33] = ((m11 * m22) - (m12 * m21));
	interpreterProxy->pop(argc + 1);
	return interpreterProxy->push(dstOop);
}


/*	Computes the determinant of the upper 3x3 of a Matrix4x4 */

EXPORT(sqInt) primitiveDet3(void) {
    sqInt argc;
    double det;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;

	argc = interpreterProxy->methodArgumentCount();
	if (!(argc == 0)) {
		return interpreterProxy->primitiveFail();
	}
	flag("stackArgv");
	srcOop = interpreterProxy->stackObjectValue(argc);
	src = interpreterProxy->firstIndexableField(srcOop);
	m11 = src[0];
	m12 = src[1];
	m13 = src[2];
	m21 = src[4];
	m22 = src[5];
	m23 = src[6];
	m31 = src[8];
	m32 = src[9];

	/* do the actual work */

	m33 = src[10];
	det = ((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31)));
	interpreterProxy->pop(argc + 1);
	return interpreterProxy->pushFloat(det);
}


/*	Primitive. Gather good random entropy from a system source. */

EXPORT(sqInt) primitiveGatherEntropy(void) {
    sqInt bufOop;
    void *bufPtr;
    sqInt bufSize;
    sqInt okay;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	bufOop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isBytes(bufOop))) {
		return interpreterProxy->primitiveFail();
	}
	bufSize = interpreterProxy->byteSizeOf(bufOop);
	bufPtr = interpreterProxy->firstIndexableField(bufOop);
	okay = ioGatherEntropy(bufPtr, bufSize);
	if (!(okay)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	return interpreterProxy->pushBool(1);
}


/*	Primitive. Perform an inplace house holder matrix inversion */

EXPORT(sqInt) primitiveInplaceHouseHolderInvert(void) {
    double beta;
    double d[4][4];
    sqInt i;
    sqInt j;
    sqInt k;
    double m[4][4];
    sqInt r;
    float *rcvr;
    double s;
    double sigma;
    double sum;
    double x[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };

	;
	rcvr = stackMatrix(0);
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			(m[i])[j] = (rcvr[(i * 4) + j]);
		}
	}
	for (j = 0; j <= 3; j += 1) {
		sigma = 0.0;
		for (i = j; i <= 3; i += 1) {
			sigma += ((m[i])[j]) * ((m[i])[j]);
		}
		if (sigma < 1.0e-10) {
			return interpreterProxy->primitiveFail();
		}
		if (((m[j])[j]) < 0.0) {
			s = sqrt(sigma);
		} else {
			s = 0.0 - (sqrt(sigma));
		}
		for (r = 0; r <= 3; r += 1) {
			(d[j])[r] = s;
		}
		beta = 1.0 / ((s * ((m[j])[j])) - sigma);
		(m[j])[j] = (((m[j])[j]) - s);
		for (k = (j + 1); k <= 3; k += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((m[i])[j]) * ((m[i])[k]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(m[i])[k] = (((m[i])[k]) + (((m[i])[j]) * sum));
			}
		}
		for (r = 0; r <= 3; r += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((x[i])[r]) * ((m[i])[j]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(x[i])[r] = (((x[i])[r]) + (sum * ((m[i])[j])));
			}
		}
	}
	for (r = 0; r <= 3; r += 1) {
		for (i = 3; i >= 0; i += -1) {
			for (j = (i + 1); j <= 3; j += 1) {
				(x[i])[r] = (((x[i])[r]) - (((x[j])[r]) * ((m[i])[j])));
			}
			(x[i])[r] = (((x[i])[r]) / ((d[i])[r]));
		}
	}
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			rcvr[(i * 4) + j] = (((float) ((x[i])[j])));
		}
	}
	return null;
}


/*	Computes the inverse of the Matrix4x4 receiver, using the 'classical adjoint' method,
	placing the results the the Matrix4x4 argument,
	 */

EXPORT(sqInt) primitiveInverseByAdjoint(void) {
    sqInt argc;
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c14 = 3;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c24 = 7;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    const int c34 = 11;
    double det;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;


	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */

	;
	argc = interpreterProxy->methodArgumentCount();
	if (!(argc == 1)) {
		return interpreterProxy->primitiveFail();
	}
	flag("stackArgv");
	srcOop = interpreterProxy->stackObjectValue(argc);
	src = interpreterProxy->firstIndexableField(srcOop);
	dstOop = interpreterProxy->stackObjectValue(argc - 1);

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */

	dst = interpreterProxy->firstIndexableField(dstOop);
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* read in the source translation vector */

	m33 = src[c33];
	x = src[c14];
	y = src[c24];

	/* do the actual work */
	/* first, compute the determinant of the upper 3x3 of the source */

	z = src[c34];

	/* Compute the classical adjunct of the source, and divide by the source determinant
	storing in the destination.  adjoint = transpose of cofactors, so we'll transpose as we store. */

	det = ((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31)));

	/* let's make div by det a multiply */

	det = 1 / det;
	dst[c11] = (((m22 * m33) - (m23 * m32)) * det);
	dst[c21] = ((0.0 - ((m21 * m33) - (m23 * m31))) * det);
	dst[c31] = (((m21 * m32) - (m22 * m31)) * det);
	dst[c12] = ((0.0 - ((m12 * m33) - (m13 * m32))) * det);
	dst[c22] = (((m11 * m33) - (m13 * m31)) * det);
	dst[c32] = ((0.0 - ((m11 * m32) - (m12 * m31))) * det);
	dst[c13] = (((m12 * m23) - (m13 * m22)) * det);
	dst[c23] = ((0.0 - ((m11 * m23) - (m13 * m21))) * det);
	dst[c33] = (((m11 * m22) - (m12 * m21)) * det);
	m11 = dst[c11];
	m12 = dst[c12];
	m13 = dst[c13];
	m21 = dst[c21];
	m22 = dst[c22];
	m23 = dst[c23];
	m31 = dst[c31];
	m32 = dst[c32];
	m33 = dst[c33];
	dst[c14] = (0.0 - (((x * m11) + (y * m12)) + (z * m13)));
	dst[c24] = (0.0 - (((x * m21) + (y * m22)) + (z * m23)));
	dst[c34] = (0.0 - (((x * m31) + (y * m32)) + (z * m33)));
	interpreterProxy->pop(argc + 1);
	return interpreterProxy->push(dstOop);
}


/*	Perform an MD5 transform of input */

EXPORT(sqInt) primitiveMD5Transform(void) {
    sqInt bufOop;
    unsigned int *buffer;
    unsigned int *hash;
    sqInt hashOop;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	hashOop = interpreterProxy->stackObjectValue(0);
	if (!((interpreterProxy->isWords(hashOop)) && ((interpreterProxy->slotSizeOf(hashOop)) == 4))) {
		return interpreterProxy->primitiveFail();
	}
	hash = interpreterProxy->firstIndexableField(hashOop);
	bufOop = interpreterProxy->stackObjectValue(1);
	if (!((interpreterProxy->isWords(bufOop)) && ((interpreterProxy->slotSizeOf(bufOop)) == 16))) {
		return interpreterProxy->primitiveFail();
	}
	buffer = interpreterProxy->firstIndexableField(bufOop);
	MD5Transform(hash, buffer);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	return interpreterProxy->push(bufOop);
}

EXPORT(sqInt) primitiveOrthoNormInverseMatrix(void) {
    float *dst;
    sqInt dstOop;
    double rx;
    double ry;
    double rz;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;

	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	srcOop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->isWords(srcOop)) && ((interpreterProxy->slotSizeOf(srcOop)) == 16))) {
		return interpreterProxy->primitiveFail();
	}

	/* reload srcOop in case of GC */

	dstOop = interpreterProxy->clone(srcOop);
	srcOop = interpreterProxy->stackObjectValue(0);
	src = interpreterProxy->firstIndexableField(srcOop);

	/* Transpose upper 3x3 matrix */
	/* dst at: 0 put: (src at: 0). */

	dst = interpreterProxy->firstIndexableField(dstOop);
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	x = src[3];
	y = src[7];
	z = src[11];
	rx = ((x * (dst[0])) + (y * (dst[1]))) + (z * (dst[2]));
	ry = ((x * (dst[4])) + (y * (dst[5]))) + (z * (dst[6]));
	rz = ((x * (dst[8])) + (y * (dst[9]))) + (z * (dst[10]));
	dst[3] = (((float) (0.0 - rx)));
	dst[7] = (((float) (0.0 - ry)));
	dst[11] = (((float) (0.0 - rz)));
	interpreterProxy->pop(1);
	return interpreterProxy->push(dstOop);
}

EXPORT(sqInt) primitiveTransformDirection(void) {
    float *matrix;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	v3Oop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->isWords(v3Oop)) && ((interpreterProxy->slotSizeOf(v3Oop)) == 3))) {
		return interpreterProxy->primitiveFail();
	}
	vertex = interpreterProxy->firstIndexableField(v3Oop);
	matrix = stackMatrix(1);
	if (matrix == null) {
		return interpreterProxy->primitiveFail();
	}
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = ((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]));
	ry = ((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]));
	rz = ((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]));
	v3Oop = interpreterProxy->clone(v3Oop);
	vertex = interpreterProxy->firstIndexableField(v3Oop);
	vertex[0] = (((float) rx));
	vertex[1] = (((float) ry));
	vertex[2] = (((float) rz));
	interpreterProxy->pop(2);
	return interpreterProxy->push(v3Oop);
}


/*	Transform two matrices into the third */

EXPORT(sqInt) primitiveTransformMatrixWithInto(void) {
    float *m1;
    float *m2;
    float *m3;

	m3 = stackMatrix(0);
	m2 = stackMatrix(1);
	m1 = stackMatrix(2);
	if (((m1 == null) || (m2 == null)) || (m3 == null)) {
		return interpreterProxy->primitiveFail();
	}
	if (m2 == m3) {
		return interpreterProxy->primitiveFail();
	}
	transformMatrixwithinto(m1, m2, m3);
	return interpreterProxy->pop(3);
}

EXPORT(sqInt) primitiveTransformVector3(void) {
    float *matrix;
    double rw;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	v3Oop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->isWords(v3Oop)) && ((interpreterProxy->slotSizeOf(v3Oop)) == 3))) {
		return interpreterProxy->primitiveFail();
	}
	vertex = interpreterProxy->firstIndexableField(v3Oop);
	matrix = stackMatrix(1);
	if (matrix == null) {
		return interpreterProxy->primitiveFail();
	}
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = (((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]))) + (matrix[3]);
	ry = (((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]))) + (matrix[7]);
	rz = (((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]))) + (matrix[11]);
	rw = (((x * (matrix[12])) + (y * (matrix[13]))) + (z * (matrix[14]))) + (matrix[15]);
	v3Oop = interpreterProxy->clone(v3Oop);
	vertex = interpreterProxy->firstIndexableField(v3Oop);
	if (rw == 1.0) {
		vertex[0] = (((float) rx));
		vertex[1] = (((float) ry));
		vertex[2] = (((float) rz));
	} else {
		if (rw == 0.0) {
			rw = 0.0;
		} else {
			rw = 1.0 / rw;
		}
		vertex[0] = (((float) (rx * rw)));
		vertex[1] = (((float) (ry * rw)));
		vertex[2] = (((float) (rz * rw)));
	}
	interpreterProxy->pop(2);
	return interpreterProxy->push(v3Oop);
}

EXPORT(sqInt) primitiveTransposeMatrix(void) {
    float *dst;
    sqInt dstOop;
    float *src;
    sqInt srcOop;

	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	srcOop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->isWords(srcOop)) && ((interpreterProxy->slotSizeOf(srcOop)) == 16))) {
		return interpreterProxy->primitiveFail();
	}

	/* reload srcOop in case of GC */

	dstOop = interpreterProxy->clone(srcOop);
	srcOop = interpreterProxy->stackObjectValue(0);
	src = interpreterProxy->firstIndexableField(srcOop);

	/* dst at: 0 put: (src at: 0). */

	dst = interpreterProxy->firstIndexableField(dstOop);
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[3] = (src[12]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[7] = (src[13]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	dst[11] = (src[14]);
	dst[12] = (src[3]);
	dst[13] = (src[7]);
	dst[14] = (src[11]);
	interpreterProxy->pop(1);
	return interpreterProxy->push(dstOop);
}


/*	Primitive. Answer whether an AABB intersects with a given triangle */

EXPORT(sqInt) primitiveTriBoxIntersects(void) {
    float *maxCorner;
    float *minCorner;
    sqInt result;
    float *v0;
    float *v1;
    float *v2;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	v2 = stackVector3(0);
	v1 = stackVector3(1);
	v0 = stackVector3(2);
	maxCorner = stackVector3(3);
	minCorner = stackVector3(4);
	result = triBoxOverlap(minCorner, maxCorner, v0, v1, v2);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(6);
	return interpreterProxy->pushBool(result);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


/*	Load a 4x4 transformation matrix from the interpreter stack.
	Return a pointer to the matrix data if successful, nil otherwise. */

static void* stackMatrix(sqInt index) {
    sqInt oop;

	oop = interpreterProxy->stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if ((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 16)) {
		return interpreterProxy->firstIndexableField(oop);
	}
	return null;
}


/*	Load a Vector3 from the interpreter stack.
	Return a pointer to the float data if successful, nil otherwise. */

static void* stackVector3(sqInt index) {
    sqInt oop;

	oop = interpreterProxy->stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if ((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 3)) {
		return interpreterProxy->firstIndexableField(oop);
	}
	return null;
}


/*	Transform src with arg into dst.
	It is allowed that src == dst but not arg == dst */

static sqInt transformMatrixwithinto(float *src, float *arg, float *dst) {
    double c1;
    double c2;
    double c3;
    double c4;
    sqInt i;
    float *m1;
    float *m2;
    float *m3;

	m1 = ((float *) src);
	m2 = ((float *) arg);
	m3 = ((float *) dst);
	for (i = 0; i <= 3; i += 1) {

		/* Compute next row */

		c1 = ((((((double) (m1[0]) )) * (((double) (m2[0]) ))) + ((((double) (m1[1]) )) * (((double) (m2[4]) )))) + ((((double) (m1[2]) )) * (((double) (m2[8]) )))) + ((((double) (m1[3]) )) * (((double) (m2[12]) )));
		c2 = ((((((double) (m1[0]) )) * (((double) (m2[1]) ))) + ((((double) (m1[1]) )) * (((double) (m2[5]) )))) + ((((double) (m1[2]) )) * (((double) (m2[9]) )))) + ((((double) (m1[3]) )) * (((double) (m2[13]) )));
		c3 = ((((((double) (m1[0]) )) * (((double) (m2[2]) ))) + ((((double) (m1[1]) )) * (((double) (m2[6]) )))) + ((((double) (m1[2]) )) * (((double) (m2[10]) )))) + ((((double) (m1[3]) )) * (((double) (m2[14]) )));

		/* Store result */

		c4 = ((((((double) (m1[0]) )) * (((double) (m2[3]) ))) + ((((double) (m1[1]) )) * (((double) (m2[7]) )))) + ((((double) (m1[2]) )) * (((double) (m2[11]) )))) + ((((double) (m1[3]) )) * (((double) (m2[15]) )));
		m3[0] = c1;
		m3[1] = c2;
		m3[2] = c3;
		m3[3] = c4;
		m1 += 4;
		m3 += 4;
	}
	return null;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* CroquetPlugin_exports[][3] = {
	{"CroquetPlugin", "getModuleName", (void*)getModuleName},
	{"CroquetPlugin", "primitiveInverseByAdjoint", (void*)primitiveInverseByAdjoint},
	{"CroquetPlugin", "primitiveTransformDirection", (void*)primitiveTransformDirection},
	{"CroquetPlugin", "primitiveARC4Transform", (void*)primitiveARC4Transform},
	{"CroquetPlugin", "primitiveAdj3", (void*)primitiveAdj3},
	{"CroquetPlugin", "primitiveTransformMatrixWithInto", (void*)primitiveTransformMatrixWithInto},
	{"CroquetPlugin", "primitiveOrthoNormInverseMatrix", (void*)primitiveOrthoNormInverseMatrix},
	{"CroquetPlugin", "setInterpreter", (void*)setInterpreter},
	{"CroquetPlugin", "primitiveTransformVector3", (void*)primitiveTransformVector3},
	{"CroquetPlugin", "primitiveTransposeMatrix", (void*)primitiveTransposeMatrix},
	{"CroquetPlugin", "primitiveDet3", (void*)primitiveDet3},
	{"CroquetPlugin", "primitiveTriBoxIntersects", (void*)primitiveTriBoxIntersects},
	{"CroquetPlugin", "primitiveMD5Transform", (void*)primitiveMD5Transform},
	{"CroquetPlugin", "primitiveGatherEntropy", (void*)primitiveGatherEntropy},
	{"CroquetPlugin", "primitiveInplaceHouseHolderInvert", (void*)primitiveInplaceHouseHolderInvert},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

