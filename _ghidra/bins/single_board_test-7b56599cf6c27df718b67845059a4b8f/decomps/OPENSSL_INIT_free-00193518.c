
void OPENSSL_INIT_free(undefined4 *param_1)

{
  free((void *)*param_1);
  free((void *)param_1[1]);
  (*(code *)(undefined *)0x0)(param_1);
  return;
}

