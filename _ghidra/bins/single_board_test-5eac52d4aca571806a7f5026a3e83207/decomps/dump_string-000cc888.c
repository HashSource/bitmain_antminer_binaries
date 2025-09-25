
/* WARNING: Unknown calling convention */

int dump_string(char *str,size_t len,json_dump_callback_t dump,void *data,size_t flags)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  uint uVar5;
  char *buffer;
  uint uVar6;
  uint local_34;
  char seq [13];
  
  local_34 = 0;
  iVar1 = (*dump)("\"",1,data);
  if (iVar1 == 0) {
    pcVar2 = str;
    pcVar3 = str;
LAB_000cc8da:
    do {
      buffer = pcVar2;
      pcVar2 = buffer;
      if (buffer < str + len) {
        pcVar2 = utf8_iterate(buffer,(int)(str + len) - (int)buffer,(int32_t *)&local_34);
        if (pcVar2 == (char *)0x0) {
          return -1;
        }
        if ((((local_34 != 0x5c && local_34 != 0x22) && (0x1f < (int)local_34)) &&
            (((flags & 0x400) == 0 || (local_34 != 0x2f)))) &&
           (((flags & 0x40) == 0 || ((int)local_34 < 0x80)))) goto LAB_000cc8da;
      }
      if ((buffer != pcVar3) && (iVar1 = (*dump)(pcVar3,(int)buffer - (int)pcVar3,data), iVar1 != 0)
         ) {
        return -1;
      }
      if (pcVar2 == buffer) {
        iVar1 = (*dump)("\"",1,data);
        return iVar1;
      }
      if (local_34 == 0xc) {
        sVar4 = 2;
        pcVar3 = "\\f";
LAB_000cc8d0:
        iVar1 = (*dump)(pcVar3,sVar4,data);
      }
      else {
        if ((int)local_34 < 0xd) {
          if (local_34 == 9) {
            sVar4 = 2;
            pcVar3 = "\\t";
          }
          else if (local_34 == 10) {
            sVar4 = 2;
            pcVar3 = "\\n";
          }
          else {
            if (local_34 != 8) goto LAB_000cc8bc;
            sVar4 = 2;
            pcVar3 = "\\b";
          }
          goto LAB_000cc8d0;
        }
        if (local_34 == 0x22) {
          pcVar3 = "\\\"";
          sVar4 = 2;
          goto LAB_000cc8d0;
        }
        if (0x22 < (int)local_34) {
          if (local_34 == 0x2f) {
            sVar4 = 2;
            pcVar3 = "\\/";
          }
          else {
            if (local_34 != 0x5c) goto LAB_000cc8bc;
            sVar4 = 2;
            pcVar3 = "\\\\";
          }
          goto LAB_000cc8d0;
        }
        if (local_34 != 0xd) {
LAB_000cc8bc:
          if ((int)local_34 < 0x10000) {
            snprintf(seq,0xd,"\\u%04X");
            pcVar3 = seq;
            sVar4 = 6;
          }
          else {
            uVar6 = local_34 - 0x10000;
            uVar5 = local_34 & 0x3ff;
            local_34 = uVar6;
            snprintf(seq,0xd,"\\u%04X\\u%04X",uVar6 * 0x1000 >> 0x16 | 0xd800,uVar5 | 0xdc00);
            pcVar3 = seq;
            sVar4 = 0xc;
          }
          goto LAB_000cc8d0;
        }
        iVar1 = (*dump)("\\r",2,data);
      }
      pcVar3 = pcVar2;
    } while (iVar1 == 0);
  }
  return -1;
}

