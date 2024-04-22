
/* WARNING: Unknown calling convention */

_Bool power_check_reply(uint8_t *cmd,uint8_t *reply_buf,uint8_t reply_len)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar3 = (uint)reply_len;
  if ((((*cmd == *reply_buf) && (cmd[1] == reply_buf[1])) && (cmd[3] == reply_buf[3])) &&
     (uVar1 = (uint)reply_buf[2], uVar1 + 2 == uVar3)) {
    if (uVar1 < 3) {
      sVar2 = 0;
    }
    else {
      uVar4 = 2;
      sVar2 = 0;
      do {
        pbVar5 = reply_buf + uVar4;
        uVar4 = uVar4 + 1 & 0xffff;
        sVar2 = sVar2 + (ushort)*pbVar5;
      } while (uVar4 < uVar1);
    }
    if ((ushort)((ushort)reply_buf[uVar3 - 2] + (ushort)reply_buf[uVar3 - 1] * 0x100) == sVar2) {
      return true;
    }
    printf("power reply crc error, crc %04x != crc_reply %04x:\n");
    if (uVar3 != 0) {
      pbVar5 = reply_buf + -1;
      do {
        pbVar5 = pbVar5 + 1;
        printf("%02x ",(uint)*pbVar5);
      } while (reply_buf + (uVar3 - 1 & 0xffff) != pbVar5);
    }
  }
  else {
    puts("power reply data error:");
    if (uVar3 != 0) {
      pbVar5 = reply_buf + -1;
      do {
        pbVar5 = pbVar5 + 1;
        printf("%02x ",(uint)*pbVar5);
      } while (reply_buf + (uVar3 - 1 & 0xffff) != pbVar5);
    }
  }
  putchar(10);
  return false;
}

