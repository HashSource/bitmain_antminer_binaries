
ASN1_VALUE * ec_asn1_group2parameters_constprop_0(EC_GROUP *param_1)

{
  EC_GROUP *pEVar1;
  bool bVar2;
  BIGNUM *order;
  ASN1_VALUE *val;
  EC_METHOD *pEVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  ASN1_VALUE *pAVar6;
  ASN1_INTEGER *pAVar7;
  BIGNUM *pBVar8;
  BIGNUM *b;
  EC_POINT *p;
  point_conversion_form_t form;
  size_t len;
  size_t sVar9;
  ASN1_STRING *str;
  uchar *to;
  ASN1_VALUE *pAVar10;
  void *data;
  int iVar11;
  int iVar12;
  EC_GROUP *pEVar13;
  undefined4 *puVar14;
  uchar *puVar15;
  int *piVar16;
  ASN1_BIT_STRING *str_00;
  uchar *puVar17;
  uchar *data_00;
  int local_34;
  uchar local_30 [12];
  
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x22a);
    return (ASN1_VALUE *)0x0;
  }
  val = ASN1_item_new((ASN1_ITEM *)&ECPARAMETERS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x230);
    puVar15 = (uchar *)0x0;
    goto LAB_000f533c;
  }
  puVar14 = *(undefined4 **)(val + 4);
  *(undefined4 *)val = 1;
  if (puVar14 == (undefined4 *)0x0 || param_1 == (EC_GROUP *)0x0) goto LAB_000f531e;
  if ((ASN1_OBJECT *)*puVar14 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)*puVar14);
  }
  if ((ASN1_TYPE *)puVar14[1] != (ASN1_TYPE *)0x0) {
    ASN1_TYPE_free((ASN1_TYPE *)puVar14[1]);
  }
  pEVar3 = EC_GROUP_method_of(param_1);
  iVar4 = EC_METHOD_get_field_type(pEVar3);
  pAVar5 = OBJ_nid2obj(iVar4);
  iVar12 = 0x148;
  *puVar14 = pAVar5;
  if (pAVar5 == (ASN1_OBJECT *)0x0) {
LAB_000f56aa:
    ERR_put_error(0x10,0x9a,8,"ec_asn1.c",iVar12);
    goto LAB_000f531e;
  }
  if (iVar4 == 0x196) {
    pBVar8 = BN_new();
    iVar4 = 0x14e;
    if (pBVar8 == (BIGNUM *)0x0) goto LAB_000f5640;
    iVar4 = EC_GROUP_get_curve_GFp(param_1,pBVar8,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
    if (iVar4 == 0) {
      ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x153);
      bVar2 = false;
    }
    else {
      pAVar7 = BN_to_ASN1_INTEGER(pBVar8,(ASN1_INTEGER *)0x0);
      puVar14[1] = pAVar7;
      bVar2 = true;
      if (pAVar7 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x159);
        bVar2 = false;
      }
    }
    BN_free(pBVar8);
    if (!bVar2) goto LAB_000f531e;
LAB_000f5434:
    piVar16 = *(int **)(val + 8);
    local_30[0] = '\0';
    if (((piVar16 == (int *)0x0) || (*piVar16 == 0)) || (piVar16[1] == 0)) {
LAB_000f55a8:
      iVar4 = 0x241;
      goto LAB_000f5322;
    }
    pBVar8 = BN_new();
    if ((pBVar8 == (BIGNUM *)0x0) || (b = BN_new(), b == (BIGNUM *)0x0)) {
      b = (BIGNUM *)0x0;
      ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1bc);
