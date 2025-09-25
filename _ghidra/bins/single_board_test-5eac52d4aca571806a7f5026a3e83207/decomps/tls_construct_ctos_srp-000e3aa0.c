
undefined4 tls_construct_ctos_srp(int param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  char *__s;
  
  if (*(int *)(param_1 + 0x61c) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0xc,0,2);
  if ((((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
      (iVar1 = WPACKET_start_sub_packet_len__(param_2,1), iVar1 != 0)) &&
     (iVar1 = WPACKET_set_flags(param_2,1), iVar1 != 0)) {
    __s = *(char **)(param_1 + 0x61c);
    sVar2 = strlen(__s);
    iVar1 = WPACKET_memcpy(param_2,__s,sVar2);
    if (((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
       (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1de,0x44,"ssl/statem/extensions_clnt.c",0x6b);
  return 0;
}

