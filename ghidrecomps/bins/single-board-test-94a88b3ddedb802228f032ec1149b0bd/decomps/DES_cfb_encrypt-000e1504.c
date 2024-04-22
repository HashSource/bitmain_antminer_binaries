
void DES_cfb_encrypt(uchar *in,uchar *out,int numbits,long length,DES_key_schedule *schedule,
                    DES_cblock *ivec,int enc)

{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  uchar uVar4;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uchar *puVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint local_70;
  uchar *local_5c;
  uchar *local_58;
  uint local_54;
  uint local_40;
  uint local_3c;
  byte local_38 [9];
  uchar local_2f;
  uchar local_2e;
  uchar local_2d;
  uchar local_2c;
  uchar local_2b;
  uchar local_2a;
  uchar local_29;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  
  if (numbits - 1U < 0x40) {
    uVar2 = numbits + 7 >> 3;
    iVar17 = numbits >> 3;
    uVar19 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar21 = numbits & 7;
    uVar18 = (uint)(*ivec)[4] | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 |
             (uint)(*ivec)[7] << 0x18;
    uVar11 = uVar18;
    uVar13 = uVar19;
    local_5c = in;
    local_58 = out;
    if (enc == 0) {
      if (uVar2 <= (uint)length) {
        local_54 = length - uVar2;
        do {
          local_40 = uVar13;
          local_3c = uVar11;
          DES_encrypt1(&local_40,schedule,1);
          puVar16 = local_5c + uVar2;
          switch(uVar2 - 2) {
          case 0:
            uVar12 = 0;
            uVar10 = uVar12;
            goto LAB_000e1692;
          case 1:
            uVar12 = 0;
            uVar10 = uVar12;
            goto LAB_000e1688;
          case 2:
            uVar10 = 0;
            goto LAB_000e1680;
          case 3:
            uVar10 = 0;
            goto LAB_000e1678;
          case 4:
            uVar10 = 0;
            goto LAB_000e166e;
          case 5:
            uVar10 = 0;
            break;
          case 6:
            pbVar3 = puVar16 + -1;
            puVar16 = puVar16 + -1;
            uVar10 = (uint)*pbVar3 << 0x18;
            break;
          default:
            uVar10 = 0;
            uVar12 = uVar10;
            goto LAB_000e169c;
          }
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar10 = uVar10 | (uint)*pbVar3 << 0x10;
LAB_000e166e:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar10 = uVar10 | (uint)*pbVar3 << 8;
LAB_000e1678:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar10 = uVar10 | *pbVar3;
LAB_000e1680:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar12 = (uint)*pbVar3 << 0x18;
LAB_000e1688:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar12 = uVar12 | (uint)*pbVar3 << 0x10;
LAB_000e1692:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar12 = uVar12 | (uint)*pbVar3 << 8;
LAB_000e169c:
          local_5c = puVar16 + (uVar2 - 1);
          uVar20 = uVar12 | puVar16[-1];
          uVar18 = uVar20;
          uVar19 = uVar11;
          if ((numbits != 0x20) && (uVar18 = uVar10, uVar19 = uVar20, numbits != 0x40)) {
            local_38[0] = (byte)uVar13;
            local_38[4] = (byte)uVar11;
            local_2f = (uchar)(uVar12 >> 8);
            local_38[3] = (byte)(uVar13 >> 0x18);
            local_38[5] = (byte)(uVar11 >> 8);
            local_38[6] = (byte)(uVar11 >> 0x10);
            local_38[7] = (byte)(uVar11 >> 0x18);
            local_38[8] = puVar16[-1];
            local_2c = (uchar)uVar10;
            local_38[1] = (byte)(uVar13 >> 8);
            local_38[2] = (byte)(uVar13 >> 0x10);
            local_2e = (uchar)(uVar12 >> 0x10);
            local_2d = (uchar)(uVar12 >> 0x18);
            local_2b = (uchar)(uVar10 >> 8);
            local_2a = (uchar)(uVar10 >> 0x10);
            local_29 = (uchar)(uVar10 >> 0x18);
            if (uVar21 == 0) {
              memmove(local_38,local_38 + iVar17,8);
              local_70 = (uint)local_38[0];
              uVar12 = (uint)local_38[1];
              uVar15 = (uint)local_38[2];
              uVar13 = (uint)local_38[3];
              uVar11 = (uint)local_38[4];
              uVar19 = (uint)local_38[5];
              uVar22 = (uint)local_38[6];
              uVar18 = (uint)local_38[7];
            }
            else {
              uVar14 = 8 - uVar21;
              uVar11 = (int)(uint)local_38[iVar17 + 1] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17] << uVar21;
              local_70 = uVar11 & 0xff;
              local_38[0] = (byte)uVar11;
              uVar11 = (int)(uint)local_38[iVar17 + 2] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 1] << uVar21;
              uVar12 = uVar11 & 0xff;
              local_38[1] = (byte)uVar11;
              uVar11 = (int)(uint)local_38[iVar17 + 3] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 2] << uVar21;
              uVar15 = uVar11 & 0xff;
              local_38[2] = (byte)uVar11;
              uVar11 = (int)(uint)local_38[iVar17 + 4] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 3] << uVar21;
              uVar13 = uVar11 & 0xff;
              local_38[3] = (byte)uVar11;
              uVar18 = (int)(uint)local_38[iVar17 + 5] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 4] << uVar21;
              uVar11 = uVar18 & 0xff;
              local_38[4] = (byte)uVar18;
              uVar18 = (int)(uint)local_38[iVar17 + 6] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 5] << uVar21;
              uVar19 = uVar18 & 0xff;
              local_38[5] = (byte)uVar18;
              uVar18 = (int)(uint)local_38[iVar17 + 7] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 6] << uVar21;
              uVar22 = uVar18 & 0xff;
              local_38[6] = (byte)uVar18;
              uVar14 = (int)(uint)local_38[iVar17 + 8] >> (uVar14 & 0xff) |
                       (uint)local_38[iVar17 + 7] << uVar21;
              uVar18 = uVar14 & 0xff;
              local_38[7] = (byte)uVar14;
            }
            uVar18 = uVar22 << 0x10 | uVar19 << 8 | uVar11 | uVar18 << 0x18;
            uVar19 = uVar15 << 0x10 | uVar12 << 8 | local_70 | uVar13 << 0x18;
          }
          uVar20 = uVar20 ^ local_40;
          local_58 = local_58 + uVar2;
          uVar10 = uVar10 ^ local_3c;
          puVar16 = local_58;
          switch(uVar2) {
          case 2:
            goto LAB_000e18ac;
          case 3:
            goto switchD_000e1872_caseD_3;
          case 4:
            goto LAB_000e189c;
          case 5:
            goto switchD_000e1872_caseD_5;
          case 6:
            break;
          case 8:
            local_58[-1] = (uchar)(uVar10 >> 0x18);
            puVar16 = local_58 + -1;
          case 7:
            local_58 = puVar16 + -1;
            puVar16[-1] = (uchar)(uVar10 >> 0x10);
            break;
          default:
            goto switchD_000e1872_caseD_7;
          }
          puVar16 = local_58 + -1;
          local_58[-1] = (uchar)(uVar10 >> 8);
