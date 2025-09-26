
undefined4 CRYPTO_ocb128_setiv(undefined4 *param_1,void *param_2,size_t param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  code *pcVar15;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  int local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  int local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined2 uStack_43;
  byte local_41;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  byte local_30 [12];
  
  if ((param_3 - 1 < 0xf) && (param_4 - 1 < 0x10)) {
    memset(param_1 + 0x12,0,0x50);
    local_50 = (param_4 & 0xf) << 4;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_43 = 0;
    local_41 = 0;
    memcpy((void *)((int)&local_40 - param_3),param_2,param_3);
    pcVar15 = (code *)*param_1;
    (&local_41)[-param_3] = (&local_41)[-param_3] | 1;
    local_60 = local_50;
    uStack_5c = uStack_4c;
    uStack_58 = uStack_48;
    uStack_54 = CONCAT13(local_41,CONCAT21(uStack_43,uStack_44)) & 0xc0ffffff;
    (*pcVar15)(&local_60,&local_70,param_1[2]);
    uVar14 = ((uint)local_41 << 0x1a) >> 0x1d;
    local_40 = local_70;
    uStack_3c = local_6c;
    uStack_38 = local_68;
    uStack_34 = uStack_64;
    uVar13 = local_41 & 7;
    uVar12 = 8 - uVar13;
    local_30[0] = local_70._1_1_ ^ (byte)local_70;
    local_30[1] = local_70._1_1_ ^ local_70._2_1_;
    local_30[2] = local_70._2_1_ ^ local_70._3_1_;
    local_30[3] = local_70._3_1_ ^ (byte)local_6c;
    local_30[4] = (byte)local_6c ^ local_6c._1_1_;
    local_30[5] = local_6c._1_1_ ^ local_6c._2_1_;
    local_30[6] = local_6c._2_1_ ^ local_6c._3_1_;
    bVar1 = local_30[uVar14 - 1];
    bVar2 = local_30[uVar14 - 2];
    bVar3 = local_30[uVar14 - 3];
    bVar4 = local_30[uVar14 - 4];
    *(byte *)((int)param_1 + 0x86) = (byte)((int)(uint)bVar1 >> (uVar12 & 0xff)) | bVar2 << uVar13;
    *(byte *)((int)param_1 + 0x85) = bVar3 << uVar13 | (byte)((int)(uint)bVar2 >> (uVar12 & 0xff));
    bVar2 = *(byte *)((int)&uStack_38 + uVar14 + 2);
    bVar5 = *(byte *)((int)&uStack_38 + uVar14 + 3);
    *(byte *)(param_1 + 0x21) = (byte)((int)(uint)bVar3 >> (uVar12 & 0xff)) | bVar4 << uVar13;
    bVar3 = *(byte *)((int)&uStack_38 + uVar14 + 1);
    bVar6 = *(byte *)((int)&uStack_38 + uVar14);
    bVar7 = *(byte *)((int)&uStack_3c + uVar14 + 3);
    bVar8 = *(byte *)((int)&uStack_3c + uVar14 + 2);
    *(byte *)((int)param_1 + 0x82) = bVar2 << uVar13 | (byte)((int)(uint)bVar5 >> (uVar12 & 0xff));
    bVar9 = *(byte *)((int)&uStack_3c + uVar14 + 1);
    *(byte *)((int)param_1 + 0x81) = bVar3 << uVar13 | (byte)((int)(uint)bVar2 >> (uVar12 & 0xff));
    bVar2 = *(byte *)((int)&local_40 + uVar14 + 3);
    bVar10 = *(byte *)((int)&local_40 + uVar14 + 2);
    *(byte *)(param_1 + 0x20) = bVar6 << uVar13 | (byte)((int)(uint)bVar3 >> (uVar12 & 0xff));
    bVar3 = *(byte *)((int)&local_40 + uVar14 + 1);
    *(byte *)((int)param_1 + 0x83) = bVar5 << uVar13 | (byte)((int)(uint)bVar4 >> (uVar12 & 0xff));
    *(byte *)((int)param_1 + 0x7f) = bVar7 << uVar13 | (byte)((int)(uint)bVar6 >> (uVar12 & 0xff));
    bVar4 = *(byte *)((int)&uStack_3c + uVar14);
    cVar11 = *(char *)((int)&local_40 + uVar14);
    bVar5 = local_30[uVar14];
    *(byte *)((int)param_1 + 0x7e) = bVar8 << uVar13 | (byte)((int)(uint)bVar7 >> (uVar12 & 0xff));
    *(byte *)((int)param_1 + 0x7d) = bVar9 << uVar13 | (byte)((int)(uint)bVar8 >> (uVar12 & 0xff));
    *(byte *)((int)param_1 + 0x87) =
         (byte)((int)((uint)bVar5 & 0xff << (uVar12 & 0xff)) >> (uVar12 & 0xff)) | bVar1 << uVar13;
    *(byte *)(param_1 + 0x1f) = bVar4 << uVar13 | (byte)((int)(uint)bVar9 >> (uVar12 & 0xff));
    *(byte *)((int)param_1 + 0x7b) = (byte)((int)(uint)bVar4 >> (uVar12 & 0xff)) | bVar2 << uVar13;
    *(byte *)((int)param_1 + 0x7a) = bVar10 << uVar13 | (byte)((int)(uint)bVar2 >> (uVar12 & 0xff));
    *(byte *)((int)param_1 + 0x79) = bVar3 << uVar13 | (byte)((int)(uint)bVar10 >> (uVar12 & 0xff));
    *(byte *)(param_1 + 0x1e) = cVar11 << uVar13 | (byte)((int)(uint)bVar3 >> (uVar12 & 0xff));
    return 1;
  }
  return 0xffffffff;
}

