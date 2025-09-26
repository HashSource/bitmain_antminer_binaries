
/* WARNING: Unknown calling convention */

int sweep_flush(void)

{
  int iVar1;
  char tmp42 [256];
  int ret;
  
  iVar1 = (*ops.flush)(&freq_matrix);
  if (iVar1 == 0) {
    builtin_strncpy(tmp42,"Sweep Succes",0xc);
    tmp42[0xc] = 's';
    tmp42[0xd] = '\0';
    puts(tmp42);
  }
  else {
    builtin_strncpy(tmp42,"Sweep Fa",8);
    tmp42[8] = 'i';
    tmp42[9] = 'l';
    tmp42[10] = '\0';
    puts(tmp42);
  }
  if (freq_matrix != (float *)0x0) {
    free(freq_matrix);
    freq_matrix = (float *)0x0;
  }
  if (state_matrix != (uint8_t *)0x0) {
    free(state_matrix);
    state_matrix = (uint8_t *)0x0;
  }
  return iVar1;
}

