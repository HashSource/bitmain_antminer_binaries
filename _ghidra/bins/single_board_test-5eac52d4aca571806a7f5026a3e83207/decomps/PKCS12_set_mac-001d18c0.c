
int PKCS12_set_mac(PKCS12 *p12,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  EVP_MD *md_type)

{
  int iVar1;
  int iVar2;
  char *name;
  EVP_MD *md;
  uint uVar3;
  HMAC_CTX *ctx;
  int iVar4;
  uchar *salt_00;
  PKCS12_MAC_DATA *pPVar5;
  ASN1_OCTET_STRING *pAVar6;
  long iter_00;
  bool bVar7;
  uint local_d4;
  X509_ALGOR *local_d0;
  ASN1_OBJECT *local_cc;
  ASN1_STRING *local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  uchar auStack_88 [64];
  ASN1_STRING *local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if (md_type == (EVP_MD *)0x0) {
    md_type = EVP_sha1();
  }
  iVar1 = PKCS12_setup_mac(p12,iter,salt,saltlen,md_type);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x7b,0x6e,"crypto/pkcs12/p12_mutl.c",0xba);
    return 0;
  }
  iVar1 = OBJ_obj2nid(p12->authsafes->type);
  if (iVar1 != 0x15) {
    ERR_put_error(0x23,0x6b,0x79,"crypto/pkcs12/p12_mutl.c",0x5c);
    goto LAB_001d19c4;
  }
  pPVar5 = p12->mac;
  iter_00 = 1;
  salt_00 = pPVar5->salt->data;
  iVar1 = pPVar5->salt->length;
  if (pPVar5->iter != (ASN1_INTEGER *)0x0) {
    iter_00 = ASN1_INTEGER_get(pPVar5->iter);
    pPVar5 = p12->mac;
  }
  X509_SIG_get0(pPVar5->dinfo,&local_d0,0);
  X509_ALGOR_get0(&local_cc,(int *)0x0,(void **)0x0,local_d0);
  iVar2 = OBJ_obj2nid(local_cc);
  name = OBJ_nid2sn(iVar2);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x23,0x6b,0x76,"crypto/pkcs12/p12_mutl.c",0x69);
    goto LAB_001d19c4;
  }
  iVar2 = EVP_MD_size(md);
  uVar3 = EVP_MD_type(md);
  if (iVar2 < 0) goto LAB_001d19c4;
  bVar7 = 0x328 < uVar3;
  if (uVar3 != 0x329) {
    bVar7 = uVar3 != 0x3d6;
  }
  if ((bVar7 && (uVar3 != 0x329 && uVar3 != 0x3d7)) ||
     (iVar4 = ossl_safe_getenv("LEGACY_GOST_PKCS12"), iVar4 != 0)) {
    iVar1 = PKCS12_key_gen_utf8(pass,passlen,salt_00,iVar1,3,iter_00,iVar2,&local_c8,md);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x6b,0x6b,"crypto/pkcs12/p12_mutl.c",0x7d);
      ctx = (HMAC_CTX *)0x0;
    }
    else {
LAB_001d1988:
      ctx = (HMAC_CTX *)HMAC_CTX_new();
      if (ctx != (HMAC_CTX *)0x0) {
        iVar1 = HMAC_Init_ex(ctx,&local_c8,iVar2,md,(ENGINE *)0x0);
        if ((iVar1 != 0) &&
           (pAVar6 = (p12->authsafes->d).data, iVar1 = HMAC_Update(ctx,pAVar6->data,pAVar6->length),
           iVar1 != 0)) {
          iVar1 = HMAC_Final(ctx,auStack_88,&local_d4);
          OPENSSL_cleanse(&local_c8,0x40);
          HMAC_CTX_free(ctx);
          if (iVar1 != 0) {
            X509_SIG_getm(p12->mac->dinfo,0,&local_c8);
            iVar1 = ASN1_OCTET_STRING_set(local_c8,auStack_88,local_d4);
            if (iVar1 != 0) {
              return 1;
            }
            ERR_put_error(0x23,0x7b,0x6f,"crypto/pkcs12/p12_mutl.c",199);
            return 0;
          }
          goto LAB_001d19c4;
        }
      }
    }
  }
  else {
    iVar1 = PKCS5_PBKDF2_HMAC(pass,passlen,salt_00,iVar1,iter_00,md,0x60,auStack_88);
    if (iVar1 != 0) {
      iVar2 = 0x20;
      local_c8 = local_48;
      uStack_c4 = uStack_44;
      uStack_c0 = uStack_40;
      uStack_bc = uStack_3c;
      local_b8 = local_38;
      uStack_b4 = uStack_34;
      uStack_b0 = uStack_30;
      uStack_ac = uStack_2c;
      OPENSSL_cleanse(auStack_88,0x60);
      goto LAB_001d1988;
    }
    ERR_put_error(0x23,0x6b,0x6b,"crypto/pkcs12/p12_mutl.c",0x77);
    ctx = (HMAC_CTX *)0x0;
  }
  OPENSSL_cleanse(&local_c8,0x40);
  HMAC_CTX_free(ctx);
LAB_001d19c4:
  ERR_put_error(0x23,0x7b,0x6d,"crypto/pkcs12/p12_mutl.c",0xc2);
  return 0;
}

