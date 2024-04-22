
/* WARNING: Type propagation algorithm not settling */

undefined4
rsa_pkey_ctrl(undefined4 param_1,undefined4 param_2,ASN1_STRING *param_3,PKCS7_SIGNER_INFO *param_4)

{
  EVP_PKEY_CTX *pEVar1;
  int iVar2;
  undefined4 *puVar3;
  X509_ALGOR *pXVar4;
  char *pcVar5;
  EVP_MD *p2;
  EVP_MD *p2_00;
  void *pval;
  X509_ALGOR **obj;
  int iVar6;
  ASN1_OCTET_STRING *str;
  ASN1_OBJECT *pAVar7;
  ASN1_STRING *pAVar8;
  int *piVar9;
  char **ppcVar10;
  undefined4 uVar11;
  ASN1_OBJECT **ppAVar12;
  char *p2_01;
  X509_ALGOR *local_44;
  EVP_MD *local_40;
  undefined4 local_3c;
  int local_38;
  ASN1_STRING *local_34;
  X509_ALGOR *local_30;
  X509_ALGOR *local_2c [2];
  
  local_44 = (X509_ALGOR *)0x0;
  switch(param_2) {
  case 1:
    if (param_3 != (ASN1_STRING *)0x0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)0x0,&local_44);
    break;
  case 2:
    if (param_3 != (ASN1_STRING *)0x0) {
      return 1;
    }
    PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,&local_44);
    break;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x2a0;
    return 1;
  default:
    return 0xfffffffe;
  case 5:
    if (param_3 != (ASN1_STRING *)0x0) {
      if (param_3 != (ASN1_STRING *)0x1) {
        return 1;
      }
      uVar11 = CMS_SignerInfo_get0_pkey_ctx(param_4);
      CMS_SignerInfo_get0_algs
                ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,local_2c
                );
      iVar2 = OBJ_obj2nid(local_2c[0]->algorithm);
      if (iVar2 == 6) {
        return 1;
      }
      if (iVar2 == 0x390) {
        uVar11 = rsa_pss_to_ctx(0,uVar11,local_2c[0],0);
        return uVar11;
      }
      iVar2 = OBJ_find_sigid_algs(iVar2,(int *)0x0,&local_38);
      if (iVar2 != 0) {
        if (local_38 == 6) {
          return 1;
        }
        return 0;
      }
      return 0;
    }
    local_38 = 1;
    pEVar1 = (EVP_PKEY_CTX *)CMS_SignerInfo_get0_pkey_ctx(param_4);
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,local_2c);
    if ((pEVar1 != (EVP_PKEY_CTX *)0x0) &&
       (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,-1,0x1006,0,&local_38), iVar2 < 1)) {
      return 0;
    }
    pXVar4 = local_2c[0];
    if (local_38 != 1) {
      if (local_38 != 6) {
        return 0;
      }
      pval = (void *)rsa_ctx_to_pss(pEVar1);
      if (pval != (void *)0x0) {
        pAVar7 = OBJ_nid2obj(0x390);
        X509_ALGOR_set0(local_2c[0],pAVar7,0x10,pval);
        return 1;
      }
      return 0;
    }
    goto LAB_000fd1d2;
  case 7:
    if (param_3 != (ASN1_STRING *)0x0) {
      if (param_3 != (ASN1_STRING *)0x1) {
        return 1;
      }
      pEVar1 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
      if (pEVar1 == (EVP_PKEY_CTX *)0x0) {
        return 0;
      }
      iVar2 = CMS_RecipientInfo_ktri_get0_algs
                        ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,
                         (X509_ALGOR **)&local_34);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)local_34->length);
      if (iVar2 == 6) {
        return 1;
      }
      if (iVar2 != 0x397) {
        ERR_put_error(4,0x9e,0xa4,DAT_000fd640,0x328);
        return 0xffffffff;
      }
      piVar9 = (int *)local_34->type;
      if ((piVar9 == (int *)0x0) || (*piVar9 != 0x10)) {
LAB_000fd520:
        ERR_put_error(4,0x9e,0xa2,DAT_000fd640,0x32f);
        RSA_OAEP_PARAMS_free(0);
        return 0xffffffff;
      }
      local_30 = (X509_ALGOR *)((undefined4 *)piVar9[1])[2];
      puVar3 = (undefined4 *)d2i_RSA_OAEP_PARAMS(0,&local_30,*(undefined4 *)piVar9[1]);
      if (puVar3 == (undefined4 *)0x0) goto LAB_000fd520;
      ppAVar12 = (ASN1_OBJECT **)puVar3[1];
      if (ppAVar12 == (ASN1_OBJECT **)0x0) {
LAB_000fd556:
        pXVar4 = (X509_ALGOR *)0x0;
      }
      else {
        iVar2 = OBJ_obj2nid(*ppAVar12);
        if ((iVar2 != 0x38f) || (ppAVar12[1]->sn != (char *)0x10)) {
          ppAVar12 = (ASN1_OBJECT **)puVar3[1];
          goto LAB_000fd556;
        }
        ppcVar10 = ppAVar12[1]->ln;
        local_2c[0] = (X509_ALGOR *)ppcVar10[2];
        pXVar4 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)local_2c,(long)*ppcVar10);
        ppAVar12 = (ASN1_OBJECT **)puVar3[1];
      }
      if (ppAVar12 == (ASN1_OBJECT **)0x0) {
        p2 = EVP_sha1();
        if (p2 != (EVP_MD *)0x0) {
LAB_000fd318:
          if ((ASN1_OBJECT **)*puVar3 == (ASN1_OBJECT **)0x0) {
            p2_00 = EVP_sha1();
            if (p2_00 == (EVP_MD *)0x0) goto LAB_000fd5fa;
          }
          else {
            iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)*puVar3);
            pcVar5 = OBJ_nid2sn(iVar2);
            p2_00 = EVP_get_digestbyname(pcVar5);
            if (p2_00 == (EVP_MD *)0x0) {
              ERR_put_error(4,0x9d,0xa3,DAT_000fd6dc,499);
              uVar11 = 0xffffffff;
              goto LAB_000fd36a;
            }
          }
          ppAVar12 = (ASN1_OBJECT **)puVar3[2];
          if (ppAVar12 == (ASN1_OBJECT **)0x0) {
            pcVar5 = (char *)0x0;
            p2_01 = (char *)0x0;
          }
          else {
            iVar2 = OBJ_obj2nid(*ppAVar12);
            if (iVar2 != 0x3a7) {
              uVar11 = 0xffffffff;
              ERR_put_error(4,0x9e,0xa5,DAT_000fd640,0x33d);
              goto LAB_000fd36a;
            }
            if (ppAVar12[1]->sn != (char *)0x4) {
              ERR_put_error(4,0x9e,0xa1,DAT_000fd640,0x341);
              goto LAB_000fd5fa;
            }
            ppcVar10 = ppAVar12[1]->ln;
            pcVar5 = *ppcVar10;
            p2_01 = ppcVar10[2];
            ppcVar10[2] = (char *)0x0;
          }
          iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,-1,0x1001,4,(void *)0x0);
          if ((((0 < iVar2) && (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x300,0x1009,0,p2_00), 0 < iVar2)
               ) && (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x3f8,0x1005,0,p2), 0 < iVar2)) &&
             (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x300,0x100a,(int)pcVar5,p2_01), 0 < iVar2)) {
            uVar11 = 1;
            goto LAB_000fd36a;
          }
        }
      }
      else {
        iVar2 = OBJ_obj2nid(*ppAVar12);
        if (iVar2 == 0x38f) {
          if (pXVar4 == (X509_ALGOR *)0x0) {
            ERR_put_error(4,0x9f,0x9a,DAT_000fd6dc,0x203);
          }
          else {
            iVar2 = OBJ_obj2nid(pXVar4->algorithm);
            pcVar5 = OBJ_nid2sn(iVar2);
            p2 = EVP_get_digestbyname(pcVar5);
            if (p2 != (EVP_MD *)0x0) goto LAB_000fd318;
            ERR_put_error(4,0x9f,0x97,DAT_000fd6dc,0x208);
          }
        }
        else {
          ERR_put_error(4,0x9f,0x99,DAT_000fd640,0x1ff);
        }
      }
