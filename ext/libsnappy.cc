#include <ruby.h>
#include <snappy.h>

using namespace snappy;

typedef VALUE (ruby_method)(...);

extern "C" VALUE compress(VALUE self, VALUE input) {
 string *out = new string();

 size_t sz = snappy::Compress(RSTRING_PTR(input), RSTRING_LEN(input), out);
 VALUE ret = rb_str_new(out->c_str(), sz);
 delete out;

 return ret;
}

extern "C" VALUE uncompress(VALUE self, VALUE input) {
 VALUE ret;
 string *out = new string();

 bool pass = snappy::Uncompress(RSTRING_PTR(input), RSTRING_LEN(input), out);

 if (pass)
   ret = rb_str_new(out->c_str(), out->length());
 else
   ret = Qnil;

 delete out;
 return ret;
}

static VALUE RSnappy;

extern "C" void Init_libsnappy()
{
   RSnappy = rb_define_class("Snappy", rb_cObject);
   rb_define_singleton_method(RSnappy, "compress", (ruby_method*) &compress, 1);
   rb_define_singleton_method(RSnappy, "uncompress", (ruby_method*) &uncompress, 1);
}