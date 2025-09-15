
SSL_METHOD * ssl23_get_server_method(int param_1)

{
  SSL_METHOD *pSVar1;
  
  if (param_1 == 2) {
    pSVar1 = SSLv2_server_method();
    return pSVar1;
  }
  if (param_1 == 0x300) {
    pSVar1 = SSLv3_server_method();
    return pSVar1;
  }
  if (param_1 == 0x301) {
    pSVar1 = TLSv1_server_method();
    return pSVar1;
  }
  if (param_1 != 0x302) {
    if (param_1 == 0x303) {
      pSVar1 = TLSv1_2_server_method();
      return pSVar1;
    }
    return (SSL_METHOD *)0x0;
  }
  pSVar1 = TLSv1_1_server_method();
  return pSVar1;
}

