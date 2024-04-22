
void blake64_init(int param_1,void *param_2,void *param_3)

{
  memcpy((void *)(param_1 + 0x88),param_2,0x40);
  memcpy((void *)(param_1 + 200),param_3,0x20);
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}

