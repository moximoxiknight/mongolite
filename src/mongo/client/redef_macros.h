//K:Version8
/** @file redef_macros.h macros for mongo internals
    
    @see undef_macros.h undefines these after use to minimize name pollution.
*/


// If you define a new global un-prefixed macro, please add it here and in undef_macros

//Knight
//#include "mongo/util/allocator.h"

#pragma once

#include "mongo/util/signal_handlers.h"
#include "mongo/client/undef_macros.h"

namespace mongo {

inline void * ourmalloc(size_t size) {
	void *x = malloc(size);
	if ( x == 0 ) printStackAndExit(0);
	return x;
}

inline void * ourrealloc(void *ptr, size_t size) {
	void *x = realloc(ptr, size);
	if ( x == 0 ) printStackAndExit(0);
	return x;
}

#define MONGO_malloc mongo::ourmalloc
#define MONGO_realloc mongo::ourrealloc

//K: delete code below
// this redefines 'malloc' to 'MONGO_malloc', etc
//#include "mongo/client/redef_macros.h"

} // namespace mongo


#define MONGO_MACROS_PUSHED 1

// util/allocator.h
#pragma push_macro("malloc")
#undef malloc
#define malloc MONGO_malloc
#pragma push_macro("realloc")
#undef realloc
#define realloc MONGO_realloc

// util/assert_util.h
#pragma push_macro("verify")
#undef verify
#define verify MONGO_verify
#pragma push_macro("dassert")
#undef dassert
#define dassert MONGO_dassert
#pragma push_macro("wassert")
#undef wassert
#define wassert MONGO_wassert
#pragma push_macro("massert")
#undef massert
#define massert MONGO_massert
#pragma push_macro("uassert")
#undef uassert
#define uassert MONGO_uassert
#pragma push_macro("DESTRUCTOR_GUARD")
#undef DESTRUCTOR_GUARD
#define DESTRUCTOR_GUARD MONGO_DESTRUCTOR_GUARD

// util/goodies.h
#pragma push_macro("PRINT")
#undef PRINT
#define PRINT MONGO_PRINT
#pragma push_macro("PRINTFL")
#undef PRINTFL
#define PRINTFL MONGO_PRINTFL

// util/debug_util.h
#pragma push_macro("DEV")
#undef DEV
#define DEV MONGO_DEV
#pragma push_macro("DEBUGGING")
#undef DEBUGGING
#define DEBUGGING MONGO_DEBUGGING
#pragma push_macro("SOMETIMES")
#undef SOMETIMES
#define SOMETIMES MONGO_SOMETIMES
#pragma push_macro("OCCASIONALLY")
#undef OCCASIONALLY
#define OCCASIONALLY MONGO_OCCASIONALLY
#pragma push_macro("RARELY")
#undef RARELY
#define RARELY MONGO_RARELY
#pragma push_macro("ONCE")
#undef ONCE
#define ONCE MONGO_ONCE

// util/log.h
#pragma push_macro("LOG")
#undef LOG
#define LOG MONGO_LOG


