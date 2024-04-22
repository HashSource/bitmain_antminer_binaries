
undefined4 Curl_pipeline_set_server_blacklist(int *param_1,int *param_2)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_2;
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Curl_llist_alloc(DAT_0003c650);
    ppcVar1 = DAT_0003c654;
    if (iVar2 == 0) {
      return 3;
    }
    iVar3 = *param_1;
    while (iVar3 != 0) {
      iVar3 = (**ppcVar1)();
      if (iVar3 == 0) {
        return 3;
      }
      iVar3 = Curl_llist_insert_next(iVar2,*(undefined4 *)(iVar2 + 4),iVar3);
      if (iVar3 == 0) {
        return 3;
      }
      param_1 = param_1 + 1;
      iVar3 = *param_1;
    }
  }
  if (iVar4 != 0) {
    Curl_llist_destroy(iVar4,0);
  }
  *param_2 = iVar2;
  return 0;
}

