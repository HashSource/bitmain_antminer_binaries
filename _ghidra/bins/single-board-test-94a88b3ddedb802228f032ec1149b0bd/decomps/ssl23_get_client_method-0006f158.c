
SSL_METHOD * ssl23_get_client_method(int param_1)

{
  SSL_METHOD *pSVar1;
  
  if (param_1 == 2) {
    pSVar1 = SSLv2_client_method();
    return pSVar1;
  }
  if (param_1 == 0x300) {
    pSVar1 = SSLv3_client_method();
    return pSVar1;
  }
  if (param_1 == 0x301) {
    pSVar1 = TLSv1_client_method();
    return pSVar1;
  }
  if (param_1 != 0x302) {
    if (param_1 == 0x303) {
      pSVar1 = TLSv1_2_client_method();
      return pSVar1;
    }
    return (SSL_METHOD *)0x0;
  }
  pSVar1 = TLSv1_1_client_method();
  return pSVar1;
}

