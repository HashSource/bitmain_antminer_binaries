
/* WARNING: Unknown calling convention */

void * V9_receive_func(void *arg)

{
  byte which_chain_00;
  byte bVar1;
  chain_info *chain_info;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar *puVar8;
  uchar which_i2c;
  uint uVar9;
  uchar which_chain;
  int iVar10;
  uchar *puVar11;
  uchar temp_buf [5];
  uchar auStack_63b [2];
  uchar uStack_639;
  uchar data_buf [500];
  uchar receive_buf [1050];
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  bVar1 = *(byte *)((int)arg + 1);
  memset(receive_buf,0,0x41a);
  uVar9 = 0;
  memset(data_buf,0,500);
  temp_buf[0] = '\0';
  temp_buf[1] = '\0';
  temp_buf[2] = '\0';
  temp_buf[3] = '\0';
  temp_buf[4] = '\0';
  printf("%s: which_chain = %d, which_i2c = %d\n",DAT_0001a464,(uint)which_chain_00,(uint)bVar1);
  clear_uart_rx_fifo(which_chain_00);
joined_r0x0001a36e:
  do {
    if (start_receive == false) {
      return (void *)0x0;
    }
    usleep(5000);
    iVar10 = 5000000;
    while( true ) {
      while (gIsOpeningCore != false) {
        usleep(20000);
      }
      memset(receive_buf,0,0x41a);
      uVar2 = uart_receive(which_chain_00,receive_buf,1000);
      if (uVar2 != 0) break;
      iVar10 = iVar10 + -1;
      if (iVar10 == 0) goto joined_r0x0001a36e;
    }
    puVar11 = data_buf + (uVar9 - 1);
    puVar6 = data_buf + 499;
    uVar5 = 0;
    do {
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 + 1;
      uVar9 = uVar9 + 1;
      puVar11 = puVar11 + 1;
      *puVar11 = *puVar6;
    } while (uVar5 < uVar2);
    if (4 < uVar9) {
      puVar11 = data_buf;
      iVar10 = uVar9 / 5 + ((uint)((ulonglong)uVar9 * 0xcccccccd >> 0x20) & 0xfffffffc);
      puVar6 = puVar11 + iVar10;
      do {
        temp_buf[0] = '\0';
        temp_buf[1] = '\0';
        temp_buf[2] = '\0';
        temp_buf[3] = '\0';
        temp_buf[4] = '\0';
        puVar4 = puVar11;
        puVar7 = temp_buf;
        do {
          puVar8 = puVar7 + 1;
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar8;
        } while (puVar8 != auStack_63b);
        iVar3 = BM1385_is_nonce_or_reg_value(temp_buf[4]);
        if (iVar3 == 0) {
          V9_check_register_value(which_chain_00,temp_buf);
        }
        else if ((gStartTest != false) && (gIsOpenCoreEnd != false)) {
          v9_check_nonce(which_chain_00,temp_buf);
        }
        puVar11 = puVar11 + 5;
      } while (puVar6 != puVar11);
      uVar9 = uVar9 - iVar10;
      if (uVar9 != 0) {
        puVar11 = &uStack_639;
        puVar6 = data_buf + iVar10 + -1;
        do {
          puVar6 = puVar6 + 1;
          puVar11 = puVar11 + 1;
          *puVar11 = *puVar6;
        } while (puVar6 != data_buf + iVar10 + -1 + uVar9);
      }
    }
  } while( true );
}

