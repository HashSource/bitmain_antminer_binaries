
undefined4 surewarehk_load_privkey(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined local_69;
  undefined4 local_68;
  undefined4 local_64;
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
  
  iVar1 = DAT_000dd7a8;
  local_68 = 0;
  local_60 = *DAT_000dd7a0;
  uStack_5c = DAT_000dd7a0[1];
  uStack_58 = DAT_000dd7a0[2];
  uStack_54 = DAT_000dd7a0[3];
  local_64 = 0;
  local_50 = DAT_000dd7a0[4];
  local_69 = 0;
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
  if (*(code **)(DAT_000dd7a8 + 0x20) == (code *)0x0) {
    iVar2 = *(int *)(DAT_000dd7a8 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    ERR_put_error(iVar2,0x69,0x75,DAT_000dd7a4,0x33d);
    uVar3 = 0;
  }
  else {
    iVar2 = (**(code **)(DAT_000dd7a8 + 0x20))(&local_60,param_2,&local_64,&local_68,&local_69);
    if (iVar2 == 1) {
      uVar3 = sureware_load_public(param_1,param_2,local_64,local_68,local_69);
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar1 + 4) = iVar2;
      }
      ERR_put_error(iVar2,0x69,0x80,DAT_000dd7a4,0x342);
      ERR_add_error_data(1,&local_60);
      uVar3 = 0;
    }
  }
  return uVar3;
}

