
undefined4
Curl_write_plain(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  uVar1 = Curl_send_plain(param_1,*(int *)(param_1 + 0x158) == param_2,param_3,param_4,&local_14);
  *param_5 = uVar1;
  return local_14;
}

