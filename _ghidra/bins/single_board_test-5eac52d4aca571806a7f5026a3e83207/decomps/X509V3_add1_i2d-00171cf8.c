
int X509V3_add1_i2d(stack_st_X509_EXTENSION **x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  X509_EXTENSION *a;
  uint uVar3;
  stack_st_X509_EXTENSION *psVar4;
  
  uVar3 = flags & 0xf;
  if (uVar3 != 1) {
    iVar1 = X509v3_get_ext_by_NID(*x,nid,-1);
    if (-1 < iVar1) {
      if (uVar3 == 4) {
        return 1;
      }
      if (uVar3 == 0) {
        iVar1 = 0x91;
        goto LAB_00171d28;
      }
      if (uVar3 == 5) {
        pXVar2 = (X509_EXTENSION *)OPENSSL_sk_delete(*x,iVar1);
        if (pXVar2 == (X509_EXTENSION *)0x0) {
          return -1;
        }
        X509_EXTENSION_free(pXVar2);
        return 1;
      }
      pXVar2 = X509V3_EXT_i2d(nid,crit,value);
      if (pXVar2 != (X509_EXTENSION *)0x0) {
        a = (X509_EXTENSION *)OPENSSL_sk_value(*x,iVar1);
        X509_EXTENSION_free(a);
        iVar1 = OPENSSL_sk_set(*x,iVar1,pXVar2);
        if (iVar1 == 0) {
          return -1;
        }
        return 1;
      }
      goto LAB_00171dac;
    }
    if ((uVar3 - 3 & 0xfffffffd) == 0) {
      iVar1 = 0x66;
LAB_00171d28:
      if ((flags & 0x10) == 0) {
        ERR_put_error(0x22,0x8c,iVar1,"crypto/x509v3/v3_lib.c",0x12f);
        return 0;
      }
      return 0;
    }
  }
  pXVar2 = X509V3_EXT_i2d(nid,crit,value);
  if (pXVar2 != (X509_EXTENSION *)0x0) {
    psVar4 = *x;
    if (((psVar4 != (stack_st_X509_EXTENSION *)0x0) ||
        (psVar4 = (stack_st_X509_EXTENSION *)OPENSSL_sk_new_null(),
        psVar4 != (stack_st_X509_EXTENSION *)0x0)) &&
       (iVar1 = OPENSSL_sk_push(psVar4,pXVar2), iVar1 != 0)) {
      *x = psVar4;
      return 1;
    }
    if (psVar4 != *x) {
      OPENSSL_sk_free(psVar4);
    }
    X509_EXTENSION_free(pXVar2);
    return -1;
  }
LAB_00171dac:
  ERR_put_error(0x22,0x8c,0x90,"crypto/x509v3/v3_lib.c",0x10f);
  return 0;
}

