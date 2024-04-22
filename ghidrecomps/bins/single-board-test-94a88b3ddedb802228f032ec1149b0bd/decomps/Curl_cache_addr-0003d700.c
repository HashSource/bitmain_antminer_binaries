
int Curl_cache_addr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  char *__s;
  size_t sVar2;
  undefined4 *puVar3;
  int iVar4;
  
  __s = (char *)create_hostcache_id(param_3,param_4,param_3,param_4,param_4);
  if (__s == (char *)0x0) {
    iVar4 = 0;
  }
  else {
    sVar2 = strlen(__s);
    puVar3 = (undefined4 *)(**DAT_0003d784)(1,0xc);
    if (puVar3 == (undefined4 *)0x0) {
      (**DAT_0003d788)(__s);
      iVar4 = 0;
    }
    else {
      *puVar3 = param_2;
      puVar3[2] = 1;
      time(puVar3 + 1);
      if (puVar3[1] == 0) {
        puVar3[1] = 1;
      }
      iVar4 = Curl_hash_add(*(undefined4 *)(param_1 + 0x38),__s,sVar2 + 1,puVar3);
      ppcVar1 = DAT_0003d788;
      if (iVar4 == 0) {
        (**DAT_0003d788)(puVar3);
        (**ppcVar1)(__s);
      }
      else {
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
        (**ppcVar1)(__s);
      }
    }
  }
  return iVar4;
}

