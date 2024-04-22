
/* WARNING: Unknown calling convention */

void set_led(_Bool stop)

{
  char cVar1;
  int iVar2;
  char cmd [100];
  
  iVar2 = DAT_0003462c;
  cVar1 = *(char *)(DAT_00034630 + 0x674);
  *(byte *)(DAT_0003462c + 0x90) = *(byte *)(DAT_0003462c + 0x90) ^ 1;
  if (cVar1 == '\0') {
    if (stop) {
      sprintf(cmd,DAT_00034634,0,DAT_00034644);
      system(cmd);
      sprintf(cmd,DAT_00034634,(uint)*(byte *)(iVar2 + 0x90),DAT_00034640);
      system(cmd);
    }
    else {
      sprintf(cmd,DAT_00034634,0,DAT_00034640);
      system(cmd);
      sprintf(cmd,DAT_00034634,(uint)*(byte *)(iVar2 + 0x90),DAT_00034644);
      system(cmd);
    }
  }
  else if (stop) {
    sprintf(cmd,DAT_00034634,0,DAT_00034638);
    system(cmd);
    sprintf(cmd,DAT_00034634,(uint)*(byte *)(iVar2 + 0x90),DAT_0003463c);
    system(cmd);
  }
  else {
    sprintf(cmd,DAT_00034634,0,DAT_0003463c);
    system(cmd);
    sprintf(cmd,DAT_00034634,(uint)*(byte *)(iVar2 + 0x90),DAT_00034638);
    system(cmd);
  }
  return;
}

