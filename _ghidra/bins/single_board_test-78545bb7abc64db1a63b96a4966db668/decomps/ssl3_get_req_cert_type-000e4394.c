
int ssl3_get_req_cert_type(int *param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  undefined8 uVar3;
  int local_14;
  
  iVar1 = *(int *)(param_1[0x101] + 200);
  local_14 = 0;
  if (iVar1 != 0) {
    iVar1 = WPACKET_memcpy(param_2,iVar1,*(undefined4 *)(param_1[0x101] + 0xcc));
    return iVar1;
  }
  ssl_set_sig_mask(&local_14,param_1,0x5000e);
  iVar2 = *(int *)(*(int *)(param_1[0x1f] + 0x210) + 0x10);
  iVar1 = extraout_r1;
  if (*param_1 < 0x301) {
    if ((*param_1 != 0x300) || (iVar1 = iVar2 << 0x1e, -1 < iVar1)) goto LAB_000e43da;
    uVar3 = WPACKET_put_bytes__(param_2,iVar1,5,0,1);
    if ((int)uVar3 != 0) {
      uVar3 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),6,0,1);
      iVar1 = (int)((ulonglong)uVar3 >> 0x20);
      if ((int)uVar3 != 0) goto LAB_000e43da;
    }
LAB_000e441e:
    iVar1 = 0;
  }
  else {
    if (iVar2 << 0x1b < 0) {
      uVar3 = WPACKET_put_bytes__(param_2,extraout_r1,0x16,0,1);
      if ((int)uVar3 != 0) {
        uVar3 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0xee,0,1);
        if ((int)uVar3 != 0) {
          iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0xef,0,1);
          if (iVar1 == 0) {
            return 0;
          }
          return 1;
        }
      }
      goto LAB_000e441e;
    }
LAB_000e43da:
    if (-1 < local_14 << 0x1f) {
      uVar3 = WPACKET_put_bytes__(param_2,1,1,0,1);
      iVar1 = (int)((ulonglong)uVar3 >> 0x20);
      if ((int)uVar3 == 0) goto LAB_000e441e;
    }
    if (-1 < local_14 << 0x1e) {
      uVar3 = WPACKET_put_bytes__(param_2,1,2,0,1);
      iVar1 = (int)((ulonglong)uVar3 >> 0x20);
      if ((int)uVar3 == 0) goto LAB_000e441e;
    }
    if ((*param_1 < 0x301) || (local_14 << 0x1c < 0)) {
      return 1;
    }
    iVar1 = WPACKET_put_bytes__(param_2,iVar1,0x40,0,1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

