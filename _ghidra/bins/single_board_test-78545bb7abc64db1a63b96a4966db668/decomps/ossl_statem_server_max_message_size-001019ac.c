
undefined4 ossl_statem_server_max_message_size(int param_1)

{
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0x14:
    return 0x20144;
  default:
    return 0;
  case 0x1b:
    return *(undefined4 *)(param_1 + 0x4fc);
  case 0x1c:
    return 0x800;
  case 0x1d:
    return 0x4000;
  case 0x1e:
    return 0x202;
  case 0x1f:
  case 0x2c:
    return 1;
  case 0x20:
    return 0x40;
  }
}

