
undefined4 dtls_construct_hello_verify_request(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  uint local_14 [2];
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0x4d0) + 0x7c);
  if (((pcVar2 == (code *)0x0) ||
      (iVar1 = (*pcVar2)(param_1,*(undefined4 *)(param_1 + 0x80),local_14), iVar1 == 0)) ||
     (0xff < local_14[0])) {
    ossl_statem_fatal(param_1,0xffffffff,0x181,400,"ssl/statem/statem_srvr.c",0x518);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x80);
    *(uint *)(iVar1 + 0x100) = local_14[0];
    iVar1 = dtls_raw_hello_verify_request(param_2,iVar1,local_14[0]);
    if (iVar1 != 0) {
      return 1;
    }
    ossl_statem_fatal(param_1,0xffffffff,0x181,0x44,"ssl/statem/statem_srvr.c",0x520);
  }
  return 0;
}

