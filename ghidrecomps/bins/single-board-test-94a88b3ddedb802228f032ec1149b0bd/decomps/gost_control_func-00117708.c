
undefined4 gost_control_func(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char **ppcVar1;
  char *pcVar2;
  char *ptr;
  undefined4 uVar3;
  
  ppcVar1 = DAT_0011773c;
  if (param_2 == 200) {
    pcVar2 = getenv(DAT_00117740);
    ptr = *ppcVar1;
    if (pcVar2 != (char *)0x0) {
      param_4 = pcVar2;
    }
    if (ptr != (char *)0x0) {
      CRYPTO_free(ptr);
    }
    pcVar2 = BUF_strdup(param_4);
    uVar3 = 1;
    *ppcVar1 = pcVar2;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

