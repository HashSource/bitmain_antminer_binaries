
undefined4 tls1_set_peer_legacy_sigalg(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = ssl_cert_lookup_by_pkey(param_2,&local_c);
  if ((iVar1 != 0) && (iVar1 = tls1_get_legacy_sigalg(param_1,local_c), iVar1 != 0)) {
    *(int *)(*(int *)(param_1 + 0x7c) + 0x278) = iVar1;
    return 1;
  }
  return 0;
}

