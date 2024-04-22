
undefined4 hwcrhk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int lib;
  undefined *local_420;
  undefined4 local_41c;
  undefined auStack_418 [1028];
  
  iVar1 = DAT_000dc214;
  local_420 = auStack_418;
  local_41c = 0x400;
  if (*(int *)(DAT_000dc214 + 0x14) == 0) {
    iVar2 = *(int *)(DAT_000dc214 + 0x1c);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 0x1c) = iVar2;
    }
    ERR_put_error(iVar2,0x6c,0x6a,DAT_000dc218,0x45a);
    uVar3 = 0;
  }
  else {
    iVar2 = (**(code **)(DAT_000dc214 + 0x38))
                      (*(int *)(DAT_000dc214 + 0x14),param_1,param_2,&local_420);
    if (iVar2 < 0) {
      lib = *(int *)(iVar1 + 0x1c);
      if (iVar2 == -2) {
        if (lib == 0) {
          lib = ERR_get_next_error_library();
          *(int *)(iVar1 + 0x1c) = lib;
        }
        ERR_put_error(lib,0x6c,0x70,DAT_000dc218,0x465);
      }
      else {
        if (lib == 0) {
          lib = ERR_get_next_error_library();
          *(int *)(iVar1 + 0x1c) = lib;
        }
        ERR_put_error(lib,0x6c,0x6f,DAT_000dc218,0x467);
      }
      ERR_add_error_data(1,local_420);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

