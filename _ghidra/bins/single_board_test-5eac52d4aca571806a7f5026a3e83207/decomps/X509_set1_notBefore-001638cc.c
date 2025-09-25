
void X509_set1_notBefore(int param_1)

{
  if (param_1 != 0) {
    x509_set1_time(param_1 + 0x20);
    return;
  }
  return;
}

