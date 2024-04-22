
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  _STACK **pp_Var1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  EVP_CIPHER *pEVar5;
  EVP_MD *pEVar6;
  int n;
  code *pcVar7;
  undefined4 local_70;
  int local_6c;
  
  iVar2 = OBJ_obj2nid(pbe_obj);
  pp_Var1 = DAT_000b2f0c;
  if (iVar2 != 0) {
    local_70 = 0;
    local_6c = iVar2;
    if ((((*DAT_000b2f0c != (_STACK *)0x0) &&
         (iVar2 = sk_find(*DAT_000b2f0c,&local_70), iVar2 != -1)) &&
        (pvVar3 = sk_value(*pp_Var1,iVar2), pvVar3 != (void *)0x0)) ||
       (pvVar3 = OBJ_bsearch_(&local_70,DAT_000b2f14,0x15,0x14,DAT_000b2f10), pvVar3 != (void *)0x0)
       ) {
      iVar2 = *(int *)((int)pvVar3 + 8);
      n = *(int *)((int)pvVar3 + 0xc);
      pcVar7 = *(code **)((int)pvVar3 + 0x10);
      if (pass == (char *)0x0) {
        passlen = 0;
      }
      else if (passlen == -1) {
        passlen = strlen(pass);
      }
      if (iVar2 == -1) {
        pEVar5 = (EVP_CIPHER *)0x0;
      }
      else {
        pcVar4 = OBJ_nid2sn(iVar2);
        pEVar5 = EVP_get_cipherbyname(pcVar4);
        if (pEVar5 == (EVP_CIPHER *)0x0) {
          ERR_put_error(6,0x74,0xa0,DAT_000b2f18,0xb5);
          return 0;
        }
      }
      if (n == -1) {
        pEVar6 = (EVP_MD *)0x0;
      }
      else {
        pcVar4 = OBJ_nid2sn(n);
        pEVar6 = EVP_get_digestbyname(pcVar4);
        if (pEVar6 == (EVP_MD *)0x0) {
          ERR_put_error(6,0x74,0xa1,DAT_000b2f18,0xbf);
          return 0;
        }
      }
      iVar2 = (*pcVar7)(ctx,pass,passlen,param,pEVar5,pEVar6,en_de);
      if (iVar2 == 0) {
        ERR_put_error(6,0x74,0x78,DAT_000b2f18,0xc5);
      }
      return (uint)(iVar2 != 0);
    }
  }
  ERR_put_error(6,0x74,0x79,DAT_000b2f18,0xa2);
  if (pbe_obj == (ASN1_OBJECT *)0x0) {
    BUF_strlcpy((char *)&local_70,DAT_000b2f20,0x50);
  }
  else {
    i2t_ASN1_OBJECT((char *)&local_70,0x50,pbe_obj);
  }
  ERR_add_error_data(2,DAT_000b2f1c,&local_70);
  return 0;
}

