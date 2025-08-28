
undefined4 Curl_loadhostpairs(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined4 local_224;
  undefined1 auStack_220 [256];
  undefined1 auStack_120 [256];
  
  puVar5 = *(undefined4 **)(param_1 + 0x464);
  do {
    while( true ) {
      if (puVar5 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x464) = 0;
        return 0;
      }
      pcVar1 = (char *)*puVar5;
      if (pcVar1 != (char *)0x0) break;
LAB_0003da94:
      puVar5 = (undefined4 *)puVar5[1];
    }
    if (*pcVar1 != '-') {
      iVar2 = __isoc99_sscanf(pcVar1,"%255[^:]:%d:%255s",auStack_220,&local_224,auStack_120);
      if (iVar2 == 3) {
        iVar2 = Curl_str2addr(auStack_120,local_224);
        if (iVar2 == 0) {
          Curl_infof(param_1,"Address in \'%s\' found illegal!\n",*puVar5);
        }
        else {
          pcVar1 = (char *)create_hostcache_id(auStack_220,local_224);
          if (pcVar1 == (char *)0x0) {
LAB_0003dbb0:
            Curl_freeaddrinfo(iVar2);
            return 0x1b;
          }
          sVar4 = strlen(pcVar1);
          if (*(int *)(param_1 + 0x48) != 0) {
            Curl_share_lock(param_1,3,2);
          }
          iVar3 = Curl_hash_pick(*(undefined4 *)(param_1 + 0x38),pcVar1,sVar4 + 1);
          (*Curl_cfree)(pcVar1);
          if (iVar3 == 0) {
            iVar3 = Curl_cache_addr(param_1,iVar2,auStack_220,local_224);
            if (iVar3 != 0) {
              *(undefined4 *)(iVar3 + 4) = 0;
              *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + -1;
            }
          }
          else {
            Curl_freeaddrinfo(iVar2);
          }
          if (*(int *)(param_1 + 0x48) != 0) {
            Curl_share_unlock(param_1,3);
          }
          if (iVar3 == 0) goto LAB_0003dbb0;
          Curl_infof(param_1,"Added %s:%d:%s to DNS cache\n",auStack_220,local_224,auStack_120);
        }
      }
      else {
        Curl_infof(param_1,"Couldn\'t parse CURLOPT_RESOLVE entry \'%s\'!\n",*puVar5);
      }
      goto LAB_0003da94;
    }
    iVar2 = __isoc99_sscanf(pcVar1 + 1,&DAT_001356e4,auStack_220,&local_224);
    if (iVar2 == 2) {
      pcVar1 = (char *)create_hostcache_id(auStack_220,local_224);
      if (pcVar1 == (char *)0x0) {
        return 0x1b;
      }
      sVar4 = strlen(pcVar1);
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_lock(param_1,3,2);
      }
      Curl_hash_delete(*(undefined4 *)(param_1 + 0x38),pcVar1,sVar4 + 1);
      if (*(int *)(param_1 + 0x48) != 0) {
        Curl_share_unlock(param_1,3);
      }
      (*Curl_cfree)(pcVar1);
      goto LAB_0003da94;
    }
    Curl_infof(param_1,"Couldn\'t parse CURLOPT_RESOLVE removal entry \'%s\'!\n",*puVar5);
    puVar5 = (undefined4 *)puVar5[1];
  } while( true );
}

