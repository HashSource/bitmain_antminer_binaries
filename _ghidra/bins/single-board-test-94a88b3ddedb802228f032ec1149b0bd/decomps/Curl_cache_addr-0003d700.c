
int Curl_cache_addr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *__s;
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  
  __s = (char *)create_hostcache_id(param_3,param_4,param_3,param_4,param_4);
  if (__s == (char *)0x0) {
    iVar3 = 0;
  }
  else {
    sVar1 = strlen(__s);
    puVar2 = (undefined4 *)(*Curl_ccalloc)(1,0xc);
    if (puVar2 == (undefined4 *)0x0) {
      (*Curl_cfree)(__s);
      iVar3 = 0;
    }
    else {
      *puVar2 = param_2;
      puVar2[2] = 1;
      time(puVar2 + 1);
      if (puVar2[1] == 0) {
        puVar2[1] = 1;
      }
      iVar3 = Curl_hash_add(*(undefined4 *)(param_1 + 0x38),__s,sVar1 + 1,puVar2);
      if (iVar3 == 0) {
        (*Curl_cfree)(puVar2);
        (*Curl_cfree)(__s);
      }
      else {
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
        (*Curl_cfree)(__s);
      }
    }
  }
  return iVar3;
}

