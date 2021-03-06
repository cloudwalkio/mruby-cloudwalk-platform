#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

mrb_value
mrb_magnetic_s_open(mrb_state *mrb, mrb_value self)
{
  mrb_int ret;

  /*TODO Implement*/

  return mrb_fixnum_value(ret);
}

mrb_value
mrb_magnetic_s_read(mrb_state *mrb, mrb_value self)
{
  mrb_int ret;

  /*TODO Implement*/

  return mrb_fixnum_value(ret);
}

mrb_value
mrb_magnetic_s_close(mrb_state *mrb, mrb_value self)
{
  /*TODO Implement*/

  return mrb_nil_value();
}

/*{:track1 => "", :track2 => "", :track3 => ""}*/
mrb_value
mrb_magnetic_s_tracks(mrb_state *mrb, mrb_value self)
{
  mrb_value hash;

  /*TODO Implement*/

  hash = mrb_hash_new(mrb);
  mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track1")), mrb_str_new_cstr(mrb, "track1 information"));
  mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track2")), mrb_str_new_cstr(mrb, "track2 information"));
  mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track3")), mrb_str_new_cstr(mrb, "track3 information"));

  return hash;
}

void
mrb_magnetic_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *magnetic;

  platform = mrb_class_get(mrb, "Platform");
  magnetic = mrb_define_class_under(mrb, platform, "Magnetic", mrb->object_class);

  mrb_define_class_method(mrb , magnetic , "open"      , mrb_magnetic_s_open      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , magnetic , "read"      , mrb_magnetic_s_read      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , magnetic , "close"     , mrb_magnetic_s_close     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , magnetic , "tracks"    , mrb_magnetic_s_tracks    , MRB_ARGS_REQ(1));
}

