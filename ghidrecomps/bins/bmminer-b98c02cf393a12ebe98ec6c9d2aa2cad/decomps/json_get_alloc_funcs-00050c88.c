
void json_get_alloc_funcs(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = do_malloc;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = do_free;
  }
  return;
}

