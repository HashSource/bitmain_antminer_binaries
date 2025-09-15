
void * sock_read(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != (void *)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0;
    param_2 = (void *)read(param_1->num,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if (((int)param_2 < 1) && ((int)param_2 + 1U < 2)) {
      iVar2 = *piVar1;
      if (iVar2 == 0x47) {
LAB_000a9c32:
        BIO_set_flags(param_1,9);
        return param_2;
      }
      if (iVar2 < 0x48) {
        if ((iVar2 == 4) || (iVar2 == 0xb)) goto LAB_000a9c32;
      }
      else if ((iVar2 == 0x6b) || ((0x6a < iVar2 && (iVar2 - 0x72U < 2)))) goto LAB_000a9c32;
    }
  }
  return param_2;
}

