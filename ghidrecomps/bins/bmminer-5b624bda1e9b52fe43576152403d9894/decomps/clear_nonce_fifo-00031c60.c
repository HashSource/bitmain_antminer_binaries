
/* WARNING: Unknown calling convention */

void clear_nonce_fifo(void)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = DAT_00031c84;
  pthread_mutex_lock(DAT_00031c84);
  nonce_read_out.p_wr = 0;
  nonce_read_out.p_rd = 0;
  nonce_read_out.nonce_num = 0;
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f228)(ppVar1);
  return;
}

