
undefined4 i2r_address(BIO *param_1,int param_2,int param_3,size_t *param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  size_t __n;
  int iVar5;
  int iVar6;
  byte local_30 [5];
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  char local_22;
  char local_21;
  
  __n = *param_4;
  if (-1 < (int)__n) {
    if (param_2 == 1) {
      if ((int)__n < 5) {
        if (__n != 0) {
          memcpy(local_30,(void *)param_4[2],__n);
          if ((param_4[3] & 7) != 0) {
            bVar2 = (byte)(0xff >> (8 - (param_4[3] & 7) & 0xff));
            if (param_3 == 0) {
              local_30[__n - 1] = local_30[__n - 1] & ~bVar2;
            }
            else {
              local_30[__n - 1] = bVar2 | local_30[__n - 1];
            }
          }
        }
        memset(local_30 + __n,param_3,4 - __n);
        BIO_printf(param_1,"%d.%d.%d.%d",(uint)local_30[0],(uint)local_30[1],(uint)local_30[2],
                   (uint)local_30[3]);
        return 1;
      }
    }
    else {
      if (param_2 != 2) {
        if (__n != 0) {
          iVar5 = 0;
          do {
            iVar5 = iVar5 + 1;
            BIO_printf(param_1,"%s%02x");
          } while (iVar5 < (int)*param_4);
        }
        BIO_printf(param_1,"[%d]",param_4[3] & 7);
        return 1;
      }
      if ((int)__n < 0x11) {
        if (__n != 0) {
          memcpy(local_30,(void *)param_4[2],__n);
          if ((param_4[3] & 7) != 0) {
            bVar2 = (byte)(0xff >> (8 - (param_4[3] & 7) & 0xff));
            if (param_3 == 0) {
              local_30[__n - 1] = local_30[__n - 1] & ~bVar2;
            }
            else {
              local_30[__n - 1] = bVar2 | local_30[__n - 1];
            }
          }
        }
        memset(local_30 + __n,param_3,0x10 - __n);
        if ((local_21 == '\0') && (local_22 == '\0')) {
          if ((local_23 == '\0') && (local_24 == '\0')) {
            if ((local_25 == '\0') && (local_26 == '\0')) {
              if ((local_27 == '\0') && (local_28 == '\0')) {
                if ((local_29 == '\0') && (local_2a == '\0')) {
                  if ((local_2b == '\0') && (local_30[4] == '\0')) {
                    if ((local_30[3] == 0) && (local_30[2] == 0)) {
                      if ((local_30[1] == 0) && (local_30[0] == 0)) {
                        BIO_puts(param_1,":");
                        BIO_puts(param_1,":");
                        return 1;
                      }
                      iVar5 = 2;
                    }
                    else {
                      iVar5 = 4;
                    }
                  }
                  else {
                    iVar5 = 6;
                  }
                }
                else {
                  iVar5 = 8;
                }
              }
              else {
                iVar5 = 10;
              }
            }
            else {
              iVar5 = 0xc;
            }
          }
          else {
            iVar5 = 0xe;
          }
        }
        else {
          iVar5 = 0x10;
        }
        iVar6 = 0;
        do {
          pbVar1 = local_30 + iVar6;
          iVar3 = iVar6 + 1;
          pcVar4 = "";
          if (iVar6 != 0xe) {
            pcVar4 = ":";
          }
          iVar6 = iVar6 + 2;
          BIO_printf(param_1,"%x%s",(uint)CONCAT11(*pbVar1,local_30[iVar3]),pcVar4);
        } while (iVar6 < iVar5);
        if (iVar5 != 0x10) {
          BIO_puts(param_1,":");
        }
        return 1;
      }
    }
  }
  return 0;
}

