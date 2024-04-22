
X509_TRUST * X509_TRUST_get0(int idx)

{
  X509_TRUST *pXVar1;
  
  if (idx < 0) {
    return (X509_TRUST *)0x0;
  }
  if (idx < 8) {
    return (X509_TRUST *)(DAT_000c50e8 + idx * 0x18);
  }
  pXVar1 = (X509_TRUST *)sk_value(*DAT_000c50ec,idx + -8);
  return pXVar1;
}

