
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  bool bVar1;
  BIO *pBVar2;
  int iVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  size_t len;
  ASN1_OBJECT *pAVar6;
  uchar *out;
  void *pvVar7;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  long lVar8;
  ASN1_TYPE *type;
  stack_st_X509 *psVar9;
  PKCS7_SIGN_ENVELOPE *pPVar10;
  pkcs7_st *ppVar11;
  _STACK *p_Var12;
  _STACK *p_Var13;
  BIO *cipher;
  X509_ALGOR *pXVar14;
  _STACK *p_Var15;
  BIO *local_a0;
  _STACK *local_98;
  BIO *local_84;
  EVP_CIPHER_CTX *local_80;
  size_t local_7c;
  uchar auStack_78 [16];
  uchar auStack_68 [68];
  
  local_84 = (BIO *)0x0;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x69,0x8f,DAT_000d00f4,0x109);
    return (BIO *)0x0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x69,0x7a,DAT_000d00f4,0x117);
    return (BIO *)0x0;
  }
  iVar3 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar3) {
  case 0x15:
    p_Var13 = (_STACK *)0x0;
    pXVar14 = (X509_ALGOR *)0x0;
    local_98 = (_STACK *)0x0;
    p_Var12 = (_STACK *)0x0;
    cipher = (BIO *)0x0;
    p_Var15 = (_STACK *)0x0;
    break;
  case 0x16:
    ppVar11 = ((p7->d).sign)->contents;
    p_Var12 = &((p7->d).sign)->md_algs->stack;
    iVar3 = OBJ_obj2nid(ppVar11->type);
    if (iVar3 == 0x15) {
      p_Var13 = (_STACK *)(ppVar11->d).data;
    }
    else {
      iVar3 = OBJ_obj2nid(ppVar11->type);
      if (iVar3 - 0x15U < 6) {
LAB_000cff84:
        p_Var13 = (_STACK *)0x0;
      }
      else {
        p_Var13 = (_STACK *)(ppVar11->d).data;
        if (p_Var13 != (_STACK *)0x0) {
          if (p_Var13->num != 4) goto LAB_000cff84;
          p_Var13 = (_STACK *)p_Var13->data;
        }
      }
    }
    pXVar14 = (X509_ALGOR *)0x0;
    cipher = (BIO *)0x0;
    local_98 = (_STACK *)0x0;
    p_Var15 = (_STACK *)0x0;
    break;
  case 0x17:
    psVar9 = ((p7->d).sign)->cert;
    local_98 = &((p7->d).sign)->md_algs->stack;
    cipher = (BIO *)(psVar9->stack).num_alloc;
    pXVar14 = (X509_ALGOR *)(psVar9->stack).data;
    if (cipher == (BIO *)0x0) {
      iVar3 = 0x132;
      cipher = (BIO *)0x0;
LAB_000d0014:
      ERR_put_error(0x21,0x69,0x74,DAT_000d00f4,iVar3);
      local_a0 = cipher;
      goto LAB_000cff0c;
    }
    p_Var12 = (_STACK *)0x0;
    p_Var15 = (_STACK *)0x0;
    p_Var13 = p_Var12;
    break;
  case 0x18:
    pPVar10 = (p7->d).signed_and_enveloped;
    local_98 = &pPVar10->recipientinfo->stack;
    cipher = (BIO *)pPVar10->enc_data->cipher;
    pXVar14 = pPVar10->enc_data->algorithm;
    p_Var12 = &pPVar10->md_algs->stack;
    iVar3 = 0x129;
    if (cipher == (BIO *)0x0) goto LAB_000d0014;
    p_Var15 = (_STACK *)0x0;
    p_Var13 = p_Var15;
    break;
  case 0x19:
    ppVar11 = ((p7->d).digest)->contents;
    p_Var15 = (_STACK *)((p7->d).digest)->md;
    iVar3 = OBJ_obj2nid(ppVar11->type);
    if (iVar3 == 0x15) {
      p_Var13 = (_STACK *)(ppVar11->d).data;
    }
    else {
      iVar3 = OBJ_obj2nid(ppVar11->type);
      if (iVar3 - 0x15U < 6) {
LAB_000cfd24:
        p_Var13 = (_STACK *)0x0;
      }
      else {
        p_Var13 = (_STACK *)(ppVar11->d).data;
        if (p_Var13 != (_STACK *)0x0) {
          if (p_Var13->num != 4) goto LAB_000cfd24;
          p_Var13 = (_STACK *)p_Var13->data;
        }
      }
    }
    pXVar14 = (X509_ALGOR *)0x0;
    p_Var12 = (_STACK *)0x0;
    cipher = (BIO *)0x0;
    local_98 = (_STACK *)0x0;
    break;
  default:
    ERR_put_error(0x21,0x69,0x70,DAT_000d00f4,0x13d);
    local_a0 = (BIO *)0x0;
    goto LAB_000cff0c;
  }
  iVar3 = 0;
  do {
    iVar4 = sk_num(p_Var12);
    if (iVar4 <= iVar3) {
      if ((p_Var15 == (_STACK *)0x0) ||
         (iVar3 = PKCS7_bio_add_digest(&local_84,p_Var15), iVar3 != 0)) {
        pBVar2 = local_84;
        if (cipher == (BIO *)0x0) goto LAB_000cffb8;
        pBVar5 = BIO_f_cipher();
        local_a0 = BIO_new(pBVar5);
        if (local_a0 == (BIO *)0x0) {
          ERR_put_error(0x21,0x69,0x20,DAT_000d00f4,0x14f);
          goto LAB_000cff0c;
        }
        BIO_ctrl(local_a0,0x81,0,&local_80);
        len = EVP_CIPHER_key_length((EVP_CIPHER *)cipher);
        iVar3 = EVP_CIPHER_iv_length((EVP_CIPHER *)cipher);
        iVar4 = EVP_CIPHER_type((EVP_CIPHER *)cipher);
        pAVar6 = OBJ_nid2obj(iVar4);
        pXVar14->algorithm = pAVar6;
        if ((((0 < iVar3) && (iVar4 = RAND_pseudo_bytes(auStack_78,iVar3), iVar4 < 1)) ||
            (iVar4 = EVP_CipherInit_ex(local_80,(EVP_CIPHER *)cipher,(ENGINE *)0x0,(uchar *)0x0,
                                       (uchar *)0x0,1), iVar4 < 1)) ||
           ((iVar4 = EVP_CIPHER_CTX_rand_key(local_80,auStack_68), iVar4 < 1 ||
            (iVar4 = EVP_CipherInit_ex(local_80,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,
                                       auStack_78,1), iVar4 < 1)))) goto LAB_000cff0c;
        if (0 < iVar3) {
          type = pXVar14->parameter;
          if (type == (ASN1_TYPE *)0x0) {
            type = ASN1_TYPE_new();
            pXVar14->parameter = type;
            if (type == (ASN1_TYPE *)0x0) goto LAB_000cff0c;
          }
          iVar3 = EVP_CIPHER_param_to_asn1(local_80,type);
          if (iVar3 < 0) goto LAB_000cff0c;
        }
        iVar3 = 0;
        goto LAB_000cfeae;
      }
      break;
    }
    pvVar7 = sk_value(p_Var12,iVar3);
    iVar4 = PKCS7_bio_add_digest(&local_84,pvVar7);
    iVar3 = iVar3 + 1;
  } while (iVar4 != 0);
  goto LAB_000cff94;
