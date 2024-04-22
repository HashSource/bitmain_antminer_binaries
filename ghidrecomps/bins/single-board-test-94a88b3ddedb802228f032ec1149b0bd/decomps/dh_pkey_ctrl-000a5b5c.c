
int dh_pkey_ctrl(undefined4 param_1,int param_2,ASN1_STRING *param_3,undefined4 *param_4)

{
  bool bVar1;
  EVP_PKEY_CTX *pEVar2;
  EVP_PKEY *pEVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  EVP_CIPHER_CTX *pEVar7;
  EVP_CIPHER *pEVar8;
  ASN1_TYPE *type;
  size_t sVar9;
  uchar *puVar10;
  void *pvVar11;
  ASN1_STRING *str;
  ASN1_INTEGER *pAVar12;
  EVP_MD *p2;
  char *pcVar13;
  ulong uVar14;
  DH *dh;
  BIGNUM *pBVar15;
  EVP_PKEY *pkey;
  long *plVar16;
  X509_ALGOR *pXVar17;
  int local_44;
  X509_ALGOR *local_40;
  ASN1_OBJECT *local_3c;
  ASN1_STRING *local_38;
  ASN1_OBJECT *local_34;
  ASN1_STRING *local_30;
  EVP_MD *local_2c [2];
  
  if (param_2 != 7) {
    if (param_2 != 8) {
      return -2;
    }
    *param_4 = 1;
    return 1;
  }
  if (param_3 == (ASN1_STRING *)0x1) {
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
      if (local_3c == (ASN1_OBJECT *)0x0) {
        return 0;
      }
      if (local_38 == (ASN1_STRING *)0x0) {
        return 0;
      }
      X509_ALGOR_get0(&local_34,&local_44,&local_30,(X509_ALGOR *)local_3c);
      iVar4 = OBJ_obj2nid(local_34);
      if ((((iVar4 != 0x398) || (local_44 == 5)) ||
          (pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2), pEVar3 == (EVP_PKEY *)0x0)) ||
         (pEVar3->type != 0x398)) goto LAB_000a5e5e;
      pcVar13 = (pEVar3->pkey).ptr;
      dh = DH_new();
      if ((dh != (DH *)0x0) && (iVar4 = int_dh_param_copy(dh,pcVar13,0xffffffff), iVar4 == 0)) {
        DH_free(dh);
        dh = (DH *)0x0;
      }
      iVar4 = ASN1_STRING_length(local_38);
      local_2c[0] = (EVP_MD *)ASN1_STRING_data(local_38);
      if (iVar4 != 0) {
        iVar6 = 1 - (int)local_2c[0];
        if ((EVP_MD *)0x1 < local_2c[0]) {
          iVar6 = 0;
        }
        if (iVar6 == 0) {
          pAVar12 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,(uchar **)local_2c,iVar4);
          if (pAVar12 == (ASN1_INTEGER *)0x0) {
            ERR_put_error(5,0x76,0x68,DAT_000a6074,0x2af);
          }
          else {
            pBVar15 = ASN1_INTEGER_to_BN(pAVar12,(BIGNUM *)0x0);
            *(BIGNUM **)&dh->field_0x14 = pBVar15;
            if (pBVar15 == (BIGNUM *)0x0) {
              ERR_put_error(5,0x76,0x6d,DAT_000a6074,0x2b5);
            }
            else {
              pkey = EVP_PKEY_new();
              if (pkey != (EVP_PKEY *)0x0) {
                EVP_PKEY_assign(pkey,*(int *)pEVar3->ameth,dh);
                iVar4 = EVP_PKEY_derive_set_peer(pEVar2,pkey);
                ASN1_INTEGER_free(pAVar12);
                EVP_PKEY_free(pkey);
                if (iVar4 < 1) goto LAB_000a5e5e;
                goto LAB_000a5d82;
              }
            }
            ASN1_INTEGER_free(pAVar12);
          }
        }
      }
      if (dh != (DH *)0x0) {
        DH_free(dh);
      }
LAB_000a5e5e:
      ERR_put_error(5,0x75,0x71,DAT_000a6074,0x329);
      return 0;
    }
