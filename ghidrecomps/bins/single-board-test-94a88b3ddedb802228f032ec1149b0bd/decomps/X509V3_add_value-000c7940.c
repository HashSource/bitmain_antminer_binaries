
int X509V3_add_value(char *name,char *value,stack_st_CONF_VALUE **extlist)

{
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if ((name == (char *)0x0) || (name = BUF_strdup(name), name != (char *)0x0)) {
    if (((value == (char *)0x0) || (value = BUF_strdup(value), value != (char *)0x0)) &&
       (data = (undefined4 *)CRYPTO_malloc(0xc,DAT_000c79dc,0x5b), data != (undefined4 *)0x0)) {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        p_Var2 = sk_new_null();
        *extlist = (stack_st_CONF_VALUE *)p_Var2;
        if (p_Var2 != (_STACK *)0x0) goto LAB_000c797a;
      }
      else {
LAB_000c797a:
        data[1] = name;
        data[2] = value;
        *data = 0;
        iVar1 = sk_push(&(*extlist)->stack,data);
        if (iVar1 != 0) {
          return 1;
        }
      }
      ERR_put_error(0x22,0x69,0x41,DAT_000c79dc,0x66);
      CRYPTO_free(data);
      goto LAB_000c79a2;
    }
  }
  else {
    value = (char *)0x0;
  }
  ERR_put_error(0x22,0x69,0x41,DAT_000c79dc,0x66);
LAB_000c79a2:
  if (name != (char *)0x0) {
    CRYPTO_free(name);
  }
  if (value != (char *)0x0) {
    CRYPTO_free(value);
    value = (char *)0x0;
  }
  return (int)value;
}

