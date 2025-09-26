
uint * o2i_SCT(int *param_1,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *local_2c [2];
  
  if (0xfffe < param_3 - 1) {
    ERR_put_error(0x32,0x6e,0x68,"crypto/ct/ct_oct.c",0x4c);
    SCT_free(0);
    return (uint *)0x0;
  }
  puVar3 = (uint *)SCT_new();
  if (puVar3 != (uint *)0x0) {
    local_2c[0] = (byte *)*param_2;
    bVar1 = *local_2c[0];
    *puVar3 = (uint)bVar1;
    if (bVar1 == 0) {
      if (param_3 < 0x2b) {
        iVar5 = 99;
      }
      else {
        local_2c[0] = local_2c[0] + 1;
        uVar4 = CRYPTO_memdup(local_2c[0],0x20,"crypto/ct/ct_oct.c",0x68);
        puVar3[3] = uVar4;
        if (uVar4 == 0) goto LAB_0011e368;
        puVar3[4] = 0x20;
        bVar2 = local_2c[0][0x20];
        pbVar8 = local_2c[0] + 0x2a;
        puVar3[6] = 0;
        puVar3[7] = (uint)bVar2 << 0x18;
        uVar6 = (uint)local_2c[0][0x21] << 0x10 | (uint)bVar2 << 0x18;
        puVar3[6] = (uint)bVar1;
        puVar3[7] = uVar6;
        uVar6 = uVar6 | (uint)local_2c[0][0x22] << 8;
        puVar3[6] = (uint)bVar1;
        puVar3[7] = uVar6;
        uVar6 = local_2c[0][0x23] | uVar6;
        puVar3[6] = (uint)bVar1;
        puVar3[7] = uVar6;
        uVar4 = (uint)bVar1 | (uint)local_2c[0][0x24] << 0x18;
        puVar3[6] = uVar4;
        puVar3[7] = uVar6;
        uVar4 = (uint)local_2c[0][0x25] << 0x10 | uVar4;
        puVar3[6] = uVar4;
        puVar3[7] = uVar6;
        uVar4 = (uint)local_2c[0][0x26] << 8 | uVar4;
        puVar3[6] = uVar4;
        puVar3[7] = uVar6;
        puVar3[6] = uVar4 | local_2c[0][0x27];
        puVar3[7] = uVar6;
        uVar4 = (uint)CONCAT11(local_2c[0][0x28],local_2c[0][0x29]);
        local_2c[0] = pbVar8;
        if (param_3 - 0x2b < uVar4) {
          iVar5 = 0x72;
        }
        else {
          if (uVar4 != 0) {
            uVar6 = CRYPTO_memdup(pbVar8,uVar4,"crypto/ct/ct_oct.c",0x76);
            puVar3[8] = uVar6;
            if (uVar6 == 0) goto LAB_0011e368;
          }
          local_2c[0] = local_2c[0] + uVar4;
          iVar7 = (param_3 - 0x2b) - uVar4;
          puVar3[9] = uVar4;
          iVar5 = o2i_SCT_signature(puVar3,local_2c,iVar7);
          if (0 < iVar5) {
            *param_2 = local_2c[0] + (iVar7 - iVar5);
            goto LAB_0011e308;
          }
          iVar5 = 0x80;
        }
      }
      ERR_put_error(0x32,0x6e,0x68,"crypto/ct/ct_oct.c",iVar5);
    }
    else {
      uVar4 = CRYPTO_memdup(local_2c[0],param_3,"crypto/ct/ct_oct.c",0x87);
      puVar3[1] = uVar4;
      if (uVar4 != 0) {
        puVar3[2] = param_3;
        *param_2 = local_2c[0] + param_3;
LAB_0011e308:
        if (param_1 != (int *)0x0) {
          SCT_free(*param_1);
          *param_1 = (int)puVar3;
        }
        return puVar3;
      }
    }
  }
LAB_0011e368:
  SCT_free(puVar3);
  return (uint *)0x0;
}

