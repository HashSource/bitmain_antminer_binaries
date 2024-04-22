
/* WARNING: Unknown calling convention */

void clear_register_value_buf(void)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = DAT_00031cac;
  pthread_mutex_lock(DAT_00031cac);
  reg_value_buf.p_wr = 0;
  reg_value_buf.p_rd = 0;
  reg_value_buf.reg_value_num = 0;
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f228)(ppVar1);
  return;
}

