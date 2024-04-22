
/* WARNING: Type propagation algorithm not settling */

int ec_pkey_ctrl(EVP_PKEY *param_1,undefined4 param_2,EVP_MD *param_3,PKCS7_SIGNER_INFO *param_4)

{
  bool bVar1;
  EVP_PKEY_CTX *pEVar2;
  EVP_PKEY *pEVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  EVP_CIPHER_CTX *pEVar6;
  EVP_CIPHER *pEVar7;
  ASN1_TYPE *type;
  ASN1_STRING *str;
  EVP_MD *pEVar8;
  char *pcVar9;
  ulong uVar10;
  EC_GROUP *group;
  EC_KEY *pEVar11;
  long *plVar12;
  int iVar13;
  rsa_st *key;
  X509_ALGOR *pXVar14;
  int local_40;
  X509_ALGOR *local_3c;
  ASN1_OBJECT *local_38;
  ASN1_OBJECT *local_34;
  void *local_30;
  EVP_MD *local_2c;
  int local_28;
  EVP_MD *local_24 [2];
  
  switch(param_2) {
  case 1:
    if (param_3 == (EVP_MD *)0x0) {
      PKCS7_SIGNER_INFO_get0_algs
                (param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)&local_2c,(X509_ALGOR **)local_24);
joined_r0x000f7726:
      if (((local_2c != (EVP_MD *)0x0) && ((ASN1_OBJECT *)local_2c->type != (ASN1_OBJECT *)0x0)) &&
         (iVar13 = OBJ_obj2nid((ASN1_OBJECT *)local_2c->type), iVar13 != 0)) {
        iVar5 = EVP_PKEY_id(param_1);
        iVar13 = OBJ_find_sigid_by_algs(&local_28,iVar13,iVar5);
        if (iVar13 != 0) {
          pAVar4 = OBJ_nid2obj(local_28);
          X509_ALGOR_set0((X509_ALGOR *)local_24[0],pAVar4,-1,param_3);
          return 1;
        }
      }
      return -1;
    }
    goto LAB_000f76b2;
  default:
switchD_000f7696_caseD_2:
    iVar13 = -2;
    break;
  case 3:
    iVar13 = 2;
    param_4->version = (ASN1_INTEGER *)0x2a0;
    break;
  case 5:
    if (param_3 == (EVP_MD *)0x0) {
      CMS_SignerInfo_get0_algs
                ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)&local_2c,
                 (X509_ALGOR **)local_24);
      goto joined_r0x000f7726;
    }
LAB_000f76b2:
    iVar13 = 1;
    break;
  case 7:
    if (param_3 == (EVP_MD *)0x1) {
      pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
      if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
        return 0;
      }
      pEVar8 = (EVP_MD *)EVP_PKEY_CTX_get0_peerkey(pEVar2);
      if (pEVar8 == (EVP_MD *)0x0) {
        iVar13 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_3c,&local_38,0,0,0);
        if (iVar13 == 0) {
          return 0;
        }
        if (local_3c == (X509_ALGOR *)0x0) {
          return 0;
        }
        if (local_38 == (ASN1_OBJECT *)0x0) {
          return 0;
        }
        local_2c = pEVar8;
        X509_ALGOR_get0(&local_34,&local_28,&local_30,local_3c);
        iVar13 = OBJ_obj2nid(local_34);
        if (iVar13 == 0x198) {
          if ((local_28 == 5) || (local_28 == -1)) {
            pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2);
            if (pEVar3 != (EVP_PKEY *)0x0) {
              group = EC_KEY_get0_group((EC_KEY *)(pEVar3->pkey).rsa);
              local_2c = (EVP_MD *)EC_KEY_new();
              if (local_2c == (EVP_MD *)0x0) goto LAB_000f79a4;
              iVar13 = EC_KEY_set_group((EC_KEY *)local_2c,group);
              if (iVar13 != 0) goto LAB_000f7bac;
            }
            goto LAB_000f798a;
          }
          local_2c = (EVP_MD *)eckey_type2param(local_28,local_30);
          if (local_2c == (EVP_MD *)0x0) goto LAB_000f79a4;
