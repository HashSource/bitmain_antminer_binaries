
int power_send_cmd(int param_1,int param_2,int param_3,int param_4)

{
  undefined uVar1;
  int iVar2;
  FILE *__stream;
  byte *pbVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar5 = 1;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  do {
    if (param_2 != 0) {
      pbVar3 = (byte *)(param_1 + -1);
      do {
        pbVar3 = pbVar3 + 1;
        set_iic(*pbVar3 | 0x5201100);
      } while (pbVar3 != (byte *)((param_2 - 1U & 0xff) + param_1));
    }
    puVar4 = (undefined *)(param_3 + -1);
    usleep(500000);
    if (param_4 != 0) {
      do {
        uVar1 = set_iic(0x6200000);
        puVar4 = puVar4 + 1;
        *puVar4 = uVar1;
      } while (puVar4 != (undefined *)((param_4 - 1U & 0xff) + param_3));
    }
    iVar2 = power_check_reply(param_1,param_3,param_4);
    if (iVar2 != 0) break;
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: power send cmd 0x%02x failed, retry for %d times\n","power.c",
                0x3a0,DAT_000424e8,(uint)*(byte *)(param_1 + 2),iVar5);
      }
      fclose(__stream);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return iVar2;
}

