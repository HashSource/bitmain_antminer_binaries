
undefined4 Curl_ssl_config_matches(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == *param_2) {
    if ((((*(short *)(param_1 + 2) == *(short *)(param_2 + 2)) &&
         (iVar1 = safe_strequal(param_1[3],param_2[3]), iVar1 != 0)) &&
        (iVar1 = safe_strequal(param_1[4],param_2[4]), iVar1 != 0)) &&
       ((iVar1 = safe_strequal(param_1[7],param_2[7]), iVar1 != 0 &&
        (iVar1 = safe_strequal(param_1[8],param_2[8]), iVar1 != 0)))) {
      uVar2 = safe_strequal(param_1[9],param_2[9]);
      return uVar2;
    }
  }
  return 0;
}

