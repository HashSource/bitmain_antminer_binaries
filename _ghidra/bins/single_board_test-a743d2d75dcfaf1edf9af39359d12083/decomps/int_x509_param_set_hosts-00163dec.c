
undefined4 int_x509_param_set_hosts(int *param_1,int param_2,char *param_3,size_t param_4)

{
  bool bVar1;
  void *pvVar2;
  char *ptr;
  _STACK *st;
  int iVar3;
  size_t __n;
  
  if (param_4 == 0) {
    if (param_3 == (char *)0x0) {
LAB_00163eaa:
      bVar1 = true;
      goto LAB_00163e1e;
    }
    param_4 = strlen(param_3);
  }
  else {
    if (param_3 == (char *)0x0) goto LAB_00163eaa;
    if (param_4 < 2) {
      __n = 1;
    }
    else {
      __n = param_4 - 1;
    }
    pvVar2 = memchr(param_3,0,__n);
    if (pvVar2 != (void *)0x0) {
      return 0;
    }
  }
  if (param_3[param_4 - 1] == '\0') {
    param_4 = param_4 - 1;
    bVar1 = param_3 == (char *)0x0 || param_4 == 0;
  }
  else if (param_3 == (char *)0x0 || param_4 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
LAB_00163e1e:
  if ((param_2 == 0) && ((_STACK *)*param_1 != (_STACK *)0x0)) {
    sk_pop_free((_STACK *)*param_1,(func *)0x163de9);
    *param_1 = 0;
  }
  if (bVar1) {
    return 1;
  }
  ptr = BUF_strndup(param_3,param_4);
  if (ptr != (char *)0x0) {
    st = (_STACK *)*param_1;
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *param_1 = (int)st;
      if (st == (_STACK *)0x0) {
        CRYPTO_free(ptr);
        return 0;
      }
    }
    iVar3 = sk_push(st,ptr);
    if (iVar3 != 0) {
      return 1;
    }
    CRYPTO_free(ptr);
    iVar3 = sk_num((_STACK *)*param_1);
    if (iVar3 == 0) {
      sk_free((_STACK *)*param_1);
      *param_1 = 0;
      return 0;
    }
  }
  return 0;
}

