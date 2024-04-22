
undefined4 x509_name_ex_new(void **param_1)

{
  _STACK **ptr;
  _STACK *p_Var1;
  
  ptr = (_STACK **)CRYPTO_malloc(0x14,DAT_000b7530,0x88);
  if (ptr == (_STACK **)0x0) {
    ERR_put_error(0xd,0xab,0x41,DAT_000b7530,0x96);
  }
  else {
    p_Var1 = sk_new_null();
    *ptr = p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = (_STACK *)BUF_MEM_new();
      ptr[2] = p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        ptr[3] = (_STACK *)0x0;
        ptr[4] = (_STACK *)0x0;
        ptr[1] = (_STACK *)0x1;
        *param_1 = ptr;
        return 1;
      }
    }
    ERR_put_error(0xd,0xab,0x41,DAT_000b7530,0x96);
    if (*ptr != (_STACK *)0x0) {
      sk_free(*ptr);
    }
    CRYPTO_free(ptr);
  }
  return 0;
}

