
int Curl_ntlm_core_mk_lmv2_resp
              (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_38 = *param_3;
  uStack_34 = param_3[1];
  local_30 = *param_2;
  uStack_2c = param_2[1];
  iVar1 = Curl_hmac_md5(param_1,0x10,&local_38,0x10,&local_28);
  if (iVar1 == 0) {
    *param_4 = local_28;
    param_4[1] = uStack_24;
    param_4[2] = uStack_20;
    param_4[3] = uStack_1c;
    uVar2 = param_2[1];
    param_4[4] = *param_2;
    param_4[5] = uVar2;
  }
  return iVar1;
}

