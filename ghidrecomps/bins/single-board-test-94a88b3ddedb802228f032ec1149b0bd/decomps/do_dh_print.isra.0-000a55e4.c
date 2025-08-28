
undefined4 do_dh_print_isra_0(BIO *param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  BIGNUM *a;
  BIGNUM *a_00;
  char *pcVar7;
  
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
    uVar5 = iVar3 >> 3;
    if (uVar5 != 0) {
      if (*(BIGNUM **)(param_2 + 0xc) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0xc));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x24) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x24));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x28) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x28));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (*(BIGNUM **)(param_2 + 0x34) != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x34));
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (a_00 != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(a_00);
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (a != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(a);
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (param_4 == 2) {
        pcVar7 = "DH Private-Key";
      }
      else if (param_4 == 1) {
        pcVar7 = "DH Public-Key";
      }
      else {
        pcVar7 = "DH Parameters";
      }
      buf = (uchar *)CRYPTO_malloc(uVar5 + 10,"dh_ameth.c",0x177);
      if (buf == (uchar *)0x0) {
        iVar3 = 0x41;
        goto LAB_000a574c;
      }
      BIO_indent(param_1,param_3,0x80);
      iVar3 = BN_num_bits(*(BIGNUM **)(param_2 + 8));
      iVar3 = BIO_printf(param_1,"%s: (%d bit)\n",pcVar7,iVar3);
      if (0 < iVar3) {
        iVar2 = param_3 + 4;
        iVar3 = ASN1_bn_print(param_1,"private-key:",a,buf,iVar2);
        if (((((iVar3 != 0) &&
              (iVar3 = ASN1_bn_print(param_1,"public-key:",a_00,buf,iVar2), iVar3 != 0)) &&
             (iVar3 = ASN1_bn_print(param_1,"prime:",*(BIGNUM **)(param_2 + 8),buf,iVar2),
             iVar3 != 0)) &&
            (iVar3 = ASN1_bn_print(param_1,"generator:",*(BIGNUM **)(param_2 + 0xc),buf,iVar2),
            iVar3 != 0)) &&
           (((*(BIGNUM **)(param_2 + 0x24) == (BIGNUM *)0x0 ||
             (iVar3 = ASN1_bn_print(param_1,"subgroup order:",*(BIGNUM **)(param_2 + 0x24),buf,iVar2
                                   ), iVar3 != 0)) &&
            ((*(BIGNUM **)(param_2 + 0x28) == (BIGNUM *)0x0 ||
             (iVar3 = ASN1_bn_print(param_1,"subgroup factor:",*(BIGNUM **)(param_2 + 0x28),buf,
                                    iVar2), iVar3 != 0)))))) {
          if (*(int *)(param_2 + 0x2c) == 0) {
LAB_000a5844:
            if ((*(BIGNUM **)(param_2 + 0x34) == (BIGNUM *)0x0) ||
               (iVar3 = ASN1_bn_print(param_1,"counter:",*(BIGNUM **)(param_2 + 0x34),buf,iVar2),
               iVar3 != 0)) {
              if (*(int *)(param_2 + 0x10) != 0) {
                BIO_indent(param_1,iVar2,0x80);
                iVar3 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                                   *(undefined4 *)(param_2 + 0x10));
                if (iVar3 < 1) goto LAB_000a572e;
              }
              uVar6 = 1;
              goto LAB_000a5742;
            }
          }
          else {
            BIO_indent(param_1,iVar2,0x80);
            BIO_puts(param_1,"seed:");
            iVar3 = 0;
            do {
              iVar4 = *(int *)(param_2 + 0x30);
              if (iVar4 <= iVar3) {
                iVar3 = BIO_write(param_1,"\n",1);
                if (iVar3 < 1) {
                  return 0;
                }
                goto LAB_000a5844;
              }
              if (iVar3 == (iVar3 / 0xf) * 0xf) {
                iVar4 = BIO_puts(param_1,"\n");
                if ((iVar4 < 1) || (iVar4 = BIO_indent(param_1,param_3 + 8,0x80), iVar4 == 0))
                break;
                iVar4 = *(int *)(param_2 + 0x30);
              }
              pbVar1 = (byte *)(*(int *)(param_2 + 0x2c) + iVar3);
              iVar3 = iVar3 + 1;
              if (iVar3 == iVar4) {
                pcVar7 = "";
              }
              else {
                pcVar7 = ":";
              }
              iVar4 = BIO_printf(param_1,"%02x%s",(uint)*pbVar1,pcVar7);
            } while (0 < iVar4);
          }
        }
      }
LAB_000a572e:
      uVar6 = 0;
      ERR_put_error(5,100,7,"dh_ameth.c",0x1ac);
LAB_000a5742:
      CRYPTO_free(buf);
      return uVar6;
    }
  }
  iVar3 = 0x43;
LAB_000a574c:
  ERR_put_error(5,100,iVar3,"dh_ameth.c",0x1ac);
  return 0;
}

