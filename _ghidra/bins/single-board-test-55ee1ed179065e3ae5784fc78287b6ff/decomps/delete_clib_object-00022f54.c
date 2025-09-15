
void delete_clib_object(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    free((void *)*param_1);
    free(param_1);
  }
  return;
}