LAB_000cfeae:
  iVar4 = sk_num(local_98);
  if (iVar4 <= iVar3) goto LAB_000cff9a;
  pvVar7 = sk_value(local_98,iVar3);
  pkey = X509_get_pubkey(*(X509 **)((int)pvVar7 + 0x10));
  if ((pkey == (EVP_PKEY *)0x0) ||
     (ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0), ctx == (EVP_PKEY_CTX *)0x0)) goto LAB_000cff0c;
  iVar4 = EVP_PKEY_encrypt_init(ctx);
  if (iVar4 < 1) {
LAB_000cfee4:
    bVar1 = false;
  }
  else {
    iVar4 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,3,0,pvVar7);
    if (iVar4 < 1) {
      ERR_put_error(0x21,0x84,0x98,DAT_000d00f4,0xa0);
      bVar1 = false;
    }
    else {
      iVar4 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_7c,auStack_68,len);
      if (iVar4 < 1) goto LAB_000cfee4;
      out = (uchar *)CRYPTO_malloc(local_7c,DAT_000d00f4,0xa7);
      if (out == (uchar *)0x0) {
        ERR_put_error(0x21,0x84,0x41,DAT_000d00f4,0xaa);
        bVar1 = false;
      }
      else {
        iVar4 = EVP_PKEY_encrypt(ctx,out,&local_7c,auStack_68,len);
        if (iVar4 < 1) {
          EVP_PKEY_free(pkey);
          EVP_PKEY_CTX_free(ctx);
          CRYPTO_free(out);
          goto LAB_000cff0c;
        }
        bVar1 = true;
        ASN1_STRING_set0(*(ASN1_STRING **)((int)pvVar7 + 0xc),out,local_7c);
      }
    }
  }
  EVP_PKEY_free(pkey);
  EVP_PKEY_CTX_free(ctx);
  if (!bVar1) goto LAB_000cff0c;
  iVar3 = iVar3 + 1;
  goto LAB_000cfeae;
LAB_000cff9a:
  OPENSSL_cleanse(auStack_68,len);
  pBVar2 = local_a0;
  if (local_84 != (BIO *)0x0) {
    BIO_push(local_84,local_a0);
    pBVar2 = local_84;
  }
LAB_000cffb8:
  local_84 = pBVar2;
  if (bio != (BIO *)0x0) goto LAB_000cffbc;
  iVar3 = OBJ_obj2nid(p7->type);
  if ((iVar3 == 0x16) && (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 != 0)) {
    pBVar5 = BIO_s_null();
    bio = BIO_new(pBVar5);
LAB_000d009e:
    if (bio != (BIO *)0x0) goto LAB_000cffbc;
  }
  else if ((p_Var13 != (_STACK *)0x0) && (0 < p_Var13->num)) {
    bio = BIO_new_mem_buf((uchar *)p_Var13->sorted,p_Var13->num);
    goto LAB_000d009e;
  }
  pBVar5 = BIO_s_mem();
  bio = BIO_new(pBVar5);
  if (bio != (BIO *)0x0) {
    BIO_ctrl(bio,0x82,0,(void *)0x0);
LAB_000cffbc:
    if (local_84 == (BIO *)0x0) {
      return bio;
    }
    BIO_push(local_84,bio);
    return local_84;
  }
LAB_000cff94:
  local_a0 = (BIO *)0x0;
LAB_000cff0c:
  if (local_84 != (BIO *)0x0) {
    BIO_free_all(local_84);
  }
  if (local_a0 != (BIO *)0x0) {
    BIO_free_all(local_a0);
  }
  return (BIO *)0x0;
}

