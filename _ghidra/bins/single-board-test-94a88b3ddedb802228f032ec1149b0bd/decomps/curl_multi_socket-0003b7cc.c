
int curl_multi_socket(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = multi_socket(param_1,0,param_2,0,param_3);
  if (iVar1 < 1) {
    update_timer(param_1);
  }
  return iVar1;
}

