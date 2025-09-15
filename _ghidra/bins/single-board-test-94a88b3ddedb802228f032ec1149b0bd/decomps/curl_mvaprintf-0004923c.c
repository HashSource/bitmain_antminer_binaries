
int curl_mvaprintf(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = dprintf_formatf(&local_18,0x484ed,param_1,param_2);
  if ((iVar1 == -1) || (local_c != 0)) {
    if (local_10 != 0) {
      (*Curl_cfree)(local_18);
      local_10 = 0;
    }
  }
  else if (local_10 == 0) {
    local_10 = (*Curl_cstrdup)(&DAT_0013a6fc);
  }
  else {
    *(undefined1 *)(local_18 + local_14) = 0;
    local_10 = local_18;
  }
  return local_10;
}

