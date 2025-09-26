
void DES_cfb_encrypt(uchar *in,uchar *out,int numbits,long length,DES_key_schedule *schedule,
                    DES_cblock *ivec,int enc)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uchar *puVar7;
  uint uVar8;
  uchar *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uchar *local_58;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  
  if (numbits - 1U < 0x40) {
    uVar10 = numbits + 7 >> 3;
    uVar13 = *(uint *)(*ivec + 4);
    iVar2 = numbits >> 3;
    uVar11 = numbits & 7;
    uVar14 = *(uint *)*ivec;
    local_58 = in;
    if (enc == 0) {
      if (uVar10 <= (uint)length) {
        uVar8 = uVar14;
        uVar15 = uVar13;
        uVar5 = length - uVar10;
        do {
          local_40 = uVar8;
          local_3c = uVar15;
          DES_encrypt1(&local_40,schedule,1);
          puVar7 = local_58 + uVar10;
          switch(uVar10 - 2) {
          case 0:
            uVar12 = 0;
            uVar6 = uVar12;
            goto LAB_0019de14;
          case 1:
            uVar12 = 0;
            uVar6 = uVar12;
            goto LAB_0019de0a;
          case 2:
            uVar6 = 0;
            goto LAB_0019de02;
          case 3:
            uVar6 = 0;
            goto LAB_0019ddfa;
          case 4:
            uVar6 = 0;
            goto LAB_0019ddf0;
          case 5:
            uVar6 = 0;
            break;
          case 6:
            pbVar3 = puVar7 + -1;
            puVar7 = puVar7 + -1;
            uVar6 = (uint)*pbVar3 << 0x18;
            break;
          default:
            uVar12 = 0;
            uVar6 = uVar12;
            goto LAB_0019de1e;
          }
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar6 = uVar6 | (uint)*pbVar3 << 0x10;
LAB_0019ddf0:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar6 = uVar6 | (uint)*pbVar3 << 8;
LAB_0019ddfa:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar6 = uVar6 | *pbVar3;
LAB_0019de02:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar12 = (uint)*pbVar3 << 0x18;
LAB_0019de0a:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar12 = uVar12 | (uint)*pbVar3 << 0x10;
LAB_0019de14:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar12 = uVar12 | (uint)*pbVar3 << 8;
LAB_0019de1e:
          local_58 = puVar7 + (uVar10 - 1);
          uVar12 = uVar12 | puVar7[-1];
          uVar14 = uVar15;
          uVar13 = uVar12;
          if ((numbits != 0x20) && (uVar14 = uVar12, uVar13 = uVar6, numbits != 0x40)) {
            local_38 = uVar8;
            local_34 = uVar15;
            local_30 = uVar12;
            local_2c = uVar6;
            if (uVar11 == 0) {
              memmove(&local_38,(void *)((int)&local_38 + iVar2),8);
              uVar14 = local_38;
              uVar13 = local_34;
            }
            else {
              uVar14 = 8 - uVar11;
              bVar4 = (byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 1) >> (uVar14 & 0xff)) |
                      *(char *)((int)&local_38 + iVar2) << uVar11;
              local_38._1_3_ = (undefined3)(uVar8 >> 8);
              local_38 = CONCAT31(local_38._1_3_,bVar4);
              local_38._2_2_ = (undefined2)(uVar8 >> 0x10);
              local_38._0_2_ =
                   CONCAT11((byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 2) >>
                                  (uVar14 & 0xff)) | *(char *)((int)&local_38 + iVar2 + 1) << uVar11
                            ,bVar4);
              local_38._3_1_ = (undefined1)(uVar8 >> 0x18);
              local_38._0_3_ =
                   CONCAT12((byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 3) >>
                                  (uVar14 & 0xff)) | *(char *)((int)&local_38 + iVar2 + 2) << uVar11
                            ,(undefined2)local_38);
              local_38 = CONCAT13((byte)((int)(uint)*(byte *)((int)&local_34 + iVar2) >>
                                        (uVar14 & 0xff)) |
                                  *(char *)((int)&local_38 + iVar2 + 3) << uVar11,
                                  (undefined3)local_38);
              bVar4 = (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 1) >> (uVar14 & 0xff)) |
                      *(char *)((int)&local_34 + iVar2) << uVar11;
              local_34._1_3_ = (undefined3)(uVar15 >> 8);
              local_34 = CONCAT31(local_34._1_3_,bVar4);
              local_34._2_2_ = (undefined2)(uVar15 >> 0x10);
              local_34._0_2_ =
                   CONCAT11((byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 2) >>
                                  (uVar14 & 0xff)) | *(char *)((int)&local_34 + iVar2 + 1) << uVar11
                            ,bVar4);
              local_34._3_1_ = (undefined1)(uVar15 >> 0x18);
              local_34._0_3_ =
                   CONCAT12(*(char *)((int)&local_34 + iVar2 + 2) << uVar11 |
                            (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 3) >>
                                  (uVar14 & 0xff)),(undefined2)local_34);
              local_34 = CONCAT13(*(char *)((int)&local_34 + iVar2 + 3) << uVar11 |
                                  (byte)((int)(uint)*(byte *)((int)&local_30 + iVar2) >>
                                        (uVar14 & 0xff)),(undefined3)local_34);
              uVar14 = local_38;
              uVar13 = local_34;
            }
          }
          puVar9 = out + uVar10;
          uVar6 = uVar6 ^ local_3c;
          uVar12 = uVar12 ^ local_40;
          puVar7 = puVar9;
          switch(uVar10) {
          case 0:
                    /* WARNING: This code block may not be properly labeled as switch case */
            goto LAB_0019df86;
          case 1:
            goto switchD_0019df4e_caseD_1;
          case 2:
            goto LAB_0019df76;
          case 3:
            goto switchD_0019df4e_caseD_3;
          case 4:
            break;
          case 6:
            puVar7 = puVar9 + -1;
            *puVar7 = (uchar)(uVar6 >> 0x18);
          case 5:
            puVar9 = puVar7 + -1;
            puVar7[-1] = (uchar)(uVar6 >> 0x10);
            break;
          default:
            goto switchD_0019df4e_default;
          }
          puVar7 = puVar9 + -1;
          puVar9[-1] = (uchar)(uVar6 >> 8);
