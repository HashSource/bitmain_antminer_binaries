
void digestInit(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined local_48 [2];
  undefined local_46;
  undefined local_45;
  undefined auStack_18 [16];
  
  memset(local_48,0,0x40);
  local_46 = 1;
  local_45 = 1;
  iVar1 = __aeabi_idiv(0x200,param_2);
  iVar1 = param_2 * iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  local_48[0] = (undefined)(iVar1 >> 3);
  zcashPerson(auStack_18,param_2,param_3);
  blake2b_init_param(param_1,local_48);
  return;
}

