
undefined4 tls_construct_ctos_padding(int param_1,undefined4 param_2)

{
  int iVar1;
  EVP_MD *md;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_18;
  size_t local_14;
  
  if (-1 < *(int *)(param_1 + 0x4ec) << 0x1b) {
    return 2;
  }
  iVar1 = WPACKET_get_total_written(param_2,&local_14);
  if (iVar1 == 0) {
    uVar3 = 0x3b4;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x474);
    if ((((*piVar2 == 0x304) && (piVar2[0x75] != 0)) && (piVar2[0x6e] != 0)) &&
       (md = (EVP_MD *)ssl_md(*(undefined4 *)(piVar2[0x6e] + 0x34)), md != (EVP_MD *)0x0)) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x474) + 0x1d4);
      iVar1 = EVP_MD_size(md);
      local_14 = iVar1 + local_14 + iVar4 + 0xf;
    }
    if (0xff < local_14 - 0x100) {
      return 1;
    }
    if (0x200 - local_14 < 5) {
      local_14 = 1;
    }
    else {
      local_14 = 0x1fc - local_14;
    }
    iVar1 = WPACKET_put_bytes__(param_2,local_14,0x15,0,2);
    if ((iVar1 != 0) &&
       (iVar1 = WPACKET_sub_allocate_bytes__(param_2,local_14,&local_18,2), iVar1 != 0)) {
      memset(local_18,0,local_14);
      return 1;
    }
    uVar3 = 0x3dd;
  }
  ossl_statem_fatal(param_1,0x50,0x1d8,0x44,"ssl/statem/extensions_clnt.c",uVar3);
  return 0;
}

