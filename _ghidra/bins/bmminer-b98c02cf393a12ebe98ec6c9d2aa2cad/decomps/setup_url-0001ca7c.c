
undefined4 setup_url(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *__s1;
  int iVar1;
  char *__dest;
  
  __s1 = (char *)get_proxy(param_2,param_1,param_3,param_4,param_4);
  iVar1 = detect_stratum(param_1,__s1);
  if (iVar1 == 0) {
    opt_set_charp(__s1,param_1 + 0xa4);
    iVar1 = strncmp(__s1,"http://",7);
    if ((iVar1 != 0) && (iVar1 = strncmp(__s1,"https://",8), iVar1 != 0)) {
      __dest = (char *)_cgmalloc(0x100,"cgminer.c","setup_url",0x3fc);
      builtin_strncpy(__dest,"stratum+tcp://",0xf);
      strncat(__dest,__s1,0xf2);
      detect_stratum(param_1,__dest);
      free(__dest);
    }
  }
  return *(undefined4 *)(param_1 + 0xa4);
}

