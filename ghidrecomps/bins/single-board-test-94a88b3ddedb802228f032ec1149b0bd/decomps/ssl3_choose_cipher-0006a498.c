
void * ssl3_choose_cipher(int param_1,_STACK *param_2,_STACK *param_3)

{
  int iVar1;
  void *data;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  _STACK *p_Var7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  iVar6 = *(int *)(param_1 + 0x98);
  p_Var7 = param_3;
  if ((-1 < *(int *)(param_1 + 0x100) << 9) && ((*(uint *)(iVar6 + 0x38) & 0x30000) == 0)) {
    p_Var7 = param_2;
    param_2 = param_3;
  }
  iVar5 = 0;
  tls1_set_cert_validity(param_1);
  pvVar8 = (void *)0x0;
  do {
    iVar1 = sk_num(p_Var7);
    if (iVar1 <= iVar5) {
      return pvVar8;
    }
    data = sk_value(p_Var7,iVar5);
    if ((-1 < *(int *)((int)data + 0x1c) << 0x1d) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1b < 0)) {
      ssl_set_cert_masks(iVar6,data);
      uVar4 = *(uint *)(iVar6 + 8);
      uVar10 = *(uint *)(iVar6 + 0xc);
      bVar12 = *(int *)(param_1 + 0x1d0) << 0x15 < 0;
      uVar3 = *(uint *)(iVar6 + 0x10);
      uVar11 = *(uint *)(iVar6 + 0x14);
      if (bVar12) {
        uVar4 = uVar4 | 0x400;
      }
      uVar2 = *(uint *)((int)data + 0xc);
      if (bVar12) {
        uVar10 = uVar10 | 0x400;
        uVar3 = uVar3 | 0x400;
      }
      uVar9 = *(uint *)((int)data + 0x10);
      if (bVar12) {
        uVar11 = uVar11 | 0x400;
      }
      if ((-1 < (int)(uVar2 << 0x17)) || (*(int *)(param_1 + 0xe0) != 0)) {
        if (*(int *)((int)data + 0x20) << 0x1e < 0) {
          if ((uVar3 & uVar2) != 0) {
            bVar12 = (uVar11 & uVar9) != 0;
            if (-1 < (int)(uVar2 << 0x18)) goto LAB_0006a558;
LAB_0006a4d4:
            if ((bVar12) &&
               ((iVar1 = tls1_check_ec_tmp_key(param_1,*(undefined4 *)((int)data + 8)), iVar1 != 0
                && (iVar1 = sk_find(param_2,data), -1 < iVar1)))) {
              if (((uVar9 & 0x40) == 0) || (*(char *)(*(int *)(param_1 + 0x58) + 0x420) == '\0')) {
LAB_0006a568:
                pvVar8 = sk_value(param_2,iVar1);
                return pvVar8;
              }
              if (pvVar8 == (void *)0x0) {
                pvVar8 = sk_value(param_2,iVar1);
              }
            }
          }
        }
        else if ((uVar4 & uVar2) != 0) {
          bVar12 = (uVar10 & uVar9) != 0;
          if ((int)(uVar2 << 0x18) < 0) goto LAB_0006a4d4;
LAB_0006a558:
          if ((bVar12) && (iVar1 = sk_find(param_2,data), -1 < iVar1)) goto LAB_0006a568;
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

