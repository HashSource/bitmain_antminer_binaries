
undefined4 targetValidator(void *param_1,void *param_2)

{
  undefined4 uVar1;
  undefined4 local_61c;
  undefined4 local_618;
  undefined4 local_614;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 local_608;
  undefined4 local_604;
  undefined4 local_600;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined4 local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 local_5e0;
  undefined auStack_5dc [140];
  undefined2 local_550;
  undefined local_54e;
  undefined auStack_54d [1345];
  undefined4 local_c;
  
  memset(auStack_5dc,0,0x5cf);
  local_5fc = 0;
  local_5f8 = 0;
  local_5f4 = 0;
  local_5f0 = 0;
  local_5ec = 0;
  local_5e8 = 0;
  local_5e4 = 0;
  local_5e0 = 0;
  local_61c = 0;
  local_618 = 0;
  local_614 = 0;
  local_610 = 0;
  local_60c = 0;
  local_608 = 0;
  local_604 = 0;
  local_600 = 0;
  memcpy(auStack_5dc,param_1,0x8c);
  local_550 = (undefined2)local_c;
  local_54e = (undefined)((uint)local_c >> 0x10);
  memcpy(auStack_54d,param_2,0x540);
  Sha256_Onestep(auStack_5dc,0x5cf,&local_5fc);
  Sha256_Onestep(&local_5fc,0x20,&local_61c);
  uVar1 = target_zero_cal(&local_61c);
  return uVar1;
}