LAB_000f7bac:
          iVar13 = ASN1_STRING_length((ASN1_STRING *)local_38);
          local_24[0] = (EVP_MD *)ASN1_STRING_data((ASN1_STRING *)local_38);
          if ((((iVar13 == 0) || (local_24[0] == (EVP_MD *)0x0)) ||
              (pEVar11 = o2i_ECPublicKey((EC_KEY **)&local_2c,(uchar **)local_24,iVar13),
              pEVar11 == (EC_KEY *)0x0)) || (pEVar3 = EVP_PKEY_new(), pEVar3 == (EVP_PKEY *)0x0))
          goto LAB_000f798a;
          EVP_PKEY_set1_EC_KEY(pEVar3,(ec_key_st *)local_2c);
          iVar13 = EVP_PKEY_derive_set_peer(pEVar2,pEVar3);
          bVar1 = 0 < iVar13;
        }
        else {
LAB_000f798a:
          pEVar3 = (EVP_PKEY *)0x0;
          bVar1 = false;
        }
        if (local_2c != (EVP_MD *)0x0) {
          EC_KEY_free((EC_KEY *)local_2c);
        }
        if (pEVar3 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pEVar3);
        }
        if (!bVar1) {
LAB_000f79a4:
          ERR_put_error(0x10,0xee,0x95,DAT_000f7c10,0x32a);
          return 0;
        }
      }
      iVar5 = 0;
      local_24[0] = (EVP_MD *)0x0;
      iVar13 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_34,&local_30);
      if (iVar13 == 0) goto LAB_000f79ea;
      iVar13 = OBJ_obj2nid((ASN1_OBJECT *)local_34->sn);
      if ((iVar13 != 0) && (iVar13 = OBJ_find_sigid_algs(iVar13,&local_28,&local_40), iVar13 != 0))
      {
        if (local_40 != 0x3b2) {
          if (local_40 != 0x3b3) goto LAB_000f7a72;
          iVar5 = 1;
        }
        iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1003,iVar5,(void *)0x0);
        if ((0 < iVar13) &&
           (iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,2,(void *)0x0), 0 < iVar13)) {
          pcVar9 = OBJ_nid2sn(local_28);
          pEVar8 = EVP_get_digestbyname(pcVar9);
          if ((pEVar8 != (EVP_MD *)0x0) &&
             (iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1005,0,pEVar8), 0 < iVar13)) {
            if (*local_34->ln != (char *)0x10) goto LAB_000f79ea;
            plVar12 = (long *)local_34->ln[1];
            local_2c = (EVP_MD *)plVar12[2];
            pXVar14 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_2c,*plVar12);
            if (pXVar14 == (X509_ALGOR *)0x0) {
              bVar1 = false;
            }
            else {
              pEVar6 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
              if (pEVar6 == (EVP_CIPHER_CTX *)0x0) {
LAB_000f7b5a:
                bVar1 = false;
              }
              else {
                iVar13 = OBJ_obj2nid(pXVar14->algorithm);
                pcVar9 = OBJ_nid2sn(iVar13);
                pEVar7 = EVP_get_cipherbyname(pcVar9);
                if ((((pEVar7 == (EVP_CIPHER *)0x0) ||
                     (uVar10 = EVP_CIPHER_flags(pEVar7), (uVar10 & 0xf0007) != 0x10002)) ||
                    (iVar13 = EVP_EncryptInit_ex(pEVar6,pEVar7,(ENGINE *)0x0,(uchar *)0x0,
                                                 (uchar *)0x0), iVar13 == 0)) ||
                   (iVar13 = EVP_CIPHER_asn1_to_param(pEVar6,pXVar14->parameter), iVar13 < 1))
                goto LAB_000f7b5a;
                iVar13 = EVP_CIPHER_CTX_key_length(pEVar6);
                iVar5 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1007,iVar13,(void *)0x0);
                if (((iVar5 < 1) ||
                    (iVar13 = CMS_SharedInfo_encode(local_24,pXVar14,local_30,iVar13), iVar13 == 0))
                   || (iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1009,iVar13,local_24[0]),
                      iVar13 < 1)) goto LAB_000f7b5a;
                local_24[0] = (EVP_MD *)0x0;
                bVar1 = true;
              }
              X509_ALGOR_free(pXVar14);
            }
            if (local_24[0] != (EVP_MD *)0x0) {
              CRYPTO_free(local_24[0]);
            }
            if (!bVar1) goto LAB_000f79ea;
            goto LAB_000f76b2;
          }
        }
      }
LAB_000f7a72:
      ERR_put_error(0x10,0xef,0x94,DAT_000f7c10,0x2ed);
