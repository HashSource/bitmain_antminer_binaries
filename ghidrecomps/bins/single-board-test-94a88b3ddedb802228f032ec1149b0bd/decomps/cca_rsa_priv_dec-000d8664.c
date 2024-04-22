
bool cca_rsa_priv_dec(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4)

{
  undefined4 *puVar1;
  uint local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined auStack_40 [8];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined auStack_30 [12];
  
  local_54 = 0;
  local_38 = DAT_0016ad78;
  uStack_34 = DAT_0016ad7c;
  local_4c = 0;
  local_50 = 1;
  local_58 = param_1;
  local_48 = RSA_size(param_4);
  puVar1 = (undefined4 *)RSA_get_ex_data(param_4,hndidx);
  local_44 = *puVar1;
  (*pkaDecrypt)(&local_60,&local_5c,&local_54,auStack_40,&local_50,&local_38,&local_58,param_2,
                &local_4c,auStack_30,&local_44,puVar1 + 1,&local_48,param_3);
  return (local_60 | local_5c) == 0;
}

