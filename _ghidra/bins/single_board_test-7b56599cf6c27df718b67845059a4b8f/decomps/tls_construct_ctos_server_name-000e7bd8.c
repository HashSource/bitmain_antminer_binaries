
undefined4 tls_construct_ctos_server_name(int param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  char *__s;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x538) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0,0,2);
  if ((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) {
    uVar3 = WPACKET_start_sub_packet_len__(param_2,2);
    if (((int)uVar3 != 0) &&
       (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0,0,1), iVar1 != 0)) {
      __s = *(char **)(param_1 + 0x538);
      sVar2 = strlen(__s);
      iVar1 = WPACKET_sub_memcpy__(param_2,__s,sVar2,2);
      if (((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
         (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
        return 1;
      }
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1db,0x44,"ssl/statem/extensions_clnt.c",0x37);
  return 0;
}

