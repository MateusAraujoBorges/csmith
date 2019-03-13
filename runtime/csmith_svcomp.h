#ifndef CSMITH_SVCOMP_H
#define CSMITH_SVCOMP_H

/**
 * Most of the stuff here is copied from csmith_minimal.h
 */

#define int8_t signed char
#define uint8_t unsigned char

#define int16_t short
#define uint16_t unsigned short

#define int32_t int
#define uint32_t unsigned

#define int64_t long long
#define uint64_t unsigned long long

/* Limits of integral types.  */

/* Minimum of signed integral types.  */
# define INT8_MIN		(-128)
# define INT16_MIN		(-32767-1)
# define INT32_MIN		(-2147483647-1)
#ifndef NO_LONGLONG
# define INT64_MIN		(-(9223372036854775807LL)-1)
#endif
/* Maximum of signed integral types.  */
# define INT8_MAX		(127)
# define INT16_MAX		(32767)
# define INT32_MAX		(2147483647)
#ifndef NO_LONGLONG
# define INT64_MAX		(9223372036854775807LL)
#endif

/* Maximum of unsigned integral types.  */
# define UINT8_MAX		(255)
# define UINT16_MAX		(65535)
# define UINT32_MAX		(4294967295U)
#ifndef NO_LONGLONG
# define UINT64_MAX		(18446744073709551615ULL)
#endif

#  define CHAR_BIT	8

/* Limits of FP types.  */

#define FLT_MAX 3.40282347e+38F
#define DBL_MAX 1.7976931348623158e+308

static inline void platform_main_begin(void)
{
}

static inline void crc32_gentab (void)
{
}

static inline void 
transparent_crc (uint64_t val, char* vname, int flag)
{
}

static void 
transparent_crc_bytes (char *ptr, int nbytes, char* vname, int flag)
{
}

void put_hex (int x)
{
  switch (x) {
  case 0x0: putchar ('0'); break;
  case 0x1: putchar ('1'); break;
  case 0x2: putchar ('2'); break;
  case 0x3: putchar ('3'); break;
  case 0x4: putchar ('4'); break;
  case 0x5: putchar ('5'); break;
  case 0x6: putchar ('6'); break;
  case 0x7: putchar ('7'); break;
  case 0x8: putchar ('8'); break;
  case 0x9: putchar ('9'); break;
  case 0xa: putchar ('a'); break;
  case 0xb: putchar ('b'); break;
  case 0xc: putchar ('c'); break;
  case 0xd: putchar ('d'); break;
  case 0xe: putchar ('e'); break;
  case 0xf: putchar ('f'); break;
  }
}

static inline void
platform_main_end (uint64_t x, int flag)
{
}

#endif /* CSMITH_SVCOMP_H */
