
undefined4 blake2b_init_key(undefined4 param_1,byte param_2,void *param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_c8 [128];
  byte local_48;
  byte local_47;
  undefined local_46;
  undefined local_45;
  undefined auStack_44 [4];
  undefined auStack_40 [8];
  undefined local_38;
  undefined local_37;
  undefined auStack_36 [14];
  undefined auStack_28 [16];
  undefined auStack_18 [16];
  
  if ((param_2 == 0) || (0x40 < param_2)) {
    uVar2 = 0xffffffff;
  }
  else if ((param_3 == (void *)0x0) || ((param_4 == 0 || (0x40 < param_4)))) {
    uVar2 = 0xffffffff;
  }
  else {
    local_46 = 1;
    local_45 = 1;
    local_48 = param_2;
    local_47 = param_4;
    store32(auStack_44,0);
    store64(auStack_40,auStack_40,0,0);
    local_38 = 0;
    local_37 = 0;
    memset(auStack_36,0,0xe);
    memset(auStack_28,0,0x10);
    memset(auStack_18,0,0x10);
    iVar1 = blake2b_init_param(param_1,&local_48);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      memset(auStack_c8,0,0x80);
      memcpy(auStack_c8,param_3,(uint)param_4);
      blake2b_update(param_1,auStack_c8,0x80,0);
      secure_zero_memory(auStack_c8,0x80);
      uVar2 = 0;
    }
  }
  return uVar2;
}

