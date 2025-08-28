
int curl_slist_append(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*Curl_cstrdup)(param_2);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Curl_slist_append_nodup(param_1,iVar1);
    if (iVar2 == 0) {
      (*Curl_cfree)(iVar1);
    }
  }
  return iVar2;
}

