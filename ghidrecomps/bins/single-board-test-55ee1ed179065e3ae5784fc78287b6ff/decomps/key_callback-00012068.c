
void key_callback(int param_1,int param_2)

{
  char *local_10 [2];
  
  local_10[0] = "reset";
  local_10[1] = "ipreport";
  if (param_2 == 0) {
    printf("%s key pressed\n",local_10[param_1 + -0x100]);
    key_pressed = 1;
  }
  else if (param_2 == 1) {
    printf("%s key up\n",local_10[param_1 + -0x100]);
    key_pressed = 0;
  }
  if (param_1 == 0x100) {
    red_led_off();
    green_led_off();
  }
  return;
}

