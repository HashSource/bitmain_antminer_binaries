
ASN1_OCTET_STRING *
rsa_pkey_ctrl(int param_1,undefined4 param_2,ASN1_STRING *param_3,PKCS7_SIGNER_INFO *param_4)

{
  ASN1_INTEGER *pAVar1;
  EVP_PKEY_CTX *pEVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  EVP_MD *pEVar6;
  EVP_MD *p2;
  RSA_PSS_PARAMS *a;
  ASN1_OBJECT *pAVar7;
  int *piVar8;
  ASN1_OCTET_STRING *pAVar9;
  RSA_PSS_PARAMS *a_00;
  undefined4 *puVar10;
  X509_ALGOR *pXVar11;
  void *pvVar12;
  int iVar13;
  EVP_MD *local_3c;
  EVP_MD *local_38;
  X509_ALGOR *local_34;
  ASN1_OCTET_STRING *local_30;
  EVP_MD *local_2c;
  EVP_MD *local_28;
  EVP_MD *local_24;
  
  local_3c = (EVP_MD *)0x0;
  switch(param_2) {
  case 1:
    if (param_3 != (ASN1_STRING *)0x0) {
      return (ASN1_OCTET_STRING *)0x1;
    }
    PKCS7_SIGNER_INFO_get0_algs
              (param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)0x0,(X509_ALGOR **)&local_3c);
    break;
  case 2:
    if (**(int **)(param_1 + 0xc) == 0x390) {
      return (ASN1_OCTET_STRING *)0xfffffffe;
    }
    if (param_3 != (ASN1_STRING *)0x0) {
      return (ASN1_OCTET_STRING *)0x1;
    }
    PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,(X509_ALGOR **)&local_3c);
    break;
  case 3:
    iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 0x34);
    if (iVar3 == 0) {
      param_4->version = (ASN1_INTEGER *)0x2a0;
      return (ASN1_OCTET_STRING *)0x1;
    }
    iVar3 = rsa_pss_get_param(iVar3,&local_2c,&local_28,&local_24);
    if (iVar3 == 0) {
      ERR_put_error(4,0,0x44,"crypto/rsa/rsa_ameth.c",0x203);
      return (ASN1_OCTET_STRING *)0x0;
    }
    pAVar1 = (ASN1_INTEGER *)EVP_MD_type(local_2c);
    param_4->version = pAVar1;
    return (ASN1_OCTET_STRING *)0x2;
  default:
    return (ASN1_OCTET_STRING *)0xfffffffe;
  case 5:
    if (param_3 == (ASN1_STRING *)0x0) {
      local_28 = (EVP_MD *)0x1;
      iVar3 = CMS_SignerInfo_get0_pkey_ctx(param_4);
      CMS_SignerInfo_get0_algs
                ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,
                 (X509_ALGOR **)&local_24);
      if ((iVar3 != 0) &&
         (iVar13 = RSA_pkey_ctx_ctrl(iVar3,0xffffffff,0x1006,0,&local_28), iVar13 < 1)) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      pEVar6 = local_24;
      if (local_28 != (EVP_MD *)0x1) {
        if (local_28 != (EVP_MD *)0x6) {
          return (ASN1_OCTET_STRING *)0x0;
        }
        pvVar12 = (void *)rsa_ctx_to_pss_string(iVar3);
        if (pvVar12 == (void *)0x0) {
          return (ASN1_OCTET_STRING *)0x0;
        }
        pAVar7 = OBJ_nid2obj(0x390);
        X509_ALGOR_set0((X509_ALGOR *)local_24,pAVar7,0x10,pvVar12);
        return (ASN1_OCTET_STRING *)0x1;
      }
      goto LAB_0014abd0;
    }
    if (param_3 != (ASN1_STRING *)0x1) {
      return (ASN1_OCTET_STRING *)0x1;
    }
    pEVar2 = (EVP_PKEY_CTX *)CMS_SignerInfo_get0_pkey_ctx(param_4);
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,&local_34)
    ;
    iVar3 = OBJ_obj2nid(local_34->algorithm);
    if (iVar3 != 0x390) {
      if (**(int **)pEVar2 == 0x390) {
        ERR_put_error(4,0x9e,0x90,"crypto/rsa/rsa_ameth.c",0x2fb);
        return (ASN1_OCTET_STRING *)0x0;
      }
      if (iVar3 == 6) {
        return (ASN1_OCTET_STRING *)0x1;
      }
      iVar3 = OBJ_find_sigid_algs(iVar3,(int *)0x0,(int *)&local_24);
      if (iVar3 == 0) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      if (local_24 != (EVP_MD *)&DAT_00000006) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      return (ASN1_OCTET_STRING *)0x1;
    }
    local_2c = (EVP_MD *)0x0;
    local_28 = (EVP_MD *)0x0;
    iVar3 = OBJ_obj2nid(local_34->algorithm);
    if (iVar3 != 0x390) {
      ERR_put_error(4,0x9b,0x9b,"crypto/rsa/rsa_ameth.c",0x2a4);
      return (ASN1_OCTET_STRING *)0xffffffff;
    }
    a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,local_34->parameter);
    a_00 = a;
    if ((a != (RSA_PSS_PARAMS *)0x0) &&
       (pXVar11 = a->maskGenAlgorithm, pXVar11 != (X509_ALGOR *)0x0)) {
      iVar3 = OBJ_obj2nid(pXVar11->algorithm);
      if (iVar3 == 0x38f) {
        pXVar11 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar11->parameter);
        a[1].hashAlgorithm = pXVar11;
        if (pXVar11 != (X509_ALGOR *)0x0) goto LAB_0014b04a;
      }
      else {
        a[1].hashAlgorithm = (X509_ALGOR *)0x0;
      }
      a_00 = (RSA_PSS_PARAMS *)0x0;
      RSA_PSS_PARAMS_free(a);
    }
