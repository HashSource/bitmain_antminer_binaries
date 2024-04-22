
/* WARNING: Unknown calling convention */

void re_send_last_job(void)

{
  int iVar1;
  
  iVar1 = DAT_00039384;
  if (*(char *)(DAT_00039384 + 0x98) == '\x17') {
    return;
  }
  pthread_mutex_lock(DAT_00039388);
  send_job((uchar *)(iVar1 + 0x98));
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f228)(DAT_00039388);
  return;
}

