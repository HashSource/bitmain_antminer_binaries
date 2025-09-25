
undefined4
ec_pkey_ctrl(EVP_PKEY *param_1,undefined4 param_2,EVP_MD *param_3,PKCS7_SIGNER_INFO *param_4)

{
  undefined4 uVar1;
  EVP_PKEY_CTX *pEVar2;
  EVP_PKEY *pEVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  EVP_CIPHER_CTX *pEVar7;
  EVP_CIPHER *pEVar8;
  ASN1_TYPE *type;
  char *pcVar9;
  EVP_MD *p2;
  ulong uVar10;
  EC_GROUP *group;
  ASN1_STRING *str;
  ASN1_INTEGER *pAVar11;
  long *plVar12;
  X509_ALGOR *pXVar13;
  EC_KEY *pEVar14;
  X509_ALGOR *local_3c;
  ASN1_OBJECT *local_38;
  ASN1_OBJECT *local_34;
  int local_30;
  EVP_MD *local_2c;
  EVP_PKEY *local_28;
  EVP_MD *local_24 [2];
  
  switch(param_2) {
  case 1:
    if (param_3 != (EVP_MD *)0x0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs
              (param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)&local_28,(X509_ALGOR **)local_24);
    break;
  default:
    return 0xfffffffe;
  case 3:
    iVar4 = EVP_PKEY_id(param_1);
    if (iVar4 == 0x494) {
      pAVar11 = (ASN1_INTEGER *)0x477;
    }
    else {
      pAVar11 = (ASN1_INTEGER *)0x2a0;
    }
    param_4->version = pAVar11;
    return 1;
  case 5:
    if (param_3 != (EVP_MD *)0x0) {
      return 1;
    }
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)&local_28,
               (X509_ALGOR **)local_24);
    break;
  case 7:
    if (param_3 == (EVP_MD *)0x1) {
      pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
      if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
        return 0;
      }
      pEVar3 = EVP_PKEY_CTX_get0_peerkey(pEVar2);
      if (pEVar3 == (EVP_PKEY *)0x0) {
        iVar4 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_3c,&local_38,0,0,0);
        if (iVar4 == 0) {
          return 0;
        }
        if (local_3c == (X509_ALGOR *)0x0) {
          return 0;
        }
        if (local_38 == (ASN1_OBJECT *)0x0) {
          return 0;
        }
        local_28 = pEVar3;
        X509_ALGOR_get0(&local_34,&local_30,&local_2c,local_3c);
        iVar4 = OBJ_obj2nid(local_34);
        if (iVar4 == 0x198) {
          if ((local_30 == -1) || (local_30 == 5)) {
            pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2);
            if (pEVar3 != (EVP_PKEY *)0x0) {
              group = EC_KEY_get0_group((EC_KEY *)pEVar3->save_parameters);
              local_28 = (EVP_PKEY *)EC_KEY_new();
              if (local_28 != (EVP_PKEY *)0x0) {
                pEVar3 = (EVP_PKEY *)EC_KEY_set_group((EC_KEY *)local_28,group);
                goto joined_r0x001160e2;
              }
            }
          }
          else {
            local_28 = (EVP_PKEY *)eckey_type2param(local_30,local_2c);
            pEVar3 = local_28;
joined_r0x001160e2:
            if (pEVar3 != (EVP_PKEY *)0x0) {
              iVar4 = ASN1_STRING_length((ASN1_STRING *)local_38);
              local_24[0] = (EVP_MD *)ASN1_STRING_get0_data(local_38);
              if ((((local_24[0] != (EVP_MD *)0x0) && (iVar4 != 0)) &&
                  (pEVar14 = o2i_ECPublicKey((EC_KEY **)&local_28,(uchar **)local_24,iVar4),
                  pEVar14 != (EC_KEY *)0x0)) && (pEVar3 = EVP_PKEY_new(), pEVar3 != (EVP_PKEY *)0x0)
                 ) {
                EVP_PKEY_set1_EC_KEY(pEVar3,(ec_key_st *)local_28);
                iVar4 = EVP_PKEY_derive_set_peer(pEVar2,pEVar3);
                if (iVar4 < 1) goto LAB_00115f38;
                EC_KEY_free((EC_KEY *)local_28);
                EVP_PKEY_free(pEVar3);
                goto LAB_00115e38;
              }
            }
          }
        }
        pEVar3 = (EVP_PKEY *)0x0;
LAB_00115f38:
        EC_KEY_free((EC_KEY *)local_28);
        EVP_PKEY_free(pEVar3);
        ERR_put_error(0x10,0xee,0x95,"crypto/ec/ec_ameth.c",0x32b);
        return 0;
      }
