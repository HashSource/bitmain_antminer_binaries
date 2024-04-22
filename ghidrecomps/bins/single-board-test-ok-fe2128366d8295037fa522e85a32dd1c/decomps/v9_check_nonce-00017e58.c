
undefined4 v9_check_nonce(byte param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  
  bVar1 = *param_2;
  bVar2 = param_2[1];
  bVar3 = param_2[2];
  bVar4 = param_2[3];
  uVar5 = __udivsi3(*param_2,gChain_Asic_Interval);
  uVar6 = param_2[3] & 0x3f;
  uVar7 = param_2[4] & 0x7f;
  if (uVar5 < 0x2d) {
    if (uVar6 < 0x32) {
      if (uVar7 < (uint)Conf._64_4_) {
        iVar9 = *(int *)(cgpu + (uVar5 + 0x402a) * 4 + 4) + (uVar6 * Conf._64_4_ + uVar7) * 0x74;
        if (((uint)bVar4 | (uint)bVar1 << 0x18 | (uint)bVar2 << 0x10 | (uint)bVar3 << 8) ==
            *(uint *)(iVar9 + 4)) {
          if (*(int *)(iVar9 + (param_1 + 0xc) * 4 + 4) == 0) {
            *(int *)(iVar9 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar9 + (param_1 + 0xc) * 4 + 4) + 1;
            *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) =
                 *(int *)(gValid_Nonce_Num + (uint)param_1 * 4) + 1;
            *(int *)(gAsic_Core_Nonce_Num + (((uint)param_1 * 0x80 + uVar5) * 0x80 + uVar6) * 4) =
                 *(int *)(gAsic_Core_Nonce_Num + (((uint)param_1 * 0x80 + uVar5) * 0x80 + uVar6) * 4
                         ) + 1;
          }
          else {
            *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) =
                 *(int *)(gRepeated_Nonce_Id + (uint)param_1 * 4) + 1;
            *(int *)(iVar9 + (param_1 + 0xc) * 4 + 4) =
                 *(int *)(iVar9 + (param_1 + 0xc) * 4 + 4) + 1;
          }
        }
        uVar8 = 0;
      }
      else {
        printf("%s: received work_id = %02d nonce. error!!!\t","v9_check_nonce",uVar7);
        printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
               (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
        uVar8 = 0xffffffff;
      }
    }
    else {
      printf("%s: received core%02d nonce. error!!!\t","v9_check_nonce",uVar6);
      printf(",received data is : 0x%02x%02x%02x%02x%02x\n",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4]);
      uVar8 = 0xffffffff;
    }
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}

