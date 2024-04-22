
void ssl23_get_cipher(uint param_1)

{
  uint uVar1;
  
  uVar1 = ssl3_num_ciphers();
  if (uVar1 <= param_1) {
    ssl2_get_cipher(param_1 - uVar1);
    return;
  }
  ssl3_get_cipher(param_1);
  return;
}