LAB_00115e38:
      iVar6 = 0;
      local_2c = (EVP_MD *)0x0;
      iVar4 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_34,&local_30);
      if (iVar4 == 0) goto LAB_00115e4a;
      iVar4 = OBJ_obj2nid((ASN1_OBJECT *)local_34->sn);
      if (iVar4 != 0) {
        iVar4 = OBJ_find_sigid_algs(iVar4,(int *)local_24,(int *)&local_28);
        if (iVar4 != 0) {
          if (local_28 != (EVP_PKEY *)0x3b2) {
            if (local_28 != (EVP_PKEY *)0x3b3) goto LAB_00115edc;
            iVar6 = 1;
          }
          iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1003,iVar6,(void *)0x0);
          if ((0 < iVar4) &&
             (iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,2,(void *)0x0), 0 < iVar4)) {
            pcVar9 = OBJ_nid2sn((int)local_24[0]);
            p2 = EVP_get_digestbyname(pcVar9);
            if ((p2 != (EVP_MD *)0x0) &&
               (iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1005,0,p2), 0 < iVar4)) {
              if (*local_34->ln == (char *)0x10) {
                plVar12 = (long *)local_34->ln[1];
                local_24[0] = (EVP_MD *)plVar12[2];
                pXVar13 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)local_24,*plVar12);
                if ((pXVar13 != (X509_ALGOR *)0x0) &&
                   (pEVar7 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4),
                   pEVar7 != (EVP_CIPHER_CTX *)0x0)) {
                  iVar4 = OBJ_obj2nid(pXVar13->algorithm);
                  pcVar9 = OBJ_nid2sn(iVar4);
                  pEVar8 = EVP_get_cipherbyname(pcVar9);
                  if ((pEVar8 != (EVP_CIPHER *)0x0) &&
                     (((uVar10 = EVP_CIPHER_flags(pEVar8), (uVar10 & 0xf0007) == 0x10002 &&
                       (iVar4 = EVP_EncryptInit_ex(pEVar7,pEVar8,(ENGINE *)0x0,(uchar *)0x0,
                                                   (uchar *)0x0), iVar4 != 0)) &&
                      (iVar4 = EVP_CIPHER_asn1_to_param(pEVar7,pXVar13->parameter), 0 < iVar4)))) {
                    iVar4 = EVP_CIPHER_CTX_key_length(pEVar7);
                    iVar6 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1007,iVar4,(void *)0x0);
                    if (((0 < iVar6) &&
                        (iVar4 = CMS_SharedInfo_encode(&local_2c,pXVar13,local_30,iVar4), iVar4 != 0
                        )) && (iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1009,iVar4,local_2c),
                              0 < iVar4)) {
                      local_2c = (EVP_MD *)0x0;
                      X509_ALGOR_free(pXVar13);
                      CRYPTO_free(local_2c);
                      return 1;
                    }
                  }
                }
                X509_ALGOR_free(pXVar13);
                CRYPTO_free(local_2c);
              }
              goto LAB_00115e4a;
            }
          }
        }
      }
LAB_00115edc:
      ERR_put_error(0x10,0xef,0x94,"crypto/ec/ec_ameth.c",0x2f0);