LAB_000a5d82:
    iVar4 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_34,&local_30);
    if (iVar4 == 0) goto LAB_000a5d90;
    iVar4 = OBJ_obj2nid((ASN1_OBJECT *)local_34->sn);
    if (iVar4 != 0xf5) {
      ERR_put_error(5,0x77,0x70,DAT_000a6074,0x2df);
      goto LAB_000a5d90;
    }
    iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1006,2,(void *)0x0);
    if (iVar4 < 1) goto LAB_000a5d90;
    p2 = EVP_sha1();
    iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1007,0,p2);
    if ((iVar4 < 1) || (*local_34->ln != (char *)0x10)) goto LAB_000a5d90;
    plVar16 = (long *)local_34->ln[1];
    local_2c[0] = (EVP_MD *)plVar16[2];
    pXVar17 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)local_2c,*plVar16);
    if (pXVar17 == (X509_ALGOR *)0x0) goto LAB_000a5d90;
    pEVar7 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
    if (pEVar7 == (EVP_CIPHER_CTX *)0x0) {
LAB_000a5f2e:
      bVar1 = false;
    }
    else {
      iVar4 = OBJ_obj2nid(pXVar17->algorithm);
      pcVar13 = OBJ_nid2sn(iVar4);
      pEVar8 = EVP_get_cipherbyname(pcVar13);
      if ((((pEVar8 == (EVP_CIPHER *)0x0) ||
           (uVar14 = EVP_CIPHER_flags(pEVar8), (uVar14 & 0xf0007) != 0x10002)) ||
          (iVar4 = EVP_EncryptInit_ex(pEVar7,pEVar8,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0),
          iVar4 == 0)) || (iVar4 = EVP_CIPHER_asn1_to_param(pEVar7,pXVar17->parameter), iVar4 < 1))
      goto LAB_000a5f2e;
      iVar4 = EVP_CIPHER_CTX_key_length(pEVar7);
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1009,iVar4,(void *)0x0);
      if (iVar4 < 1) goto LAB_000a5f2e;
      iVar4 = EVP_CIPHER_type(pEVar8);
      pAVar5 = OBJ_nid2obj(iVar4);
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x100d,0,pAVar5);
      if (iVar4 < 1) goto LAB_000a5f2e;
      if (local_30 == (ASN1_STRING *)0x0) {
        pvVar11 = (void *)0x0;
        sVar9 = 0;
      }
      else {
        sVar9 = ASN1_STRING_length(local_30);
        puVar10 = ASN1_STRING_data(local_30);
        pvVar11 = BUF_memdup(puVar10,sVar9);
        if (pvVar11 == (void *)0x0) goto LAB_000a5f2e;
      }
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x100b,sVar9,pvVar11);
      if (iVar4 < 1) {
        X509_ALGOR_free(pXVar17);
        if (pvVar11 != (void *)0x0) {
          CRYPTO_free(pvVar11);
        }
        goto LAB_000a5d90;
      }
      bVar1 = true;
    }
    X509_ALGOR_free(pXVar17);
    if (bVar1) {
      return 1;
    }
LAB_000a5d90:
    ERR_put_error(5,0x75,0x72,DAT_000a6074,0x32f);
    return 0;
  }
  if (param_3 != (ASN1_STRING *)0x0) {
    return -2;
  }
  local_30 = param_3;
  pEVar2 = (EVP_PKEY_CTX *)CMS_RecipientInfo_get0_pkey_ctx(param_4);
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    return 0;
  }
  pEVar3 = EVP_PKEY_CTX_get0_pkey(pEVar2);
  iVar4 = CMS_RecipientInfo_kari_get0_orig_id(param_4,&local_40,&local_38,0,0,0);
  if (iVar4 == 0) {
LAB_000a5baa:
    iVar4 = 0;
    pXVar17 = (X509_ALGOR *)0x0;
LAB_000a5bae:
    if (local_30 != (ASN1_STRING *)0x0) goto LAB_000a5bb2;
  }
  else {
    X509_ALGOR_get0(&local_3c,(int *)0x0,(void **)0x0,local_40);
    pAVar5 = OBJ_nid2obj(0);
    if (local_3c == pAVar5) {
      pAVar12 = BN_to_ASN1_INTEGER(((pEVar3->pkey).rsa)->e,(ASN1_INTEGER *)0x0);
      if (pAVar12 != (ASN1_INTEGER *)0x0) {
        iVar4 = i2d_ASN1_INTEGER(pAVar12,(uchar **)&local_30);
        ASN1_INTEGER_free(pAVar12);
        if (0 < iVar4) {
          ASN1_STRING_set0(local_38,local_30,iVar4);
          pXVar17 = local_40;
          local_38->flags = local_38->flags & 0xfffffff0U | 8;
          local_30 = param_3;
          pAVar5 = OBJ_nid2obj(0x398);
          X509_ALGOR_set0(pXVar17,pAVar5,-1,(void *)0x0);
          goto LAB_000a5be2;
        }
      }
      goto LAB_000a5baa;
    }
LAB_000a5be2:
    iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1006,-2,(void *)0x0);
    if ((iVar4 < 1) || (iVar6 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1008,0,local_2c), iVar6 == 0)
       ) goto LAB_000a5baa;
    if (iVar4 == 1) {
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1006,2,(void *)0x0);
      if (0 < iVar4) goto LAB_000a5c28;
      goto LAB_000a5baa;
    }
    if (iVar4 != 2) goto LAB_000a5baa;
