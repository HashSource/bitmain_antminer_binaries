
undefined4 tls1_process_sigalgs(int param_1)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  void *__s;
  bool bVar10;
  int local_44;
  short *local_40;
  short *local_38;
  undefined4 *local_34;
  short *local_2c [2];
  
  iVar8 = *(int *)(param_1 + 0x404);
  __s = (void *)(*(int *)(param_1 + 0x7c) + 0x27c);
  uVar6 = *(uint *)(iVar8 + 0x10);
  CRYPTO_free(*(void **)(param_1 + 0xf88));
  uVar6 = uVar6 & 0x30000;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  *(undefined4 *)(param_1 + 0xf8c) = 0;
  if ((*(int *)(param_1 + 0x1c) == 0) &&
     (psVar3 = *(short **)(iVar8 + 0xd8), psVar3 != (short *)0x0 && uVar6 == 0)) {
    iVar9 = *(int *)(iVar8 + 0xdc);
    iVar5 = *(int *)(param_1 + 0x7c);
    iVar8 = iVar9;
    local_2c[0] = psVar3;
    if ((*(uint *)(param_1 + 0x4ec) & 0x400000) != 0) goto LAB_000f7c52;
LAB_000f7d98:
    iVar8 = iVar9;
    if (uVar6 != 0) goto LAB_000f7c52;
    iVar8 = *(int *)(iVar5 + 0x270);
    local_40 = *(short **)(iVar5 + 0x268);
    local_38 = local_2c[0];
  }
  else {
    if (*(short **)(iVar8 + 0xd0) == (short *)0x0 || uVar6 != 0) {
      iVar9 = tls12_get_psigalgs(param_1,0,local_2c);
    }
    else {
      iVar9 = *(int *)(iVar8 + 0xd4);
      local_2c[0] = *(short **)(iVar8 + 0xd0);
    }
    iVar5 = *(int *)(param_1 + 0x7c);
    iVar8 = iVar9;
    if ((*(uint *)(param_1 + 0x4ec) & 0x400000) == 0) goto LAB_000f7d98;
LAB_000f7c52:
    iVar9 = *(int *)(iVar5 + 0x270);
    local_38 = *(short **)(iVar5 + 0x268);
    local_40 = local_2c[0];
  }
  if (iVar8 != 0) {
    iVar5 = 0;
    local_44 = 0;
    psVar3 = local_40;
LAB_000f7c7c:
    do {
      puVar4 = &sigalg_lookup_tbl;
      do {
        if (*(short *)(puVar4 + 4) == *psVar3) goto LAB_000f7c96;
        puVar4 = puVar4 + 0x20;
      } while (puVar4 != legacy_rsa_sigalg);
      puVar4 = (undefined1 *)0x0;
LAB_000f7c96:
      iVar1 = tls1_lookup_md(puVar4,0);
      if (((iVar1 == 0) ||
          (iVar1 = tls12_sigalg_allowed_part_16(param_1,0x5000c,puVar4), iVar1 == 0)) ||
         (iVar9 == 0)) {
LAB_000f7cd4:
        iVar5 = iVar5 + 1;
        psVar3 = psVar3 + 1;
        if (iVar8 == iVar5) break;
        goto LAB_000f7c7c;
      }
      if (*local_38 != *psVar3) {
        iVar1 = 0;
        psVar2 = local_38;
        do {
          iVar1 = iVar1 + 1;
          if (iVar9 == iVar1) goto LAB_000f7cd4;
          psVar2 = psVar2 + 1;
        } while (*psVar2 != *psVar3);
      }
      iVar5 = iVar5 + 1;
      psVar3 = psVar3 + 1;
      local_44 = local_44 + 1;
    } while (iVar8 != iVar5);
    if (local_44 != 0) {
      puVar7 = (undefined4 *)CRYPTO_malloc(local_44 << 2,"ssl/t1_lib.c",0x6f8);
      if (puVar7 == (undefined4 *)0x0) {
        ERR_put_error(0x14,0x277,0x41,"ssl/t1_lib.c",0x6f9);
        return 0;
      }
      iVar5 = 0;
      local_44 = 0;
      local_34 = puVar7;
LAB_000f7e0a:
      do {
        puVar4 = &sigalg_lookup_tbl;
        do {
          if (*(short *)(puVar4 + 4) == *local_40) goto LAB_000f7e1e;
          puVar4 = puVar4 + 0x20;
        } while (puVar4 != legacy_rsa_sigalg);
        puVar4 = (undefined1 *)0x0;
LAB_000f7e1e:
        iVar1 = tls1_lookup_md(puVar4,0);
        if (((iVar1 == 0) ||
            (iVar1 = tls12_sigalg_allowed_part_16(param_1,0x5000c,puVar4), iVar1 == 0)) ||
           (iVar9 == 0)) {
LAB_000f7e5c:
          iVar5 = iVar5 + 1;
          local_40 = local_40 + 1;
          if (iVar8 == iVar5) break;
          goto LAB_000f7e0a;
        }
        if (*local_38 != *local_40) {
          iVar1 = 0;
          psVar3 = local_38;
          do {
            iVar1 = iVar1 + 1;
            if (iVar9 == iVar1) goto LAB_000f7e5c;
            psVar3 = psVar3 + 1;
          } while (*psVar3 != *local_40);
        }
        local_44 = local_44 + 1;
        if (local_34 == (undefined4 *)0x0) goto LAB_000f7e5c;
        iVar5 = iVar5 + 1;
        *local_34 = puVar4;
        local_34 = local_34 + 1;
        local_40 = local_40 + 1;
      } while (iVar8 != iVar5);
      goto LAB_000f7cf0;
    }
  }
  puVar7 = (undefined4 *)0x0;
  local_44 = 0;
LAB_000f7cf0:
  *(undefined4 **)(param_1 + 0xf88) = puVar7;
  *(int *)(param_1 + 0xf8c) = local_44;
  memset(__s,0,0x24);
  uVar6 = *(uint *)(param_1 + 0xf8c);
  if (uVar6 == 0) {
    return 1;
  }
  iVar8 = 0;
  do {
    iVar9 = *(int *)(puVar7[iVar8] + 0x14);
    if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) {
LAB_000f7d44:
      if (*(int *)((int)__s + iVar9 * 4) != 0) goto LAB_000f7d18;
      iVar5 = ssl_cert_is_disabled(iVar9);
      if (iVar5 == 0) {
        *(undefined4 *)((int)__s + iVar9 * 4) = 0x102;
      }
      uVar6 = *(uint *)(param_1 + 0xf8c);
      if (uVar6 <= iVar8 + 1U) {
        return 1;
      }
    }
    else {
      iVar1 = **(int **)(param_1 + 4);
      bVar10 = SBORROW4(iVar1,0x10000);
      iVar5 = iVar1 + -0x10000;
      if (iVar1 != 0x10000) {
        bVar10 = SBORROW4(iVar1,0x303);
        iVar5 = iVar1 + -0x303;
      }
      if (((iVar1 == 0x10000 || iVar1 == 0x303) || iVar5 < 0 != bVar10) ||
         (*(int *)(puVar7[iVar8] + 0x10) != 6)) goto LAB_000f7d44;
LAB_000f7d18:
      if (uVar6 <= iVar8 + 1U) {
        return 1;
      }
    }
    iVar8 = iVar8 + 1;
    puVar7 = *(undefined4 **)(param_1 + 0xf88);
  } while( true );
}

