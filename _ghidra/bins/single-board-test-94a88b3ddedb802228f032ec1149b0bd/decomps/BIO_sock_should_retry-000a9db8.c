
int BIO_sock_should_retry(int i)

{
  int *piVar1;
  int iVar2;
  
  if (1 < i + 1U) {
    return 0;
  }
  piVar1 = __errno_location();
  iVar2 = *piVar1;
  if (iVar2 != 0x47) {
    if (iVar2 < 0x48) {
      if ((iVar2 != 4) && (iVar2 != 0xb)) {
        return 0;
      }
    }
    else if ((iVar2 != 0x6b) && ((iVar2 < 0x6b || (1 < iVar2 - 0x72U)))) {
      return 0;
    }
  }
  return 1;
}

