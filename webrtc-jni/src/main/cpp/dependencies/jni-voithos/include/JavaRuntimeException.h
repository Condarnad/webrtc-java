/*
 * Copyright (c) 2019, Alex Andres. All rights reserved.
 *
 * Use of this source code is governed by the 3-Clause BSD license that can be
 * found in the LICENSE file in the root of the source tree.
 */

#ifndef JNI_JAVA_RUNTIME_EXCEPTION_H_
#define JNI_JAVA_RUNTIME_EXCEPTION_H_

#include "JavaThrowable.h"

#include <jni.h>

namespace jni
{
	class JavaRuntimeException : public JavaThrowable
	{
		private:
			class JavaRuntimeExceptionClass : public JavaThrowableClass
			{
				public:
					JavaRuntimeExceptionClass(JNIEnv * env) :
						JavaThrowableClass(env, "java/lang/RuntimeException")
					{
					}
			};

		public:
			template <typename... Args>
			JavaRuntimeException(JNIEnv * env, const char * message, Args &&... args) :
				JavaThrowable(env, message, std::forward<Args>(args)...)
			{
			}

			operator jthrowable() const override
			{
				return createThrowable<JavaRuntimeExceptionClass>();
			}
	};
}

#endif