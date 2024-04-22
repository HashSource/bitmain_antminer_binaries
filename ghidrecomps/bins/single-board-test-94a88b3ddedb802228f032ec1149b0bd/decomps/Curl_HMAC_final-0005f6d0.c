
undefined4 Curl_HMAC_final(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    param_2 = param_1[2] + *(int *)(iVar1 + 0xc);
  }
  (**(code **)(iVar1 + 8))(param_2,param_1[1]);
  (**(code **)(iVar1 + 4))(param_1[2],param_2,*(undefined4 *)(iVar1 + 0x14));
  (**(code **)(iVar1 + 8))(param_2,param_1[2]);
  (**DAT_0005f708)(param_1);
  return 0;
}

