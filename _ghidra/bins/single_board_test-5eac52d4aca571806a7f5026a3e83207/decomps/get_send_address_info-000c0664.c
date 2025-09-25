
/* WARNING: Unknown calling convention */

int32_t get_send_address_info
                  (uint32_t which_uart,uint32_t *bit_shift_num,uint32_t *chain_send_fifo_status_addr
                  ,uint32_t *chain_send_ready_addr,uint32_t *chain_send_buffer_addr)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  char tmp42 [2048];
  
  switch(which_uart) {
  case 0:
    uVar1 = 0x18;
    uVar4 = 0x41;
    uVar3 = 0x45;
    uVar2 = 0x46;
    break;
  case 1:
    uVar1 = 0x10;
    uVar4 = 0x41;
    uVar3 = 0x47;
    uVar2 = 0x48;
    break;
  case 2:
    uVar1 = 8;
    uVar4 = 0x41;
    uVar3 = 0x49;
    uVar2 = 0x4a;
    break;
  case 3:
    uVar3 = 0x41;
    uVar2 = 0x4b;
    uVar1 = 0x4c;
    goto LAB_000c06c2;
  case 4:
    uVar1 = 0x18;
    uVar4 = 0x42;
    uVar3 = 0x4d;
    uVar2 = 0x4e;
    break;
  case 5:
    uVar1 = 0x10;
    uVar4 = 0x42;
    uVar3 = 0x4f;
    uVar2 = 0x50;
    break;
  case 6:
    uVar1 = 8;
    uVar4 = 0x42;
    uVar3 = 0x51;
    uVar2 = 0x52;
    break;
  case 7:
    uVar3 = 0x42;
    uVar2 = 0x53;
    uVar1 = 0x54;
    goto LAB_000c06c2;
  case 8:
    uVar1 = 0x18;
    uVar4 = 0x43;
    uVar3 = 0x55;
    uVar2 = 0x56;
    break;
  case 9:
    uVar1 = 0x10;
    uVar4 = 0x43;
    uVar3 = 0x57;
    uVar2 = 0x58;
    break;
  case 10:
    uVar1 = 8;
    uVar4 = 0x43;
    uVar3 = 0x74;
    uVar2 = 0x75;
    break;
  case 0xb:
    uVar3 = 0x43;
    uVar2 = 0x76;
    uVar1 = 0x77;
LAB_000c06c2:
    *bit_shift_num = 0;
    *chain_send_fifo_status_addr = uVar3;
    *chain_send_ready_addr = uVar2;
    *chain_send_buffer_addr = uVar1;
    return 0;
  case 0xc:
    uVar1 = 0x18;
    uVar4 = 0x44;
    uVar3 = 0x78;
    uVar2 = 0x79;
    break;
  case 0xd:
    uVar1 = 0x10;
    uVar4 = 0x44;
    uVar3 = 0x7a;
    uVar2 = 0x7b;
    break;
  default:
    snprintf(tmp42,0x800,"%s: The uart %d is not supported!!!\n","get_send_address_info",which_uart)
    ;
    _applog(0,tmp42,false);
    return -1;
  }
  *bit_shift_num = uVar1;
  *chain_send_fifo_status_addr = uVar4;
  *chain_send_ready_addr = uVar3;
  *chain_send_buffer_addr = uVar2;
  return 0;
}

