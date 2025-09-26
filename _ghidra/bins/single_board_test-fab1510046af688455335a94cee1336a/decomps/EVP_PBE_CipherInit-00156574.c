
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  EVP_CIPHER *pEVar4;
  EVP_MD *pEVar5;
  int n;
  code *pcVar6;
  undefined4 local_70;
  int local_6c;
  
  iVar1 = OBJ_obj2nid(pbe_obj);
  if (iVar1 != 0) {
    local_70 = 0;
    local_6c = iVar1;
    if ((((pbe_algs != (_STACK *)0x0) && (iVar1 = sk_find(pbe_algs,&local_70), iVar1 != -1)) &&
        (pvVar2 = sk_value(pbe_algs,iVar1), pvVar2 != (void *)0x0)) ||
       (pvVar2 = OBJ_bsearch_(&local_70,&builtin_pbe,0x15,0x14,(cmp *)0x156545),
       pvVar2 != (void *)0x0)) {
      iVar1 = *(int *)((int)pvVar2 + 8);
      n = *(int *)((int)pvVar2 + 0xc);
      pcVar6 = *(code **)((int)pvVar2 + 0x10);
      if (pass == (char *)0x0) {
        passlen = 0;
      }
      else if (passlen == -1) {
        passlen = strlen(pass);
      }
      if (iVar1 == -1) {
        pEVar4 = (EVP_CIPHER *)0x0;
      }
      else {
        pcVar3 = OBJ_nid2sn(iVar1);
        pEVar4 = EVP_get_cipherbyname(pcVar3);
        if (pEVar4 == (EVP_CIPHER *)0x0) {
          ERR_put_error(6,0x74,0xa0,"evp_pbe.c",0xb5);
          return 0;
        }
      }
      if (n == -1) {
        pEVar5 = (EVP_MD *)0x0;
      }
      else {
        pcVar3 = OBJ_nid2sn(n);
        pEVar5 = EVP_get_digestbyname(pcVar3);
        if (pEVar5 == (EVP_MD *)0x0) {
          ERR_put_error(6,0x74,0xa1,"evp_pbe.c",0xbf);
          return 0;
        }
      }
      iVar1 = (*pcVar6)(ctx,pass,passlen,param,pEVar4,pEVar5,en_de);
      if (iVar1 == 0) {
        ERR_put_error(6,0x74,0x78,"evp_pbe.c",0xc5);
      }
      return (uint)(iVar1 != 0);
    }
  }
  ERR_put_error(6,0x74,0x79,"evp_pbe.c",0xa2);
  if (pbe_obj == (ASN1_OBJECT *)0x0) {
    BUF_strlcpy((char *)&local_70,"NULL",0x50);
  }
  else {
    i2t_ASN1_OBJECT((char *)&local_70,0x50,pbe_obj);
  }
  ERR_add_error_data(2,&DAT_00213d08,&local_70);
  return 0;
}

