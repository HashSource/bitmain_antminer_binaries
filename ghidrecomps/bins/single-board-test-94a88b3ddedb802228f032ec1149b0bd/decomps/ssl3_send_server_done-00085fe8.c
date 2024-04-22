
void ssl3_send_server_done(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 0x2170) {
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,0xe,0);
    *(undefined4 *)(param_1 + 0x34) = 0x2171;
  }
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  return;
}