LAB_0014b04a:
    iVar3 = rsa_pss_get_param(a_00,&local_28,&local_2c,&local_30);
    if (iVar3 == 0) {
      pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
      ERR_put_error(4,0x9b,0x95,"crypto/rsa/rsa_ameth.c",0x2ab);
    }
    else {
      iVar3 = EVP_PKEY_CTX_ctrl(pEVar2,-1,0xf8,0xd,0,&local_24);
      if (0 < iVar3) {
        iVar3 = EVP_MD_type(local_28);
        iVar13 = EVP_MD_type(local_24);
        if (iVar3 == iVar13) {
          iVar3 = RSA_pkey_ctx_ctrl(pEVar2,0xffffffff,0x1001,6,0);
          if (((0 < iVar3) && (iVar3 = RSA_pkey_ctx_ctrl(pEVar2,0x18,0x1002,local_30,0), 0 < iVar3))
             && (iVar3 = RSA_pkey_ctx_ctrl(pEVar2,0x3f8,0x1005,0,local_2c), 0 < iVar3)) {
            pAVar9 = (ASN1_OCTET_STRING *)0x1;
            goto LAB_0014b09e;
          }
        }
        else {
          ERR_put_error(4,0x9b,0x9e,"crypto/rsa/rsa_ameth.c",0x2b8);
        }
      }
      pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
    }
