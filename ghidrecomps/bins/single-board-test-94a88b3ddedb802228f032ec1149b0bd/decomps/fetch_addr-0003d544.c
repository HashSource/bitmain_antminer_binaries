
int fetch_addr(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char *__s;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c [2];
  
  iVar4 = *param_1;
  __s = (char *)create_hostcache_id(param_2,param_3);
  if (__s == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    sVar1 = strlen(__s);
    iVar2 = Curl_hash_pick(*(undefined4 *)(iVar4 + 0x38),__s,sVar1 + 1);
    if ((iVar2 != 0) && (*(int *)(iVar4 + 0x2c8) != -1)) {
      time(local_1c);
      iVar3 = *(int *)(iVar4 + 0x2c8);
      if ((*(int *)(iVar2 + 4) != 0) &&
         (local_1c[0] = local_1c[0] - *(int *)(iVar2 + 4), iVar3 <= local_1c[0])) {
        Curl_infof(iVar4,DAT_0003d5b8,local_1c[0],iVar3,iVar3);
        iVar2 = 0;
        Curl_hash_delete(*(undefined4 *)(iVar4 + 0x38),__s,sVar1 + 1);
      }
    }
    (**DAT_0003d5b4)(__s);
  }
  return iVar2;
}

