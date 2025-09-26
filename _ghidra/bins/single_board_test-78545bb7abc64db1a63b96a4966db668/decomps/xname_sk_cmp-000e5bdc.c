
int xname_sk_cmp(undefined4 *param_1,undefined4 *param_2)

{
  uchar *ptr;
  uint __n;
  uint uVar1;
  int iVar2;
  X509_NAME *a;
  uchar *local_18;
  uchar *local_14;
  
  a = (X509_NAME *)*param_2;
  local_18 = (uchar *)0x0;
  local_14 = (uchar *)0x0;
  __n = i2d_X509_NAME((X509_NAME *)*param_1,&local_18);
  uVar1 = i2d_X509_NAME(a,&local_14);
  ptr = local_18;
  if ((int)(__n | uVar1) < 0) {
    iVar2 = -2;
  }
  else if (__n == uVar1) {
    iVar2 = memcmp(local_18,local_14,__n);
  }
  else {
    iVar2 = __n - uVar1;
  }
  CRYPTO_free(ptr);
  CRYPTO_free(local_14);
  return iVar2;
}

