
undefined4 curl_multi_info_read(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  *param_2 = 0;
  if (((param_1 != (int *)0x0) && (*param_1 == 0xbab1e)) &&
     (iVar1 = Curl_llist_count(param_1[5]), iVar1 != 0)) {
    puVar3 = *(undefined4 **)(undefined4 *)param_1[5];
    uVar4 = *puVar3;
    Curl_llist_remove((undefined4 *)param_1[5],puVar3,0);
    Curl_llist_count(param_1[5]);
    uVar2 = curlx_uztosi();
    *param_2 = uVar2;
    return uVar4;
  }
  return 0;
}

