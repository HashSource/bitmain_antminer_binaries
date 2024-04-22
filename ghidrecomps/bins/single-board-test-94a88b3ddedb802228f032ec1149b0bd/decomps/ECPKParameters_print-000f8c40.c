
int ECPKParameters_print(BIO *bp,EC_GROUP *x,int off)

{
  byte *pbVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *cofactor;
  EC_METHOD *meth;
  char *pcVar3;
  EC_POINT *pEVar4;
  point_conversion_form_t form;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int extraout_r1;
  int iVar8;
  size_t sVar9;
  BIGNUM *a;
  BIGNUM *b;
  BIGNUM *order;
  BIGNUM *buf;
  uint uVar10;
  BIGNUM *p;
  BIGNUM *local_c8;
  size_t local_c0;
  size_t local_b0;
  undefined local_a8;
  undefined auStack_a7 [131];
  
  if (x == (EC_GROUP *)0x0) {
    iVar2 = 0x43;
    cofactor = (BIGNUM *)0x0;
    ctx = (BN_CTX *)0x0;
    a = (BIGNUM *)0x0;
    b = (BIGNUM *)0x0;
    order = (BIGNUM *)0x0;
    buf = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
    local_c8 = (BIGNUM *)0x0;
  }
  else {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      iVar2 = 0x41;
      cofactor = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      b = (BIGNUM *)0x0;
      order = (BIGNUM *)0x0;
      buf = (BIGNUM *)0x0;
      p = (BIGNUM *)0x0;
      local_c8 = (BIGNUM *)0x0;
    }
    else {
      iVar2 = EC_GROUP_get_asn1_flag(x);
      if (iVar2 == 0) {
        meth = EC_GROUP_method_of(x);
        iVar2 = EC_METHOD_get_field_type(meth);
        p = BN_new();
        if (p == (BIGNUM *)0x0) {
          iVar2 = 0x41;
          cofactor = (BIGNUM *)0x0;
          a = (BIGNUM *)0x0;
          b = (BIGNUM *)0x0;
          order = (BIGNUM *)0x0;
          buf = (BIGNUM *)0x0;
          local_c8 = (BIGNUM *)0x0;
        }
        else {
          a = BN_new();
          if (a == (BIGNUM *)0x0) {
            iVar2 = 0x41;
            cofactor = (BIGNUM *)0x0;
            b = (BIGNUM *)0x0;
            order = (BIGNUM *)0x0;
            buf = (BIGNUM *)0x0;
            local_c8 = (BIGNUM *)0x0;
          }
          else {
            b = BN_new();
            if (b == (BIGNUM *)0x0) {
              iVar2 = 0x41;
              cofactor = (BIGNUM *)0x0;
              order = (BIGNUM *)0x0;
              buf = (BIGNUM *)0x0;
              local_c8 = (BIGNUM *)0x0;
            }
            else {
              order = BN_new();
              if (order == (BIGNUM *)0x0) {
                iVar2 = 0x41;
                cofactor = (BIGNUM *)0x0;
                buf = (BIGNUM *)0x0;
                local_c8 = (BIGNUM *)0x0;
              }
              else {
                cofactor = BN_new();
                if (cofactor == (BIGNUM *)0x0) {
                  iVar2 = 0x41;
                  buf = (BIGNUM *)0x0;
                  local_c8 = (BIGNUM *)0x0;
                }
                else if (iVar2 == 0x197) {
                  iVar8 = EC_GROUP_get_curve_GF2m();
                  if (iVar8 == 0) {
                    local_c8 = (BIGNUM *)0x0;
LAB_000f8d78:
                    iVar2 = 0x10;
                    buf = (BIGNUM *)0x0;
                  }
                  else {
LAB_000f8e22:
                    pEVar4 = EC_GROUP_get0_generator(x);
                    if (pEVar4 == (EC_POINT *)0x0) {
                      iVar2 = 0x10;
                      buf = (BIGNUM *)0x0;
                      local_c8 = (BIGNUM *)0x0;
                    }
                    else {
                      buf = (BIGNUM *)EC_GROUP_get_order(x,order,(BN_CTX *)0x0);
                      if ((buf == (BIGNUM *)0x0) ||
                         (buf = (BIGNUM *)EC_GROUP_get_cofactor(x,cofactor,(BN_CTX *)0x0),
                         buf == (BIGNUM *)0x0)) {
                        iVar2 = 0x10;
                        local_c8 = buf;
                      }
                      else {
                        form = EC_GROUP_get_point_conversion_form(x);
                        local_c8 = EC_POINT_point2bn(x,pEVar4,form,(BIGNUM *)0x0,ctx);
                        if (local_c8 == (BIGNUM *)0x0) goto LAB_000f8d78;
                        iVar5 = BN_num_bits(p);
                        iVar8 = iVar5 + 0xe;
                        if (-1 < iVar5 + 7) {
                          iVar8 = iVar5 + 7;
                        }
                        iVar6 = BN_num_bits(a);
                        iVar5 = iVar6 + 7;
                        if (iVar6 + 7 < 0) {
                          iVar5 = iVar6 + 0xe;
                        }
                        uVar10 = iVar8 >> 3;
                        if ((uint)(iVar8 >> 3) <= (uint)(iVar5 >> 3)) {
                          uVar10 = iVar5 >> 3;
                        }
                        iVar5 = BN_num_bits(b);
                        iVar8 = iVar5 + 7;
                        if (iVar5 + 7 < 0) {
                          iVar8 = iVar5 + 0xe;
                        }
                        if (uVar10 < (uint)(iVar8 >> 3)) {
                          uVar10 = iVar8 >> 3;
                        }
                        iVar5 = BN_num_bits(local_c8);
                        iVar8 = iVar5 + 7;
                        if (iVar5 + 7 < 0) {
                          iVar8 = iVar5 + 0xe;
                        }
                        if (uVar10 < (uint)(iVar8 >> 3)) {
                          uVar10 = iVar8 >> 3;
                        }
                        iVar5 = BN_num_bits(order);
                        iVar8 = iVar5 + 7;
                        if (iVar5 + 7 < 0) {
                          iVar8 = iVar5 + 0xe;
                        }
                        if (uVar10 < (uint)(iVar8 >> 3)) {
                          uVar10 = iVar8 >> 3;
                        }
                        iVar5 = BN_num_bits(cofactor);
                        iVar8 = iVar5 + 7;
                        if (iVar5 + 7 < 0) {
                          iVar8 = iVar5 + 0xe;
                        }
                        if (uVar10 < (uint)(iVar8 >> 3)) {
                          uVar10 = iVar8 >> 3;
                        }
                        puVar7 = EC_GROUP_get0_seed(x);
                        if (puVar7 == (uchar *)0x0) {
                          local_b0 = 0;
                        }
                        else {
                          local_b0 = EC_GROUP_get_seed_len(x);
                        }
                        buf = (BIGNUM *)CRYPTO_malloc(uVar10 + 10,DAT_000f9158,0x101);
                        if (buf == (BIGNUM *)0x0) {
                          iVar2 = 0x41;
                          goto LAB_000f8c94;
                        }
                        iVar8 = BIO_indent(bp,off,0x80);
                        if (iVar8 != 0) {
                          pcVar3 = OBJ_nid2sn(iVar2);
                          iVar8 = BIO_printf(bp,DAT_000f915c,pcVar3);
                          if (0 < iVar8) {
                            if (iVar2 == 0x197) {
                              iVar2 = EC_GROUP_get_basis_type(x);
                              if ((iVar2 != 0) && (iVar8 = BIO_indent(bp,off,0x80), iVar8 != 0)) {
                                pcVar3 = OBJ_nid2sn(iVar2);
                                iVar2 = BIO_printf(bp,DAT_000f9184,pcVar3);
                                if (0 < iVar2) {
                                  iVar2 = ASN1_bn_print(bp,DAT_000f9188,p,(uchar *)buf,off);
                                  goto joined_r0x000f90e2;
                                }
                              }
                            }
                            else {
                              iVar2 = ASN1_bn_print(bp,DAT_000f9160,p,(uchar *)buf,off);
joined_r0x000f90e2:
                              if (((iVar2 != 0) &&
                                  (iVar2 = ASN1_bn_print(bp,DAT_000f9164,a,(uchar *)buf,off),
                                  iVar2 != 0)) &&
                                 (iVar2 = ASN1_bn_print(bp,DAT_000f9168,b,(uchar *)buf,off),
                                 iVar2 != 0)) {
                                if (form == POINT_CONVERSION_COMPRESSED) {
                                  iVar2 = ASN1_bn_print(bp,DAT_000f9194,local_c8,(uchar *)buf,off);
                                }
                                else if (form == POINT_CONVERSION_UNCOMPRESSED) {
                                  iVar2 = ASN1_bn_print(bp,DAT_000f9190,local_c8,(uchar *)buf,off);
                                }
                                else {
                                  iVar2 = ASN1_bn_print(bp,DAT_000f916c,local_c8,(uchar *)buf,off);
                                }
                                if (((iVar2 != 0) &&
                                    (iVar2 = ASN1_bn_print(bp,DAT_000f9170,order,(uchar *)buf,off),
                                    iVar2 != 0)) &&
                                   (iVar2 = ASN1_bn_print(bp,DAT_000f9174,cofactor,(uchar *)buf,off)
                                   , iVar2 != 0)) {
                                  if (puVar7 == (uchar *)0x0) goto LAB_000f8df2;
                                  if (off < 1) {
                                    local_c0 = 0;
                                  }
                                  else {
                                    if (0x7f < off) {
                                      off = 0x80;
                                    }
                                    memset(&local_a8,0x20,off);
                                    iVar2 = BIO_write(bp,&local_a8,off);
                                    local_c0 = off;
                                    if (iVar2 < 1) goto LAB_000f8f64;
                                  }
                                  iVar2 = BIO_printf(bp,DAT_000f9178,DAT_000f917c);
                                  if (0 < iVar2) {
                                    sVar9 = 0;
                                    do {
                                      if (sVar9 == local_b0) {
                                        iVar2 = BIO_write(bp,DAT_000f918c,1);
                                        if (0 < iVar2) goto LAB_000f8df2;
                                        break;
                                      }
                                      __aeabi_uidivmod(sVar9,0xf);
                                      if (extraout_r1 == 0) {
                                        local_a8 = 10;
                                        memset(auStack_a7,0x20,local_c0 + 4);
                                        iVar2 = BIO_write(bp,&local_a8,local_c0 + 5);
                                        if (iVar2 < 1) break;
                                      }
                                      pbVar1 = puVar7 + sVar9;
                                      sVar9 = sVar9 + 1;
                                      pcVar3 = "";
                                      if (local_b0 != sVar9) {
                                        pcVar3 = ":";
                                      }
                                      iVar2 = BIO_printf(bp,DAT_000f9180,(uint)*pbVar1,pcVar3);
                                    } while (0 < iVar2);
                                  }
                                }
                              }
                            }
                          }
                        }
LAB_000f8f64:
                        iVar2 = 0x20;
                      }
                    }
                  }
                }
                else {
                  iVar8 = EC_GROUP_get_curve_GFp(x,p,a,b,ctx);
                  if (iVar8 != 0) goto LAB_000f8e22;
                  iVar2 = 0x10;
                  local_c8 = (BIGNUM *)0x0;
                  buf = (BIGNUM *)0x0;
                }
              }
            }
          }
        }
      }
      else {
        cofactor = (BIGNUM *)BIO_indent(bp,off,0x80);
        if ((cofactor != (BIGNUM *)0x0) &&
           (cofactor = (BIGNUM *)EC_GROUP_get_curve_name(x), cofactor != (BIGNUM *)0x0)) {
          pcVar3 = OBJ_nid2sn((int)cofactor);
          iVar2 = BIO_printf(bp,DAT_000f8e64,pcVar3);
          if ((0 < iVar2) && (iVar2 = BIO_printf(bp,DAT_000f8e68), 0 < iVar2)) {
            iVar2 = EC_curve_nid2nist(cofactor);
            if (iVar2 != 0) {
              cofactor = (BIGNUM *)BIO_indent(bp,off,0x80);
              if (cofactor == (BIGNUM *)0x0) goto LAB_000f8c74;
              iVar2 = BIO_printf(bp,DAT_000f8e6c,iVar2);
              if (iVar2 < 1) goto LAB_000f8e54;
            }
            cofactor = (BIGNUM *)0x0;
            order = (BIGNUM *)0x0;
            b = (BIGNUM *)0x0;
            a = (BIGNUM *)0x0;
            p = (BIGNUM *)0x0;
            buf = (BIGNUM *)0x0;
            local_c8 = (BIGNUM *)0x0;
LAB_000f8df2:
            iVar8 = 1;
            goto LAB_000f8ca6;
          }
LAB_000f8e54:
          cofactor = (BIGNUM *)0x0;
        }
LAB_000f8c74:
        iVar2 = 0x20;
        a = cofactor;
        b = cofactor;
        order = cofactor;
        buf = cofactor;
        p = cofactor;
        local_c8 = cofactor;
      }
    }
  }
LAB_000f8c94:
  iVar8 = 0;
  ERR_put_error(0x10,0x95,iVar2,DAT_000f8e60,0x141);
LAB_000f8ca6:
  if (p != (BIGNUM *)0x0) {
    BN_free(p);
  }
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (local_c8 != (BIGNUM *)0x0) {
    BN_free(local_c8);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (cofactor != (BIGNUM *)0x0) {
    BN_free(cofactor);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (buf != (BIGNUM *)0x0) {
    CRYPTO_free(buf);
  }
  return iVar8;
}

