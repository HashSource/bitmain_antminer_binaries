
undefined4 Curl_conncache_find_bundle(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *__s;
  size_t sVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    if (*(char *)(param_1 + 0x1ef) == '\0') {
      uVar2 = *(undefined4 *)(param_1 + 0x98);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xa8);
    }
    __s = (char *)curl_maprintf(DAT_0003c158,uVar2,*(undefined2 *)(param_1 + 0x460),
                                *(char *)(param_1 + 0x1ef),param_4);
    if (__s != (char *)0x0) {
      sVar1 = strlen(__s);
      uVar2 = Curl_hash_pick(param_2,__s,sVar1);
      (**DAT_0003c15c)(__s);
      return uVar2;
    }
  }
  return 0;
}

