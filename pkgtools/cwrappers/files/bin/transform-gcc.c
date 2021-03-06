#include <stdlib.h>

static uint32_t
transform_cc_fixed(const void * __restrict key, size_t keylen)
{
	static const uint8_t g[221] = {
	    0x00, 0x28, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	    0x60, 0x29, 0x63, 0x10, 0x00, 0x2c, 0x57, 0x0e, 0x26, 0x00,
	    0x2c, 0x00, 0x2a, 0x00, 0x2d, 0x00, 0x00, 0x67, 0x2e, 0x00,
	    0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x1b, 0x4e, 0x00,
	    0x00, 0x00, 0x00, 0x1c, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
	    0x21, 0x55, 0x0b, 0x20, 0x00, 0x46, 0x00, 0x00, 0x4d, 0x3e,
	    0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x5f, 0x22, 0x00,
	    0x42, 0x58, 0x14, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x41, 0x07,
	    0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00,
	    0x42, 0x00, 0x00, 0x40, 0x04, 0x4e, 0x09, 0x00, 0x00, 0x00,
	    0x42, 0x67, 0x00, 0x20, 0x34, 0x68, 0x39, 0x00, 0x69, 0x00,
	    0x00, 0x00, 0x00, 0x21, 0x00, 0x31, 0x17, 0x00, 0x00, 0x3d,
	    0x38, 0x5b, 0x00, 0x61, 0x00, 0x55, 0x00, 0x00, 0x3b, 0x4b,
	    0x55, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x44,
	    0x00, 0x6d, 0x00, 0x5c, 0x06, 0x3e, 0x00, 0x4d, 0x45, 0x59,
	    0x39, 0x2c, 0x00, 0x45, 0x00, 0x00, 0x6d, 0x00, 0x0b, 0x00,
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x63,
	    0x00, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x1a, 0x5f,
	    0x1e, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x57, 0x2a,
	    0x5f, 0x38, 0x5a, 0x00, 0x08, 0x2f, 0x30, 0x00, 0x00, 0x64,
	    0x18, 0x00, 0x51, 0x20, 0x00, 0x0d, 0x00, 0x55, 0x18, 0x15,
	    0x48, 0x00, 0x00, 0x4f, 0x37, 0x58, 0x00, 0x62, 0x1d, 0x00,
	    0x05,
	};
	uint32_t h[3];

	mi_vector_hash(key, keylen, 0x327b23c6U, h);
	return (g[h[0] % 221] + g[h[1] % 221]) % 110;
}