LAB_000fd5fa:
      uVar11 = 0xffffffff;
LAB_000fd36a:
      RSA_OAEP_PARAMS_free(puVar3);
      if (pXVar4 == (X509_ALGOR *)0x0) {
        return uVar11;
      }
      X509_ALGOR_free(pXVar4);
      return uVar11;
    }
    local_34 = param_3;
    pEVar1 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
    local_38 = 1;
    CMS_RecipientInfo_ktri_get0_algs
              ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_30);
    if ((pEVar1 != (EVP_PKEY_CTX *)0x0) &&
       (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,-1,0x1006,0,&local_38), iVar2 < 1)) {
      return 0;
    }
    pXVar4 = local_30;
    if (local_38 == 1) goto LAB_000fd1d2;
    if (local_38 != 4) {
      return 0;
    }
    iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x300,0x100b,0,&local_40);
    if (((iVar2 < 1) || (iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x3f8,0x1008,0,&local_3c), iVar2 < 1))
       || ((iVar2 = EVP_PKEY_CTX_ctrl(pEVar1,6,0x300,0x100c,0,local_2c), iVar2 < 0 ||
           (obj = (X509_ALGOR **)RSA_OAEP_PARAMS_new(), obj == (X509_ALGOR **)0x0)))) {
      uVar11 = 0;
      goto LAB_000fd508;
    }
    iVar6 = EVP_MD_type(local_40);
    if (iVar6 == 0x40) {
LAB_000fd4be:
      iVar6 = rsa_md_to_mgf1(obj + 1,local_3c);
      if (iVar6 == 0) goto LAB_000fd654;
      if (iVar2 == 0) {
LAB_000fd6ae:
        pAVar8 = ASN1_item_pack(obj,DAT_000fd6e0,&local_34);
        if (pAVar8 == (ASN1_STRING *)0x0) goto LAB_000fd654;
        pAVar7 = OBJ_nid2obj(0x397);
        X509_ALGOR_set0(local_30,pAVar7,0x10,local_34);
        uVar11 = 1;
        local_34 = (ASN1_STRING *)0x0;
      }
      else {
        str = ASN1_OCTET_STRING_new();
        pXVar4 = X509_ALGOR_new();
        obj[2] = pXVar4;
        if ((pXVar4 == (X509_ALGOR *)0x0) || (str == (ASN1_OCTET_STRING *)0x0)) goto LAB_000fd654;
        iVar2 = ASN1_OCTET_STRING_set(str,local_2c[0],iVar2);
        if (iVar2 != 0) {
          pXVar4 = obj[2];
          pAVar7 = OBJ_nid2obj(0x3a7);
          X509_ALGOR_set0(pXVar4,pAVar7,4,str);
          goto LAB_000fd6ae;
        }
        ASN1_OCTET_STRING_free(str);
        uVar11 = 0;
      }
    }
    else {
      pXVar4 = X509_ALGOR_new();
      *obj = pXVar4;
      if (pXVar4 != (X509_ALGOR *)0x0) {
        X509_ALGOR_set_md(pXVar4,local_40);
        goto LAB_000fd4be;
      }
LAB_000fd654:
      uVar11 = 0;
    }
    RSA_OAEP_PARAMS_free(obj);
LAB_000fd508:
    if (local_34 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(local_34);
      return uVar11;
    }
    return uVar11;
  case 8:
    param_4->version = (ASN1_INTEGER *)0x0;
    return 1;
  }
  pXVar4 = local_44;
  if (local_44 == (X509_ALGOR *)0x0) {
    return 1;
  }
LAB_000fd1d2:
  pAVar7 = OBJ_nid2obj(6);
  X509_ALGOR_set0(pXVar4,pAVar7,5,(void *)0x0);
  return 1;
}

