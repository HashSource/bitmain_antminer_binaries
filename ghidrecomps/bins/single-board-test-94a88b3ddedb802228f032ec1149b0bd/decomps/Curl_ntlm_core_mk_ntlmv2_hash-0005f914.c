
undefined4
Curl_ntlm_core_mk_ntlmv2_hash
          (int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  undefined uVar1;
  undefined *puVar2;
  __int32_t **pp_Var3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  byte *pbVar7;
  __int32_t _Var8;
  int iVar9;
  undefined *puVar10;
  
  iVar9 = (param_4 + param_2) * 2;
  puVar2 = (undefined *)(**DAT_0005f9a8)(iVar9);
  if (puVar2 == (undefined *)0x0) {
    uVar4 = 0x1b;
  }
  else {
    if (param_2 != 0) {
      pp_Var3 = __ctype_toupper_loc();
      param_2 = param_2 * 2;
      pbVar7 = (byte *)(param_1 + -1);
      puVar5 = puVar2;
      do {
        pbVar7 = pbVar7 + 1;
        _Var8 = (*pp_Var3)[*pbVar7];
        puVar5[1] = 0;
        *puVar5 = (char)_Var8;
        puVar5 = puVar5 + 2;
      } while (puVar5 != puVar2 + param_2);
    }
    puVar5 = puVar2 + param_2;
    if (param_4 != 0) {
      puVar10 = puVar5 + param_4 * 2;
      puVar6 = (undefined *)(param_3 + -1);
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
        puVar5[1] = 0;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 2;
      } while (puVar5 != puVar10);
    }
    uVar4 = curlx_uztoui(iVar9);
    uVar4 = Curl_hmac_md5(param_5,0x10,puVar2,uVar4,param_6);
    (**DAT_0005f9ac)(puVar2);
  }
  return uVar4;
}

