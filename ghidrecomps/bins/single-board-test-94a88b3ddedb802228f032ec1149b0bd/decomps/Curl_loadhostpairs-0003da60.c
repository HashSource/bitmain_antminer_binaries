
undefined4 Curl_loadhostpairs(int param_1)

{
  code **ppcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  char **ppcVar6;
  undefined4 local_224;
  undefined auStack_220 [256];
  undefined auStack_120 [256];
  
  ppcVar1 = DAT_0003dbc0;
  ppcVar6 = *(char ***)(param_1 + 0x464);
  do {
    while( true ) {
      if (ppcVar6 == (char **)0x0) {
        *(undefined4 *)(param_1 + 0x464) = 0;
        return 0;
      }
      pcVar2 = *ppcVar6;
      if (pcVar2 != (char *)0x0) break;
LAB_0003da94:
      ppcVar6 = (char **)ppcVar6[1];
    }
    if (*pcVar2 != '-') {
      iVar3 = __isoc99_sscanf(pcVar2,DAT_0003dbc4,auStack_220,&local_224,auStack_120);
      if (iVar3 == 3) {
        iVar3 = Curl_str2addr(auStack_120,local_224);
        if (iVar3 == 0) {
          Curl_infof(param_1,DAT_0003dbd8,*ppcVar6);
        }
        else {
          pcVar2 = (char *)create_hostcache_id(auStack_220,local_224);
          if (pcVar2 == (char *)0x0) {
LAB_0003dbb0:
            Curl_freeaddrinfo(iVar3);
            return 0x1b;
          }
          sVar5 = strlen(pcVar2);
          if (*(int *)(param_1 + 0x48) != 0) {
            Curl_share_lock(param_1,3,2);
          }
          iVar4 = Curl_hash_pick(*(undefined4 *)(param_1 + 0x38),pcVar2,sVar5 + 1);
          (**ppcVar1)(pcVar2);
          if (iVar4 == 0) {
            iVar4 = Curl_cache_addr(param_1,iVar3,auStack_220,local_224);
            if (iVar4 != 0) {
              *(undefined4 *)(iVar4 + 4) = 0;
              *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + -1;
            }
          }
          else {
            Curl_freeaddrinfo(iVar3);
          }
          if (*(int *)(param_1 + 0x48) != 0) {
            Curl_share_unlock(param_1,3);
          }
          if (iVar4 == 0) goto LAB_0003dbb0;
          Curl_infof(param_1,DAT_0003dbd4,auStack_220,local_224,auStack_120);
        }
      }
      else {
        Curl_infof(param_1,DAT_0003dbc8,*ppcVar6);
      }
      goto LAB_0003da94;
    }
    iVar3 = __isoc99_sscanf(pcVar2 + 1,DAT_0003dbcc,auStack_220,&local_224);
    if (iVar3 == 2) {
      pcVar2 = (char *)create_hostcache_id(auStack_220,local_224);
      if (pcVar2 == (char *)0x0) {
        return 0x1b;
      }
      sVar5 = strlen(pcVar2);
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_lock(param_1,3,2);
      }
      Curl_hash_delete(*(undefined4 *)(param_1 + 0x38),pcVar2,sVar5 + 1);
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_unlock(param_1,3);
      }
      (**ppcVar1)(pcVar2);
      goto LAB_0003da94;
    }
    Curl_infof(param_1,DAT_0003dbd0,*ppcVar6);
    ppcVar6 = (char **)ppcVar6[1];
  } while( true );
}

