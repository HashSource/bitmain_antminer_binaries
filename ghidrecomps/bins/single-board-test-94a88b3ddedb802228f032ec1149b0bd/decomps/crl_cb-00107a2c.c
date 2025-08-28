
int crl_cb(int param_1,undefined4 *param_2)

{
  X509_CRL_METHOD *pXVar1;
  int iVar2;
  EVP_MD *type;
  ISSUING_DIST_POINT *pIVar3;
  AUTHORITY_KEYID *pAVar4;
  ASN1_INTEGER *pAVar5;
  int iVar6;
  X509_REVOKED *x;
  stack_st_GENERAL_NAME *data;
  _STACK *p_Var7;
  ASN1_ENUMERATED *a;
  long lVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ASN1_BIT_STRING *pAVar15;
  uint extraout_r3;
  X509_CRL *data_00;
  _STACK *p_Var16;
  stack_st_GENERAL_NAME *psVar17;
  bool bVar18;
  int local_2c [2];
  
  data_00 = (X509_CRL *)*param_2;
  if (param_1 == 3) {
    if ((*(code **)(data_00->meth + 8) == (code *)0x0) ||
       (iVar2 = (**(code **)(data_00->meth + 8))(data_00), iVar2 != 0)) {
      if (data_00->akid != (AUTHORITY_KEYID *)0x0) {
        AUTHORITY_KEYID_free(data_00->akid);
      }
      if (data_00->idp != (ISSUING_DIST_POINT *)0x0) {
        ISSUING_DIST_POINT_free(data_00->idp);
      }
      ASN1_INTEGER_free(data_00->crl_number);
      ASN1_INTEGER_free(data_00->base_crl_number);
      sk_pop_free(&data_00->issuers->stack,(func *)0xc8851);
      iVar2 = 1;
    }
  }
  else {
    if (param_1 == 5) {
      type = EVP_sha1();
      X509_CRL_digest(data_00,type,data_00->sha1_hash,(uint *)0x0);
      pIVar3 = (ISSUING_DIST_POINT *)X509_CRL_get_ext_d2i(data_00,0x302,(int *)0x0,(int *)0x0);
      data_00->idp = pIVar3;
      if (pIVar3 != (ISSUING_DIST_POINT *)0x0) {
        uVar11 = pIVar3->onlyuser;
        uVar14 = data_00->idp_flags;
        uVar12 = uVar11;
        if (0 < (int)uVar11) {
          uVar12 = uVar14 | 5;
        }
        data_00->idp_flags = uVar14 | 1;
        if (0 < (int)uVar11) {
          uVar14 = 2;
        }
        if ((int)uVar11 < 1) {
          uVar14 = 1;
        }
        else {
          data_00->idp_flags = uVar12;
        }
        uVar13 = pIVar3->onlyCA;
        uVar12 = (uint)(0 < (int)uVar11);
        uVar11 = uVar13;
        if (0 < (int)uVar13) {
          uVar11 = data_00->idp_flags | 8;
          uVar12 = uVar14;
        }
        if (0 < (int)uVar13) {
          data_00->idp_flags = uVar11;
        }
        uVar14 = pIVar3->onlyattr;
        uVar11 = uVar14;
        if (0 < (int)uVar14) {
          uVar12 = uVar12 + 1;
          uVar11 = data_00->idp_flags | 0x10;
        }
        if (0 < (int)uVar14) {
          data_00->idp_flags = uVar11;
        }
        uVar11 = uVar12;
        if (1 < (int)uVar12) {
          uVar11 = data_00->idp_flags | 2;
        }
        if (1 < (int)uVar12) {
          data_00->idp_flags = uVar11;
        }
        uVar11 = pIVar3->indirectCRL;
        uVar12 = uVar11;
        if (0 < (int)uVar11) {
          uVar12 = data_00->idp_flags | 0x20;
        }
        if (0 < (int)uVar11) {
          data_00->idp_flags = uVar12;
        }
        pAVar15 = pIVar3->onlysomereasons;
        if (pAVar15 != (ASN1_BIT_STRING *)0x0) {
          uVar12 = pAVar15->length;
          if ((int)uVar12 < 1) {
            pAVar15 = (ASN1_BIT_STRING *)data_00->idp_reasons;
          }
          data_00->idp_flags = data_00->idp_flags | 0x40;
          if (0 < (int)uVar12) {
            pbVar10 = pAVar15->data;
            bVar18 = uVar12 != 1;
            pAVar15 = (ASN1_BIT_STRING *)(uint)*pbVar10;
            data_00->idp_reasons = (int)pAVar15;
            if (bVar18) {
              uVar12 = (uint)pbVar10[1];
            }
            if (bVar18) {
              pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar15 | uVar12 << 8);
            }
          }
          data_00->idp_reasons = (uint)pAVar15 & 0x807f;
        }
        DIST_POINT_set_dpname(pIVar3->distpoint,data_00->crl->issuer);
      }
      pAVar4 = (AUTHORITY_KEYID *)X509_CRL_get_ext_d2i(data_00,0x5a,(int *)0x0,(int *)0x0);
      data_00->akid = pAVar4;
      pAVar5 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data_00,0x58,(int *)0x0,(int *)0x0);
      data_00->crl_number = pAVar5;
      pAVar5 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data_00,0x8c,(int *)0x0,(int *)0x0);
      data_00->base_crl_number = pAVar5;
      if ((pAVar5 != (ASN1_INTEGER *)0x0) && (data_00->crl_number == (ASN1_INTEGER *)0x0)) {
        data_00->flags = data_00->flags | 0x80;
      }
      p_Var16 = &data_00->crl->extensions->stack;
      iVar2 = 0;
      do {
        iVar6 = sk_num(p_Var16);
        if (iVar6 <= iVar2) goto LAB_00107b94;
        puVar9 = (undefined4 *)sk_value(p_Var16,iVar2);
        iVar6 = OBJ_obj2nid((ASN1_OBJECT *)*puVar9);
        uVar12 = extraout_r3;
        if (iVar6 == 0x359) {
          uVar12 = data_00->flags | 0x1000;
        }
        if (iVar6 == 0x359) {
          data_00->flags = uVar12;
        }
        iVar2 = iVar2 + 1;
      } while ((int)puVar9[1] < 1);
      if ((iVar6 != 0x302 && iVar6 != 0x5a) && (iVar6 != 0x8c)) {
        data_00->flags = data_00->flags | 0x200;
      }
