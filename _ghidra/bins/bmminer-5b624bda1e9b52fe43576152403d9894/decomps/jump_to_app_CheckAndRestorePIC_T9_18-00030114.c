
/* WARNING: Unknown calling convention */

void jump_to_app_CheckAndRestorePIC_T9_18(int chainIndex)

{
  uchar chain;
  uchar which_iic;
  int iVar1;
  byte local_121;
  char logstr [256];
  
  chain = (uchar)chainIndex;
  if (fpga_version < 0xe) {
    if (chainIndex == (chainIndex / 3) * 3) {
      sprintf(logstr,"chain[%d] PIC jump to app\n",chainIndex);
      writeInitLogFile(logstr);
      which_iic = (uchar)(chainIndex / 3);
      dsPIC33EP16GS202_jump_to_app_from_loader(which_iic);
      get_pic_software_version(chain,&local_121);
      sprintf(logstr,"Check chain[%d] PIC fw version=0x%02x\n",chainIndex,(uint)local_121);
      writeInitLogFile(logstr);
      if (local_121 != 3) {
        iVar1 = 2;
        do {
          sprintf(logstr,"chain[%d] PIC need restore ...\n",chainIndex);
          writeInitLogFile(logstr);
          dsPIC33EP16GS202_update_pic_app_program(which_iic);
          dsPIC33EP16GS202_jump_to_app_from_loader(which_iic);
          get_pic_software_version(chain,&local_121);
          sprintf(logstr,"After restore: chain[%d] PIC fw version=0x%02x\n",chainIndex,
                  (uint)local_121);
          writeInitLogFile(logstr);
          if (local_121 == 3) {
            return;
          }
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
  }
  else if (chainIndex - 1U < 3) {
    sprintf(logstr,"chain[%d] PIC jump to app\n",chainIndex);
    writeInitLogFile(logstr);
    dsPIC33EP16GS202_jump_to_app_from_loader(chain);
    get_pic_software_version(chain,&local_121);
    sprintf(logstr,"Check chain[%d] PIC fw version=0x%02x\n",chainIndex,(uint)local_121);
    writeInitLogFile(logstr);
    if (local_121 != 3) {
      iVar1 = 2;
      do {
        sprintf(logstr,"chain[%d] PIC need restore ...\n",chainIndex);
        writeInitLogFile(logstr);
        dsPIC33EP16GS202_update_pic_app_program(chain);
        dsPIC33EP16GS202_jump_to_app_from_loader(chain);
        get_pic_software_version(chain,&local_121);
        sprintf(logstr,"After restore: chain[%d] PIC fw version=0x%02x\n",chainIndex,(uint)local_121
               );
        writeInitLogFile(logstr);
        if (local_121 == 3) {
          return;
        }
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

