
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  int iVar1;
  X509_TRUST *pXVar2;
  char *pcVar3;
  int *ptr;
  int iVar4;
  uint uVar5;
  
  uVar5 = flags & 0xfffffffeU | 2;
  iVar1 = X509_TRUST_get_by_id(id);
  if (iVar1 == -1) {
    ptr = (int *)CRYPTO_malloc(0x18,"crypto/x509/x509_trs.c",0x8a);
    iVar1 = 0x8b;
    if (ptr != (int *)0x0) {
      ptr[1] = 1;
      pcVar3 = CRYPTO_strdup(name,"crypto/x509/x509_trs.c",0x96);
      ptr[3] = (int)pcVar3;
      if (pcVar3 == (char *)0x0) {
        iVar1 = 0x97;
      }
      else {
        *ptr = id;
        iVar4 = trtable;
        ptr[4] = arg1;
        ptr[2] = (int)ck;
        ptr[1] = ptr[1] & 1U | uVar5;
        ptr[5] = (int)arg2;
        if (iVar4 == 0) {
          iVar4 = OPENSSL_sk_new(0x1c68bd);
          iVar1 = 0xa8;
          trtable = iVar4;
          if (iVar4 == 0) goto LAB_001c6c22;
        }
        iVar1 = OPENSSL_sk_push(iVar4,ptr);
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = 0xac;
      }
LAB_001c6c22:
      ERR_put_error(0xb,0x85,0x41,"crypto/x509/x509_trs.c",iVar1);
      CRYPTO_free((void *)ptr[3]);
      CRYPTO_free(ptr);
      return 0;
    }
  }
  else {
    pXVar2 = X509_TRUST_get0(iVar1);
    if (pXVar2->flags << 0x1e < 0) {
      CRYPTO_free(pXVar2->name);
    }
    pcVar3 = CRYPTO_strdup(name,"crypto/x509/x509_trs.c",0x96);
    pXVar2->name = pcVar3;
    if (pcVar3 != (char *)0x0) {
      pXVar2->trust = id;
      pXVar2->arg1 = arg1;
      pXVar2->check_trust = (_func_1956 *)ck;
      pXVar2->flags = pXVar2->flags & 1U | uVar5;
      pXVar2->arg2 = arg2;
      return 1;
    }
    iVar1 = 0x97;
    ptr = (int *)0x0;
  }
  ERR_put_error(0xb,0x85,0x41,"crypto/x509/x509_trs.c",iVar1);
  return (int)ptr;
}

