
void delete_clib_object(void **param_1)

{
  if (param_1 != (void **)0x0) {
    free(*param_1);
    free(param_1);
  }
  return;
}

