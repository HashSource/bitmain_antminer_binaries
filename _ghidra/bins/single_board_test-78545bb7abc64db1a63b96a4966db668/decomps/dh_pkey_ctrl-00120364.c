
void * dh_pkey_ctrl(undefined4 param_1,int param_2,ASN1_STRING *param_3,undefined4 *param_4)

{
  EVP_PKEY_CTX *pEVar1;
  EVP_PKEY *pEVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  EVP_CIPHER_CTX *pEVar6;
  EVP_CIPHER *pEVar7;
  ASN1_TYPE *type;
  undefined4 uVar8;
  void *p2;
  ASN1_INTEGER *pAVar9;
  EVP_MD *p2_00;
  EVP_CIPHER_CTX *ctx;
  char *name;
  ulong uVar10;
  BIGNUM *pBVar11;
  ASN1_STRING *str;
  long *plVar12;
  void *pvVar13;
  EVP_CIPHER_CTX *a;
  X509_ALGOR *pXVar14;
  EVP_PKEY *pkey;
  DH *dh;
  X509_ALGOR *local_40;
  ASN1_OBJECT *local_3c;
  ASN1_OBJECT *local_38;
  ASN1_STRING *local_34;
  ASN1_STRING *local_30;
  EVP_MD *local_2c [2];
  
  if (param_2 != 7) {
    if (param_2 != 8) {
      return (void *)0xfffffffe;
    }
    *param_4 = 1;
    return (void *)0x1;
  }
  if (param_3 == (ASN1_STRING *)0x1) {
    pEVar1 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
    if (pEVar1 == (EVP_PKEY_CTX *)0x0) {
      return (void *)0x0;
    }
    pEVar2 = EVP_PKEY_CTX_get0_peerkey(pEVar1);
    if (pEVar2 == (EVP_PKEY *)0x0) {
      iVar3 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_40,&local_3c,0,0,0);
      if (iVar3 == 0) {
        return (void *)0x0;
      }
      if (local_40 == (X509_ALGOR *)0x0) {
        return (void *)0x0;
      }
      if (local_3c == (ASN1_OBJECT *)0x0) {
        return (void *)0x0;
      }
      X509_ALGOR_get0(&local_38,(int *)&local_34,&local_30,local_40);
      iVar3 = OBJ_obj2nid(local_38);
      if ((((iVar3 != 0x398) || (local_34 == (ASN1_STRING *)&DAT_00000005)) ||
          (pEVar2 = EVP_PKEY_CTX_get0_pkey(pEVar1), pEVar2 == (EVP_PKEY *)0x0)) ||
         ((pEVar2->type != 0x398 ||
          (dh = DHparams_dup((DH *)pEVar2->save_parameters), dh == (DH *)0x0)))) {
        dh = (DH *)0x0;
        pkey = (EVP_PKEY *)0x0;
        pAVar9 = (ASN1_STRING *)0x0;
LAB_0012069c:
        ASN1_INTEGER_free(pAVar9);
        EVP_PKEY_free(pkey);
        DH_free(dh);
        ERR_put_error(5,0x72,0x6f,"crypto/dh/dh_ameth.c",0x2fd);
        return (void *)0x0;
      }
      iVar3 = ASN1_STRING_length((ASN1_STRING *)local_3c);
      local_2c[0] = (EVP_MD *)ASN1_STRING_get0_data(local_3c);
      if ((local_2c[0] == (EVP_MD *)0x0) || (iVar3 == 0)) {
        pkey = (EVP_PKEY *)0x0;
        pAVar9 = (ASN1_STRING *)0x0;
        goto LAB_0012069c;
      }
      pAVar9 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,(uchar **)local_2c,iVar3);
      if (pAVar9 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(5,0x73,0x68,"crypto/dh/dh_ameth.c",0x287);
        pkey = (EVP_PKEY *)0x0;
        goto LAB_0012069c;
      }
      pBVar11 = ASN1_INTEGER_to_BN(pAVar9,(BIGNUM *)0x0);
      dh->pub_key = pBVar11;
      if (pBVar11 == (BIGNUM *)0x0) {
        ERR_put_error(5,0x73,0x6d,"crypto/dh/dh_ameth.c",0x28d);
        pkey = (EVP_PKEY *)0x0;
        goto LAB_0012069c;
      }
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) goto LAB_0012069c;
      EVP_PKEY_assign(pkey,*(int *)pEVar2->ameth,dh);
      iVar3 = EVP_PKEY_derive_set_peer(pEVar1,pkey);
      if (iVar3 < 1) {
        dh = (DH *)0x0;
        goto LAB_0012069c;
      }
      ASN1_INTEGER_free(pAVar9);
      EVP_PKEY_free(pkey);
      DH_free((DH *)0x0);
    }
    iVar3 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_34,&local_30);
    if (iVar3 != 0) {
      iVar3 = OBJ_obj2nid((ASN1_OBJECT *)local_34->length);
      if (iVar3 != 0xf5) {
        a = (EVP_CIPHER_CTX *)0x0;
        ERR_put_error(5,0x74,0x70,"crypto/dh/dh_ameth.c",0x2b5);
        pEVar6 = a;
        goto LAB_0012059a;
      }
      iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1006,2,(void *)0x0);
      if (0 < iVar3) {
        p2_00 = EVP_sha1();
        iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1007,0,p2_00);
        if ((0 < iVar3) && (*(int *)local_34->type == 0x10)) {
          plVar12 = (long *)((int *)local_34->type)[1];
          local_2c[0] = (EVP_MD *)plVar12[2];
          a = (EVP_CIPHER_CTX *)d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)local_2c,*plVar12);
          if (a != (EVP_CIPHER_CTX *)0x0) {
            ctx = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
            pEVar6 = ctx;
            if (ctx != (EVP_CIPHER_CTX *)0x0) {
              iVar3 = OBJ_obj2nid((ASN1_OBJECT *)a->cipher);
              name = OBJ_nid2sn(iVar3);
              pEVar7 = EVP_get_cipherbyname(name);
              if (pEVar7 == (EVP_CIPHER *)0x0) {
                pEVar6 = (EVP_CIPHER_CTX *)0x0;
              }
              else {
                uVar10 = EVP_CIPHER_flags(pEVar7);
                if ((uVar10 & 0xf0007) == 0x10002) {
                  iVar3 = EVP_EncryptInit_ex(ctx,pEVar7,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
                  if ((iVar3 == 0) ||
                     (iVar3 = EVP_CIPHER_asn1_to_param(ctx,(ASN1_TYPE *)a->engine), iVar3 < 1)) {
                    pEVar6 = (EVP_CIPHER_CTX *)0x0;
                  }
                  else {
                    pEVar6 = (EVP_CIPHER_CTX *)0x0;
                    iVar3 = EVP_CIPHER_CTX_key_length(ctx);
                    iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1009,iVar3,(void *)0x0);
                    if (0 < iVar3) {
                      iVar3 = EVP_CIPHER_type(pEVar7);
                      pAVar4 = OBJ_nid2obj(iVar3);
                      iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x100d,0,pAVar4);
                      if (0 < iVar3) {
                        if (local_30 == (ASN1_STRING *)0x0) {
                          pEVar6 = (EVP_CIPHER_CTX *)0x0;
                          iVar3 = 0;
                        }
                        else {
                          iVar3 = ASN1_STRING_length(local_30);
                          uVar8 = ASN1_STRING_get0_data(local_30);
                          pEVar6 = (EVP_CIPHER_CTX *)
                                   CRYPTO_memdup(uVar8,iVar3,"crypto/dh/dh_ameth.c",0x2dd);
                          if (pEVar6 == (EVP_CIPHER_CTX *)0x0) goto LAB_0012059a;
                        }
                        iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x100b,iVar3,pEVar6);
                        if (0 < iVar3) {
                          X509_ALGOR_free((X509_ALGOR *)a);
                          CRYPTO_free((void *)0x0);
                          return (void *)0x1;
                        }
                      }
                    }
                  }
                }
                else {
                  pEVar6 = (EVP_CIPHER_CTX *)0x0;
                }
              }
            }
            goto LAB_0012059a;
          }
        }
      }
    }
    a = (EVP_CIPHER_CTX *)0x0;
    pEVar6 = (EVP_CIPHER_CTX *)0x0;
