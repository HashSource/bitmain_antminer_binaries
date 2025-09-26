
bool tls1_check_sig_alg_part_10(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = X509_get_signature_nid(param_2);
  if (param_3 != 0) {
    return iVar2 == param_3;
  }
  if (((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
      (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) ||
     (*(int *)(*(int *)(param_1 + 0x7c) + 0x26c) == 0)) {
    iVar3 = *(int *)(param_1 + 0xf8c);
    bVar1 = false;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x7c) + 0x274);
    bVar1 = true;
  }
  if (iVar3 == 0) {
    return false;
  }
  iVar6 = 0;
  do {
    if (bVar1) {
      puVar4 = &sigalg_lookup_tbl;
      do {
        if (*(short *)(puVar4 + 4) ==
            *(short *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x26c) + iVar6 * 2)) {
          iVar5 = *(int *)(puVar4 + 0x18);
          goto joined_r0x001040e2;
        }
        puVar4 = puVar4 + 0x20;
      } while (puVar4 != legacy_rsa_sigalg);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xf88) + iVar6 * 4);
      if (iVar5 != 0) {
        iVar5 = *(int *)(iVar5 + 0x18);
joined_r0x001040e2:
        if (iVar2 == iVar5) {
          return true;
        }
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == iVar3) {
      return false;
    }
  } while( true );
}