LAB_00107b94:
      psVar17 = (stack_st_GENERAL_NAME *)0x0;
      p_Var16 = &data_00->crl->revoked->stack;
      for (iVar2 = 0; iVar6 = sk_num(p_Var16), iVar2 < iVar6; iVar2 = iVar2 + 1) {
        x = (X509_REVOKED *)sk_value(p_Var16,iVar2);
        data = (stack_st_GENERAL_NAME *)X509_REVOKED_get_ext_d2i(x,0x303,local_2c,(int *)0x0);
        if (data == (stack_st_GENERAL_NAME *)0x0) {
          if (local_2c[0] == -1) goto LAB_00107bf2;
LAB_00107c92:
          data_00->flags = data_00->flags | 0x80;
          break;
        }
        p_Var7 = &data_00->issuers->stack;
        if (p_Var7 == (_STACK *)0x0) {
          p_Var7 = sk_new_null();
          data_00->issuers = (stack_st_GENERAL_NAMES *)p_Var7;
          if (p_Var7 == (_STACK *)0x0) {
            return 0;
          }
        }
        iVar6 = sk_push(p_Var7,data);
        psVar17 = data;
        if (iVar6 == 0) {
          return 0;
        }
LAB_00107bf2:
        x->issuer = psVar17;
        a = (ASN1_ENUMERATED *)X509_REVOKED_get_ext_d2i(x,0x8d,local_2c,(int *)0x0);
        if (a == (ASN1_ENUMERATED *)0x0) {
          if (local_2c[0] != -1) goto LAB_00107c92;
          x->reason = -1;
        }
        else {
          lVar8 = ASN1_ENUMERATED_get(a);
          x->reason = lVar8;
          ASN1_ENUMERATED_free(a);
        }
        p_Var7 = &x->extensions->stack;
        local_2c[0] = 0;
        while (iVar6 = sk_num(p_Var7), local_2c[0] < iVar6) {
          puVar9 = (undefined4 *)sk_value(p_Var7,local_2c[0]);
          if ((0 < (int)puVar9[1]) && (iVar6 = OBJ_obj2nid((ASN1_OBJECT *)*puVar9), iVar6 != 0x303))
          {
            data_00->flags = data_00->flags | 0x200;
            break;
          }
          local_2c[0] = local_2c[0] + 1;
        }
      }
      if (*(code **)(data_00->meth + 4) != (code *)0x0) {
        iVar2 = (**(code **)(data_00->meth + 4))(data_00);
        if (iVar2 != 0) {
          return 1;
        }
        return 0;
      }
    }
    else if (param_1 == 1) {
      data_00->idp = (ISSUING_DIST_POINT *)0x0;
      data_00->akid = (AUTHORITY_KEYID *)0x0;
      pXVar1 = default_crl_method;
      data_00->flags = 0;
      data_00->idp_flags = 0;
      data_00->meth = pXVar1;
      data_00->meth_data = (void *)0x0;
      data_00->issuers = (stack_st_GENERAL_NAMES *)0x0;
      data_00->crl_number = (ASN1_INTEGER *)0x0;
      data_00->base_crl_number = (ASN1_INTEGER *)0x0;
      data_00->idp_reasons = 0x807f;
      return 1;
    }
    iVar2 = 1;
  }
  return iVar2;
}

