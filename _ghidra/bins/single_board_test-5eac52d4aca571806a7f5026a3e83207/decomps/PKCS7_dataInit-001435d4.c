
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  BIO *pBVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  size_t len;
  ASN1_OBJECT *pAVar6;
  void *p2;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  long lVar7;
  ASN1_TYPE *type;
  stack_st_X509 *psVar8;
  PKCS7_SIGN_ENVELOPE *pPVar9;
  PKCS7_SIGNED *pPVar10;
  pkcs7_st *ppVar11;
  EVP_CIPHER *pEVar12;
  EVP_CIPHER *pEVar13;
  EVP_CIPHER *pEVar14;
  EVP_CIPHER *cipher;
  ASN1_OCTET_STRING *pAVar15;
  uchar *out;
  BIO *local_a4;
  BIO *local_a0;
  BIO *local_84;
  EVP_CIPHER_CTX *local_80;
  size_t local_7c;
  uchar auStack_78 [16];
  uchar auStack_68 [68];
  
  local_84 = (BIO *)0x0;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x69,0x8f,"crypto/pkcs7/pk7_doit.c",0xd1);
    return (BIO *)0x0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x69,0x7a,"crypto/pkcs7/pk7_doit.c",0xdf);
    return (BIO *)0x0;
  }
  iVar2 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar2) {
  case 0x15:
    pAVar15 = (ASN1_OCTET_STRING *)0x0;
    pEVar12 = (EVP_CIPHER *)0x0;
    pEVar14 = (EVP_CIPHER *)0x0;
    pEVar13 = (EVP_CIPHER *)0x0;
    cipher = (EVP_CIPHER *)0x0;
    local_a4 = (BIO *)0x0;
    break;
  case 0x16:
    ppVar11 = ((p7->d).sign)->contents;
    pEVar13 = (EVP_CIPHER *)((p7->d).sign)->md_algs;
    iVar2 = OBJ_obj2nid(ppVar11->type);
    if (iVar2 == 0x15) {
      pEVar12 = (EVP_CIPHER *)0x0;
      pAVar15 = (ppVar11->d).data;
      pEVar14 = (EVP_CIPHER *)0x0;
      cipher = (EVP_CIPHER *)0x0;
      local_a4 = (BIO *)0x0;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar11->type);
      if (iVar2 - 0x15U < 6) {
LAB_00143818:
        pAVar15 = (ASN1_OCTET_STRING *)0x0;
        pEVar12 = (EVP_CIPHER *)0x0;
        pEVar14 = (EVP_CIPHER *)0x0;
        cipher = (EVP_CIPHER *)0x0;
        local_a4 = (BIO *)0x0;
      }
      else {
        pPVar10 = (ppVar11->d).sign;
        if (pPVar10 == (PKCS7_SIGNED *)0x0) {
          cipher = (EVP_CIPHER *)0x0;
          pEVar12 = (EVP_CIPHER *)0x0;
          pEVar14 = (EVP_CIPHER *)0x0;
          pAVar15 = (ASN1_OCTET_STRING *)0x0;
          local_a4 = (BIO *)0x0;
        }
        else {
          if (pPVar10->version != (ASN1_INTEGER *)0x4) goto LAB_00143818;
          pEVar12 = (EVP_CIPHER *)0x0;
          pAVar15 = (ASN1_OCTET_STRING *)pPVar10->md_algs;
          pEVar14 = (EVP_CIPHER *)0x0;
          cipher = (EVP_CIPHER *)0x0;
          local_a4 = (BIO *)0x0;
        }
      }
    }
    break;
  case 0x17:
    psVar8 = ((p7->d).sign)->cert;
    pEVar14 = (EVP_CIPHER *)((p7->d).sign)->md_algs;
    cipher = (EVP_CIPHER *)(psVar8->stack).num_alloc;
    pEVar12 = (EVP_CIPHER *)(psVar8->stack).data;
    if (cipher == (EVP_CIPHER *)0x0) {
      iVar2 = 0xfa;
LAB_00143a46:
      local_a4 = (BIO *)0x0;
      ERR_put_error(0x21,0x69,0x74,"crypto/pkcs7/pk7_doit.c",iVar2);
      goto LAB_001437e4;
    }
    pAVar15 = (ASN1_OCTET_STRING *)0x0;
    pEVar13 = (EVP_CIPHER *)0x0;
    local_a4 = (BIO *)0x0;
    break;
  case 0x18:
    pPVar9 = (p7->d).signed_and_enveloped;
    pEVar14 = (EVP_CIPHER *)pPVar9->recipientinfo;
    pEVar13 = (EVP_CIPHER *)pPVar9->md_algs;
    cipher = pPVar9->enc_data->cipher;
    pEVar12 = (EVP_CIPHER *)pPVar9->enc_data->algorithm;
    if (cipher == (EVP_CIPHER *)0x0) {
      iVar2 = 0xf1;
      goto LAB_00143a46;
    }
    pAVar15 = (ASN1_OCTET_STRING *)0x0;
    local_a4 = (BIO *)0x0;
    break;
  case 0x19:
    ppVar11 = ((p7->d).digest)->contents;
    local_a4 = (BIO *)((p7->d).digest)->md;
    iVar2 = OBJ_obj2nid(ppVar11->type);
    if (iVar2 == 0x15) {
      pEVar12 = (EVP_CIPHER *)0x0;
      pAVar15 = (ppVar11->d).data;
      pEVar14 = (EVP_CIPHER *)0x0;
      pEVar13 = (EVP_CIPHER *)0x0;
      cipher = (EVP_CIPHER *)0x0;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar11->type);
      if (iVar2 - 0x15U < 6) {
LAB_00143882:
        pAVar15 = (ASN1_OCTET_STRING *)0x0;
        cipher = (EVP_CIPHER *)0x0;
        pEVar12 = cipher;
        pEVar13 = cipher;
        pEVar14 = cipher;
      }
      else {
        pPVar10 = (ppVar11->d).sign;
        if (pPVar10 == (PKCS7_SIGNED *)0x0) {
          cipher = (EVP_CIPHER *)0x0;
          pEVar12 = (EVP_CIPHER *)0x0;
          pEVar13 = (EVP_CIPHER *)0x0;
          pEVar14 = (EVP_CIPHER *)0x0;
          pAVar15 = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          if (pPVar10->version != (ASN1_INTEGER *)0x4) goto LAB_00143882;
          pEVar12 = (EVP_CIPHER *)0x0;
          pAVar15 = (ASN1_OCTET_STRING *)pPVar10->md_algs;
          pEVar14 = (EVP_CIPHER *)0x0;
          pEVar13 = (EVP_CIPHER *)0x0;
          cipher = (EVP_CIPHER *)0x0;
        }
      }
    }
    break;
  default:
    ERR_put_error(0x21,0x69,0x70,"crypto/pkcs7/pk7_doit.c",0x105);
    local_a4 = (BIO *)0x0;
    goto LAB_001437e4;
  }
  iVar2 = 0;
  do {
    iVar4 = OPENSSL_sk_num(pEVar13);
    if (iVar4 <= iVar2) {
      if ((local_a4 == (BIO *)0x0) ||
         (iVar2 = PKCS7_bio_add_digest_isra_2(&local_84,local_a4), iVar2 != 0)) {
        pBVar1 = local_84;
        if (cipher == (EVP_CIPHER *)0x0) goto LAB_001438dc;
        pBVar5 = BIO_f_cipher();
        local_a4 = BIO_new(pBVar5);
        if (local_a4 == (BIO *)0x0) {
          ERR_put_error(0x21,0x69,0x20,"crypto/pkcs7/pk7_doit.c",0x117);
          goto LAB_001437e4;
        }
        BIO_ctrl(local_a4,0x81,0,&local_80);
        len = EVP_CIPHER_key_length(cipher);
        iVar2 = EVP_CIPHER_iv_length(cipher);
        iVar4 = EVP_CIPHER_type(cipher);
        pAVar6 = OBJ_nid2obj(iVar4);
        ((_STACK *)&pEVar12->nid)->num = (int)pAVar6;
        if (((0 < iVar2) && (iVar4 = RAND_bytes(auStack_78,iVar2), iVar4 < 1)) ||
           (iVar4 = EVP_CipherInit_ex(local_80,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1),
           iVar4 < 1)) goto LAB_001437e4;
        iVar4 = EVP_CIPHER_CTX_rand_key(local_80,auStack_68);
        if ((iVar4 < 1) ||
           (iVar4 = EVP_CipherInit_ex(local_80,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,auStack_78
                                      ,1), iVar4 < 1)) goto LAB_001437e4;
        if (0 < iVar2) {
          type = (ASN1_TYPE *)pEVar12->block_size;
          if (type == (ASN1_TYPE *)0x0) {
            type = ASN1_TYPE_new();
            pEVar12->block_size = (int)type;
            if (type == (ASN1_TYPE *)0x0) goto LAB_001437e4;
          }
          iVar2 = EVP_CIPHER_param_to_asn1(local_80,type);
          if (iVar2 < 0) goto LAB_001437e4;
        }
        iVar2 = 0;
        goto LAB_00143790;
      }
      break;
    }
    uVar3 = OPENSSL_sk_value(pEVar13,iVar2);
    iVar4 = PKCS7_bio_add_digest_isra_2(&local_84,uVar3);
    iVar2 = iVar2 + 1;
  } while (iVar4 != 0);
  goto LAB_001438bc;
