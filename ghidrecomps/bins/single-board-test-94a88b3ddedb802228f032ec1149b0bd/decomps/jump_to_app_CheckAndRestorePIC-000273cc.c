
void jump_to_app_CheckAndRestorePIC(uint param_1)

{
  byte local_11;
  FILE *local_10;
  FILE *local_c;
  
  if (3 < log_level) {
    local_c = fopen(log_file,"a+");
    if (local_c != (FILE *)0x0) {
      fprintf(local_c,"%s:%d: chain[%d] PIC jump to app\n","main.c",0x864,param_1);
    }
    fclose(local_c);
  }
  dsPIC33EP16GS202_jump_to_app_from_loader(param_1 & 0xff);
  get_pic_software_version(param_1 & 0xff,&local_11);
  if (3 < log_level) {
    local_10 = fopen(log_file,"a+");
    if (local_10 != (FILE *)0x0) {
      fprintf(local_10,"%s:%d: Check chain[%d] PIC fw version=0x%02x\n","main.c",0x869,param_1,
              (uint)local_11);
    }
    fclose(local_10);
  }
  return;
}