switchD_000e1872_caseD_5:
          local_58 = puVar16 + -1;
          puVar16[-1] = (uchar)uVar10;
LAB_000e189c:
          puVar16 = local_58 + -1;
          local_58[-1] = (uchar)(uVar20 >> 0x18);
switchD_000e1872_caseD_3:
          local_58 = puVar16 + -1;
          puVar16[-1] = (uchar)(uVar20 >> 0x10);
LAB_000e18ac:
          puVar16 = local_58 + -1;
          local_58[-1] = (uchar)(uVar20 >> 8);
switchD_000e1872_caseD_7:
          local_58 = puVar16 + (uVar2 - 1);
          puVar16[-1] = (uchar)uVar20;
          bVar1 = uVar2 <= local_54;
          uVar11 = uVar18;
          uVar13 = uVar19;
          local_54 = local_54 - uVar2;
        } while (bVar1);
      }
    }
    else {
      while (uVar19 = uVar13, uVar18 = uVar11, uVar2 <= (uint)length) {
        local_40 = uVar19;
        local_3c = uVar18;
        DES_encrypt1(&local_40,schedule,1);
        length = length - uVar2;
        puVar16 = local_5c + uVar2;
        switch(uVar2 - 2) {
        case 0:
          uVar10 = 0;
          uVar11 = uVar10;
          goto LAB_000e1934;
        case 1:
          uVar10 = 0;
          uVar11 = uVar10;
          goto LAB_000e192a;
        case 2:
          uVar10 = 0;
          goto LAB_000e1920;
        case 3:
          uVar10 = 0;
          goto LAB_000e1918;
        case 4:
          uVar10 = 0;
          goto LAB_000e190e;
        case 5:
          uVar10 = 0;
          break;
        case 6:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar10 = (uint)*pbVar3 << 0x18;
          break;
        default:
          uVar10 = 0;
          uVar11 = uVar10;
          goto LAB_000e193e;
        }
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar10 = uVar10 | (uint)*pbVar3 << 0x10;
LAB_000e190e:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar10 = uVar10 | (uint)*pbVar3 << 8;
LAB_000e1918:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar10 = uVar10 | *pbVar3;
LAB_000e1920:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = (uint)*pbVar3 << 0x18;
LAB_000e192a:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = uVar11 | (uint)*pbVar3 << 0x10;
LAB_000e1934:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = uVar11 | (uint)*pbVar3 << 8;
LAB_000e193e:
        local_5c = puVar16 + (uVar2 - 1);
        local_58 = local_58 + uVar2;
        uVar12 = local_40 ^ (puVar16[-1] | uVar11);
        uVar10 = uVar10 ^ local_3c;
        uVar4 = (uchar)(uVar10 >> 8);
        uVar5 = (uchar)(uVar10 >> 0x10);
        uVar6 = (uchar)(uVar10 >> 0x18);
        uVar7 = (uchar)(uVar12 >> 8);
        uVar8 = (uchar)(uVar12 >> 0x10);
        uVar9 = (uchar)(uVar12 >> 0x18);
        puVar16 = local_58;
        switch(uVar2 - 2) {
        case 0:
          goto LAB_000e19c8;
        case 1:
          goto switchD_000e1960_caseD_1;
        case 2:
          goto LAB_000e19b8;
        case 3:
          goto switchD_000e1960_caseD_3;
        case 4:
          break;
        case 6:
          local_58[-1] = uVar6;
          puVar16 = local_58 + -1;
        case 5:
          local_58 = puVar16 + -1;
          puVar16[-1] = uVar5;
          break;
        default:
          goto switchD_000e1960_caseD_7;
        }
        puVar16 = local_58 + -1;
        local_58[-1] = uVar4;
switchD_000e1960_caseD_3:
        local_58 = puVar16 + -1;
        puVar16[-1] = (uchar)uVar10;
LAB_000e19b8:
        puVar16 = local_58 + -1;
        local_58[-1] = uVar9;
switchD_000e1960_caseD_1:
        local_58 = puVar16 + -1;
        puVar16[-1] = uVar8;
LAB_000e19c8:
        puVar16 = local_58 + -1;
        local_58[-1] = uVar7;
switchD_000e1960_caseD_7:
        local_58 = puVar16 + (uVar2 - 1);
        puVar16[-1] = (byte)uVar12;
        uVar11 = uVar12;
        uVar13 = uVar18;
        if ((numbits != 0x20) && (uVar11 = uVar10, uVar13 = uVar12, numbits != 0x40)) {
          local_38[0] = (byte)uVar19;
          local_38[1] = (byte)(uVar19 >> 8);
          local_38[4] = (byte)uVar18;
          local_38[8] = (byte)uVar12;
          local_2c = (uchar)uVar10;
          local_38[2] = (byte)(uVar19 >> 0x10);
          local_38[3] = (byte)(uVar19 >> 0x18);
          local_38[6] = (byte)(uVar18 >> 0x10);
          local_38[5] = (byte)(uVar18 >> 8);
          local_38[7] = (byte)(uVar18 >> 0x18);
          local_2f = uVar7;
          local_2e = uVar8;
          local_2d = uVar9;
          local_2b = uVar4;
          local_2a = uVar5;
          local_29 = uVar6;
          if (uVar21 == 0) {
            memmove(local_38,local_38 + iVar17,8);
            uVar18 = (uint)local_38[0];
            uVar12 = (uint)local_38[1];
            uVar20 = (uint)local_38[2];
            uVar13 = (uint)local_38[3];
            uVar11 = (uint)local_38[4];
            uVar10 = (uint)local_38[5];
            uVar22 = (uint)local_38[6];
            uVar19 = (uint)local_38[7];
          }
          else {
            uVar15 = 8 - uVar21;
            uVar11 = (int)(uint)local_38[iVar17 + 1] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17] << uVar21;
            uVar18 = uVar11 & 0xff;
            local_38[0] = (byte)uVar11;
            uVar11 = (int)(uint)local_38[iVar17 + 2] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 1] << uVar21;
            uVar12 = uVar11 & 0xff;
            local_38[1] = (byte)uVar11;
            uVar11 = (int)(uint)local_38[iVar17 + 3] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 2] << uVar21;
            uVar20 = uVar11 & 0xff;
            local_38[2] = (byte)uVar11;
            uVar11 = (int)(uint)local_38[iVar17 + 4] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 3] << uVar21;
            uVar13 = uVar11 & 0xff;
            local_38[3] = (byte)uVar11;
            uVar19 = (int)(uint)local_38[iVar17 + 5] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 4] << uVar21;
            uVar11 = uVar19 & 0xff;
            local_38[4] = (byte)uVar19;
            uVar19 = (int)(uint)local_38[iVar17 + 6] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 5] << uVar21;
            uVar10 = uVar19 & 0xff;
            local_38[5] = (byte)uVar19;
            uVar19 = (int)(uint)local_38[iVar17 + 7] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 6] << uVar21;
            uVar22 = uVar19 & 0xff;
            local_38[6] = (byte)uVar19;
            uVar15 = (int)(uint)local_38[iVar17 + 8] >> (uVar15 & 0xff) |
                     (uint)local_38[iVar17 + 7] << uVar21;
            uVar19 = uVar15 & 0xff;
            local_38[7] = (byte)uVar15;
          }
          uVar11 = uVar22 << 0x10 | uVar10 << 8 | uVar11 | uVar19 << 0x18;
          uVar13 = uVar20 << 0x10 | uVar12 << 8 | uVar18 | uVar13 << 0x18;
        }
      }
    }
    (*ivec)[0] = (uchar)uVar19;
    (*ivec)[4] = (uchar)uVar18;
    (*ivec)[1] = (uchar)(uVar19 >> 8);
    (*ivec)[2] = (uchar)(uVar19 >> 0x10);
    (*ivec)[3] = (uchar)(uVar19 >> 0x18);
    (*ivec)[5] = (uchar)(uVar18 >> 8);
    (*ivec)[6] = (uchar)(uVar18 >> 0x10);
    (*ivec)[7] = (uchar)(uVar18 >> 0x18);
  }
  return;
}

