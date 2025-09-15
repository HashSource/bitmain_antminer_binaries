
undefined4 cswift_rand_bytes(char *param_1,size_t param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_448;
  undefined4 local_444;
  char *local_440;
  char acStack_43c [20];
  char acStack_428 [1028];
  
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_448);
  if (iVar1 == 0) {
    if (0x3ff < (int)param_2) {
      pcVar3 = param_1;
      do {
        local_444 = 0x400;
        param_2 = param_2 - 0x400;
        param_1 = pcVar3 + 0x400;
        local_440 = pcVar3;
        iVar1 = (*p_CSwift_SimpleRequest)(local_448,5,0,0,&local_444,1);
        if (iVar1 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          uVar2 = 0;
          ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c",0x419);
          sprintf(acStack_428,"%ld",iVar1);
          ERR_add_error_data(2,"CryptoSwift error number is ",acStack_428);
          goto LAB_000db368;
        }
        pcVar3 = param_1;
      } while (0x3ff < (int)param_2);
    }
    if (param_2 == 0) {
      uVar2 = 1;
    }
    else {
      local_440 = acStack_428;
      uVar2 = 1;
      local_444 = 0x400;
      iVar1 = (*p_CSwift_SimpleRequest)(local_448,5,0,0,&local_444,1);
      if (iVar1 == 0) {
        memcpy(param_1,local_440,param_2);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        uVar2 = 0;
        ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c",0x428);
        sprintf(acStack_43c,"%ld",iVar1);
        ERR_add_error_data(2,"CryptoSwift error number is ",acStack_43c);
      }
    }
LAB_000db368:
    (*p_CSwift_ReleaseAccContext)(local_448);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar2 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6c,"e_cswift.c",0x3fc);
  }
  return uVar2;
}

