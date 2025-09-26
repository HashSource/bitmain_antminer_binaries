
void X509_set1_notAfter(int param_1)

{
  if (param_1 != 0) {
    x509_set1_time(param_1 + 0x24);
    return;
  }
  return;
}

