
undefined4 surewarehk_load_pubkey(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined local_65;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined local_4e;
  undefined auStack_4d [49];
  
  iVar1 = DAT_000dd6e0;
  local_64 = 0;
  local_60 = *DAT_000dd6d8;
  uStack_5c = DAT_000dd6d8[1];
  uStack_58 = DAT_000dd6d8[2];
  uStack_54 = DAT_000dd6d8[3];
  local_65 = 0;
  uStack_50 = (undefined2)DAT_000dd6d8[4];
  local_4e = (undefined)((uint)DAT_000dd6d8[4] >> 0x10);
  memset(auStack_4d,0,0x2d);
  if (*(code **)(iVar1 + 0x1c) == (code *)0x0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    ERR_put_error(iVar2,0x71,0x75,DAT_000dd6dc,0x357);
    uVar3 = 0;
  }
  else {
    iVar2 = (**(code **)(iVar1 + 0x1c))(&local_60,param_2,&local_64,&local_65);
    if (iVar2 == 1) {
      uVar3 = sureware_load_public(param_1,param_2,0,local_64,local_65);
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar1 + 4) = iVar2;
      }
      ERR_put_error(iVar2,0x71,0x81,DAT_000dd6dc,0x35d);
      ERR_add_error_data(1,&local_60);
      uVar3 = 0;
    }
  }
  return uVar3;
}

