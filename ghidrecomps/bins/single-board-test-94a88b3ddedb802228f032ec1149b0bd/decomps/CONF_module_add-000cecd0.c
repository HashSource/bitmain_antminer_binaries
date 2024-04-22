
int CONF_module_add(char *name,undefined1 *ifunc,undefined1 *ffunc)

{
  _STACK **pp_Var1;
  undefined4 *data;
  char *pcVar2;
  int iVar3;
  _STACK *p_Var4;
  
  pp_Var1 = DAT_000ced2c;
  if (*DAT_000ced2c == (_STACK *)0x0) {
    p_Var4 = sk_new_null();
    *pp_Var1 = p_Var4;
    if (p_Var4 == (_STACK *)0x0) {
      return 0;
    }
  }
  data = (undefined4 *)CRYPTO_malloc(0x18,DAT_000ced30,0x11d);
  if (data != (undefined4 *)0x0) {
    *data = 0;
    pcVar2 = BUF_strdup(name);
    data[4] = 0;
    data[1] = pcVar2;
    data[2] = ifunc;
    data[3] = ffunc;
    iVar3 = sk_push(*pp_Var1,data);
    if (iVar3 != 0) {
      return 1;
    }
    CRYPTO_free(data);
  }
  return 0;
}

