
int curl_multi_socket_action
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = multi_socket(param_1,0,param_2,param_3,param_4);
  if (iVar1 < 1) {
    update_timer(param_1);
  }
  return iVar1;
}

