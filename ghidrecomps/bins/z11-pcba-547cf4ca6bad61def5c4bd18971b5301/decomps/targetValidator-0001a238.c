
undefined4 targetValidator(void *param_1,void *param_2)

{
  undefined4 uVar1;
  undefined auStack_61c [32];
  undefined auStack_5fc [32];
  undefined auStack_5dc [140];
  undefined2 local_550;
  undefined local_54e;
  undefined auStack_54d [1345];
  undefined4 local_c;
  
  memset(auStack_5dc,0,0x5cf);
  memset(auStack_5fc,0,0x20);
  memset(auStack_61c,0,0x20);
  memcpy(auStack_5dc,param_1,0x8c);
  local_550 = (undefined2)local_c;
  local_54e = (undefined)((uint)local_c >> 0x10);
  memcpy(auStack_54d,param_2,0x540);
  Sha256_Onestep(auStack_5dc,0x5cf,auStack_5fc);
  Sha256_Onestep(auStack_5fc,0x20,auStack_61c);
  uVar1 = target_zero_cal(auStack_61c);
  return uVar1;
}

