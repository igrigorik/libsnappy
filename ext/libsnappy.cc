#include <ruby.h>
#include <snappy.h>

using namespace snappy;

typedef VALUE (ruby_method)(...);

extern "C" VALUE compress(VALUE self, VALUE input, VALUE length) {
 string *out = new string();
 char *in = StringValuePtr(input);
 size_t sz = snappy::Compress(in, NUM2INT(length), out);
 VALUE ret = rb_str_new(out->c_str(), sz);
 delete out;
 return ret;
}

extern "C" VALUE uncompress(VALUE self, VALUE input, VALUE length) {
 VALUE ret;
 string *out = new string();
 char* str = StringValuePtr(input);
 bool pass = snappy::Uncompress(str, NUM2INT(length), out);

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
   rb_define_singleton_method(RSnappy, "compress", (ruby_method*) &compress, 2);
   rb_define_singleton_method(RSnappy, "uncompress", (ruby_method*) &uncompress, 2);
}