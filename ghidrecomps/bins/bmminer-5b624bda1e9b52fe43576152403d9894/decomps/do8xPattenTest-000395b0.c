
/* WARNING: Unknown calling convention */

void do8xPattenTest(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  pthread_mutex_t *ppVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  iVar7 = DAT_00039700;
  iVar4 = DAT_000396e4;
  iVar11 = 0;
  ppVar9 = (pthread_mutex_t *)(DAT_000396e4 + 0x9a0);
  *(undefined *)(DAT_000396e4 + 0x980) = 0;
  piVar5 = DAT_000396e8;
  *(undefined *)(iVar7 + 0xdd4) = 1;
  pthread_mutex_lock(ppVar9);
  uVar10 = get_dhash_acc_control();
  iVar6 = DAT_00039704;
  set_dhash_acc_control(uVar10 & 0xffffffbf);
  iVar8 = DAT_00039708;
  sleep(3);
  uVar10 = get_dhash_acc_control();
  set_dhash_acc_control(uVar10 & 0xffffffbf);
  sleep(2);
  iVar12 = *piVar5;
  do {
    while (piVar3 = (int *)(iVar12 + 8), iVar12 = iVar12 + 4, *piVar3 == 1) {
      iVar1 = iVar11 * 0x80;
      iVar2 = iVar11 * 0x100;
      iVar11 = iVar11 + 1;
      memcpy((void *)(iVar6 + iVar1),(void *)(iVar8 + iVar2),0x80);
      if (iVar11 == 0x10) goto LAB_00039624;
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0x10);
LAB_00039624:
  iVar6 = DAT_00039704;
  set_asic_ticket_mask(0);
  iVar8 = DAT_0003970c;
  clement_doTestBoardOnce(true);
  iVar11 = 0;
  iVar12 = *piVar5;
  do {
    while (piVar3 = (int *)(iVar12 + 8), iVar12 = iVar12 + 4, *piVar3 == 1) {
      iVar1 = iVar11 * 0x80;
      iVar2 = iVar11 * 0x100;
      iVar11 = iVar11 + 1;
      memcpy((void *)(iVar6 + iVar1),(void *)(iVar8 + iVar2),0x80);
      if (iVar11 == 0x10) goto LAB_00039660;
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0x10);
LAB_00039660:
  iVar6 = DAT_000396ec;
  set_nonce2_and_job_id_store_address(*(uint *)(DAT_000396ec + 0x8c));
  set_job_start_address(*(int *)(iVar6 + 0x8c) + 0x200000);
  set_asic_ticket_mask(0x3f);
  cgsleep_ms(10);
  uVar10 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar10 | 0x10000);
  clear_nonce_fifo();
  if (*DAT_000396f0 == 0) {
    set_time_out_control(*(uint *)(*piVar5 + 0x48) & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(*(int *)(*piVar5 + 0x48) * *DAT_000396f0 & 0x1ffffU | 0x80000000);
  }
  ppVar9 = DAT_000396f4;
  *(undefined *)(iVar7 + 0xdd4) = 0;
  pthread_mutex_unlock(ppVar9);
  re_send_last_job();
  cgtime(DAT_000396f8);
  cgtime(DAT_000396fc);
  *(undefined *)(iVar4 + 0x980) = 1;
  return;
}

