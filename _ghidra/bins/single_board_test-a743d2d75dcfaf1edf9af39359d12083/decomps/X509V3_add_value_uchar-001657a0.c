
int X509V3_add_value_uchar(char *name,char *value,stack_st_CONF_VALUE **extlist)

{
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if ((name == (char *)0x0) || (name = BUF_strdup(name), name != (char *)0x0)) {
    if (((value == (char *)0x0) || (value = BUF_strdup(value), value != (char *)0x0)) &&
       (data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x5b), data != (undefined4 *)0x0)) {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        p_Var2 = sk_new_null();
        *extlist = (stack_st_CONF_VALUE *)p_Var2;
        if (p_Var2 != (_STACK *)0x0) goto LAB_0016573a;
      }
      else {
LAB_0016573a:
        data[1] = name;
        data[2] = value;
        *data = 0;
        iVar1 = sk_push(&(*extlist)->stack,data);
        if (iVar1 != 0) {
          return 1;
        }
      }
      ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
      CRYPTO_free(data);
      goto LAB_00165762;
    }
  }
  else {
    value = (char *)0x0;
  }
  ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
LAB_00165762:
  if (name != (char *)0x0) {
    CRYPTO_free(name);
  }
  if (value != (char *)0x0) {
    CRYPTO_free(value);
    value = (char *)0x0;
  }
  return (int)value;
}

