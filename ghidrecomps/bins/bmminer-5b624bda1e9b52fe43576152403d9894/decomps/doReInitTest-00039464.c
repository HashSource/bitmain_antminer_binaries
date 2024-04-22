
/* WARNING: Unknown calling convention */

void doReInitTest(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  pthread_mutex_t *ppVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  iVar7 = DAT_000395a8;
  iVar6 = DAT_000395a4;
  iVar11 = 0;
  ppVar9 = (pthread_mutex_t *)(DAT_000395a4 + 0x9a0);
  *(undefined *)(DAT_000395a4 + 0x980) = 0;
  piVar8 = DAT_000395ac;
  *(undefined *)(iVar7 + 0xdd4) = 1;
  pthread_mutex_lock(ppVar9);
  uVar10 = get_dhash_acc_control();
  iVar4 = DAT_00039588;
  set_dhash_acc_control(uVar10 & 0xffffffbf);
  iVar5 = DAT_0003958c;
  sleep(3);
  uVar10 = get_dhash_acc_control();
  set_dhash_acc_control(uVar10 & 0xffffffbf);
  sleep(2);
  iVar12 = *piVar8;
  do {
    while (piVar3 = (int *)(iVar12 + 8), iVar12 = iVar12 + 4, *piVar3 == 1) {
      iVar1 = iVar11 * 0x80;
      iVar2 = iVar11 * 0x100;
      iVar11 = iVar11 + 1;
      memcpy((void *)(iVar4 + iVar1),(void *)(iVar5 + iVar2),0x80);
      if (iVar11 == 0x10) goto LAB_000394da;
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0x10);
LAB_000394da:
  iVar4 = DAT_00039590;
  set_nonce2_and_job_id_store_address(*(uint *)(DAT_00039590 + 0x8c));
  set_job_start_address(*(int *)(iVar4 + 0x8c) + 0x200000);
  *(undefined *)(iVar7 + 0xdd4) = 0;
  bitmain_reinit_test();
  uVar10 = *(uint *)(iVar4 + 0x8c);
  *(undefined *)(iVar7 + 0xdd4) = 1;
  set_nonce2_and_job_id_store_address(uVar10);
  set_job_start_address(*(int *)(iVar4 + 0x8c) + 0x200000);
  set_asic_ticket_mask(0x3f);
  cgsleep_ms(10);
  uVar10 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar10 | 0x10000);
  clear_nonce_fifo();
  if (*DAT_00039594 == 0) {
    set_time_out_control(*(uint *)(*piVar8 + 0x48) & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(*(int *)(*piVar8 + 0x48) * *DAT_00039594 & 0x1ffffU | 0x80000000);
  }
  ppVar9 = DAT_00039598;
  *(undefined *)(iVar7 + 0xdd4) = 0;
  pthread_mutex_unlock(ppVar9);
  re_send_last_job();
  cgtime(DAT_0003959c);
  cgtime(DAT_000395a0);
  *(undefined *)(iVar6 + 0x980) = 1;
  return;
}

