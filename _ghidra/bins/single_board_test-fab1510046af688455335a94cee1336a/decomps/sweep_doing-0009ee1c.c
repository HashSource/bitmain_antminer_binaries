
/* WARNING: Unknown calling convention */

int sweep_doing(void)

{
  int iVar1;
  char tmp42 [256];
  
  iVar1 = (*ops.sweep)(&freq_matrix,&state_matrix);
  if ((iVar1 == 0) && (g_sweep_err_code == 0)) {
    iVar1 = sweep_flush();
  }
  else {
    snprintf(tmp42,0x100,"sweep failed g_sweep_err_code %d",g_sweep_err_code);
    puts(tmp42);
    iVar1 = -1;
  }
  return iVar1;
}

