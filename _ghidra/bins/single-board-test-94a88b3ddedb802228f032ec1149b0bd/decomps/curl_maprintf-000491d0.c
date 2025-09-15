
int curl_maprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = dprintf_formatf(&local_30,0x484ed,param_1,&uStack_c);
  if ((iVar1 == -1) || (local_24 != 0)) {
    if (local_28 != 0) {
      (*Curl_cfree)(local_30);
      local_28 = 0;
    }
  }
  else if (local_28 == 0) {
    local_28 = (*Curl_cstrdup)(&DAT_0013a6fc);
  }
  else {
    *(undefined1 *)(local_30 + local_2c) = 0;
    local_28 = local_30;
  }
  return local_28;
}

