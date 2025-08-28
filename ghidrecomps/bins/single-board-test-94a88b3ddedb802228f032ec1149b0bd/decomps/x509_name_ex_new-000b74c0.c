
undefined4 x509_name_ex_new(undefined4 *param_1)

{
  undefined4 *ptr;
  _STACK *p_Var1;
  BUF_MEM *pBVar2;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x14,"x_name.c",0x88);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x96);
  }
  else {
    p_Var1 = sk_new_null();
    *ptr = p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      pBVar2 = BUF_MEM_new();
      ptr[2] = pBVar2;
      if (pBVar2 != (BUF_MEM *)0x0) {
        ptr[3] = 0;
        ptr[4] = 0;
        ptr[1] = 1;
        *param_1 = ptr;
        return 1;
      }
    }
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x96);
    if ((_STACK *)*ptr != (_STACK *)0x0) {
      sk_free((_STACK *)*ptr);
    }
    CRYPTO_free(ptr);
  }
  return 0;
}

