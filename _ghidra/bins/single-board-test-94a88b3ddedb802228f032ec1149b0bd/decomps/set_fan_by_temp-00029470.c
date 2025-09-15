
/* WARNING: Removing unreachable block (ram,0x000295a6) */
/* WARNING: Removing unreachable block (ram,0x000295ac) */
/* WARNING: Removing unreachable block (ram,0x000295b4) */

void set_fan_by_temp(void)

{
  char cVar1;
  FILE *pFVar2;
  uint local_14;
  char local_e;
  char local_d;
  int local_c;
  
  local_14 = 100;
  local_d = '\0';
  local_e = '}';
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (testDone[local_c] == '\0')) {
      cVar1 = read_asic_temperature(local_c);
      if ((char)board_temp[local_c] < cVar1) {
        board_temp[local_c] = cVar1;
      }
      if (local_d < cVar1) {
        local_d = cVar1;
      }
      if (cVar1 < local_e) {
        local_e = cVar1;
      }
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: get top_temp=%d low_temp=%d\n","main.c",0xd56,(int)local_d,(int)local_e
             );
    }
    fclose(pFVar2);
  }
  if ((local_d == '\0') || (local_e == '\0')) {
    local_14 = 100;
  }
  else if (local_e < 'K') {
    local_14 = 0x1e;
  }
  else if ('K' < local_e) {
    local_14 = (int)local_e - 0x2d;
  }
  if ('U' < local_d) {
    local_14 = 100;
  }
  set_PWM(local_14 & 0xff);
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: set fan PWM=%d\n","main.c",0xd77,local_14);
    }
    fclose(pFVar2);
  }
  return;
}

