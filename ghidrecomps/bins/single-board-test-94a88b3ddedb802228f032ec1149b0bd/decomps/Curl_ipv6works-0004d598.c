
bool Curl_ipv6works(void)

{
  int iVar1;
  
  if (ipv6_works_22847 == -1) {
    iVar1 = socket(10,2,0);
    if (iVar1 == -1) {
      ipv6_works_22847 = 0;
      return false;
    }
    ipv6_works_22847 = 1;
    Curl_closesocket(0,iVar1);
  }
  return 0 < ipv6_works_22847;
}

