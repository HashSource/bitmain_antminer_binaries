
undefined4 cswift_rand_bytes(char *param_1,size_t param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_448;
  undefined4 local_444;
  char *local_440;
  char acStack_43c [20];
  char acStack_428 [1028];
  
  iVar1 = DAT_000db3f8;
  iVar2 = (**(code **)(DAT_000db3f8 + 0xc))(&local_448);
  if (iVar2 == 0) {
    if (0x3ff < (int)param_2) {
      pcVar6 = param_1;
      do {
        local_444 = 0x400;
        param_2 = param_2 - 0x400;
        param_1 = pcVar6 + 0x400;
        local_440 = pcVar6;
        iVar3 = (**(code **)(iVar1 + 0x14))(local_448,5,0,0,&local_444,1);
        iVar2 = DAT_000db3f8;
        if (iVar3 != 0) {
          iVar4 = *(int *)(DAT_000db3f8 + 4);
          if (iVar4 == 0) {
            iVar4 = ERR_get_next_error_library();
            *(int *)(iVar2 + 4) = iVar4;
          }
          uVar5 = 0;
          ERR_put_error(iVar4,0x6c,0x6b,DAT_000db3f4,0x419);
          sprintf(acStack_428,DAT_000db3fc,iVar3);
          ERR_add_error_data(2,DAT_000db400,acStack_428);
          goto LAB_000db368;
        }
        pcVar6 = param_1;
      } while (0x3ff < (int)param_2);
    }
    if (param_2 == 0) {
      uVar5 = 1;
    }
    else {
      local_440 = acStack_428;
      uVar5 = 1;
      local_444 = 0x400;
      iVar3 = (**(code **)(iVar1 + 0x14))(local_448,5,0,0,&local_444,1);
      iVar2 = DAT_000db3f8;
      if (iVar3 == 0) {
        memcpy(param_1,local_440,param_2);
      }
      else {
        iVar4 = *(int *)(DAT_000db3f8 + 4);
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar2 + 4) = iVar4;
        }
        uVar5 = 0;
        ERR_put_error(iVar4,0x6c,0x6b,DAT_000db3f4,0x428);
        sprintf(acStack_43c,DAT_000db3fc,iVar3);
        ERR_add_error_data(2,DAT_000db400,acStack_43c);
      }
    }
LAB_000db368:
    (**(code **)(iVar1 + 0x18))(local_448);
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    uVar5 = 0;
    ERR_put_error(iVar2,0x6c,0x6c,DAT_000db3f4,0x3fc);
  }
  return uVar5;
}

