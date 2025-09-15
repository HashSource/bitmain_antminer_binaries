
undefined4
X509_check_host(undefined4 param_1,char *param_2,size_t param_3,undefined4 param_4,
               undefined4 param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  size_t __n;
  
  if (param_2 == (char *)0x0) {
LAB_000c835e:
    uVar2 = 0xfffffffe;
  }
  else {
    if (param_3 == 0) {
      param_3 = strlen(param_2);
    }
    else {
      if (param_3 < 2) {
        __n = 1;
      }
      else {
        __n = param_3 - 1;
      }
      pvVar1 = memchr(param_2,0,__n);
      if (pvVar1 != (void *)0x0) goto LAB_000c835e;
    }
    if ((1 < param_3) && (param_2[param_3 - 1] == '\0')) {
      param_3 = param_3 - 1;
    }
    uVar2 = do_x509_check(param_1,param_2,param_3,param_4,2,param_5);
  }
  return uVar2;
}

