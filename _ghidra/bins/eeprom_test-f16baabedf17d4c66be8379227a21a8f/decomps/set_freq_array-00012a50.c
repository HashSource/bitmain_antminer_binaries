
_Bool set_freq_array(int flag,uint16_t (*freq_data) [9],int freq)

{
  _Bool _Var1;
  int freq_local;
  uint16_t (*freq_data_local) [9];
  int flag_local;
  int j_1;
  int i;
  int j;
  
  if ((flag < 0) || (0xc < flag)) {
    _Var1 = false;
  }
  else {
    if (flag == 0) {
      for (j = 0; j < 0xc; j = j + 1) {
        for (i = 0; i < 9; i = i + 1) {
          freq_data[j][i] = (uint16_t)freq;
        }
      }
    }
    else {
      for (j_1 = 0; j_1 < 9; j_1 = j_1 + 1) {
        freq_data[flag + -1][j_1] = (uint16_t)freq;
      }
    }
    _Var1 = true;
  }
  return _Var1;
}

