
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  int iVar1;
  char *pcVar2;
  EVP_CIPHER *pEVar3;
  EVP_MD *pEVar4;
  int local_74;
  int local_70;
  code *local_6c;
  char acStack_68 [80];
  
  iVar1 = OBJ_obj2nid(pbe_obj);
  iVar1 = EVP_PBE_find(0,iVar1,&local_74,&local_70,&local_6c);
  if (iVar1 == 0) {
    ERR_put_error(6,0x74,0x79,"crypto/evp/evp_pbe.c",0x5f);
    if (pbe_obj == (ASN1_OBJECT *)0x0) {
      OPENSSL_strlcpy(acStack_68,"NULL",0x50);
    }
    else {
      i2t_ASN1_OBJECT(acStack_68,0x50,pbe_obj);
    }
    ERR_add_error_data(2,&DAT_0021b6bc,acStack_68);
    return 0;
  }
  if (pass == (char *)0x0) {
    passlen = 0;
    if (local_74 != -1) goto LAB_001bfc70;
    passlen = 0;
  }
  else {
    if (passlen == -1) {
      passlen = strlen(pass);
    }
    if (local_74 != -1) {
LAB_001bfc70:
      pcVar2 = OBJ_nid2sn(local_74);
      pEVar3 = EVP_get_cipherbyname(pcVar2);
      if (pEVar3 == (EVP_CIPHER *)0x0) {
        ERR_put_error(6,0x74,0xa0,"crypto/evp/evp_pbe.c",0x72);
        return 0;
      }
      goto joined_r0x001bfcbe;
    }
  }
  pEVar3 = (EVP_CIPHER *)0x0;
joined_r0x001bfcbe:
  if (local_70 == -1) {
    pEVar4 = (EVP_MD *)0x0;
  }
  else {
    pcVar2 = OBJ_nid2sn(local_70);
    pEVar4 = EVP_get_digestbyname(pcVar2);
    if (pEVar4 == (EVP_MD *)0x0) {
      ERR_put_error(6,0x74,0xa1,"crypto/evp/evp_pbe.c",0x7c);
      return 0;
    }
  }
  iVar1 = (*local_6c)(ctx,pass,passlen,param,pEVar3,pEVar4,en_de);
  if (iVar1 == 0) {
    ERR_put_error(6,0x74,0x78,"crypto/evp/evp_pbe.c",0x82);
    return 0;
  }
  return 1;
}

