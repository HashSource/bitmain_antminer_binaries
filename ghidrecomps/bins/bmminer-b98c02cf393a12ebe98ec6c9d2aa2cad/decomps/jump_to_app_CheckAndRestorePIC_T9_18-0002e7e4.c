
void jump_to_app_CheckAndRestorePIC_T9_18(uint param_1)

{
  FILE *pFVar1;
  byte local_19 [5];
  
  if (1 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: chain[%d] PIC jump to app\n","driver-btm-c5.c",0x6e7,DAT_0002e8d8,
              param_1);
    }
    fclose(pFVar1);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: chain[%d] PIC jump to app\n","driver-btm-c5.c",0x6e8,DAT_0002e8d8,
                param_1);
      }
      fclose(pFVar1);
    }
  }
  dsPIC33EP16GS202_jump_to_app_from_loader(param_1 & 0xff);
  dsPIC33EP16GS202_get_pic_sw_version(param_1 & 0xff,local_19);
  if (log_level < 4) {
    return;
  }
  pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
  if (pFVar1 != (FILE *)0x0) {
    fprintf(pFVar1,"%s:%d:%s: Check chain[%d] PIC fw version=0x%02x\n","driver-btm-c5.c",0x6ed,
            DAT_0002e8d8,param_1,(uint)local_19[0]);
  }
  fclose(pFVar1);
  return;
}

