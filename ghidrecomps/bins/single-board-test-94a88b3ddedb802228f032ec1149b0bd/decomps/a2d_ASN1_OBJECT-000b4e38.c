
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  ulong uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint w;
  int iVar11;
  byte *pbVar12;
  BIGNUM *a;
  int iVar13;
  int local_64;
  uchar *local_5c;
  uchar *local_50;
  int local_48;
  uchar local_40 [28];
  
  if (num != 0) {
    if (num == -1) {
      num = strlen(buf);
      bVar1 = *buf;
    }
    else {
      bVar1 = *buf;
    }
    uVar4 = bVar1 - 0x30;
    if (uVar4 < 3) {
      if ((int)(num - 1U) < 1) {
        ERR_put_error(0xd,100,0x8a,DAT_000b515c,0x71);
      }
      else {
        iVar13 = num - 2;
        pbVar12 = (byte *)(buf + 2);
        if (iVar13 == 0) {
          return 0;
        }
        if (buf[1] == '.' || buf[1] == ' ') {
          a = (BIGNUM *)0x0;
          local_64 = 0;
          local_48 = 0x18;
          local_5c = local_40;
          do {
            w = 0;
            bVar2 = false;
            pbVar6 = pbVar12;
            do {
              while( true ) {
                pbVar12 = pbVar6 + 1;
                uVar10 = (uint)*pbVar6;
                iVar13 = iVar13 + -1;
                if (uVar10 == 0x20 || uVar10 == 0x2e) goto LAB_000b4f30;
                if (9 < uVar10 - 0x30) {
                  ERR_put_error(0xd,100,0x82,DAT_000b515c,0x87);
                  goto LAB_000b5018;
                }
                bVar3 = (bool)(bVar2 ^ 1);
                if (w < 0x19999991) {
                  bVar3 = false;
                }
                pbVar6 = pbVar12;
                if (!bVar3) break;
                if (((a == (BIGNUM *)0x0) && (a = BN_new(), a == (BIGNUM *)0x0)) ||
                   (iVar5 = BN_set_word(a,w), iVar5 == 0)) goto LAB_000b5018;
                bVar2 = true;
LAB_000b4f14:
                iVar5 = BN_mul_word(a,10);
                if ((iVar5 == 0) || (iVar5 = BN_add_word(a,uVar10 - 0x30), iVar5 == 0))
                goto LAB_000b5018;
                if (iVar13 == 0) goto LAB_000b4f30;
              }
              if (bVar2) goto LAB_000b4f14;
              w = (uVar10 + w * 10) - 0x30;
            } while (iVar13 != 0);
LAB_000b4f30:
            if (local_64 == 0) {
              if ((int)uVar4 < 2 && 0x27 < w) {
                ERR_put_error(0xd,100,0x93,DAT_000b515c,0x9b);
                goto LAB_000b5018;
              }
              if (bVar2) {
                iVar5 = BN_add_word(a,uVar4 * 0x28);
                if (iVar5 != 0) goto LAB_000b5072;
                goto LAB_000b5018;
              }
              w = w + uVar4 * 0x28;
LAB_000b4f60:
              iVar5 = 0;
              do {
                bVar1 = (byte)w;
                w = w >> 7;
                local_5c[iVar5] = bVar1 & 0x7f;
                iVar5 = iVar5 + 1;
              } while (w != 0);
            }
            else {
              if (!bVar2) goto LAB_000b4f60;
LAB_000b5072:
              iVar5 = BN_num_bits(a);
              iVar5 = (iVar5 + 6) / 7;
              if (local_48 < iVar5) {
                if (local_5c != local_40) {
                  CRYPTO_free(local_5c);
                }
                local_48 = iVar5 + 0x20;
                local_5c = (uchar *)CRYPTO_malloc(local_48,DAT_000b515c,0xad);
                if (local_5c == (uchar *)0x0) goto LAB_000b5020;
              }
              if (iVar5 != 0) {
                iVar11 = 0;
                do {
                  uVar7 = BN_div_word(a,0x80);
                  local_5c[iVar11] = (uchar)uVar7;
                  iVar11 = iVar11 + 1;
                } while (iVar5 != iVar11);
              }
            }
            if (out == (uchar *)0x0) {
              local_64 = local_64 + iVar5;
            }
            else {
              if (olen < local_64 + iVar5) {
                ERR_put_error(0xd,100,0x6b,DAT_000b515c,0xbf);
                goto LAB_000b5018;
              }
              if (1 < iVar5) {
                pbVar6 = local_5c + iVar5;
                pbVar8 = out + local_64;
                do {
                  pbVar6 = pbVar6 + -1;
                  pbVar9 = pbVar8 + 1;
                  *pbVar8 = *pbVar6 | 0x80;
                  pbVar8 = pbVar9;
                } while (pbVar9 != out + iVar5 + local_64 + -1);
                local_64 = iVar5 + local_64 + -1;
              }
              out[local_64] = *local_5c;
              local_64 = local_64 + 1;
            }
            if (iVar13 == 0) {
              if (local_5c != local_40) {
                CRYPTO_free(local_5c);
              }
              if (a == (BIGNUM *)0x0) {
                return local_64;
              }
              BN_free(a);
              return local_64;
            }
          } while (uVar10 == 0x20 || uVar10 == 0x2e);
        }
        else {
          local_5c = local_40;
          a = (BIGNUM *)0x0;
        }
        ERR_put_error(0xd,100,0x83,DAT_000b515c,0x7a);
LAB_000b5018:
        local_50 = local_40;
        if (local_5c != local_50) {
LAB_000b5020:
          CRYPTO_free(local_5c);
        }
        if (a != (BIGNUM *)0x0) {
          BN_free(a);
          return 0;
        }
      }
    }
    else {
      ERR_put_error(0xd,100,0x7a,DAT_000b515c,0x6c);
    }
  }
  return 0;
}

