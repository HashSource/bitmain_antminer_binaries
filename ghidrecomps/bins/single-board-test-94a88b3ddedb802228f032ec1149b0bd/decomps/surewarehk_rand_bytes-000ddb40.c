
bool surewarehk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int lib;
  bool bVar2;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined2 local_48;
  undefined auStack_46 [46];
  
  iVar1 = DAT_000ddbac;
  local_58 = *DAT_000ddba8;
  uStack_54 = DAT_000ddba8[1];
  uStack_50 = DAT_000ddba8[2];
  uStack_4c = DAT_000ddba8[3];
  local_48 = (undefined2)DAT_000ddba8[4];
  memset(auStack_46,0,0x2e);
  if (*(code **)(iVar1 + 0x30) == (code *)0x0) {
    lib = *(int *)(iVar1 + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x6c,0x75,DAT_000ddbb0,0x293);
    bVar2 = false;
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x30))(&local_58,param_1,param_2);
    surewarehk_error_handling(&local_58,0x6c,iVar1);
    bVar2 = iVar1 == 1;
  }
  return bVar2;
}

