
undefined4 targetValidator(void *param_1,void *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_61c [32];
  undefined1 auStack_5fc [32];
  undefined1 auStack_5dc [140];
  undefined2 local_550;
  undefined1 local_54e;
  undefined1 auStack_54d [1345];
  undefined3 local_c;
  undefined1 uStack_9;
  
  _local_c = CONCAT13(uStack_9,0x540fd);
  memset(auStack_5dc,0,0x5cf);
  memset(auStack_5fc,0,0x20);
  memset(auStack_61c,0,0x20);
  memcpy(auStack_5dc,param_1,0x8c);
  local_550 = (undefined2)_local_c;
  local_54e = (undefined1)((uint)_local_c >> 0x10);
  memcpy(auStack_54d,param_2,0x540);
  Sha256_Onestep(auStack_5dc,0x5cf,auStack_5fc);
  Sha256_Onestep(auStack_5fc,0x20,auStack_61c);
  uVar1 = target_zero_cal(auStack_61c);
  return uVar1;
}

