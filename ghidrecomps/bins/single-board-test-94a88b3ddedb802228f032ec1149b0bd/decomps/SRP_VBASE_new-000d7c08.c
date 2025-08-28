
undefined4 * SRP_VBASE_new(char *param_1)

{
  undefined4 *ptr;
  _STACK *p_Var1;
  char *pcVar2;
  undefined4 *puVar3;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x14,"srp_vfy.c",0xfc);
  puVar3 = ptr;
  if (ptr != (undefined4 *)0x0) {
    p_Var1 = sk_new_null();
    *ptr = p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = sk_new_null();
      ptr[1] = p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        ptr[3] = 0;
        ptr[4] = 0;
        ptr[2] = 0;
        if (param_1 == (char *)0x0) {
          return ptr;
        }
        pcVar2 = BUF_strdup(param_1);
        ptr[2] = pcVar2;
        if (pcVar2 != (char *)0x0) {
          return ptr;
        }
        sk_free((_STACK *)*ptr);
        sk_free((_STACK *)ptr[1]);
        CRYPTO_free(ptr);
        return (undefined4 *)0x0;
      }
    }
    puVar3 = (undefined4 *)0x0;
    CRYPTO_free(ptr);
  }
  return puVar3;
}

