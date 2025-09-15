
ssize_t sock_write(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  ssize_t sVar2;
  int iVar3;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  sVar2 = write(param_1->num,param_2,param_3);
  BIO_clear_flags(param_1,0xf);
  if (0 < sVar2) {
    return sVar2;
  }
  if (1 < sVar2 + 1U) {
    return sVar2;
  }
  iVar3 = *piVar1;
  if (iVar3 != 0x47) {
    if (iVar3 < 0x48) {
      if ((iVar3 == 4) || (iVar3 == 0xb)) goto LAB_000a9d70;
    }
    else if ((iVar3 == 0x6b) || ((0x6a < iVar3 && (iVar3 - 0x72U < 2)))) goto LAB_000a9d70;
    return sVar2;
  }
LAB_000a9d70:
  BIO_set_flags(param_1,10);
  return sVar2;
}

