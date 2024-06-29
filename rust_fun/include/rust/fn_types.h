/*
** EPITECH PROJECT, 2024
** errors
** File description:
** yo
*/

#pragma once
#include <stdbool.h>
#include "version.h"

#define TYPESFN_VERSION VERSION

#define PRINT(x) typeof(x)##print(x)

void panic(void *error, char *file, int line);
#define PANIC(msg) panic(msg, __FILE__, __LINE__)

#define OPTION(t) struct{t val;bool is_none;}

#define SOME(v) ((typeof(fn_info.rt)){.val = (v), .is_none = false})
#define NONE ((typeof(fn_info.rt)){.is_none = true})

#define MATCH_OPTION(opt, some, svar, none) ({LET o = (opt); if (o.is_none) {none}; else {LET svar = o.val;some};})

#define RESULT(ok_t, err_t) struct{union{ok_t ok;err_t err;};bool is_err;}
#define OK(val) ((typeof(fn_info.rt)){.ok = (val), .is_err = false})
#define ERR(val) ((typeof(fn_info.rt)){.err = (val), .is_err = true})

#define MATCH_RESULT(res, ok, ovar, err, evar) ({LET r = (res); if (r.is_err) {LET evar = r.err;err;} else {LET ovar = r.ok;ok;}})

#define EXPECT(res, msg) ({LET r = (res); r.is_err ? (PANIC(msg), r.ok) : r.ok;})
#define UNWRAP(res) EXPECT(res, "expect ok")
#define EXPECT_ERR(res, msg) ({LET r = (res); r.is_err ? r.err : (PANIC(msg), r.err);})
#define UNWRAP_ERR(res) EXPECT_ERR(res, "expect err")
#define TRY(res) ({LET r = (res); if (r.is_err) return ERR(r.err); r.ok;})

#define LET const LET_MUT
#define LET_MUT __auto_type

#define FN_DATA(name, args, ret) struct {name##_rt rt; name##_rt (*fn) args;} fn_info = {.fn = name}
#define FN_C_HEADER(name, args, ret, scope) scope name##_rt name args
#define FN_HEADER(name, args, ret, scope) typedef ret name##_rt; FN_C_HEADER(name, args, ret, scope)
#define FN_BODY(name, args, ret, ...)  { FN_DATA(name, args, FN_RT(name)); return ({__VA_ARGS__}); }

#define FN_DECL(name, args, ret) FN_HEADER(name, args, ret, extern)
#define PUB_FN(name, args, ret, ...) FN_C_HEADER(name, args, ret,)FN_BODY(name, args, ret, __VA_ARGS__)

#define FN(name, args, ret, ...) FN_HEADER(name,args,ret,static) FN_BODY(name, args, ret, __VA_ARGS__)
#define FN_RT(name) name##_rt
