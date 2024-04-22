
_STACK ** SRP_VBASE_new(char *param_1)

{
  _STACK **ptr;
  _STACK *p_Var1;
  _STACK **pp_Var2;
  
  ptr = (_STACK **)CRYPTO_malloc(0x14,DAT_000d7c64,0xfc);
  pp_Var2 = ptr;
  if (ptr != (_STACK **)0x0) {
    p_Var1 = sk_new_null();
    *ptr = p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = sk_new_null();
      ptr[1] = p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        ptr[3] = (_STACK *)0x0;
        ptr[4] = (_STACK *)0x0;
        ptr[2] = (_STACK *)0x0;
        if (param_1 == (char *)0x0) {
          return ptr;
        }
        p_Var1 = (_STACK *)BUF_strdup(param_1);
        ptr[2] = p_Var1;
        if (p_Var1 != (_STACK *)0x0) {
          return ptr;
        }
        sk_free(*ptr);
        sk_free(ptr[1]);
        CRYPTO_free(ptr);
        return (_STACK **)0x0;
      }
    }
    pp_Var2 = (_STACK **)0x0;
    CRYPTO_free(ptr);
  }
  return pp_Var2;
}

