
undefined4 do_dh_print_isra_0(BIO *param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  BIGNUM *a;
  BIGNUM *a_00;
  
  if (param_4 == 2) {
    a = *(BIGNUM **)(param_2 + 0x18);
LAB_000a5606:
    a_00 = *(BIGNUM **)(param_2 + 0x14);
  }
  else {
    a = (BIGNUM *)0x0;
    if (0 < param_4) goto LAB_000a5606;
    a_00 = (BIGNUM *)0x0;
  }
  if (*(BIGNUM **)(param_2 + 8) != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 8));
    iVar3 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar3 = iVar2 + 7;
    }
    uVar6 = iVar3 >> 3;
    if (uVar6 != 0) {
      if (*(BIGNUM **)(param_2 + 0xc) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0xc));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x24) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x24));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x28) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x28));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x34) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x34));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      if (a_00 != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(a_00);
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      if (a != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(a);
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar6 < (uint)(iVar3 >> 3)) {
          uVar6 = iVar3 >> 3;
        }
      }
      uVar7 = DAT_000a58cc;
      if ((param_4 != 2) && (uVar7 = DAT_000a5890, param_4 == 1)) {
        uVar7 = DAT_000a5894;
      }
      buf = (uchar *)CRYPTO_malloc(uVar6 + 10,DAT_000a5898,0x177);
      if (buf == (uchar *)0x0) {
        iVar3 = 0x41;
        goto LAB_000a574c;
      }
      BIO_indent(param_1,param_3,0x80);
      iVar3 = BN_num_bits(*(BIGNUM **)(param_2 + 8));
      iVar3 = BIO_printf(param_1,DAT_000a589c,uVar7,iVar3);
      if (0 < iVar3) {
        iVar2 = param_3 + 4;
        iVar3 = ASN1_bn_print(param_1,DAT_000a58a0,a,buf,iVar2);
        if (((((iVar3 != 0) &&
              (iVar3 = ASN1_bn_print(param_1,DAT_000a58a4,a_00,buf,iVar2), iVar3 != 0)) &&
             (iVar3 = ASN1_bn_print(param_1,DAT_000a58a8,*(BIGNUM **)(param_2 + 8),buf,iVar2),
             iVar3 != 0)) &&
            (iVar3 = ASN1_bn_print(param_1,DAT_000a58ac,*(BIGNUM **)(param_2 + 0xc),buf,iVar2),
            iVar3 != 0)) &&
           (((*(BIGNUM **)(param_2 + 0x24) == (BIGNUM *)0x0 ||
             (iVar3 = ASN1_bn_print(param_1,DAT_000a58b0,*(BIGNUM **)(param_2 + 0x24),buf,iVar2),
             iVar3 != 0)) &&
            ((*(BIGNUM **)(param_2 + 0x28) == (BIGNUM *)0x0 ||
             (iVar3 = ASN1_bn_print(param_1,DAT_000a58b4,*(BIGNUM **)(param_2 + 0x28),buf,iVar2),
             iVar3 != 0)))))) {
          if (*(int *)(param_2 + 0x2c) == 0) {
LAB_000a5844:
            if ((*(BIGNUM **)(param_2 + 0x34) == (BIGNUM *)0x0) ||
               (iVar3 = ASN1_bn_print(param_1,DAT_000a58c4,*(BIGNUM **)(param_2 + 0x34),buf,iVar2),
               iVar3 != 0)) {
              if (*(int *)(param_2 + 0x10) != 0) {
                BIO_indent(param_1,iVar2,0x80);
                iVar3 = BIO_printf(param_1,DAT_000a58c8,*(undefined4 *)(param_2 + 0x10));
                if (iVar3 < 1) goto LAB_000a572e;
              }
              uVar7 = 1;
              goto LAB_000a5742;
            }
          }
          else {
            BIO_indent(param_1,iVar2,0x80);
            BIO_puts(param_1,DAT_000a58b8);
            uVar7 = DAT_000a58d0;
            iVar3 = 0;
            do {
              iVar5 = *(int *)(param_2 + 0x30);
              if (iVar5 <= iVar3) {
                iVar3 = BIO_write(param_1,DAT_000a58c0,1);
                if (iVar3 < 1) {
                  return 0;
                }
                goto LAB_000a5844;
              }
              if (iVar3 == (iVar3 / 0xf) * 0xf) {
                iVar5 = BIO_puts(param_1,DAT_000a58c0);
                if ((iVar5 < 1) || (iVar5 = BIO_indent(param_1,param_3 + 8,0x80), iVar5 == 0))
                break;
                iVar5 = *(int *)(param_2 + 0x30);
              }
              pbVar1 = (byte *)(*(int *)(param_2 + 0x2c) + iVar3);
              iVar3 = iVar3 + 1;
              uVar4 = uVar7;
              if (iVar3 == iVar5) {
                uVar4 = DAT_000a58d4;
              }
              iVar5 = BIO_printf(param_1,DAT_000a58bc,(uint)*pbVar1,uVar4);
            } while (0 < iVar5);
          }
        }
      }
LAB_000a572e:
      uVar7 = 0;
      ERR_put_error(5,100,7,DAT_000a5898,0x1ac);
LAB_000a5742:
      CRYPTO_free(buf);
      return uVar7;
    }
  }
  iVar3 = 0x43;
LAB_000a574c:
  ERR_put_error(5,100,iVar3,DAT_000a5898,0x1ac);
  return 0;
}