LAB_0014b09e:
    RSA_PSS_PARAMS_free(a_00);
    return pAVar9;
  case 7:
    if (**(int **)(param_1 + 0xc) == 0x390) {
      return (ASN1_OCTET_STRING *)0xfffffffe;
    }
    if (param_3 == (ASN1_STRING *)0x0) {
      local_30 = param_3;
      pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
      local_28 = (EVP_MD *)0x1;
      iVar3 = CMS_RecipientInfo_ktri_get0_algs
                        ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,
                         (X509_ALGOR **)&local_2c);
      if (iVar3 < 1) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      if ((pEVar2 != (EVP_PKEY_CTX *)0x0) &&
         (iVar3 = RSA_pkey_ctx_ctrl(pEVar2,0xffffffff,0x1006,0,&local_28), iVar3 < 1)) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      pEVar6 = local_2c;
      if (local_28 == (EVP_MD *)0x1) goto LAB_0014abd0;
      if (local_28 != (EVP_MD *)0x4) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      iVar3 = EVP_PKEY_CTX_ctrl(pEVar2,6,0x300,0x100b,0,&local_38);
      if ((((iVar3 < 1) || (iVar3 = RSA_pkey_ctx_ctrl(pEVar2,0x3f8,0x1008,0,&local_34), iVar3 < 1))
          || (iVar3 = EVP_PKEY_CTX_ctrl(pEVar2,6,0x300,0x100c,0,&local_24), iVar3 < 0)) ||
         (puVar4 = (undefined4 *)RSA_OAEP_PARAMS_new(), puVar4 == (undefined4 *)0x0)) {
        pAVar9 = (ASN1_OCTET_STRING *)0x0;
        puVar4 = (undefined4 *)0x0;
      }
      else {
        if ((local_38 != (EVP_MD *)0x0) && (iVar13 = EVP_MD_type(local_38), iVar13 != 0x40)) {
          pAVar9 = (ASN1_OCTET_STRING *)X509_ALGOR_new();
          *puVar4 = pAVar9;
          if (pAVar9 == (ASN1_OCTET_STRING *)0x0) goto LAB_0014af10;
          X509_ALGOR_set_md((X509_ALGOR *)pAVar9,local_38);
        }
        pAVar9 = (ASN1_OCTET_STRING *)rsa_md_to_mgf1(puVar4 + 1,local_34);
        if (pAVar9 != (ASN1_OCTET_STRING *)0x0) {
          if (iVar3 != 0) {
            pAVar9 = (ASN1_OCTET_STRING *)X509_ALGOR_new();
            puVar4[2] = pAVar9;
            if ((pAVar9 == (ASN1_OCTET_STRING *)0x0) ||
               (pAVar9 = ASN1_OCTET_STRING_new(), pAVar9 == (ASN1_OCTET_STRING *)0x0))
            goto LAB_0014af10;
            iVar3 = ASN1_OCTET_STRING_set(pAVar9,local_24,iVar3);
            if (iVar3 == 0) {
              ASN1_OCTET_STRING_free(pAVar9);
              pAVar9 = (ASN1_OCTET_STRING *)0x0;
              goto LAB_0014af10;
            }
            pXVar11 = (X509_ALGOR *)puVar4[2];
            pAVar7 = OBJ_nid2obj(0x3a7);
            X509_ALGOR_set0(pXVar11,pAVar7,4,pAVar9);
          }
          pAVar9 = ASN1_item_pack(puVar4,(ASN1_ITEM *)&RSA_OAEP_PARAMS_it,&local_30);
          if (pAVar9 != (ASN1_STRING *)0x0) {
            pAVar7 = OBJ_nid2obj(0x397);
            X509_ALGOR_set0((X509_ALGOR *)local_2c,pAVar7,0x10,local_30);
            pAVar9 = (ASN1_OCTET_STRING *)0x1;
            local_30 = (ASN1_STRING *)0x0;
          }
        }
      }
