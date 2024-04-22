
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1397_receive_func(void *arg)

{
  uchar which_chain_00;
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uchar which_chain;
  uint buf [2];
  
  uVar1 = DAT_00028f14;
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  buf[0] = 0;
  buf[1] = 0;
  while (start_receive != false) {
    usleep(5000);
    uVar2 = read_axi_fpga(6);
    if ((uVar2 & 0x1ff) != 0) {
      uVar3 = 0;
      do {
        get_return_nonce(buf);
        if ((int)buf[0] < 0) {
          if (gBegin_Get_Nonce != false) {
            if ((buf[0] & 0xe0) == 0x80) {
              single_BM1397_check_nonce(which_chain_00,buf);
            }
            else {
              printf("%s: data = 0x%08x\n",uVar1);
            }
          }
        }
        else {
          single_BM1397_check_register_value(which_chain_00,buf);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uVar2 & 0x1ff));
    }
  }
  return (void *)0x0;
}

