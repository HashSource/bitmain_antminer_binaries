
int Curl_slist_duplicate(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar2 = 0;
  do {
    iVar1 = curl_slist_append(iVar2,*param_1);
    if (iVar1 == 0) {
      curl_slist_free_all(iVar2);
      return 0;
    }
    param_1 = (undefined4 *)param_1[1];
    iVar2 = iVar1;
  } while (param_1 != (undefined4 *)0x0);
  return iVar1;
}

