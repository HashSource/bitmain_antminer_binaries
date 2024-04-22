
undefined4 do_EC_KEY_print(BIO *param_1,EC_KEY *param_2,int param_3,int param_4)

{
  EC_GROUP *group;
  BN_CTX *c;
  EC_POINT *pEVar1;
  point_conversion_form_t form;
  BIGNUM *a;
  int iVar2;
  BIGNUM *order;
  int iVar3;
  uint uVar4;
  BIGNUM *buf;
  undefined4 uVar5;
  BIGNUM *a_00;
  undefined4 local_2c;
  
  if ((param_2 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_2), group == (EC_GROUP *)0x0))
  {
    c = (BN_CTX *)0x0;
    iVar3 = 0x43;
    order = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    buf = (BIGNUM *)0x0;
  }
  else {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar3 = 0x41;
      a = (BIGNUM *)0x0;
      order = (BIGNUM *)0x0;
      buf = (BIGNUM *)0x0;
    }
    else {
      if (param_4 < 1) {
        a_00 = (BIGNUM *)0x0;
        a = (BIGNUM *)0x0;
        local_2c = DAT_000f7e8c;
        buf = (BIGNUM *)0x0;
      }
      else {
        pEVar1 = EC_KEY_get0_public_key(param_2);
        if (pEVar1 == (EC_POINT *)0x0) {
          uVar4 = 0;
          a = (BIGNUM *)0x0;
        }
        else {
          form = EC_KEY_get_conv_form(param_2);
          a = EC_POINT_point2bn(group,pEVar1,form,(BIGNUM *)0x0,c);
          if (a == (BIGNUM *)0x0) {
            iVar3 = 0x10;
            order = (BIGNUM *)0x0;
            buf = (BIGNUM *)0x0;
            goto LAB_000f7d5e;
          }
          iVar2 = BN_num_bits(a);
          iVar3 = iVar2 + 0xe;
          if (-1 < iVar2 + 7) {
            iVar3 = iVar2 + 7;
          }
          uVar4 = iVar3 >> 3;
        }
        if (param_4 == 2) {
          a_00 = EC_KEY_get0_private_key(param_2);
          if (a_00 != (BIGNUM *)0x0) {
            iVar2 = BN_num_bits(a_00);
            iVar3 = iVar2 + 0xe;
            if (-1 < iVar2 + 7) {
              iVar3 = iVar2 + 7;
            }
            if (uVar4 < (uint)(iVar3 >> 3)) {
              uVar4 = iVar3 >> 3;
            }
          }
          order = (BIGNUM *)CRYPTO_malloc(uVar4 + 10,DAT_000f7e88,0x1c9);
          if (order == (BIGNUM *)0x0) goto LAB_000f7e7a;
          local_2c = DAT_000f7e94;
          buf = order;
        }
        else {
          order = (BIGNUM *)CRYPTO_malloc(uVar4 + 10,DAT_000f7e88,0x1c9);
          if (order == (BIGNUM *)0x0) {
LAB_000f7e7a:
            iVar3 = 0x41;
            buf = order;
            goto LAB_000f7d5e;
          }
          a_00 = (BIGNUM *)0x0;
          buf = order;
          local_2c = DAT_000f7e8c;
          if (param_4 == 1) {
            local_2c = DAT_000f7e90;
          }
        }
      }
      order = (BIGNUM *)BIO_indent(param_1,param_3,0x80);
      iVar3 = 0x20;
      if (order != (BIGNUM *)0x0) {
        order = BN_new();
        if ((order != (BIGNUM *)0x0) &&
           (iVar3 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0), iVar3 != 0)) {
          iVar3 = BN_num_bits(order);
          iVar3 = BIO_printf(param_1,DAT_000f7e98,local_2c,iVar3);
          if (((0 < iVar3) &&
              ((a_00 == (BIGNUM *)0x0 ||
               (iVar3 = ASN1_bn_print(param_1,DAT_000f7e9c,a_00,(uchar *)buf,param_3), iVar3 != 0)))
              ) && ((a == (BIGNUM *)0x0 ||
                    (iVar3 = ASN1_bn_print(param_1,DAT_000f7ea0,a,(uchar *)buf,param_3), iVar3 != 0)
                    ))) {
            uVar5 = 1;
            iVar3 = ECPKParameters_print(param_1,group,param_3);
            if (iVar3 != 0) goto LAB_000f7d72;
          }
        }
        iVar3 = 0x20;
      }
    }
  }
LAB_000f7d5e:
  uVar5 = 0;
  ERR_put_error(0x10,0xdd,iVar3,DAT_000f7e88,0x1e9);
LAB_000f7d72:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  if (buf != (BIGNUM *)0x0) {
    CRYPTO_free(buf);
  }
  return uVar5;
}

