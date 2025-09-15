
void blake32_init(int param_1,void *param_2,void *param_3)

{
  memcpy((void *)(param_1 + 0x44),param_2,0x20);
  memcpy((void *)(param_1 + 100),param_3,0x10);
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