LAB_00143790:
  iVar4 = OPENSSL_sk_num(pEVar14);
  if (iVar4 <= iVar2) goto LAB_001438c2;
  p2 = (void *)OPENSSL_sk_value(pEVar14,iVar2);
  pkey = (EVP_PKEY *)X509_get0_pubkey(*(undefined4 *)((int)p2 + 0x10));
  if ((pkey == (EVP_PKEY *)0x0) ||
     (ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0), ctx == (EVP_PKEY_CTX *)0x0)) goto LAB_001437e4;
  iVar4 = EVP_PKEY_encrypt_init(ctx);
  if (iVar4 < 1) {
LAB_001437ce:
    out = (uchar *)0x0;
LAB_001437d2:
    EVP_PKEY_CTX_free(ctx);
    CRYPTO_free(out);
    goto LAB_001437e4;
  }
  iVar4 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,3,0,p2);
  if (iVar4 < 1) {
    out = (uchar *)0x0;
    ERR_put_error(0x21,0x84,0x98,"crypto/pkcs7/pk7_doit.c",0x6e);
    goto LAB_001437d2;
  }
  iVar4 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_7c,auStack_68,len);
  if (iVar4 < 1) goto LAB_001437ce;
  iVar2 = iVar2 + 1;
  out = (uchar *)CRYPTO_malloc(local_7c,"crypto/pkcs7/pk7_doit.c",0x75);
  if (out == (uchar *)0x0) {
    ERR_put_error(0x21,0x84,0x41,"crypto/pkcs7/pk7_doit.c",0x78);
    goto LAB_001437d2;
  }
  iVar4 = EVP_PKEY_encrypt(ctx,out,&local_7c,auStack_68,len);
  if (iVar4 < 1) goto LAB_001437d2;
  ASN1_STRING_set0(*(ASN1_STRING **)((int)p2 + 0xc),out,local_7c);
  EVP_PKEY_CTX_free(ctx);
  CRYPTO_free((void *)0x0);
  goto LAB_00143790;
