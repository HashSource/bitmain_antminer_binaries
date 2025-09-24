
undefined4 tls_construct_cert_status_body(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = WPACKET_put_bytes__(param_2,param_2,*(int *)(param_1 + 0x53c),
                              *(int *)(param_1 + 0x53c) >> 0x1f,1);
  if ((iVar1 != 0) &&
     (iVar1 = WPACKET_sub_memcpy__
                        (param_2,*(undefined4 *)(param_1 + 0x554),*(undefined4 *)(param_1 + 0x558),3
                        ), iVar1 != 0)) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x1ee,0x44,"ssl/statem/statem_srvr.c",0x1070);
  return 0;
}