LAB_000f79ea:
      ERR_put_error(0x10,0xee,0x96,DAT_000f7c10,0x330);
      return 0;
    }
    if (param_3 != (EVP_MD *)0x0) goto switchD_000f7696_caseD_2;
    local_2c = param_3;
    pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      return 0;
    }
    pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2);
    iVar13 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_3c,&local_34,0,0,0);
    if (iVar13 == 0) {
LAB_000f76f4:
      iVar13 = 0;
      pXVar14 = (X509_ALGOR *)0x0;
LAB_000f76f8:
      if (local_2c != (EVP_MD *)0x0) {
LAB_000f76fc:
        CRYPTO_free(local_2c);
      }
      if (pXVar14 == (X509_ALGOR *)0x0) {
        return iVar13;
      }
    }
    else {
      X509_ALGOR_get0(&local_38,(int *)0x0,(void **)0x0,local_3c);
      pAVar4 = OBJ_nid2obj(0);
      if (local_38 == pAVar4) {
        key = (pEVar3->pkey).rsa;
        iVar13 = i2o_ECPublicKey((EC_KEY *)key,(uchar **)0x0);
        if (((iVar13 < 1) ||
            (local_2c = (EVP_MD *)CRYPTO_malloc(iVar13,DAT_000f7c10,0x359),
            local_2c == (EVP_MD *)0x0)) ||
           (local_24[0] = local_2c, iVar13 = i2o_ECPublicKey((EC_KEY *)key,(uchar **)local_24),
           iVar13 < 1)) goto LAB_000f76f4;
        ASN1_STRING_set0((ASN1_STRING *)local_34,local_2c,iVar13);
        pXVar14 = local_3c;
        local_34->length = local_34->length & 0xfffffff0U | 8;
        local_2c = param_3;
        pAVar4 = OBJ_nid2obj(0x198);
        X509_ALGOR_set0(pXVar14,pAVar4,-1,(void *)0x0);
      }
      iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,-2,(void *)0x0);
      if ((iVar13 < 1) ||
         (iVar5 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1006,0,local_24), iVar5 == 0))
      goto LAB_000f76f4;
      iVar5 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1003,-2,(void *)0x0);
      if (iVar5 < 0) goto LAB_000f76f4;
      if (iVar5 == 0) {
        iVar5 = 0x3b2;
      }
      else if (iVar5 == 1) {
        iVar5 = 0x3b3;
      }
      if ((iVar13 != 1) ||
         (iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,2,(void *)0x0), iVar13 < 1))
      goto LAB_000f76f4;
      if (local_24[0] == (EVP_MD *)0x0) {
        local_24[0] = EVP_sha1();
        iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1005,0,local_24[0]);
        if (iVar13 < 1) goto LAB_000f76f4;
      }
      iVar13 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_3c,&local_30);
      if (iVar13 == 0) goto LAB_000f76f4;
      iVar13 = EVP_MD_type(local_24[0]);
      iVar13 = OBJ_find_sigid_by_algs(&local_28,iVar13,iVar5);
      if (iVar13 == 0) goto LAB_000f76f4;
      pEVar6 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
      pEVar7 = EVP_CIPHER_CTX_cipher(pEVar6);
      iVar13 = EVP_CIPHER_type(pEVar7);
      iVar5 = EVP_CIPHER_CTX_key_length(pEVar6);
      pXVar14 = X509_ALGOR_new();
      if (pXVar14 == (X509_ALGOR *)0x0) goto LAB_000f76f4;
      pAVar4 = OBJ_nid2obj(iVar13);
      pXVar14->algorithm = pAVar4;
      type = ASN1_TYPE_new();
      pXVar14->parameter = type;
      if ((type == (ASN1_TYPE *)0x0) || (iVar13 = EVP_CIPHER_param_to_asn1(pEVar6,type), iVar13 < 1)
         ) {
LAB_000f7c8e:
        iVar13 = 0;
        goto LAB_000f76f8;
      }
      iVar13 = ASN1_TYPE_get(pXVar14->parameter);
      if (iVar13 == 0) {
        ASN1_TYPE_free(pXVar14->parameter);
        pXVar14->parameter = (ASN1_TYPE *)0x0;
      }
      iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1007,iVar5,(void *)0x0);
      if (iVar13 < 1) goto LAB_000f7c8e;
      iVar13 = CMS_SharedInfo_encode(&local_2c,pXVar14,local_30,iVar5);
      if (iVar13 == 0) goto LAB_000f76f8;
      iVar13 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1009,iVar13,local_2c);
      if (iVar13 < 1) goto LAB_000f7c8e;
      local_2c = (EVP_MD *)0x0;
      iVar13 = i2d_X509_ALGOR(pXVar14,(uchar **)&local_2c);
      if (local_2c != (EVP_MD *)0x0) {
        if (iVar13 != 0) {
          str = ASN1_STRING_new();
          if (str == (ASN1_STRING *)0x0) {
            iVar13 = 0;
          }
          else {
            ASN1_STRING_set0(str,local_2c,iVar13);
            iVar13 = 1;
            local_2c = (EVP_MD *)0x0;
            pAVar4 = OBJ_nid2obj(local_28);
            X509_ALGOR_set0(local_3c,pAVar4,0x10,str);
          }
          goto LAB_000f76f8;
        }
        goto LAB_000f76fc;
      }
      iVar13 = 0;
    }
    X509_ALGOR_free(pXVar14);
    break;
  case 8:
    iVar13 = 1;
    param_4->version = (ASN1_INTEGER *)0x1;
  }
  return iVar13;
}