LAB_00115e4a:
      ERR_put_error(0x10,0xee,0x96,"crypto/ec/ec_ameth.c",0x331);
      return 0;
    }
    if (param_3 != (EVP_MD *)0x0) {
      return 0xfffffffe;
    }
    local_2c = param_3;
    pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      return 0;
    }
    pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2);
    iVar4 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_3c,&local_34,0,0,0);
    if (iVar4 != 0) {
      X509_ALGOR_get0(&local_38,(int *)0x0,(void **)0x0,local_3c);
      pAVar5 = OBJ_nid2obj(0);
      if (local_38 == pAVar5) {
        pEVar14 = (EC_KEY *)pEVar3->save_parameters;
        iVar4 = i2o_ECPublicKey(pEVar14,(uchar **)0x0);
        if (((iVar4 < 1) ||
            (local_2c = (EVP_MD *)CRYPTO_malloc(iVar4,"crypto/ec/ec_ameth.c",0x35a),
            local_2c == (EVP_MD *)0x0)) ||
           (local_24[0] = local_2c, iVar4 = i2o_ECPublicKey(pEVar14,(uchar **)local_24), iVar4 < 1))
        goto LAB_00115c46;
        ASN1_STRING_set0((ASN1_STRING *)local_34,local_2c,iVar4);
        pXVar13 = local_3c;
        local_34->length = local_34->length & 0xfffffff0U | 8;
        local_2c = param_3;
        pAVar5 = OBJ_nid2obj(0x198);
        X509_ALGOR_set0(pXVar13,pAVar5,-1,(void *)0x0);
      }
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,-2,(void *)0x0);
      if ((0 < iVar4) &&
         (iVar6 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1006,0,local_24), iVar6 != 0)) {
        iVar6 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1003,-2,(void *)0x0);
        if (-1 < iVar6) {
          if (iVar6 == 0) {
            iVar6 = 0x3b2;
          }
          else if (iVar6 == 1) {
            iVar6 = 0x3b3;
          }
          if ((iVar4 == 1) &&
             (iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1004,2,(void *)0x0), 0 < iVar4)) {
            if (local_24[0] == (EVP_MD *)0x0) {
              local_24[0] = EVP_sha1();
              iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1005,0,local_24[0]);
              if (iVar4 < 1) goto LAB_00115c46;
            }
            iVar4 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_3c,&local_30);
            if (iVar4 != 0) {
              iVar4 = EVP_MD_type(local_24[0]);
              iVar4 = OBJ_find_sigid_by_algs((int *)&local_28,iVar4,iVar6);
              if (iVar4 != 0) {
                pEVar7 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
                pEVar8 = EVP_CIPHER_CTX_cipher(pEVar7);
                iVar4 = EVP_CIPHER_type(pEVar8);
                iVar6 = EVP_CIPHER_CTX_key_length(pEVar7);
                pXVar13 = X509_ALGOR_new();
                if (pXVar13 != (X509_ALGOR *)0x0) {
                  pAVar5 = OBJ_nid2obj(iVar4);
                  pXVar13->algorithm = pAVar5;
                  type = ASN1_TYPE_new();
                  pXVar13->parameter = type;
                  if (type == (ASN1_TYPE *)0x0) {
                    uVar1 = 0;
                  }
                  else {
                    iVar4 = EVP_CIPHER_param_to_asn1(pEVar7,type);
                    if (iVar4 < 1) {
                      uVar1 = 0;
                    }
                    else {
                      iVar4 = ASN1_TYPE_get(pXVar13->parameter);
                      if (iVar4 == 0) {
                        ASN1_TYPE_free(pXVar13->parameter);
                        pXVar13->parameter = (ASN1_TYPE *)0x0;
                      }
                      uVar1 = 0;
                      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1007,iVar6,(void *)0x0);
                      if (0 < iVar4) {
                        iVar4 = CMS_SharedInfo_encode(&local_2c,pXVar13,local_30,iVar6);
                        if (iVar4 == 0) {
                          uVar1 = 0;
                        }
                        else {
                          iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x198,0x400,0x1009,iVar4,local_2c);
                          if (0 < iVar4) {
                            local_2c = (EVP_MD *)0x0;
                            iVar4 = i2d_X509_ALGOR(pXVar13,(uchar **)&local_2c);
                            if ((local_2c == (EVP_MD *)0x0) ||
                               ((EVP_MD *)(uint)(iVar4 == 0) != (EVP_MD *)0x0)) {
                              uVar1 = 0;
                            }
                            else {
                              str = ASN1_STRING_new();
                              if (str == (ASN1_STRING *)0x0) {
                                uVar1 = 0;
                              }
                              else {
                                ASN1_STRING_set0(str,local_2c,iVar4);
                                uVar1 = 1;
                                local_2c = (EVP_MD *)(uint)(iVar4 == 0);
                                pAVar5 = OBJ_nid2obj((int)local_28);
                                X509_ALGOR_set0(local_3c,pAVar5,0x10,str);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_00115c4c;
                }
              }
            }
          }
        }
      }
    }
LAB_00115c46:
    uVar1 = 0;
    pXVar13 = (X509_ALGOR *)0x0;
LAB_00115c4c:
    CRYPTO_free(local_2c);
    X509_ALGOR_free(pXVar13);
    return uVar1;
  case 8:
    param_4->version = (ASN1_INTEGER *)0x1;
    return 1;
  case 9:
    uVar1 = EVP_PKEY_get0_EC_KEY();
    uVar1 = EC_KEY_oct2key(uVar1,param_4,param_3,0);
    return uVar1;
  case 10:
    uVar1 = EVP_PKEY_get0_EC_KEY();
    uVar1 = EC_KEY_key2buf(uVar1,4,param_4,0);
    return uVar1;
  }
  if (((local_28 != (EVP_PKEY *)0x0) && ((ASN1_OBJECT *)local_28->type != (ASN1_OBJECT *)0x0)) &&
     (iVar4 = OBJ_obj2nid((ASN1_OBJECT *)local_28->type), iVar4 != 0)) {
    iVar6 = EVP_PKEY_id(param_1);
    iVar4 = OBJ_find_sigid_by_algs((int *)&local_2c,iVar4,iVar6);
    if (iVar4 != 0) {
      pAVar5 = OBJ_nid2obj((int)local_2c);
      X509_ALGOR_set0((X509_ALGOR *)local_24[0],pAVar5,-1,param_3);
      return 1;
    }
  }
  return 0xffffffff;
}

