
undefined4 RAND_DRBG_set_reseed_defaults(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  
  bVar4 = 0xffffff < param_2;
  bVar3 = param_2 == 0x1000000;
  if (param_2 < 0x1000001) {
    bVar4 = 0xffffff < param_1;
    bVar3 = param_1 == 0x1000000;
  }
  if (bVar4 && !bVar3) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    bVar4 = SBORROW4(param_4,0x100000);
    iVar1 = param_4 + -0x100000;
    bVar3 = param_4 == 0x100000;
    if (param_4 < 0x100001) {
      bVar4 = SBORROW4(param_3,0x100000);
      iVar1 = param_3 + -0x100000;
      bVar3 = param_3 == 0x100000;
    }
    if (bVar3 || iVar1 < 0 != bVar4) {
      uVar2 = 1;
      master_reseed_interval = param_1;
      slave_reseed_interval = param_2;
      master_reseed_time_interval = param_3;
      slave_reseed_time_interval = param_4;
    }
  }
  return uVar2;
}