LAB_001438c2:
  OPENSSL_cleanse(auStack_68,len);
  pBVar1 = local_a4;
  if (local_84 != (BIO *)0x0) {
    BIO_push(local_84,local_a4);
    pBVar1 = local_84;
  }
LAB_001438dc:
  local_84 = pBVar1;
  local_a0 = bio;
  if (bio != (BIO *)0x0) goto LAB_001438e2;
  iVar2 = OBJ_obj2nid(p7->type);
  if ((iVar2 == 0x16) && (lVar7 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar7 != 0)) {
    pBVar5 = BIO_s_null();
    local_a0 = BIO_new(pBVar5);
  }
  else {
    if ((pAVar15 == (ASN1_OCTET_STRING *)0x0) ||
       (iVar2 = ((_STACK *)&pAVar15->length)->num, iVar2 < 1)) {
      pBVar5 = BIO_s_mem();
      local_a0 = BIO_new(pBVar5);
      if (local_a0 != (BIO *)0x0) {
        BIO_ctrl(local_a0,0x82,0,(void *)0x0);
        goto LAB_001438e2;
      }
      goto LAB_001438bc;
    }
    local_a0 = BIO_new_mem_buf(pAVar15->data,iVar2);
  }
  if (local_a0 != (BIO *)0x0) {
LAB_001438e2:
    if (local_84 != (BIO *)0x0) {
      BIO_push(local_84,local_a0);
      return local_84;
    }
    return local_a0;
  }
LAB_001438bc:
  local_a4 = (BIO *)0x0;
LAB_001437e4:
  BIO_free_all(local_84);
  BIO_free_all(local_a4);
  return (BIO *)0x0;
}

