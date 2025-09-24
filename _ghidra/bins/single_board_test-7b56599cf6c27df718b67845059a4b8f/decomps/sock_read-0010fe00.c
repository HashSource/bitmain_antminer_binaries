
void * sock_read(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != (void *)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0;
    param_2 = (void *)read((int)param_1->ptr,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if ((int)param_2 < 1) {
      iVar2 = BIO_sock_should_retry((int)param_2);
      if (iVar2 == 0) {
        if (param_2 == (void *)0x0) {
          param_1->retry_reason = param_1->retry_reason | 0x800;
        }
      }
      else {
        BIO_set_flags(param_1,9);
      }
    }
  }
  return param_2;
}