LAB_000f55c4:
      if (pBVar8 != (BIGNUM *)0x0) {
        bVar2 = false;
        goto LAB_000f5548;
      }
      bVar2 = false;
    }
    else {
      pEVar3 = EC_GROUP_method_of(param_1);
      iVar4 = EC_METHOD_get_field_type(pEVar3);
      if (iVar4 == 0x196) {
        iVar4 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,pBVar8,b,(BN_CTX *)0x0);
        iVar12 = 0x1c5;
        if (iVar4 == 0) goto LAB_000f582c;
      }
      else {
        iVar4 = EC_GROUP_get_curve_GF2m();
        if (iVar4 == 0) {
          iVar12 = 0x1cd;
LAB_000f582c:
          ERR_put_error(0x10,0x99,0x10,"ec_asn1.c",iVar12);
          goto LAB_000f55c4;
        }
      }
      iVar12 = BN_num_bits(pBVar8);
      iVar4 = iVar12 + 0xe;
      if (-1 < iVar12 + 7) {
        iVar4 = iVar12 + 7;
      }
      puVar15 = (uchar *)(iVar4 >> 3);
      iVar12 = BN_num_bits(b);
      iVar4 = iVar12 + 0xe;
      if (-1 < iVar12 + 7) {
        iVar4 = iVar12 + 7;
      }
      iVar12 = 1;
      data_00 = local_30;
      if (puVar15 == (uchar *)0x0) {
LAB_000f54cc:
        if (iVar4 >> 3 == 0) {
          to = local_30;
          local_34 = 1;
          puVar17 = (uchar *)0x0;
LAB_000f54dc:
          iVar4 = ASN1_STRING_set((ASN1_STRING *)*piVar16,data_00,iVar12);
          if ((iVar4 == 0) ||
             (iVar4 = ASN1_STRING_set((ASN1_STRING *)piVar16[1],to,local_34), iVar4 == 0)) {
            ERR_put_error(0x10,0x99,0xd,"ec_asn1.c",0x1f8);
joined_r0x000f5804:
            bVar2 = false;
          }
          else {
            data = *(void **)(param_1 + 0x3c);
            if (data == (void *)0x0) {
              bVar2 = true;
              if ((ASN1_BIT_STRING *)piVar16[2] != (ASN1_BIT_STRING *)0x0) {
                ASN1_BIT_STRING_free((ASN1_BIT_STRING *)piVar16[2]);
                piVar16[2] = 0;
                goto joined_r0x000f5804;
              }
            }
            else {
              str_00 = (ASN1_BIT_STRING *)piVar16[2];
              if (str_00 == (ASN1_STRING *)0x0) {
                str_00 = ASN1_BIT_STRING_new();
                piVar16[2] = (int)str_00;
                if (str_00 == (ASN1_BIT_STRING *)0x0) {
                  ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x200);
                  goto joined_r0x000f5804;
                }
                data = *(void **)(param_1 + 0x3c);
              }
              iVar4 = *(int *)(param_1 + 0x40);
              str_00->flags = str_00->flags & 0xfffffff0U | 8;
              iVar4 = ASN1_BIT_STRING_set(str_00,data,iVar4);
              if (iVar4 == 0) {
                ERR_put_error(0x10,0x99,0xd,"ec_asn1.c",0x207);
                goto joined_r0x000f5804;
              }
            }
            bVar2 = true;
          }
        }
        else {
          to = (uchar *)CRYPTO_malloc(iVar4 >> 3,"ec_asn1.c",0x1ea);
          puVar17 = to;
          if (to != (uchar *)0x0) {
            local_34 = BN_bn2bin(b,to);
            if (local_34 != 0) goto LAB_000f54dc;
            ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x1ef);
            goto joined_r0x000f5804;
          }
          ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1eb);
          bVar2 = false;
        }
joined_r0x000f5804:
        if (puVar15 != (uchar *)0x0) goto LAB_000f57a6;
      }
      else {
        puVar15 = (uchar *)CRYPTO_malloc((int)puVar15,"ec_asn1.c",0x1da);
        if (puVar15 == (uchar *)0x0) {
          ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1db);
          goto LAB_000f55c4;
        }
        iVar12 = BN_bn2bin(pBVar8,puVar15);
        data_00 = puVar15;
        if (iVar12 != 0) goto LAB_000f54cc;
        ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x1df);
        bVar2 = false;
        puVar17 = (uchar *)0x0;
LAB_000f57a6:
        CRYPTO_free(puVar15);
      }
      if (puVar17 != (uchar *)0x0) {
        CRYPTO_free(puVar17);
      }
