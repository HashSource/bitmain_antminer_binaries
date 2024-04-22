
int general_allocate_string
              (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
              int param_8,int param_9)

{
  int *ptr;
  _STACK *p_Var1;
  int iVar2;
  
  if (param_2 == 0) {
    ERR_put_error(0x28,0x6d,0x43,DAT_000d4358,0x8f);
  }
  else if ((param_4 - 1U < 3) && (param_6 == 0)) {
    ERR_put_error(0x28,0x6d,0x69,DAT_000d4358,0x92);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x20,DAT_000d4358,0x93);
    if (ptr != (int *)0x0) {
      iVar2 = *(int *)(param_1 + 4);
      if (param_3 != 0) {
        param_3 = 1;
      }
      ptr[1] = param_2;
      ptr[7] = param_3;
      *ptr = param_4;
      ptr[3] = param_6;
      ptr[2] = param_5;
      if (iVar2 == 0) {
        p_Var1 = sk_new_null();
        *(_STACK **)(param_1 + 4) = p_Var1;
        if (p_Var1 == (_STACK *)0x0) {
          if ((ptr[7] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[4]);
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[4] = param_7;
      ptr[5] = param_8;
      ptr[6] = param_9;
      iVar2 = sk_push(*(_STACK **)(param_1 + 4),ptr);
      if (0 < iVar2) {
        return iVar2;
      }
      return iVar2 + -1;
    }
  }
  return -1;
}