LAB_0014af10:
      RSA_OAEP_PARAMS_free(puVar4);
      ASN1_STRING_free(local_30);
      return pAVar9;
    }
    if (param_3 != (ASN1_STRING *)0x1) {
      return (ASN1_OCTET_STRING *)0x1;
    }
    pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    iVar3 = CMS_RecipientInfo_ktri_get0_algs
                      ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,
                       (X509_ALGOR **)&local_24);
    if (iVar3 == 0) {
      return (ASN1_OCTET_STRING *)0xffffffff;
    }
    iVar3 = OBJ_obj2nid((ASN1_OBJECT *)local_24->type);
    if (iVar3 == 6) {
      return (ASN1_OCTET_STRING *)0x1;
    }
    if (iVar3 != 0x397) {
      ERR_put_error(4,0x9f,0xa2,"crypto/rsa/rsa_ameth.c",0x3a7);
      return (ASN1_OCTET_STRING *)0xffffffff;
    }
    puVar4 = (undefined4 *)
             ASN1_TYPE_unpack_sequence(&RSA_OAEP_PARAMS_it,(ASN1_TYPE *)local_24->pkey_type);
    if (puVar4 != (undefined4 *)0x0) {
      puVar10 = (undefined4 *)puVar4[1];
      if (puVar10 == (undefined4 *)0x0) {
        puVar10 = (undefined4 *)puVar4[3];
        if (puVar10 == (undefined4 *)0x0) {
          pEVar6 = EVP_sha1();
          if (pEVar6 != (EVP_MD *)0x0) goto LAB_0014ad10;
        }
        else {
LAB_0014acfa:
          iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar10);
          pcVar5 = OBJ_nid2sn(iVar3);
          pEVar6 = EVP_get_digestbyname(pcVar5);
          if (pEVar6 == (EVP_MD *)0x0) {
LAB_0014b0f6:
            ERR_put_error(4,0x9c,0xa6,"crypto/rsa/rsa_ameth.c",0x249);
            pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
            goto LAB_0014ad62;
          }
LAB_0014ad10:
          if ((undefined4 *)*puVar4 == (undefined4 *)0x0) {
            p2 = EVP_sha1();
            if (p2 == (EVP_MD *)0x0) goto LAB_0014af3e;
          }
          else {
            iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)*puVar4);
            pcVar5 = OBJ_nid2sn(iVar3);
            p2 = EVP_get_digestbyname(pcVar5);
            if (p2 == (EVP_MD *)0x0) goto LAB_0014b0f6;
          }
          puVar10 = (undefined4 *)puVar4[2];
          if (puVar10 != (undefined4 *)0x0) {
            iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar10);
            if (iVar3 == 0x3a7) {
              if (*(int *)puVar10[1] == 4) {
                piVar8 = (int *)((int *)puVar10[1])[1];
                iVar3 = *piVar8;
                pvVar12 = (void *)piVar8[2];
                piVar8[2] = 0;
                goto LAB_0014af88;
              }
              iVar13 = 0x3c1;
              iVar3 = 0xa0;
            }
            else {
              iVar13 = 0x3bd;
              iVar3 = 0xa3;
            }
            ERR_put_error(4,0x9f,iVar3,"crypto/rsa/rsa_ameth.c",iVar13);
            pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
            goto LAB_0014ad62;
          }
          iVar3 = 0;
          pvVar12 = (void *)0x0;
LAB_0014af88:
          iVar13 = RSA_pkey_ctx_ctrl(pEVar2,0xffffffff,0x1001,4,0);
          if (((0 < iVar13) && (iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,6,0x300,0x1009,0,p2), 0 < iVar13))
             && (iVar13 = RSA_pkey_ctx_ctrl(pEVar2,0x3f8,0x1005,0,pEVar6), 0 < iVar13)) {
            iVar3 = EVP_PKEY_CTX_ctrl(pEVar2,6,0x300,0x100a,iVar3,pvVar12);
            if (iVar3 < 1) {
              pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
            }
            else {
              pAVar9 = (ASN1_OCTET_STRING *)0x1;
            }
            goto LAB_0014ad62;
          }
        }
LAB_0014af3e:
        pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
        goto LAB_0014ad62;
      }
      iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar10);
      if (iVar3 == 0x38f) {
        puVar10 = (undefined4 *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,puVar10[1]);
        puVar4[3] = puVar10;
        if (puVar10 != (undefined4 *)0x0) goto LAB_0014acfa;
      }
      else {
        puVar4[3] = 0;
      }
      RSA_OAEP_PARAMS_free(puVar4);
    }
    pAVar9 = (ASN1_OCTET_STRING *)0xffffffff;
    ERR_put_error(4,0x9f,0xa1,"crypto/rsa/rsa_ameth.c",0x3ae);
    puVar4 = (undefined4 *)0x0;
LAB_0014ad62:
    RSA_OAEP_PARAMS_free(puVar4);
    return pAVar9;
  case 8:
    if (**(int **)(param_1 + 0xc) == 0x390) {
      return (ASN1_OCTET_STRING *)0xfffffffe;
    }
    param_4->version = (ASN1_INTEGER *)0x0;
    return (ASN1_OCTET_STRING *)0x1;
  }
  pEVar6 = local_3c;
  if (local_3c == (EVP_MD *)0x0) {
    return (ASN1_OCTET_STRING *)0x1;
  }
LAB_0014abd0:
  pAVar7 = OBJ_nid2obj(6);
  X509_ALGOR_set0((X509_ALGOR *)pEVar6,pAVar7,5,(void *)0x0);
  return (ASN1_OCTET_STRING *)0x1;
}