switchD_0019df4e_caseD_3:
          puVar9 = puVar7 + -1;
          puVar7[-1] = (uchar)uVar6;
LAB_0019df76:
          puVar7 = puVar9 + -1;
          puVar9[-1] = (uchar)(uVar12 >> 0x18);
switchD_0019df4e_caseD_1:
                    /* WARNING: This code block may not be properly labeled as switch case */
          puVar9 = puVar7 + -1;
          puVar7[-1] = (uchar)(uVar12 >> 0x10);
LAB_0019df86:
          puVar7 = puVar9 + -1;
          puVar9[-1] = (uchar)(uVar12 >> 8);
switchD_0019df4e_default:
          puVar7[-1] = (uchar)uVar12;
          out = puVar7 + (uVar10 - 1);
          bVar1 = uVar10 <= uVar5;
          uVar8 = uVar14;
          uVar15 = uVar13;
          uVar5 = uVar5 - uVar10;
        } while (bVar1);
      }
    }
    else {
      uVar8 = uVar13;
      uVar15 = uVar14;
      while (uVar14 = uVar15, uVar13 = uVar8, uVar10 <= (uint)length) {
        length = length - uVar10;
        local_40 = uVar14;
        local_3c = uVar13;
        DES_encrypt1(&local_40,schedule,1);
        puVar7 = local_58 + uVar10;
        switch(uVar10 - 2) {
        case 0:
          uVar5 = 0;
          uVar8 = uVar5;
          goto LAB_0019dffe;
        case 1:
          uVar5 = 0;
          uVar8 = uVar5;
          goto LAB_0019dff4;
        case 2:
          uVar5 = 0;
          goto LAB_0019dfec;
        case 3:
          uVar5 = 0;
          goto LAB_0019dfe4;
        case 4:
          uVar5 = 0;
          goto LAB_0019dfda;
        case 5:
          uVar5 = 0;
          break;
        case 6:
          pbVar3 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          uVar5 = (uint)*pbVar3 << 0x18;
          break;
        default:
          uVar5 = 0;
          uVar8 = uVar5;
          goto LAB_0019e008;
        }
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar5 = uVar5 | (uint)*pbVar3 << 0x10;
LAB_0019dfda:
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar5 = uVar5 | (uint)*pbVar3 << 8;
LAB_0019dfe4:
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar5 = uVar5 | *pbVar3;
LAB_0019dfec:
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar8 = (uint)*pbVar3 << 0x18;
LAB_0019dff4:
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar8 = uVar8 | (uint)*pbVar3 << 0x10;
LAB_0019dffe:
        pbVar3 = puVar7 + -1;
        puVar7 = puVar7 + -1;
        uVar8 = uVar8 | (uint)*pbVar3 << 8;
LAB_0019e008:
        local_58 = puVar7 + (uVar10 - 1);
        puVar9 = out + uVar10;
        uVar6 = (puVar7[-1] | uVar8) ^ local_40;
        uVar5 = uVar5 ^ local_3c;
        puVar7 = puVar9;
        switch(uVar10) {
        case 2:
          goto LAB_0019e068;
        case 3:
          goto switchD_0019e026_caseD_3;
        case 4:
          goto LAB_0019e054;
        case 5:
          goto switchD_0019e026_caseD_5;
        case 6:
          puVar7 = puVar9;
          break;
        case 8:
          puVar9 = puVar9 + -1;
          *puVar9 = (uchar)(uVar5 >> 0x18);
        case 7:
          puVar9[-1] = (uchar)(uVar5 >> 0x10);
          puVar7 = puVar9 + -1;
          break;
        default:
          goto switchD_0019e026_default;
        }
        puVar9 = puVar7 + -1;
        puVar7[-1] = (uchar)(uVar5 >> 8);
switchD_0019e026_caseD_5:
        puVar9[-1] = (uchar)uVar5;
        puVar9 = puVar9 + -1;
LAB_0019e054:
        puVar7 = puVar9 + -1;
        puVar9[-1] = (uchar)(uVar6 >> 0x18);
switchD_0019e026_caseD_3:
        puVar9 = puVar7 + -1;
        puVar7[-1] = (uchar)(uVar6 >> 0x10);
LAB_0019e068:
        puVar7 = puVar9 + -1;
        puVar9[-1] = (uchar)(uVar6 >> 8);
switchD_0019e026_default:
        puVar7[-1] = (uchar)uVar6;
        out = puVar7 + (uVar10 - 1);
        uVar8 = uVar6;
        uVar15 = uVar13;
        if ((numbits != 0x20) && (uVar8 = uVar5, uVar15 = uVar6, numbits != 0x40)) {
          local_38 = uVar14;
          local_34 = uVar13;
          local_30 = uVar6;
          local_2c = uVar5;
          if (uVar11 == 0) {
            memmove(&local_38,(void *)((int)&local_38 + iVar2),8);
            uVar8 = local_34;
            uVar15 = local_38;
          }
          else {
            uVar8 = 8 - uVar11;
            bVar4 = *(char *)((int)&local_38 + iVar2) << uVar11 |
                    (byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 1) >> (uVar8 & 0xff));
            local_38._1_3_ = (undefined3)(uVar14 >> 8);
            local_38 = CONCAT31(local_38._1_3_,bVar4);
            local_38._2_2_ = (undefined2)(uVar14 >> 0x10);
            local_38._0_2_ =
                 CONCAT11(*(char *)((int)&local_38 + iVar2 + 1) << uVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 2) >> (uVar8 & 0xff))
                          ,bVar4);
            local_38._3_1_ = (undefined1)(uVar14 >> 0x18);
            local_38._0_3_ =
                 CONCAT12(*(char *)((int)&local_38 + iVar2 + 2) << uVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_38 + iVar2 + 3) >> (uVar8 & 0xff))
                          ,(undefined2)local_38);
            local_38 = CONCAT13(*(char *)((int)&local_38 + iVar2 + 3) << uVar11 |
                                (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2) >>
                                      (uVar8 & 0xff)),(undefined3)local_38);
            bVar4 = *(char *)((int)&local_34 + iVar2) << uVar11 |
                    (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 1) >> (uVar8 & 0xff));
            local_34._1_3_ = (undefined3)(uVar13 >> 8);
            local_34 = CONCAT31(local_34._1_3_,bVar4);
            local_34._2_2_ = (undefined2)(uVar13 >> 0x10);
            local_34._0_2_ =
                 CONCAT11(*(char *)((int)&local_34 + iVar2 + 1) << uVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 2) >> (uVar8 & 0xff))
                          ,bVar4);
            local_34._3_1_ = (undefined1)(uVar13 >> 0x18);
            local_34._0_3_ =
                 CONCAT12(*(char *)((int)&local_34 + iVar2 + 2) << uVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_34 + iVar2 + 3) >> (uVar8 & 0xff))
                          ,(undefined2)local_34);
            local_34 = CONCAT13(*(char *)((int)&local_34 + iVar2 + 3) << uVar11 |
                                (byte)((int)(uint)*(byte *)((int)&local_30 + iVar2) >>
                                      (uVar8 & 0xff)),(undefined3)local_34);
            uVar8 = local_34;
            uVar15 = local_38;
          }
        }
      }
    }
    (*ivec)[0] = (uchar)uVar14;
    (*ivec)[4] = (uchar)uVar13;
    (*ivec)[1] = (uchar)(uVar14 >> 8);
    (*ivec)[2] = (uchar)(uVar14 >> 0x10);
    (*ivec)[3] = (uchar)(uVar14 >> 0x18);
    (*ivec)[5] = (uchar)(uVar13 >> 8);
    (*ivec)[6] = (uchar)(uVar13 >> 0x10);
    (*ivec)[7] = (uchar)(uVar13 >> 0x18);
  }
  return;
}

