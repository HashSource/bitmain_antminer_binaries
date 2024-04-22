
/* WARNING: Unknown calling convention */

void insert_reg_data(uint *buf)

{
  uint *puVar1;
  pthread_mutex_t *ppVar2;
  undefined4 extraout_r1;
  undefined4 in_r3;
  uint uVar3;
  
  puVar1 = DAT_000367a8;
  if ((DAT_000367a8[2] < 0x1ff) && (*DAT_000367a8 < 0x1ff)) {
    pthread_mutex_lock(DAT_000367ac);
    ppVar2 = DAT_000367ac;
    puVar1[(*puVar1 + 1) * 2 + 1] = buf[1];
    *(byte *)(puVar1 + (*puVar1 + 1) * 2 + 2) = *(byte *)((int)buf + 3) & 0x1f;
    *(byte *)((int)puVar1 + (*puVar1 + 1) * 8 + 9) = (byte)*buf & 0xf;
    if (*puVar1 < 0x1ff) {
      uVar3 = *puVar1 + 1;
    }
    else {
      uVar3 = 0;
    }
    *puVar1 = uVar3;
    if (puVar1[2] < 0x1ff) {
      uVar3 = DAT_000367a8[2] + 1;
    }
    else {
      uVar3 = 0x1ff;
    }
    DAT_000367a8[2] = uVar3;
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f228)(ppVar2,extraout_r1,uVar3,in_r3);
    return;
  }
  clear_register_value_buf();
  return;
}

