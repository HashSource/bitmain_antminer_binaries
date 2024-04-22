
void power_check_protocal_type(void)

{
  int iVar1;
  FILE *pFVar2;
  int iVar3;
  
  iVar3 = 10;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  do {
    iVar1 = set_iic((power_iic_addr & 7) << 0x10 | (power_iic_no & 3) << 0x1a | 0x3000000 |
                    (((uint)power_iic_addr << 0x19) >> 0x1c) << 0x14);
    usleep(200000);
    if (iVar1 == 0xf5) {
      if (log_level < 4) {
        power_protocal_type = 2;
      }
      else {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: power protocal %02x, using package cmd\n","power.c",0x94,
                  "power_check_protocal_type",0xf5);
        }
        fclose(pFVar2);
        power_protocal_type = 2;
      }
      goto LAB_00011f64;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: power protocal %02x, using simple cmd\n","power.c",0x99,
              "power_check_protocal_type",iVar1);
    }
    fclose(pFVar2);
  }
  power_protocal_type = 1;
LAB_00011f64:
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(iic_mutex);
  return;
}

