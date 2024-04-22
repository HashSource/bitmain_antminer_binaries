
X509_PURPOSE * X509_PURPOSE_get0(int idx)

{
  X509_PURPOSE *pXVar1;
  
  if (idx < 0) {
    return (X509_PURPOSE *)0x0;
  }
  if (idx < 9) {
    return (X509_PURPOSE *)(DAT_000cba48 + idx * 0x1c);
  }
  pXVar1 = (X509_PURPOSE *)sk_value(*DAT_000cba4c,idx + -9);
  return pXVar1;
}

