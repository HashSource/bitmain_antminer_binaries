
void x509_name_ex_free(undefined4 *param_1)

{
  undefined4 *ptr;
  
  if ((param_1 != (undefined4 *)0x0) && (ptr = (undefined4 *)*param_1, ptr != (undefined4 *)0x0)) {
    BUF_MEM_free((BUF_MEM *)ptr[2]);
    sk_pop_free((_STACK *)*ptr,(func *)0xb7535);
    if ((void *)ptr[3] != (void *)0x0) {
      CRYPTO_free((void *)ptr[3]);
    }
    CRYPTO_free(ptr);
    *param_1 = 0;
  }
  return;
}

