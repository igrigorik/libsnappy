#include "rice/Class.hpp"
#include "snappy.h"

using namespace Rice;

Object compress(Object v) {
  String input = from_ruby<snappy::string>(v);
  snappy::string output;

  snappy::Compress(input.c_str(), input.length(), &output);
  String out = to_ruby<snappy::string>(output);

  return out;
}

Object uncompress(Object v) {
  String input = from_ruby<snappy::string>(v);
  snappy::string output;

  snappy::Uncompress(input.c_str(), input.length(), &output);
  String out = to_ruby<snappy::string>(output);

  return out;
}

extern "C"

void Init_snappy() {
  Rice::Module rb_mSnappy = define_module("Snappy")
    .define_singleton_method("compress", &compress)
    .define_singleton_method("uncompress", &uncompress);
}