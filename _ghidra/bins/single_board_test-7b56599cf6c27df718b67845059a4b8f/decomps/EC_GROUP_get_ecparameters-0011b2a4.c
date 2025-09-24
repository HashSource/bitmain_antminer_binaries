
undefined4 * EC_GROUP_get_ecparameters(EC_GROUP *param_1,undefined4 *param_2)

{
  EC_METHOD *meth;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 *puVar3;
  int *piVar4;
  ASN1_NULL *pAVar5;
  BIGNUM *a;
  void *data;
  void *data_00;
  EC_POINT *pEVar6;
  point_conversion_form_t pVar7;
  ASN1_STRING *str;
  ASN1_INTEGER *pAVar8;
  void *data_01;
  uint num;
  undefined4 *puVar9;
  ASN1_INTEGER *pAVar10;
  BIGNUM *pBVar11;
  ASN1_BIT_STRING *str_00;
  void *local_38;
  undefined4 local_34;
  undefined4 local_30;
  long local_2c [2];
  
  local_38 = (void *)0x0;
  puVar3 = param_2;
  if ((param_2 == (undefined4 *)0x0) &&
     (puVar3 = (undefined4 *)ECPARAMETERS_new(), puVar3 == (undefined4 *)0x0)) {
    ERR_put_error(0x10,0x105,0x41,"crypto/ec/ec_asn1.c",0x1cb);
    goto LAB_0011b36c;
  }
  puVar9 = (undefined4 *)puVar3[1];
  *puVar3 = 1;
  if (puVar9 == (undefined4 *)0x0 || param_1 == (EC_GROUP *)0x0) {
LAB_0011b2d0:
    ERR_put_error(0x10,0x105,0x10,"crypto/ec/ec_asn1.c",0x1d6);
  }
  else {
    pBVar11 = (BIGNUM *)0x0;
    ASN1_OBJECT_free((ASN1_OBJECT *)*puVar9);
    ASN1_TYPE_free((ASN1_TYPE *)puVar9[1]);
    meth = EC_GROUP_method_of(param_1);
    iVar1 = EC_METHOD_get_field_type(meth);
    pAVar2 = OBJ_nid2obj(iVar1);
    *puVar9 = pAVar2;
    if (pAVar2 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0x10,0x9a,8,"crypto/ec/ec_asn1.c",0x109);
      pBVar11 = (BIGNUM *)0x0;
LAB_0011b342:
      BN_free(pBVar11);
      goto LAB_0011b2d0;
    }
    if (iVar1 != 0x196) {
      if (iVar1 == 0x197) {
        piVar4 = (int *)X9_62_CHARACTERISTIC_TWO_new();
        puVar9[1] = piVar4;
        if (piVar4 == (int *)0x0) {
          iVar1 = 300;
          pBVar11 = (BIGNUM *)0x0;
          goto LAB_0011b71c;
        }
        iVar1 = EC_GROUP_get_degree(param_1);
        *piVar4 = iVar1;
        iVar1 = EC_GROUP_get_basis_type(param_1);
        if (iVar1 == 0) {
          ERR_put_error(0x10,0x9a,0x10,"crypto/ec/ec_asn1.c",0x135);
          pBVar11 = (BIGNUM *)0x0;
        }
        else {
          pAVar2 = OBJ_nid2obj(iVar1);
          piVar4[1] = (int)pAVar2;
          if (pAVar2 == (ASN1_OBJECT *)0x0) {
            ERR_put_error(0x10,0x9a,8,"crypto/ec/ec_asn1.c",0x13a);
            pBVar11 = (BIGNUM *)0x0;
          }
          else {
            if (iVar1 == 0x2aa) {
              iVar1 = EC_GROUP_get_trinomial_basis(param_1,local_2c);
              if (iVar1 != 0) {
                pAVar8 = ASN1_INTEGER_new();
                piVar4[2] = (int)pAVar8;
                if (pAVar8 == (ASN1_INTEGER *)0x0) {
                  iVar1 = 0x146;
                  goto LAB_0011b7d4;
                }
                iVar1 = ASN1_INTEGER_set(pAVar8,local_2c[0]);
                if (iVar1 != 0) goto LAB_0011b3cc;
                ERR_put_error(0x10,0x9a,0xd,"crypto/ec/ec_asn1.c",0x14a);
              }
            }
            else {
              if (iVar1 == 0x2ab) {
                iVar1 = EC_GROUP_get_pentanomial_basis(param_1,&local_34,&local_30,local_2c);
                if (iVar1 == 0) goto LAB_0011b74e;
                puVar9 = (undefined4 *)X9_62_PENTANOMIAL_new();
                piVar4[2] = (int)puVar9;
                if (puVar9 != (undefined4 *)0x0) {
                  pBVar11 = (BIGNUM *)0x0;
                  *puVar9 = local_34;
                  puVar9[1] = local_30;
                  puVar9[2] = local_2c[0];
                  goto LAB_0011b3d0;
                }
                iVar1 = 0x155;
              }
              else {
                pAVar5 = ASN1_NULL_new();
                piVar4[2] = (int)pAVar5;
                if (pAVar5 != (ASN1_NULL *)0x0) {
LAB_0011b3cc:
                  pBVar11 = (BIGNUM *)0x0;
                  goto LAB_0011b3d0;
                }
                iVar1 = 0x162;
              }
LAB_0011b7d4:
              ERR_put_error(0x10,0x9a,0x41,"crypto/ec/ec_asn1.c",iVar1);
            }
LAB_0011b74e:
            pBVar11 = (BIGNUM *)0x0;
          }
        }
      }
      else {
        ERR_put_error(0x10,0x9a,0x83,"crypto/ec/ec_asn1.c",0x169);
      }
      goto LAB_0011b342;
    }
    pBVar11 = BN_new();
    if (pBVar11 == (BIGNUM *)0x0) {
      iVar1 = 0x10f;
LAB_0011b71c:
      ERR_put_error(0x10,0x9a,0x41,"crypto/ec/ec_asn1.c",iVar1);
      goto LAB_0011b342;
    }
    iVar1 = EC_GROUP_get_curve(param_1,pBVar11,0,0,0);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x9a,0x10,"crypto/ec/ec_asn1.c",0x114);
      goto LAB_0011b342;
    }
    pAVar8 = BN_to_ASN1_INTEGER(pBVar11,(ASN1_INTEGER *)0x0);
    puVar9[1] = pAVar8;
    if (pAVar8 == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x10,0x9a,0xd,"crypto/ec/ec_asn1.c",0x11a);
      goto LAB_0011b342;
    }
