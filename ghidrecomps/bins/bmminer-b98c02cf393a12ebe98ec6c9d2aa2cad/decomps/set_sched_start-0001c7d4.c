
char * set_sched_start(char *param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = DAT_0001c81c;
  iVar2 = sscanf(param_1,"%d:%d",DAT_0001c81c + 1,DAT_0001c81c);
  if (iVar2 != 2) {
    return "Invalid time set, should be HH:MM";
  }
  if ((puVar1[1] < 0x18) && (*puVar1 < 0x3c)) {
    *(undefined *)(puVar1 + -2) = 1;
    return (char *)0x0;
  }
  return "Invalid time set.";
}