static struct transformation fixed_transforms[] = {
	{ "-E", 2, transform_pass, NULL },
	{ "-O", 2, transform_pass, NULL },
	{ "-O0", 3, transform_pass, NULL },
	{ "-O1", 3, transform_pass, NULL },
	{ "-c", 2, transform_pass, NULL },
	{ "-g", 2, transform_pass, NULL },
	{ "-o", 2, transform_pass, NULL },
	{ "-s", 2, transform_pass, NULL },
	{ "-V", 2, transform_pass, NULL },
	{ "-v", 2, transform_pass, NULL },
	{ "--version", 9, transform_pass, NULL },
	{ "-", 1, transform_pass, NULL },
	{ "-dynamic", 8, transform_pass, NULL },
	{ "-export-dynamic", 15, transform_pass, NULL },
	{ "-fexpensive-options", 19, transform_pass, NULL },
	{ "-ffast-math", 11, transform_pass, NULL },
	{ "-ffloat-store", 13, transform_pass, NULL },
	{ "-finline-functions", 18, transform_pass, NULL },
	{ "-fno-builtin", 12, transform_pass, NULL },
	{ "-fno-common", 11, transform_pass, NULL },
	{ "-fno-implicit-templates", 23, transform_pass, NULL },
	{ "-fno-inline-functions", 21, transform_pass, NULL },
	{ "-fno-strict-aliasing", 20, transform_pass, NULL },
	{ "-fomit-frame-pointer", 20, transform_pass, NULL },
	{ "-fPIC", 5, transform_pass, NULL },
	{ "-fpic", 5, transform_pass, NULL },
	{ "-fpcc-struct-return", 19, transform_pass, NULL },
	{ "-freg-struct-return", 19, transform_pass, NULL },
	{ "-fsigned-char", 13, transform_pass, NULL },
	{ "-funroll-loops", 14, transform_pass, NULL },
	{ "-funsigned-char", 15, transform_pass, NULL },
	{ "-ggdb", 5, transform_pass, NULL },
	{ "-M", 2, transform_pass, NULL },
	{ "-MD", 3, transform_pass, NULL },
	{ "-MF", 3, transform_pass, NULL },
	{ "-MM", 3, transform_pass, NULL },
	{ "-MMD", 4, transform_pass, NULL },
	{ "-MP", 3, transform_pass, NULL },
	{ "-MT", 3, transform_pass, NULL },
	{ "-m32", 4, transform_pass, NULL },
	{ "-m64", 4, transform_pass, NULL },
	{ "-mieee-fp", 9, transform_pass, NULL },
	{ "-O2", 3, transform_pass, NULL },
	{ "-O3", 3, transform_pass, NULL },
	{ "-Os", 3, transform_pass, NULL },
	{ "-pedantic", 9, transform_pass, NULL },
	{ "-pedantic-errors", 16, transform_pass, NULL },
	{ "-pipe", 5, transform_pass, NULL },
	{ "-pthread", 8, transform_pass, NULL },
	{ "-print-search-dirs", 18, transform_pass, NULL },
	{ "-S", 2, transform_pass, NULL },
	{ "-shared", 7, transform_pass, NULL },
	{ "-static", 7, transform_pass, NULL },
	{ "-std=c99", 8, transform_pass, NULL },
	{ "-std=gnu89", 10, transform_pass, NULL },
	{ "-std=gnu99", 10, transform_pass, NULL },
	{ "-W", 2, transform_pass, NULL },
	{ "-Wall", 5, transform_pass, NULL },
	{ "-Wcast-align", 12, transform_pass, NULL },
	{ "-Wcast-qual", 11, transform_pass, NULL },
	{ "-Wchar-subscripts", 17, transform_pass, NULL },
	{ "-Wconversion", 12, transform_pass, NULL },
	{ "-Wextra", 7, transform_pass, NULL },
	{ "-Werror", 7, transform_pass, NULL },
	{ "-Werror-implicit-function-declaration", 37, transform_pass, NULL },
	{ "-Wformat=0", 10, transform_pass, NULL },
	{ "-Wformat=1", 10, transform_pass, NULL },
	{ "-Wformat=2", 10, transform_pass, NULL },
	{ "-Wmissing-declarations", 22, transform_pass, NULL },
	{ "-Wmissing-format-attribute", 26, transform_pass, NULL },
	{ "-Wmissing-prototypes", 20, transform_pass, NULL },
	{ "-Wnested-externs", 16, transform_pass, NULL },
	{ "-Wno-error", 10, transform_pass, NULL },
	{ "-Wno-format-y2k", 15, transform_pass, NULL },
	{ "-Wno-format-zero-length", 23, transform_pass, NULL },
	{ "-Wno-implicit-int", 17, transform_pass, NULL },
	{ "-Wno-import", 11, transform_pass, NULL },
	{ "-Wno-inline", 11, transform_pass, NULL },
	{ "-Wno-long-long", 14, transform_pass, NULL },
	{ "-Wno-sign-compare", 17, transform_pass, NULL },
	{ "-Wno-traditional", 16, transform_pass, NULL },
	{ "-Wno-undef", 10, transform_pass, NULL },
	{ "-Wno-uninitialized", 18, transform_pass, NULL },
	{ "-Wno-unused", 11, transform_pass, NULL },
	{ "-Wno-unused-parameter", 21, transform_pass, NULL },
	{ "-Wno-write-strings", 18, transform_pass, NULL },
	{ "-Wparentheses", 13, transform_pass, NULL },
	{ "-Wpointer-arith", 15, transform_pass, NULL },
	{ "-Wreturn-type", 13, transform_pass, NULL },
	{ "-Wshadow", 8, transform_pass, NULL },
	{ "-Wsign-compare", 14, transform_pass, NULL },
	{ "-Wstrict-aliasing", 17, transform_pass, NULL },
	{ "-Wstrict-prototypes", 19, transform_pass, NULL },
	{ "-Wswitch", 8, transform_pass, NULL },
	{ "-Wunused", 8, transform_pass, NULL },
	{ "-Wundef", 7, transform_pass, NULL },
	{ "-Wwrite-strings", 15, transform_pass, NULL },
	{ "-w", 2, transform_discard, NULL },
	{ "-fexceptions", 12, transform_pass, NULL },
	{ "-fno-check-new", 14, transform_pass, NULL },
	{ "-fno-exceptions", 15, transform_pass, NULL },
	{ "-fno-rtti", 9, transform_pass, NULL },
	{ "-Wno-non-virtual-dtor", 21, transform_pass, NULL },
	{ "-fgnu-runtime", 13, transform_pass, NULL },
	{ "-mt", 3, transform_discard, NULL },
	{ "-Kpic", 5, transform_replace, "-fPIC" },
	{ "-kpic", 5, transform_replace, "-fPIC" },
	{ "-KPIC", 5, transform_replace, "-fPIC" },
	{ "-kPIC", 5, transform_replace, "-fPIC" },
	{ "-64", 3, transform_replace, "-m64" },
};

static struct transformation var_transforms[] = {
	{ "-D", 2, transform_pass, NULL },
	{ "-I", 2, transform_pass, NULL },
	{ "-L", 2, transform_pass, NULL },
	{ "-U", 2, transform_pass, NULL },
	{ "-falign-functions=", 18, transform_pass, NULL },
	{ "-falign-loops=", 14, transform_pass, NULL },
	{ "-falign-jumps=", 14, transform_pass, NULL },
	{ "-fno-builtin-", 13, transform_pass, NULL },
	{ "-mabi=", 6, transform_pass, NULL },
	{ "-march=", 7, transform_pass, NULL },
	{ "-mcpu=", 6, transform_pass, NULL },
	{ "-print-prog-name=", 17, transform_pass, NULL },
	{ "-WL,", 4, transform_pass, NULL },
	{ "-WS,", 4, transform_pass, NULL },
	{ "-Wc,", 4, transform_pass, NULL },
	{ "-Wl,", 4, transform_pass, NULL },
	{ "-fmessage-length=", 17, transform_pass, NULL },
	{ "-ftemplate-depth=", 17, transform_pass, NULL },
	{ "-fconstant-string-class=", 24, transform_pass, NULL },
	{ "-", 1, transform_pass_with_warning, NULL },
	{ NULL, 0, NULL, NULL },
};
