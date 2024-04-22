
bool Curl_ipv6works(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0004d5d0;
  iVar2 = *DAT_0004d5d0;
  if (iVar2 == -1) {
    iVar2 = socket(10,2,0);
    if (iVar2 == -1) {
      *piVar1 = 0;
      return false;
    }
    *piVar1 = 1;
    Curl_closesocket(0,iVar2);
    iVar2 = *piVar1;
  }
  return 0 < iVar2;
}