LAB_000f5548:
      BN_free(pBVar8);
    }
    if (b != (BIGNUM *)0x0) {
      BN_free(b);
    }
    if (!bVar2) goto LAB_000f55a8;
    p = EC_GROUP_get0_generator(param_1);
    if (p == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0x9b,0x71,"ec_asn1.c",0x247);
      puVar15 = (uchar *)0x0;
    }
    else {
      form = EC_GROUP_get_point_conversion_form(param_1);
      len = EC_POINT_point2oct(param_1,p,form,(uchar *)0x0,0,(BN_CTX *)0x0);
      if (len == 0) {
        ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x24f);
        puVar15 = (uchar *)0x0;
      }
      else {
        puVar15 = (uchar *)CRYPTO_malloc(len,"ec_asn1.c",0x252);
        iVar4 = 0x253;
        if (puVar15 == (uchar *)0x0) {
LAB_000f57be:
          ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",iVar4);
        }
        else {
          sVar9 = EC_POINT_point2oct(param_1,p,form,puVar15,len,(BN_CTX *)0x0);
          iVar4 = 599;
          if (sVar9 == 0) {
LAB_000f562c:
            ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",iVar4);
          }
          else {
            str = *(ASN1_STRING **)(val + 0xc);
            if (str == (ASN1_STRING *)0x0) {
              str = ASN1_OCTET_STRING_new();
              *(ASN1_STRING **)(val + 0xc) = str;
              if (str == (ASN1_OCTET_STRING *)0x0) {
                iVar4 = 0x25b;
                goto LAB_000f57be;
              }
            }
            iVar4 = ASN1_OCTET_STRING_set(str,puVar15,len);
            iVar12 = 0x25f;
            if (iVar4 != 0) {
              iVar4 = EC_GROUP_get_order(param_1,order,(BN_CTX *)0x0);
              if (iVar4 == 0) {
                iVar4 = 0x265;
                goto LAB_000f562c;
              }
              pAVar7 = BN_to_ASN1_INTEGER(order,*(ASN1_INTEGER **)(val + 0x10));
              iVar12 = 0x26a;
              *(ASN1_INTEGER **)(val + 0x10) = pAVar7;
              if (pAVar7 != (ASN1_INTEGER *)0x0) {
                iVar4 = EC_GROUP_get_cofactor(param_1,order,(BN_CTX *)0x0);
                if (iVar4 == 0) goto LAB_000f533c;
                pAVar7 = BN_to_ASN1_INTEGER(order,*(ASN1_INTEGER **)(val + 0x14));
                *(ASN1_INTEGER **)(val + 0x14) = pAVar7;
                if (pAVar7 != (ASN1_INTEGER *)0x0) goto LAB_000f533c;
                iVar12 = 0x272;
              }
            }
            ERR_put_error(0x10,0x9b,0xd,"ec_asn1.c",iVar12);
          }
        }
      }
    }
  }
  else {
    pAVar6 = ASN1_item_new((ASN1_ITEM *)X9_62_CHARACTERISTIC_TWO_it);
    iVar4 = 0x16b;
    puVar14[1] = pAVar6;
    if (pAVar6 == (ASN1_VALUE *)0x0) {
LAB_000f5640:
      ERR_put_error(0x10,0x9a,0x41,"ec_asn1.c",iVar4);
    }
    else {
      iVar4 = EC_GROUP_get_degree(param_1);
      *(int *)pAVar6 = iVar4;
      pEVar3 = EC_GROUP_method_of(param_1);
      iVar4 = EC_METHOD_get_field_type(pEVar3);
      if ((iVar4 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) {
        iVar4 = 0;
        pEVar13 = param_1;
        do {
          iVar4 = iVar4 + 1;
          pEVar1 = pEVar13 + 0x60;
          pEVar13 = pEVar13 + 4;
        } while (*(int *)pEVar1 != 0);
        if (iVar4 == 4) {
          pAVar5 = OBJ_nid2obj(0x2ab);
          *(ASN1_OBJECT **)(pAVar6 + 4) = pAVar5;
          if (pAVar5 == (ASN1_OBJECT *)0x0) {
LAB_000f56a6:
            iVar12 = 0x179;
            goto LAB_000f56aa;
          }
          pEVar3 = EC_GROUP_method_of(param_1);
          iVar4 = EC_METHOD_get_field_type(pEVar3);
          if (((((iVar4 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
               (iVar4 = *(int *)(param_1 + 0x60), iVar4 != 0)) &&
              ((iVar12 = *(int *)(param_1 + 100), iVar12 != 0 &&
               (iVar11 = *(int *)(param_1 + 0x68), iVar11 != 0)))) &&
             (*(int *)(param_1 + 0x6c) == 0)) {
            pAVar10 = ASN1_item_new((ASN1_ITEM *)X9_62_PENTANOMIAL_it);
            *(ASN1_VALUE **)(pAVar6 + 8) = pAVar10;
            if (pAVar10 != (ASN1_VALUE *)0x0) {
              *(int *)pAVar10 = iVar11;
              *(int *)(pAVar10 + 4) = iVar12;
              *(int *)(pAVar10 + 8) = iVar4;
              goto LAB_000f5434;
            }
            iVar4 = 0x194;
            goto LAB_000f5640;
          }
          ERR_put_error(0x10,0xc1,0x42,"ec_asn1.c",0x77);
        }
        else {
          if (iVar4 != 2) goto LAB_000f530c;
          pAVar5 = OBJ_nid2obj(0x2aa);
          *(ASN1_OBJECT **)(pAVar6 + 4) = pAVar5;
          if (pAVar5 == (ASN1_OBJECT *)0x0) goto LAB_000f56a6;
          pEVar3 = EC_GROUP_method_of(param_1);
          iVar4 = EC_METHOD_get_field_type(pEVar3);
          if (((iVar4 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
             ((iVar4 = *(int *)(param_1 + 0x60), iVar4 != 0 && (*(int *)(param_1 + 100) == 0)))) {
            pAVar7 = ASN1_INTEGER_new();
            *(ASN1_INTEGER **)(pAVar6 + 8) = pAVar7;
            if (pAVar7 == (ASN1_INTEGER *)0x0) {
              iVar4 = 0x185;
              goto LAB_000f5640;
            }
            iVar4 = ASN1_INTEGER_set(pAVar7,iVar4);
            if (iVar4 != 0) goto LAB_000f5434;
            ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x189);
          }
          else {
            ERR_put_error(0x10,0xc2,0x42,"ec_asn1.c",0x61);
          }
        }
      }
      else {
LAB_000f530c:
        ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x174);
      }
    }
LAB_000f531e:
    iVar4 = 0x23b;
LAB_000f5322:
    puVar15 = (uchar *)0x0;
    ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",iVar4);
  }
  ASN1_item_free(val,(ASN1_ITEM *)&ECPARAMETERS_it);
  val = (ASN1_VALUE *)0x0;
LAB_000f533c:
  BN_free(order);
  if (puVar15 != (uchar *)0x0) {
    CRYPTO_free(puVar15);
  }
  return val;
}

