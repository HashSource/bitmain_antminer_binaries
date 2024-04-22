
void surewarehk_rand_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int lib;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined local_48;
  undefined auStack_47 [47];
  
  iVar1 = DAT_000dd208;
  local_58 = *DAT_000dd204;
  uStack_54 = DAT_000dd204[1];
  uStack_50 = DAT_000dd204[2];
  uStack_4c = DAT_000dd204[3];
  local_48 = (undefined)DAT_000dd204[4];
  memset(auStack_47,0,0x2f);
  if (*(code **)(iVar1 + 0xc) == (code *)0x0) {
    lib = *(int *)(iVar1 + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x6d,0x75,DAT_000dd20c,0x2a1);
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0xc))(&local_58,param_1,param_2);
    surewarehk_error_handling(&local_58,0x6d,uVar2);
  }
  return;
}

