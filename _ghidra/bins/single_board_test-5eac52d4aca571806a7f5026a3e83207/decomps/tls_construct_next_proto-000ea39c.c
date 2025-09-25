
undefined4 tls_construct_next_proto(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  size_t __n;
  void *local_1c [2];
  
  iVar2 = *(int *)(param_1 + 0x5a0);
  local_1c[0] = (void *)0x0;
  iVar1 = WPACKET_sub_memcpy__(param_2,*(undefined4 *)(param_1 + 0x59c),iVar2,1);
  if (iVar1 != 0) {
    __n = 0x20 - (iVar2 + 2U & 0x1f);
    iVar1 = WPACKET_sub_allocate_bytes__(param_2,__n,local_1c,1);
    if (iVar1 != 0) {
      memset(local_1c[0],0,__n);
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1aa,0x44,"ssl/statem/statem_clnt.c",0xe43);
  return 0;
}

