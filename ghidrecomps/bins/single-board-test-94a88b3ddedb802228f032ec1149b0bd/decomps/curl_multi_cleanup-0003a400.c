
undefined4 curl_multi_cleanup(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined auStack_140 [144];
  undefined auStack_b0 [148];
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    uVar1 = 1;
  }
  else {
    piVar5 = param_1 + 0x1a;
    *param_1 = 0;
    piVar2 = (int *)Curl_conncache_find_first_connection(piVar5);
    while (piVar2 != (int *)0x0) {
      iVar4 = param_1[0x24];
      *piVar2 = iVar4;
      sigpipe_ignore_isra_2(*(undefined *)(iVar4 + 0x324),auStack_b0);
      Curl_disconnect(piVar2,0);
      sigpipe_restore(auStack_b0);
      piVar2 = (int *)Curl_conncache_find_first_connection(piVar5);
    }
    iVar4 = param_1[0x24];
    if (iVar4 != 0) {
      sigpipe_ignore_isra_2(*(undefined *)(iVar4 + 0x324),auStack_140);
      iVar3 = param_1[0x24];
      iVar4 = 1;
      *(int **)(iVar3 + 0x38) = param_1 + 0xb;
      Curl_hostcache_clean(iVar3,param_1 + 0xb);
      Curl_close(param_1[0x24]);
    }
    Curl_hash_destroy(param_1 + 0x12);
    Curl_conncache_destroy(piVar5);
    Curl_llist_destroy(param_1[5],0);
    Curl_llist_destroy(param_1[6],0);
    piVar2 = (int *)param_1[1];
    while (piVar5 = piVar2, piVar2 != (int *)0x0) {
      while (piVar2 = (int *)*piVar5, piVar5[0xf] != 2) {
        piVar5[0x160] = 0;
        piVar5[0x10] = 0;
        piVar5 = piVar2;
        if (piVar2 == (int *)0x0) goto LAB_0003a4e0;
      }
      Curl_hostcache_clean(piVar5,piVar5[0xe]);
      piVar5[0xe] = 0;
      piVar5[0xf] = 0;
      piVar5[0x160] = 0;
      piVar5[0x10] = 0;
    }
LAB_0003a4e0:
    Curl_hash_destroy(param_1 + 0xb);
    Curl_pipeline_set_site_blacklist(0,param_1 + 0x2b);
    Curl_pipeline_set_server_blacklist(0,param_1 + 0x2c);
    (**DAT_0003a514)(param_1);
    if (iVar4 != 0) {
      sigpipe_restore(auStack_140);
    }
    uVar1 = 0;
  }
  return uVar1;
}

