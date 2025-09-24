
int PKCS12_gen_mac(PKCS12 *p12,char *pass,int passlen,uchar *mac,uint *maclen)

{
  int iVar1;
  int iVar2;
  char *name;
  EVP_MD *md;
  uint uVar3;
  HMAC_CTX *ctx;
  int iVar4;
  uchar *salt;
  PKCS12_MAC_DATA *pPVar5;
  ASN1_OCTET_STRING *pAVar6;
  long iter;
  bool bVar7;
  X509_ALGOR *local_d0;
  ASN1_OBJECT *local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  uchar auStack_88 [64];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar1 = OBJ_obj2nid(p12->authsafes->type);
  if (iVar1 != 0x15) {
    ERR_put_error(0x23,0x6b,0x79,"crypto/pkcs12/p12_mutl.c",0x5c);
    return 0;
  }
  pPVar5 = p12->mac;
  iter = 1;
  salt = pPVar5->salt->data;
  iVar1 = pPVar5->salt->length;
  if (pPVar5->iter != (ASN1_INTEGER *)0x0) {
    iter = ASN1_INTEGER_get(pPVar5->iter);
    pPVar5 = p12->mac;
  }
  X509_SIG_get0(pPVar5->dinfo,&local_d0,0);
  X509_ALGOR_get0(&local_cc,(int *)0x0,(void **)0x0,local_d0);
  iVar2 = OBJ_obj2nid(local_cc);
  name = OBJ_nid2sn(iVar2);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x23,0x6b,0x76,"crypto/pkcs12/p12_mutl.c",0x69);
    return 0;
  }
  iVar2 = EVP_MD_size(md);
  uVar3 = EVP_MD_type(md);
  if (iVar2 < 0) {
    return 0;
  }
  bVar7 = 0x328 < uVar3;
  if (uVar3 != 0x329) {
    bVar7 = uVar3 != 0x3d6;
  }
  if ((bVar7 && (uVar3 != 0x329 && uVar3 != 0x3d7)) ||
     (iVar4 = ossl_safe_getenv("LEGACY_GOST_PKCS12"), iVar4 != 0)) {
    iVar1 = PKCS12_key_gen_utf8(pass,passlen,salt,iVar1,3,iter,iVar2,&local_c8,md);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x6b,0x6b,"crypto/pkcs12/p12_mutl.c",0x7d);
      iVar1 = 0;
      ctx = (HMAC_CTX *)0x0;
      goto LAB_001d56d0;
    }
  }
  else {
    iVar1 = PKCS5_PBKDF2_HMAC(pass,passlen,salt,iVar1,iter,md,0x60,auStack_88);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x6b,0x6b,"crypto/pkcs12/p12_mutl.c",0x77);
      iVar1 = 0;
      ctx = (HMAC_CTX *)0x0;
      goto LAB_001d56d0;
    }
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
  }
  ctx = (HMAC_CTX *)HMAC_CTX_new();
  if (ctx == (HMAC_CTX *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = HMAC_Init_ex(ctx,&local_c8,iVar2,md,(ENGINE *)0x0);
    if (((iVar1 != 0) &&
        (pAVar6 = (p12->authsafes->d).data, iVar1 = HMAC_Update(ctx,pAVar6->data,pAVar6->length),
        iVar1 != 0)) && (iVar1 = HMAC_Final(ctx,mac,maclen), iVar1 != 0)) {
      iVar1 = 1;
    }
  }
LAB_001d56d0:
  OPENSSL_cleanse(&local_c8,0x40);
  HMAC_CTX_free(ctx);
  return iVar1;
}

