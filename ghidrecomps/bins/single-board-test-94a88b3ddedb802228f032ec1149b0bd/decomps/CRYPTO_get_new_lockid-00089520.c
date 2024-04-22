
int CRYPTO_get_new_lockid(char *name)

{
  _STACK **pp_Var1;
  char *data;
  int iVar2;
  _STACK *p_Var3;
  
  pp_Var1 = DAT_00089588;
  if (*DAT_00089588 == (_STACK *)0x0) {
    p_Var3 = sk_new_null();
    *pp_Var1 = p_Var3;
    if (p_Var3 == (_STACK *)0x0) {
      ERR_put_error(0xf,0x65,0x41,DAT_0008958c,0xdd);
      return 0;
    }
  }
  data = BUF_strdup(name);
  if (data == (char *)0x0) {
    ERR_put_error(0xf,0x65,0x41,DAT_0008958c,0xe1);
    iVar2 = 0;
  }
  else {
    iVar2 = sk_push(*pp_Var1,data);
    if (iVar2 == 0) {
      CRYPTO_free(data);
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 0x29;
    }
  }
  return iVar2;
}

