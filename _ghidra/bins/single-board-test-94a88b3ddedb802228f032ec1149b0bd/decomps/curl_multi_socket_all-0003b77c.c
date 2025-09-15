
int curl_multi_socket_all(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = multi_socket(param_1,1,0xffffffff,0,param_2);
  if (iVar1 < 1) {
    update_timer(param_1);
  }
  return iVar1;
}

