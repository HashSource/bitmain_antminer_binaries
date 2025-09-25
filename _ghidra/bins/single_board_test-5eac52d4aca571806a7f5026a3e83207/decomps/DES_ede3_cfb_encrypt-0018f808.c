
void DES_ede3_cfb_encrypt
               (uchar *in,uchar *out,int numbits,long length,DES_key_schedule *ks1,
               DES_key_schedule *ks2,DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  bool bVar1;
  byte *pbVar2;
  uchar uVar3;
  uchar uVar5;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uchar *puVar17;
  uchar *puVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uchar *local_64;
  uchar *local_58;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  byte local_30;
  uchar local_2f;
  uchar local_2e;
  uchar local_2d;
  uchar local_2c;
  uchar local_2b;
  uchar local_2a;
  uchar local_29;
  uchar uVar4;
  byte bVar6;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  
  if (numbits < 0x41) {
    uVar12 = numbits + 7;
    uVar19 = uVar12 >> 3;
    uVar22 = *(uint *)*ivec;
    uVar21 = *(uint *)(*ivec + 4);
    if (enc == 0) {
      if (uVar19 <= (uint)length) {
        uVar12 = uVar12 & numbits >> 0x20;
        if (uVar19 > (uint)length) {
          uVar12 = numbits;
        }
        uVar11 = numbits & 7U;
        if (numbits < 1) {
          uVar11 = -(-numbits & 7U);
        }
        uVar16 = 8 - uVar11;
        pvVar13 = (void *)((int)&local_38 + ((int)uVar12 >> 3));
        uVar12 = length - uVar19;
        uVar20 = uVar21;
        uVar23 = uVar22;
        local_64 = out;
        local_58 = in;
        do {
          local_40 = uVar23;
          local_3c = uVar20;
          DES_encrypt3(&local_40,ks1,ks2,ks3);
          local_58 = local_58 + uVar19;
          switch(uVar19 - 1) {
          case 0:
            uVar15 = 0;
            uVar14 = uVar15;
            goto LAB_0018fb08;
          case 1:
            uVar15 = 0;
            uVar14 = uVar15;
            goto LAB_0018fafe;
          case 2:
            uVar15 = 0;
            uVar14 = uVar15;
            goto LAB_0018faf4;
          case 3:
            uVar14 = 0;
            goto LAB_0018faec;
          case 4:
            uVar14 = 0;
            goto LAB_0018fae4;
          case 5:
            uVar14 = 0;
            goto LAB_0018fada;
          case 6:
            uVar14 = 0;
            break;
          case 7:
            pbVar2 = local_58 + -1;
            local_58 = local_58 + -1;
            uVar14 = (uint)*pbVar2 << 0x18;
            break;
          default:
            uVar15 = 0;
            uVar14 = uVar15;
            goto LAB_0018fb10;
          }
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar14 = uVar14 | (uint)*pbVar2 << 0x10;
LAB_0018fada:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar14 = uVar14 | (uint)*pbVar2 << 8;
LAB_0018fae4:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar14 = uVar14 | *pbVar2;
LAB_0018faec:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar15 = (uint)*pbVar2 << 0x18;
LAB_0018faf4:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar15 = uVar15 | (uint)*pbVar2 << 0x10;
LAB_0018fafe:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar15 = uVar15 | (uint)*pbVar2 << 8;
LAB_0018fb08:
          pbVar2 = local_58 + -1;
          local_58 = local_58 + -1;
          uVar15 = uVar15 | *pbVar2;
LAB_0018fb10:
          local_58 = local_58 + uVar19;
          uVar21 = uVar15;
          uVar22 = uVar20;
          if ((numbits != 0x20) && (uVar21 = uVar14, uVar22 = uVar15, numbits != 0x40)) {
            local_2a = (uchar)(uVar14 >> 0x10);
            local_30 = (byte)uVar15;
            local_2c = (uchar)uVar14;
            local_2f = (uchar)(uVar15 >> 8);
            local_2e = (uchar)(uVar15 >> 0x10);
            local_2d = (uchar)(uVar15 >> 0x18);
            local_2b = (uchar)(uVar14 >> 8);
            local_29 = (uchar)(uVar14 >> 0x18);
            local_38 = uVar23;
            local_34 = uVar20;
            if ((numbits & 7U) == 0) {
              memmove(&local_38,pvVar13,8);
              uVar21 = local_34;
              uVar22 = local_38;
            }
            else {
              memmove(&local_38,pvVar13,9);
              local_38._0_2_ =
                   CONCAT11(local_38._1_1_ << (uVar11 & 0xff) |
                            (byte)((int)(uint)local_38._2_1_ >> (uVar16 & 0xff)),
                            (char)local_38 << (uVar11 & 0xff) |
                            (byte)((int)(uint)local_38._1_1_ >> (uVar16 & 0xff)));
              local_38._0_3_ =
                   CONCAT12(local_38._2_1_ << (uVar11 & 0xff) |
                            (byte)((int)(uint)local_38._3_1_ >> (uVar16 & 0xff)),
                            (undefined2)local_38);
              local_38 = CONCAT13(local_38._3_1_ << (uVar11 & 0xff) |
                                  (byte)((int)(local_34 & 0xff) >> (uVar16 & 0xff)),
                                  (undefined3)local_38);
              local_34._0_3_ =
                   CONCAT12(local_34._2_1_ << (uVar11 & 0xff) |
                            (byte)((int)(uint)local_34._3_1_ >> (uVar16 & 0xff)),
                            CONCAT11(local_34._1_1_ << (uVar11 & 0xff) |
                                     (byte)((int)(uint)local_34._2_1_ >> (uVar16 & 0xff)),
                                     (char)local_34 << (uVar11 & 0xff) |
                                     (byte)((int)(uint)local_34._1_1_ >> (uVar16 & 0xff))));
              local_34 = CONCAT13((byte)((int)(uint)local_30 >> (uVar16 & 0xff)) |
                                  local_34._3_1_ << (uVar11 & 0xff),(undefined3)local_34);
              uVar21 = local_34;
              uVar22 = local_38;
            }
          }
          uVar14 = uVar14 ^ local_3c;
          uVar15 = uVar15 ^ local_40;
          local_64 = local_64 + uVar19;
          puVar17 = local_64;
          switch(uVar19) {
          case 0:
                    /* WARNING: This code block may not be properly labeled as switch case */
            goto LAB_0018fca0;
          case 1:
            goto switchD_0018fc62_caseD_1;
          case 2:
            goto LAB_0018fc90;
          case 3:
            goto switchD_0018fc62_caseD_3;
          case 4:
            break;
          case 7:
            local_64 = local_64 + -1;
            *local_64 = (uchar)(uVar14 >> 0x18);
          case 6:
            puVar17 = local_64 + -1;
            *puVar17 = (uchar)(uVar14 >> 0x10);
          case 5:
            local_64 = puVar17 + -1;
            puVar17[-1] = (uchar)(uVar14 >> 8);
            break;
          default:
            goto switchD_0018fc62_default;
          }
          puVar17 = local_64 + -1;
          local_64[-1] = (uchar)uVar14;
switchD_0018fc62_caseD_3:
          local_64 = puVar17 + -1;
          puVar17[-1] = (uchar)(uVar15 >> 0x18);
LAB_0018fc90:
          puVar17 = local_64 + -1;
          local_64[-1] = (uchar)(uVar15 >> 0x10);
switchD_0018fc62_caseD_1:
          local_64 = puVar17 + -1;
          puVar17[-1] = (uchar)(uVar15 >> 8);
LAB_0018fca0:
          puVar17 = local_64 + -1;
          local_64[-1] = (uchar)uVar15;
switchD_0018fc62_default:
          local_64 = puVar17 + uVar19;
          bVar1 = uVar19 <= uVar12;
          uVar12 = uVar12 - uVar19;
          uVar20 = uVar21;
          uVar23 = uVar22;
        } while (bVar1);
      }
    }
    else if (uVar19 <= (uint)length) {
      uVar12 = uVar12 & numbits >> 0x20;
      if (uVar19 > (uint)length) {
        uVar12 = numbits;
      }
      uVar11 = numbits & 7U;
      if (numbits < 1) {
        uVar11 = -(-numbits & 7U);
      }
      uVar16 = 8 - uVar11;
      pvVar13 = (void *)((int)&local_38 + ((int)uVar12 >> 3));
      uVar12 = uVar21;
      uVar20 = length - uVar19;
      uVar23 = uVar22;
      do {
        puVar17 = in + uVar19;
        local_40 = uVar23;
        local_3c = uVar12;
        DES_encrypt3(&local_40,ks1,ks2,ks3);
        switch(uVar19 - 1) {
        case 0:
          uVar14 = 0;
          uVar15 = uVar14;
          goto LAB_0018fd26;
        case 1:
          uVar14 = 0;
          uVar21 = uVar14;
          goto LAB_0018fd1c;
        case 2:
          uVar14 = 0;
          uVar21 = uVar14;
          goto LAB_0018fd12;
        case 3:
          uVar14 = 0;
          goto LAB_0018fd0a;
        case 4:
          uVar14 = 0;
          goto LAB_0018fd02;
        case 5:
          uVar14 = 0;
          goto LAB_0018fcf8;
        case 6:
          uVar14 = 0;
          break;
        case 7:
          pbVar2 = puVar17 + -1;
          puVar17 = puVar17 + -1;
          uVar14 = (uint)*pbVar2 << 0x18;
          break;
        default:
          uVar15 = 0;
          uVar14 = uVar15;
          goto LAB_0018fd2e;
        }
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar14 = uVar14 | (uint)*pbVar2 << 0x10;
LAB_0018fcf8:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar14 = uVar14 | (uint)*pbVar2 << 8;
LAB_0018fd02:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar14 = uVar14 | *pbVar2;
LAB_0018fd0a:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar21 = (uint)*pbVar2 << 0x18;
LAB_0018fd12:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar21 = uVar21 | (uint)*pbVar2 << 0x10;
LAB_0018fd1c:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar15 = uVar21 | (uint)*pbVar2 << 8;
LAB_0018fd26:
        pbVar2 = puVar17 + -1;
        puVar17 = puVar17 + -1;
        uVar15 = *pbVar2 | uVar15;
LAB_0018fd2e:
        in = puVar17 + uVar19;
        puVar18 = out + uVar19;
        uVar14 = uVar14 ^ local_3c;
        uVar15 = local_40 ^ uVar15;
        uVar5 = (uchar)uVar14;
        bVar6 = (byte)uVar15;
        uVar7 = (uchar)(uVar14 >> 8);
        uVar3 = (uchar)(uVar14 >> 0x10);
        uVar4 = (uchar)(uVar14 >> 0x18);
        uVar8 = (uchar)(uVar15 >> 8);
        uVar9 = (uchar)(uVar15 >> 0x10);
        uVar10 = (uchar)(uVar15 >> 0x18);
        puVar17 = puVar18;
        switch(uVar19 - 1) {
        case 0:
          goto LAB_0018f8d6;
        case 1:
          goto switchD_0018fd4a_caseD_1;
        case 2:
          goto LAB_0018f8c6;
        case 3:
          goto switchD_0018fd4a_caseD_3;
        case 4:
          break;
        case 7:
          puVar18 = puVar18 + -1;
          *puVar18 = uVar4;
        case 6:
          puVar17 = puVar18 + -1;
          *puVar17 = uVar3;
        case 5:
          puVar18 = puVar17 + -1;
          puVar17[-1] = uVar7;
          break;
        default:
          goto switchD_0018fd4a_default;
        }
        puVar17 = puVar18 + -1;
        puVar18[-1] = uVar5;
switchD_0018fd4a_caseD_3:
        puVar18 = puVar17 + -1;
        puVar17[-1] = uVar10;
LAB_0018f8c6:
        puVar17 = puVar18 + -1;
        puVar18[-1] = uVar9;
switchD_0018fd4a_caseD_1:
        puVar18 = puVar17 + -1;
        puVar17[-1] = uVar8;
LAB_0018f8d6:
        puVar17 = puVar18 + -1;
        puVar18[-1] = bVar6;
switchD_0018fd4a_default:
        out = puVar17 + uVar19;
        uVar21 = uVar15;
        uVar22 = uVar12;
        if ((numbits != 0x20) && (uVar21 = uVar14, uVar22 = uVar15, numbits != 0x40)) {
          local_38 = uVar23;
          local_34 = uVar12;
          local_30 = bVar6;
          local_2f = uVar8;
          local_2e = uVar9;
          local_2d = uVar10;
          local_2c = uVar5;
          local_2b = uVar7;
          local_2a = uVar3;
          local_29 = uVar4;
          if ((numbits & 7U) == 0) {
            memmove(&local_38,pvVar13,8);
            uVar21 = local_34;
            uVar22 = local_38;
          }
          else {
            memmove(&local_38,pvVar13,9);
            local_38._0_2_ =
                 CONCAT11(local_38._1_1_ << (uVar11 & 0xff) |
                          (byte)((int)(uint)local_38._2_1_ >> (uVar16 & 0xff)),
                          (char)local_38 << (uVar11 & 0xff) |
                          (byte)((int)(uint)local_38._1_1_ >> (uVar16 & 0xff)));
            local_38._0_3_ =
                 CONCAT12(local_38._2_1_ << (uVar11 & 0xff) |
                          (byte)((int)(uint)local_38._3_1_ >> (uVar16 & 0xff)),(undefined2)local_38)
            ;
            local_38 = CONCAT13(local_38._3_1_ << (uVar11 & 0xff) |
                                (byte)((int)(local_34 & 0xff) >> (uVar16 & 0xff)),
                                (undefined3)local_38);
            local_34._0_3_ =
                 CONCAT12(local_34._2_1_ << (uVar11 & 0xff) |
                          (byte)((int)(uint)local_34._3_1_ >> (uVar16 & 0xff)),
                          CONCAT11(local_34._1_1_ << (uVar11 & 0xff) |
                                   (byte)((int)(uint)local_34._2_1_ >> (uVar16 & 0xff)),
                                   (char)local_34 << (uVar11 & 0xff) |
                                   (byte)((int)(uint)local_34._1_1_ >> (uVar16 & 0xff))));
            local_34 = CONCAT13((byte)((int)(uint)local_30 >> (uVar16 & 0xff)) |
                                local_34._3_1_ << (uVar11 & 0xff),(undefined3)local_34);
            uVar21 = local_34;
            uVar22 = local_38;
          }
        }
        bVar1 = uVar19 <= uVar20;
        uVar12 = uVar21;
        uVar20 = uVar20 - uVar19;
        uVar23 = uVar22;
      } while (bVar1);
    }
    (*ivec)[0] = (uchar)uVar22;
    (*ivec)[4] = (uchar)uVar21;
    (*ivec)[1] = (uchar)(uVar22 >> 8);
    (*ivec)[2] = (uchar)(uVar22 >> 0x10);
    (*ivec)[3] = (uchar)(uVar22 >> 0x18);
    (*ivec)[5] = (uchar)(uVar21 >> 8);
    (*ivec)[6] = (uchar)(uVar21 >> 0x10);
    (*ivec)[7] = (uchar)(uVar21 >> 0x18);
  }
  return;
}

