
/* WARNING: Unknown calling convention */

void jump_to_app_CheckAndRestorePIC_T9_18(int chainIndex)

{
  uchar chain;
  uchar which_iic;
  uchar pic_version;
  int iVar1;
  byte local_121;
  char logstr [256];
  
  chain = (uchar)chainIndex;
  if (*DAT_00030258 < 0xe) {
    if (chainIndex == (chainIndex / 3) * 3) {
      sprintf(logstr,DAT_0003025c,chainIndex);
      writeInitLogFile(logstr);
      which_iic = (uchar)(chainIndex / 3);
      dsPIC33EP16GS202_jump_to_app_from_loader(which_iic);
      get_pic_software_version(chain,&local_121);
      sprintf(logstr,DAT_00030260,chainIndex,(uint)local_121);
      writeInitLogFile(logstr);
      if (local_121 != 3) {
        iVar1 = 2;
        do {
          sprintf(logstr,DAT_00030264,chainIndex);
          writeInitLogFile(logstr);
          dsPIC33EP16GS202_update_pic_app_program(which_iic);
          dsPIC33EP16GS202_jump_to_app_from_loader(which_iic);
          get_pic_software_version(chain,&local_121);
          sprintf(logstr,DAT_00030268,chainIndex,(uint)local_121);
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
    sprintf(logstr,DAT_0003025c,chainIndex);
    writeInitLogFile(logstr);
    dsPIC33EP16GS202_jump_to_app_from_loader(chain);
    get_pic_software_version(chain,&local_121);
    sprintf(logstr,DAT_00030260,chainIndex,(uint)local_121);
    writeInitLogFile(logstr);
    if (local_121 != 3) {
      iVar1 = 2;
      do {
        sprintf(logstr,DAT_00030264,chainIndex);
        writeInitLogFile(logstr);
        dsPIC33EP16GS202_update_pic_app_program(chain);
        dsPIC33EP16GS202_jump_to_app_from_loader(chain);
        get_pic_software_version(chain,&local_121);
        sprintf(logstr,DAT_00030268,chainIndex,(uint)local_121);
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

