/** 
 *  @file		Debug.h
 *  @brief     
 *  @details   
 *  @author    	Emile
 *  @date      	2013-07-27
 *  @pre       
 *  @bug       
 *  @warning   
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef DEBUG

#include <stdio.h>
#ifndef __FUNCTION_NAME__
#ifdef WIN32   //WINDOWS
#define __FUNCTION_NAME__   __FUNCTION__
#else          //*NIX
#define __FUNCTION_NAME__   __func__
#endif /* #ifdef WIN32   //WINDOWS */
#endif /* #ifndef __FUNCTION_NAME__ */

#define DEBUG_PRINT(fmt, ...) do { fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __FUNCTION_NAME__, __VA_ARGS__); fflush(stderr); } while (0)
#define D(x) do { x; } while (0)
#define TEST_STR "test string"

#else
#define DEBUG_PRINT(fmt, ...) do { } while (0)
#define D(x) do {} while (0)
#endif /* DEBUG VAR */

#endif /* DEBUG_H_ */
