
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  undefined4 *val;
  BIGNUM *a;
  int iVar1;
  int iVar2;
  uchar *__s;
  int iVar3;
  size_t num;
  uchar *buf;
  ASN1_OBJECT *pAVar4;
  uint uVar5;
  ASN1_STRING *pAVar6;
  uint len;
  ASN1_STRING *pAVar7;
  int *val_00;
  EC_GROUP *group;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) ||
     ((-1 < *(int *)(key + 0x10) << 0x1e && (*(int *)(key + 8) == 0)))) {
    ERR_put_error(0x10,0xc0,0x43,DAT_000f6060,0x462);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new(DAT_000f605c);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,DAT_000f6060,0x467);
    return 0;
  }
  a = *(BIGNUM **)(key + 0xc);
  *val = *(undefined4 *)key;
  iVar1 = BN_num_bits(a);
  iVar3 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar3 = iVar1 + 7;
  }
  iVar2 = EC_GROUP_get_degree(*(EC_GROUP **)(key + 4));
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  uVar5 = iVar3 >> 3;
  len = iVar1 >> 3;
  if (len < uVar5) {
    ERR_put_error(0x10,0xc0,100,DAT_000f6060,0x474);
  }
  else {
    __s = (uchar *)CRYPTO_malloc(len,DAT_000f6060,0x478);
    if (__s != (uchar *)0x0) {
      iVar3 = BN_bn2bin(*(BIGNUM **)(key + 0xc),__s + (len - uVar5));
      if (iVar3 == 0) {
        ERR_put_error(0x10,0xc0,3,DAT_000f6060,0x47f);
        pAVar6 = (ASN1_STRING *)0x0;
        pAVar7 = (ASN1_STRING *)0x0;
      }
      else {
        if (len != uVar5) {
          memset(__s,0,len - uVar5);
        }
        pAVar6 = (ASN1_STRING *)ASN1_STRING_set((ASN1_STRING *)val[1],__s,len);
        iVar3 = 0x488;
        buf = __s;
        if (pAVar6 == (ASN1_STRING *)0x0) {
LAB_000f5ef6:
          ERR_put_error(0x10,0xc0,0xd,DAT_000f6060,iVar3);
          pAVar7 = pAVar6;
          __s = buf;
        }
        else {
          uVar5 = *(uint *)(key + 0x10);
          if ((int)(uVar5 << 0x1f) < 0) {
LAB_000f5e70:
            if ((uVar5 & 2) == 0) {
              pAVar6 = ASN1_STRING_type_new(3);
              iVar3 = 0x498;
              val[3] = pAVar6;
              if (pAVar6 != (ASN1_STRING *)0x0) {
                num = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                         *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                         (BN_CTX *)0x0);
                if ((num <= len) ||
                   (buf = (uchar *)CRYPTO_realloc(__s,num,DAT_000f6060,0x4a0), len = num,
                   buf != (uchar *)0x0)) {
                  pAVar6 = (ASN1_STRING *)
                           EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                              *(point_conversion_form_t *)(key + 0x14),buf,len,
                                              (BN_CTX *)0x0);
                  iVar3 = 0x4ab;
                  __s = buf;
                  if (pAVar6 == (ASN1_STRING *)0x0) goto LAB_000f5fe6;
                  pAVar6 = (ASN1_STRING *)val[3];
                  pAVar6->flags = pAVar6->flags & 0xfffffff0U | 8;
                  iVar3 = ASN1_STRING_set(pAVar6,buf,len);
                  if (iVar3 == 0) {
                    iVar3 = 0x4b2;
                    pAVar6 = (ASN1_STRING *)0x0;
                    goto LAB_000f5ef6;
                  }
                  goto LAB_000f5f52;
                }
                iVar3 = 0x4a2;
                pAVar6 = (ASN1_STRING *)0x0;
              }
              ERR_put_error(0x10,0xc0,0x41,DAT_000f6060,iVar3);
              pAVar7 = pAVar6;
            }
            else {
LAB_000f5f52:
              pAVar6 = (ASN1_STRING *)ASN1_item_i2d((ASN1_VALUE *)val,out,DAT_000f605c);
              pAVar7 = (ASN1_STRING *)0x1;
              __s = buf;
              if (pAVar6 == (ASN1_STRING *)0x0) {
                ERR_put_error(0x10,0xc0,0x10,DAT_000f6060,0x4b8);
                pAVar7 = (ASN1_STRING *)0x0;
              }
            }
          }
          else {
            val_00 = (int *)val[2];
            group = *(EC_GROUP **)(key + 4);
            if (val_00 == (int *)0x0) {
              val_00 = (int *)ASN1_item_new(DAT_000f6064);
              if (val_00 != (int *)0x0) goto LAB_000f5fc4;
              ERR_put_error(0x10,0x9c,0x41,DAT_000f6060,0x28d);
            }
            else {
              if (*val_00 == 0) {
                if ((ASN1_OBJECT *)val_00[1] != (ASN1_OBJECT *)0x0) {
                  ASN1_OBJECT_free((ASN1_OBJECT *)val_00[1]);
                }
              }
              else if ((*val_00 == 1) && ((ASN1_VALUE *)val_00[1] != (ASN1_VALUE *)0x0)) {
                ASN1_item_free((ASN1_VALUE *)val_00[1],DAT_000f6068);
              }
LAB_000f5fc4:
              iVar3 = EC_GROUP_get_asn1_flag(group);
              if (iVar3 == 0) {
                *val_00 = 1;
                pAVar4 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(group);
                val_00[1] = (int)pAVar4;
joined_r0x000f6008:
                if (pAVar4 != (ASN1_OBJECT *)0x0) {
                  val[2] = val_00;
                  uVar5 = *(uint *)(key + 0x10);
                  goto LAB_000f5e70;
                }
              }
              else {
                iVar3 = EC_GROUP_get_curve_name(group);
                if (iVar3 != 0) {
                  *val_00 = 0;
                  pAVar4 = OBJ_nid2obj(iVar3);
                  val_00[1] = (int)pAVar4;
                  goto joined_r0x000f6008;
                }
              }
              ASN1_item_free((ASN1_VALUE *)val_00,DAT_000f6064);
            }
            iVar3 = 0x490;
            pAVar6 = (ASN1_STRING *)0x0;
            val[2] = 0;
LAB_000f5fe6:
            ERR_put_error(0x10,0xc0,0x10,DAT_000f6060,iVar3);
            pAVar7 = pAVar6;
          }
        }
      }
      CRYPTO_free(__s);
      goto LAB_000f5e0c;
    }
    ERR_put_error(0x10,0xc0,0x41,DAT_000f6060,0x47a);
  }
  pAVar7 = (ASN1_STRING *)0x0;
  pAVar6 = (ASN1_STRING *)0x0;
LAB_000f5e0c:
  ASN1_item_free((ASN1_VALUE *)val,DAT_000f605c);
  if (pAVar7 == (ASN1_STRING *)0x0) {
    return 0;
  }
  return (int)pAVar6;
}

