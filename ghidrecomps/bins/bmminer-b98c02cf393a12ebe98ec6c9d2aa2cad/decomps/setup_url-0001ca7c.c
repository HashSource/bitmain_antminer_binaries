
undefined4 setup_url(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  char cVar4;
  char *__s1;
  int iVar5;
  undefined4 *__dest;
  
  __s1 = (char *)get_proxy(param_2,param_1,param_3,param_4,param_4);
  iVar5 = detect_stratum(param_1,__s1);
  if (iVar5 == 0) {
    opt_set_charp(__s1,param_1 + 0xa4);
    iVar5 = strncmp(__s1,"http://",7);
    if ((iVar5 != 0) && (iVar5 = strncmp(__s1,"https://",8), iVar5 != 0)) {
      __dest = (undefined4 *)_cgmalloc(0x100,"cgminer.c",DAT_0001cb18,0x3fc);
      cVar4 = s_stratum_tcp____0005c5ec[14];
      uVar3 = s_stratum_tcp____0005c5ec._12_2_;
      uVar2 = s_stratum_tcp____0005c5ec._8_4_;
      uVar1 = s_stratum_tcp____0005c5ec._4_4_;
      *__dest = s_stratum_tcp____0005c5ec._0_4_;
      __dest[1] = uVar1;
      __dest[2] = uVar2;
      *(char *)((int)__dest + 0xe) = cVar4;
      *(undefined2 *)(__dest + 3) = uVar3;
      strncat((char *)__dest,__s1,0xf2);
      detect_stratum(param_1,__dest);
      free(__dest);
    }
  }
  return *(undefined4 *)(param_1 + 0xa4);
}

