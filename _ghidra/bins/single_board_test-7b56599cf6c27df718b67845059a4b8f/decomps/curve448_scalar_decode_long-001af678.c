
void curve448_scalar_decode_long(undefined4 *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  undefined **ppuVar4;
  uint uVar5;
  uint uVar6;
  undefined ***pppuVar7;
  undefined **local_9c;
  undefined **local_98 [14];
  undefined1 auStack_60 [60];
  
  local_9c = &_GLOBAL_OFFSET_TABLE_;
  if (param_3 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
  }
  else {
    pppuVar7 = &local_9c;
    uVar5 = 0;
    uVar6 = (param_3 / 0x38) * 0x38;
    if (param_3 == uVar6) {
      uVar6 = param_3 - 0x38;
    }
    do {
      while (param_3 - uVar6 <= uVar5) {
        pppuVar7 = pppuVar7 + 1;
        *pppuVar7 = (undefined **)0x0;
        if (pppuVar7 == local_98 + 0xd) goto LAB_001af718;
      }
      ppuVar4 = (undefined **)0x0;
      pbVar1 = (byte *)(uVar6 + uVar5 + param_2);
      uVar2 = 0;
      do {
        uVar3 = uVar2 + 1;
        uVar5 = uVar5 + 1;
        ppuVar4 = (undefined **)((uint)ppuVar4 | (uint)*pbVar1 << ((uVar2 & 0x1f) << 3));
        pbVar1 = pbVar1 + 1;
        uVar2 = uVar3;
      } while (uVar5 < param_3 - uVar6 && uVar3 < 4);
      pppuVar7 = pppuVar7 + 1;
      *pppuVar7 = ppuVar4;
    } while (pppuVar7 != local_98 + 0xd);
LAB_001af718:
    if (param_3 != 0x38) {
      if (uVar6 != 0) {
        do {
          uVar6 = uVar6 - 0x38;
          sc_montmul(local_98,local_98,&sc_r2);
          curve448_scalar_decode(auStack_60,param_2 + uVar6);
          curve448_scalar_add(local_98,local_98,auStack_60);
        } while (uVar6 != 0);
      }
      *param_1 = local_98[0];
      param_1[1] = local_98[1];
      param_1[2] = local_98[2];
      param_1[3] = local_98[3];
      param_1[4] = local_98[4];
      param_1[5] = local_98[5];
      param_1[6] = local_98[6];
      param_1[7] = local_98[7];
      param_1[8] = local_98[8];
      param_1[9] = local_98[9];
      param_1[10] = local_98[10];
      param_1[0xb] = local_98[0xb];
      param_1[0xc] = local_98[0xc];
      param_1[0xd] = local_98[0xd];
      curve448_scalar_destroy(local_98);
      curve448_scalar_destroy(auStack_60);
      return;
    }
    curve448_scalar_mul(param_1,local_98,curve448_scalar_one);
    curve448_scalar_destroy(local_98);
  }
  return;
}

