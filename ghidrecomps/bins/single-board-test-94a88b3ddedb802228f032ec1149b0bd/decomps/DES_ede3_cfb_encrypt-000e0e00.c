
void DES_ede3_cfb_encrypt
               (uchar *in,uchar *out,int numbits,long length,DES_key_schedule *ks1,
               DES_key_schedule *ks2,DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  bool bVar1;
  byte *pbVar2;
  uchar uVar3;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  uchar *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint local_88;
  uchar *local_6c;
  uchar *local_68;
  uint local_40;
  uint local_3c;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  uchar local_2f;
  uchar local_2e;
  uchar local_2d;
  uchar local_2c;
  uchar local_2b;
  uchar local_2a;
  uchar local_29;
  byte bVar4;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  
  if (numbits < 0x41) {
    uVar13 = numbits + 7;
    uVar24 = uVar13 >> 3;
    uVar21 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar20 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
    local_6c = in;
    local_68 = out;
    if (enc == 0) {
      if (uVar24 <= (uint)length) {
        uVar13 = uVar13 & numbits >> 0x20;
        if (((uint)(numbits >> 0x1f) >> 0x1c & 1) == 0) {
          uVar13 = numbits;
        }
        pbVar14 = local_38 + ((int)uVar13 >> 3);
        uVar26 = numbits % 8;
        uVar15 = 8 - uVar26;
        uVar13 = uVar20;
        uVar17 = uVar21;
        uVar25 = length - uVar24;
        do {
          local_40 = uVar17;
          local_3c = uVar13;
          DES_encrypt3(&local_40,ks1,ks2,ks3);
          puVar16 = local_6c + uVar24;
          switch(uVar24 - 1) {
          case 0:
            uVar18 = 0;
            uVar22 = uVar18;
            goto LAB_000e0fc2;
          case 1:
            uVar18 = 0;
            uVar20 = uVar18;
            goto LAB_000e0fb8;
          case 2:
            uVar18 = 0;
            uVar20 = uVar18;
            goto LAB_000e0fae;
          case 3:
            uVar18 = 0;
            goto LAB_000e0fa6;
          case 4:
            uVar18 = 0;
            goto LAB_000e0f9e;
          case 5:
            uVar18 = 0;
            goto LAB_000e0f94;
          case 6:
            uVar18 = 0;
            break;
          case 7:
            pbVar2 = puVar16 + -1;
            puVar16 = puVar16 + -1;
            uVar18 = (uint)*pbVar2 << 0x18;
            break;
          default:
            uVar22 = 0;
            local_6c = puVar16 + uVar24;
            uVar18 = uVar22;
            goto joined_r0x000e1224;
          }
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar18 = uVar18 | (uint)*pbVar2 << 0x10;
LAB_000e0f94:
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar18 = uVar18 | (uint)*pbVar2 << 8;
LAB_000e0f9e:
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar18 = uVar18 | *pbVar2;
LAB_000e0fa6:
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar20 = (uint)*pbVar2 << 0x18;
LAB_000e0fae:
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar20 = uVar20 | (uint)*pbVar2 << 0x10;
LAB_000e0fb8:
          pbVar2 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar22 = uVar20 | (uint)*pbVar2 << 8;
LAB_000e0fc2:
          local_6c = puVar16 + (uVar24 - 1);
          uVar22 = puVar16[-1] | uVar22;
joined_r0x000e1224:
          uVar20 = uVar22;
          uVar21 = uVar13;
          if ((numbits != 0x20) && (uVar20 = uVar18, uVar21 = uVar22, numbits != 0x40)) {
            local_38[0] = (byte)uVar17;
            local_34 = (byte)uVar13;
            local_38[2] = (byte)(uVar17 >> 0x10);
            local_31 = (byte)(uVar13 >> 0x18);
            local_38[3] = (byte)(uVar17 >> 0x18);
            local_29 = (uchar)(uVar18 >> 0x18);
            local_33 = (byte)(uVar13 >> 8);
            local_32 = (byte)(uVar13 >> 0x10);
            local_30 = (byte)uVar22;
            local_2c = (uchar)uVar18;
            local_38[1] = (byte)(uVar17 >> 8);
            local_2f = (uchar)(uVar22 >> 8);
            local_2e = (uchar)(uVar22 >> 0x10);
            local_2d = (uchar)(uVar22 >> 0x18);
            local_2b = (uchar)(uVar18 >> 8);
            local_2a = (uchar)(uVar18 >> 0x10);
            if ((numbits & 7U) == 0) {
              memmove(local_38,pbVar14,8);
              local_88 = (uint)local_38[0];
              uVar21 = (uint)local_38[1];
              uVar13 = (uint)local_38[2];
              uVar27 = (uint)local_38[3];
              uVar11 = (uint)local_34;
              uVar23 = (uint)local_33;
              uVar17 = (uint)local_32;
              uVar20 = (uint)local_31;
            }
            else {
              memmove(local_38,pbVar14,9);
              uVar20 = (uint)local_38[0] << (uVar26 & 0xff) |
                       (int)(uint)local_38[1] >> (uVar15 & 0xff);
              uVar17 = (int)(uint)local_38[2] >> (uVar15 & 0xff) |
                       (uint)local_38[1] << (uVar26 & 0xff);
              uVar21 = uVar17 & 0xff;
              uVar23 = (int)(uint)local_38[3] >> (uVar15 & 0xff) |
                       (uint)local_38[2] << (uVar26 & 0xff);
              uVar13 = uVar23 & 0xff;
              local_88 = uVar20 & 0xff;
              local_38[0] = (byte)uVar20;
              local_38[1] = (byte)uVar17;
              uVar20 = (int)(uint)local_34 >> (uVar15 & 0xff) | (uint)local_38[3] << (uVar26 & 0xff)
              ;
              uVar27 = (int)(uint)local_33 >> (uVar15 & 0xff) | (uint)local_34 << (uVar26 & 0xff);
              uVar11 = uVar27 & 0xff;
              local_38[2] = (byte)uVar23;
              uVar17 = (int)(uint)local_32 >> (uVar15 & 0xff) | (uint)local_33 << (uVar26 & 0xff);
              uVar23 = uVar17 & 0xff;
              local_34 = (byte)uVar27;
              local_33 = (byte)uVar17;
              uVar27 = uVar20 & 0xff;
              local_38[3] = (byte)uVar20;
              uVar12 = (int)(uint)local_31 >> (uVar15 & 0xff) | (uint)local_32 << (uVar26 & 0xff);
              uVar19 = (int)(uint)local_30 >> (uVar15 & 0xff) | (uint)local_31 << (uVar26 & 0xff);
              uVar17 = uVar12 & 0xff;
              uVar20 = uVar19 & 0xff;
              local_32 = (byte)uVar12;
              local_31 = (byte)uVar19;
            }
            uVar20 = uVar17 << 0x10 | uVar23 << 8 | uVar11 | uVar20 << 0x18;
            uVar21 = uVar13 << 0x10 | uVar21 << 8 | local_88 | uVar27 << 0x18;
          }
          uVar22 = uVar22 ^ local_40;
          local_68 = local_68 + uVar24;
          uVar18 = uVar18 ^ local_3c;
          puVar16 = local_68;
          switch(uVar24) {
          case 1:
            goto LAB_000e11d0;
          case 2:
            goto switchD_000e118e_caseD_2;
          case 3:
            goto LAB_000e11c0;
          case 4:
            goto switchD_000e118e_caseD_4;
          case 5:
            break;
          case 8:
            local_68[-1] = (uchar)(uVar18 >> 0x18);
            local_68 = local_68 + -1;
          case 7:
            local_68[-1] = (uchar)(uVar18 >> 0x10);
            puVar16 = local_68 + -1;
          case 6:
            local_68 = puVar16 + -1;
            puVar16[-1] = (uchar)(uVar18 >> 8);
            break;
          default:
            goto switchD_000e118e_caseD_8;
          }
          puVar16 = local_68 + -1;
          local_68[-1] = (uchar)uVar18;
switchD_000e118e_caseD_4:
          local_68 = puVar16 + -1;
          puVar16[-1] = (uchar)(uVar22 >> 0x18);
LAB_000e11c0:
          puVar16 = local_68 + -1;
          local_68[-1] = (uchar)(uVar22 >> 0x10);
switchD_000e118e_caseD_2:
          local_68 = puVar16 + -1;
          puVar16[-1] = (uchar)(uVar22 >> 8);
LAB_000e11d0:
          puVar16 = local_68 + -1;
          local_68[-1] = (uchar)uVar22;
switchD_000e118e_caseD_8:
          local_68 = puVar16 + uVar24;
          bVar1 = uVar24 <= uVar25;
          uVar13 = uVar20;
          uVar17 = uVar21;
          uVar25 = uVar25 - uVar24;
        } while (bVar1);
      }
    }
    else if (uVar24 <= (uint)length) {
      uVar13 = uVar13 & numbits >> 0x20;
      if (((uint)(numbits >> 0x1f) >> 0x1c & 1) == 0) {
        uVar13 = numbits;
      }
      pbVar14 = local_38 + ((int)uVar13 >> 3);
      uVar15 = numbits % 8;
      uVar26 = 8 - uVar15;
      uVar13 = uVar20;
      uVar17 = uVar21;
      uVar25 = length - uVar24;
      do {
        local_40 = uVar17;
        local_3c = uVar13;
        DES_encrypt3(&local_40,ks1,ks2,ks3);
        local_6c = local_6c + uVar24;
        switch(uVar24 - 1) {
        case 0:
          uVar18 = 0;
          uVar22 = uVar18;
          goto LAB_000e1270;
        case 1:
          uVar18 = 0;
          uVar20 = uVar18;
          goto LAB_000e1266;
        case 2:
          uVar18 = 0;
          uVar20 = uVar18;
          goto LAB_000e125c;
        case 3:
          uVar18 = 0;
          goto LAB_000e1252;
        case 4:
          uVar18 = 0;
          goto LAB_000e124a;
        case 5:
          uVar18 = 0;
          goto LAB_000e1240;
        case 6:
          uVar18 = 0;
          break;
        case 7:
          pbVar2 = local_6c + -1;
          local_6c = local_6c + -1;
          uVar18 = (uint)*pbVar2 << 0x18;
          break;
        default:
          uVar18 = 0;
          uVar22 = uVar18;
          goto LAB_000e127a;
        }
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar18 = uVar18 | (uint)*pbVar2 << 0x10;
LAB_000e1240:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar18 = uVar18 | (uint)*pbVar2 << 8;
LAB_000e124a:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar18 = uVar18 | *pbVar2;
LAB_000e1252:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar20 = (uint)*pbVar2 << 0x18;
LAB_000e125c:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar20 = uVar20 | (uint)*pbVar2 << 0x10;
LAB_000e1266:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar22 = uVar20 | (uint)*pbVar2 << 8;
LAB_000e1270:
        pbVar2 = local_6c + -1;
        local_6c = local_6c + -1;
        uVar22 = *pbVar2 | uVar22;
LAB_000e127a:
        local_6c = local_6c + uVar24;
        uVar22 = uVar22 ^ local_40;
        uVar18 = uVar18 ^ local_3c;
        local_68 = local_68 + uVar24;
        uVar3 = (uchar)uVar18;
        bVar4 = (byte)uVar22;
        uVar5 = (uchar)(uVar18 >> 8);
        uVar6 = (uchar)(uVar18 >> 0x10);
        uVar7 = (uchar)(uVar18 >> 0x18);
        uVar8 = (uchar)(uVar22 >> 8);
        uVar9 = (uchar)(uVar22 >> 0x10);
        uVar10 = (uchar)(uVar22 >> 0x18);
        puVar16 = local_68;
        switch(uVar24 - 1) {
        case 0:
          goto LAB_000e12e6;
        case 1:
          goto switchD_000e1296_caseD_1;
        case 2:
          goto LAB_000e12d2;
        case 3:
          goto switchD_000e1296_caseD_3;
        case 4:
          break;
        case 7:
          local_68[-1] = uVar7;
          local_68 = local_68 + -1;
        case 6:
          local_68[-1] = uVar6;
          puVar16 = local_68 + -1;
        case 5:
          local_68 = puVar16 + -1;
          puVar16[-1] = uVar5;
          break;
        default:
          goto switchD_000e1296_caseD_8;
        }
        puVar16 = local_68 + -1;
        local_68[-1] = uVar3;
switchD_000e1296_caseD_3:
        local_68 = puVar16 + -1;
        puVar16[-1] = uVar10;
LAB_000e12d2:
        puVar16 = local_68 + -1;
        local_68[-1] = uVar9;
switchD_000e1296_caseD_1:
        local_68 = puVar16 + -1;
        puVar16[-1] = uVar8;
LAB_000e12e6:
        puVar16 = local_68 + -1;
        local_68[-1] = bVar4;
switchD_000e1296_caseD_8:
        local_68 = puVar16 + uVar24;
        uVar20 = uVar22;
        uVar21 = uVar13;
        if ((numbits != 0x20) && (uVar20 = uVar18, uVar21 = uVar22, numbits != 0x40)) {
          local_38[1] = (byte)(uVar17 >> 8);
          local_38[0] = (byte)uVar17;
          local_34 = (byte)uVar13;
          local_38[2] = (byte)(uVar17 >> 0x10);
          local_38[3] = (byte)(uVar17 >> 0x18);
          local_32 = (byte)(uVar13 >> 0x10);
          local_33 = (byte)(uVar13 >> 8);
          local_31 = (byte)(uVar13 >> 0x18);
          local_30 = bVar4;
          local_2f = uVar8;
          local_2e = uVar9;
          local_2d = uVar10;
          local_2c = uVar3;
          local_2b = uVar5;
          local_2a = uVar6;
          local_29 = uVar7;
          if ((numbits & 7U) == 0) {
            memmove(local_38,pbVar14,8);
            uVar21 = (uint)local_38[0];
            uVar13 = (uint)local_38[1];
            uVar17 = (uint)local_38[2];
            uVar23 = (uint)local_38[3];
            uVar27 = (uint)local_34;
            uVar18 = (uint)local_33;
            uVar22 = (uint)local_32;
            uVar20 = (uint)local_31;
          }
          else {
            memmove(local_38,pbVar14,9);
            uVar13 = (uint)local_38[2];
            uVar20 = (uint)local_38[0] << (uVar15 & 0xff) |
                     (int)(uint)local_38[1] >> (uVar26 & 0xff);
            uVar22 = (uint)local_34;
            uVar21 = uVar20 & 0xff;
            local_38[0] = (byte)uVar20;
            uVar20 = uVar13 << (uVar15 & 0xff) | (int)(uint)local_38[3] >> (uVar26 & 0xff);
            uVar17 = uVar20 & 0xff;
            local_38[2] = (byte)uVar20;
            uVar20 = (int)uVar13 >> (uVar26 & 0xff) | (uint)local_38[1] << (uVar15 & 0xff);
            uVar13 = uVar20 & 0xff;
            local_38[1] = (byte)uVar20;
            uVar20 = (int)(uint)local_33 >> (uVar26 & 0xff) | uVar22 << (uVar15 & 0xff);
            uVar27 = uVar20 & 0xff;
            local_34 = (byte)uVar20;
            uVar20 = (uint)local_33 << (uVar15 & 0xff) | (int)(uint)local_32 >> (uVar26 & 0xff);
            uVar18 = uVar20 & 0xff;
            uVar22 = (int)uVar22 >> (uVar26 & 0xff) | (uint)local_38[3] << (uVar15 & 0xff);
            uVar23 = uVar22 & 0xff;
            local_33 = (byte)uVar20;
            local_38[3] = (byte)uVar22;
            uVar19 = (int)(uint)local_31 >> (uVar26 & 0xff) | (uint)local_32 << (uVar15 & 0xff);
            uVar22 = uVar19 & 0xff;
            uVar11 = (uint)local_31 << (uVar15 & 0xff) | (int)(uint)local_30 >> (uVar26 & 0xff);
            uVar20 = uVar11 & 0xff;
            local_32 = (byte)uVar19;
            local_31 = (byte)uVar11;
          }
          uVar20 = uVar22 << 0x10 | uVar18 << 8 | uVar27 | uVar20 << 0x18;
          uVar21 = uVar17 << 0x10 | uVar13 << 8 | uVar21 | uVar23 << 0x18;
        }
        bVar1 = uVar24 <= uVar25;
        uVar13 = uVar20;
        uVar17 = uVar21;
        uVar25 = uVar25 - uVar24;
      } while (bVar1);
    }
    (*ivec)[0] = (uchar)uVar21;
    (*ivec)[4] = (uchar)uVar20;
    (*ivec)[1] = (uchar)(uVar21 >> 8);
    (*ivec)[2] = (uchar)(uVar21 >> 0x10);
    (*ivec)[3] = (uchar)(uVar21 >> 0x18);
    (*ivec)[5] = (uchar)(uVar20 >> 8);
    (*ivec)[6] = (uchar)(uVar20 >> 0x10);
    (*ivec)[7] = (uchar)(uVar20 >> 0x18);
  }
  return;
}

