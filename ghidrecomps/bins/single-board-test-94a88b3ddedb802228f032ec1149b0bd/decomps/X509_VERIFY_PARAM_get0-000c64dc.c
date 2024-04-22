
void * X509_VERIFY_PARAM_get0(int param_1)

{
  void *pvVar1;
  
  if (param_1 < 5) {
    return (void *)(DAT_000c64f8 + param_1 * 0x24);
  }
  pvVar1 = sk_value(*DAT_000c64fc,param_1 + -5);
  return pvVar1;
}

