
int pkey_dh_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  long p1;
  uint uVar2;
  int iVar3;
  
  iVar1 = strcmp(param_2,"dh_paramgen_prime_len");
  if (iVar1 == 0) {
    iVar1 = strtol(param_3,(char **)0x0,10);
    iVar3 = 0x1001;
LAB_001974d8:
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,iVar3,iVar1,(void *)0x0);
    return iVar1;
  }
  iVar1 = strcmp(param_2,"dh_rfc5114");
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    uVar2 = strtol(param_3,(char **)0x0,10);
    if (uVar2 < 4) {
      *(uint *)(iVar1 + 0x18) = uVar2;
      return 1;
    }
  }
  else {
    iVar1 = strcmp(param_2,"dh_param");
    if (iVar1 != 0) {
      iVar1 = strcmp(param_2,"dh_paramgen_generator");
      if (iVar1 == 0) {
        iVar1 = strtol(param_3,(char **)0x0,10);
        iVar3 = 0x1002;
      }
      else {
        iVar1 = strcmp(param_2,"dh_paramgen_subprime_len");
        if (iVar1 == 0) {
          iVar1 = strtol(param_3,(char **)0x0,10);
          iVar3 = 0x1004;
        }
        else {
          iVar1 = strcmp(param_2,"dh_paramgen_type");
          if (iVar1 != 0) {
            iVar1 = strcmp(param_2,"dh_pad");
            if (iVar1 != 0) {
              return -2;
            }
            p1 = strtol(param_3,(char **)0x0,10);
            iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,0x400,0x1010,p1,(void *)0x0);
            return iVar1;
          }
          iVar1 = strtol(param_3,(char **)0x0,10);
          iVar3 = 0x1005;
        }
      }
      goto LAB_001974d8;
    }
    iVar3 = *(int *)(param_1 + 0x14);
    iVar1 = OBJ_sn2nid(param_3);
    if (iVar1 != 0) {
      *(int *)(iVar3 + 0x1c) = iVar1;
      return 1;
    }
    ERR_put_error(5,0x78,0x6e,"crypto/dh/dh_pmeth.c",0xf4);
  }
  return -2;
}

