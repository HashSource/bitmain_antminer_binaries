
void ssl_set_sig_mask(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  short *local_2c [2];
  
  iVar1 = tls12_get_psigalgs(param_2,1,local_2c);
  if (iVar1 == 0) {
    uVar5 = 0xb;
  }
  else {
    uVar5 = 0xb;
    iVar6 = 0;
    do {
      puVar4 = &sigalg_lookup_tbl;
      do {
        if (*(short *)(puVar4 + 4) == *local_2c[0]) {
          iVar2 = ssl_cert_lookup_by_idx(*(undefined4 *)(puVar4 + 0x14));
          if ((((iVar2 != 0) && ((uVar5 & *(uint *)(iVar2 + 4)) != 0)) &&
              (iVar3 = tls1_lookup_md(puVar4,0), iVar3 != 0)) &&
             (iVar3 = tls12_sigalg_allowed_part_16(param_2,param_3,puVar4), iVar3 != 0)) {
            uVar5 = uVar5 & ~*(uint *)(iVar2 + 4);
          }
          break;
        }
        puVar4 = puVar4 + 0x20;
      } while (puVar4 != legacy_rsa_sigalg);
      iVar6 = iVar6 + 1;
      local_2c[0] = local_2c[0] + 1;
    } while (iVar1 != iVar6);
  }
  *param_1 = uVar5 | *param_1;
  return;
}

