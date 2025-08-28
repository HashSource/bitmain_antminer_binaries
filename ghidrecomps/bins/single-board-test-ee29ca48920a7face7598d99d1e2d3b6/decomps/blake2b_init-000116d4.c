
undefined4 blake2b_init(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  byte local_48 [8];
  undefined1 auStack_40 [8];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 auStack_36 [14];
  undefined1 auStack_28 [16];
  undefined1 auStack_18 [16];
  
  if ((param_2 == 0) || (0x40 < param_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    local_48[1] = 0;
    local_48[2] = 1;
    local_48[3] = 1;
    local_48[0] = param_2;
    store32(local_48 + 4,0);
    store64(auStack_40,auStack_40,0,0);
    local_38 = 0;
    local_37 = 0;
    memset(auStack_36,0,0xe);
    memset(auStack_28,0,0x10);
    memset(auStack_18,0,0x10);
    uVar1 = blake2b_init_param(param_1,local_48);
  }
  return uVar1;
}

