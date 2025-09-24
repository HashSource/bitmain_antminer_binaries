
bool tls_construct_ctos_psk(int param_1,undefined4 param_2)

{
  bool bVar1;
  EVP_MD *md;
  EVP_MD *md_00;
  time_t tVar2;
  EVP_MD *pEVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  
  piVar5 = *(int **)(param_1 + 0x474);
  *(undefined4 *)(param_1 + 0x5c4) = 0;
  local_30 = 0;
  local_2c[0] = 0;
  if (*piVar5 != 0x304) {
    return (bool)2;
  }
  if (piVar5[0x75] == 0) {
    iVar8 = *(int *)(param_1 + 0x478);
    if (iVar8 == 0) {
      return (bool)2;
    }
    if (*(int *)(param_1 + 0x44c) == 1) {
LAB_000e8e98:
      pEVar3 = (EVP_MD *)ssl_handshake_md(param_1);
      piVar5 = *(int **)(param_1 + 0x474);
      if (piVar5[0x75] != 0) goto LAB_000e8d9a;
      iVar8 = *(int *)(param_1 + 0x478);
      uVar9 = 0;
      md_00 = (EVP_MD *)0x0;
      goto LAB_000e8dce;
    }
    uVar9 = 0;
    md_00 = (EVP_MD *)0x0;
    pEVar3 = (EVP_MD *)0x0;
    iVar4 = 0;
    bVar1 = false;
    goto LAB_000e8d40;
  }
  if (*(int *)(param_1 + 0x44c) == 1) goto LAB_000e8e98;
  pEVar3 = (EVP_MD *)0x0;
LAB_000e8d9a:
  if (piVar5[0x6e] == 0) {
    uVar12 = 0x40a;
    uVar6 = 0x44;
    goto LAB_000e8ef2;
  }
  md_00 = (EVP_MD *)ssl_md(*(undefined4 *)(piVar5[0x6e] + 0x34));
  if ((md_00 == (EVP_MD *)0x0) || (md_00 != pEVar3 && *(int *)(param_1 + 0x44c) == 1)) {
    iVar8 = *(int *)(param_1 + 0x478);
    uVar9 = 0;
LAB_000e8dce:
    iVar4 = 0;
    bVar1 = false;
    if (iVar8 == 0) {
      return (bool)2;
    }
LAB_000e8d40:
    bVar10 = bVar1;
    md = (EVP_MD *)ssl_md(*(undefined4 *)(*(int *)(iVar8 + 0x1b8) + 0x34));
    if (md == (EVP_MD *)0x0) {
      uVar12 = 0x45c;
      uVar6 = 0xdb;
LAB_000e8ef2:
      ossl_statem_fatal(param_1,0x50,0x1f5,uVar6,"ssl/statem/extensions_clnt.c",uVar12);
      return false;
    }
    if (md != pEVar3 && *(int *)(param_1 + 0x44c) == 1) {
      uVar12 = 0x466;
      uVar6 = 0xdb;
      goto LAB_000e8d7a;
    }
    local_3c = EVP_MD_size(md);
  }
  else {
    tVar2 = time((time_t *)0x0);
    iVar4 = *(int *)(param_1 + 0x474);
    iVar8 = tVar2 - *(int *)(iVar4 + 0x1b0);
    if (iVar8 == 0) {
      uVar9 = 0;
    }
    else {
      uVar7 = iVar8 - 1;
      uVar9 = 0;
      if ((*(uint *)(iVar4 + 0x1d8) < uVar7) ||
         ((uVar9 = uVar7 * 1000, uVar7 != 0 && (uVar7 != uVar9 / 1000)))) {
        iVar8 = *(int *)(param_1 + 0x478);
        goto LAB_000e8dce;
      }
    }
    bVar10 = true;
    uVar9 = uVar9 + *(int *)(iVar4 + 0x1dc);
    iVar4 = EVP_MD_size(md_00);
    iVar8 = *(int *)(param_1 + 0x478);
    *(int *)(param_1 + 0x5c4) = *(int *)(param_1 + 0x5c4) + 1;
    bVar1 = true;
    if (iVar8 != 0) goto LAB_000e8d40;
    md = (EVP_MD *)0x0;
    local_3c = 0;
  }
  uVar6 = 2;
  iVar8 = WPACKET_put_bytes__(param_2);
  if (((iVar8 == 0) || (iVar8 = WPACKET_start_sub_packet_len__(param_2,2), iVar8 == 0)) ||
     (iVar8 = WPACKET_start_sub_packet_len__(param_2,2), iVar8 == 0)) {
    uVar12 = 0x472;
  }
  else if (bVar10) {
    uVar11 = WPACKET_sub_memcpy__
                       (param_2,*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x1d0),
                        *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x1d4),2,uVar6);
    if ((int)uVar11 != 0) {
      uVar6 = 4;
      iVar8 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar11 >> 0x20),uVar9,0,4);
      if (iVar8 != 0) goto LAB_000e8e20;
    }
    uVar12 = 0x47b;
  }
  else {
LAB_000e8e20:
    if (*(int *)(param_1 + 0x478) != 0) {
      iVar8 = WPACKET_sub_memcpy__
                        (param_2,*(undefined4 *)(param_1 + 0x47c),*(undefined4 *)(param_1 + 0x480),2
                         ,uVar6);
      if ((iVar8 == 0) || (iVar8 = WPACKET_put_bytes__(param_2,4,0,0,4), iVar8 == 0)) {
        uVar12 = 0x485;
        goto LAB_000e8e06;
      }
      *(int *)(param_1 + 0x5c4) = *(int *)(param_1 + 0x5c4) + 1;
    }
    iVar8 = WPACKET_close(param_2);
    if (((((iVar8 != 0) && (iVar8 = WPACKET_get_total_written(param_2,&local_38), iVar8 != 0)) &&
         ((iVar8 = WPACKET_start_sub_packet_len__(param_2,2), iVar8 != 0 &&
          ((!bVar10 || (iVar8 = WPACKET_sub_allocate_bytes__(param_2,iVar4,&local_30,1), iVar8 != 0)
           ))))) &&
        ((*(int *)(param_1 + 0x478) == 0 ||
         (iVar8 = WPACKET_sub_allocate_bytes__(param_2,local_3c,local_2c,1), iVar8 != 0)))) &&
       ((((iVar8 = WPACKET_close(param_2), iVar8 != 0 &&
          (iVar8 = WPACKET_close(param_2), iVar8 != 0)) &&
         (iVar8 = WPACKET_get_total_written(param_2,&local_34), iVar8 != 0)) &&
        (iVar8 = WPACKET_fill_lengths(param_2), iVar8 != 0)))) {
      iVar8 = WPACKET_get_curr(param_2);
      if ((bVar10) &&
         (iVar4 = tls_psk_do_binder(param_1,md_00,iVar8 - local_34,local_38,0,local_30,
                                    *(undefined4 *)(param_1 + 0x474),1,0), iVar4 != 1)) {
        return false;
      }
      if (*(int *)(param_1 + 0x478) == 0) {
        bVar10 = true;
      }
      else {
        iVar8 = tls_psk_do_binder(param_1,md,iVar8 - local_34,local_38,0,local_2c[0],
                                  *(int *)(param_1 + 0x478),1,1);
        bVar10 = iVar8 == 1;
      }
      return bVar10;
    }
    uVar12 = 0x49b;
  }
LAB_000e8e06:
  uVar6 = 0x44;
LAB_000e8d7a:
  ossl_statem_fatal(param_1,0x50,0x1f5,uVar6,"ssl/statem/extensions_clnt.c",uVar12);
  return false;
}

