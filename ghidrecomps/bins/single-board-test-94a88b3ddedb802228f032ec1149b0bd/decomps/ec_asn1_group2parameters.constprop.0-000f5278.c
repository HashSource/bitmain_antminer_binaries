
undefined4 * ec_asn1_group2parameters_constprop_0(EC_GROUP *param_1)

{
  bool bVar1;
  BIGNUM *order;
  undefined4 *val;
  EC_METHOD *pEVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  char *pcVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_INTEGER *pAVar7;
  BIGNUM *pBVar8;
  BIGNUM *b;
  EC_POINT *p;
  point_conversion_form_t form;
  size_t len;
  size_t sVar9;
  ASN1_STRING *str;
  uchar *to;
  int *piVar10;
  void *data;
  int iVar11;
  int iVar12;
  EC_GROUP *pEVar13;
  ASN1_OBJECT **ppAVar14;
  uchar *puVar15;
  ASN1_STRING **ppAVar16;
  ASN1_BIT_STRING *str_00;
  uchar *puVar17;
  uchar *data_00;
  int local_34;
  uchar local_30 [12];
  
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,DAT_000f56bc,0x22a);
    return (undefined4 *)0x0;
  }
  val = (undefined4 *)ASN1_item_new(DAT_000f53dc);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,DAT_000f56bc,0x230);
    puVar15 = (uchar *)0x0;
    goto LAB_000f533c;
  }
  ppAVar14 = (ASN1_OBJECT **)val[1];
  *val = 1;
  if (ppAVar14 == (ASN1_OBJECT **)0x0 || param_1 == (EC_GROUP *)0x0) goto LAB_000f531e;
  if (*ppAVar14 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(*ppAVar14);
  }
  if (ppAVar14[1] != (ASN1_OBJECT *)0x0) {
    ASN1_TYPE_free((ASN1_TYPE *)ppAVar14[1]);
  }
  pEVar2 = EC_GROUP_method_of(param_1);
  iVar3 = EC_METHOD_get_field_type(pEVar2);
  pAVar4 = OBJ_nid2obj(iVar3);
  iVar12 = 0x148;
  *ppAVar14 = pAVar4;
  if (pAVar4 == (ASN1_OBJECT *)0x0) {
LAB_000f56aa:
    ERR_put_error(0x10,0x9a,8,DAT_000f56bc,iVar12);
    goto LAB_000f531e;
  }
  if (iVar3 == 0x196) {
    pBVar8 = BN_new();
    iVar3 = 0x14e;
    if (pBVar8 == (BIGNUM *)0x0) goto LAB_000f5640;
    iVar3 = EC_GROUP_get_curve_GFp(param_1,pBVar8,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
    if (iVar3 == 0) {
      ERR_put_error(0x10,0x9a,0x10,DAT_000f56bc,0x153);
      bVar1 = false;
    }
    else {
      pAVar4 = (ASN1_OBJECT *)BN_to_ASN1_INTEGER(pBVar8,(ASN1_INTEGER *)0x0);
      ppAVar14[1] = pAVar4;
      bVar1 = true;
      if (pAVar4 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x10,0x9a,0xd,DAT_000f56bc,0x159);
        bVar1 = false;
      }
    }
    BN_free(pBVar8);
    if (!bVar1) goto LAB_000f531e;
LAB_000f5434:
    ppAVar16 = (ASN1_STRING **)val[2];
    local_30[0] = '\0';
    if (((ppAVar16 == (ASN1_STRING **)0x0) || (*ppAVar16 == (ASN1_STRING *)0x0)) ||
       (ppAVar16[1] == (ASN1_STRING *)0x0)) {
LAB_000f55a8:
      iVar3 = 0x241;
      goto LAB_000f5322;
    }
    pBVar8 = BN_new();
    if ((pBVar8 == (BIGNUM *)0x0) || (b = BN_new(), b == (BIGNUM *)0x0)) {
      b = (BIGNUM *)0x0;
      ERR_put_error(0x10,0x99,0x41,DAT_000f56bc,0x1bc);
LAB_000f55c4:
      if (pBVar8 != (BIGNUM *)0x0) {
        bVar1 = false;
        goto LAB_000f5548;
      }
      bVar1 = false;
    }
    else {
      pEVar2 = EC_GROUP_method_of(param_1);
      iVar3 = EC_METHOD_get_field_type(pEVar2);
      if (iVar3 == 0x196) {
        iVar3 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,pBVar8,b,(BN_CTX *)0x0);
        iVar12 = 0x1c5;
        if (iVar3 == 0) goto LAB_000f582c;
      }
      else {
        iVar3 = EC_GROUP_get_curve_GF2m();
        if (iVar3 == 0) {
          iVar12 = 0x1cd;
LAB_000f582c:
          ERR_put_error(0x10,0x99,0x10,DAT_000f5940,iVar12);
          goto LAB_000f55c4;
        }
      }
      iVar12 = BN_num_bits(pBVar8);
      iVar3 = iVar12 + 0xe;
      if (-1 < iVar12 + 7) {
        iVar3 = iVar12 + 7;
      }
      puVar15 = (uchar *)(iVar3 >> 3);
      iVar12 = BN_num_bits(b);
      iVar3 = iVar12 + 0xe;
      if (-1 < iVar12 + 7) {
        iVar3 = iVar12 + 7;
      }
      iVar12 = 1;
      data_00 = local_30;
      if (puVar15 == (uchar *)0x0) {
LAB_000f54cc:
        if (iVar3 >> 3 == 0) {
          to = local_30;
          local_34 = 1;
          puVar17 = (uchar *)0x0;
LAB_000f54dc:
          iVar3 = ASN1_STRING_set(*ppAVar16,data_00,iVar12);
          if ((iVar3 == 0) || (iVar3 = ASN1_STRING_set(ppAVar16[1],to,local_34), iVar3 == 0)) {
            ERR_put_error(0x10,0x99,0xd,DAT_000f5940,0x1f8);
joined_r0x000f5804:
            bVar1 = false;
          }
          else {
            data = *(void **)(param_1 + 0x3c);
            if (data == (void *)0x0) {
              bVar1 = true;
              if (ppAVar16[2] != (ASN1_BIT_STRING *)0x0) {
                ASN1_BIT_STRING_free(ppAVar16[2]);
                ppAVar16[2] = (ASN1_STRING *)0x0;
                goto joined_r0x000f5804;
              }
            }
            else {
              str_00 = ppAVar16[2];
              if (str_00 == (ASN1_STRING *)0x0) {
                str_00 = ASN1_BIT_STRING_new();
                ppAVar16[2] = str_00;
                if (str_00 == (ASN1_BIT_STRING *)0x0) {
                  ERR_put_error(0x10,0x99,0x41,DAT_000f5940,0x200);
                  goto joined_r0x000f5804;
                }
                data = *(void **)(param_1 + 0x3c);
              }
              iVar3 = *(int *)(param_1 + 0x40);
              str_00->flags = str_00->flags & 0xfffffff0U | 8;
              iVar3 = ASN1_BIT_STRING_set(str_00,data,iVar3);
              if (iVar3 == 0) {
                ERR_put_error(0x10,0x99,0xd,DAT_000f5940,0x207);
                goto joined_r0x000f5804;
              }
            }
            bVar1 = true;
          }
        }
        else {
          to = (uchar *)CRYPTO_malloc(iVar3 >> 3,DAT_000f5940,0x1ea);
          puVar17 = to;
          if (to != (uchar *)0x0) {
            local_34 = BN_bn2bin(b,to);
            if (local_34 != 0) goto LAB_000f54dc;
            ERR_put_error(0x10,0x99,3,DAT_000f5940,0x1ef);
            goto joined_r0x000f5804;
          }
          ERR_put_error(0x10,0x99,0x41,DAT_000f5940,0x1eb);
          bVar1 = false;
        }
joined_r0x000f5804:
        if (puVar15 != (uchar *)0x0) goto LAB_000f57a6;
      }
      else {
        puVar15 = (uchar *)CRYPTO_malloc((int)puVar15,DAT_000f5940,0x1da);
        if (puVar15 == (uchar *)0x0) {
          ERR_put_error(0x10,0x99,0x41,DAT_000f5940,0x1db);
          goto LAB_000f55c4;
        }
        iVar12 = BN_bn2bin(pBVar8,puVar15);
        data_00 = puVar15;
        if (iVar12 != 0) goto LAB_000f54cc;
        ERR_put_error(0x10,0x99,3,DAT_000f5940,0x1df);
        bVar1 = false;
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
    if (!bVar1) goto LAB_000f55a8;
    p = EC_GROUP_get0_generator(param_1);
    if (p == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0x9b,0x71,DAT_000f5940,0x247);
      puVar15 = (uchar *)0x0;
    }
    else {
      form = EC_GROUP_get_point_conversion_form(param_1);
      len = EC_POINT_point2oct(param_1,p,form,(uchar *)0x0,0,(BN_CTX *)0x0);
      if (len == 0) {
        ERR_put_error(0x10,0x9b,0x10,DAT_000f56bc,0x24f);
        puVar15 = (uchar *)0x0;
      }
      else {
        puVar15 = (uchar *)CRYPTO_malloc(len,DAT_000f56bc,0x252);
        iVar3 = 0x253;
        if (puVar15 == (uchar *)0x0) {
LAB_000f57be:
          ERR_put_error(0x10,0x9b,0x41,DAT_000f5940,iVar3);
        }
        else {
          sVar9 = EC_POINT_point2oct(param_1,p,form,puVar15,len,(BN_CTX *)0x0);
          iVar3 = 599;
          if (sVar9 == 0) {
LAB_000f562c:
            ERR_put_error(0x10,0x9b,0x10,DAT_000f56bc,iVar3);
          }
          else {
            str = (ASN1_STRING *)val[3];
            if (str == (ASN1_STRING *)0x0) {
              str = ASN1_OCTET_STRING_new();
              val[3] = str;
              if (str == (ASN1_OCTET_STRING *)0x0) {
                iVar3 = 0x25b;
                goto LAB_000f57be;
              }
            }
            iVar3 = ASN1_OCTET_STRING_set(str,puVar15,len);
            iVar12 = 0x25f;
            if (iVar3 != 0) {
              iVar3 = EC_GROUP_get_order(param_1,order,(BN_CTX *)0x0);
              if (iVar3 == 0) {
                iVar3 = 0x265;
                goto LAB_000f562c;
              }
              pAVar7 = BN_to_ASN1_INTEGER(order,(ASN1_INTEGER *)val[4]);
              iVar12 = 0x26a;
              val[4] = pAVar7;
              if (pAVar7 != (ASN1_INTEGER *)0x0) {
                iVar3 = EC_GROUP_get_cofactor(param_1,order,(BN_CTX *)0x0);
                if (iVar3 == 0) goto LAB_000f533c;
                pAVar7 = BN_to_ASN1_INTEGER(order,(ASN1_INTEGER *)val[5]);
                val[5] = pAVar7;
                if (pAVar7 != (ASN1_INTEGER *)0x0) goto LAB_000f533c;
                iVar12 = 0x272;
              }
            }
            ERR_put_error(0x10,0x9b,0xd,DAT_000f5940,iVar12);
          }
        }
      }
    }
  }
  else {
    pAVar4 = (ASN1_OBJECT *)ASN1_item_new(DAT_000f53e0);
    iVar3 = 0x16b;
    ppAVar14[1] = pAVar4;
    if (pAVar4 == (ASN1_OBJECT *)0x0) {
LAB_000f5640:
      ERR_put_error(0x10,0x9a,0x41,DAT_000f56bc,iVar3);
    }
    else {
      pcVar5 = (char *)EC_GROUP_get_degree(param_1);
      pAVar4->sn = pcVar5;
      pEVar2 = EC_GROUP_method_of(param_1);
      iVar3 = EC_METHOD_get_field_type(pEVar2);
      if ((iVar3 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) {
        iVar3 = 0;
        pEVar13 = param_1;
        do {
          iVar3 = iVar3 + 1;
          piVar10 = (int *)(pEVar13 + 0x60);
          pEVar13 = pEVar13 + 4;
        } while (*piVar10 != 0);
        if (iVar3 == 4) {
          pAVar6 = OBJ_nid2obj(0x2ab);
          pAVar4->ln = &pAVar6->sn;
          if (pAVar6 == (ASN1_OBJECT *)0x0) {
LAB_000f56a6:
            iVar12 = 0x179;
            goto LAB_000f56aa;
          }
          pEVar2 = EC_GROUP_method_of(param_1);
          iVar3 = EC_METHOD_get_field_type(pEVar2);
          if (((((iVar3 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
               (iVar3 = *(int *)(param_1 + 0x60), iVar3 != 0)) &&
              ((iVar12 = *(int *)(param_1 + 100), iVar12 != 0 &&
               (iVar11 = *(int *)(param_1 + 0x68), iVar11 != 0)))) &&
             (*(int *)(param_1 + 0x6c) == 0)) {
            piVar10 = (int *)ASN1_item_new(DAT_000f5944);
            pAVar4->nid = (int)piVar10;
            if (piVar10 != (int *)0x0) {
              *piVar10 = iVar11;
              piVar10[1] = iVar12;
              piVar10[2] = iVar3;
              goto LAB_000f5434;
            }
            iVar3 = 0x194;
            goto LAB_000f5640;
          }
          ERR_put_error(0x10,0xc1,0x42,DAT_000f5940,0x77);
        }
        else {
          if (iVar3 != 2) goto LAB_000f530c;
          pAVar6 = OBJ_nid2obj(0x2aa);
          pAVar4->ln = &pAVar6->sn;
          if (pAVar6 == (ASN1_OBJECT *)0x0) goto LAB_000f56a6;
          pEVar2 = EC_GROUP_method_of(param_1);
          iVar3 = EC_METHOD_get_field_type(pEVar2);
          if (((iVar3 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
             ((iVar3 = *(int *)(param_1 + 0x60), iVar3 != 0 && (*(int *)(param_1 + 100) == 0)))) {
            pAVar7 = ASN1_INTEGER_new();
            pAVar4->nid = (int)pAVar7;
            if (pAVar7 == (ASN1_INTEGER *)0x0) {
              iVar3 = 0x185;
              goto LAB_000f5640;
            }
            iVar3 = ASN1_INTEGER_set(pAVar7,iVar3);
            if (iVar3 != 0) goto LAB_000f5434;
            ERR_put_error(0x10,0x9a,0xd,DAT_000f53e4,0x189);
          }
          else {
            ERR_put_error(0x10,0xc2,0x42,DAT_000f5940,0x61);
          }
        }
      }
      else {
LAB_000f530c:
        ERR_put_error(0x10,0x9a,0x10,DAT_000f53e4,0x174);
      }
    }
LAB_000f531e:
    iVar3 = 0x23b;
LAB_000f5322:
    puVar15 = (uchar *)0x0;
    ERR_put_error(0x10,0x9b,0x10,DAT_000f53e4,iVar3);
  }
  ASN1_item_free((ASN1_VALUE *)val,DAT_000f53dc);
  val = (undefined4 *)0x0;
LAB_000f533c:
  BN_free(order);
  if (puVar15 != (uchar *)0x0) {
    CRYPTO_free(puVar15);
  }
  return val;
}

