
int ECPKParameters_print(BIO *bp,EC_GROUP *x,int off)

{
  byte *pbVar1;
  BN_CTX *c;
  int iVar2;
  BIGNUM *num;
  EC_METHOD *meth;
  BIGNUM *num_00;
  BIGNUM *num_01;
  BIGNUM *num_02;
  EC_POINT *pEVar3;
  BIGNUM *num_03;
  BIGNUM *num_04;
  point_conversion_form_t form;
  uchar *puVar4;
  char *pcVar5;
  void *data;
  int extraout_r1;
  int iVar6;
  size_t sVar7;
  char *local_c8;
  char *local_c4;
  size_t local_b4;
  undefined1 local_b0;
  undefined1 auStack_af [139];
  
  if (x == (EC_GROUP *)0x0) {
    iVar2 = 0x43;
    num = (BIGNUM *)0x0;
    c = (BN_CTX *)0x0;
    num_00 = (BIGNUM *)0x0;
    num_01 = (BIGNUM *)0x0;
    num_02 = (BIGNUM *)0x0;
  }
  else {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar2 = 0x41;
      num = (BIGNUM *)0x0;
      num_00 = (BIGNUM *)0x0;
      num_01 = (BIGNUM *)0x0;
      num_02 = (BIGNUM *)0x0;
    }
    else {
      iVar2 = EC_GROUP_get_asn1_flag(x);
      if (iVar2 == 0) {
        meth = EC_GROUP_method_of(x);
        iVar2 = EC_METHOD_get_field_type(meth);
        num_00 = BN_new();
        if (num_00 == (BIGNUM *)0x0) {
          iVar2 = 0x41;
          num = (BIGNUM *)0x0;
          num_01 = (BIGNUM *)0x0;
          num_02 = (BIGNUM *)0x0;
        }
        else {
          num_01 = BN_new();
          if (num_01 == (BIGNUM *)0x0) {
            iVar2 = 0x41;
            num = (BIGNUM *)0x0;
            num_02 = (BIGNUM *)0x0;
          }
          else {
            num_02 = BN_new();
            if (num_02 == (BIGNUM *)0x0) {
              iVar2 = 0x41;
              num = (BIGNUM *)0x0;
            }
            else {
              iVar6 = EC_GROUP_get_curve(x,num_00,num_01,num_02,c);
              if (iVar6 == 0) {
                iVar2 = 0x10;
                num = (BIGNUM *)0x0;
              }
              else {
                pEVar3 = EC_GROUP_get0_generator(x);
                if (pEVar3 == (EC_POINT *)0x0) {
                  iVar2 = 0x10;
                  num = (BIGNUM *)0x0;
                }
                else {
                  num_03 = (BIGNUM *)EC_GROUP_get0_order(x);
                  num_04 = (BIGNUM *)EC_GROUP_get0_cofactor(x);
                  if (num_03 == (BIGNUM *)0x0) {
                    iVar2 = 0x10;
                    num = (BIGNUM *)0x0;
                  }
                  else {
                    form = EC_GROUP_get_point_conversion_form(x);
                    num = EC_POINT_point2bn(x,pEVar3,form,(BIGNUM *)0x0,c);
                    if (num == (BIGNUM *)0x0) {
                      iVar2 = 0x10;
                    }
                    else {
                      puVar4 = EC_GROUP_get0_seed(x);
                      if (puVar4 == (uchar *)0x0) {
                        local_b4 = 0;
                      }
                      else {
                        local_b4 = EC_GROUP_get_seed_len(x);
                      }
                      iVar6 = BIO_indent(bp,off,0x80);
                      if (iVar6 != 0) {
                        pcVar5 = OBJ_nid2sn(iVar2);
                        iVar6 = BIO_printf(bp,"Field Type: %s\n",pcVar5);
                        if (0 < iVar6) {
                          if (iVar2 == 0x197) {
                            iVar2 = EC_GROUP_get_basis_type(x);
                            if ((iVar2 != 0) && (iVar6 = BIO_indent(bp,off,0x80), iVar6 != 0)) {
                              pcVar5 = OBJ_nid2sn(iVar2);
                              iVar2 = BIO_printf(bp,"Basis Type: %s\n",pcVar5);
                              if (0 < iVar2) {
                                iVar2 = ASN1_bn_print(bp,"Polynomial:",num_00,(uchar *)0x0,off);
                                goto joined_r0x0012b7cc;
                              }
                            }
                          }
                          else {
                            iVar2 = ASN1_bn_print(bp,"Prime:",num_00,(uchar *)0x0,off);
joined_r0x0012b7cc:
                            if (((iVar2 != 0) &&
                                (iVar2 = ASN1_bn_print(bp,"A:   ",num_01,(uchar *)0x0,off),
                                iVar2 != 0)) &&
                               (iVar2 = ASN1_bn_print(bp,"B:   ",num_02,(uchar *)0x0,off),
                               iVar2 != 0)) {
                              if (form == POINT_CONVERSION_COMPRESSED) {
                                iVar2 = ASN1_bn_print(bp,"Generator (compressed):",num,(uchar *)0x0,
                                                      off);
                              }
                              else if (form == POINT_CONVERSION_UNCOMPRESSED) {
                                iVar2 = ASN1_bn_print(bp,"Generator (uncompressed):",num,
                                                      (uchar *)0x0,off);
                              }
                              else {
                                iVar2 = ASN1_bn_print(bp,"Generator (hybrid):",num,(uchar *)0x0,off)
                                ;
                              }
                              if (((iVar2 != 0) &&
                                  (iVar2 = ASN1_bn_print(bp,"Order: ",num_03,(uchar *)0x0,off),
                                  iVar2 != 0)) &&
                                 ((num_04 == (BIGNUM *)0x0 ||
                                  (iVar2 = ASN1_bn_print(bp,"Cofactor: ",num_04,(uchar *)0x0,off),
                                  iVar2 != 0)))) {
                                if (puVar4 == (uchar *)0x0) {
LAB_0012b7fe:
                                  iVar6 = 1;
                                  goto LAB_0012b492;
                                }
                                if (off < 1) {
                                  off = 0;
                                }
                                else {
                                  if (0x7f < off) {
                                    off = 0x80;
                                  }
                                  data = memset(&local_b0,0x20,off);
                                  iVar2 = BIO_write(bp,data,off);
                                  if (iVar2 < 1) goto LAB_0012b58c;
                                }
                                iVar2 = BIO_printf(bp,"%s","Seed:");
                                if (0 < iVar2) {
                                  sVar7 = 0;
                                  local_c8 = "";
                                  local_c4 = ":";
                                  do {
                                    if (local_b4 == sVar7) {
                                      iVar2 = BIO_write(bp,"\n",1);
                                      if (0 < iVar2) goto LAB_0012b7fe;
                                      break;
                                    }
                                    __aeabi_uidivmod(sVar7,0xf);
                                    if (extraout_r1 == 0) {
                                      local_b0 = 10;
                                      memset(auStack_af,0x20,off + 4);
                                      iVar2 = BIO_write(bp,&local_b0,off + 5);
                                      if (iVar2 < 1) break;
                                    }
                                    pbVar1 = puVar4 + sVar7;
                                    sVar7 = sVar7 + 1;
                                    pcVar5 = local_c8;
                                    if (local_b4 != sVar7) {
                                      pcVar5 = local_c4;
                                    }
                                    iVar2 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,pcVar5);
                                  } while (0 < iVar2);
                                }
                              }
                            }
                          }
                        }
                      }
LAB_0012b58c:
                      iVar2 = 0x20;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        num = (BIGNUM *)BIO_indent(bp,off,0x80);
        if (num == (BIGNUM *)0x0) {
LAB_0012b46a:
          iVar2 = 0x20;
          num_00 = num;
          num_01 = num;
          num_02 = num;
        }
        else {
          num = (BIGNUM *)EC_GROUP_get_curve_name(x);
          if (num != (BIGNUM *)0x0) {
            pcVar5 = OBJ_nid2sn((int)num);
            iVar2 = BIO_printf(bp,"ASN1 OID: %s",pcVar5);
            if ((0 < iVar2) && (iVar2 = BIO_printf(bp,"\n"), 0 < iVar2)) {
              iVar2 = EC_curve_nid2nist(num);
              if (iVar2 != 0) {
                num = (BIGNUM *)BIO_indent(bp,off,0x80);
                if (num == (BIGNUM *)0x0) goto LAB_0012b46a;
                iVar2 = BIO_printf(bp,"NIST CURVE: %s\n",iVar2);
                if (iVar2 < 1) goto LAB_0012b5e8;
              }
              num = (BIGNUM *)0x0;
              iVar6 = 1;
              num_00 = num;
              num_01 = num;
              num_02 = num;
              goto LAB_0012b492;
            }
LAB_0012b5e8:
            num = (BIGNUM *)0x0;
          }
          iVar2 = 0x20;
          num_00 = num;
          num_01 = num;
          num_02 = num;
        }
      }
    }
  }
  iVar6 = 0;
  ERR_put_error(0x10,0x95,iVar2,"crypto/ec/eck_prn.c",0xd6);
LAB_0012b492:
  BN_free(num_00);
  BN_free(num_01);
  BN_free(num_02);
  BN_free(num);
  BN_CTX_free(c);
  return iVar6;
}