LAB_0012059a:
    X509_ALGOR_free((X509_ALGOR *)a);
    CRYPTO_free(pEVar6);
    ERR_put_error(5,0x72,0x71,"crypto/dh/dh_ameth.c",0x303);
    return (void *)0x0;
  }
  if (param_3 != (ASN1_STRING *)0x0) {
    return (void *)0xfffffffe;
  }
  local_30 = param_3;
  pEVar1 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
  if (pEVar1 == (EVP_PKEY_CTX *)0x0) {
    return (void *)0x0;
  }
  pEVar2 = EVP_PKEY_CTX_get0_pkey(pEVar1);
  iVar3 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_40,&local_38,0,0,0);
  if (iVar3 != 0) {
    X509_ALGOR_get0(&local_3c,(int *)0x0,(void **)0x0,local_40);
    pAVar4 = OBJ_nid2obj(0);
    if (local_3c == pAVar4) {
      pAVar9 = BN_to_ASN1_INTEGER(*(BIGNUM **)(pEVar2->save_parameters + 0x14),(ASN1_INTEGER *)0x0);
      if (pAVar9 != (ASN1_INTEGER *)0x0) {
        iVar3 = i2d_ASN1_INTEGER(pAVar9,(uchar **)&local_30);
        ASN1_INTEGER_free(pAVar9);
        if (0 < iVar3) {
          ASN1_STRING_set0((ASN1_STRING *)local_38,local_30,iVar3);
          pXVar14 = local_40;
          local_38->length = local_38->length & 0xfffffff0U | 8;
          local_30 = param_3;
          pAVar4 = OBJ_nid2obj(0x398);
          X509_ALGOR_set0(pXVar14,pAVar4,-1,(void *)0x0);
          goto LAB_00120404;
        }
      }
    }
    else {
LAB_00120404:
      iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1006,-2,(void *)0x0);
      if ((0 < iVar3) &&
         (iVar5 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1008,0,local_2c), iVar5 != 0)) {
        if (iVar3 == 1) {
          iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1006,2,(void *)0x0);
          if (0 < iVar3) goto LAB_00120450;
        }
        else if (iVar3 == 2) {
LAB_00120450:
          if (local_2c[0] == (EVP_MD *)0x0) {
            local_2c[0] = EVP_sha1();
            iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1007,0,local_2c[0]);
            if (0 < iVar3) goto LAB_00120462;
          }
          else {
            iVar3 = EVP_MD_type(local_2c[0]);
            if (iVar3 == 0x40) {
LAB_00120462:
              iVar3 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_40,&local_34);
              if (iVar3 != 0) {
                pEVar6 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
                pEVar7 = EVP_CIPHER_CTX_cipher(pEVar6);
                iVar3 = EVP_CIPHER_type(pEVar7);
                pAVar4 = OBJ_nid2obj(iVar3);
                iVar5 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x100d,0,pAVar4);
                if (0 < iVar5) {
                  iVar5 = EVP_CIPHER_CTX_key_length(pEVar6);
                  pXVar14 = X509_ALGOR_new();
                  if (pXVar14 != (X509_ALGOR *)0x0) {
                    pAVar4 = OBJ_nid2obj(iVar3);
                    pXVar14->algorithm = pAVar4;
                    type = ASN1_TYPE_new();
                    pXVar14->parameter = type;
                    if (type == (ASN1_TYPE *)0x0) {
                      pvVar13 = (void *)0x0;
                      p2 = (void *)0x0;
                    }
                    else {
                      iVar3 = EVP_CIPHER_param_to_asn1(pEVar6,type);
                      if (0 < iVar3) {
                        iVar3 = ASN1_TYPE_get(pXVar14->parameter);
                        if (iVar3 == 0) {
                          ASN1_TYPE_free(pXVar14->parameter);
                          pXVar14->parameter = (ASN1_TYPE *)0x0;
                        }
                        iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x1009,iVar5,(void *)0x0);
                        if (0 < iVar3) {
                          if (local_34 == (ASN1_STRING *)0x0) {
                            iVar3 = 0;
                            p2 = (void *)0x0;
                          }
                          else {
                            iVar3 = ASN1_STRING_length(local_34);
                            uVar8 = ASN1_STRING_get0_data(local_34);
                            p2 = (void *)CRYPTO_memdup(uVar8,iVar3,"crypto/dh/dh_ameth.c",0x36d);
                            if (p2 == (void *)0x0) {
                              pvVar13 = (void *)0x0;
                              goto LAB_001203c0;
                            }
                          }
                          iVar3 = EVP_PKEY_CTX_ctrl(pEVar1,0x398,0x400,0x100b,iVar3,p2);
                          if (iVar3 < 1) {
                            pvVar13 = (void *)0x0;
                          }
                          else {
                            local_30 = (ASN1_STRING *)0x0;
                            iVar3 = i2d_X509_ALGOR(pXVar14,(uchar **)&local_30);
                            if ((local_30 == (ASN1_STRING *)0x0) ||
                               ((ASN1_STRING *)(uint)(iVar3 == 0) != (ASN1_STRING *)0x0)) {
                              pvVar13 = (void *)0x0;
                              p2 = pvVar13;
                            }
                            else {
                              str = ASN1_STRING_new();
                              if (str == (ASN1_STRING *)0x0) {
                                pvVar13 = (void *)0x0;
                                p2 = (void *)0x0;
                              }
                              else {
                                ASN1_STRING_set0(str,local_30,iVar3);
                                local_30 = (ASN1_STRING *)(uint)(iVar3 == 0);
                                pAVar4 = OBJ_nid2obj(0xf5);
                                X509_ALGOR_set0(local_40,pAVar4,0x10,str);
                                pvVar13 = (void *)0x1;
                                p2 = (void *)0x0;
                              }
                            }
                          }
                          goto LAB_001203c0;
                        }
                      }
                      pvVar13 = (void *)0x0;
                      p2 = (void *)0x0;
                    }
                    goto LAB_001203c0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  pvVar13 = (void *)0x0;
  pXVar14 = (X509_ALGOR *)0x0;
  p2 = (void *)0x0;
LAB_001203c0:
  CRYPTO_free(local_30);
  X509_ALGOR_free(pXVar14);
  CRYPTO_free(p2);
  return pvVar13;
}

