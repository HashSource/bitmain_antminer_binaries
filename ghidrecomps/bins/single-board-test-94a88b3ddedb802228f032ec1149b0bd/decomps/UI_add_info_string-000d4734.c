
int UI_add_info_string(UI *ui,char *text)

{
  int *ptr;
  _STACK *p_Var1;
  int iVar2;
  
  if (text == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,DAT_000d47d0,0x8f);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x20,DAT_000d47d0,0x93);
    if (ptr != (int *)0x0) {
      iVar2 = *(int *)(ui + 4);
      ptr[1] = (int)text;
      ptr[7] = 0;
      ptr[2] = 0;
      ptr[3] = 0;
      *ptr = 4;
      if (iVar2 == 0) {
        p_Var1 = sk_new_null();
        *(_STACK **)(ui + 4) = p_Var1;
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
      ptr[4] = 0;
      ptr[5] = 0;
      ptr[6] = 0;
      iVar2 = sk_push(*(_STACK **)(ui + 4),ptr);
      if (0 < iVar2) {
        return iVar2;
      }
      return iVar2 + -1;
    }
  }
  return -1;
}

