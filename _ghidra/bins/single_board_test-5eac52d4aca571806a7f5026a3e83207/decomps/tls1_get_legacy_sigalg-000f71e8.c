
undefined1 * tls1_get_legacy_sigalg(int param_1,uint param_2,int *param_3,undefined4 param_4)

{
  short *psVar1;
  undefined1 *puVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  
  if (param_2 == 0xffffffff) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      param_3 = *(int **)(param_1 + 0x404) + 5;
      param_2 = (**(int **)(param_1 + 0x404) - (int)param_3 >> 2) * -0x33333333;
      goto LAB_000f71f0;
    }
    param_2 = 0;
    while( true ) {
      iVar3 = ssl_cert_lookup_by_idx(param_2);
      param_3 = *(int **)(iVar3 + 4);
      uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x14);
      if ((uVar5 & (uint)param_3) != 0) break;
      param_2 = param_2 + 1;
      if (param_2 == 9) {
        return (undefined1 *)0x0;
      }
    }
    if (param_2 != 4) goto LAB_000f71f0;
    if (uVar5 != 0x20) {
      iVar3 = *(int *)(param_1 + 0x404);
      if (*(int *)(iVar3 + 0x90) == 0) {
        if (*(int *)(iVar3 + 0x7c) == 0) {
          if (*(int *)(iVar3 + 0x68) == 0) goto LAB_000f72d0;
        }
        else {
          param_2 = 5;
        }
      }
      else {
        param_2 = 6;
      }
      goto LAB_000f720a;
    }
LAB_000f72d0:
    sVar4 = -0x1213;
  }
  else {
LAB_000f71f0:
    if (8 < param_2) {
      return (undefined1 *)0x0;
    }
    uVar5 = (uint)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e) >> 0x1f;
    if (param_2 != 0) {
      uVar5 = 1;
    }
    if (uVar5 == 0) {
      puVar2 = legacy_rsa_sigalg;
      iVar3 = tls1_lookup_md(legacy_rsa_sigalg,0,param_3,0,param_4);
      goto joined_r0x000f72ae;
    }
LAB_000f720a:
    sVar4 = *(short *)(tls_default_sigalg + param_2 * 2);
  }
  puVar2 = &sigalg_lookup_tbl;
  do {
    psVar1 = (short *)(puVar2 + 4);
    if (*psVar1 == sVar4) goto LAB_000f7232;
    puVar2 = puVar2 + 0x20;
  } while (puVar2 != legacy_rsa_sigalg);
  puVar2 = (undefined1 *)0x0;
LAB_000f7232:
  iVar3 = tls1_lookup_md(puVar2,0,legacy_rsa_sigalg,*psVar1,param_4);
  if (iVar3 == 0) {
    return (undefined1 *)0x0;
  }
  iVar3 = tls1_lookup_md(puVar2,0);
joined_r0x000f72ae:
  if ((iVar3 != 0) && (iVar3 = tls12_sigalg_allowed_part_16(param_1,0x5000b,puVar2), iVar3 != 0)) {
    return puVar2;
  }
  return (undefined1 *)0x0;
}

