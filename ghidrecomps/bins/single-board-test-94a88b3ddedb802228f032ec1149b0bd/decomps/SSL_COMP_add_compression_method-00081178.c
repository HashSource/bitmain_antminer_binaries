
int SSL_COMP_add_compression_method(int id,COMP_METHOD *cm)

{
  _STACK **pp_Var1;
  int *data;
  _STACK *p_Var2;
  int iVar3;
  
  pp_Var1 = DAT_00081238;
  if ((cm == (COMP_METHOD *)0x0) || (cm->type == 0)) {
    iVar3 = 1;
  }
  else if (id - 0xc1U < 0x3f) {
    CRYPTO_mem_ctrl(3);
    data = (int *)CRYPTO_malloc(0xc,DAT_0008123c,0x7ca);
    *data = id;
    data[2] = (int)cm;
    load_builtin_compressions();
    p_Var2 = *pp_Var1;
    if (p_Var2 != (_STACK *)0x0) {
      iVar3 = sk_find(p_Var2,data);
      if (-1 < iVar3) {
        CRYPTO_free(data);
        CRYPTO_mem_ctrl(2);
        ERR_put_error(0x14,0xa5,0x135,DAT_0008123c,0x7d2);
        return 1;
      }
      p_Var2 = *pp_Var1;
      if ((p_Var2 != (_STACK *)0x0) && (iVar3 = sk_push(p_Var2,data), iVar3 != 0)) {
        CRYPTO_mem_ctrl(2);
        return 0;
      }
    }
    CRYPTO_free(data);
    CRYPTO_mem_ctrl(2);
    ERR_put_error(0x14,0xa5,0x41,DAT_0008123c,0x7d8);
    iVar3 = 1;
  }
  else {
    ERR_put_error(0x14,0xa5,0x133,DAT_0008123c,0x7c5);
    iVar3 = 0;
  }
  return iVar3;
}

