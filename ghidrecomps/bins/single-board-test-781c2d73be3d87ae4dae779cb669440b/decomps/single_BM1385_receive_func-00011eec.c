
/* WARNING: Unknown calling convention */

void * single_BM1385_receive_func(void *arg)

{
  byte which_chain_00;
  byte bVar1;
  chain_info *chain_info;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar which_chain;
  uchar which_i2c;
  int iVar8;
  uchar *puVar9;
  uint uVar10;
  uint uVar11;
  uchar temp_buf [5];
  uchar auStack_607 [2];
  uchar uStack_605;
  uchar data_buf [500];
  uchar receive_buf [1000];
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  bVar1 = *(byte *)((int)arg + 1);
  memset(receive_buf,0,1000);
  memset(data_buf,0,500);
  temp_buf[0] = '\0';
  temp_buf[1] = '\0';
  temp_buf[2] = '\0';
  temp_buf[3] = '\0';
  uVar10 = 0;
  temp_buf[4] = '\0';
  uVar11 = 0;
  printf("%s: which_chain = %d, which_i2c = %d\n",DAT_00012088,(uint)which_chain_00,(uint)bVar1);
  clear_uart_rx_fifo(which_chain_00);
joined_r0x00011f6e:
  do {
    if (start_receive == false) {
      return (void *)0x0;
    }
    iVar8 = 5000000;
    usleep(5000);
    while( true ) {
      memset(receive_buf,0,1000);
      uVar2 = uart_receive(which_chain_00,receive_buf,1000);
      if (uVar2 != 0 && uVar11 < 3) break;
      iVar8 = iVar8 + -1;
      if (iVar8 == 0) goto joined_r0x00011f6e;
    }
    puVar9 = data_buf + (uVar10 - 1);
    puVar5 = data_buf + 499;
    do {
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
      *puVar9 = *puVar5;
    } while (puVar5 != data_buf + uVar2 + 499);
    uVar10 = uVar10 + uVar2;
    if (4 < uVar10) {
      puVar9 = data_buf;
      iVar8 = uVar10 / 5 + ((uint)((ulonglong)uVar10 * 0xcccccccd >> 0x20) & 0xfffffffc);
      puVar5 = puVar9 + iVar8;
      do {
        temp_buf[0] = '\0';
        temp_buf[1] = '\0';
        temp_buf[2] = '\0';
        temp_buf[3] = '\0';
        temp_buf[4] = '\0';
        puVar4 = puVar9;
        puVar6 = temp_buf;
        do {
          puVar7 = puVar6 + 1;
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar7;
        } while (puVar7 != auStack_607);
        if ((char)temp_buf[4] < '\0') {
          if ((gStartTest != false) && (gIsOpenCoreEnd != false)) {
            iVar3 = single_BM1385_check_nonce(which_chain_00,temp_buf);
            goto joined_r0x0001207e;
          }
        }
        else {
          iVar3 = single_BM1385_check_register_value(which_chain_00,temp_buf);
joined_r0x0001207e:
          if (iVar3 == -1) {
            uVar11 = uVar11 + 1;
          }
        }
        puVar9 = puVar9 + 5;
      } while (puVar5 != puVar9);
      uVar10 = uVar10 - iVar8;
      if (uVar10 != 0) {
        puVar9 = &uStack_605;
        puVar5 = data_buf + iVar8 + -1;
        do {
          puVar5 = puVar5 + 1;
          puVar9 = puVar9 + 1;
          *puVar9 = *puVar5;
        } while (puVar5 != data_buf + uVar10 + iVar8 + -1);
      }
    }
  } while( true );
}

