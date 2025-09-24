
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  byte *pbVar5;
  ulong uVar6;
  byte *pbVar7;
  uint w;
  int iVar8;
  byte *pbVar9;
  BIGNUM *a;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uchar *puVar13;
  uchar *local_64;
  int local_5c;
  uchar *local_54;
  int local_48;
  uchar local_40 [28];
  
  if (num == 0) {
    return 0;
  }
  if (num == -1) {
    num = strlen(buf);
    uVar11 = (byte)*buf - 0x30;
    if (2 < uVar11) goto LAB_0017f9c8;
LAB_0017f818:
    if (1 < num) {
      iVar8 = num - 2;
      pbVar9 = (byte *)(buf + 2);
      if (iVar8 == 0) {
        a = (BIGNUM *)0x0;
        local_5c = 0;
LAB_0017fac4:
        BN_free(a);
        return local_5c;
      }
      if (buf[1] == ' ' || buf[1] == '.') {
        a = (BIGNUM *)0x0;
        local_5c = 0;
        local_48 = 0x18;
        local_64 = local_40;
        do {
          w = 0;
          bVar2 = false;
          pbVar7 = pbVar9;
          do {
            while( true ) {
              pbVar9 = pbVar7 + 1;
              uVar12 = (uint)*pbVar7;
              iVar8 = iVar8 + -1;
              if (uVar12 == 0x2e || uVar12 == 0x20) goto LAB_0017f8d2;
              iVar4 = ossl_ctype_check(uVar12,4);
              if (iVar4 == 0) {
                ERR_put_error(0xd,100,0x82,"crypto/asn1/a_object.c",100);
                goto LAB_0017f980;
              }
              bVar3 = (bool)(bVar2 ^ 1);
              if (w < 0x19999991) {
                bVar3 = false;
              }
              pbVar7 = pbVar9;
              if (!bVar3) break;
              if (((a == (BIGNUM *)0x0) && (a = BN_new(), a == (BIGNUM *)0x0)) ||
                 (iVar4 = BN_set_word(a,w), iVar4 == 0)) goto LAB_0017f980;
              bVar2 = true;
LAB_0017f8b4:
              iVar4 = BN_mul_word(a,10);
              if ((iVar4 == 0) || (iVar4 = BN_add_word(a,uVar12 - 0x30), iVar4 == 0))
              goto LAB_0017f980;
              if (iVar8 == 0) goto LAB_0017f8d2;
            }
            if (bVar2) goto LAB_0017f8b4;
            w = (uVar12 - 0x30) + w * 10;
          } while (iVar8 != 0);
LAB_0017f8d2:
          if (local_5c == 0) {
            if (0x27 < w && (int)uVar11 < 2) {
              ERR_put_error(0xd,100,0x93,"crypto/asn1/a_object.c",0x78);
              goto LAB_0017f980;
            }
            if (bVar2) {
              iVar4 = BN_add_word(a,uVar11 * 0x28);
              if (iVar4 != 0) goto LAB_0017fa04;
              goto LAB_0017f980;
            }
            w = w + uVar11 * 0x28;
LAB_0017f8fa:
            iVar10 = 0;
            pbVar7 = local_64 + -1;
            do {
              bVar1 = (byte)w;
              w = w >> 7;
              iVar10 = iVar10 + 1;
              pbVar7 = pbVar7 + 1;
              *pbVar7 = bVar1 & 0x7f;
            } while (w != 0);
          }
          else {
            if (!bVar2) goto LAB_0017f8fa;
LAB_0017fa04:
            iVar4 = BN_num_bits(a);
            iVar4 = (iVar4 + 6) / 7;
            if (local_48 < iVar4) {
              if (local_64 != local_40) {
                CRYPTO_free(local_64);
              }
              local_48 = iVar4 + 0x20;
              local_64 = (uchar *)CRYPTO_malloc(local_48,"crypto/asn1/a_object.c",0x8a);
              if (local_64 == (uchar *)0x0) goto LAB_0017f988;
LAB_0017fa4a:
              iVar10 = 0;
              puVar13 = local_64 + -1;
              do {
                uVar6 = BN_div_word(a,0x80);
                iVar10 = iVar10 + 1;
                if (uVar6 == 0xffffffff) goto LAB_0017f980;
                puVar13 = puVar13 + 1;
                *puVar13 = (uchar)uVar6;
              } while (iVar4 != iVar10);
            }
            else {
              if (iVar4 != 0) goto LAB_0017fa4a;
              iVar10 = 0;
            }
          }
          if (out == (uchar *)0x0) {
            local_5c = local_5c + iVar10;
          }
          else {
            if (olen < iVar10 + local_5c) {
              ERR_put_error(0xd,100,0x6b,"crypto/asn1/a_object.c",0xa0);
              goto LAB_0017f980;
            }
            if (1 < iVar10) {
              pbVar7 = local_64 + iVar10;
              pbVar5 = out + local_5c;
              do {
                pbVar7 = pbVar7 + -1;
                *pbVar5 = *pbVar7 | 0x80;
                pbVar5 = pbVar5 + 1;
              } while (local_64 + 1 != pbVar7);
              local_5c = iVar10 + local_5c + -1;
            }
            out[local_5c] = *local_64;
            local_5c = local_5c + 1;
          }
          if (iVar8 == 0) {
            if (local_64 != local_40) {
              CRYPTO_free(local_64);
            }
            goto LAB_0017fac4;
          }
        } while (uVar12 == 0x2e || uVar12 == 0x20);
      }
      else {
        local_64 = local_40;
        a = (BIGNUM *)0x0;
      }
      ERR_put_error(0xd,100,0x83,"crypto/asn1/a_object.c",0x57);
LAB_0017f980:
      local_54 = local_40;
      if (local_64 != local_54) {
LAB_0017f988:
        CRYPTO_free(local_64);
      }
      goto LAB_0017f994;
    }
    ERR_put_error(0xd,100,0x8a,"crypto/asn1/a_object.c",0x4e);
  }
  else {
    uVar11 = (byte)*buf - 0x30;
    if (uVar11 < 3) goto LAB_0017f818;
LAB_0017f9c8:
    ERR_put_error(0xd,100,0x7a,"crypto/asn1/a_object.c",0x49);
  }
  a = (BIGNUM *)0x0;
LAB_0017f994:
  BN_free(a);
  return 0;
}

