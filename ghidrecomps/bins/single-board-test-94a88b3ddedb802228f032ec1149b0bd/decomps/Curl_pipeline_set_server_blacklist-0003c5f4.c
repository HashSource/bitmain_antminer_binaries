
undefined4 Curl_pipeline_set_server_blacklist(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = Curl_llist_alloc(0x3c329);
    if (iVar1 == 0) {
      return 3;
    }
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar2 = (*Curl_cstrdup)();
      if (iVar2 == 0) {
        return 3;
      }
      iVar2 = Curl_llist_insert_next(iVar1,*(undefined4 *)(iVar1 + 4),iVar2);
      if (iVar2 == 0) {
        return 3;
      }
      param_1 = param_1 + 1;
      iVar2 = *param_1;
    }
  }
  if (iVar3 != 0) {
    Curl_llist_destroy(iVar3,0);
  }
  *param_2 = iVar1;
  return 0;
}

