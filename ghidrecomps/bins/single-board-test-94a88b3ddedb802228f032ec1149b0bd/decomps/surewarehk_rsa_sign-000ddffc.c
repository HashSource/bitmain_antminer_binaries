
int surewarehk_rsa_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4,
                       int param_5)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar3 = DAT_000de0f8;
  local_60 = *DAT_000de0ec;
  uStack_5c = DAT_000de0ec[1];
  uStack_58 = DAT_000de0ec[2];
  uStack_54 = DAT_000de0ec[3];
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (*(int *)(DAT_000de0f8 + 0x38) == 0) {
    iVar2 = *(int *)(DAT_000de0f8 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar2;
    }
    ERR_put_error(iVar2,0x6f,0x75,DAT_000de0f4,0x3df);
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,*(int *)(DAT_000de0f0 + 0xd4));
    if (pvVar1 == (void *)0x0) {
      iVar2 = *(int *)(iVar3 + 4);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar2;
      }
      ERR_put_error(iVar2,0x6f,0x69,DAT_000de0f4,0x3e4);
    }
    else {
      if (param_5 == 1) {
        iVar3 = (**(code **)(iVar3 + 0x38))(&local_60,param_1,param_2,&iStack_64,param_3,pvVar1,1);
        surewarehk_error_handling(&local_60,0x6f,iVar3);
        if (iVar3 != 1) {
          return iVar3;
        }
        return iStack_64;
      }
      iVar2 = *(int *)(iVar3 + 4);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar2;
      }
      ERR_put_error(iVar2,0x6f,0x6b,DAT_000de0f4,0x3f1);
    }
  }
  return 0;
}

