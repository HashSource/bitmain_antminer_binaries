
void check_temp_func(void)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = -100;
  do {
    uVar3 = 0;
LAB_00033d5c:
    do {
      if (*(int *)(dev + (uVar3 + 2) * 4) == 1) {
        if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
          if ((int)uVar3 % 3 == 1) {
LAB_00033d8c:
            if ('\0' < *(char *)(dev + uVar3 + 0x458)) {
              iVar4 = 0;
              do {
                iVar2 = dev + uVar3 * 8 + iVar4;
                iVar4 = iVar4 + 1;
                uVar1 = check_reg_temp(DEVICEADDR[uVar3],0,0,0,*(undefined *)(iVar2 + 0x4e8),uVar3);
                if ((uVar1 != 0) && (iVar2 = (uVar1 & 0xff) - 0x40, iVar5 < iVar2)) {
                  iVar5 = iVar2;
                }
              } while (iVar4 < *(char *)(dev + uVar3 + 0x458));
              uVar3 = uVar3 + 1;
              if (uVar3 == 0x10) break;
              goto LAB_00033d5c;
            }
          }
        }
        else if (((uVar3 & 0xfffffffd) == 8) || (uVar3 == 0xc || uVar3 == 6)) goto LAB_00033d8c;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x10);
    if (0x59 < iVar5) {
      global_stop = 1;
      status_error = 1;
      once_error = 1;
      if (3 < log_level) {
        __stream = fopen(log_file,(char *)&DAT_0005e760);
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: disable pic dac because of temp\n","driver-btm-c5.c",0x20aa,
                  DAT_00033e88);
        }
        fclose(__stream);
      }
      uVar3 = 0;
      do {
        while (*(int *)(dev + (uVar3 + 2) * 4) == 1) {
          pthread_mutex_lock(DAT_00033e84);
          uVar1 = uVar3 & 0xff;
          uVar3 = uVar3 + 1;
          disable_pic_dac(uVar1);
          pthread_mutex_unlock(DAT_00033e84);
          if (uVar3 == 0x10) goto LAB_00033e24;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0x10);
LAB_00033e24:
      uVar3 = get_dhash_acc_control();
      set_dhash_acc_control(uVar3 & 0xffffffbf);
    }
    sleep(3);
  } while( true );
}