LAB_000a5c28:
    if (local_2c[0] == (EVP_MD *)0x0) {
      local_2c[0] = EVP_sha1();
      iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1007,0,local_2c[0]);
      if (0 < iVar4) goto LAB_000a5c3a;
      goto LAB_000a5baa;
    }
    iVar4 = EVP_MD_type(local_2c[0]);
    if (iVar4 != 0x40) goto LAB_000a5baa;
LAB_000a5c3a:
    iVar4 = CMS_RecipientInfo_kari_get0_alg(param_4,&local_40,&local_34);
    if (iVar4 == 0) goto LAB_000a5baa;
    pEVar7 = (EVP_CIPHER_CTX *)CMS_RecipientInfo_kari_get0_ctx(param_4);
    pEVar8 = EVP_CIPHER_CTX_cipher(pEVar7);
    iVar4 = EVP_CIPHER_type(pEVar8);
    pAVar5 = OBJ_nid2obj(iVar4);
    iVar6 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x100d,0,pAVar5);
    if (iVar6 < 1) goto LAB_000a5baa;
    iVar6 = EVP_CIPHER_CTX_key_length(pEVar7);
    pXVar17 = X509_ALGOR_new();
    if (pXVar17 == (X509_ALGOR *)0x0) goto LAB_000a5baa;
    pAVar5 = OBJ_nid2obj(iVar4);
    pXVar17->algorithm = pAVar5;
    type = ASN1_TYPE_new();
    pXVar17->parameter = type;
    if ((type == (ASN1_TYPE *)0x0) || (iVar4 = EVP_CIPHER_param_to_asn1(pEVar7,type), iVar4 < 1)) {
LAB_000a5fce:
      iVar4 = 0;
      goto LAB_000a5bae;
    }
    iVar4 = ASN1_TYPE_get(pXVar17->parameter);
    if (iVar4 == 0) {
      ASN1_TYPE_free(pXVar17->parameter);
      pXVar17->parameter = (ASN1_TYPE *)0x0;
    }
    iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x1009,iVar6,(void *)0x0);
    if (iVar4 < 1) goto LAB_000a5fce;
    if (local_34 == (ASN1_OBJECT *)0x0) {
      pvVar11 = (void *)0x0;
      sVar9 = 0;
    }
    else {
      sVar9 = ASN1_STRING_length((ASN1_STRING *)local_34);
      puVar10 = ASN1_STRING_data((ASN1_STRING *)local_34);
      pvVar11 = BUF_memdup(puVar10,sVar9);
      if (pvVar11 == (void *)0x0) goto LAB_000a5fce;
    }
    iVar4 = EVP_PKEY_CTX_ctrl(pEVar2,0x398,0x400,0x100b,sVar9,pvVar11);
    if (iVar4 < 1) goto LAB_000a5fce;
    local_30 = (ASN1_STRING *)0x0;
    iVar4 = i2d_X509_ALGOR(pXVar17,(uchar **)&local_30);
    if (local_30 == (ASN1_STRING *)0x0) {
      iVar4 = 0;
      goto LAB_000a5bba;
    }
    if (iVar4 != 0) {
      str = ASN1_STRING_new();
      if (str == (ASN1_STRING *)0x0) {
        iVar4 = 0;
      }
      else {
        ASN1_STRING_set0(str,local_30,iVar4);
        local_30 = (ASN1_STRING *)0x0;
        iVar4 = 1;
        pAVar5 = OBJ_nid2obj(0xf5);
        X509_ALGOR_set0(local_40,pAVar5,0x10,str);
      }
      goto LAB_000a5bae;
    }
LAB_000a5bb2:
    CRYPTO_free(local_30);
  }
  if (pXVar17 == (X509_ALGOR *)0x0) {
    return iVar4;
  }
LAB_000a5bba:
  X509_ALGOR_free(pXVar17);
  return iVar4;
}

