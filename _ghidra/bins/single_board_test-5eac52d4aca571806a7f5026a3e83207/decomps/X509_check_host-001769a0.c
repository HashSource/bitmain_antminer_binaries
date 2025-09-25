
undefined4 X509_check_host(undefined4 param_1,char *param_2,uint param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0xfffffffe;
  }
  if (param_3 == 0) {
    strlen(param_2);
  }
  else {
    if (param_3 < 2) {
      pvVar1 = memchr(param_2,0,1);
    }
    else {
      pvVar1 = memchr(param_2,0,param_3 - 1);
    }
    if (pvVar1 != (void *)0x0) {
      return 0xfffffffe;
    }
  }
  uVar2 = do_x509_check(param_1,param_2);
  return uVar2;
}

