
void ssl3_send_hello_request(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 0x2120) {
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,0,0);
    *(undefined4 *)(param_1 + 0x34) = 0x2121;
  }
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  return;
}