LAB_0011b3d0:
    BN_free(pBVar11);
    piVar4 = (int *)puVar3[2];
    if (((piVar4 == (int *)0x0) || (*piVar4 == 0)) || (piVar4[1] == 0)) {
LAB_0011b44e:
      ERR_put_error(0x10,0x105,0x10,"crypto/ec/ec_asn1.c",0x1dc);
    }
    else {
      pBVar11 = BN_new();
      if ((pBVar11 == (BIGNUM *)0x0) || (a = BN_new(), a == (BIGNUM *)0x0)) {
        data_00 = (void *)0x0;
        ERR_put_error(0x10,0x99,0x41,"crypto/ec/ec_asn1.c",0x17f);
        data = (void *)0x0;
        a = (BIGNUM *)0x0;
LAB_0011b424:
        CRYPTO_free(data);
        CRYPTO_free(data_00);
        BN_free(pBVar11);
        BN_free(a);
        goto LAB_0011b44e;
      }
      iVar1 = EC_GROUP_get_curve(param_1,0,pBVar11,a,0);
      if (iVar1 == 0) {
        ERR_put_error(0x10,0x99,0x10,"crypto/ec/ec_asn1.c",0x185);
        data_00 = (void *)0x0;
        data = (void *)0x0;
        goto LAB_0011b424;
      }
      iVar1 = EC_GROUP_get_degree(param_1);
      num = iVar1 + 7U >> 3;
      data = CRYPTO_malloc(num,"crypto/ec/ec_asn1.c",399);
      if ((data == (void *)0x0) ||
         (data_00 = CRYPTO_malloc(num,"crypto/ec/ec_asn1.c",400), data_00 == (void *)0x0)) {
        data_00 = (void *)0x0;
        ERR_put_error(0x10,0x99,0x41,"crypto/ec/ec_asn1.c",0x191);
        goto LAB_0011b424;
      }
      iVar1 = BN_bn2binpad(pBVar11,data,num);
      if ((iVar1 < 0) || (iVar1 = BN_bn2binpad(a,data_00,num), iVar1 < 0)) {
        ERR_put_error(0x10,0x99,3,"crypto/ec/ec_asn1.c",0x196);
        goto LAB_0011b424;
      }
      iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)*piVar4,data,num);
      if ((iVar1 == 0) ||
         (iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)piVar4[1],data_00,num), iVar1 == 0)) {
        iVar1 = 0x19d;
LAB_0011b732:
        ERR_put_error(0x10,0x99,0xd,"crypto/ec/ec_asn1.c",iVar1);
        goto LAB_0011b424;
      }
      data_01 = *(void **)(param_1 + 0x20);
      if (data_01 == (void *)0x0) {
        ASN1_BIT_STRING_free((ASN1_STRING *)piVar4[2]);
        piVar4[2] = 0;
      }
      else {
        str_00 = (ASN1_BIT_STRING *)piVar4[2];
        if (str_00 == (ASN1_STRING *)0x0) {
          str_00 = ASN1_BIT_STRING_new();
          piVar4[2] = (int)str_00;
          if (str_00 == (ASN1_BIT_STRING *)0x0) {
            ERR_put_error(0x10,0x99,0x41,"crypto/ec/ec_asn1.c",0x1a5);
            goto LAB_0011b424;
          }
          data_01 = *(void **)(param_1 + 0x20);
        }
        iVar1 = *(int *)(param_1 + 0x24);
        str_00->flags = str_00->flags & 0xfffffff0U | 8;
        iVar1 = ASN1_BIT_STRING_set(str_00,data_01,iVar1);
        if (iVar1 == 0) {
          iVar1 = 0x1ac;
          goto LAB_0011b732;
        }
      }
      CRYPTO_free(data);
      CRYPTO_free(data_00);
      BN_free(pBVar11);
      BN_free(a);
      pEVar6 = EC_GROUP_get0_generator(param_1);
      if (pEVar6 == (EC_POINT *)0x0) {
        ERR_put_error(0x10,0x105,0x71,"crypto/ec/ec_asn1.c",0x1e2);
      }
      else {
        pVar7 = EC_GROUP_get_point_conversion_form(param_1);
        iVar1 = EC_POINT_point2buf(param_1,pEVar6,pVar7,&local_38,0);
        if (iVar1 == 0) {
          ERR_put_error(0x10,0x105,0x10,"crypto/ec/ec_asn1.c",0x1ea);
        }
        else {
          str = (ASN1_STRING *)puVar3[3];
          if (str == (ASN1_STRING *)0x0) {
            str = ASN1_OCTET_STRING_new();
            puVar3[3] = str;
            if (str == (ASN1_OCTET_STRING *)0x0) {
              CRYPTO_free(local_38);
              ERR_put_error(0x10,0x105,0x41,"crypto/ec/ec_asn1.c",0x1ef);
              goto LAB_0011b2e8;
            }
          }
          ASN1_STRING_set0(str,local_38,iVar1);
          pBVar11 = (BIGNUM *)EC_GROUP_get0_order(param_1);
          if (pBVar11 == (BIGNUM *)0x0) {
            ERR_put_error(0x10,0x105,0x10,"crypto/ec/ec_asn1.c",0x1f7);
          }
          else {
            pAVar10 = (ASN1_INTEGER *)puVar3[4];
            pAVar8 = BN_to_ASN1_INTEGER(pBVar11,pAVar10);
            puVar3[4] = pAVar8;
            if (pAVar8 == (ASN1_INTEGER *)0x0) {
              iVar1 = 0x1fd;
              puVar3[4] = pAVar10;
            }
            else {
              pBVar11 = (BIGNUM *)EC_GROUP_get0_cofactor(param_1);
              if (pBVar11 == (BIGNUM *)0x0) {
                return puVar3;
              }
              pAVar10 = (ASN1_INTEGER *)puVar3[5];
              pAVar8 = BN_to_ASN1_INTEGER(pBVar11,pAVar10);
              puVar3[5] = pAVar8;
              if (pAVar8 != (ASN1_INTEGER *)0x0) {
                return puVar3;
              }
              iVar1 = 0x207;
              puVar3[5] = pAVar10;
            }
            ERR_put_error(0x10,0x105,0xd,"crypto/ec/ec_asn1.c",iVar1);
          }
        }
      }
    }
  }
LAB_0011b2e8:
  if (param_2 != (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_0011b36c:
  ECPARAMETERS_free(puVar3);
  return (undefined4 *)0x0;
}

