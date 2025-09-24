
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  char *pcVar3;
  int *ptr;
  int iVar4;
  
  iVar1 = X509_PURPOSE_get_by_id(id);
  if (iVar1 != -1) {
    pXVar2 = X509_PURPOSE_get0(iVar1);
    if (pXVar2->flags << 0x1e < 0) {
      CRYPTO_free(pXVar2->name);
      CRYPTO_free(pXVar2->sname);
    }
    pcVar3 = CRYPTO_strdup(name,"crypto/x509v3/v3_purp.c",0xb6);
    pXVar2->name = pcVar3;
    pcVar3 = CRYPTO_strdup(sname,"crypto/x509v3/v3_purp.c",0xb7);
    pXVar2->sname = pcVar3;
    if (pcVar3 != (char *)0x0 && pXVar2->name != (char *)0x0) {
      pXVar2->purpose = id;
      pXVar2->trust = trust;
      pXVar2->check_purpose = (_func_4299 *)ck;
      pXVar2->usr_data = arg;
      pXVar2->flags = pXVar2->flags & 1U | 2 | flags & 0xfffffffeU;
      return 1;
    }
    ERR_put_error(0x22,0x89,0x41,"crypto/x509v3/v3_purp.c",0xb9);
    return 0;
  }
  ptr = (int *)CRYPTO_malloc(0x1c,"crypto/x509v3/v3_purp.c",0xa8);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x22,0x89,0x41,"crypto/x509v3/v3_purp.c",0xa9);
    return 0;
  }
  ptr[2] = 1;
  pcVar3 = CRYPTO_strdup(name,"crypto/x509v3/v3_purp.c",0xb6);
  ptr[4] = (int)pcVar3;
  pcVar3 = CRYPTO_strdup(sname,"crypto/x509v3/v3_purp.c",0xb7);
  ptr[5] = (int)pcVar3;
  if (pcVar3 == (char *)0x0 || ptr[4] == 0) {
    iVar1 = 0xb9;
  }
  else {
    *ptr = id;
    iVar4 = xptable;
    ptr[1] = trust;
    ptr[3] = (int)ck;
    ptr[6] = (int)arg;
    ptr[2] = ptr[2] & 1U | 2 | flags & 0xfffffffeU;
    if (iVar4 == 0) {
      iVar4 = OPENSSL_sk_new(0x177bc9);
      iVar1 = 0xca;
      xptable = iVar4;
      if (iVar4 == 0) goto LAB_0017822e;
    }
    iVar1 = OPENSSL_sk_push(iVar4,ptr);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = 0xce;
  }
LAB_0017822e:
  ERR_put_error(0x22,0x89,0x41,"crypto/x509v3/v3_purp.c",iVar1);
  CRYPTO_free((void *)ptr[4]);
  CRYPTO_free((void *)ptr[5]);
  CRYPTO_free(ptr);
  return 0;
}

