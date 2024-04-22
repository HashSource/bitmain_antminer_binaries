
int UI_dup_info_string(UI *ui,char *text)

{
  char *pcVar1;
  int *ptr;
  _STACK *p_Var2;
  int iVar3;
  
  if (text == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,DAT_000d4894,0x8f);
  }
  else {
    pcVar1 = BUF_strdup(text);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x66,0x41,DAT_000d4894,0x16d);
      return -1;
    }
    ptr = (int *)CRYPTO_malloc(0x20,DAT_000d4894,0x93);
    if (ptr != (int *)0x0) {
      iVar3 = *(int *)(ui + 4);
      ptr[1] = (int)pcVar1;
      ptr[7] = 1;
      ptr[2] = 0;
      ptr[3] = 0;
      *ptr = 4;
      if (iVar3 == 0) {
        p_Var2 = sk_new_null();
        *(_STACK **)(ui + 4) = p_Var2;
        if (p_Var2 == (_STACK *)0x0) {
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
      iVar3 = sk_push(*(_STACK **)(ui + 4),ptr);
      if (0 < iVar3) {
        return iVar3;
      }
      return iVar3 + -1;
    }
  }
  return -1;
}

